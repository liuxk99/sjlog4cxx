// #include <sys/system_properties.h>
#include <string.h>

#include "sjlog.h"
#include "logcat_dumper.h"
#include "loggable.h"

int main(int argc, char** argv) {

    // printf("hello %s\n", __func__);
    char buf[64] = "";
    sprintf(buf, "%s", __func__);

    char tag[] = "SjLog";
    LogcatDumper *pDumper = NULL;
    if (is_loggable()) {
        pDumper = new LogcatDumper(tag);
    }
    SjLog sjLog(buf, pDumper);

    return 0;
}