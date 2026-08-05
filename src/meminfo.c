#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "meminfo.h"
#include "file_reader.h"

static long parse_field_meminfo(char *meminfo_content, char *field_name) {
	char *finded = strstr(meminfo_content, field_name);
	if (finded == NULL) {
		return -1;
	}

	finded = strchr(finded, ':');
	if (finded == NULL) {
		return -1;
	}

	long value = atol(finded + 1);
	return value;
}

meminfo_data extract_data_from_meminfo(void) {
	meminfo_data data = {0};
	char *content = read_file("/proc/meminfo");
	if (!content) return data;

	data.ram_total = parse_field_meminfo(content, "MemTotal");
	data.ram_free = parse_field_meminfo(content, "MemFree");
	data.ram_available = parse_field_meminfo(content, "MemAvailable");
	data.swap_total = parse_field_meminfo(content, "SwapTotal");
	data.swap_available = parse_field_meminfo(content, "SwapFree");
	data.ok = 1;

	free(content);
	return data;
}
