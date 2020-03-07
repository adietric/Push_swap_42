/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:00:03 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 15:20:33 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void		ft_action_3(t_var *v, char *tmp)
{
	if (ft_strcmp(tmp, "rb") == 0 && v->nb_b > 1)
		ft_execution_r(v, 'b');
	else if (ft_strcmp(tmp, "rr") == 0 && v->nb_a > 1 && v->nb_b > 1)
	{
		ft_execution_r(v, 'a');
		ft_execution_r(v, 'b');
	}
	else if (ft_strcmp(tmp, "rra") == 0 && v->nb_a > 1)
		ft_execution_rr(v, 'a');
	else if (ft_strcmp(tmp, "rrb") == 0 && v->nb_b > 1)
		ft_execution_rr(v, 'b');
	else if (ft_strcmp(tmp, "rrr") == 0 && v->nb_a > 1 && v->nb_b > 1)
	{
		ft_execution_rr(v, 'a');
		ft_execution_rr(v, 'b');
	}
}

void		ft_action_2(t_var *v, char *tmp)
{
	if (ft_strcmp(tmp, "sa") == 0 && v->nb_a > 1)
		ft_execution_s(v, 'a');
	else if (ft_strcmp(tmp, "sb") == 0 && v->nb_b > 1)
		ft_execution_s(v, 'b');
	else if (ft_strcmp(tmp, "ss") == 0 && v->nb_a > 1 && v->nb_b > 1)
	{
		ft_execution_s(v, 'a');
		ft_execution_s(v, 'b');
	}
	else if (ft_strcmp(tmp, "pa") == 0 && v->nb_b > 0)
		ft_execution_p(v, 'a');
	else if (ft_strcmp(tmp, "pb") == 0 && v->nb_a > 0)
		ft_execution_p(v, 'b');
	else if (ft_strcmp(tmp, "ra") == 0 && v->nb_a > 1)
		ft_execution_r(v, 'a');
	ft_action_3(v, tmp);
	if (v->print_action == 1)
		ft_putendl(tmp);
}

void		ft_action_1(t_var *v)
{
	int		i;
	char	*tmp;

	v->start = 0;
	i = 0;
	while (v->action[i] != '\0')
	{
		while (v->action[i] != '\n')
			i++;
		tmp = ft_strsub(v->action, v->start, i - v->start);
		i++;
		ft_action_2(v, tmp);
		v->start = i;
		ft_strdel(&tmp);
	}
}
