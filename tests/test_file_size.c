#include "calc_filesize.h"
#include <stdio.h>

int main() {
	printf("File size: %ld bytes\n", calc_filesize("README.md"));
	return 0;
}
