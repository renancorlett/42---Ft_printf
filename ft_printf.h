/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:37:14 by rcorlett          #+#    #+#             */
/*   Updated: 2024/10/29 09:46:42 by rcorlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *argument, ...);
int	print_string(char *str);
int	print_number(int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned long n, int uppercase);
int	print_pointer(void *ptr);

#endif
