#ifndef RESOURCES
#define RESOURCES value

struct Resources get_resources_info();

struct Resources {
    unsigned long long disk_total;
    unsigned long long disk_used;
    unsigned long long disk_free;
};

#endif /* ifndef RESOURCES */
