/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdm_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:22:57 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 17:56:21 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

static void		ft_little_tab_2(t_var *v)
{
	if (v->tab_a[2] > v->tab_a[1] && v->tab_a[1] < v->tab_a[0]
		&& v->tab_a[2] < v->tab_a[0])
	{
		ft_action_2(v, "sa");
		v->nb_d_action_tot += 1;
	}
	else if (v->tab_a[2] < v->tab_a[1] && v->tab_a[1] > v->tab_a[0]
		&& v->tab_a[2] < v->tab_a[0])
	{
		ft_action_2(v, "sa");
		ft_action_2(v, "ra");
		v->nb_d_action_tot += 2;
	}
}

int				ft_little_tab_1(t_var *v)
{
	v->print_action = 1;
	if (v->tab_a[2] > v->tab_a[1] && v->tab_a[1] > v->tab_a[0]
		&& v->tab_a[2] > v->tab_a[0])
	{
		ft_action_2(v, "sa");
		ft_action_2(v, "rra");
		v->nb_d_action_tot += 2;
	}
	else if (v->tab_a[2] > v->tab_a[1] && v->tab_a[1] < v->tab_a[0]
		&& v->tab_a[2] > v->tab_a[0])
	{
		ft_action_2(v, "ra");
		v->nb_d_action_tot += 1;
	}
	else if (v->tab_a[2] < v->tab_a[1] && v->tab_a[1] > v->tab_a[0]
		&& v->tab_a[2] > v->tab_a[0])
	{
		ft_action_2(v, "rra");
		v->nb_d_action_tot += 1;
	}
	ft_little_tab_2(v);
	return (0);
}
