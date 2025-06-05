/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:42:45 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/05 18:13:54 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	*intcpy(int *src, int len)
{
	int	*dest;
	int	i;

	i = 0;
	dest = ft_calloc(len + 1, sizeof(int));
	while (i < len)
	{
		dest[i] = src[i];
		++i;
	}
	return (dest);
}

int	*bubble_sort(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	*temp;

	i = 0;
	temp = intcpy(tab, len);
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (temp[j] > temp[j + 1])
			{
				tmp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (temp);
}

void	*bubble_sort2(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	current = *stack;
	while (!stack_sorted(*stack))
	{
		if (current->nbr > current->next->nbr)
		{
			tmp = current->next;
			tmp->prev = current->prev;
			tmp = tmp->next;
			temp[j] = temp[j + 1];
			temp[j + 1] = tmp;
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
		cu
		}
	}
}

/**int	main(void)
{
	int	nbs[10] =  {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
	int	len =  10;
	printf("Max: %i\n", max(nbs, len));
}
**/