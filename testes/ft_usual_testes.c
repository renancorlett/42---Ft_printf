/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usual_testes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:43:55 by rcorlett          #+#    #+#             */
/*   Updated: 2024/11/04 11:45:08 by rcorlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ft_count;

    // Teste da função print_char
    ft_count = print_char('A');  // A
    printf("\nprint_char contou: %d caracteres\n\n", ft_count); // 1

    // Teste da função print_str
    ft_count = print_str("Hello, world!");  // Hello, world!
    printf("\nprint_str contou: %d caracteres\n\n", ft_count); // 13

    // Teste da função print_str com NULL
    ft_count = print_str(NULL);  // (null)
    printf("\nprint_str com NULL contou: %d caracteres\n\n", ft_count); // 6

    // Teste da função print_nbr
    ft_count = print_nbr(12345);  // 12345
    printf("\nprint_nbr contou: %d caracteres\n\n", ft_count); // 5

    // Teste da função print_nbr com número negativo
    ft_count = print_nbr(-12345);  // -12345
    printf("\nprint_nbr com negativo contou: %d caracteres\n\n", ft_count); // 6

    // Teste da função print_unsigned
    ft_count = print_unsigned(12345);  // 12345
    printf("\nprint_unsigned contou: %d caracteres\n\n", ft_count); // 5

    // Teste da função print_hex com letras minúsculas
    ft_count = print_hex(255, 1);  // ff
    printf("\nprint_hex (minúsculas) contou: %d caracteres\n\n", ft_count); // 2

    // Teste da função print_hex com letras maiúsculas
    ft_count = print_hex(255, 0);  // FF
    printf("\nprint_hex (maiúsculas) contou: %d caracteres\n\n", ft_count); // 2

    // Teste da função print_pointer com endereço válido
    int x = 42;
    ft_count = print_pointer((unsigned long)&x);  // Exemplo: 0x7ffeeaeb89c8
    printf("\nprint_pointer contou: %d caracteres\n\n", ft_count); // Varia conforme o endereço

    // Teste da função print_pointer com NULL
    ft_count = print_pointer(0);  // (nil)
    printf("\nprint_pointer com NULL contou: %d caracteres\n\n", ft_count); // 5

    // Teste da função print_address
    ft_count = print_address(0xabcdef);  // abcdef
    printf("\nprint_address contou: %d caracteres\n\n", ft_count); // 6
    
    return (0);
}

