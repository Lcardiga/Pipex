/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcardiga <lcardiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:47:02 by lcardiga          #+#    #+#             */
/*   Updated: 2021/11/11 22:55:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str1;
	size_t	str2;
	size_t	i;
	char	*memory;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	memory = (char *)malloc(sizeof(*memory) * (str1 + str2 + 1));
	if (!memory)
		return (NULL);
	while (*s1 != '\0')
		memory[i++] = *s1++;
	while (*s2 != '\0')
		memory[i++] = *s2++;
	memory[i] = '\0';
	return (memory);
}
