#ifndef LOGCAT_DUMPER_H
#define LOGCAT_DUMPER_H

#include "sjdumper.h"

class LogcatDumper: public Dumper {
public:
    LogcatDumper(char* tag) {
        mTag = tag;
    }
private:
    char *mTag = NULL;

public:
    virtual ~LogcatDumper() {};

public:
    void dump(const char* prefix, const char* msg);
};

#endif