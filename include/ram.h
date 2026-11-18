#ifndef RAM
#define RAM value
struct RamInfo {
	unsigned long ram_total;
	unsigned long ram_free;
	unsigned long ram_available;
	unsigned long swap_total;
	unsigned long swap_free;
};

struct RamInfo get_ram_info();

#endif /* ifndef RAM */
