/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:12 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/04 11:58:23 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i = 1;
	int	j = 0;
	int	*nbs;

	nbs = malloc(argc * sizeof(int));
	if (!nbs)
		return (-2);	
	if (argc < 2)
		return (-1);

	while (argv[i])
	{
		printf("-> '%s'\n", argv[i]);
		++i;
	}

	nbs = sanitize_args(argc, argv);

	while (nbs[j])
	{
		printf("-> '%i'\n", nbs[j]);
		++j;
	}
		printf("PINGAAAAAA\n");


}