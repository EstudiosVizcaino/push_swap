/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:43:05 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/03 16:22:33 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Counts the number of strings in a NULL-terminated array of strings.
 *
 * @param str NULL-terminated array of strings.
 * @return int The number of strings in the array.
 */
int	ft_strlen2(char **str)
{
	int	count;

	count = 0;
	while (str[count])
		++count;
	return (count);
}

/**
 * @brief Frees a NULL-terminated array of strings and all its elements.
 *
 * Safely frees each string in the array and then frees the array itself.
 *
 * @param str NULL-terminated array of strings to free.
 */
void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == NULL)
		return ;
	while (str[i])
		free(str[i++]);
	free (str);
}

/**
 * @brief Returns the index of the number given inside the array.
 * @param n Value to find.
 * @param arr Integer array (must contain n).
 * @return Index of n in arr.
 */
int	get_index(int n, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != n)
		i++;
	return (i);
}

/**
 * @brief Approximates the square root of a number.
 * @param number The number to compute the square root of.
 * @return Closest integer to the square root of number.
 */
int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	if (i * i == number)
		return (i);
	return (i - 1);
}

/**
 * @brief Sorts an array of integers in ascending order using
 * the insertion sort algorithm.
 *
 * This function modifies the original array in-place.
 *
 * @param array Pointer to the array of integers to sort.
 * @param n Number of elements in the array.
 */
void	insertion_sort(int array[], int n)
{
	int	element;
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		element = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > element)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = element;
		i++;
	}
}
