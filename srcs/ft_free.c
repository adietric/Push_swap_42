/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:31:55 by adietric          #+#    #+#             */
/*   Updated: 2019/04/04 16:14:21 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void	ft_free(t_var *v)
{
	if (v->error == 0 && v->nb_a > 1 && v->justonce != 0)
		free(v->tab_nb_p);
	free(v->tab_a);
	free(v->tab_b);
	free(v->tab_ord);
}

void	ft_intdel(int **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

void	ft_free_tab_1(t_var *v, int *tab_a)
{
	ft_intdel(&tab_a);
	ft_free(v);
}

void	ft_free_tab_2(t_var *v, int *tab_a, int *tab_b)
{
	ft_intdel(&tab_a);
	ft_intdel(&tab_b);
	ft_free(v);
}

void	ft_free_tab_3(t_var *v, int *tab_a, int *tab_b, int *tab_ord)
{
	ft_intdel(&tab_a);
	ft_intdel(&tab_b);
	ft_intdel(&tab_ord);
}
