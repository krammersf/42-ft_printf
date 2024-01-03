/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:26:50 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/02 12:55:50 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// ======================== INCLUDES ========================================

# include <unistd.h> // required by write
# include <stdarg.h> // required by `variable argument lists`, see STDARG(3)
# include <stdlib.h> // required by exit
# include <stdio.h> // required by printf

// ======================== PROTOTYPES ======================================

// ft_printf.c
int		ft_printf(const char *str, ...);
int		ft_check(const char *str, va_list pf);

// single files *.c
int		ft_putchar(int c);
int		ft_putbase_hex(unsigned long nb, char c);
int		ft_putnbr(long nb);
int		ft_putunbr(unsigned int nb);
int		ft_putpointer(unsigned long nb);
int		ft_putstr(char *str);

#endif

/*
Esse é um arquivo de cabeçalho (header file) que define a interface da
função ft_printf e declara os protótipos de todas as outras funções usadas
na implementação do mesmo.

A primeira parte desse arquivo define algumas inclusões (#include)
de bibliotecas padrão em C, como unistd.h, stdarg.h, stdlib.h e stdio.h.

Em seguida, são declarados os protótipos das funções que implementam
o ft_printf e outras funções auxiliares, como ft_check, ft_putchar,
ft_putbase_hex, ft_putnbr, ft_putunbr e ft_putstr.

Por fim, o arquivo é protegido por meio de uma diretiva de pré-processador
(#ifndef) para evitar que o conteúdo seja incluído mais de uma vez em
diferentes partes do programa. Isso é comum em arquivos de cabeçalho
para evitar problemas de duplicação de definições de símbolos e para
melhorar a organização do código.
*/
