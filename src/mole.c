#include "data_calculator.h"
#include "net.h"
#include "os_info.h"
#include "ram.h"
#include "resources.h"
#include <os_info.h>
#include <stdio.h>

static void build_ram_info();
static void build_resources_info();
static void build_os_info();

void mole()
{
	// RAM INFO
	printf("#--------------------------------------------------------------------------------------#\n");
	build_ram_info();

	// RESOURSES
	printf("#--------------------------------------------------------------------------------------#\n");
	build_resources_info();

	// OS INFO
	printf("#--------------------------------------------------------------------------------------#\n");
	build_os_info();

	printf("#--------------------------------------------------------------------------------------#\n");
}

static void build_ram_info()
{
	struct RamInfo ram_info = get_ram_info();
	printf("| RAM Total		   :%lu %f %f\n",
		ram_info.ram_total, kb_to_gb(ram_info.ram_total), kb_to_tb(ram_info.ram_total));
	printf("| RAM Free		   :%lu\n",
		ram_info.ram_free);

	printf("| RAM Available    :%lu\n", ram_info.ram_available);
	printf("| Swap Total	   :%lu\n", ram_info.swap_total);
	printf("| Swap Free		   :%lu\n", ram_info.swap_free);
}

static void build_resources_info()
{
	struct Resources resources_info = get_resources_info();
	printf("| Disk Total	   :%f GB\n", bytes_to_gb(resources_info.disk_total));
	printf("| Disk Free		   :%llu\n", resources_info.disk_used);
	printf("| Disk Used		   :%llu\n", resources_info.disk_free);
}

static void build_os_info()
{
	struct OsInfo os_info = get_os_info();
	printf(
		"| OS				:%s\n"
		"| Distro			:%s\n"
		"| Hostname			:%s\n"
		"| Kernel			:%s\n"
		"| Compilation		:%s\n"
		"| Architecture		:%s\n"
		"| Packages			:%lu\n",
		os_info.os_name,
		os_info.distro,
		os_info.hostname,
		os_info.kernel_version,
		os_info.kernel_compilation,
		os_info.architecture,
		os_info.packages);
}
