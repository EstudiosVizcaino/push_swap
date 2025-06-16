/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:12:06 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/16 15:15:32 by cvizcain         ###   ########.fr       */
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

/**
 * @brief Sorts a stack of exactly three nodes in ascending order.
 *
 * This function assumes that the stack `a` contains exactly three nodes.
 * It finds the node with the maximum value and rotates or reverse-rotates
 * the stack to move it to the correct position. Then, if the top two nodes
 * are in the wrong order, it swaps them. The function uses the stack 
 * operations `ra`, `rra`, and `sa` to sort the elements.
 *
 * @param a Pointer to the head pointer of the stack to sort.
 */
void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
	print_stack(*a);
}
