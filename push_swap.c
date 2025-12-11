/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:59:37 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/26 15:32:52 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_p	*a;

	a = NULL;
	if (argc == 2)
		ft_arg_str(&a, argv[1]);
	else if (argc < 2)
		return (1);
	else if ((argc > 2))
		ft_arg_3(argv, &a);
	if (a && ft_sort_check(a) == 1)
		ft_sort(&a);
	else
		ft_free_lst(&a);
	return (0);
}
