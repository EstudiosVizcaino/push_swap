/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:29 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/09 18:48:46 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Checks if the linked list stack is sorted in ascending order.
 *
 * Iterates through the stack and verifies that each node's data is less than
 * or equal to the next node's data.
 *
 * @param stack Pointer to the head of the stack.
 * @return int Returns 1 if sorted in ascending order, 0 otherwise.
 */
int	is_sorted(t_stack_node *stack)
{
	t_stack_node	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/**
 * @brief Finds the minimum s_index value in a linked list stack.
 *
 * Iterates through the stack nodes and returns the smallest s_index found.
 *
 * @param stack Pointer to the head of the stack.
 * @return int The minimum s_index value.
 */
int	get_min_index(t_stack_node *stack)
{
	t_stack_node	*current;
	int				min_index;

	current = stack;
	min_index = current->s_index;
	while (current->next)
	{
		current = current->next;
		if (current->s_index < min_index)
			min_index = current->s_index;
	}
	return (min_index);
}

/**
 * @brief Initializes a linked list stack from an integer array.
 *
 * Pushes the elements from the array onto the stack in reverse order,
 * sorts the array using insertion sort, then assigns an index (`s_index`)
 * to each node based on the sorted array positions.
 *
 * @param stack Pointer to the initial stack (can be NULL).
 * @param nb Array of integers to initialize the stack.
 * @param size Number of elements in the array.
 * @return t_stack_node* Pointer to the initialized stack.
 */
t_stack_node	*init(t_stack_node *stack, int *nb, int size)
{
	int				i;
	t_stack_node	*tmp;

	i = size - 1;
	while (i >= 0)
	{
		push_stack(&stack, 0, nb[i]);
		i--;
	}
	insertion_sort(nb, size);
	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->s_index = get_index(tmp->data, nb);
		tmp = tmp->next;
	}
	return (stack);
}

/**
 * @brief Frees nodes from a linked list stack.
 *
 * Frees all nodes in the stack unless the parameter `str` points exactly
 * to the string literal "SINGLE_NODE", in which case only the first node
 * is freed.
 *
 * @param stack Pointer to the pointer of the stack head.
 * @param str Control string to optionally free only one node.
 */
void	free_stack(t_stack_node **stack, char *str)
{
	t_stack_node	*tmp;
	int				data;
	char			*instruction;

	if (!stack)
		return ;
	instruction = "SINGLE_NODE";
	while (*stack)
	{
		tmp = *stack;
		data = tmp->data;
		*stack = tmp->next;
		free(tmp);
		tmp = NULL;
		if (str == instruction)
			return ;
	}
	if (data)
		data = 0;
}

/**
 * @brief Adds a new node at the beginning of the stack (linked list).
 *
 * Allocates memory for a new node and sets its data and index.
 * The new node becomes the new head of the stack.
 *
 * @param stack Pointer to the pointer of the head node.
 * @param index The index to assign to the new node.
 * @param data The data to assign to the new node.
 */
void	push_stack(t_stack_node **stack, int index, int data)
{
	t_stack_node	*tmp;

	tmp = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!tmp)
		return ;
	tmp->data = data;
	tmp->s_index = index;
	tmp->next = *stack;
	*stack = tmp;
}
