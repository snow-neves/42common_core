/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:36:23 by nneves-a          #+#    #+#             */
/*   Updated: 2024/04/09 20:46:16 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	destlen  = ft_strlen(dst);
	srclen = ft_strlen(src);
	x = destlen;
	if (size <= srclen)
		return (size + srclen);
	while (src[y] != '\0' && y < size - destlen - 1)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	dest[x] = '\0';
	return (x);
}
