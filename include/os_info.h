#ifndef OS_INFO
#define OS_INFO value

struct OsInfo {
    char os_name[200];
    char distro[200];
    char hostname[200];
    char kernel_version[200];
    char kernel_compilation[200];
    char architecture[65];
    unsigned long packages;
};

struct OsInfo get_os_info();

#endif /* ifndef OS_INFO */
