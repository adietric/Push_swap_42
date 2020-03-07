/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:44:42 by flafonso          #+#    #+#             */
/*   Updated: 2019/04/03 18:36:50 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s2;

	s2 = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		s2[i] = (unsigned char)c;
		i++;
	}
	return (s2);
}
