/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:11:55 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/12 15:18:20 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
/// @brief Swaps places of first two nodes
/// @param head 
static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	(*head) = (*head)->next;
	(*head)->prev->prev = 
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
--------------------------------------------------

		A 				B				C

	*Head			Head->next		Head->next->next
	prev: NULL		prev: A			prev: B
	next: B			next: C			next: D 

