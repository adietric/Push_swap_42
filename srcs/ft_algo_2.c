/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:56:29 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 15:20:22 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

int			ft_algo_tab_2_2(t_var *v, int l, int next_pivot)
{
	int		r;
	char	*c;

	c = NULL;
	r = (v->a_or_b % 2 == 0) ? (1) : (2);
	if (ft_check_tab_pivot(v, 2) != 1)
		return (1);
	if (next_pivot == (v->nb_b_static / 2))
		l = (ft_check_position(v, v->pivot, r) == 1) ? (2) : (1);
	if (l == 1)
		c = (v->nb_a - 2 >= 0 && v->tab_a[v->nb_a - 1] > v->tab_a[v->nb_a - 2]
		&& v->tab_a[v->nb_a - 1] > v->tab_a[0]) ? ("rr") : ("rb");
	else if (l == 2)
		c = (v->nb_a - 2 >= 0 && v->tab_a[v->nb_a - 1] < v->tab_a[v->nb_a - 2]
		&& v->tab_a[v->nb_a - 1] > v->tab_a[0]) ? ("rrr") : ("rrb");
	ft_action_2(v, c);
	v->nb_d_action++;
	return (0);
}

void		ft_algo_tab_2_1_next(t_var *v)
{
	v->tab_nb_p[v->last_case]--;
	v->tab_nb_p[v->last_case] = (v->tab_nb_p[v->last_case] == 0)
	? (-1) : (v->tab_nb_p[v->last_case]);
	v->last_case = (v->tab_nb_p[v->last_case] == -1) ?
	(v->last_case - 1) : (v->last_case);
	v->brk = 1;
}

int			ft_algo_tab_2_1(t_var *v, int next_pivot)
{
	if (v->nb_a - 2 >= 0 && (v->tab_a[v->nb_a - 1] > v->tab_a[v->nb_a - 2])
		&& (v->nb_b - 2 >= 0 && v->tab_b[v->nb_b - 1] < v->tab_b[v->nb_b - 2]))
	{
		ft_action_2(v, "ss");
		v->nb_d_action++;
	}
	else if (v->nb_b - 2 >= 0 && v->tab_b[v->nb_b - 1] < v->tab_b[v->nb_b - 2])
	{
		ft_action_2(v, "sb");
		v->nb_d_action++;
	}
	else if (v->nb_a - 2 >= 0 && v->tab_a[v->nb_a - 1] > v->tab_a[v->nb_a - 2])
	{
		ft_action_2(v, "sa");
		v->nb_d_action++;
	}
	else
	{
		ft_action_2(v, "pa");
		v->nb_d_action++;
		if (v->print_action == 1)
			ft_algo_tab_2_1_next(v);
		next_pivot++;
	}
	return (next_pivot);
}

void		ft_algo_tab_2(t_var *v, int l)
{
	int		i;
	int		next_pivot;

	v->nb_d_action = 0;
	next_pivot = 0;
	i = 0;
	while (i == 0 && v->nb_b != 0)
	{
		if (v->tab_b[v->nb_b - 1] >= v->pivot)
			next_pivot = ft_algo_tab_2_1(v, next_pivot);
		else if (ft_algo_tab_2_2(v, l, next_pivot) == 1)
			break ;
	}
}
