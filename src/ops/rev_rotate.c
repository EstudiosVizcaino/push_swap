/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:07:19 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/02 16:04:14 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * @brief Moves the last node of a linked list to the front (reverse rotate).
 *
 * Does nothing if the list is empty or has only one node.
 *
 * @param head Pointer to the pointer of the head node.
 */
static void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!(*head) || !((*head)->next))
		return ;
	current = *head;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = *head;
	*head = tmp;
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
