#include <stdio.h>

#include "meminfo.h"

int main() {
	meminfo_data d = extract_data_from_meminfo();

	printf("MemTotal:     %ld kB\n", d.ram_total);
	printf("MemFree:      %ld kB\n", d.ram_free);
	printf("MemAvailable: %ld kB\n", d.ram_available);
	printf("SwapTotal:    %ld kB\n", d.swap_total);
	printf("SwapFree:     %ld kB\n", d.swap_available);

	return 0;
}
