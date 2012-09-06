#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readconf.h"

char *readconf(char *infohead, char *keyword, char *filename)
{
	FILE *f;
	char c, *end = infohead;

	f = fopen(filename, "rb");
	while ((c = fgetc(f)) != EOF) {
		if (c == '#' || c == '\"') {
			while ((c = fgetc(f)) != '\n') {
			}
			continue;
		}
		if (c == '\n')
			continue;
		if (c == ':') {
			*end = '\0';
			printf("%s", infohead);
			if (!strcmp(infohead, keyword)) {
				end = infohead;
				continue;
			}
		}
		*end = c;
		end++;
	}
	return infohead;
}
