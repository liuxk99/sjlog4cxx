#ifndef SJDUMPER_H
#define SJDUMPER_H

#include "dumper.h"

class SjDumper: public Dumper {
public:
    SjDumper(char* tag) {
        mTag = tag;
    }
private:
    char *mTag = NULL;

public:
    virtual ~SjDumper() {};

public:
    void dump(const char* prefix, const char* msg);
};

#endif
