// #include <sys/system_properties.h>
#include <string.h>
#include <stdio.h>
#include <sys/system_properties.h>

#include "sjlog.h"
#include "logcat_dumper.h"

#define LOG_TAG "SjLog"

static int8_t LOG_PROPERTY = 0;
static bool FIRST_CALL = true;

// refs to libcutils/properties.h
#define PROPERTY_VALUE_MAX 91
int8_t __is_property_loggable() {
    char buf[PROPERTY_VALUE_MAX] = "";
    int len = __system_property_get("ro.build.type", buf);
    if (len >= 0) {
        if (strcmp("userdebug", buf) == 0) {
            return 1;
        }
    }
    {
        int len = __system_property_get("persist.log.property", buf);
        if (len >= 0) {
            if (strcmp("1", buf) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char** argv) {
  if (FIRST_CALL) {
    LOG_PROPERTY = __is_property_loggable();
    FIRST_CALL = false;
  }
  printf("LOG_PROPERTY: %d\n", LOG_PROPERTY);

    // printf("hello %s\n", __func__);
    char buf[64] = "";
    sprintf(buf, "%s", __func__);

    char tag[] = LOG_TAG;
    LogcatDumper *pDumper = NULL;
    if (LOG_PROPERTY) {
        pDumper = new LogcatDumper(tag);
    }
    SjLog sjLog(buf, pDumper);

    return 0;
}