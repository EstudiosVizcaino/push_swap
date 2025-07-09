#!/bin/bash

# Full input from https://push-swap42-visualizer.vercel.app/
INPUT="./push_swap asdasd"

# System number generator
#ARG=$(seq 1 500 | sort -R | tr '\n' ' ');

# Cleans the input from https://push-swap42-visualizer.vercel.app/
NUMBERS=$(echo "$INPUT" | sed -E 's/^[^ ]+ //; s/ \|.*$//')

# Stores output from the program
OUTPUT=$(./push_swap $NUMBERS)


####################################################################################################################################################
# LINE TEST
####################################################################################################################################################
# Stores and prints number of movements (number of lines)
LINE_COUNT=$(echo "$OUTPUT" | wc -l)
# Counts amount of parameters given to the program
COUNT=$(echo "$NUMBERS" | wc -w)

if [ "$COUNT" -eq 500 ]; then
    if [ "$LINE_COUNT" -lt 5500 ]; then
        LINE_TEST="✅"
    else
        LINE_TEST="Nope! ❌"
    fi
elif [ "$COUNT" -eq 100 ]; then
    if [ "$LINE_COUNT" -lt 700 ]; then
        LINE_TEST="✅"
    else
        LINE_TEST="Nope! ❌"
    fi
elif [ "$COUNT" -eq 5 ]; then
    if [ "$LINE_COUNT" -lt 12 ]; then
        LINE_TEST="✅"
    else
        LINE_TEST="Nope! ❌"
    fi
fi

####################################################################################################################################################
# CHECKER TEST
####################################################################################################################################################
CHECKER_OUTCOME=$(echo "$OUTPUT" | ./checker_linux $NUMBERS)

if echo "$CHECKER_OUTCOME" | grep -q "OK"; then
	CHECK_ICN="✅"
	elif echo "$CHECKER_OUTCOME" | grep -q "KO"; then
		CHECK_ICN="❌";
fi

####################################################################################################################################################
# VALGRIND TEST
####################################################################################################################################################
VALGRIND_LOG=$(mktemp)
ARGS=$(echo "$NUMBERS")
valgrind -s --leak-check=full ./push_swap $ARGS > /dev/null 2> "$VALGRIND_LOG"

# Check Valgrind output
if grep -q "ERROR SUMMARY: 0 errors" "$VALGRIND_LOG" && grep -q "All heap blocks were freed -- no leaks are possible" "$VALGRIND_LOG"; then
    VALGRIND_OUT="OK ✅"
else
    VALGRIND_OUT="❌ Issues found! | $(cat "$VALGRIND_LOG")"
fi

####################################################################################################################################################
# SUMMARY
####################################################################################################################################################
# Prints output
echo "$OUTPUT"

# Prints Line Test
echo "For $COUNT numbers, number of lines: $LINE_COUNT $LINE_TEST"

# Prints Checker Test
echo "Checker outcome: $CHECKER_OUTCOME $CHECK_ICN"

# Prints Valgrind Test
echo "Valgrind: $VALGRIND_OUT"

echo "$OUTPUT" >> moves.txt

# Clean up
rm "$VALGRIND_LOG"

#Infinite loop 3 6 1 2