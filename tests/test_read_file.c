#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "read_file.h"

int main() {
	char* content = read_file("README.md");
	if(content == NULL) {
		return 1;
	}

	printf("File content\n: %s", content);

	free(content);

	return 0;
}
