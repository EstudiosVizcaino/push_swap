/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:12 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/08 20:09:17 by cvizcain         ###   ########.fr       */
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
	if (argc == 2)
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
