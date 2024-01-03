/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:28:08 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/02 12:55:54 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{	
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char c[] = "a minha casa";
	ft_putstr(c);
    printf("\n%s\n", c);
    return (0);
}
*/

/*
Essa é uma função que recebe uma string como argumento e a imprime na
saída padrão (tela). A função retorna o número de caracteres da string
que foram impressos na tela.

A função começa inicializando uma variável i com o valor 0. Em seguida,
é feita uma verificação para ver se o ponteiro para a string passada
como argumento é nulo (NULL). Se for, a função retorna imediatamente
e escreve a string "(null)" na tela, que é a mensagem padrão que
representa uma string nula.

Se o ponteiro não for nulo, a função começa a iterar pela string
usando um loop while. O loop percorre a string enquanto o caractere
atual for diferente do caractere nulo ('\0'), que marca o fim da
string. Dentro do loop, é chamada a função write para escrever o caractere
atual da string na saída padrão (tela). A cada caractere impresso, a
variável i é incrementada em 1.

Ao final do loop, a função retorna o valor de i, que representa o número
de caracteres da string que foram impressos na tela.
*/
