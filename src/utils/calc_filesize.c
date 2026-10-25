#include <stdio.h>
#include <sys/stat.h>

long calc_filesize(const char* file_path) {
	struct stat st;

	if (stat(file_path, &st) != 0) {
		perror("ERROR ON STAT");
		return -1;
	}
	return st.st_size;
}
