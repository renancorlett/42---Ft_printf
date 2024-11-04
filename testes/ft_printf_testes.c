/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:42:01 by rcorlett          #+#    #+#             */
/*   Updated: 2024/11/04 11:42:26 by rcorlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
}
