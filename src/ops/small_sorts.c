/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:12:06 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/11 16:27:04 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * @brief Prints the contents of a stack to the standard output.
 *
 * If the stack pointer is NULL, it calls print_error().
 * Otherwise, it prints all the node data values in order.
 *
 * @param stack Pointer to the first node of the stack.
 */
void	print_stack(t_stack_node *stack)
{
	printf("------------------\nPrinting stack: \n");
	if (!stack)
		print_error();
	while (stack)
	{
		printf("|%i| ", stack->data);
		stack = stack->next;
	}
	printf("\n------------------\n");
}

/**
 * @brief Counts how many nodes until a node with a specific index.
 *
 * Traverses the stack until it finds the node whose `s_index` matches
 * the given `index`, counting how many nodes it passes.
 *
 * @param stack Pointer to the start of the stack.
 * @param index The target `s_index` to find in the stack.
 * @return The number of nodes before the target node, or the total
 *         length if the index is not found.
 */
int	nodes_to_index(t_stack_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->s_index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

/**
 * @brief Sorts a stack of three elements in ascending order.
 *
 * Applies rotate (ra), reverse rotate (rra), or swap (sa) to sort the stack.
 * - If the top is the largest, rotate it down.
 * - If the middle is the largest, rotate it up.
 * - If the top two are out of order, swap them.
 * Does nothing if already sorted.
 *
 * @param stack Pointer to the stack to sort.
 */
void	sort_three(t_stack_node **stack)
{
	t_stack_node	*top;
	t_stack_node	*middle;
	t_stack_node	*bottom;

	if (is_sorted(*stack))
		return ;
	top = *stack;
	middle = top->next;
	bottom = middle->next;
	if (top->data > middle->data && top->data > bottom->data)
		ra(stack);
	else if (middle->data > top->data && middle->data > bottom->data)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

/**
 * @brief Sorts a small stack using a simplified insertion sort.
 *
 * Moves the smallest elements from stack 'a' to 'b' one by one, by analazying
 * if the target index is on the top or the lower half of the stack,
 * sorts the remaining 3 in 'a', then pushes everything back from 'b' to 'a'.
 *
 * @param a Pointer to stack 'a'.
 * @param b Pointer to stack 'b'.
 * @param length Number of elements in stack 'a'.
 */

void	s_insertion_sort(t_stack_node **a, t_stack_node **b, int len)
{
	int	min_s_index;
	int	pos_in_stack;

	while (len > 3)
	{
		min_s_index = get_min_index(*a);
		pos_in_stack = nodes_to_index(*a, min_s_index);
		if (pos_in_stack <= len / 2)
		{
			while ((*a)->s_index != min_s_index)
				ra(a);
		}
		else
		{
			while ((*a)->s_index != min_s_index)
				rra(a);
		}
		pb(b, a);
		len--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
