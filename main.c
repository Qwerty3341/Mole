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

typedef struct {
	long ram_total;
	long ram_free;
	long ram_available;
	long swap_total;
	long swap_available;
} meminfo_data;

meminfo_data extract_data_from_meminfo(void) {
	meminfo_data data = {0};
	char *meminfo = read_meminfo();
	if (!meminfo) {
		return data;
	}
	data.ram_total = parse_field_meminfo(meminfo, "MemTotal");
	data.ram_free = parse_field_meminfo(meminfo, "MemFree");
	data.ram_available = parse_field_meminfo(meminfo, "MemAvailable");
	data.swap_total = parse_field_meminfo(meminfo, "SwapTotal");
	data.swap_available = parse_field_meminfo(meminfo, "SwapFree");

	free(meminfo);
	return data;
}

int main() {
    meminfo_data d = extract_data_from_meminfo();

    printf("MemTotal:     %ld kB\n", d.ram_total);
    printf("MemFree:      %ld kB\n", d.ram_free);
    printf("MemAvailable: %ld kB\n", d.ram_available);
    printf("SwapTotal:    %ld kB\n", d.swap_total);
    printf("SwapFree:     %ld kB\n", d.swap_available);

	return 0;
}
