/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:05:04 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/09 18:42:56 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../push_swap.h"

t_processed_input	sanitize_args(int argc, char **argv);
void				print_error(void);
int					ft_strlen2(char **str);
void				ft_free_array(char **str);
void				stack_init(t_stack_node **stack_a, t_processed_input input);
void				set_length(t_processed_input *input, int n);
int					get_position(int *nbs, int nb);
void				free_stack(t_stack_node **stack, char *str);
bool				stack_sorted(t_stack_node *stack);
int					stack_len(t_stack_node *stack);
void				bubble_sort2(t_stack_node **stack);
t_stack_node		*find_last(t_stack_node *stack);
t_stack_node		*find_max(t_stack_node *stack);
t_processed_input	manage_input(int argc, char **argv);
int					is_sorted(t_stack_node *stack);
int					get_min_index(t_stack_node *stack);
int					get_index(int n, int *arr);
int					ft_sqrt(int number);
t_stack_node		*init(t_stack_node *stack, int *nb, int size);
void				push_stack(t_stack_node **stack, int index, int data);
void				insertion_sort(int array[], int n);

#endif
