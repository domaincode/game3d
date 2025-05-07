#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int err(char *str)
{
    while(*str)
        write(2, str++,1);
    return (1);
}

int cd(char *av[], int i)
{
    if(i !=2)
        return(err("error: cd: bad arguments\n"));
    else if (chdir(av[1]) == -1)
        return(err("error: cd: cannot change directory to"), err(av[1]), err("\n"));
    return (0);
     
}

