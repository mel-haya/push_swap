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
    printf("s%s\n",a->name);
}

void p(t_stack *a,t_stack *b)
{
    push_stack(a, b);
    printf("p%s\n",a->name);
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
    printf("r%s\n",a->name);
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
    printf("rr%s\n",a->name);
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

// void push_to_b(t_stack *a,t_stack *b)
// {
//     int i,s,multi,size;

//     if(a->tail > 150)
//         s = a->tail / 12;
//     else
//         s = a->tail / 7;
//     multi = 1;
//     while(a->tail >= 0)
//     {
//         i = 0;
//         size = a->tail;
//         while(i <= size)
//         {  
//             if(a->table[a->tail] < (s * multi))
//                 p(b,a);
//             else
//                 r(a,NULL);
//             i++;
//         }
//         multi++;
//     }
// }

void push_to_b(t_stack *a,t_stack *b)
{
    int i,s,multi,size,midpoint;

    midpoint = a->tail / 2;

    if(a->tail > 150)
        s = a->tail / 12;
    else
        s = a->tail / 6;
    multi = 1;
    while(a->tail >= 0)
    {
        i = 0;
        size = a->tail;
        while(i <= size)
        {  
            if(a->table[a->tail] >= (midpoint - (s * multi)) 
            && a->table[a->tail] < midpoint)
            {
                p(b,a);
                r(b,NULL);
            }
            else if(a->table[a->tail] <= (midpoint + (s * multi)) 
            && a->table[a->tail] >= midpoint)
            {
                p(b,a);
            }
            else
                r(a,NULL);
            i++;
        }
        multi++;
    }
}


int get_largest_pos(t_stack *a)
{
    int i,largest;

    i = 0;
    largest = 0;
    while(i <= a->tail)
    {
        if(a->table[i] > a->table[largest])
            largest = i;
        i++;
    }
    return largest;
}

void push_largest_left(t_stack *b,t_stack *a,int pos)
{
    int largest,flag;

    largest = b->table[pos];
    while(1)
    {
        if(b->table[b->tail] == largest)
        {
            p(a,b);
            break;
        }
        else if(b->table[b->tail] == largest - 1)
            p(a,b);
        else
        {
            r(b ,NULL);
        }
    }
}

void push_largest_right(t_stack *b,t_stack *a,int pos)
{
    int largest = b->table[pos];
    while(1)
    {
        if(b->table[b->tail] == largest)
        {
            p(a,b);
            break;
        }
        else if(b->table[b->tail] == largest - 1)
              p(a,b);
        else
        {
            rr(b ,NULL);
        }
    }
}

void sort_big_stack(t_stack *a,t_stack *b)
{
    int pos;

    push_to_b(a,b);
    while(b->tail >= 0)
    {
        pos = get_largest_pos(b);
        if(pos >= b->tail / 2)
            push_largest_left(b,a,pos);
        else if(pos < b->tail / 2)
            push_largest_right(b,a,pos);
        if(a->table[a->tail] > a->table[a->tail - 1])
            s(a,NULL);
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
