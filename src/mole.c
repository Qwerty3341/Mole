#include "ram.h"
#include <stdio.h>

void build_ram_info();

void mole() {
	// RAM
	build_ram_info();
}

void build_ram_info() {
	struct RamInfo ram_info = get_ram_info();
	printf("\n#---------------------------------------------------------#\n");
	printf("RAM Total     : %lu\n", ram_info.ram_total);
	printf("RAM Free      : %lu\n", ram_info.ram_free);
	printf("RAM Available : %lu\n", ram_info.ram_available);
	printf("Swap Total    : %lu\n", ram_info.swap_total);
	printf("Swap Free     : %lu\n", ram_info.swap_free);
}
