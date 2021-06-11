#include "push_swap.h"

void s(t_stack *a,t_stack *b)
{
    swap_stack(a);
    if(b)
    {
        swap_stack(b);
        printf("ss\n");
        return;
    }
    printf("s%c\n",a->name);
}

void p(t_stack *a,t_stack *b)
{
    push_stack(a, b);
    printf("p%c\n",a->name);
}

void r(t_stack *a,t_stack *b)
{
    rotate_stack(a);
    if(b)
    {
        rotate_stack(b);
        printf("rr\n");
        return;
    }
    printf("r%c\n",a->name);
}
void rr(t_stack *a,t_stack *b)
{
    rr_stack(a);
    if(b)
    {
        rr_stack(b);
        printf("rrr\n");
        return;
    }
    printf("rr%c\n",a->name);
}

void sort_small_stack(t_stack *a)
{
    int *table;

    table = a->table;
    if(table[2]>table[1] && table[2]>table[0])
        r(a,NULL);
    else if(table[1]>table[2] && table[1]>table[0])
        rr(a,NULL);
    if(table[2]>table[1])
        s(a,NULL);
}

void pop_by_index(t_stack *a, int index)
{
    int times;
    int i;

    i = 0;
    if(index <= a->tail / 2)
        times = index;
    else
        times = a->tail - index - 1;
    while(i <= times)
    {
        if(index <= a->tail / 2)
            rr(a,NULL);
        else
            r(a,NULL);
        i++;
    }
}

int get_smallest(t_stack *a)
{
    int i,smallest;
    
    smallest = 0;
    i = 0;
    while(i <= a->tail)
    {
        if(a->table[i] < a->table[smallest])
            smallest = i;
        i++;
    }
    return smallest;
}

void sort_five(t_stack *a, t_stack *b)
{
    pop_by_index(a, get_smallest(a));
    p(b,a);
    pop_by_index(a, get_smallest(a));
    p(b,a);
    sort_small_stack(a);
    p(a,b);
    p(a,b);
}

int issorted(t_stack *a)
{
    int i, flag;

    flag = 1;
    i = 0;
    while(i < a->tail){

        if(a->table[i] < a->table[i+1])
        {
            flag = 0;
        }
        i++;
    }
    return flag;
}

int get_pos(t_stack *s, int n)
{
    int pos, i;

    i = 0;
    pos = 0;

    while(i <= s->tail)
    {
        if(n > s->table[i])
            pos++;
        i++;
    }
    return pos;
}

void simplify_array(t_stack *s)
{
    int i,*new;

    new = malloc((s->tail + 1) * sizeof(int));

    i = 0;
    while(i <= s->tail)
    {
        new[i] = get_pos(s,s->table[i]);
        i++;
    }
    free(s->table);
    s->table = new;
}

void sort_on_same_stack(t_stack *a)
{
    while(!issorted(a))
    {
        if(a->table[a->tail] < a->table[a->tail - 1])
            s(a,NULL);
        r(a,NULL);
    }
}

// offset
// ac > 150 (12 || 13) offset = ac / 12
// ac < 150 (6) offset = ac / 6

// cas 100 : offset 16 32 48 64


// 0 - 15 16 - 31 32 - 47 48 - 65 ..... 99 90 95 93

// 99 98 97 96 

// 90 95 93 0 - 15 .....

// 7200 7700
// 690 820
