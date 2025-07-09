/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:29:03 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/02 16:17:38 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Sets the length of the processed input.
 *
 * @param input Pointer to the processed input.
 * @param n Length to set.
 */
void	set_length(t_processed_input *input, int n)
{
	input->length = n;
}

/**
 * @brief Processes and sanitizes command-line input arguments.
 *
 * Handles various input styles, including:
 * - A single quoted string:      ./program "1 2 3"
 * - Multiple separate arguments: ./program 1 2 3
 * - Mixed inputs:                ./program "1 2" 3 "4 5"
 *
 * Splits and sanitizes all arguments to produce a flat,
 * unified list of strings.
 * If the input is empty or only contains spaces,
 * sets length to -1 and returns.
 *
 * Frees any temporary memory used during processing.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of argument strings.
 * @return t_processed_input Struct containing the parsed and sanitized input
 * */
t_processed_input	manage_input(int argc, char **argv)
{
	t_processed_input	input;
	char				**first_arg;

	if (ft_str_is_only_space(argv[1]))
		return (set_length(&input, -1), input);
	first_arg = ft_split(argv[1], ' ');
	if (first_arg && *first_arg && **first_arg && argc == 2
		&& (ft_strlen2(first_arg) >= 1))
		input = sanitize_args(ft_strlen2(first_arg), first_arg);
	else
		input = sanitize_args((argc - 1), (argv + 1));
	return (ft_free_array(first_arg), input);
}
