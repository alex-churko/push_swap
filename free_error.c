/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:24:44 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/24 14:44:18 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_argv(char	**temp)
{
	int		i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		temp[i] = NULL;
		i++;
	}
	free(temp);
	temp = NULL;
}

void	ft_free_lst(t_list_p **a)
{
	t_list_p	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		(*a)->numb = 0;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}

void	ft_error(t_list_p **a)
{
	ft_free_lst(a);
	write(2, "Error\n", 6);
	exit (1);
}
