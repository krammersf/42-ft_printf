/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:27:57 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/02 12:55:53 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long nb)
{
	int	count;

	count = 0;
	if (!nb)
		return (write(1, "(nil)", 5));
	count += ft_putstr("0x");
	count += ft_putbase_hex(nb, 'x');
	return (count);
}

/*
Em resumo, a função ft_putpointer converte um ponteiro em uma sequência
de caracteres na forma hexadecimal precedido pelo prefixo "0x" e escreve
essa sequência na saída padrão, retornando o número total de caracteres
escritos. Se o ponteiro for nulo, a função escreve a string "(nil)" na
saída padrão e retorna o número total de caracteres escritos (que é 5).
*/

/*
#include <stdio.h>
#include <unistd.h>

int	ft_putbase_hex(unsigned long nb, char c);
int	ft_putstr(char *str);

int main(void)
{
    int a = 42;
    int *p = &a;

    printf("%p\n", p);
    ft_putpointer((unsigned long)p);
    printf("\n");

    return(0);
}
*/

/*
Essa é uma função em C que recebe um ponteiro como argumento
e o escreve na saída padrão (normalmente o terminal) na forma
hexadecimal precedido pelo prefixo "0x". Se o ponteiro passado
como argumento for nulo (ou seja, apontar para um endereço de
memória inválido), a função escreverá a string "(nil)" na saída
padrão. A função retorna o número total de caracteres escritos
na saída padrão.

A função ft_putpointer começa inicializando a variável count
com o valor 0. Em seguida, ela verifica se o ponteiro passado
como argumento é nulo (ou seja, se o valor for 0). Se for esse
o caso, a função escreve a string "(nil)" na saída padrão usando
a função write e retorna o número total de caracteres escritos
(que é 5, o comprimento da string "(nil)").

Se o ponteiro não for nulo, a função chama a função ft_putstr
para escrever a string "0x" na saída padrão e adiciona o número
de caracteres escritos ao valor de count. Em seguida, a função
chama a função ft_putbase_hex para escrever o valor do ponteiro
em hexadecimal na saída padrão, passando como argumento o valor
do ponteiro e o caractere 'x' para indicar que a saída deve ser
em letras minúsculas. O número de caracteres escritos pela função
ft_putbase_hex é adicionado ao valor de count.

Finalmente, a função ft_putpointer retorna o valor atual de count,
que é o número total de caracteres escritos na saída padrão.
*/

/*
Em muitos casos "(nil)" é usado para representar um ponteiro
nulo em C. Em outras palavras, ele é usado para indicar que
um ponteiro não está apontando para nenhum endereço de memória
válido.

Por outro lado, o valor NULL é um valor constante definido em C
e C++ que também representa um ponteiro nulo. Ele é usado para
inicializar ponteiros, compará-los com outros ponteiros ou testá-los
em condições. Em geral, "(nil)" e NULL são considerados equivalentes
em C e C++, embora "(nil)" seja mais comum em saídas formatadas em
strings ou em mensagens de erro, enquanto NULL é usado em código
fonte para inicializar ponteiros.
*/
