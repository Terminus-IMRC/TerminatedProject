#include <stdio.h>
#include <stdlib.h>

void will_and_die(const char *str, const int exitno)
{
	fprintf(stderr, "In the nursery tale, Terminus, the god of boundary, said following:\n%s\n", str);
	exit(exitno);
}
