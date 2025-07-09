/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:09:11 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/09 21:31:22 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * @brief Splits stack 'a' into chunks and pushes elements to stack 'b'.
 *
 * Divides the stack into chunks based on a calculated chunk size, then pushes
 * elements from 'a' to 'b' according to their sorted indices. Applies rotations
 * to optimize element distribution within 'b'.
 *
 * @param a Double pointer to stack 'a'.
 * @param b Double pointer to stack 'b'.
 * @param size Total number of elements in stack 'a'.
 */
static void	split_chunks_to_b(t_stack_node **a, t_stack_node **b, int size)
{
	int	target_index;
	int	chunk_size;

	target_index = 0;
	chunk_size = ft_sqrt(size) * 14 / 10;
	while (*a)
	{
		if ((*a)->s_index <= target_index)
		{
			pb(b, a);
			target_index++;
		}
		else if ((*a)->s_index <= target_index + chunk_size)
		{
			pb(b, a);
			target_index++;
			if (!((*a)->s_index <= target_index + chunk_size))
				rr(a, b);
			else
				rb(b);
		}
		else
			ra(a);
	}
}

/**
 * @brief Rebuilds stack 'a' by moving nodes from stack 'b' in descending order.
 *
 * Calculates the cost of rotating and reverse rotating to bring the target
 * element in 'b' to the top, then performs the most efficient operation to
 * push it to 'a'.
 *
 * @param a Pointer to stack 'a'.
 * @param b Pointer to stack 'b'.
 * @param stack_size Number of elements to move back into 'a'.
 * @return Updated pointer to the rebuilt stack 'a'.
 */
static t_stack_node	*rebuild_stack_a(t_stack_node *a, t_stack_node *b,
				int stack_size)
{
	int	rotate_cost;
	int	rev_rotate_cost;

	while (stack_size - 1 >= 0)
	{
		rotate_cost = nodes_to_index(b, stack_size - 1);
		rev_rotate_cost = stack_size - rotate_cost;
		if (rotate_cost <= rev_rotate_cost)
		{
			while (b->s_index != stack_size - 1)
				rb(&b);
			pa(&a, &b);
			stack_size--;
		}
		else
		{
			while (b->s_index != stack_size - 1)
				rrb(&b);
			pa(&a, &b);
			stack_size--;
		}
	}
	return (a);
}

/**
 * @brief Main sorting function dispatcher.
 *
 * Decides which sorting algorithm to use based on the size of the input.
 * Frees memory and exits early if stack A is already sorted.
 *
 * @param a Initial stack A.
 * @param b Initial stack B (empty at first).
 * @param numbers Array of the original input numbers (to be freed).
 * @param length Total number of input elements.
 * @return Pointer to the sorted stack A.
 */
t_stack_node	*sort(t_stack_node *a, t_stack_node *b,
					int *numbers, int stack_size)
{
	if (is_sorted(a))
	{
		free(numbers);
		free_stack(&a, "ALL_NODES");
		exit (0);
	}
	if (stack_size == 2)
		sa(&a);
	else if (stack_size == 3)
		sort_three(&a, stack_size);
	else if (stack_size <= 7)
		s_insertion_sort(&a, &b, stack_size);
	else if (stack_size > 7)
	{
		split_chunks_to_b(&a, &b, stack_size);
		a = rebuild_stack_a(a, b, stack_size);
	}
	return (a);
}
