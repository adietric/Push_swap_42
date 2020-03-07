/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:07:55 by adietric          #+#    #+#             */
/*   Updated: 2019/04/03 13:19:18 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void		ft_cpy_tab(t_var *v, int **tab, int n)
{
	int		i;

	i = -1;
	if (n == 1 && v->justonce == 0)
	{
		while (++i != v->nb_a_static)
			tab[0][i] = v->tab_ord[i];
		v->justonce = 1;
	}
	if (n == 2)
		while (++i != v->nb_a_static)
			tab[0][i] = v->tab_a[i];
	if (n == 3)
		while (++i != v->nb_a_static)
			v->tab_a[i] = tab[0][i];
	if (n == 4)
		while (++i != v->nb_b_static)
			tab[0][i] = v->tab_b[i];
	if (n == 5)
		while (++i != v->nb_b_static)
			v->tab_b[i] = tab[0][i];
}
