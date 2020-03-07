/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:20:58 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 15:20:22 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void		ft_stock_nb_p(t_var *v)
{
	int i;

	i = -1;
	if (v->justonce == 0)
	{
		v->tab_nb_p = (int*)malloc(sizeof(int) * v->nb_a + 1);
		v->tab_nb_p[0] = -1;
	}
	else if (v->nb_p != 0)
	{
		while (++i < v->nb_a + v->nb_b)
		{
			if (v->tab_nb_p[i] == -1)
			{
				v->tab_nb_p[i] = v->nb_p;
				v->tab_nb_p[i + 1] = -1;
				v->nb_p = 0;
				v->last_case = i;
				break ;
			}
		}
	}
}

void		ft_stock_action(t_var *v, char *c)
{
	char	*tmp;

	tmp = ft_strdup(v->action);
	ft_strdel(&(v->action));
	v->action = ft_strjoin(tmp, c);
	ft_strdel(&tmp);
	tmp = ft_strdup(v->action);
	ft_strdel(&(v->action));
	v->action = ft_strjoin(tmp, "\n");
	ft_strdel(&tmp);
}

void		ft_repositionne(t_var *v, int tab)
{
	int		i;
	int		max;
	char	*c;

	i = -1;
	if (tab == 1)
	{
		v->print_action = 1;
		max = v->tab_a[0];
		while (++i != v->nb_a)
			max = (v->tab_a[i] > max) ? (v->tab_a[i]) : (max);
		c = (ft_check_position(v, max, tab) == 1) ? ("rra") : ("ra");
		while (v->tab_a[0] != max)
		{
			ft_action_2(v, c);
			v->nb_d_action_tot++;
		}
		v->print_action = 0;
	}
}
