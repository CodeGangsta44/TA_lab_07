#include <iostream>
#include <cstring>
#include <cstdlib>
#include "string.h"
#include "stdio.h"
#include "Stack.h"
#include "Graph.h"

using namespace std;

Stack::Stack(int length) {
    curr_size = 0;
    size = length;
    stack = (point**)malloc(size * sizeof(point*));
    //for (int i = 0 ; i < size ; i++) stack[i] = new point(length);
    top = -1;
}

bool Stack::isEmpty() {
    return top == -1;
}

void Stack::push(point* element) {
    curr_size++;
    stack[++top] = element;
}

point* Stack::pop() {
    curr_size--;
    point* res = top > -1 ? stack[top] : NULL;
    stack[top--] = NULL;
    return res;
}

point* Stack::top_el(){
  return stack[top];
}

void Stack::show() {
    int curElemIndex = top;
    while (curElemIndex >= 0) {
        std::cout << stack[curElemIndex--] << ' ';
    }
    std::cout << std::endl;
}

bool Stack::isInStack(point* element) {
  int curElemIndex = top;
  while (curElemIndex >= 0) {
      if (stack[curElemIndex--] == element) return true;
  }
  return false;
}

Stack::~Stack() {
    for (int i = 0 ; i < size ; i++) delete [] stack[i];
    size = 0;
    top = -1;
  }

int Stack::getSize() {
    return curr_size;
}
