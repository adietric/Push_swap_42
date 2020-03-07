/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:04:27 by adietric          #+#    #+#             */
/*   Updated: 2019/04/03 13:19:19 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void	ft_execution_rr(t_var *v, char c)
{
	int i;

	i = 0;
	v->tmp = (c == 'a') ? (v->tab_a[0]) : (v->tab_b[0]);
	if (c == 'a')
	{
		while (i != v->nb_a - 1)
		{
			v->tab_a[i] = v->tab_a[i + 1];
			i++;
		}
		v->tab_a[i] = v->tmp;
	}
	else if (c == 'b')
	{
		while (i != v->nb_b - 1)
		{
			v->tab_b[i] = v->tab_b[i + 1];
			i++;
		}
		v->tab_b[i] = v->tmp;
	}
}

void	ft_execution_r(t_var *v, char c)
{
	int i;

	i = (c == 'a') ? (v->nb_a) : (v->nb_b);
	v->tmp = (c == 'a') ? (v->tab_a[v->nb_a - 1]) : (v->tab_b[v->nb_b - 1]);
	i--;
	if (c == 'a')
	{
		while (i - 1 != -1)
		{
			v->tab_a[i] = v->tab_a[i - 1];
			i--;
		}
		v->tab_a[i] = v->tmp;
	}
	else if (c == 'b')
	{
		while (i - 1 != -1)
		{
			v->tab_b[i] = v->tab_b[i - 1];
			i--;
		}
		v->tab_b[i] = v->tmp;
	}
}

void	ft_execution_p(t_var *v, char c)
{
	if (c == 'a')
	{
		v->tab_a[v->nb_a] = v->tab_b[v->nb_b - 1];
		v->nb_a++;
		v->nb_b--;
	}
	else if (c == 'b')
	{
		v->tab_b[v->nb_b] = v->tab_a[v->nb_a - 1];
		v->nb_b++;
		v->nb_a--;
	}
}

void	ft_execution_s(t_var *v, char c)
{
	if (c == 'a')
	{
		v->tmp = v->tab_a[v->nb_a - 1];
		v->tab_a[v->nb_a - 1] = v->tab_a[v->nb_a - 2];
		v->tab_a[v->nb_a - 2] = v->tmp;
	}
	else if (c == 'b')
	{
		v->tmp = v->tab_b[v->nb_b - 1];
		v->tab_b[v->nb_b - 1] = v->tab_b[v->nb_b - 2];
		v->tab_b[v->nb_b - 2] = v->tmp;
	}
}
