/* Will obtain:
 *	   Upload
 *	   Download
 *	   Ip
 * */

#include "net.h"
#include <arpa/inet.h>
#include <linux/sockios.h>
#include <net/if.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

static void get_ip(const char* iface, char* out, size_t out_size);

struct NetInfo get_net_info()
{
	struct NetInfo net_info = { 0 };

	// Get ip
	get_ip("wlp1s0", net_info.ip, sizeof net_info.ip);
	return net_info;
}

static void get_ip(const char* iface, char* out, size_t out_size)
{
	/*About
	 * This function does some hard things:
	 *	+-------------------------------------------------------------------------------------------+
	 *	| 1.  snprintf				  | Just put Unknown if fd have an error						|
	 *	| 2.  int fd				  | Makes a socket (socket will communicate with kernel)		|
	 *	| 3.  if (fd == -1)			  | Function socket() return -1 if error						|
	 *	| 4.  struct ifreq ifr		  | Struct for access the generic struct for net address		|
	 *	| 5.  memset ...			  | Fills a block of memory with a value of the second argument |
	 *	| 6.  ifr.ifr_ifru ...		  | Specifies the IPv4											|
	 *	| 7.  snprintf(...			  | Copy the interface (eth0 or wlp1s0)							|
	 *	| 8.  if ioctl ...			  | Asks to the kernel descriptor operations (like a socket)	|
	 *	| 9.  struct sockaddr_in* ... | Contains ipv4 on 4 bytes									|
	 *	| 10. inet_ntop(...			  | IP from binary to text										|
	 *	| 11. close(fd)				  | The socket have also to be closed							|
	 *	+-------------------------------------------------------------------------------------------+*/

	snprintf(out, out_size, "%s", "Unknown");
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd == -1)
		return;

	// Initialize the variable with 0 (before memset it will be filled by garbage)
	// Also can use struct ifreq ifr = { 0 };
	struct ifreq ifr;
	memset(&ifr, 0, sizeof ifr);
	ifr.ifr_ifru.ifru_addr.sa_family = AF_INET;
	snprintf(ifr.ifr_ifrn.ifrn_name, sizeof ifr.ifr_ifrn.ifrn_name, "%s", iface);
	// Asks for the IP
	if (ioctl(fd, SIOCGIFADDR, &ifr) == 0) {
		struct sockaddr_in* addr = (struct sockaddr_in*)&ifr.ifr_ifru.ifru_addr;
		// inet_ntop takes:
		//	af: type of direction [IPv4]
		//	cp: ptr to the 4 bytes of IP
		//	buf: buffer to write the resultant text
		//	len: the length of the buffer
		inet_ntop(AF_INET, &addr->sin_addr, out, out_size);
	}
	close(fd);
}
