/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:12 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/09 21:22:33 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		*nbs;
	char	**temp;
	char	**first_arg;

	i = 0;
	j = 0;
	if (argc < 2)
		return (-1);
	first_arg = ft_split(argv[1], ' ');
	if (first_arg && *first_arg && **first_arg && (ft_strlen2(first_arg) > 1))
		nbs = sanitize_args(ft_strlen2(first_arg), first_arg);
	else
		nbs = sanitize_args(argc, (argv + 1));
	if (!nbs)
		return (ft_free_array(first_arg), -1);
	return (free (nbs), ft_free_array(first_arg), 0);
}
	// while (argv[i])
	// 	printf("-> '%s'\n", argv[i++]);
	// printf("-------------------\n");
