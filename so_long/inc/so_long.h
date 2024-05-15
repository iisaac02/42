/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:16:33 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/14 11:20:52 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	void	*mlx;
	void	*win;
	void	*bush;
	void	*fond;
	void	*poke;
	void	*npc;
	void	*npcstart;
	void	*npcmv;
	void	*npcleft;
	void	*npclmv;
	void	*npcright;
	void	*npcrmv;
	void	*npcback;
	void	*npcbmv;
	void	*imgexit;
	int		errors;
	int		moves;
	int		npccontrol;
	int		linecontrol;
	int		x;
	int		y;
	int		consum;
	int		ex;
	int		back;
	int		wall;
	int		player;
	int		enemy;
	int		height_l;
	int		width_l;
	char	*big_line;
}	t_list;

int		main(int argc, char **argv);
int		init_data(t_list *d, char *map);
int		ft_strlen(const char *s);
int		key_press(int key, t_list *d);
int		check_exit(t_list *d, char letter);
int		ft_free(t_list *d);
void	print_map(t_list *d);
void	read_map(char *map, t_list *d);
void	ft_bzero(void *s, size_t n);
void	ft_error(t_list *d, int num);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		have_n(char	*temp);
char	*ft_itoa(int n);
char	*print_line(char **temp);
char	*ft_strdup(char *str, int len);

#endif