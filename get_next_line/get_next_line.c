#include "get_next_line.h"
int     nlen(char *str)
{
    int i;
    i = 0;
    if (str == NULL)
        return (0);
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    return (i);
}
int     checknmalloc(const int fd, char **line, char ***stock, t_struct *p)
{
    if (fd < 0 || line == NULL || fd > OPEN_MAX)
        return (-1);
    if (*stock == NULL)
        *stock = malloc(sizeof(char*) * (OPEN_MAX + 1));
    if (!(p->b = malloc(sizeof(char) * BUFF_SIZE + 1)))
        return (-1);
    if (!((*stock)[fd]))
        if (!((*stock)[fd] = ft_strnew(BUFF_SIZE)))
        {
            free(p->b);
            return (-1);
        }
    return (0);
}
void    ft_stock(const int fd, char **line, t_struct *p, char **stock)
{
    *line = ft_strsub(stock[fd], 0, nlen(stock[fd]));
    p->tmp2 = ft_strsub(stock[fd], nlen(stock[fd]) + 1,
    ft_strlen(&stock[fd][nlen(stock[fd])]));
    ft_strdel(&stock[fd]);
    stock[fd] = p->tmp2;
    free(p->b);
}
int     get_next_line(const int fd, char **line)
{
    static char     **stock;
    t_struct        p;
    int             ret;
    if (checknmalloc(fd, line, &stock, &p) < 0)
        return (-1);
    while (!(ft_strchr(stock[fd], '\n')) && (ret = read(fd, p.b, BUFF_SIZE)))
    {
        if (ret == -1)
        {
            free(p.b);
            return (-1);
        }
        p.b[ret] = '\0';
        p.tmp = ft_strjoin(stock[fd], p.b);
        ft_strdel(&stock[fd]);
        stock[fd] = p.tmp;
    }
    if (ft_strlen(stock[fd]) == 0)
    {
        free(p.b);
        return (0);
    }
    ft_stock(fd, line, &p, stock);
    return (1);
}