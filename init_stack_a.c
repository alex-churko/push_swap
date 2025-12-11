/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:15:53 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/26 15:25:23 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_chek_argv(char *argv)
{
	char	numb;
	int		i;

	numb = 'f';
	i = 0;
	if (!argv[i])
		return (numb);
	while (argv[i])
		i++;
	while (argv[i - 1] >= '0' && argv[i - 1] <= '9')
		i--;
	if (argv[i - 1] == '-' || argv[i - 1] == '+')
		i--;
	while (argv[i - 1] >= 9 && argv[i - 1] <= 13)
		i--;
	if (i == 0 && argv[i])
		numb = 't';
	return (numb);
}

int	ft_cmp_argv(char **temp, int i)
{
	int	j;
	int	tmp1;
	int	tmp2;

	while (temp[i])
	{
		if (ft_chek_argv(temp[i]) != 'f')
			tmp1 = ft_atoi_p(temp[i]);
		else
			return (0);
		j = i + 1;
		while (temp[j])
		{
			if (ft_chek_argv(temp[j]) != 'f')
				tmp2 = ft_atoi_p(temp[j]);
			else
				return (0);
			if (tmp1 == tmp2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_arg_str(t_list_p **a, char *str)
{
	char	**temp;
	int		i;
	int		flag;

	i = 0;
	temp = ft_split(str, 32);
	flag = ft_cmp_argv(temp, i);
	while (temp[i])
	{
		if (ft_chek_argv(temp[i]) != 'f' && flag != 0)
			ft_lstadd_back_p(a, ft_lstadd_p(ft_atoi_p(temp[i])));
		else
			ft_error(a);
		i++;
	}
	i = 0;
	if (temp[i] == NULL)
		ft_error(a);
	ft_free_argv(temp);
}

void	ft_arg_3(char **argv, t_list_p	**a)
{
	int			i;
	int			flag;

	i = 1;
	flag = ft_cmp_argv(argv, i);
	while (argv[i])
	{
		if (ft_chek_argv(argv[i]) != 'f' && flag != 0)
			ft_lstadd_back_p(a, ft_lstadd_p(ft_atoi_p(argv[i])));
		else
			ft_error(a);
		i++;
	}
}
