/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:15:47 by adietric          #+#    #+#             */
/*   Updated: 2019/04/19 11:33:26 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

int			ft_error(t_var *v)
{
	v->error++;
	if (v->error == 1)
		write(2, "Error\n", 6);
	return (1);
}

int			ft_valid2(char *c, t_var *v)
{
	if (ft_strcmp(c, "\0") == 0)
		return (1);
	if (ft_strcmp(c, "sa") != 0 && ft_strcmp(c, "sb") != 0
		&& ft_strcmp(c, "ss") != 0 && ft_strcmp(c, "pa") != 0
		&& ft_strcmp(c, "pb") != 0 && ft_strcmp(c, "ra") != 0
		&& ft_strcmp(c, "rb") != 0 && ft_strcmp(c, "rr") != 0
		&& ft_strcmp(c, "rra") != 0 && ft_strcmp(c, "rrb") != 0
		&& ft_strcmp(c, "rrr") != 0 && c[0] != '\0')
		return (1);
	ft_stock_action(v, c);
	return (0);
}

int			ft_valid1(char **av, int i)
{
	if (ft_isdigit(av[0][i]) == 0 && av[0][i] != ' '
		&& av[0][i] != '-' && av[0][i] != '+')
		return (0);
	if ((av[0][0] == '-' || av[0][0] == '+') && (ft_isdigit(av[0][1]) == 0))
		return (0);
	if ((av[0][i] == '-' || av[0][i] == '+') && (i != 0)
		&& ((ft_isdigit(av[0][i + 1]) == 0) || av[0][i - 1] != ' '))
		return (0);
	return (1);
}

int			ft_valid(char **av, t_var *v)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (av[0][i] != '\0')
	{
		if (ft_isdigit(av[0][i]) == 1)
		{
			while (ft_isdigit(av[0][i]) == 1 && av[0][i] != '\0')
				i++;
			l++;
			if (av[0][i] == '\0')
				return (l);
		}
		if (ft_valid1(av, i) == 0)
			return (ft_error(v));
		i++;
		while (av[0][i] == ' ')
			i++;
	}
	return (l);
}
