/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:49:26 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/14 07:51:14 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fdlist
{
	int				fd;
	char			*prev_line;
	struct s_fdlist	*next;
}					t_fdlist;

char		*get_next_line(int fd);
char		*ft_buffer_cat(char *dest, char *buffer, size_t buffer_size);

void		ft_delete_fd(int fd, t_fdlist **list);

size_t		ft_gnl_strlen(char *s);

t_fdlist	*ft_get_fd(int fd, t_fdlist **list);

#endif
