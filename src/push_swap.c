/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:12 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/26 00:41:09 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <stdio.h>

t_processed_input	manage_input(int argc, char **argv)
{
	t_processed_input	input;
	char				**first_arg;

	if (ft_str_is_only_space(argv[1]))
		input.length = -1;
	first_arg = ft_split(argv[1], ' ');
	if (first_arg && *first_arg && **first_arg && argc == 2
		&& (ft_strlen2(first_arg) >= 1))
		input = sanitize_args(ft_strlen2(first_arg), first_arg);
	else
		input = sanitize_args((argc - 1), (argv + 1));
	return (ft_free_array(first_arg), input);
}

int	main(int argc, char **argv)
{
	t_processed_input	input;
	t_stack_node		*a;
	//t_stack_node		*b;
	a = NULL;
	//b = NULL;
	if (argc < 2)
		return (-1);
//Implement error checking and frees into stack_init
	input = manage_input(argc, argv);
	if (input.length == -1)
		print_error();
	stack_init(&a, input.nbs);
	printf("ARGC (1) = %i\n", (argc - 1));
	printf("ARGC (2) = %i\n", input.length);
	return (0);
}
	// while (argv[i])
	// 	printf("-> '%s'\n", argv[i++]);
	// printf("-------------------\n");
