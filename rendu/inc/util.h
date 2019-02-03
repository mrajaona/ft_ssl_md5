#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
**	GNL
*/

# define BUFFER_SIZE 4096
# define DEL EOF

/*
**	Functions
*/

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_strcpy(const char *src, char **dest);
void	ft_strdel(char **as);
void	*ft_memalloc(size_t size);
int		get_next_line(int const fd, char **line);

#endif