#ifndef READCONF
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
typedef struct INFODICT{
  char keyname[100];
  char confinfo[100];
}confinfo;
typedef struct INFO_NODE{
  confinfo
}infonode;
*/
char *readconf(char *infohead, char *keyword, char *filename);
#endif
