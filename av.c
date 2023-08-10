#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints prompt and user input
 * @ac:number of args
 * @av:pointer to pointer to arguments
 * Return:size
 */
int main(int ac, char **av)
{
(void)ac;
int i;
for (i = 0; av[i] != NULL; i++)
{
printf("%s\n", av[i]);
}
return (0);
}
