/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:01:08 by nneves-a          #+#    #+#             */
/*   Updated: 2024/04/26 16:31:36 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/*
float	ft_average(int	num, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = 0;
	va_start(ap, num);
	while (i < num)
	{
		count =	count + va_arg(ap, int);
		i++;
	}
	va_end(ap);
	return ((float	count / num);
}
*/
int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	count; //count to stock all the bytes writen!
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-n, base) + 1); //+1 because of the minus '-'
	}
	else if (n < base)
	{
		return (ft_print_char(symbols[n]));
	}
	else
	{
		count = ft_print_digit(n / base, base);
		return (count + ft_print_digit(n % base, base));
	}
}

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int)); //char (but because of promotion we use integer)
	else if ( specifier == 'S')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count += ft_print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')
		count += ft_print_digit((long)(va_arg(ap, unsigned int)), 16);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			count =	count + ft_print_format(*format, ap);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

#define INT32_MIN (-2147483647 - 1)
int	main(void)
{
	int	count;
	
//	count = ft_printf("Hello %s\n", "Nuno");
//	ft_printf("The chars writen are %d\n", count);
//	count = ft_printf("%x\n", INT32_MIN);
//	ft_printf("The chars writen are %d\n", count);
//	count = ft_printf("%d\n", INT32_MIN);
//	ft_printf("The chars writen are %d\n", count);
	count = ft_printf("Ola %s, tens %d anos, em hex: %x, char:%c\n", 
	"Nuno",
	 26,
	 26,
	 'c');
	ft_printf("The chars writen are %d\n", count);
	printf("Ola %s, tens %d anos, em hex: %x, char:%c\n", 
	"Nuno",
	 26,
	 26,
	 'c');
	return (0);
}
