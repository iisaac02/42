/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:32:21 by aiturria          #+#    #+#             */
/*   Updated: 2024/03/09 11:21:59 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

static char	*ft_deleteline(char *text)
{
	char	*newtext;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!text)
		return (NULL);
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\0')
		return (free(text), NULL);
	newtext = (char *)malloc(((ft_gnlstrlen(text) + 1) - i) * sizeof(char));
	if (!newtext)
		return (free(text), NULL);
	i++;
	while (text[i] != '\0')
		newtext[j++] = text[i++];
	newtext[j] = '\0';
	free(text);
	return (newtext);
}

static char	*ft_newline(char *text)
{
	int		i;
	char	*line;

	i = 0;
	if (*text == '\0')
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(text), NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_gettext(int fd, char *text)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (bytes != 0 && !ft_gnlstrchr(text, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(text);
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		text = ft_gnlstrjoin(text, temp);
		if (!text)
			return (free(temp), NULL);
	}
	free (temp);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text[OPEN_MAX];
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text[fd] = ft_gettext(fd, text[fd]);
	if (!text[fd])
	{
		free(text[fd]);
		return (NULL);
	}
	newline = ft_newline(text[fd]);
	text[fd] = ft_deleteline(text[fd]);
	return (newline);
}

/*int	main(void)
{
	int		fd1 = open("test", O_RDONLY);
	int		fd2 = open("test2", O_RDONLY);
	int		fd3 = open("testy", O_RDONLY);
	char	*line1 = get_next_line(fd1);
	char	*line2 = get_next_line(fd2);
	char	*line3 = get_next_line(fd3);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while (line1 || line2 || line3)
	{
		if (line1)
		{
			printf("Line1: %s\n", line1);
			free(line1);
			line1 = get_next_line(fd1);
		}
		if (line2)
		{
			printf("Line2: %s\n", line2);
			free(line2);
			line2 = get_next_line(fd2);
		}
		if (line3)
		{
			printf("Line3: %s\n", line3);
			free(line3);
			line3 = get_next_line(fd3);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
