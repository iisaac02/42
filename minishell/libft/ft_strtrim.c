/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:26:55 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:56:41 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		begin;
	int		end;

	begin = 0;
	end = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[begin] && ft_strchr(set, s1[begin]))
	{
		begin++;
	}
	end = ft_strlen(s1) - 1;
	while (end > begin && ft_strrchr(set, s1[end]))
	{
		end--;
	}
	trimmed = ft_substr(s1, begin, end - begin +1);
	return (trimmed);
}

/*int main()
{
    const char *original = "   Hello, World!   ";
    const char *set = " ";

    char *trimmed = ft_strtrim(original, set);
    if (trimmed == NULL) 
	{
        fprintf(stderr, "Memory allocation failure\n");
        return 1;
	}


    printf("Original: '%s'\n", original);
    printf("Trimmed : '%s'\n", trimmed);
    free(trimmed);
	return 0;
}*/
