/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:58:27 by adietric          #+#    #+#             */
/*   Updated: 2019/04/03 14:40:29 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	c;
	char	*s1;

	if (!s)
		return (0);
	if (!(s1 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	c = (size_t)start;
	i = 0;
	while (i < len)
	{
		s1[i] = s[c + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
