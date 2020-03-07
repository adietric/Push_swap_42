/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:04:51 by adietric          #+#    #+#             */
/*   Updated: 2019/04/03 14:40:39 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

char		*ft_strdup(const char *src1)
{
	char	*tab;
	int		i;
	int		j;
	char	*src;

	src = (char *)src1;
	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (!(tab = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (j < i)
	{
		tab[j] = src[j];
		j++;
	}
	tab[j] = '\0';
	return (tab);
}
