/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 21:55:26 by adietric          #+#    #+#             */
/*   Updated: 2019/04/04 16:12:55 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

int			ft_check_loop_is_good(t_var *v, int **tab_ord, int tab)
{
	int		i;
	int		m;

	v->m = 0;
	i = -1;
	while (++i < v->nb_a - 1 && tab == 1)
	{
		m = -1;
		while (++m < v->nb_a + v->nb_b - 1)
			if (tab_ord[0][m] == v->tab_a[i])
				if (tab_ord[0][m + 1] != v->tab_a[i + 1])
					v->m++;
	}
	i = 0;
	while (++i < v->nb_b && tab == 2)
	{
		m = -1;
		while (++m < v->nb_a + v->nb_b - 1)
			if (tab_ord[0][m] == v->tab_b[i])
				if (tab_ord[0][m + 1] != v->tab_b[i - 1])
					v->m++;
	}
	if (v->m >= 1)
		return (1);
	return (-1);
}

int			ft_check_position(t_var *v, int nb, int l)
{
	int		i;

	i = -1;
	if (l == 1)
	{
		while (++i != v->nb_a - 1)
			if (v->tab_a[i] == nb)
				break ;
		if (i < (v->nb_a / 2))
			return (1);
	}
	if (l == 2)
	{
		while (++i != v->nb_b - 1)
			if (v->tab_b[i] == nb)
				break ;
		if (i < (v->nb_b / 2))
			return (1);
	}
	return (-1);
}

void		ft_check_good_nb(t_var *v, int **tab_ord)
{
	int		i;

	v->nb_a_good = 0;
	v->nb_b_good = 0;
	i = 0;
	if (v->tab_a[0] == tab_ord[0][0])
		while (i != v->nb_a && v->tab_a[i] == tab_ord[0][i])
		{
			v->nb_a_good++;
			i++;
		}
	i = 0;
	if (v->tab_b[0] == tab_ord[0][v->nb_a + v->nb_b - 1])
		while (i != v->nb_b
			&& v->tab_b[i] == tab_ord[0][v->nb_a + v->nb_b - 1 - i])
		{
			v->nb_b_good++;
			i++;
		}
}

int			ft_check_tab(t_var *v, int l)
{
	int		i;

	i = -1;
	if (l == 1)
	{
		while (++i < v->nb_a - 1)
			if (v->tab_a[i] < v->tab_a[i + 1])
				return (1);
	}
	else if (l == 2)
	{
		while (++i < v->nb_b - 1)
			if (v->tab_b[i] > v->tab_b[i + 1])
				return (1);
	}
	return (-1);
}

int			ft_check_tab_pivot(t_var *v, int tab)
{
	int		l;

	l = -1;
	if (tab == 1)
	{
		while (++l < v->nb_a)
			if (v->tab_a[l] < v->pivot)
				return (1);
	}
	else if (tab == 2)
	{
		while (++l < v->nb_b)
			if (v->tab_b[l] >= v->pivot)
				return (1);
	}
	return (-1);
}
