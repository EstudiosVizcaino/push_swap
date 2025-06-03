/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:42:45 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/03 17:26:18 by cvizcain         ###   ########.fr       */
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
	int	tmp;
	int	*temp;

	i = 0;
	temp = intcpy(tab, len);
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (temp[j] > temp[j + 1])
			{
				tmp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (temp);
}

/**int	main(void)
{
	int	nbs[10] =  {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
	int	len =  10;
	printf("Max: %i\n", max(nbs, len));
}
**/