/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:29:03 by cvizcain          #+#    #+#             */
/*   Updated: 2025/05/13 14:52:51 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_length(t_processed_input *input, int n)
{
	input->length = n;
}
int	*ft_get_index(t_processed_input input)
{
	int	*index;

	index = input.index;
	return (index);
}
