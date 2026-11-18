/********************
 * Will calculate   *
 * Bytes            *
 * GigaBytes        *
 * TeraBytes        *
 * Percent          *
 * ******************/

double kb_to_gb(unsigned long long kilobytes)
{
    return kilobytes / 1048576.0;
}

double kb_to_tb(unsigned long long kilobytes)
{
    return kilobytes / 1073741824.0;
}

double bytes_to_gb(unsigned long long bytes)
{
    return bytes / 1073741824.0;
}

double bytes_to_tb(unsigned long long bytes)
{
    return bytes / 1099511627776.0;
}

/* double bytes_to_percent(unsigned long long bytes) */
/* { */
/*  */
/* } */
