#include "os_info.h"
#include "ram.h"
#include <os_info.h>
#include <stdio.h>

void build_ram_info();

void mole()
{
    struct OsInfo os = get_os_info();
    printf("OS:           %s\n", os.os_name);
    printf("Distro:       %s\n", os.distro);
    printf("Hostname:     %s\n", os.hostname);
    printf("Kernel:       %s\n", os.kernel_version);
    printf("Compilation:  %s\n", os.kernel_compilation);
    printf("Architecture: %s\n", os.architecture);
    printf("Packages:     %lu\n", os.packages);
}

void build_ram_info()
{
    struct RamInfo ram_info = get_ram_info();
    printf("\n#---------------------------------------------------------#\n");
    printf("RAM Total     : %lu\n", ram_info.ram_total);
    printf("RAM Free      : %lu\n", ram_info.ram_free);
    printf("RAM Available : %lu\n", ram_info.ram_available);
    printf("Swap Total    : %lu\n", ram_info.swap_total);
    printf("Swap Free     : %lu\n", ram_info.swap_free);
    printf("\n#---------------------------------------------------------#\n");
}
