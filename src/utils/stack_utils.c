/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:29 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/03 18:39:06 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	//t_stack_node	*last_node;

	if (!stack)
		return ;
	node = ft_calloc(1, sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
}

void	stack_init(t_stack_node **stack_a, t_processed_input input)
{
	int				i;
	//t_stack_node	*last_node;
	i = 0;
	if (!input.nbs || !stack_a || input.length == -1)
		return (free (input.nbs));
	printf("\n"); /** Shows received numbers with position in the array */
	while (i < input.length)
	{
		printf("%i | %i\t", input.nbs[i],
			get_position(input.index, input.nbs[i]));
		++i;
	}
	if (0)
		append_node(stack_a, 2);
	printf("\n");
	free (input.nbs);
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
