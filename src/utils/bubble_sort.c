/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:42:45 by cvizcain          #+#    #+#             */
/*   Updated: 2025/05/20 17:50:11 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	*intcpy(int *src, int len)
{
	int	*dest;
	int	i;

	i = 0;
	dest = ft_calloc(len + 1, sizeof(int));
	while (i < len)
	{
		dest[i] = src[i];
		++i;
	}
	return (dest);
}

int	*bubble_sort(int *tab, int len)
{
	int	i;
	int	j;
	int	max_nb;
	int	min_nb;
	int	count;
	int	*temp;

	i = 0;
	count = 0;
	temp = intcpy(tab, len);
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (temp[j] > temp[j + 1])
			{
				max_nb = temp[j];
				min_nb = temp[j + 1];
			 temp[j] = min_nb;
			 temp[j + 1] = max_nb;
				count++;
			}
			j++;
		}
		i++;
	}
	printf("Movement Count: %i\n", count);
	return (temp);
}

/**int	main(void)
{
	int	nbs[10] =  {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
	int	len =  10;
	printf("Max: %i\n", max(nbs, len));
}
**/