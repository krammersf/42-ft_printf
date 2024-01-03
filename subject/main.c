/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:24:02 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/02 14:29:00 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_hex(unsigned long nb, char c);
int	ft_putchar(int c);
int	ft_putchar(int c);
int	ft_putnbr(long nb);
int	ft_putpointer(unsigned long nb);
int	ft_putstr(char *str);
int	ft_putunbr(unsigned int nb);

int	main(void)
{
	int a = 542;
	int *p = &a;
	char c = 'A';
	int b = -2147483648;
        char d[] = "a minha casa";
	unsigned int e = 42;
	char f = '%';

	// %c
    	printf("*************************** impime c ***\n");	
    	printf("%c (printf)", c);
	printf("\n");
    	printf(" (ft_putchar)");
    	ft_putchar(c);
	printf("\n");
	ft_printf("%c (ft_printf)", c);
	printf("\n");
	// %s
	printf("*************************** impime s ***\n");
	printf("%s (printf)", d);
	printf("\n");
	printf(" (ft_putstr)");
	ft_putstr(d);
	printf("\n");
	ft_printf("%s (ft_printf)", d);	
	printf("\n");
	// %p
	printf("*************************** impime p ***\n");
	printf("%p (printf)", p);
	printf("\n");
	printf(" (ft_putpointer)");
	ft_putpointer((unsigned long)p);
	printf("\n");
	ft_printf("%p (ft_printf)", p);
	printf("\n");
	// %d
	printf("*************************** impime d ***\n");
	printf("%d (printf)", b);
	printf("\n");
	printf(" (ft_putnbr)");
	ft_putnbr(b);
	printf("\n");
	ft_printf("%d (ft_printf)", b);
	printf("\n");
	// %i
	printf("*************************** impime i ***\n");
	printf("%i (printf)", b);
	printf("\n");
	printf(" (ft_putnbr)");
	ft_putnbr(b);
	printf("\n");
	ft_printf("%i (ft_printf)", b);
	printf("\n");	
	// %u
	printf("*************************** impime u ***\n");
	printf("%u (printf)", e);
	printf("\n");	
	printf(" (ft_putunbr)");
	ft_putunbr(e);
	printf("\n");
	ft_printf("%u (ft_printf)", e);
	printf("\n");
	// %x
	printf("*************************** impime x ***\n");
	printf("%x (printf)", a);
	printf("\n");	
	printf(" (ft_putbase_hex)");
  	ft_putbase_hex(a, 'x');
	printf("\n");
	ft_printf("%x (ft_printf)", a);
	printf("\n");	
	// %X
	printf("*************************** impime X ***\n");
	printf("%X (printf)", a);
	printf("\n");	
	printf(" (ft_putbase_hex)");
  	ft_putbase_hex(a, 'X');
	printf("\n");
	ft_printf("%X (ft_printf)", a);
	printf("\n");
	// %%
	printf("*************************** impime %% ***\n");
	printf("%c (printf)", f);
	printf("\n");
    	printf(" (ft_putchar)");
    	ft_putchar(f);
	printf("\n");
	ft_printf("%c (ft_printf)", f);
	printf("\n");
	printf("*************************** TUDO FEITO ***\n");
	
	return(0);
}
