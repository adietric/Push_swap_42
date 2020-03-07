/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:08:43 by adietric          #+#    #+#             */
/*   Updated: 2019/04/05 10:28:10 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

int			ft_abs(int nb)
{
	if (nb == -2147483648)
		return (2147483647);
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int			exite(t_var *v)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int			gere_loop(t_var *v)
{
	v->graph.taille_fenetre = 1000;
	v->graph.i = -1;
	v->graph.valeur_max = v->valeur_max;
	if (v->graphique != 0)
		gere_loop_1(v);
	v->graphique++;
	if (v->nb_a > 0)
		gere_loop_2(v);
	v->graph.x = -1;
	while (++v->graph.x < v->graph.taille_fenetre)
		mlx_pixel_put(v->mlx_ptr, v->win_ptr,
			v->graph.taille_fenetre / 2 + 20, v->graph.x, 0xFFFFFF);
	if (v->nb_b > 0)
		gere_loop_3(v);
	return (0);
}

void		ft_graphique(t_var *v)
{
	int		taille_fenetre;
	int		i;

	i = 0;
	taille_fenetre = 1000;
	v->start = 0;
	v->ii = 0;
	v->graphique = 0;
	v->mlx_ptr = mlx_init();
	v->win_ptr = mlx_new_window(v->mlx_ptr, taille_fenetre + 40,
		taille_fenetre, "Swap");
	if (v->graphique == 0)
	{
		v->valeur_max = ft_abs(v->tab_a[0]);
		while (++i < v->nb_a - 1)
			if (ft_abs(v->tab_a[i + 1]) >= v->valeur_max)
				v->valeur_max = ft_abs(v->tab_a[i + 1]);
	}
	mlx_key_hook(v->win_ptr, exite, v);
	mlx_loop_hook(v->mlx_ptr, gere_loop, v);
	mlx_loop(v->mlx_ptr);
}
