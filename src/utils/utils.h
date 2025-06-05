/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:05:04 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/05 17:23:21 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../push_swap.h"

t_processed_input	sanitize_args(int argc, char **argv);
void				print_error(void);
int					ft_strlen2(char **str);
void				ft_free_array(char **str);
int					*bubble_sort(int *tab, int len);
void				stack_init(t_stack_node **stack_a, t_processed_input input);
void				set_length(t_processed_input *input, int n);
int					get_position(int *nbs, int nb);
int					*intcpy(int *src, int len);
void				free_stack(t_stack_node **stack);
bool				stack_sorted(t_stack_node *stack);
int					stack_len(t_stack_node *stack);

#endif
