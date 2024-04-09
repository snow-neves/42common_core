/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:57:33 by nneves-a          #+#    #+#             */
/*   Updated: 2024/04/09 18:51:33 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void *ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		s[n] = c;
		n--;
	}
	return (s);
}

int	main(void)
{
	char s[19] = "Moto Ratos de Marte";
	size_t n = 9;
	int c = 'Q';

	printf("%s", ft_memset(s, c, n));
	return (0);
}
