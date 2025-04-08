/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:12 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/08 19:53:48 by cvizcain         ###   ########.fr       */
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
	if (argc == 2 && (ft_split(argv[1], ' ')))
	{
		printf("PINGUITA\n");
		nbs = sanitize_args((argc + 1), ft_split(argv[0], ' '));
	}

	// temp = ft_split(argv[1], ' ');

	// printf("Strlen: %i\n", ft_strlen2(temp));
	// while (j < ft_strlen2(temp))
	// {
	// 	nbs[j] = ft_atoi(temp[j]);
	// 	printf("-> %i\n", nbs[j++]);
	// }

	nbs = sanitize_args(argc, argv);
	if (!nbs)
		return (-1);
	return (free (nbs), 0);
}
	// while (argv[i])
	// 	printf("-> '%s'\n", argv[i++]);
	// printf("-------------------\n");
