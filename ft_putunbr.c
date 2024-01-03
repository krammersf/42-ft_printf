/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:28:27 by fde-carv          #+#    #+#             */
/*   Updated: 2023/04/28 14:46:56 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_putunbr((nb / 10));
		count += ft_putunbr(nb % 10);
	}
	else
		count += write(1, &"0123456789"[nb % 10], 1);
	return (count);
}

/*
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	unsigned int num = 42;
	
	printf("%u\n", num);
	ft_putunbr(num);
	ft_putchar('\n');

	return (0);
}
*/

/*
Essa função recebe um número inteiro não negativo sem sinal
como argumento e o imprime na saída padrão (tela) como uma
sequência de caracteres. A função retorna o número de caracteres
que foram impressos na tela.

A função começa inicializando uma variável count com o valor 0.
Em seguida, é feita uma verificação para ver se o número passado
como argumento é maior que 9. Se for, a função faz uma chamada
recursiva para a função ft_putunbr para imprimir o quociente inteiro
da divisão do número por 10, ou seja, todos os dígitos exceto o
último. Em seguida, é feita outra chamada recursiva para imprimir
o resto da divisão por 10, ou seja, o último dígito.

Se o número passado como argumento for menor ou igual a 9, a
função simplesmente chama a função ft_putchar para imprimir o
caractere correspondente ao dígito, adicionando '0' ao número
para obter o caractere correto.

Em ambos os casos, a cada caractere impresso na tela, a
variável count é incrementada em 1.

Ao final da função, ela retorna o valor de count, que representa
o número de caracteres que foram impressos na tela.
*/

/*
int	ft_putunbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_putunbr((nb / 10));
		count += ft_putunbr(nb % 10);
	}
	else
		count += ft_putchar((nb + '0'));
	return (count);
}
*/
