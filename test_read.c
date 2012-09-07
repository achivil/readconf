#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readconf.h"

int main(void)
{
	char *info;
	info = malloc(sizeof(char) * 1000);
	info = readconf(info, "ipv6", "testconf.conf");
	printf("%s", info);
	return 0;
}

