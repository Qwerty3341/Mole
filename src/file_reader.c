#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_reader.h"

#define BUFFER_CAP 4096

char *read_file(char *file_name) {
	FILE *meminfo_file = fopen(file_name, "r");
	if (meminfo_file == NULL) {
		perror("Error reading");
		return NULL;
	}

	char *buffer = malloc(BUFFER_CAP);
	if (buffer == NULL) {
		fclose(meminfo_file);
		return NULL;
	}

	buffer[0] = '\0';

	char line[256];
	size_t len = 0;
	while (fgets(line, sizeof(line), meminfo_file) != NULL) {
		size_t line_len = strlen(line);
		if (len + line_len >= BUFFER_CAP - 1) {
			break;
		}
		memcpy(buffer + len, line, line_len + 1);
		len += line_len;
	}

	fclose(meminfo_file);
	return buffer;
}
