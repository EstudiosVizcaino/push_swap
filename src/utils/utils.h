/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:05:04 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/25 17:33:17 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../push_swap.h"

int		*sanitize_args(int argc, char **argv);
void	print_error(void);
int		ft_strlen2(char **str);
void	ft_free_array(char **str);
int		*brutal_sort(int *tab, int len);
void	stack_init(t_stack_node **stack, int *nbs);
int		ft_getargc(int arc, char **argv);

#endif
