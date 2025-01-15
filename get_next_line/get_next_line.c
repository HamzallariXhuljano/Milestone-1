/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:13:13 by xhamzall          #+#    #+#             */
/*   Updated: 2025/01/15 14:11:31 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*read_ln(int fd, char *str)
{
	char *buffer;
	size_t	nbr_read;
	char *temp;

	buffer =ft_calloc((BUFFER_SIZE + 1 ), 1);
	temp = NULL;
	nbr_read = 2;
	if(!buffer)
		return (NULL);
	while (1)
	{
		if (nbr_read <= 0)
			return (free(buffer), free(temp),NULL);
		nbr_read = read(fd, buffer, BUFFER_SIZE);
		temp = ft_strjoin(str, buffer);
		str = temp;
		if (ft_strchr(str, '\n'))
			break;
	}
	free(buffer);
	buffer = NULL;
	return ( str);
}

char	*get_next_line(int fd)
{
	static char *str;
	char *line;

	if (!str)
		str = ft_strdup("");
	line = read_ln(fd, str);
	if(!line)
		return(free(str), NULL);
	return (line);
}
// int main()
// {
// 	//int	fd = open("text.txt", O_RDWR);
// 	char *line;

// 	while ((line = get_next_line(0)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	free(line);
// 	//close(fd);
// 	return (0);
// }
