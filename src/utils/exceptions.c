/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:49:03 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/02 15:27:41 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Prints a generic error message to the standard error output.
 *
 * Writes the string "Error\n" to file descriptor 2 (stderr).
 * Typically used for signaling runtime errors.
 */
void	print_error(void)
{
	write (2, "Error\n", 6);
}
