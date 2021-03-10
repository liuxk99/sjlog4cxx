// #include <sys/system_properties.h>
#include <string.h>
#include <stdio.h>

#include "sjlog.h"

unsigned char LOG_PROPERTY = 1;

int main(int argc, char** argv) {
    char buf[64] = "";
    sprintf(buf, "%s", __func__);

    char tag[] = "SjLog";
    StdDumper *pDumper = NULL;
    if (LOG_PROPERTY) {
        pDumper = new StdDumper(tag);
    }
    SjLog sjLog(buf, pDumper);

    return 0;
}