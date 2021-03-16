#include <stdio.h>

#include "sjdumper.h"

void SjDumper::dump(const char* prefix, const char* msg) {
    const char* msg_local = (msg == NULL) ? "null" : msg;
    printf("%s: %s %s\n", mTag, prefix, msg_local);
}
