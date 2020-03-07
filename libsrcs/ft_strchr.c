/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:30:40 by adietric          #+#    #+#             */
/*   Updated: 2019/04/03 14:40:50 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

char		*ft_strchr(const char *s, int c)
{
	char	*s1;
	int		i;

	s1 = (char*)s;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i++;
	}
	if (s1[i] == (char)c)
		return (&s1[i]);
	return (NULL);
}
