/*OS Info
 * Will obtain:
 *	OS
 *	Kernel
 *	Packages
 *	Architecture
 * From files:
 *  /etc/os-release 
 *  /proc/version
 *  /proc/cpuinfo
 * */

#include "os_info.h"
#include <stdio.h>
#include <stdlib.h>

void get_os(struct OsInfo* os_struct);

void get_os_info()
{
    // Make the struct for the info
    struct OsInfo data_from_os = { 0 };
    // Call the functions
    get_os(&data_from_os);
}

void get_os(struct OsInfo* os_struct)
{
    // Read /etc/os-release
    FILE* file = fopen("/etc/os-release", "r");

    if (file == NULL) {
        perror("COULD NOT LOCATE OS-RELEASE");
        return;
    }

    // Make the buffer
    char* buffer_lines = NULL;
    size_t buffer_size = 0;
    char value[250];

    // Search for NAME="Arch Linux"
    while (getline(&buffer_lines, &buffer_size, file) != -1) {
        if (sscanf(buffer_lines, "NAME=\"%249[^\"]", value) == 1) {
            os_struct->os;
            break;
        }
    }

    // free and close
    free(buffer_lines);
    fclose(file);
}

void get_kernel(struct OsInfo* os_struct)
{
    // Read /etc/os-release
    FILE* file = fopen("/proc/version", "r");

    if (file == NULL) {
        perror("NOT FIND PROC/VERSION");
        return;
    }

    // Prepare the memory
    char* buffer_lines = NULL;
    size_t buffer_size = 0;
    char value[250];

    // Find kernel info (Linux version 7.2.11-arch1-1)
    while (getline(&buffer_lines, &buffer_size, file) != -1) {
        if(sscanf(buffer_lines, "Linux version [0-9.0-9.0-9]-.+", value) == 1)
    }

    // close and free
    free(buffer_lines);
    fclose(file);
}

void get_packages(struct OsInfo* os_struct)
{
}

void get_arch(struct OsInfo* os_struct)
{
}
