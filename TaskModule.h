#include "Arduino.h"
#ifndef TaskModule_h
#define TaskModule_h
#define MODULE_NAMESIZE 64
class TaskModule {
  public:
    TaskModule();
    TaskModule(unsigned long millisec);
    void setname(char *n);
    char *getname();
    void setinterval(unsigned int val);
    unsigned int getinterval();
    boolean schedule();
    char * activate();
    void setfunc(void (*f)());
    char myname[MODULE_NAMESIZE];
    unsigned long interval;
  private:
    unsigned long last_t;
    void  (* func)();
};

#endif
