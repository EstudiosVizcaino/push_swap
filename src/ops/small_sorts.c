/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:12:06 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/10 15:15:32 by cvizcain         ###   ########.fr       */
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
	bubble_sort2(a);
	print_stack(*a);
}
