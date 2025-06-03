/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:29 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/03 18:22:07 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	stack_init(t_stack_node **stack_a, t_processed_input input)
{
	int				i;
	t_stack_node	*node;
	//t_stack_node	*last_node;
	i = 0;
	if (!input.nbs || !stack_a || input.length == -1)
		return (free (input.nbs));
	node = ft_calloc(1, sizeof(t_stack_node));
	if (!node)
		return (free (input.nbs));
	node->next = NULL;
	node->nbr = input.nbs[i];
	*stack_a = node;
	printf("\n");
	while (i < input.length)
	{
		printf("%i | %i\t", input.nbs[i],
			get_position(input.index, input.nbs[i]));
		++i;
	}
	printf("\n");
	free (input.nbs);
	free (node);
}

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
