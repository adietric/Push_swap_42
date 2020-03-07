/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:15:09 by adietric          #+#    #+#             */
/*   Updated: 2019/04/03 14:40:35 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

static char	*ft_fait(char *s, char const *s1, char const *s2)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		s[i] = s2[c];
		i++;
		c++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*s;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	c = 0;
	while (s2[c])
		c++;
	if (!(s = (char*)malloc(sizeof(char) * (i + c + 1))))
		return (NULL);
	return (ft_fait(s, s1, s2));
	return (0);
}
