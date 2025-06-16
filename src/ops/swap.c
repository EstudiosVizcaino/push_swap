/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:11:55 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/16 14:13:27 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
/**
 * @brief Swaps the first two nodes of a doubly linked stack.
 *
 * If the stack contains at least two nodes, this function rearranges
 * the pointers such that the second node becomes the new head, and
 * the original head becomes the second node.
 *
 * - The head pointer moves to the second node (B); nodes stay in memory.
 * - A's 'prev' (previously NULL) is updated to point to B.
 * - A's 'next' (previously B) is updated to point to C.
 * - If C exists, its 'prev' is updated to point to A.
 * - B's 'next' is updated to point to A.
 * - B's 'prev' is set to NULL, making it the new head.
 *
 * @param head Pointer to the pointer of the head node of the stack.
 */
static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	(*head) = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write (1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write (1, "ss\n", 3);
}
