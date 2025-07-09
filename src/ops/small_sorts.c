/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:12:06 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/09 16:19:50 by cvizcain         ###   ########.fr       */
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
 * @brief Sorts a stack of three elements
 *
 * If the stack is already sorted, does nothing. Otherwise, it identifies the
 * minimum indexed element and uses swaps and rotations to sort the stack.
 *
 * @param stack Pointer to the stack to sort.
 * @param length Number of elements in the stack.
 */
void	sort_three(t_stack_node **stack, int length)
{
	int	a;
	int	b;
	int	c;
	int	min_s_index;
	int	r;

	if (is_sorted(*stack))
		return ;
	min_s_index = get_min_index(*stack);
	r = nodes_to_index(*stack, min_s_index);
	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (!((a < b && b < c) || (b < c && a > c) || (c < a && a < b)))
	{
		sa(stack);
		if (is_sorted(*stack))
			return ;
	}
	if (r < length - r)
		ra(stack);
	else
		rra(stack);
}

/**
 * @brief Sorts a small stack using a simplified insertion sort.
 *
 * Moves the smallest elements from stack 'a' to 'b' one by one,
 * sorts the remaining 3 in 'a', then pushes everything back from 'b' to 'a'.
 *
 * @param a Pointer to stack 'a'.
 * @param b Pointer to stack 'b'.
 * @param length Number of elements in stack 'a'.
 */

void	s_insertion_sort(t_stack_node **a, t_stack_node **b, int length)
{
	int	min_index;
	int	iter;
	int	n;

	iter = 0;
	n = length;
	while (iter++ < n - 3)
	{
		min_index = get_min_index((*a));
		if (nodes_to_index((*a), min_index) <= n - min_index - \
				nodes_to_index((*a), min_index))
			while ((*a)->s_index != min_index)
				ra(a);
		else
			while ((*a)->s_index != min_index)
				rra(a);
		pb(b, a);
		length--;
	}
	sort_three(a, length);
	iter = 0;
	while (iter++ < n - 3)
		pa(a, b);
}
