/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:25:03 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/26 15:27:43 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_list_p **a)
{
	int			i;

	i = ft_lstsize_p(*a);
	if (i == 3)
	{
		if ((*a)->next->numb > (*a)->next->next->numb
			&& (*a)->next->numb > (*a)->numb)
			ft_rra(a, 0);
		else if ((*a)->numb > (*a)->next->numb
			&& (*a)->numb > (*a)->next->next->numb)
			ft_ra(a, 0);
		if ((*a)->numb > (*a)->next->numb)
			ft_sa(a, 0);
	}
	else if ((*a)->numb > (*a)->next->numb)
		ft_sa(a, 0);
}

void	ft_back_b(t_list_p **a, t_list_p **b, int i)
{
	t_list_p	*tmp;

	if (ft_lstsize_p(*b) > 1)
	{
		while (ft_sort_flag(*b) == 1)
			ft_rb(b, 0);
	}
	tmp = ft_lastlst(*a);
	while (*b)
	{
		while ((tmp->numb > (*b)->numb) && i > 0)
		{
			ft_rra(a, 0);
			tmp = ft_lastlst(*a);
			i--;
		}
		ft_pa(a, b, 0);
	}
	while ((tmp->numb < (*a)->numb))
	{
		ft_rra(a, 0);
		tmp = ft_lastlst(*a);
	}
}

void	ft_half(t_list_p **tmp, t_list_p **b, int index)
{
	if (ft_pos(*tmp, index) < ft_lstsize_p(*tmp) / 2)
	{
		if (ft_pos_b((*b), index) < ft_lstsize_p(*b) / 2
			&& ft_pos((*tmp), index) > 0 && ft_pos_b((*b), index) > 0)
			ft_rr(tmp, b, 0);
		else if (ft_pos_b((*b), index) >= ft_lstsize_p(*b) / 2)
			ft_rrb(b, 0);
		else
		{
			if (ft_pos_b((*b), index) > 0)
				ft_rb(b, 0);
			else
				ft_ra(tmp, 0);
		}
	}
	else
	{
		if (ft_pos_b((*b), index) >= ft_lstsize_p(*b) / 2)
			ft_rrr(tmp, b, 0);
		else if (ft_pos_b((*b), index) < ft_lstsize_p(*b) / 2
			&& ft_pos_b((*b), index) > 0)
			ft_rb(b, 0);
		else
			ft_rra(tmp, 0);
	}
}

void	ft_algoritm(t_list_p **tmp, t_list_p **b)
{
	int			index;
	int			pos;

	pos = ft_numb_pos_index(tmp, b, 0, 0);
	index = ft_numb_pos_index(tmp, b, 0, 1);
	while (pos >= 0)
	{
		if (ft_pos(*tmp, index) < ft_lstsize_p(*tmp) / 2)
		{
			if (pos > 0)
				ft_half(tmp, b, index);
			else
				ft_pb(tmp, b, 0);
			pos--;
		}
		else
		{
			if (pos > 0)
				ft_half(tmp, b, index);
			else
				ft_pb(tmp, b, 0);
			pos--;
		}
	}
}

void	ft_sort(t_list_p **a)
{
	t_list_p	*b;
	t_list_p	*tmp;

	tmp = *a;
	b = NULL;
	if (ft_lstsize_p(tmp) > 3)
		ft_index(a);
	while (ft_lstsize_p(tmp) > 3)
	{
		if (ft_lstsize_p(b) < 2)
			ft_pb(&tmp, &b, 0);
		else
			ft_algoritm(&tmp, &b);
	}
	ft_three(&tmp);
	ft_back_b(&tmp, &b, 3);
	ft_free_lst(&tmp);
}
