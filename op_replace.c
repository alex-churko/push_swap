/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:47:17 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/25 17:30:12 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list_p **b, int j)
{
	t_list_p	*tmp;

	tmp = *b;
	while ((*b)->next != 0)
		*b = (*b)->next;
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list_p **b, int j)
{
	t_list_p	*tmp;

	tmp = *b;
	while ((*b)->next != 0)
		*b = (*b)->next;
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list_p **a, t_list_p **b, int j)
{
	ft_ra(a, 1);
	ft_rb(b, 1);
	if (j == 0)
		write(1, "rr\n", 3);
}
