#include <string.h>
#include <sys/system_properties.h>

#include "loggable.h"

static bool LOG_PROPERTY = false;
static bool FIRST_CALL = true;

// refs to libcutils/properties.h
#define PROPERTY_VALUE_MAX 91
bool __is_loggable() {
    char buf[PROPERTY_VALUE_MAX] = "";
    int len = __system_property_get("ro.build.type", buf);
    if (len >= 0) {
        if (strcmp("userdebug", buf) == 0) {
            return true;
        }
    }
    {
        int len = __system_property_get("persist.log.property", buf);
        if (len >= 0) {
            if (strcmp("1", buf) == 0) {
                return true;
            }
        }
    }
    return false;
}

bool is_loggable() {
    if (FIRST_CALL) {
        FIRST_CALL = false;

        LOG_PROPERTY = __is_loggable();
    }
    return LOG_PROPERTY;
}