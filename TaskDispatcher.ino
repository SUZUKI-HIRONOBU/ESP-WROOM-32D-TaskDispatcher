
// Task Dispatcher
// This code was tested under ESP-WROOM-32D.
const char ProgramName[] = "Task Dispatcher Exsample 20190916a";
const char Author[] = "Hironobu SUZUKI";
const char AuthorContact[] = "<suzuki.hironobu@gmail.com>";

#include "TaskModule.h"
#define MAXTASKS 3
TaskModule  tasks[MAXTASKS] = {TaskModule( ), TaskModule( ), TaskModule( )};
void FuncOne();
void FuncTwo();
void FuncThree();
void setup() {
  Serial.begin(115200);
  ShowVersionMessages();
  for (int i = 0 ; i < MAXTASKS ; i++) {
    tasks[i].setinterval((i + 1) * 1000);
  }
  tasks[0].setname("Task1");
  tasks[1].setname("Task2");
  tasks[2].setname("Task3");
  tasks[0].setfunc(&FuncOne);
  tasks[1].setfunc(&FuncTwo);
  tasks[2].setfunc(&FuncThree);
}

void loop() {
  for (int i = 0; i < MAXTASKS ; i++) {
    if (tasks[i].schedule()) {
      char *n = tasks[i].activate();
      Serial.print(n);
      Serial.println(" Done");
    }
  }
}
