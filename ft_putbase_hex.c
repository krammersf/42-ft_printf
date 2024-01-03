/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:27:31 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/02 12:55:51 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_hex(unsigned long nb, char c)
{
	int		count;
	char	*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_putbase_hex((nb / 16), c);
		count += ft_putbase_hex((nb % 16), c);
	}
	else
		count += write(1, &base[nb], 1);
	return (count);
}

/*
Em resumo, a função ft_putbase_hex converte um número inteiro sem sinal
em uma representação hexadecimal e a exibe no terminal.
*/

/*
int	main()
{
	int a = 542;
	// %x
	printf("%x\n", a);
  	ft_putbase_hex(a, 'x');
	printf("\n");
	// %X
	printf("%X\n", a);
	ft_putbase_hex(a, 'X');
	printf("\n");

	return(0);
}
*/

/*
Esta função, escrita em linguagem C, converte um número inteiro sem sinal
numa representação hexadecimal em forma de string e a exibe no terminal.

A função ft_putbase_hex recebe dois parâmetros: nb, que é o número inteiro
sem sinal a ser convertido em hexadecimal, e c, que indica se a
representação hexadecimal deve ser em letras minúsculas ou maiúsculas.
A função retorna o número de caracteres impressos na saída padrão.

A função utiliza uma abordagem recursiva para converter o número em
hexadecimal. Primeiro, ela verifica se o valor do número é maior ou igual
a 16 (a base hexadecimal). Se for, a função é chamada novamente duas vezes,
passando a divisão inteira de nb por 16 como primeiro argumento e o
resto da divisão por 16 como segundo argumento. Essa recursão continua até
que o valor de nb seja menor que 16. Em seguida, a função exibe o caractere
correspondente ao valor de nb na tabela de conversão hexadecimal, que é
armazenada em um ponteiro base.

Se c for igual a 'x', a tabela de conversão em minúsculas é usada
(base = "0123456789abcdef"), enquanto se c for igual a 'X', a tabela de
conversão em maiúsculas é usada (base = "0123456789ABCDEF").

A função write é usada para exibir cada caractere hexadecimal individual
na saída padrão.
*/

/*
A expressão *(hex + nb) é uma forma de aceder ao valor armazenado num
ponteiro base deslocado por um número nb de posições. Ou seja, *(base + nb)
é equivalente a base[nb].

A função ft_putchar recebe um caractere como argumento e o exibe na saída
padrão. Portanto, ft_putchar(*(base + nb)) exibe o caractere hexadecimal
correspondente ao valor de nb na tabela de conversão base na saída padrão.

A expressão count += ft_putchar(*(base + nb)) adiciona o valor retornado
pela função ft_putchar à variável count, que é usada para contar o número
de caracteres impressos na saída padrão. Essa expressão é usada para contar
quantos caracteres hexadecimais são exibidos no total durante a conversão.
*/

/*
else
		count += ft_putchar(*(base + nb));
	return (count);
*/
