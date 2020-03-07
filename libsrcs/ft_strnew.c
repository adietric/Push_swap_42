/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:21:43 by adietric          #+#    #+#             */
/*   Updated: 2019/04/03 14:40:32 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

char		*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}
