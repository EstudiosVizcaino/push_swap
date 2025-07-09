/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:03:09 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/02 16:05:08 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * @brief Pushes the top element from the source stack to the destination stack.
 *
 * Allocates a new node for the destination and frees one node from the source.
 * Does nothing if memory allocation fails.
 *
 * @param dst Pointer to the pointer of the destination stack head.
 * @param src Pointer to the pointer of the source stack head.
 */
static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*tmp;

	tmp = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!tmp)
		return ;
	tmp->s_index = (*src)->s_index;
	tmp->data = 0;
	free_stack(src, "SINGLE_NODE");
	tmp->next = *dst;
	(*dst) = tmp;
}

/**
 * @brief Pushes the top element from stack B to stack A.
 *
 * Calls push(a, b) and writes "pa\n" to stdout.
 *
 * @param a Pointer to the pointer of stack A head.
 * @param b Pointer to the pointer of stack B head.
 */
void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write (1, "pa\n", 3);
}

/**
 * @brief Pushes the top element from stack A to stack B.
 *
 * Calls push(b, a) and writes "pb\n" to stdout.
 *
 * @param b Pointer to the pointer of stack B head.
 * @param a Pointer to the pointer of stack A head.
 */
void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write (1, "pb\n", 3);
}
