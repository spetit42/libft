/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 15:39:39 by spetit            #+#    #+#             */
/*   Updated: 2015/04/28 15:39:40 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_copy(char **buff_tmp, char **line, int fd)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (buff_tmp[fd][i] != '\n')
		i++;
	j = i;
	while (buff_tmp[fd][j] != '\0')
		j++;
	buff_tmp[fd][i] = '\0';
	*line = ft_strdup(buff_tmp[fd]);
	buff_tmp[fd][i] = '\n';
	i++;
	if (buff_tmp[fd][i] != '\0')
	{
		tmp = buff_tmp[fd];
		buff_tmp[fd] = ft_strsub(tmp, i, j);
		ft_strdel(&tmp);
		return (buff_tmp[fd]);
	}
	ft_strdel(&buff_tmp[fd]);
	return (buff_tmp[fd]);
}

static char		*ft_copy_buff_tmp(char **buff_tmp, char *buff, int fd)
{
	char	*tmp;

	if (buff_tmp[fd] == NULL)
		buff_tmp[fd] = ft_strdup(buff);
	else
	{
		tmp = buff_tmp[fd];
		buff_tmp[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	return (buff_tmp[fd]);
}

void			ft_cp_end(char **line, char **buf_tmp, char *buff, int fd)
{
	if (*line == NULL && buf_tmp[fd] == NULL)
		*line = ft_strdup(buff);
	else if (buf_tmp[fd] != NULL)
		*line = ft_strdup(buf_tmp[fd]);
	ft_strdel(&buf_tmp[fd]);
}

int				ft_check_buff(char **buff_tmp, char **line, int fd)
{
	buff_tmp[fd] = ft_copy(buff_tmp, line, fd);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		*buff_tmp[512];
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (buff_tmp[fd] != NULL && ft_strchr(buff_tmp[fd], '\n') != NULL)
		return (ft_check_buff(buff_tmp, line, fd));
	if (fd < 0 || fd == 1)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n') != NULL)
		{
			buff_tmp[fd] = ft_copy_buff_tmp(buff_tmp, buff, fd);
			buff_tmp[fd] = ft_copy(buff_tmp, line, fd);
			return (1);
		}
		buff_tmp[fd] = ft_copy_buff_tmp(buff_tmp, buff, fd);
	}
	ft_cp_end(line, buff_tmp, buff, fd);
	return (0);
}
