/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:56:29 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 15:20:22 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

int			ft_algo_tab_1_2(t_var *v, int l, int next_pivot)
{
	char	*c;
	int		r;

	c = NULL;
	r = (v->a_or_b % 2 == 0) ? (1) : (2);
	if (ft_check_tab_pivot(v, 1) != 1)
		return (1);
	if (next_pivot == (v->nb_a_static / 2))
		l = (ft_check_position(v, v->pivot, r) == 1) ? (2) : (1);
	if (l == 1)
		c = (v->nb_b - 2 >= 0 && v->tab_b[v->nb_b - 1] < v->tab_b[v->nb_b - 2]
		&& v->tab_b[v->nb_b - 1] < v->tab_b[0]) ? ("rr") : ("ra");
	else if (l == 2)
		c = (v->nb_b - 2 >= 0 && v->tab_b[v->nb_b - 1] > v->tab_b[v->nb_b - 2]
		&& v->tab_b[v->nb_b - 1] < v->tab_b[0]) ? ("rrr") : ("rra");
	ft_action_2(v, c);
	v->nb_d_action++;
	return (0);
}

int			ft_algo_tab_1_1(t_var *v, int next_pivot)
{
	if ((v->nb_a - 2 >= 0 && v->tab_a[v->nb_a - 1] > v->tab_a[v->nb_a - 2])
		&& (v->nb_b - 2 >= 0 && v->tab_b[v->nb_b - 1] < v->tab_b[v->nb_b - 2]))
	{
		ft_action_2(v, "ss");
		v->nb_d_action++;
	}
	else if (v->nb_a - 2 >= 0 && v->tab_a[v->nb_a - 1] > v->tab_a[v->nb_a - 2])
	{
		ft_action_2(v, "sa");
		v->nb_d_action++;
	}
	else
	{
		ft_action_2(v, "pb");
		v->nb_d_action++;
		v->nb_p = (v->print_action == 1) ? (v->nb_p + 1) : (v->nb_p);
		next_pivot++;
	}
	return (next_pivot);
}

void		ft_algo_tab_1(t_var *v, int l, int **tab_ord, int tab)
{
	int		i;
	int		next_pivot;

	v->nb_d_action = 0;
	next_pivot = 0;
	i = 0;
	while (i == 0)
	{
		if (tab == 2)
		{
			ft_algo_tab_2(v, l);
			break ;
		}
		v->brk = 0;
		ft_check_good_nb(v, tab_ord);
		if (ft_check_tab(v, 1) == -1 && v->nb_a == v->nb_a_good)
			break ;
		if (v->tab_a[v->nb_a - 1] <= v->pivot || (v->nb_a == 2 && v->nb_b == 0))
			next_pivot = ft_algo_tab_1_1(v, next_pivot);
		else if ((v->nb_a == 2 && v->nb_b == 0)
			|| ft_algo_tab_1_2(v, l, next_pivot) == 1)
			break ;
	}
}
