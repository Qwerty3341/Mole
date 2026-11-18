#include <string.h>

// Headers name
const char ram_header[] = "RAM INFO";
const char resourses_header[] = "RESOURSES";
const char cpu_gpu_header[] = "CPU / GPU";
const char os_header[] = "OS INFO";
const char net_header[] = "NET INFO";

// Columns
const char* ram_columns[] = { "Bytes", "GigaBytes", "TeraBytes", "Percent" };
const char* resourses_columns[] = { "Bytes", "GigaBytes", "TeraBytes", "Percent" };
const char* cpu_gpu_columns[] = { "Percent", "Frequency", "Cores" };
const char* net_columns[] = { "B/s", "KB/s", "MB/s", "Total" };

// Rows
const char* ram_info_rows[] = { "RAM Total", "RAM Free", "RAM Available", "Swap Total", "Swap Free" };
const char* resourses_rows[] = { "Disk Usage", "Disk Free", "VRAM Total", "VRAM Used" };
const char* cpu_gpu_rows[] = { "CPU Usage", "CPU Free", "GPU Usage" };
const char* os_info_rows[] = { "OS", "Distro", "Hostname", "Kernel", "Compilation", "Architecture", "Packages" };
const char* net_rows[] = { "Upload", "Download" };
const char* net_extra_rows[] = { "IP" };


static char* make_table_header(const char header_name[], const char* columns[]);

char* make_ram_table()
{
	return make_table_header(ram_header, ram_columns);
}

static char* make_table_header(const char header_name[], const char* columns[])
{
	char* header = "";
	strcat(header, header_name);
	strcat(header, *columns);
	return header;
}
