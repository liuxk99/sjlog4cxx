#ifndef DUMPER_H
#define DUMPER_H

class Dumper {
public:
    virtual ~Dumper() {};
public:
    virtual void dump(const char* prefix, const char* msg) = 0;
};

#endif
