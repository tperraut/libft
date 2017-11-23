/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 22:16:21 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/21 16:28:01 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < l1)
		dest[j++] = s1[i++];
	i = 0;
	while (i < l2)
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}
