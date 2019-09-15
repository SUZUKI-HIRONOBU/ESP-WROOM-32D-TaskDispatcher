#include "Arduino.h"
#include "TaskModule.h"
#include "string.h"

TaskModule::TaskModule() {
  interval = 1;
  last_t = millis();
}
TaskModule::TaskModule(unsigned long millisec) {
  interval = millisec;
  last_t = millis();
}
void TaskModule::setname(char n[]) {
  strncpy(myname, n, MODULE_NAMESIZE);
  //Serial.print(myname);
}
char *TaskModule::getname() {
  return myname;
}
void TaskModule::setfunc(void (*f)()) {
  func=f;
}

void TaskModule::setinterval(unsigned int val) {
  interval = val;
}
unsigned int  TaskModule::getinterval(){
  return interval;
}
boolean TaskModule::schedule() {
  unsigned long t = millis();
  if (t - last_t > interval) {
    last_t = t;
    return true;
  }
  return false;
}
char * TaskModule::activate() {
  func();
  return myname;
}
