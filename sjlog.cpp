// #include <sys/system_properties.h>
#include <string.h>
#include <stdio.h>

#include "sjlog.h"

unsigned char LOG_PROPERTY = 1;

int main(int argc, char** argv) {
    const int max_arg_len = 1024;

    char args[max_arg_len] = "";
    for (int i = 0; i < argc; i++) {
        strcat(args, " ");
        strcat(args, argv[i]);
    }

    char buf[max_arg_len + 32] = "";
    sprintf(buf, "%s(%d,'%s')", __func__, argc, args);

    char tag[] = "SjLog";
    StdDumper *pDumper = NULL;
    if (LOG_PROPERTY) {
        pDumper = new StdDumper(tag);
    }
    SjLog sjLog(buf, pDumper);

    printf("hello, %s\n", __func__);
    return 0;
}