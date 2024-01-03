/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:27:18 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/02 12:55:51 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	print;

	print = write(1, &c, 1);
	return (print);
}

/*
#include <stdio.h>
#include <unistd.h>

int	main()
{
    char c = 'A';
	ft_putchar(c);
    printf("\n%c\n",c);
    return (0);
}
*/

/*
	if (print == -1)
		exit (-1);
*/

/*
Esta é uma função escrita em linguagem C que recebe um caractere
como argumento e o escreve na saída padrão (geralmente o terminal).
Ela retorna o número de bytes escritos na saída padrão, que é
sempre 1, já que estamos escrevendo apenas um caractere por vez.

Internamente, a função ft_putchar usa a função write da biblioteca
padrão de entrada/saída (unistd.h) para escrever o caractere na saída
padrão. A função write tem três argumentos: o primeiro é o descritor
de arquivo (neste caso, 1 para a saída padrão), o segundo é um ponteiro
para o buffer de dados a ser escrito (neste caso, um ponteiro para o
caractere c) e o terceiro é o número de bytes a serem escritos
(neste caso, 1).

Então, a função ft_putchar basicamente encapsula a chamada para a
função write dentro de uma função mais simples, tornando mais fácil
e conveniente escrever caracteres na saída padrão em outras partes do
programa.
*/

/*
int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}
*/

/*
A função putchar() é uma função em C que é usada para escrever um
caractere na saída padrão (normalmente, a tela). O retorno da função
é o caractere escrito, como um tipo de dado inteiro (int), mas que é
originalmente um caractere não assinado (unsigned char).

No entanto, se houver algum erro ao escrever o caractere, a função
retornará o valor constante EOF (End of File). O valor EOF é definido
como um número inteiro negativo que geralmente é -1.

Portanto, o significado da frase "putchar() return the character written
as an unsigned char cast to an int or EOF on error" é que a função
putchar() retorna o caractere escrito como um inteiro, que é originalmente
um caractere não assinado, mas que, se houver algum erro, a função
retornará o valor EOF em vez do caractere escrito.
*/
