/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:43:05 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/26 00:38:29 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strlen2(char **str)
{
	int	count;

	count = 0;
	while (str[count])
		++count;
	return (count);
}

void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == NULL)
		return ;
	while (str[i])
		free(str[i++]);
	free (str);
}

void	set_length(t_processed_input *input, int n)
{
	input->length = n;
}
