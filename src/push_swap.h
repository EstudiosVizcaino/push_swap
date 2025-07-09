/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:22:16 by cvizcain          #+#    #+#             */
/*   Updated: 2025/06/19 13:59:35 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				s_index;
	struct s_stack	*next;
}					t_stack_node;

// typedef struct s_stack_node
// {
// 	int					nbr;
// 	int					index;
// 	int					push_cost;
// 	bool				above_median;
// 	bool				cheapest;
// 	struct s_stack_node	*target_node;
// 	struct s_stack_node	*next;
// 	struct s_stack_node	*prev;	
// }	t_stack_node;

typedef struct s_processed_input
{
	int	*nbs;
	// int	*index;
	int	length;
}	t_processed_input;

#endif