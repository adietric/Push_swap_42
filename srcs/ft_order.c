/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 21:34:28 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 15:19:34 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

int			ft_ord_2(t_var *v)
{
	int		i;
	int		l;
	int		tmp;

	i = -1;
	while (++i != v->nb_b)
		v->tab_ord[i] = v->tab_b[i];
	i = 0;
	while (i != v->nb_b - 1)
	{
		l = 0;
		if (v->tab_ord[i] > v->tab_ord[i + 1])
		{
			tmp = v->tab_ord[i];
			v->tab_ord[i] = v->tab_ord[i + 1];
			v->tab_ord[i + 1] = tmp;
			i = 0;
			l = 1;
		}
		if (l == 0)
			i++;
	}
	return (v->tab_nb_p[v->last_case] == 1) ? (v->tab_ord[v->nb_b - 1]) :
	(v->tab_ord[v->nb_b - (v->tab_nb_p[v->last_case] / 2)]);
}

int			ft_ord_1(t_var *v, int tab)
{
	int		i;
	int		l;
	int		tmp;

	if (tab == 2)
		return (ft_ord_2(v));
	i = -1;
	while (++i != v->nb_a)
		v->tab_ord[i] = v->tab_a[i];
	i = 0;
	while (i != v->nb_a - 1)
	{
		l = 0;
		if (v->tab_ord[i] < v->tab_ord[i + 1])
		{
			tmp = v->tab_ord[i];
			v->tab_ord[i] = v->tab_ord[i + 1];
			v->tab_ord[i + 1] = tmp;
			i = 0;
			l = 1;
		}
		if (l == 0)
			i++;
	}
	return (v->tab_ord[(v->nb_a + v->nb_a_good - 1) / 2]);
}

void		ft_order(t_var *v)
{
	int		i;
	int		y;

	if (v->justonce == 0)
	{
		i = 0;
		y = v->nb_a - 1;
		while (i < y)
		{
			v->m = v->tab_a[y];
			v->tab_a[y] = v->tab_a[i];
			v->tab_a[i] = v->m;
			i++;
			y--;
		}
	}
}
