/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:14:10 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 15:20:22 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void	gere_loop_1(t_var *v)
{
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	while (v->action[v->ii] != '\0')
	{
		while (v->action[v->ii] != '\n')
			v->ii++;
		v->graph.tmp = ft_strsub(v->action, v->start, v->ii - v->start);
		v->ii++;
		ft_action_2(v, v->graph.tmp);
		v->start = v->ii;
		ft_strdel(&v->graph.tmp);
		break ;
	}
}
