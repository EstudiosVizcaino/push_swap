/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:29 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/05 16:52:04 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = ft_calloc(1, sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
int	get_node_count(t_stack_node **stack)
{
	int	count;
	t_stack_node *tmp;

	if (!*stack)
		return (0);
	tmp = *stack;
	count = 1;
	while(tmp->next)
	{
		tmp = tmp->next;
		++count;
	}
	return (count);
}

void	stack_init(t_stack_node **stack_a, t_processed_input input)
{
	int				i;
	//t_stack_node	*last_node;
	i = 0;
	if (!input.nbs || !stack_a || input.length == -1)
		return (free (input.nbs));
	printf("\n");
	/** (IGNORE & DELETE) Shows received numbers with position in the array */
	while (i < input.length)
	{
		printf("%i | %i\t", input.nbs[i],
			get_position(input.index, input.nbs[i]));
		++i;
	}
	i = 0;
	while (i < input.length)
	{
		append_node(stack_a, input.nbs[i]);
		++i;
	}
	printf("\n");
	printf("Number of nodes: %i\n", get_node_count(stack_a));
	free (input.nbs);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
