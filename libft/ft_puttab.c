/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:39:45 by mmonier           #+#    #+#             */
/*   Updated: 2018/11/23 12:39:48 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab)
{
	int i;

	i = 0;
	while (tab && tab[i])
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		i++;
	}
}
