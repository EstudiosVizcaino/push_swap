/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:11:55 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/02 16:02:58 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * @brief Swaps the first two nodes of a linked list stack.
 *
 * Does nothing if the list is empty or has only one node.
 *
 * @param head Pointer to the pointer of the head node.
 */
static void	swap(t_stack_node **head)
{
	t_stack_node	*tmp;

	if (!head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (tmp->next);
	tmp->next = (*head)->next;
	(*head)->next = tmp;
}

/**
 * @brief Swaps the top two nodes of stack A and writes 
 * "sa\n" to standard output.
 * @param a Pointer to the pointer of the head of stack A.
 */
void	sa(t_stack_node **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

/**
 * @brief Swaps the top two nodes of stack B and writes 
 * "sb\n" to standard output.
 * @param b Pointer to the pointer of the head of stack B.
 */
void	sb(t_stack_node **b)
{
	swap(b);
	write (1, "sb\n", 3);
}

/**
 * @brief Swaps the top two elements of both stacks A and B simultaneously 
 * and writes "ss\n" to standard output.
 * @param a Pointer to the pointer of the head of stack A.
 * @param b Pointer to the pointer of the head of stack B.
 */
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write (1, "ss\n", 3);
}
