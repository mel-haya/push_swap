#include "checker.h"

int main(int c, char **v)
{
    t_stack	*stack_a;
	t_stack	*stack_b;
    char *s = (char *) calloc(4, sizeof(char));//tr

	stack_a = fill_stack(c, v, 1, "a");
	stack_b = fill_stack(c, v, 0, "b");
	if (!check_stack(stack_a))
	{
		printf("ERROR\n");
		return (0);
	}
    int l = 0;
    int i;
    while(read(0, buffer, 1)) > 0)
    {
        i = 0;
        while(s[i] != '\n' && l != EOF)
        {
            l = read(0,&s[i],1);
            i++;
        }
        printf("%s\n",s);
    }
	//int i = read(0,&s[1],1);
    //s[0] = 'h';
    //s[1] = 0;
    //printf("%d -> %s\n",i,s);
}