#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_meminfo() {
	// Open meminfo for get the data
	FILE *meminfo_file = fopen("/proc/meminfo", "r");
	if (meminfo_file == NULL) { /* fopen fail */
		perror("Error reading /proc/meminfo");
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

long parse_field_meminfo(char *meminfo_content, char *field_name) {
	/* RAM and Swap */
	char *finded = strstr(meminfo_content, field_name);
	if (finded == NULL) { /* field not found */
		return -1;
	}

	finded = strchr(finded, ':');
	if (finded == NULL) { /* field not found */
		return -1;
	}

	long value = atol(finded + 1);

	return value;
}

void extract_data_from_meminfo() {
	char *meminfo = read_meminfo();
	long ram_total = parse_field_meminfo(meminfo, "MemTotal");
	long ram_free = parse_field_meminfo(meminfo, "MemFree");
	long ram_available = parse_field_meminfo(meminfo, "MemAvailable");
	long swap_total = parse_field_meminfo(meminfo, "SwapTotal");
	long swap_available = parse_field_meminfo(meminfo, "SwapFree");
}

int main() {
	char *meminfo = read_meminfo();
	if (meminfo != NULL) {
		long t = parse_field_meminfo(meminfo, "MemFree");
		printf("%ld\n", t);
		free(meminfo);
	}
	return 0;
}
