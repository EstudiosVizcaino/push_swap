/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:10:06 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/02 16:03:37 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * @brief Rotates the linked list by moving the first node to the end.
 *
 * Does nothing if the list is empty or has only one node.
 *
 * @param head Pointer to the pointer of the head node.
 */
static void	rotate(t_stack_node **head)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (*head == NULL || ((*head)->next == NULL))
		return ;
	tmp = *head;
	*head = tmp->next;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}

/**
 * @brief Rotates stack A upwards by one.
 *
 * The first element of stack A becomes the last one. This function
 * performs the operation and writes "ra\n" to standard output.
 *
 * @param a Pointer to the pointer of the head of stack A.
 */
void	ra(t_stack_node **a)
{
	rotate(a);
	write (1, "ra\n", 3);
}

/**
 * @brief Rotates stack B upwards by one.
 *
 * The first element of stack B becomes the last one. This function
 * performs the operation and writes "rb\n" to standard output.
 *
 * @param b Pointer to the pointer of the head of stack B.
 */
void	rb(t_stack_node **b)
{
	rotate(b);
	write (1, "rb\n", 3);
}

/**
 * @brief Rotates both stacks A and B upwards by one simultaneously.
 *
 * The first element of each stack becomes the last one.
 * This function performs the operation on both stacks and 
 * writes "rr\n" to standard output.
 *
 * @param a Pointer to the pointer of the head of stack A.
 * @param b Pointer to the pointer of the head of stack B.
 */
void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}
