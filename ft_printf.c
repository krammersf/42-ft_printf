/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:12:34 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/02 12:55:47 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 PRINTF(3)               BSD Library Functions Manual               PRINTF(3)

 NAME
       printf -- formatted output conversion

 LIBRARY
      Standard C Library (libc, -lc)

 SYNOPSIS
      #include <stdio.h>

      int
      printf(const char * restrict format, ...);
 ...
 DESCRIPTION
     The printf() family of functions produces output according to a format as
     described below.  The printf() function writes output to stdout, the 
     standard output stream;
 ...
     These functions write the output under the control of a format string 
     that specifies how subsequent arguments (or arguments accessed via the 
     variable-length argument facilities of stdarg(3)) are converted 
     for output.
 ...
 RETURN VALUES
     Function returns the number of characters printed (not including
     the trailing `\0' used to end output to strings).
     Functions returns a negative value if an error occurs.
*/

/*
Variadic Function uses the following, based on STDARG(3):
 		- va_list  : type to hold the information about variable arguments
 		- va_start : initialize the variable argument list name given
	  	- va_arg   : retrieve the next argument
	  	- va_end   : end the argument list
*/

/*
Function will find every character after '%' and use it to select the 
correct format/function to handle the argument. If not format is provided 
the function will simply write to stdout the provided text. In case there
is an error writting to the stdout -1 will be returned (see implementation
of ft_putchar), else the normal behaviour is to return the printed characters

Function takes the format parameter and redirects to the relevant function 
to handle the argument. The value of each parameter is retrivied by using
the `va_args` function
The return value is the number of characters printed.
*/

/*
Format as per subject
	- %c Prints a single character.
	- %s Prints a string (as defined by the common C convention).
	- %p The void * pointer argument has to be printed in hexadecimal format.
	- %d Prints a decimal (base 10) number.
 	- %i Prints an integer in base 10.
 	- %u Prints an unsigned decimal (base 10) number.
 	- %x Prints a number in hexadecimal (base 16) lowercase format.
 	- %X Prints a number in hexadecimal (base 16) uppercase format.
 	- %% Prints a percent sign.
*/

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	pf;

	count = 0;
	va_start(pf, str);
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_check((str + 1), pf);
			str++;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(pf);
	return (count);
}

int	ft_check(const char *str, va_list pf)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += ft_putchar(va_arg(pf, int));
	else if (*str == 's')
		count += ft_putstr(va_arg(pf, char *));
	else if (*str == 'p')
		count += ft_putpointer(va_arg(pf, unsigned long));
	else if (*str == 'd' || *str == 'i')
		count += ft_putnbr(va_arg(pf, int));
	else if (*str == 'u')
		count += ft_putunbr(va_arg(pf, unsigned int));
	else if (*str == 'x' || *str == 'X')
		count += ft_putbase_hex(va_arg(pf, unsigned int), *str);
	else if (*str == '%')
		count += ft_putchar('%');
	return (count);
}

/*   *** RESUMO ***
Essas duas funções fazem parte da implementação da função ft_printf, que é
uma função que é usada para imprimir texto formatado na saída padrão. A função
ft_check é chamada pela função ft_printf para lidar com cada especificador
de formato na string de entrada. A função ft_printf percorre a string de
entrada e chama a função ft_check para cada especificador de formato que
encontrar.

A função ft_check recebe como entrada a string de formato e um ponteiro de
argumento de variável (va_list) que aponta para o primeiro argumento variável
após a string de formato. A função verifica o caractere de especificação de
formato no início da string de formato e chama a função apropriada para
lidar com o tipo de especificador de formato encontrado. Por exemplo, se o
caractere de especificação de formato for 'c', a função chamará a função
ft_putchar para imprimir o caractere correspondente à variável apontada
pelo ponteiro de argumento de variável.

A função ft_printf percorre a string de formato e chama a função ft_check
para cada especificador de formato que encontrar. Se o caractere atual
na string de formato for '%' (o caractere de escape para um especificador
de formato), a função ft_printf chama a função ft_check para lidar com o
especificador de formato que segue. Se o caractere atual na string de
formato não for '%', a função ft_printf simplesmente imprime o caractere
correspondente.

A função ft_printf retorna o número total de caracteres que foram
impressos na saída padrão.
*/

/*
*** ft_check(const char *str, va_list pf) ***
Esta é uma função auxiliar que é usada pela função ft_printf para
determinar qual função deve ser usada para imprimir o argumento atual. A
função ft_check recebe uma string e uma lista de argumentos variáveis
(variadic arguments), percorre a string até encontrar um especificador
de formato %, verifica qual é o tipo de argumento que vem a seguir e, em
seguida, chama a função correspondente para imprimir esse argumento. Os
tipos de argumentos que esta função pode lidar incluem caracteres (%c),
strings (%s), ponteiros (%p), números inteiros (%d e %i), números não
assinados (%u) e números hexadecimais (%x e %X).

Por exemplo, se a string contiver %d como especificador de formato, a
função chama ft_putnbr para imprimir o número inteiro correspondente. A
função va_arg é usada para obter o argumento atual da lista de argumentos
variáveis, e o contador count é atualizado para refletir o número de
caracteres impressos. A função retorna o número total de caracteres
impressos.
*/

/*
*** ft_printf(const char *str, ...) ***
A função ft_printf é responsável por imprimir uma string formatada, com
possíveis parâmetros de formato. Ela recebe como primeiro argumento a
string a ser impressa e, opcionalmente, outros argumentos que serão
utilizados na formatação.

A função começa inicializando uma variável do tipo va_list chamada pf,
que será utilizada para acessar os argumentos adicionais passados à
função. Em seguida, um loop é executado enquanto a string de formato
não acabar.

Se o caractere atual na string de formato for um '%' então a função
ft_check é chamada para processar o argumento de formato seguinte e
realizar a impressão formatada. O ponteiro str é incrementado após o
caractere '%' para pular o formato já processado.

Se o caractere atual não for um '%' então ele é imprimido diretamente
na saída e o ponteiro str é incrementado.

Ao final, a função ft_printf retorna o número total de caracteres
impressos.
*/

/*
Na função ft_printf, quando o caractere atual em str é %, o código
chama a função ft_check com um ponteiro para o próximo caractere em
str (str + 1). Isso ocorre porque o caractere % indica que um
especificador de formato está sendo usado, então o próximo caractere
em str será o especificador de formato real.

Por exemplo, se str for "Hello, %s!", o código de ft_printf irá
encontrar o caractere % e chamará ft_check com o ponteiro para o
caractere s. Em ft_check, o caractere s será lido e a função
correspondente será chamada para formatar e imprimir o argumento
correspondente.

Essa é a razão pela qual str + 1 é passado para ft_check em vez
de apenas str. Isso permite que a função ft_check leia o
especificador de formato correto e formate o argumento apropriado
para a saída.
*/
