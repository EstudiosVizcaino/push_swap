/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:12 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/25 18:03:14 by cvizcain         ###   ########.fr       */
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
	if (nbs == 0)
	{
		ft_free_array(first_arg);
		free (nbs);
		return (0);
	}
	return (ft_free_array(first_arg), nbs);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				*nbs;
	

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (-1);
//Implement error checking and frees into stack_init
	nbs = manage_input(argc, argv);
	if (!nbs)
		return (0);
	stack_init(&a, nbs);
	printf("ARGC (1) = %i\n", (argc - 1));
	printf("ARGC (2) = %i\n", ft_getargc(argc, argv));
	return (0);
}
	// while (argv[i])
	// 	printf("-> '%s'\n", argv[i++]);
	// printf("-------------------\n");

