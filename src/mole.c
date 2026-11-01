#include "ram.h"
#include "os_info.h"
#include <os_info.h>
#include <stdio.h>

void build_ram_info();

void mole() {
	// RAM
	build_ram_info();

	struct OsInfo os = get_os_info();

	printf("%s\n %s \n", os.os, os.kernel);
}

void build_ram_info() {
	struct RamInfo ram_info = get_ram_info();
	printf("\n#---------------------------------------------------------#\n");
	printf("RAM Total     : %lu\n", ram_info.ram_total);
	printf("RAM Free      : %lu\n", ram_info.ram_free);
	printf("RAM Available : %lu\n", ram_info.ram_available);
	printf("Swap Total    : %lu\n", ram_info.swap_total);
	printf("Swap Free     : %lu\n", ram_info.swap_free);
	printf("\n#---------------------------------------------------------#\n");
}
