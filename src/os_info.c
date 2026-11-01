/*OS Info
 * Will obtain:
 *	OS
 *	Kernel
 *	Packages
 *	Architecture
 * From files:
 *  /etc/os-release -> distro name
 *  /proc/version -> kernel version
 *  /proc/cpuinfo
 * */

#include "os_info.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_os(struct OsInfo* os_struct);
char* get_distro(FILE* file, char** buffer, size_t* buffer_size);
char* get_kernel(FILE* file, char** buffer, size_t* buffer_size);

struct OsInfo get_os_info()
{
    // Make the struct for the info
    struct OsInfo data_from_os = { 0 };

    // Files names
    char* files[] = { "/etc/os-release", "/proc/version" };

    // Make the buffer
    char* buffer_lines = NULL;
    size_t buffer_size = 0;

    // Get distro
    FILE* os_release = fopen(files[0], "r"); // file for distro name
    if (os_release == NULL) {
        perror("COULD NOT LOCATE /etc/os-release");
    } else {
        data_from_os.os = get_distro(os_release, &buffer_lines, &buffer_size);
        fclose(os_release);
    }

    // Get kernel version
    FILE* proc_version = fopen(files[1], "r"); // file for kernel version
    if (proc_version == NULL) {
        perror("COULD NOT LOCATE /proc/version");
    } else {
        data_from_os.kernel = get_kernel(proc_version, &buffer_lines, &buffer_size);
		fclose(proc_version);
    }

    // free the buffer
	free(buffer_lines);
	
	return data_from_os;
}

char* get_distro(FILE* file, char** buffer, size_t* buffer_size)
{
    char value[250];

    while (getline(buffer, buffer_size, file) != -1) {
        if (sscanf(*buffer, "NAME=\"%249[^\"]", value) == 1
            || scanf(*buffer, "NAME=\%249[^\n]", value) == 1) {
            return strdup(value);
        }
    }
    return strdup("Unknown (not found)");
}

char* get_kernel(FILE* file, char** buffer, size_t* buffer_size)
{
    char value[250];

    // Find kernel info (Linux version 7.2.11-arch1-1)
    while (getline(buffer, buffer_size, file) != -1) {
        if (sscanf(*buffer, "Linux version %249s", value) == 1) {
            return strdup(value);
        }
    }

    return strdup("Unknown (could not found)");
}

/* void get_packages(struct OsInfo* os_struct) { } */

/* void get_arch(struct OsInfo* os_struct) { } */
