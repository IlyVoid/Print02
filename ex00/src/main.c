/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:10:14 by quvan-de          #+#    #+#             */
/*   Updated: 2024/02/24 17:41:55 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	set_tens(int n)
{
	if (n >= 90)
		return (90);
	else if (n >= 80)
		return (80);
	else if (n >= 70)
		return (70);
	else if (n >= 60)
		return (60);
	else if (n >= 50)
		return (50);
	else if (n >= 40)
		return (40);
	else if (n >= 30)
		return (30);
	else if (n >= 20)
		return (20);
	else if (n <= 20)
		return (n);
	else
		return (0);
}

int	set_multi(int n)
{
	if (n >= 1000000000)
		return (100000000);
	else if (n >= 1000000)
		return (1000000);
	else if (n >= 1000)
		return (1000);
	else if (n >= 100)
		return (100);
	else
		return (set_tens(n));
}

void	print(int n, t_list *tab, int *first)
{
	int	i;
	int	multi;

	i = 0;
	multi = set_multi(n);
	if (multi >= 100)
		print(n / multi, tab, first);
	if (*first == 0)
		write(1, " ", 1);
	*first = 0;
	while (tab[i].n != multi)
		i++;
	put_str(tab[i].value);
	if (multi != 0 && n % multi != 0)
		print(n % multi, tab, first);
}

int	main(int ac, char **av)
{
	t_list	*tab;
	int		*first;
	int		add_first;

	add_first = 1;
	first = &add_first;
	if (ac == 2)
	{
		if (atoi_number(av[1]) < 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		tab = operate("EnglishDict.txt");
		print(atoi_number(av[1]), tab, first);
	}
	return (0);
}
