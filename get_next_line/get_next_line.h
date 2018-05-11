#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <limits.h>
# define BUFF_SIZE 10
typedef struct  s_struct
{
    char        *tmp;
    char        *tmp2;
    char        *b;
}               t_struct;
int             get_next_line(const int fd, char **line);
#endif