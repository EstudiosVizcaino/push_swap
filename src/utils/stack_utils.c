/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:29 by cvizcain          #+#    #+#             */
/*   Updated: 2025/05/20 17:08:28 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	stack_init(t_stack_node **stack, t_processed_input input)
{
	int				i;
	t_stack_node	*node;
	//t_stack_node	*last_node;
	i = 0;
	if (!input.nbs || !stack || input.length == -1)
		return (free (input.nbs));
	node = ft_calloc(1, sizeof(t_stack_node));
	if (!node)
		return (free (input.nbs));
	node->next = NULL;
	node->nbr = input.nbs[i];
	*stack = node;
	printf("\n");
	while (i < input.length)
	{
		printf("%i | %i\t", input.nbs[i], get_position(input.index, input.nbs[i]));
		++i;
	}
	printf("\n");
	free (input.nbs);
	free (node);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
