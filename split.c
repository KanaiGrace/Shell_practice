#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * main - prints prompt and user input
 * @ac:number of args
 * @av:pointer to pointer to arguments
 * Return:size
 */
int main(int ac, char **av)
{
char *words = NULL;
size_t lenb = 0;
ssize_t rtnget;
char *words_copy = NULL; /* copy of string to split */
char *delim = " \n"; /* char to separate string */
char *split; /* hold string after split */
int split_num = 0, i;
(void)ac;
printf("$");
rtnget = getline(&words, &lenb, stdin);
words_copy = malloc(sizeof(char) * rtnget);/* allocate memory to words_copy */
if (words_copy == NULL)
{
printf("Memory allocation failded");
return (-1);
}
strcpy(words_copy, words);/*copy the string */
if (rtnget == -1)
{
printf("Exit..\n");
return (-1);
}
else
{
split = strtok(words, delim);/* assign outcome of strtok to split */
while (split != NULL) /* count the number of words we have after split */
{
split_num++;
split = strtok (NULL, delim);
}
av = malloc(sizeof(char *) * (split_num));/*allocate mem to hold split strings */
split = strtok(words_copy, delim);
for (i = 0; split != NULL; i++)
{
av[i] = malloc(sizeof(char) * strlen(split));
if (av[i] == NULL)
{
printf("av mem allocation failed");
return (-1);
}
strcpy(av[i], split);
split = strtok(NULL, delim);
}
av[i] = NULL;
for (i = 0; av[i] != NULL; i++)
{
printf("%d: %s\n", i, av[i]);
free(av[i]);
}
free(av);
free(words_copy);
free(words);
}
return (0);
}
