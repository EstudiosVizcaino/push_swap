/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:07:19 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/16 14:45:10 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
/**
 * @brief Moves the last node of the stack to the top (reverse rotate).
 *
 * This function performs a reverse rotation on a doubly linked list
 * representing a stack. It moves the last node to the top, effectively
 * rotating all other nodes down by one position.
 *
 * - If the stack is empty or has only one node, the function returns.
 * - Finds the last node (Last) of the stack.
 * - (Last)->prev is now at the bottom of the stack and points to NULL
 * - Sets (Last)->next to point to the original head of the stack.
 * - Sets (Last)->prev to NULL, making it the new head.
 * - Updates the old head's 'prev' pointer to point back to (Last).
 *
 * @param stack Pointer to the pointer of the head node of the stack.
 */
static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

/**
 * @brief Reverse rotates stack A downwards by one.
 *
 * The last element of stack A becomes the first one. This function
 * performs the operation and writes "rra\n" to standard output.
 *
 * @param a Pointer to the pointer of the head of stack A.
 */
void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write (1, "rra\n", 4);
}

/**
 * @brief Reverse rotates stack B downwards by one.
 *
 * The last element of stack B becomes the first one. This function
 * performs the operation and writes "rrb\n" to standard output.
 *
 * @param b Pointer to the pointer of the head of stack B.
 */
void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write (1, "rrb\n", 4);
}

/**
 * @brief Reverse rotates both stacks A and B downwards by one 
 * simultaneously.
 *
 * The last element of each stack becomes the first one.
 * This function performs the operation on both stacks and writes 
 * "rrr\n" to standard output.
 *
 * @param a Pointer to the pointer of the head of stack A.
 * @param b Pointer to the pointer of the head of stack B.
 */
void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write (1, "rrr\n", 4);
}
