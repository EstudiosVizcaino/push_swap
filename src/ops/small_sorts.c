/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:12:06 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/16 15:11:15 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_stack(t_stack_node *stack)
{
	printf("------------------\nPrinting stack: \n");
	if (!stack)
		print_error();
	while (stack)
	{
		printf("|%i| ", stack->nbr);
		stack = stack->next;
	}
	printf("\n------------------\n");
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
			rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
	print_stack(*a);
}
