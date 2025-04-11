/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:12 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/11 11:27:30 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*nbs;
	char	**first_arg;

	if (argc < 2)
		return (-1);
	
	first_arg = ft_split(argv[1], ' ');
	if (first_arg && *first_arg && **first_arg && (ft_strlen2(first_arg) > 1) && argc == 2)
		nbs = sanitize_args(ft_strlen2(first_arg), first_arg);
	else
		nbs = sanitize_args((argc - 1), (argv + 1));
	if (!nbs)
		return (ft_free_array(first_arg), -1);
	return (free (nbs), ft_free_array(first_arg), 0);
}
	// while (argv[i])
	// 	printf("-> '%s'\n", argv[i++]);
	// printf("-------------------\n");
