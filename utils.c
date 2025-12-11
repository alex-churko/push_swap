/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:25:51 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/24 16:25:55 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_index(t_list_p **a, int max, int size, int i)
{
	t_list_p	*tmp;
	int			num;

	tmp = *a;
	while (tmp)
	{
		if (max == tmp->numb && size == ft_lstsize_p(*a))
			tmp->index = size;
		if ((max - tmp->numb) < i && (max - tmp->numb) > 0)
		{
			tmp->index = size - 1;
			num = tmp->numb;
			i = max - tmp->numb;
		}
		tmp = tmp->next;
	}
	return (num);
}

void	ft_index(t_list_p **a)
{
	t_list_p	*tmp;
	int			size;
	int			i;
	int			max;

	size = ft_lstsize_p(*a);
	tmp = *a;
	max = ft_max(a);
	i = max - ft_min(a);
	while (size > 1)
	{
		max = ft_init_index(a, max, size, i);
		size--;
	}
}

int	ft_min(t_list_p **b)
{
	t_list_p	*tmp;
	long int	i;

	tmp = (*b);
	i = tmp->numb;
	while (tmp)
	{
		if (tmp->numb < i)
			i = tmp->numb;
		tmp = tmp->next;
	}
	return ((int)i);
}

int	ft_max(t_list_p **b)
{
	t_list_p	*tmp;
	int			i;

	tmp = (*b);
	i = (*b)->numb;
	while (tmp)
	{
		if (tmp->numb > i)
			i = tmp->numb;
		tmp = tmp->next;
	}
	return (i);
}
