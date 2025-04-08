/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:43:05 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/08 19:48:28 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strlen2(char **str)
{
	int	count;
	int	j;

	count = 0;
	while (str[count])
		++count;
	return (count);
}