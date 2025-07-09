/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:12 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/19 15:07:57 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "ops/operations.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_processed_input	input;
	t_stack_node		*a;
	t_stack_node		*b;

	b = NULL;
	a = b;
	if (argc < 2)
		return (-1);
	input = manage_input(argc, argv);
	if (input.length == -1)
		return (print_error(), -1);
	a = init(a, input.nbs, input.length);
	a = sort(a, b, input.nbs, input.length);
	return (free(input.nbs), free_stack(&a, "ALL_NODES"), 0);
}
