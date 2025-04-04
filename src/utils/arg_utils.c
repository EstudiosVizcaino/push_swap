/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:04:35 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/04 12:02:47 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	**twin_killer(int **nbs)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	j = 0;
	while (nbs[i][j])
	{
		
	}
	return (0);
}

int	*sanitize_args(int argc, char **nbs)
{
	int	i;
	int	j;
	int	*temp;

	i = 0;
	j = 0;
	temp = malloc(argc * sizeof(int));
	if (!temp)
		return(NULL);

	while (nbs[i])
	{
		temp[j] = ft_atoi(nbs[i]);
		++i;
		++j;
	}
	j = 1;			
	while (temp[j])
	{
		printf("-> '%i'\n", temp[j]);
		++j;
	}

	return (temp);
}
