#ifndef NET
#define NET value

#include <netinet/in.h>

struct NetInfo {
	unsigned int upload_data;
	unsigned int download_data;
	char ip[INET_ADDRSTRLEN];
};

struct NetInfo get_net_info();

#endif /* ifndef NET */
