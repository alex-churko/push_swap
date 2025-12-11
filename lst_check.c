/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:07:16 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/24 16:28:54 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_p	*ft_lastlst(t_list_p *a)
{
	t_list_p	*tmp;

	tmp = a;
	while (tmp->next != 0)
		tmp = tmp->next;
	return (tmp);
}

t_list_p	*ft_lstadd_p(int numb)
{
	t_list_p	*new;

	new = (t_list_p *)malloc(sizeof(t_list_p));
	if (!new)
		ft_error(&new);
	new -> numb = numb;
	new -> next = NULL;
	return (new);
}

void	ft_lstadd_back_p(t_list_p **lst, t_list_p *new)
{
	t_list_p	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp -> next)
			tmp = tmp -> next;
		tmp -> next = new;
	}
}

int	ft_lstsize_p(t_list_p *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst-> next;
		++i;
	}
	return (i);
}
