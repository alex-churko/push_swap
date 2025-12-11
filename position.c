/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:05:28 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/24 16:16:20 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos_b(t_list_p *b, int numb)
{
	int	i;
	int	max_pos;
	int	pos;
	int	dif;

	i = 0;
	dif = 2147483647;
	pos = 0;
	max_pos = ft_max_pos(&b);
	while (b)
	{
		if (numb > b->index && numb - b->index < dif)
		{
			pos = i;
			dif = numb - b->index;
		}
		b = b->next;
		i++;
	}
	if (dif == 2147483647)
	{
		pos = max_pos - 1;
	}
	return (pos);
}

int	ft_pos_a_b(int size, t_list_p *b, int numb, int i)
{
	int	j;

	j = ft_pos_b(b, numb);
	if (i < size / 2)
	{
		if (j < ft_lstsize_p(b) / 2 && i > j)
			return (i);
		else if (j < ft_lstsize_p(b) / 2 && i < j)
			return (j);
		else
			return (ft_lstsize_p(b) - j + i);
	}
	else
	{
		if (j > ft_lstsize_p(b) / 2)
		{
			if (size - i > ft_lstsize_p(b) - j)
				return (size - i);
			else
				return (ft_lstsize_p(b) - j);
		}
		else
			return (j + size - i);
	}
}

int	ft_numb_pos_index(t_list_p **a, t_list_p **b, int i, int j)
{
	int			numb;
	int			size;
	int			index;
	t_list_p	*tmp;
	t_list_p	*tmp_b;

	numb = 2147483647;
	tmp = *a;
	tmp_b = *b;
	size = ft_lstsize_p(tmp);
	while (tmp)
	{
		if (ft_pos_a_b(size, tmp_b, tmp->index, i) < numb)
		{
			numb = ft_pos_a_b(size, tmp_b, tmp->index, i);
			index = tmp->index;
		}
		tmp = tmp->next;
		i++;
	}
	if (j == 1)
		return (index);
	else
		return (numb);
}

int	ft_max_pos(t_list_p **a)
{
	t_list_p	*tmp;
	int			i;
	int			numb;
	int			pos;

	i = 0;
	numb = (*a)->numb;
	tmp = (*a)->next;
	while (tmp)
	{
		if (numb < tmp->numb)
			numb = tmp->numb;
		tmp = tmp->next;
	}
	tmp = (*a);
	while (tmp)
	{
		if (numb == tmp->numb)
			pos = i;
		tmp = tmp->next;
		i++;
	}
	pos++;
	return (pos);
}

int	ft_pos(t_list_p *a, int index)
{
	t_list_p	*tmp;
	int			i;

	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index == index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}
