/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:42:45 by cvizcain          #+#    #+#             */
/*   Updated: 2025/05/20 15:41:07 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	*bubble_sort(int *tab, int len)
{
	int	i;
	int	j;
	int	max_nb;
	int	min_nb;
	int	count;

	i = 0;
	count = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				max_nb = tab[j];
				min_nb = tab[j + 1];
				tab[j] = min_nb;
				tab[j + 1] = max_nb;
				count++;
			}
			j++;
		}
		i++;
	}
	printf("Movement Count: %i\n", count);
	return (tab);
}

/**int	main(void)
{
	int	nbs[10] =  {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
	int	len =  10;
	printf("Max: %i\n", max(nbs, len));
}
**/