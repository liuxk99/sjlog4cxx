#ifndef SJ_LOG_H
#define SJ_LOG_H

#include <sys/cdefs.h>
#include <stdio.h>

#include "sjdumper.h"

class SjLog {
public:
    SjLog(char* msg, Dumper* dumper) {
        mMsg = msg;
        this->dumper = dumper;
    }

    ~SjLog() {
        if (dumper != NULL) {
            delete dumper;
            dumper = NULL;
        }
    }

private:
    char* mMsg = NULL;

private:

    void print(const char* prefix, const char* msg) {
        if (dumper != NULL) {
            dumper->dump(prefix, msg);
        }
    }

public:
    void setDumper(Dumper *dumper) {
        this->dumper = dumper;
    }
private:
    Dumper *dumper = NULL;
};

#endif
