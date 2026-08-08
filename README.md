# push_swap

> Sort a stack of integers with the smallest possible number of moves, using only a crippled instruction set and a second stack.

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Leaks](https://img.shields.io/badge/valgrind-0%20leaks-success.svg)](https://valgrind.org/)
[![500 numbers](https://img.shields.io/badge/500%20numbers-~4900%20moves-success.svg)](#performance)
[![School](https://img.shields.io/badge/42-Madrid-black.svg)](https://www.42madrid.com/)

`push_swap` is an algorithmic project from the 42 school curriculum. Given a
list of unique integers, the program prints the **shortest sequence of stack
operations it can find** that leaves the numbers sorted in ascending order. It
never sorts the data itself — it emits the *recipe*, which an external `checker`
then replays to verify the result.

The whole challenge is the move budget: sorting 500 numbers with a naive
approach costs tens of thousands of operations. This implementation averages
**~4,900**.

---

## Table of contents

- [The problem](#the-problem)
- [Performance](#performance)
- [Build](#build)
- [Usage](#usage)
- [How it works](#how-it-works)
- [Project layout](#project-layout)
- [Testing](#testing)
- [License](#license)

---

## The problem

You are given two stacks, `a` and `b`. Stack `a` starts with the input in the
order given; `b` starts empty. Only eleven instructions are allowed:

| Instruction | Effect |
|---|---|
| `sa` / `sb` / `ss` | Swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | Push the top of the other stack onto `a` / `b` |
| `ra` / `rb` / `rr` | Rotate `a` / `b` / both up — the first element becomes the last |
| `rra` / `rrb` / `rrr` | Reverse rotate `a` / `b` / both — the last element becomes the first |

The goal: end with `a` sorted ascending and `b` empty, printing one instruction
per line, using as few lines as possible.

## Performance

Measured over random permutations on this machine, verified move-by-move with
the official `checker`:

| Input size | Runs | Average moves | Best | Worst | 42 target (5/5) |
|---|---|---|---|---|---|
| 3   | 200 | 1     | 0     | 2     | ≤ 3 |
| 5   | 300 | 7     | 0     | 10    | ≤ 12 |
| 100 | 200 | **549**   | 503   | 605   | < 700 |
| 500 | 100 | **4,889** | 4,739 | 5,032 | < 5,500 |

Every run in the table was replayed through `checker_linux` and returned `OK`
— zero failures. Sorting 500 numbers takes roughly 6 ms.

Memory is clean under Valgrind:

```
HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks
  total heap usage: 603 allocs, 603 frees, 10,425 bytes allocated
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

## Build

Requires a C compiler and `make`. No external dependencies — the bundled
[`libft`](libft/) provides everything.

```sh
git clone https://github.com/EstudiosVizcaino/push_swap.git
cd push_swap
make
```

This produces the `push_swap` binary in the project root.

| Target | Description |
|---|---|
| `make` / `make all` | Build `libft` and link `push_swap` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files, `libft.a` and the binary |
| `make re` | `fclean` followed by `all` |

Compiled with `-Wall -Wextra -Werror`.

## Usage

Pass the numbers as separate arguments, as one quoted string, or any mix of
the two:

```sh
$ ./push_swap 4 67 3 87 23
ra
ra
pb
ra
ra
pb
rra
pa
pa

$ ./push_swap "5 1 4 2 3"      # single quoted string
$ ./push_swap "5 1" 4 "2 3"    # mixed — equivalent to the above
```

Piping the output into the checker is the canonical way to verify a run:

```sh
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
OK
```

Counting the moves:

```sh
$ ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
4981
```

### Behaviour and error handling

- If the input is **already sorted**, the program prints nothing and exits `0`.
- On invalid input it prints `Error` to **stderr** and exits non-zero.

Input is rejected when it contains a non-numeric character, a duplicate value,
a number outside the `int` range, a malformed sign (`--5`, `+`, `5-3`), or when
the arguments are empty or whitespace only.

```sh
$ ./push_swap 1 2 2        # duplicate
Error
$ ./push_swap 1 a 3        # not a number
Error
$ ./push_swap 2147483648   # overflows int
Error
```

## How it works

The program picks a strategy based on how many numbers it was given. Before
anything else, each value is replaced by its **rank** (`s_index`) in the sorted
input — so the algorithm only ever reasons about `0 … n-1` and never has to
compare raw integers again.

| Size | Strategy |
|---|---|
| already sorted | print nothing, exit immediately |
| 2 | a single `sa` |
| 3 | hard-coded three-element sort |
| 4 – 7 | selection sort through `b` |
| 8+ | chunk sort |

### Three elements

Six permutations, at most two moves. The largest element is rotated out of the
way, then a `sa` fixes the remaining pair if needed.

### Four to seven elements

A selection sort that uses `b` as a parking lot. Repeatedly: find the smallest
remaining rank, rotate it to the top — choosing `ra` or `rra` depending on
which half of the stack it sits in — and `pb` it. Once only three elements are
left, sort them directly and push everything back. Because `b` received the
values in ascending order, pushing back restores them in sorted order.

### Eight and above — chunk sort

The interesting case, in two phases.

**Phase 1 — split into `b`.** Walk stack `a` and push every element whose rank
falls inside the current window down to `b`, rotating past everything else. The
window advances as elements are taken, so `b` fills up in roughly descending
order with small values near the top of each chunk.

The chunk width is the tuned part:

```c
chunk_size = ft_sqrt(size) * 14 / 10;    /* ≈ 1.4 · √n */
```

That is 14 for 100 numbers and 30 for 500. Narrow chunks mean `b` comes out
almost perfectly ordered but phase 1 burns rotations; wide chunks are cheap to
build but expensive to unwind. `1.4·√n` is the empirical sweet spot between
the two.

Elements already close to the front of the next window get an `rb` (or a
combined `rr`, saving a move) so that phase 2 finds them where it wants them.

**Phase 2 — rebuild `a`.** Repeatedly bring the **largest** remaining rank in
`b` to the top and `pa` it, so `a` grows downward in sorted order. For each
target the algorithm counts how far it sits from the top and compares the cost
of rotating forward against reverse-rotating backward, then takes the cheaper
direction. Since each `pa` places the next-largest value on top of `a`, no
further correction is ever needed.

## Project layout

```
push_swap/
├── src/
│   ├── push_swap.c          # entry point: parse → build stack → sort → free
│   ├── push_swap.h          # t_stack_node, t_processed_input
│   ├── ops/
│   │   ├── swap.c           # sa, sb, ss
│   │   ├── push.c           # pa, pb
│   │   ├── rotate.c         # ra, rb, rr
│   │   ├── rev_rotate.c     # rra, rrb, rrr
│   │   ├── small_sorts.c    # sort_three, s_insertion_sort
│   │   └── ksort.c          # chunk sort + strategy dispatch
│   └── utils/
│       ├── arg_utils.c      # validation: format, duplicates, int range
│       ├── input_utils.c    # argument normalisation
│       ├── stack_utils.c    # stack construction, ranking, teardown
│       ├── utils.c          # ft_sqrt, insertion sort, helpers
│       └── exceptions.c     # error reporting
├── libft/                   # bundled C standard-library subset
├── tester.sh                # single verbose run
├── autotester.sh            # repeated runs with a pass/fail summary
└── Makefile
```

Roughly 1,200 lines in `src/`, plus the `libft` support library. Every function
carries a Doxygen block.

## Testing

Two scripts drive the binary against the provided checker. Both generate a
random permutation, run `push_swap`, replay the output through `checker_linux`,
and check the move count against the 42 thresholds — `tester.sh` also runs the
whole thing under Valgrind.

```sh
./tester.sh        # one run, verbose, with leak check
./autotester.sh    # repeated runs, summary table
```

`checker_linux` and `checker_Mac` are the binaries supplied by 42; pick the one
matching your platform.

A quick ad-hoc loop is often enough:

```sh
for i in $(seq 1 100); do
  ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' ')
  ./push_swap $ARG | ./checker_linux $ARG
done | sort | uniq -c
```

## License

Educational project, written as part of the 42 curriculum. Free to read, learn
from, and borrow. If you are a 42 student currently working on `push_swap`:
implementing it yourself is the whole point — read the algorithm section, not
the source.
