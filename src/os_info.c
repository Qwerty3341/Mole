#include "os_info.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

/* Info from os:
 *  os name
 *  distro
 *  hostname
 *  kernel_version
 *  architecture
 *  number of packages
 * */

static void get_distro(char *out, size_t out_size);

struct OsInfo get_os_info()
{
    // Make the structs for the info
    struct OsInfo data = { 0 };
    struct utsname os;

    /* Uname info
     *  sysname -> os name
     *  nodename -> hostname
     *  release -> kernel version
     *  version -> kernel compilation
     *  machine -> architecture
     * */

    if (uname(&os) == 0) {
        snprintf(data.os_name, sizeof data.os_name, "%s", os.sysname);
        snprintf(data.hostname, sizeof data.hostname, "%s", os.nodename);
        snprintf(data.kernel_version, sizeof data.kernel_version, "%s", os.release);
        snprintf(data.kernel_compilation, sizeof data.kernel_compilation, "%s", os.version);
        snprintf(data.architecture, sizeof data.architecture, "%s", os.machine);
    }

    // Now get the distro
    get_distro(data.distro, sizeof data.distro);

    // Get the number of packages

    return data;
}

static void get_distro(char *out, size_t out_size)
{
    snprintf(out, out_size, "%s", "Unknown");

    FILE *file = fopen("/etc/os-release", "r");
    if (!file)
        return;

    char *line = NULL;
    size_t line_size = 0;
    char value[250];

    while (getline(&line, &line_size, file) != -1) {
        if (sscanf(line, "PRETTY_NAME=\"%249[^\"]", value) == 1
            || sscanf(line, "PRETTY_NAME=%249[^\n]", value) == 1) {
            snprintf(out, out_size, "%s", value);
            break;
        }
    }

    free(line);
    fclose(file);
}
