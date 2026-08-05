#ifndef MEMINFO_H
#define MEMINFO_H

typedef struct {
	long ram_total;
	long ram_free;
	long ram_available;
	long swap_total;
	long swap_available;
	int ok;
} meminfo_data;

meminfo_data extract_data_from_meminfo(void);

#endif
