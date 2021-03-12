#include <stdio.h>
#include <string.h>

#include <sys/system_properties.h>

#include "loggable.h"

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

bool is_loggable() {
    if (FIRST_CALL) {
        {
            LOG_PROPERTY = __is_property_loggable();
        }
        FIRST_CALL = false;
    }

    printf("LOG_PROPERTY: %d\n", LOG_PROPERTY);
    if (LOG_PROPERTY) {
        return true;
    }
    return false;
}
