#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readconf.h"

char *readconf(char *infohead, char *keyword, char *filename)
{
	FILE *f;
	char c, *end = infohead;
  infonode *link_head, *new_node;
  confinfo *dictnode, dictlink[100];
  int i = 0;

  dictnode = malloc(sizeof(confinfo));
	f = fopen(filename, "rb");
	while ((c = fgetc(f)) != EOF) {
		if (c == '#' || c == '\"') {
			while ((c = fgetc(f)) != '\n') {
			}
			continue;
		}//jump over the comment
		*end = c;
    if (c == ':') {
      *end = '\0';
      end = infohead;
      strcpy((char *)&(dictnode->keyname), infohead);
      continue;
    }
    if (c == '\n') {
		  *end = '\0';
      end = infohead;
      strcpy((char *)&(dictnode->info), infohead);
      dictlink[i] = *dictnode;
      i++;
      continue;
    }
    end++;
  }
  for (i = i - 1; i >= 0; i--) {
    if (!strcmp(dictlink[i].keyname, keyword)) {
      //printf("keyname: %s\t\tinfo: %s\n", dictlink[i].keyname, dictlink[i].info);
      strcpy(infohead, dictlink[i].info);
      //printf("now info is %s\n", infohead);
      return infohead;
    }
  }
  return "No info!\n";
}
