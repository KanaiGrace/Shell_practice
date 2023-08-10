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
(void)av;
char *words = NULL;
size_t lenb = 0;
ssize_t rtnget;
while (1)
{
printf("$");
rtnget = getline(&words, &lenb, stdin);
if (rtnget == -1)
{
printf("Exit..\n");
return (-1);
}
printf("%s\n", words);
}
free(words);
return (0);
}
