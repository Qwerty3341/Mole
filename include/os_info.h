#ifndef OS_INFO
#define OS_INFO value

struct OsInfo {
    char* os;
    char* kernel;
    unsigned long packages;
    char* architecture;
};

struct OsInfo get_os_info();

#endif /* ifndef OS_INFO */
