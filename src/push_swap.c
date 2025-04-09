/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:12 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/09 17:35:53 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	*nbs;
	char	**temp;

	i = 0;
	j = 0;
	if (argc < 2)
		return (-1);
	//Prueba Split

	//printf("ft_split: %s", );

	
	if (argc == 2 && (ft_isdigit(ft_atoi(argv[1])) && argv[2] != NULL))
	{
		printf("PINGUITA\n");
		nbs = sanitize_args(ft_strlen2(argv), ft_split(argv[0], ' '));
	}
	else 
		nbs = sanitize_args(ft_strlen2(argv), argv);

	if (!nbs)
		return (-1);

	return (free (nbs), 0);
}
	// while (argv[i])
	// 	printf("-> '%s'\n", argv[i++]);
	// printf("-------------------\n");
