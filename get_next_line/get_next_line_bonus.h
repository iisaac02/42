/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:22:29 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/20 19:27:57 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char *str, int len);
char	*ft_strjoin(char *s1, char *s2);
int		have_n(char	*temp);
char	*print_line(char **temp);

#endif