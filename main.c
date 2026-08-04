#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_meminfo() {
	// Open meminfo for get the data
	FILE *meminfo_file = fopen("/proc/meminfo", "r");
	if (meminfo_file == NULL) { /* fopen fail */
		perror("ERROR reading /proc/meminfo");
		return NULL;
	}

	// Define the buffer for reading the content
	size_t capability = 4096; /* bytes */
	char *buffer = malloc(capability);
	if (buffer == NULL) {
		fclose(meminfo_file);
		return NULL;
	}

	buffer[0] = '\0';

	// Read the lines of meminfo_file
	char line[256]; /* bytes */
	while (fgets(line, sizeof(line), meminfo_file) != NULL) {
		strcat(buffer, line);
	}
	// Closing the FILE
	fclose(meminfo_file);

	return buffer;
}

void print_info() {}

int main() {
	char *ram = read_meminfo();
	if (ram != NULL) {
		printf("%s", ram);
		free(ram);
	}
	return 0;
}
