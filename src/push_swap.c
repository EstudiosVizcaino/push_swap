/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:12 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/12 21:02:13 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <stdio.h>

int	*manage_input(int argc, char **argv)
{
	int		*nbs;
	char	**first_arg;

	if (ft_str_is_only_space(argv[1]))
		return (print_error(), NULL);
	first_arg = ft_split(argv[1], ' ');
	if (first_arg && *first_arg && **first_arg && argc == 2
		&& (ft_strlen2(first_arg) >= 1))
		nbs = sanitize_args(ft_strlen2(first_arg), first_arg);
	else
		nbs = sanitize_args((argc - 1), (argv + 1));
	return (ft_free_array(first_arg), nbs);
}

int	main(int argc, char **argv)
{
	int		*nbs;

	if (argc < 2)
		return (-1);
	nbs = manage_input(argc, argv);
	if (!nbs)
		return (-1);
	return (free (nbs), 0);
}
	// while (argv[i])
	// 	printf("-> '%s'\n", argv[i++]);
	// printf("-------------------\n");
