/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:13:13 by xhamzall          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/15 18:23:51 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
/*   Updated: 2025/01/16 02:45:25 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


>>>>>>> f6578ae6c2a75f9ceff0a690b97de10f19daa1de
#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*str_src;
	unsigned char		*str_dest;
	size_t				i;

	i = 0;
	str_dest = dest;
	str_src = src;
	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (dest);
}

static char	*read_ln(int fd, char *str)
{
	char *buffer;
	ssize_t	nbr_read;
	char *temp;

	if (!str)
<<<<<<< HEAD
		str = ft_strdup("");
	buffer =ft_calloc((BUFFER_SIZE + 1 ), 1);
=======
		str = NULL;
	buffer =calloc(BUFFER_SIZE + 1 ,1);
>>>>>>> f6578ae6c2a75f9ceff0a690b97de10f19daa1de
	temp = NULL;
	nbr_read = 0;
	if(!buffer)
		return (NULL);
	while (1)
	{
		nbr_read = read(fd, buffer, BUFFER_SIZE);
		if (nbr_read ==-1)
			return (free(buffer), free(str),NULL);
		if (nbr_read == 0)
			break;
		temp = ft_strjoin(str, buffer);
		str = temp;
		if (ft_strchr(str, '\n'))
			break;
	}
<<<<<<< HEAD
	return (free (temp), free(buffer),str);
=======
	return ( free(buffer),str);
>>>>>>> f6578ae6c2a75f9ceff0a690b97de10f19daa1de
}
static char	*make_ln(char *str)
{
	size_t	i;
	size_t	new_ln;
	char	*mk_line;

	i = 0;
	new_ln = 0;
	if(!str)
		return (NULL);
	while (str[i] && str[i] != '\n' )
		i++;
	if (str[i] == '\n')
		new_ln++;
	mk_line = malloc((new_ln + i) * sizeof(char) + 1);
	if (!mk_line)
		return (NULL);
	ft_memcpy(mk_line, str, i + new_ln);
	mk_line[i + new_ln] = '\0';
	return (mk_line);
}
static char	*prev (char *str)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n' )
		i++;
	if (str[i] == '\0' || str[i + 1] == '\0')
		return(free(str), NULL);
	tmp = ft_strdup(&str[i+1]);
	return(free(str), tmp);
}

char	*get_next_line(int fd)
{
	static char *str;
	char *line;

	str = read_ln(fd, str);
<<<<<<< HEAD
	if(!str)
		return(NULL);
=======
	if (!str)
		str = ft_strdup("");
>>>>>>> f6578ae6c2a75f9ceff0a690b97de10f19daa1de
	line = make_ln(str);
	if(!line || line[0] == 0)
		return(free(str), free (line), NULL);
	str = prev(str);
	return (line);
}
  int	main(void)
{
	int	fd;
	char *line;

	fd = open("txt.txt", O_RDWR);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
<<<<<<< HEAD
=======
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
>>>>>>> f6578ae6c2a75f9ceff0a690b97de10f19daa1de

