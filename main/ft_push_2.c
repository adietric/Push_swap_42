/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:58:31 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 17:54:59 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void		ft_psn_5(t_var *v)
{
	while (v->nb_b != 0)
	{
		v->print_action = 1;
		ft_action_2(v, "pa");
		v->nb_d_action_tot++;
	}
}

void		ft_psn_4(t_var *v, int **tab_a, int **tab_b, int i)
{
	int		r;

	r = (v->a_or_b % 2 == 0) ? (1) : (2);
	if (i < v->nb_d_action)
	{
		v->print_action = 1;
		ft_cpy_tab(v, tab_a, 3);
		ft_cpy_tab(v, tab_b, 5);
		ft_back_to_start(v);
		ft_algo_tab_1(v, 1, &v->tab_ord, r);
		v->print_action = 0;
	}
	else
	{
		v->print_action = 1;
		ft_cpy_tab(v, tab_a, 3);
		ft_cpy_tab(v, tab_b, 5);
		ft_back_to_start(v);
		ft_algo_tab_1(v, 2, &v->tab_ord, r);
		v->print_action = 0;
	}
	v->nb_d_action_tot = v->nb_d_action_tot + v->nb_d_action;
	v->nb_a_static = v->nb_a;
	v->nb_b_static = v->nb_b;
}

void		ft_psn_3(t_var *v, int **tab_a, int **tab_b, int l)
{
	if (l == 1)
	{
		ft_cpy_tab(v, tab_a, 2);
		ft_cpy_tab(v, tab_b, 4);
	}
	if (l == 2)
	{
		ft_cpy_tab(v, tab_a, 3);
		ft_cpy_tab(v, tab_b, 5);
		ft_back_to_start(v);
	}
	if (l == 3)
	{
		v->a_or_b++;
		v->stop = (ft_check_tab(v, 1) == -1 && ft_check_tab(v, 2) == -1
		&& (v->nb_a_good == v->nb_a) && (v->nb_b_good == v->nb_b)) ? (1) : (0);
	}
}

void		ft_psn_2(t_var *v, int **tab_ord, int tab)
{
	int		nb;
	char	*c;

	v->print_action = 1;
	while (v->pivot == v->pivot)
	{
		nb = (tab == 1) ? (tab_ord[0][0]) : (tab_ord[0][v->nb_a + v->nb_b - 1]);
		if (ft_check_tab(v, tab) == -1)
			break ;
		if (ft_check_position(v, nb, tab) == 1)
		{
			c = (tab == 1) ? ("rra") : ("rrb");
			ft_action_2(v, c);
			v->nb_d_action_tot++;
		}
		else if (ft_check_position(v, nb, tab) != 1)
		{
			c = (tab == 1) ? ("ra") : ("rb");
			ft_action_2(v, c);
			v->nb_d_action_tot++;
		}
	}
	v->print_action = 0;
}

void		ft_psn_1(t_var *v, int **tab_ord, int r, int l)
{
	if (l == 1)
	{
		ft_stock_nb_p(v);
		v->nb_a_static = v->nb_a;
		v->nb_b_static = v->nb_b;
	}
	if (l == 2)
	{
		ft_check_good_nb(v, tab_ord);
		v->pivot = ft_ord_1(v, r);
		ft_cpy_tab(v, tab_ord, 1);
	}
	if (l == 3)
	{
		ft_check_good_nb(v, tab_ord);
		ft_repositionne(v, r);
	}
}
