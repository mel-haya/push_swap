#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_stack
{
    int             number;
    struct s_stack  *next;
}               t_stack;