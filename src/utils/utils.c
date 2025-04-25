/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:43:05 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/25 18:13:25 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//Fix condition to include input by string variable. Compare to main's comprobation
int	ft_getargc(int argc, char **argv)
{
	int			i;
	char	**aux;

	i = 0;

	if ((ft_strlen2(argv) <= 2 && argc == 2) || argc != 2)
		argc--;
	else
	{
		while (argv[i])
		{
			if (ft_strchr(argv[i], ' '))
			{
				aux = ft_split(argv[i], ' ');
				argc += (ft_strlen2(aux) - 1);
				ft_free_array(aux);
			}
			++i;
		}
	}
	
	return (argc);
}

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
