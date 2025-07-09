/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:55:04 by cvizcain          #+#    #+#             */
/*   Updated: 2025/07/03 16:21:31 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "../utils/utils.h"

void			print_stack(t_stack_node *stack);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
int				nodes_to_index(t_stack_node *stack, int index);
void			sort_three(t_stack_node **stack, int length);
void			s_insertion_sort(t_stack_node **a, t_stack_node **b,
					int length);
t_stack_node	*sort(t_stack_node *stack_a, t_stack_node *stack_b,
					int *numbers, int length);

#endif