/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddidenko <ddidenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:24:25 by hsievier          #+#    #+#             */
/*   Updated: 2023/06/02 11:03:32 by ddidenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = ft_strjoin(0, line);
	if (ft_clean(line) > 0)
		return (next_line);
	i = read(fd, line, BUFFER_SIZE);
	if (i < 0)
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	while (i > 0)
	{
		next_line = ft_strjoin(next_line, line);
		if (ft_clean(line) > 0)
			break ;
		i = read(fd, line, BUFFER_SIZE);
	}
	return (next_line);
}

// int main()
// {
//  int fd = open("test.txt", O_RDONLY);
//  char *line;
//  line = get_next_line(fd);
//  while (line != NULL)
//  {
//   write(1, line, ft_strlen(line));
//   free(line);
//   line = get_next_line(fd);
//  }
//  return 0;
// }