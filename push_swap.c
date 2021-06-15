#include "push_swap.h"

t_stack *fill_stack(int c,char **v,int multi,char *name)
{
    t_stack *s;
    int i;

    s = malloc(sizeof(t_stack));
    s->table = malloc(sizeof(int) * (c - 1));
    s->tail = (c - 1) * multi;
    i = 0;
    while(i < s->tail)
    {
        s->table[i] = ft_atoi(v[c - i - 1]) * multi;
        i++; 
    }
    s->tail--;
    s->name = name;
    return s;
}

void print_stack(t_stack *stack)
{
    int i = 0;
    printf("%s ->",stack->name);
    if(stack->tail >= 0)
    {
        while(i <= stack->tail)
        {
            printf("%d - ",stack->table[i]);
            i++;
        }
    } 
    printf("\n");
}

void swap_stack(t_stack *stack_a)
{
    int tmp;
    if(stack_a->tail < 1)
        return ;
    tmp = stack_a->table[stack_a->tail];
    stack_a->table[stack_a->tail] = stack_a->table[stack_a->tail - 1];
    stack_a->table[stack_a->tail - 1] = tmp;
    return;
}

void push_stack(t_stack *a, t_stack *b)
{
    int last;
    if(b->tail < 0)
        return;
    last = b->table[b->tail];
    b->tail--;
    a->tail++;
    a->table[a->tail] = last; 
}

void rotate_stack(t_stack *a)
{
    int last, i;
    if(a->tail < 1)
        return;
    i = a->tail;
    last = a->table[a->tail];
    while(i > 0)
    {
        a->table[i] = a->table[i - 1];
        i--;
    }
    a->table[0] = last;
}



void rr_stack(t_stack *a)
{
    int first, i;
    if(a->tail < 1)
        return;
    i = 0;
    first = a->table[0];
    while(i < a->tail)
    {
        a->table[i] = a->table[i + 1];
        i++;
    }
    a->table[a->tail] = first;
}

int main(int c,char **v)
{
    t_stack *stack_a,*stack_b;

    stack_a = fill_stack(c, v, 1,"a");
    stack_b = fill_stack(c, v, 0,"b");

    //rr_stack(stack_a);
    //sort_small_stack(stack_a);
    //pop_by_index(stack_a, 2);
    //sort_on_same_stack(stack_a);
    //push_stack(stack_b,stack_a);
    // print_stack(stack_a);
    //print_stack(stack_a);
    simplify_array(stack_a);
    //print_stack(stack_a);
    //print_stack(stack_b);
    sort_big_stack(stack_a,stack_b);
    //print_stack(stack_a);
    //print_stack(stack_b);
    //printf("%s",v[1]);

}

