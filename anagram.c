#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define MAX_WORD 500

static int
cmpstringp(const void *p1, const void *p2)
{
	return (* (char *) p2) - (* (char *) p1);
}

int main(int argc, char *argv[])
{
	char word[MAX_WORD];
	char needle[MAX_WORD];
	char scramble[MAX_WORD];
	int n;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s WORD\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	strcpy(needle, argv[1]);
	n = strlen(needle);
	qsort(needle, n, 1, cmpstringp);

	while (fgets(word, MAX_WORD-1, stdin) != NULL)
	{
		n = strlen(word);

		if (word[n-1] == '\n')
		{
			word[n-1] = '\0';
			n--;
		}

		strcpy(scramble, word);
		qsort(scramble, n, 1, cmpstringp);

		if (strcmp(scramble, needle) == 0)
		{
			printf("%s\n", word);
		}
	}

	exit(EXIT_SUCCESS);
}


