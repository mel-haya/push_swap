#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct  s_stack
{
    int *table;
    int head;
    int tail;
}               t_stack;
