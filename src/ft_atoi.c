/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:04:17 by tperraut          #+#    #+#             */
/*   Updated: 2017/12/15 16:02:40 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** n for the sign
** r for result
** i for index
*/

int		ft_atoi(const char *str)
{
	int				n;
	int				i;
	unsigned int	r;

	n = 1;
	i = 0;
	r = 0;
	while (ft_isblank(str[i]) || ft_isreturn(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		n = -1;
	else if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (r > MAX_INT)
			return(0);
		r = r * 10 + (unsigned int)(str[i++] - '0');
	}
	return ((int)r * n);
}

int		ft_satoi(const char *str)
{
	int				n;
	int				i;
	unsigned int	r;

	n = 1;
	i = 0;
	r = 0;
	while (ft_isblank(str[i]) || ft_isreturn(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		n = -1;
	else if (str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		ft_error(ER_MSG);
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (r > MAX_INT)
			ft_error(ER_MSG);
		r = r * 10 + (unsigned int)(str[i++] - '0');
	}
	return (r * n);
}

int		ft_stratoi(char **str)
{
	int				n;
	unsigned int	r;

	n = 1;
	r = 0;
	while (ft_isblank(**str) || ft_isreturn(**str))
		(*str)++;
	if (**str == '-' && (*str)++)
		n = -1;
	else if (**str == '+')
		(*str)++;
	if (!ft_isdigit(**str))
		ft_error(ER_MSG);
	while (**str == '0')
		(*str)++;
	while (ft_isdigit(**str))
	{
		if (r > MAX_INT)
			ft_error(ER_MSG);
		r = r * 10 + (unsigned int)(**str - '0');
		(*str)++;
	}
	return (r * n);
}
