/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:04:35 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/08 20:06:30 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/// @brief Checks if the two-dimensional array contains only numbers and no
/// consecutive '-' or '+' signs.
/// @param nbs Two-dimensional array
/// @return Returns (1) if the array is properly formatted, and (0) if it isn't.
int	only_numbers(char **nbs)
{
	int	i;
	int	j;

	i = 1;
	while (nbs[i])
	{
		j = 0;
		while (nbs[i][j])
		{
			if ((nbs[i][j] != 43 && nbs[i][j] != 45) && !(ft_isdigit(nbs[i][j])))
				return (print_error(), 0);
			if ((nbs[i][j] == 43 && nbs[i][j + 1] == 43) ||
			(nbs[i][j] == 45 && nbs[i][j + 1] == 45))
				return (print_error(), 0);
			++j;
			if ((nbs[i][j] == 45 || nbs[i][j] == 43) && !(ft_isdigit(nbs[i][j])))
				return (print_error(), 0);
		}
		++i;
	}
	return (1);
}

/// @brief Receives int array with its length and using a dual loop, compares
/// each number with the rest of numbers found in the array. 
///
/// Eventually each number is going to end being compared with itself, setting 
/// @p count to '0'. So if the same number is found again, 
/// setting @p count to '1' the funcion will return (1).
/// @param length Length of the array
/// @param nbs Array of ints received by the program.
/// @return Returns (1) if the array has repeated numbers, (0) if it doesn't
int	has_repeated_numbers(int length, int *nbs)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	printf("Length: %i\n", length);
	while (i < length)
	{
		j = 0;
		count = -1;
		while (j < length)
		{
			if (nbs[j] == nbs[i])
				count++;
			if (count == 1)
				return (free (nbs), print_error(), 1);
			++j;
		}
		++i;
	}
	return (0);
}

/// @brief Receives a two-dimensional char array and after performing several
/// checks, returns it as a normal int array if the format is correct.
/// 
/// Uses only_numbers, to verify that the strings are properly formated as
/// numbers.
///
/// Uses ft_atoi, to convert each string to an int, while also checking if 
/// the values are within the range of MAX_INT and MIN_INT
///
/// Uses has_repeated_numbers, to ensure there are no duplicate values.
/// @param argc Number of arguments received by the program.
/// Note: The program's name counts as the first argument. so be aware of it.
/// @param nbs Two-dimensional array containing the input provided by the 
/// the user
/// @return If the array passes all the parsing tests, it will return a single
/// int array cointaining all the numbers in the order provided by the user
int	*sanitize_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	*temp;

	i = 1;
	j = 0;
	if (!(only_numbers(argv)))
		return (0);
	temp = ft_calloc((argc + 1), sizeof(int));
	if (!temp)
		return (NULL);
	while (argv[i])
	{
		temp[j++] = ft_atoi(argv[i++]);
	}
	if (has_repeated_numbers(argc, temp))
		return (0);
	return (temp);
}

// int	is_within_limits(int size, int *nbs)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (nbs[i] > INT_MAX || nbs[i] < (-2147483647 - 1))
// 		{
// 			printf("PUTAAAA\n");
// 			print_error();
// 			return (0);
// 		}
// 		++i;
// 	}
// 	return (1);
// }
