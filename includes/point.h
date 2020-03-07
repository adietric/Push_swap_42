/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:26:54 by adietric          #+#    #+#             */
/*   Updated: 2019/04/18 17:52:41 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "/usr/local/include/mlx.h"
# define BUFF_SIZE 32

typedef struct	s_graph
{
	int		taille_fenetre;
	float	x;
	float	y;
	float	valeur_max;
	float	pourcentage;
	int		i;
	float	largeur_x;
	float	yy;
	char	*tmp;
}				t_graph;

typedef struct	s_var
{
	int		justonce;
	int		print_action;
	int		m;
	int		pivot;
	int		start;
	int		tmp;
	int		stop;
	int		error;
	int		a_or_b;
	int		nb_a;
	int		nb_b;
	int		nb_a_good;
	int		nb_b_good;
	int		nb_d_action;
	int		nb_d_action_tot;
	int		nb_a_static;
	int		nb_b_static;
	int		*tab_a;
	int		*tab_b;
	int		*tab_ord;
	int		nb_p;
	int		brk;
	int		last_case;
	int		*tab_nb_p;
	char	*action;
	int		valid;
	int		ii;
	int		valeur_max;
	int		graphique;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_img;
	void	*mlx_clear;
	t_graph	graph;
}				t_var;

int				ft_push(int ac, char **av);
void			ft_initi(t_var *v, int i);
int				ft_valid(char **av, t_var *v);
int				ft_valid1(char **av, int i);
int				ft_valid2(char *c, t_var *v);
void			ft_stock_action(t_var *v, char *c);
int				ft_error(t_var *v);
void			ft_atoi_modif(char *av, t_var *v);
void			ft_push_start_1(t_var *v, int **tab_a,
				int **tab_b, int **tab_ord);
void			ft_push_start_2(t_var *v, int **tab_a,
				int **tab_b, int **tab_ord);
void			ft_psn_1(t_var *v, int **tab_ord, int r, int l);
void			ft_psn_2(t_var *v, int **tab_ord, int tab);
void			ft_psn_3(t_var *v, int **tab_a, int **tab_b, int l);
void			ft_psn_4(t_var *v, int **tab_a, int **tab_b, int i);
void			ft_psn_5(t_var *v);
void			ft_order(t_var *v);
int				ft_ord_1(t_var *v, int tab);
int				ft_ord_2(t_var *v);
void			ft_check(t_var *v);
int				ft_check_tab(t_var *v, int l);
int				ft_check_tab_pivot(t_var *v, int i);
int				ft_check_position(t_var *v, int nb, int l);
void			ft_check_good_nb(t_var *v, int **tab_ord);
int				ft_check_loop_is_good(t_var *v, int **tab_ord, int r);
void			ft_action_1(t_var *v);
void			ft_action_2(t_var *v, char *tmp);
void			ft_action_3(t_var *v, char *tmp);
void			ft_execution_s(t_var *v, char c);
void			ft_execution_p(t_var *v, char c);
void			ft_execution_r(t_var *v, char c);
void			ft_execution_rr(t_var *v, char c);
void			ft_cpy_tab(t_var *v, int **tab, int n);
void			ft_back_to_start(t_var *v);
void			ft_check_good_nb(t_var *v, int **tab_ord);
void			ft_algo_tab_1(t_var *v, int l, int **tab_ord, int tab);
int				ft_algo_tab_1_1(t_var *v, int next_pivot);
int				ft_algo_tab_1_2(t_var *v, int l, int next_pivot);
void			ft_algo_tab_2(t_var *v, int l);
int				ft_algo_tab_2_1(t_var *v, int next_pivot);
void			ft_algo_tab_2_1_next(t_var *v);
int				ft_algo_tab_2_2(t_var *v, int l, int next_pivot);
void			ft_stock_nb_p(t_var *v);
void			ft_repositionne(t_var *v, int tab);
void			ft_bzero(void *s, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_strdel(char **as);
char			*ft_strdup(const char *src1);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putchar(char c);
long long int	ft_atoi(const char *str, t_var *v);
int				ft_isdigit(int c);
void			ft_free(t_var *v);
void			ft_intdel(int **as);
void			ft_free_tab_1(t_var *v, int *tab);
void			ft_free_tab_2(t_var *v, int *tab_a, int *tab_b);
void			ft_free_tab_3(t_var *v, int *tab_a, int *tab_b, int *tab_ord);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzeroint(void *s, size_t n);
void			ft_doublons(t_var *v);
void			ft_graphique(t_var *v);
void			ft_push_init(t_var *v);
void			gere_loop_1(t_var *v);
void			gere_loop_2(t_var *v);
void			gere_loop_3(t_var *v);
int				ft_little_tab_1(t_var *v);
int				get_next_line(const int fd, char **line);

#endif
