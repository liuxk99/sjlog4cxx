#include <async_safe/log.h>

#include "sjdumper4a.h"

void SjDumper4A::dump(const char* prefix, const char* msg) {
    const char* msg_local = (msg == NULL) ? "null" : msg;
    async_safe_format_log(ANDROID_LOG_INFO, mTag, "%s %s", prefix, msg_local);
}
