/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usual.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:16:41 by rcorlett          #+#    #+#             */
/*   Updated: 2024/10/29 11:23:48 by rcorlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (str[count])
		count += write(1, &str[count], 1);
	return (count);
}

int	print_number(int n)
{
	long	num;
	int		count;
	char	digit;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	if (num > 9)
		count += print_number(num / 10);
	digit = (num % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}

int	print_unsigned(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n > 9)
		count += print_unsigned(n / 10);
	digit = (n % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}

int	print_hex(unsigned long n, int uppercase)
{
	int		count;
	char	*base;
	char	digit;

	count = 0;
	base = "0123456789abcdef";
	if (uppercase)
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += print_hex(n / 16, uppercase);
	digit = base[n % 16];
	count += write(1, &digit, 1);
	return (count);
}

int	print_pointer(void *ptr)
{
	unsigned long	local;
	char			*prefix;
	int				count;

	count = 0;
	local = (unsigned long)ptr;
	prefix = "0x";
	count += write(1, prefix, 2);
	count += print_hex(local, 0);
	return (count);
}
