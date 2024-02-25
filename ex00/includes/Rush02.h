/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:45:37 by quvan-de          #+#    #+#             */
/*   Updated: 2024/02/24 17:12:39 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

typedef struct s_list
{
	int		n;
	char	*value;
}	t_list;
char	*str_dup(char *src);
char	*find_number(int fd);
char	*find_value(int fd, char *c);
int		atoi_number(const char *str);
void	put_str(char *src);
t_list	*operate(char *file);

#endif
