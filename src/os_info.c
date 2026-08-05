#include <stdlib.h>
#include <string.h>
#include "file_reader.h"

static char *extract_distro_id(char *os_release) {
	char *line = strstr(os_release, "\nID=");
	if (line == NULL) {
		if (strncmp(os_release, "ID=", 3) == 0) {
			line = os_release;
		} else {
			return NULL;
		}
	}

	line += 3;
	char *end = strchr(line, '\n');
	if (end != NULL) *end = '\0';

	return line;
}

char *get_installed_packages(void) {
	// 1. Detect the distro (Arch, Debian, Fedora)
	char *content = read_file("/etc/os-release");
	if (content == NULL) return NULL;

	char *distro_id = extract_distro_id(content);
	if (distro_id == NULL) {
		free(content);
		return NULL;
	}

	if (strcmp(distro_id, "arch") == 0 || strcmp(distro_id, "manjaro") == 0) {
		// pacman -Q | wc -l
	} else if (strcmp(distro_id, "debian") == 0 || strcmp(distro_id, "ubuntu") == 0) {
		// dpkg -l | wc -l
	} else if (strcmp(distro_id, "fedora") == 0 || strcmp(distro_id, "alma") == 0) {
		// rpm -qa | wc -l
	}

	free(content);

	// 2. Execute the corresponding command to count the packages

	// 3. Format the info

	return NULL;
}


