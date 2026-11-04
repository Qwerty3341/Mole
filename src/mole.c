#include "os_info.h"
#include "ram.h"
#include <os_info.h>
#include <stdio.h>

void mole()
{
    // RAM INFO
    printf("#--------------------------------------------------------------------------------------#\n");
    struct RamInfo ram_info = get_ram_info();
    printf("| RAM Total        :%lu\n", ram_info.ram_total);
    printf("| RAM Free         :%lu\n", ram_info.ram_free);
    printf("| RAM Available    :%lu\n", ram_info.ram_available);
    printf("| Swap Total       :%lu\n", ram_info.swap_total);
    printf("| Swap Free        :%lu\n", ram_info.swap_free);

    // RESOURSES
    // CPU / GPU

    // OS INFO
    printf("#--------------------------------------------------------------------------------------#\n");
    struct OsInfo os_info = get_os_info();
    printf("| OS               :%s\n", os_info.os_name);
    printf("| Distro           :%s\n", os_info.distro);
    printf("| Hostname         :%s\n", os_info.hostname);
    printf("| Kernel           :%s\n", os_info.kernel_version);
    printf("| Compilation      :%s\n", os_info.kernel_compilation);
    printf("| Architecture     :%s\n", os_info.architecture);
    printf("| Packages         :%lu\n", os_info.packages);
    // NET INFO

    // IP
}
