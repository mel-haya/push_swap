#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"



typedef struct  s_stack
{
    int *table;
    char *name;
    int head;
    int tail;
}               t_stack;

t_stack *fill_stack(int c,char **v,int multi,char *name);
void swap_stack(t_stack *stack_a);
void push_stack(t_stack *a, t_stack *b);
void rotate_stack(t_stack *a);
void rr_stack(t_stack *a);
void sort_small_stack(t_stack *a);
void pop_by_index(t_stack *a, int index);
void sort_five(t_stack *a, t_stack *b);
void print_stack(t_stack *stack);
void sort_on_same_stack(t_stack *a);
void simplify_array(t_stack *s);
void sort_big_stack(t_stack *a,t_stack *b);
void print_stack(t_stack *stack);