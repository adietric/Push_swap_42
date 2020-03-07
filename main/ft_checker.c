/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 00:30:50 by adietric          #+#    #+#             */
/*   Updated: 2019/04/19 12:01:26 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void		ft_check(t_var *v)
{
	int		i;

	i = 0;
	while (v->nb_a - 1 >= 0 && i < v->nb_a - 1)
	{
		if (v->tab_a[i] <= v->tab_a[i + 1])
			break ;
		i++;
	}
	if (v->nb_b != 0 || (v->nb_a - 1 >= 0 && i != v->nb_a - 1))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
}

int			ft_read_inst(t_var *v)
{
	char	*c;

	v->valid = 0;
	while (get_next_line(0, &c) == 1)
		if (ft_valid2(c, v) == 1)
			return (0);
	return (1);
}

int			ft_pasgraph(int ac, char **av)
{
	t_var	v;
	int		i;

	v.action = ft_strnew(1);
	v.m = 0;
	i = 1;
	ft_initi(&v, 0);
	if (ac == 1)
		return (ft_error(&v));
	while (ac != i && (v.nb_a = v.nb_a + ft_valid(&av[i], &v)) != 0)
		i++;
	if (ac != i || v.error != 0)
		return (ft_error(&v));
	ft_initi(&v, 1);
	i = 0;
	while (++i != ac)
		ft_atoi_modif(av[i], &v);
	ft_doublons(&v);
	ft_order(&v);
	if (v.error != 0 || ft_read_inst(&v) != 1)
		return (ft_error(&v));
	ft_action_1(&v);
	ft_check(&v);
	return (0);
}

int			ft_pregraph(int ac, char **av)
{
	t_var	v;
	int		i;

	v.action = ft_strnew(1);
	v.m = 0;
	i = 1;
	ft_initi(&v, 0);
	if (ac == 1)
		return (ft_error(&v));
	while (ac != i && (v.nb_a = v.nb_a + ft_valid(&av[i], &v)) != 0)
		i++;
	if (ac != i || v.error != 0)
		return (ft_error(&v));
	ft_initi(&v, 1);
	i = 0;
	while (++i != ac)
		ft_atoi_modif(av[i], &v);
	ft_doublons(&v);
	ft_order(&v);
	if (v.error != 0 || ft_read_inst(&v) != 1)
		return (ft_error(&v));
	ft_graphique(&v);
	return (0);
}

int			main(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && ft_strcmp("-v", av[1]) == 0))
		return (0);
	if (ft_strcmp("-v", av[1]) == 0)
		ft_pregraph(ac - 1, &av[1]);
	else
		ft_pasgraph(ac, av);
	return (0);
}
