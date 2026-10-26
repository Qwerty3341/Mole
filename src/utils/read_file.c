#include "calc_filesize.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *read_file(char *file_name) {
	/*NOTE
	 * When you use this function
	 * You must free the memory
	 * Example:
	 * 	char* content = read_file("./README.md");
	 * 	free(content)
	 * 	*/

	// Open the file
	FILE *file = fopen(file_name, "r");
	if (file == NULL) {
		perror("ERROR ON READING");
		return NULL;
	}

	// Calc the file size
	long file_size = calc_filesize(file_name);
	if (file_size == -1) {
		fclose(file);
		return NULL;
	}

	// Get file content
	char *file_content = malloc(file_size + 1);
	if (file_content == NULL) {
		fclose(file);
		return NULL;
	}

	// Get the final index
	size_t n = fread(file_content, 1, file_size, file);

	// Put \0 to the final index
	file_content[n] = '\0';

	// Close the file
	fclose(file);

	// file_content ready to return
	return file_content;
}
