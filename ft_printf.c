/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:28:00 by rcorlett          #+#    #+#             */
/*   Updated: 2024/10/29 12:46:15 by rcorlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(char specifier, va_list args)
{
	int		count;
	char	c;

	count = 0;
	if (specifier == 'c')
	{
		c = (char)va_arg(args, int);
		count += write(1, &c, 1);
	}
	else if (specifier == 's')
		count += print_string(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_number(va_arg(args, int));
	else if (specifier == 'u')
		count += print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count += print_hex(va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		count += print_hex(va_arg(args, unsigned int), 1);
	else if (specifier == 'p')
		count += print_pointer(va_arg(args, void *));
	else if (specifier == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *argument, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, argument);
	while (argument[i])
	{
		if (argument[i] == '%' && argument[i + 1])
		{
			count += handle_conversion(argument[i + 1], args);
			i++;
		}
		else
			count += write(1, &argument[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

/*#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	ft_count;
	int	std_count;

//Teste de caractere
	printf("Teste de caractere:\n");
	ft_count = ft_printf("%c\n", 'C');  // C
	std_count = printf("%c\n", 'C');    // C
	printf("ft_printf contou: %d caracteres\n", ft_count);  // 2
	printf("printf padrão contou: %d caracteres\n\n", std_count);  // 2

//Teste de string
	printf("Teste de string:\n");
	ft_count = ft_printf("%s\n", "Bom dia, Portugal!");  // Bom dia, Porgual!
	std_count = printf("%s\n", "Bom dia, Portugal!");    // Bom dia, Porgual!
	printf("ft_printf contou: %d caracteres\n", ft_count);  // 19
	printf("printf padrão contou: %d caracteres\n\n", std_count);  // 19

//Teste de inteiro com sinal
	printf("Teste de inteiro com sinal:\n");
	ft_count = ft_printf("%d\n", -135);  // -135
	std_count = printf("%d\n", -135);    // -135
	printf("ft_printf contou: %d caracteres\n", ft_count);  // 5
	printf("printf padrão contou: %d caracteres\n\n", std_count);  // 5

//Teste de inteiro sem sinal
	printf("Teste de inteiro sem sinal:\n");
	ft_count = ft_printf("%u\n", 246);  // 246
	std_count = printf("%u\n", 246);    // 246
	printf("ft_printf contou: %d caracteres\n", ft_count);  // 4
	printf("printf padrão contou: %d caracteres\n\n", std_count);  // 4

//Teste de hexadecimal minúsculo
	printf("Teste de hexadecimal minúsculo:\n");
	ft_count = ft_printf("%x\n", 204);  // cc
	std_count = printf("%x\n", 204);    // cc
	printf("ft_printf contou: %d caracteres\n", ft_count);  // 3
	printf("printf padrão contou: %d caracteres\n\n", std_count);  // 3

//Teste de hexadecimal maiúsculo
	printf("Teste de hexadecimal maiúsculo:\n");
	ft_count = ft_printf("%X\n", 204);  // CC
	std_count = printf("%X\n", 204);    // CC
	printf("ft_printf contou: %d caracteres\n", ft_count);  // 3
	printf("printf padrão contou: %d caracteres\n\n", std_count);  // 3

//Teste de ponteiro
	printf("Teste de ponteiro:\n");
	ft_count = ft_printf("%p\n", (void *)0x7ffeeaeb89c8);  // 0x7ffeeaeb89c8
	std_count = printf("%p\n", (void *)0x7ffeeaeb89c8);    // 0x7ffeeaeb89c8
	printf("ft_printf contou: %d caracteres\n", ft_count);  // 15
	printf("printf padrão contou: %d caracteres\n\n", std_count);  // 15

//Teste de percentual
	printf("Teste de caractere de percentual:\n");
	ft_count = ft_printf("%%\n");  // %
	std_count = printf("%%\n");    // %
	printf("ft_printf contou: %d caracteres\n", ft_count);  // 2
	printf("printf padrão contou: %d caracteres\n\n", std_count);  // 2
	
	return 0;
}*/
