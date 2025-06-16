/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:10:06 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/16 14:30:22 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
/**
 * @brief Rotates the stack so that the top node becomes the last.
 *
 * This function performs a forward rotation on a doubly linked list
 * representing a stack. The first (top) node is moved to the bottom,
 * and all other nodes shift up by one position.
 *
 * - If the stack is empty or has only one node, the function returns.
 * - Finds the last node (Last) in the stack.
 * - Sets (Last)->next to point to the current head (A).
 * - Moves the head pointer to the second node (B).
 * - Sets B->prev to NULL, making it the new head.
 * - Sets A->prev to (Last), linking the old head to the last node.
 * - Sets A->next to NULL, making it the new last node.
 *
 * @param stack Pointer to the pointer of the head node of the stack.
 */
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write (1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write (1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}
