
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t	ft_stlen(const char *s);
char	*ft_stchr(const char *s, int c);
char	*ft_stjoin( char	*s1, char *s2);
char	*ft_stdup(char *str);
char	*get_next_line(int fd);

#endif