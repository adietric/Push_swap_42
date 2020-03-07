/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdm_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:26:31 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 18:06:26 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void		ft_doublons(t_var *v)
{
	int		i;
	int		l;
	int		c;

	i = -1;
	while (++i != v->nb_a && v->error != 1)
	{
		l = -1;
		c = 0;
		while (++l != v->nb_a)
			if (v->tab_a[l] == v->tab_a[i])
			{
				c++;
				if (c >= 2)
				{
					ft_error(v);
					break ;
				}
			}
	}
}

void		ft_back_to_start(t_var *v)
{
	v->nb_a = v->nb_a_static;
	v->nb_b = v->nb_b_static;
}

void		ft_atoi_modif(char *av, t_var *v)
{
	int		i;

	i = 0;
	while (av[i] != '\0')
	{
		while (av[i] == ' ' && av[i] != '\0')
			i++;
		if (av[i] != '\0')
			v->tab_a[v->m++] = ft_atoi(&av[i], v);
		while ((av[i] == '-' || av[i] == '+'
		|| ft_isdigit(av[i]) == 1) && av[i] != '\0')
			i++;
	}
}

void		ft_initi_1(t_var *v, int i)
{
	if (!(v->tab_a = (int*)malloc(sizeof(int) * v->nb_a)))
		exit(EXIT_FAILURE);
	ft_memset(v->tab_a, 0, v->nb_a);
	if (!(v->tab_b = (int*)malloc(sizeof(int) * v->nb_a)))
	{
		free(v->tab_a);
		exit(EXIT_FAILURE);
	}
	ft_memset(v->tab_b, 0, v->nb_a);
	if (!(v->tab_ord = (int*)malloc(sizeof(int) * v->nb_a)))
	{
		free(v->tab_a);
		free(v->tab_b);
		exit(EXIT_FAILURE);
	}
	ft_memset(v->tab_ord, 0, v->nb_a);
}

void		ft_initi(t_var *v, int i)
{
	if (i == 0)
	{
		v->error = 0;
		v->a_or_b = 0;
		v->nb_p = 0;
		v->stop = 0;
		v->brk = 0;
		v->justonce = 0;
		v->print_action = 0;
		v->nb_a = 0;
		v->nb_a_good = 0;
		v->nb_b = 0;
		v->nb_b_good = 0;
		v->nb_d_action_tot = 0;
	}
	if (i == 1)
	{
		v->nb_a_static = v->nb_a;
		v->nb_b_static = 0;
		ft_initi_1(v, i);
	}
}
