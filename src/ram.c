/*
 * The Ram will be obtained in the file: /proc/meminfo
 * That file shows the data in kB
 *
 * The data will be:
 * 	RAM Total
 * 	RAM Free
 * 	RAM Available
 * 	Swap Total
 * 	Swap Free
 * */

struct ram_info {
	int ram_total;
	int ram_free;
	int ram_available;
	int swap_total;
	int swap_fre;
};


