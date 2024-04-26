/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:52:10 by nneves-a          #+#    #+#             */
/*   Updated: 2024/04/26 12:30:17 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int	ft_lenofnum(int num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		return (1);
	else if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	number;
	char			*s;

	number = 0;
	len = ft_lenofnum(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (n == 0)
		s[0] = '0';
	else if (n < 0)
	{
		s[0] = '-';
		number = -n;
	}
	else
		number = n;
	s[len] = '\0';
	while (number != 0)
	{
		s[len - 1] = (number % 10) + '0';
		number = number / 10;
		len--;
	}
	return (s);
}
/*
int	main(void)
{
	int		x;
	char	*s;
	x = -21245314518;
	s = ft_itoa(x);
	printf("%s\n", s);
	free(s);
	return (0);
}
*/
/*
in func:
	else if (num < 0)
	{
		num = -num;
		len++; //to save space for the '-' (minus sign)
	}
*/