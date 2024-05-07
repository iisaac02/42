/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:01:18 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/20 15:59:59 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

char		*get_next_line(int fd);
int			ft_strlen(char *s);
char		*print_line(char **temp);
int			have_n(char	*temp);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str, int len);

#endif