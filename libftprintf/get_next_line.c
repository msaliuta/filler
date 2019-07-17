/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:18:14 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 14:35:11 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				linecpy(char **dst, char *src, char c)
{
	int		i;
	int		pos;

	i = -1;
	while (src[++i])
		if (src[i] == c)
			break ;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	if (!(*dst = ft_strncat(*dst, src, i)))
		return (0);
	return (pos);
}

char			*adline(char **s1, char *s2)
{
	char	*str;
	char	*temp;
	size_t	i;
	size_t	j;

	temp = *s1;
	if (!temp || !s2)
		return (NULL);
	str = ft_strnew(ft_strlen(temp) + ft_strlen(s2));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (temp[++i])
		str[i] = temp[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	free(*s1);
	return (str);
}

int				result(t_list **file, char *buf, int fd, char **line)
{
	int		i;
	t_list	*temp;
	char	*tpm;

	temp = *file;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (!(temp->content = adline((char**)&temp->content, buf)))
			return (-1);
		if (ft_strchr(temp->content, '\n'))
			break ;
	}
	if (i < BUFF_SIZE && !ft_strlen(temp->content))
		return (0);
	if ((i = linecpy(line, temp->content, '\n')) < (int)ft_strlen(temp->content))
	{
		tpm = ft_strdup(temp->content + i + 1);
		free(temp->content);
		if (!tpm || ((temp->content = tpm) && 0))
			return (-1);
	}
	else
		ft_strclr(temp->content);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			*buf;
	static t_list	*list;
	t_list			*file;
	int				i;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 ||
	!(buf = (char*)malloc(BUFF_SIZE + 1)) || read(fd, buf, 0) < 0)
		return (-1);
	file = list;
	while (file)
	{
		if ((int)file->content_size == fd)
			break ;
		file = file->next;
	}
	if (!file)
	{
		file = ft_lstnew("", fd);
		ft_lstadd(&list, file);
		file = list;
	}
	i = result(&file, buf, fd, line);
	free(buf);
	return (i);
}
