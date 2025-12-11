/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:24:29 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/25 17:30:58 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_list_p **b, int j)
{
	t_list_p	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}

void	ft_sa(t_list_p **b, int j)
{
	t_list_p	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

void	ft_ss(t_list_p **a, t_list_p **b, int j)
{
	ft_sb(b, 1);
	ft_sa(a, 1);
	if (j == 0)
		write(1, "ss\n", 3);
}
