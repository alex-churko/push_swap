/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:51:11 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/26 15:35:36 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error_ch(int i)
{
	if (i == 1)
		write(1, "Error\n", 6);
	else
		write(1, "OK\n", 3);
	exit(EXIT_FAILURE);
}

void	ft_check_sub(t_list_p **a, t_list_p **b, char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 1);
	else if (line[2] == 'b')
		ft_rrb(b, 1);
	else if (line[2] == 'r')
		ft_rrr(a, b, 1);
}

char	*ft_check(t_list_p **a, t_list_p **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(a, b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(a, b, 1);
	else
		ft_error_ch(1);
	if (ft_sort_check(*a) == 0 && ft_lstsize_p(*b) == 0)
		ft_error_ch(0);
	return (get_next_line(0));
}

void	ft_checker_sub(t_list_p **a, t_list_p **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (ft_sort_check(*a) == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_list_p	*a;
	t_list_p	*b;
	char		*line;

	b = NULL;
	a = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		ft_arg_str(&a, argv[1]);
	else if ((argc > 2))
		ft_arg_3(argv, &a);
	if (!a)
	{
		ft_free_lst(&a);
		ft_error_ch(1);
	}
	if (ft_lstsize_p(a) == 1)
		ft_error(&a);
	line = get_next_line(0);
	ft_checker_sub(&a, &b, line);
	ft_free_lst(&a);
	ft_free_lst(&b);
	return (0);
}
