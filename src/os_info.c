#include "os_info.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

/* Info from os:
 *	os_name[200];
 *	distro[200];
 *	hostname[200];
 *	kernel_version[200];
 *	kernel_compilation[200];
 *	architecture[65];
 *	packages;
 * */

static void get_distro(char* out, size_t out_size);
static unsigned long get_number_of_packages();

struct OsInfo get_os_info()
{
	// Make the structs for the info
	struct OsInfo os_data = { 0 };
	struct utsname os;

	/* Uname info
	 *	sysname -> os name
	 *	nodename -> hostname
	 *	release -> kernel version
	 *	version -> kernel compilation
	 *	machine -> architecture
	 * */

	if (uname(&os) == 0) {
		snprintf(os_data.os_name, sizeof os_data.os_name, "%s", os.sysname);
		snprintf(os_data.hostname, sizeof os_data.hostname, "%s", os.nodename);
		snprintf(os_data.kernel_version, sizeof os_data.kernel_version, "%s", os.release);
		snprintf(os_data.kernel_compilation, sizeof os_data.kernel_compilation, "%s", os.version);
		snprintf(os_data.architecture, sizeof os_data.architecture, "%s", os.machine);
	}

	// Now get the distro
	get_distro(os_data.distro, sizeof os_data.distro);

	// Get the number of packages
	os_data.packages = get_number_of_packages();

	return os_data;
}

static void get_distro(char* out, size_t out_size)
{
	snprintf(out, out_size, "%s", "Unknown");

	FILE* file = fopen("/etc/os-release", "r");
	if (!file)
		return;

	char* line = NULL;
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

static unsigned long get_number_of_packages()
{
	DIR* pacman_dir = opendir("/var/lib/pacman/local/");
	if (pacman_dir == NULL) {
		perror("Not able to open /var/lib/pacman/local/");
		return 0;
	}
	struct dirent* dir_entry;
	unsigned int counter = 0;

	while ((dir_entry = readdir(pacman_dir)) != NULL) {
		if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
			continue;
		}

		if (dir_entry->d_type == DT_DIR) {
			counter++;
		}
	}
	closedir(pacman_dir);
	return counter;
}
