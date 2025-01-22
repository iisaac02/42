/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_line_reader.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:55:10 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:55:11 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_LINE_READER_H
# define CUB_LINE_READER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_line
{
	char			*line;
	int				size;
	struct s_line	*next;
}					t_line;

char				*ft_strcat(char *str, char c, int size);
int					load_file(char *path, t_line **first, int size);
void				free_file(t_line **first);
int					add_line(t_line **line, char *data, int size);
int					free_ret(char *buf, t_line **first);

#endif
