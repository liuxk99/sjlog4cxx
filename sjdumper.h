#ifndef SJ_DUMPER_H
#define SJ_DUMPER_H

#include <string.h>

class Dumper {
public:
    virtual ~Dumper() {};
public:
    virtual void dump(const char* prefix, const char* msg) = 0;
};

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
