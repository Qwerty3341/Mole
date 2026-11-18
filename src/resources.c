/*
 * Get the next info:
 *	Disk Usage
 *	Disk Free
 * Disk info is in bytes
 * */

#include "resources.h"
#include <sys/statvfs.h>

struct Resources get_resources_info()
{
	struct Resources resources_info = { 0 };
	struct statvfs buffer;
	int ret = statvfs("/", &buffer);

	if (ret == 0) {
		resources_info.disk_total = (unsigned long long)buffer.f_blocks * buffer.f_frsize;
		resources_info.disk_free = (unsigned long long)buffer.f_bavail * buffer.f_frsize;
		resources_info.disk_used = (unsigned long long)resources_info.disk_total - resources_info.disk_free;
	}

	return resources_info;
}
