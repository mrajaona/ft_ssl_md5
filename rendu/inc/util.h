#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdlib.h>

/*
**	GNL
*/

# define BUFFER_SIZE 4096
# define DEL '\n'

/*
**	Functions
*/

size_t	ft_strlen(const char *str);
int	ft_strcmp(const char *s1, const char *s2);
int	get_next_line(int const fd, char **line);

#endif