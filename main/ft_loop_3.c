/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 08:46:52 by adietric          #+#    #+#             */
/*   Updated: 2019/04/05 10:35:26 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void	gere_loop_3_next_next(t_var *v)
{
	v->graph.yy = v->graph.y;
	while (v->graph.largeur_x >= 0)
	{
		v->graph.y = v->graph.yy;
		while (--v->graph.y >= 0)
		{
			mlx_pixel_put(v->mlx_ptr, v->win_ptr, 0.75
				* v->graph.taille_fenetre - v->graph.y + 40,
				v->graph.taille_fenetre - v->graph.x - v->graph.largeur_x,
				0x00d4ff);
			mlx_pixel_put(v->mlx_ptr, v->win_ptr, 0.75
			* v->graph.taille_fenetre + v->graph.y + 40,
			v->graph.taille_fenetre - v->graph.x - v->graph.largeur_x,
			0x00d4ff);
		}
		v->graph.largeur_x--;
	}
}

void	gere_loop_3_next(t_var *v)
{
	if (v->graph.y >= 0)
		gere_loop_3_next_next(v);
	else if (v->graph.y < 0)
	{
		v->graph.yy = v->graph.y;
		while (v->graph.largeur_x >= 0)
		{
			v->graph.y = v->graph.yy;
			while (++v->graph.y <= 0)
			{
				mlx_pixel_put(v->mlx_ptr, v->win_ptr, 0.75
				* v->graph.taille_fenetre - v->graph.y + 40,
				v->graph.taille_fenetre - v->graph.x - v->graph.largeur_x,
				0x0050ff);
				mlx_pixel_put(v->mlx_ptr, v->win_ptr, 0.75
				* v->graph.taille_fenetre + v->graph.y + 40,
				v->graph.taille_fenetre - v->graph.x - v->graph.largeur_x,
				0x0050ff);
			}
			v->graph.largeur_x--;
		}
	}
}

void	gere_loop_3(t_var *v)
{
	v->graph.i = v->nb_b;
	v->graph.x = 0;
	while (--v->graph.i > -1)
	{
		v->graph.largeur_x = (float)v->graph.taille_fenetre
		/ (v->nb_a + v->nb_b);
		v->graph.pourcentage = (v->graph.valeur_max / v->tab_b[v->nb_b - 1
		- v->graph.i]);
		v->graph.pourcentage = -v->graph.pourcentage;
		v->graph.y = (v->graph.taille_fenetre / 4) / v->graph.pourcentage;
		gere_loop_3_next(v);
		v->graph.x = v->graph.x + (float)v->graph.taille_fenetre
		/ (v->nb_a + v->nb_b);
		if (v->graph.x == v->graph.taille_fenetre)
			v->graph.x = v->graph.taille_fenetre - 0.00005;
	}
}
