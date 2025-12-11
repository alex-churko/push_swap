/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:57:49 by ochurko           #+#    #+#             */
/*   Updated: 2024/01/26 15:36:02 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_list1
{
	struct s_list1	*next;
	int				numb;
	int				index;
}	t_list_p;

int			ft_min(t_list_p **b);
int			ft_max(t_list_p **b);
int			ft_atoi_p(const char *str);
int			ft_max_pos(t_list_p **a);
int			ft_pos(t_list_p *a, int index);
int			ft_sort_flag(t_list_p *a);
int			ft_sort_check(t_list_p *a);
int			ft_pos_b(t_list_p *b, int numb);
int			ft_pos(t_list_p *a, int index);
int			ft_lstsize_p(t_list_p *lst);
int			ft_numb_pos_index(t_list_p **a, t_list_p **b, int i, int j);
void		ft_sort(t_list_p **a);
void		ft_sa(t_list_p **b, int j);
void		ft_sb(t_list_p **b, int j);
void		ft_ra(t_list_p **b, int j);
void		ft_rb(t_list_p **b, int j);
void		ft_rra(t_list_p **a, int j);
void		ft_rrb(t_list_p **b, int j);
void		ft_pa(t_list_p **a, t_list_p **b, int j);
void		ft_pb(t_list_p **a, t_list_p **b, int j);
void		ft_index(t_list_p **a);
void		ft_three(t_list_p **a);
void		ft_back_b(t_list_p **a, t_list_p **b, int i);
void		ft_ss(t_list_p **a, t_list_p **b, int j);
void		ft_rrr(t_list_p **a, t_list_p **b, int j);
void		ft_rr(t_list_p **a, t_list_p **b, int j);
void		ft_error(t_list_p **a);
void		ft_free_lst(t_list_p **a);
void		ft_free_argv(char	**temp);
void		ft_lstadd_back_p(t_list_p **lst, t_list_p *new);
t_list_p	*ft_lstadd_p(int numb);
t_list_p	*ft_lastlst(t_list_p *a);
char		*get_next_line(int fd);
char		ft_chek_argv(char *argv);
int			ft_cmp_argv(char **temp, int i);
void		ft_arg_str(t_list_p **a, char *str);
void		ft_arg_3(char **argv, t_list_p	**a);

#endif