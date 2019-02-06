#ifndef INPUT_H
# define INPUT_H

# include "util.h"
# include "output.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define STDIN 0

char	*ft_read_file(const char *path, t_params *p);
char	*ft_read_stdin(t_params *p);

#endif