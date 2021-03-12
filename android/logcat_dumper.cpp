#include <stdio.h>
#include <async_safe/log.h>

#include "logcat_dumper.h"

void LogcatDumper::dump(const char* prefix, const char* msg) {
    const char* msg_local = (msg == NULL) ? "null" : msg;
    // printf("=>:%s, %s %s\n", mTag, prefix, msg_local);
    async_safe_format_log(ANDROID_LOG_INFO, mTag, "%s %s", prefix, msg_local);
    // printf("<-:%s, %s %s\n", mTag, prefix, msg_local);
}
