/* Will obtain:
 *     Upload
 *     Download
 *     Ip
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
    snprintf(out, out_size, "%s", "Unknown");

    int fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (fd == -1)
        return;

    struct ifreq ifr;
    memset(&ifr, 0, sizeof ifr);
    ifr.ifr_ifru.ifru_addr.sa_family = AF_INET;
    snprintf(ifr.ifr_ifrn.ifrn_name, sizeof ifr.ifr_ifrn.ifrn_name, "%s", iface);

    if (ioctl(fd, SIOCGIFADDR, &ifr) == 0) {
        struct sockaddr_in* addr = (struct sockaddr_in*)&ifr.ifr_ifru.ifru_addr;
        inet_ntop(AF_INET, &addr->sin_addr, out, out_size);
    }

    close(fd);
}
