/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:20:07 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 18:05:54 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void		ft_push_start_2(t_var *v, int **tab_a, int **tab_b, int **tab_ord)
{
	int		r;
	int		i;

	r = 0;
	while (v->nb_a >= 2 || v->nb_b >= 2)
	{
		ft_psn_1(v, tab_ord, r, 1);
		r = (v->a_or_b % 2 == 0) ? (1) : (2);
		ft_psn_1(v, tab_ord, r, 2);
		if (v->nb_a > 2 && v->nb_b > 2
			&& ft_check_loop_is_good(v, tab_ord, r) == -1)
			return (ft_psn_2(v, tab_ord, r));
		if (ft_check_tab_pivot(v, r) != 1)
			break ;
		ft_psn_3(v, tab_a, tab_b, 1);
		ft_algo_tab_1(v, 1, tab_ord, r);
		i = v->nb_d_action;
		ft_psn_3(v, tab_a, tab_b, 2);
		ft_algo_tab_1(v, 2, tab_ord, r);
		ft_psn_4(v, tab_a, tab_b, i);
		ft_psn_1(v, tab_ord, r, 3);
		if ((ft_check_tab(v, 1) == -1
		&& ft_check_tab(v, 2) == -1) || v->brk == 1)
			break ;
	}
}

void		ft_push_start_1(t_var *v, int **tab_a, int **tab_b, int **tab_ord)
{
	if (ft_check_tab(v, 1) != -1)
	{
		while (v->stop == 0)
		{
			if (v->nb_a == 3 && v->nb_b == 0 && ft_little_tab_1(v) == 0)
				break ;
			if (v->nb_a == 2 && v->tab_a[1] > v->tab_a[0])
			{
				v->print_action = 1;
				ft_action_2(v, "sa");
				v->nb_d_action_tot++;
				break ;
			}
			ft_push_start_2(v, tab_a, tab_b, tab_ord);
			ft_psn_3(v, tab_a, tab_b, 3);
		}
		ft_psn_5(v);
	}
	ft_free_tab_3(v, *tab_a, *tab_b, *tab_ord);
}

void		ft_push_init(t_var *v)
{
	int		*tab_a;
	int		*tab_b;
	int		*tab_ord;

	if (!(tab_a = (int*)malloc(sizeof(int) * v->nb_a)))
	{
		ft_free(v);
		exit(EXIT_FAILURE);
	}
	ft_bzeroint(tab_a, v->nb_a);
	if (!(tab_b = (int*)malloc(sizeof(int) * v->nb_a)))
	{
		ft_free_tab_1(v, tab_a);
		exit(EXIT_FAILURE);
	}
	ft_bzeroint(tab_b, v->nb_a);
	if (!(tab_ord = (int*)malloc(sizeof(int) * v->nb_a)))
	{
		ft_free_tab_2(v, tab_a, tab_b);
		exit(EXIT_FAILURE);
	}
	ft_bzeroint(tab_ord, v->nb_a);
	ft_order(v);
	ft_push_start_1(v, &tab_a, &tab_b, &tab_ord);
}

int			ft_push(int ac, char **av)
{
	t_var	v;
	int		i;

	i = 1;
	v.error = 0;
	v.m = 0;
	ft_initi(&v, 0);
	if (ac == 1)
		return (0);
	while (ac != i && (v.nb_a = v.nb_a + ft_valid(&av[i], &v)) != 0)
		i++;
	if (v.error != 0 || ac != i)
		return (ft_error(&v));
	ft_initi(&v, 1);
	i = 0;
	while (++i != ac)
		ft_atoi_modif(av[i], &v);
	ft_doublons(&v);
	if (v.error == 0 && v.nb_a != 1)
		ft_push_init(&v);
	ft_free(&v);
	return (0);
}

int			main(int ac, char **av)
{
	ft_push(ac, av);
	return (0);
}
