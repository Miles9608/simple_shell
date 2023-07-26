#include "shell.h"

/**
 * **strtow - splits a string into words.
 * @str: store string input
 * @d: delimeter
 * Return: array pointer
 */

char **strtow(char *str, char *d)
{
	int miles, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (miles = 0; str[miles] != '\0'; miles++)
		if (!is_delim(str[miles], d) && (is_delim(str[miles + 1], d) || !str[miles + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (miles = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[miles], d))
			miles++;
		k = 0;
		while (!is_delim(str[miles + k], d) && str[miles + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[miles++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: store string input
 * @d: delimeter
 * Return: array pointer
 */
char **strtow2(char *str, char d)
{
	int miles, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (miles = 0; str[miles] != '\0'; miles++)
		if ((str[miles] != d && str[miles + 1] == d) ||
		    (str[miles] != d && !str[miles + 1]) || str[miles + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (miles = 0, j = 0; j < numwords; j++)
	{
		while (str[miles] == d && str[miles] != d)
			miles++;
		k = 0;
		while (str[miles + k] != d && str[miles + k] && str[miles + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[miles++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
