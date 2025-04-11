/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:05:04 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/11 11:07:54 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../push_swap.h"

int		*sanitize_args(int argc, char **argv);
void	print_error(void);
int		ft_strlen2(char **str);
void	ft_free_array(char **str);

#endif
