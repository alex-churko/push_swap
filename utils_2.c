/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:23:16 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/24 17:33:58 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_flag(t_list_p *a)
{
	t_list_p	*tmp;

	tmp = a;
	while (tmp->next != 0)
	{
		if (tmp->numb < tmp->next->numb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_sort_check(t_list_p *a)
{
	t_list_p	*tmp;

	tmp = a;
	while (tmp->next != 0)
	{
		if (tmp->numb > tmp->next->numb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_atoi_p(const char *str)
{
	int			i;
	int			n;
	long int	val;
	int			flag;

	i = 0;
	n = 1;
	val = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	flag = i;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		if (str[i] >= 48 && str[i] <= 57)
			val = val * 10 + (str[i] - 48);
		i++;
	}
	if ((val * n) > 2147483647 || (val * n) < -2147483648 || flag == i)
		ft_error(NULL);
	return (val * n);
}
