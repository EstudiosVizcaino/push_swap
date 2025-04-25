/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:05:04 by cvizcain          #+#    #+#             */
/*   Updated: 2025/04/26 00:37:44 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../push_swap.h"

t_processed_input		sanitize_args(int argc, char **argv);
void					print_error(void);
int						ft_strlen2(char **str);
void					ft_free_array(char **str);
int						*brutal_sort(int *tab, int len);
void					stack_init(t_stack_node **stack, int *nbs);
int						ft_getargc(int arc, char **argv);

#endif
