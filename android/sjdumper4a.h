#ifndef SJ_DUMPER_H
#define SJ_DUMPER_H

#include "dumper.h"

class SjDumper4A: public Dumper {
public:
    SjDumper4A(char* tag) {
        mTag = tag;
    }
private:
    char *mTag = NULL;

public:
    virtual ~SjDumper4A() {};

public:
    void dump(const char* prefix, const char* msg);
};

#endif
