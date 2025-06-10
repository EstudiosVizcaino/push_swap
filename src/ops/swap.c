/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:11:55 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/10 15:10:03 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	swap(t_stack_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
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
