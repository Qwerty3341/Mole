/*
 * The Ram will be obtained in the file: /proc/meminfo
 * That file shows the data in kB
 *
 * The data will be:
 * 	RAM Total
 * 	RAM Free
 * 	RAM Available
 * 	Swap Total
 * 	Swap Free
 * */

#include "ram.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RamInfo get_ram_info() {
	// Define the ram info struct
	struct RamInfo data_from_ram = {0};

	// read /proc/meminfo
	FILE *file = fopen("/proc/meminfo", "r");

	if (file == NULL) {
		perror("proc meminfo not found");
		return data_from_ram;
	}

	// Prepare the buffer
	char *lines_buffer = NULL;
	size_t bufsize = 0;
	unsigned long value;

	// search for the values getline returns -1 when reach the end of the file
	while (getline(&lines_buffer, &bufsize, file) != -1) {
		// Ram and swap info
		if (sscanf(lines_buffer, "MemTotal:%lu", &value) == 1)
			data_from_ram.ram_total = value;
		else if (sscanf(lines_buffer, "MemFree:%lu", &value) == 1)
			data_from_ram.ram_free = value;
		else if (sscanf(lines_buffer, "MemAvailable:%lu", &value) == 1)
			data_from_ram.ram_available = value;
		else if (sscanf(lines_buffer, "SwapTotal:%lu", &value) == 1)
			data_from_ram.swap_total = value;
		else if (sscanf(lines_buffer, "SwapFree:%lu", &value) == 1)
			data_from_ram.swap_free = value;
	}

	// free memory from read_file
	free(lines_buffer);
	fclose(file);
	return data_from_ram;
}
