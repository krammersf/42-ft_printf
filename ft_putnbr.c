/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:27:44 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/02 12:55:52 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// INT_MIN = -2147483648
int	ft_putnbr(long nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	else if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
		count += ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}	
	else
		count += write(1, &"0123456789"[nb % 10], 1);
	return (count);
}

/*
Em resumo, a função ft_putnbr converte um número inteiro longo numa
sequência de caracteres e escreve essa sequência na saída padrão,
retornando o número total de caracteres escritos.
*/

/*
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int a = -2147483648;
    ft_putnbr(a);
    printf("\n%d\n", a);
    return 0;
}
*/

/*
Essa é uma função em C que recebe um número inteiro longo (long)
como argumento e o escreve na saída padrão (normalmente o terminal)
como uma sequência de caracteres. A função retorna o número total
de caracteres escritos na saída padrão.

A função ft_putnbr é recursiva e começa inicializando a variável
count com o valor 0. Em seguida, ela verifica se o número passado
como argumento é igual a -2147483648 (o valor mínimo que pode ser
representado por um inteiro de 32 bits em complemento de dois).
Se for esse o caso, a função escreve a string "-2147483648" na
saída padrão usando a função write e retorna o valor atual de count.

Se o número não for igual a -2147483648, a função verifica se ele
é negativo. Se for negativo, ela escreve um caractere '-' na saída
padrão e muda o sinal do número para positivo. Em seguida, ela chama
a função ft_putnbr recursivamente, passando o valor absoluto do
número como argumento. O resultado da chamada recursiva é adicionado
ao valor de count.

Se o número for positivo e maior ou igual a 10, a função chama
ft_putnbr recursivamente duas vezes: uma vez com o quociente da
divisão inteira do número por 10 e outra vez com o resto da divisão
inteira. O resultado da soma dos valores retornados pelas chamadas
recursivas é adicionado ao valor de count.

Se o número for um dígito único (isto é, menor que 10), a função
escreve o dígito correspondente na saída padrão usando a tabela de
caracteres "0123456789" e retorna 1, que é adicionado ao valor atual
de count.
*/

/*
int	ft_int_putnbr(long n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_int_putstr("-2147483648");
	}
	else if (n < 0)
	{
		n = -n;
		count += ft_int_putchar('-');
		count += ft_int_putnbr(n);
	}
	else if (n > 9)
	{
		count += ft_int_putnbr((n / 10));
		count += ft_int_putnbr(n % 10);
	}
	else
	{
		count += ft_int_putchar((n + '0'));
	}
	return (count);
}
*/
