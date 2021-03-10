#ifndef SJ_DUMPER_H
#define SJ_DUMPER_H

#include <string.h>
#include <stdio.h>

class Dumper {
public:
    virtual ~Dumper() {};
public:
    virtual void dump(const char* prefix, const char* msg) = 0;
};

class StdDumper: public Dumper {
public:
    StdDumper(char* tag) {
        mTag = tag;
    }
private:
    char *mTag = NULL;

public:
    virtual ~StdDumper() {};

public:
    void dump(const char* prefix, const char* msg) {
        const char* msg_local = (msg == NULL) ? "null" : msg;
        printf("%s: %s %s\n", mTag, prefix, msg_local);
    };
};

#endif
