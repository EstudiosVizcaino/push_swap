/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:29 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/24 14:19:21 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	stack_init(t_stack_node **stack, int *nbs)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!nbs || !stack)
		return (free (nbs));
	node = ft_calloc(1, sizeof(t_stack_node));
	if (!node)
		return (free (nbs));
	return (free(nbs));
}
