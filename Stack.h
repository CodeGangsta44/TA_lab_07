#ifndef ASSIGNMENT_4_DATA_STRUCTURES_STACK_H
#define ASSIGNMENT_4_DATA_STRUCTURES_STACK_H

#include "Graph.h"

class Stack {
private:
    int curr_size;
    int size;
    point **stack;
    int top;
public:
    Stack(int);
    bool isEmpty();
    bool isInStack(point*);
    void push(point*);
    point* pop();
    point* top_el();
    void show();
    int getSize();
    ~Stack();
};


#endif //ASSIGNMENT_4_DATA_STRUCTURES_STACK_H
