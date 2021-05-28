#include "libft/libft.h"
#include "push_swap.h"

t_stack *item_constract(int number)
{
    t_stack *new = malloc(sizeof(t_stack *));
    new->number = number;
    new->next = NULL;
    return new;
}

int count_stack(t_stack *stack)
{
    int i;

    i = 0;
    while(stack)
    {
        stack = stack->next;
        i++;
    }
    return i;
}

void    fill_stack(int c,char **v,t_stack **stack)
{
    int i;

    i = 2;
    t_stack *first = item_constract(ft_atoi(v[1]));
    *stack = first;
    t_stack *second;
    while(i < c)
    {
        second = item_constract(ft_atoi(v[i]));
        first->next = second;
        first = second;
        i++;
    }
}

//*** sa sb ss ***//

void swap_small_stack(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    first = *stack;
    second = first->next;
    second->next = first;
    first->next = NULL;
    *stack = second;
}

void swap_stack(t_stack **stack)
{
    int l;
    int i;
    int j;
    t_stack *tmp;

    i = 1;
    l = count_stack(*stack);
    tmp = *stack;
    if(l < 2)
        return;
    if(l == 2)
    {
        swap_small_stack(stack);
        return;
    }
    while (i != l - 2)
    {
        tmp = tmp->next;
        i++;
    }
    swap_small_stack(&tmp->next);
    return;
}

//****** pa pb *******//

void push_stack(t_stack **a,t_stack **b)
{
    t_stack *b_tail;
    t_stack *a_tail;

    a_tail = *a;
    while(a_tail->next->next)
        a_tail = a_tail->next;
    if(*b)
    {
        b_tail = *b;
        while(b_tail->next)
            b_tail = b_tail->next;
        b_tail->next = a_tail->next;
    }
    else 
        *b = a_tail->next;
    a_tail->next = NULL;
}

// **** ra rb rr ***** //

void rotate_stack(t_stack **stack)
{
    int l;
    t_stack *new_tail;
    
    l = count_stack(*stack);
    if(l < 2)
        return;
    new_tail = *stack;
    while(new_tail->next->next)
        new_tail = new_tail->next;
    new_tail->next->next = *stack;
    *stack = new_tail->next;
    new_tail->next = NULL; 
}

// **** rra rrb rrr ***** //

void rr_stack(t_stack **stack)
{
    int l;
    t_stack *tail;

    
    l = count_stack(*stack);
    if(l < 2)
        return;
    tail = *stack;
    while(tail->next)
        tail = tail->next;
    tail->next = *stack;
    *stack = tail->next->next;
    tail->next->next = NULL;
}

void print_stack(t_stack *stack)
{
    while(stack)
    {

        printf("%d",stack->number);
        stack = stack->next;
        if(stack)
            printf(" - ");
    }
    printf("\n");
}




int main(int c, char **v, char **env)
{
    t_stack *stack_a;
    t_stack *stack_b;

    // if(c <= 2)
    //     return 0;
    stack_b = NULL;
    fill_stack(c,v,&stack_a);
    rr_stack(&stack_a);
    print_stack(stack_a);
    return (0);
}