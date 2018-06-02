#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "stdio.h"
#include "limits.h"
#include "Graph.h"
#include "Stack.h"

using namespace std;


void minus_one(Stack* st){
  if (st -> top_el() -> count_of_nbr_in_stack > 0) {
    st -> top_el() -> count_of_nbr_in_stack--;
  } else {
    st -> pop();
    minus_one(st);
  }
}


point* find_point(point* curr, Stack* path, int length, float *lop){

  float next_dis = INT_MAX;
  point *sw, *next;;
  for (int i = 0; i < length - 1; i++){
    sw = curr -> list_of_nbr[i];
    if ((curr -> get_dis(sw) < next_dis) && !(path -> isInStack(sw))){
      next_dis = curr -> get_dis(sw);
      next = sw;
    }
  }
  (*lop) += (curr -> get_dis(next));
  return next;
}

float calc_dis(point* p1, point* p2){
  float res_x = (p1 -> x - p2 -> x)*(p1 -> x - p2 -> x);
  float res_y = (p1 -> y - p2 -> y)*(p1 -> y - p2 -> y);
  float res = sqrt(res_x + res_y);
  return res;
}

void set_dis(point** graph, int len){
  for (int i = 0; i < len; i++){
    for(int j = 0; j < len - 1; j++){
      graph[i] -> distances[j] = calc_dis(graph[i], graph[i] -> list_of_nbr[j]);
    }
  }
}


point* find_path(point** graph, int length, float* lop){
  point* curr = graph[0];
  Stack *path_stack = new Stack(length);
  path_stack -> push(graph[0]);


  while(path_stack->getSize() < length){
    curr = find_point(curr, path_stack, length, lop);
    path_stack -> push(curr);
  }
  return path_stack -> pop();
}

int main(int argc, char* argv[]){
  ifstream fin(argv[1]);
  ofstream fout("ip71_dovhopoliuk_07_output.txt");

  int LENGTH;

  fin >> LENGTH;

  point** graph = create_matrix(LENGTH);

  int x, y;
  for (int i = 0; i < LENGTH; i++){
    fin >> x >> y;
    graph[i] -> set_coor(x, y);
  }

  set_dis(graph, LENGTH);

  float *len_of_path = new float;
  *len_of_path = 0;

  point *last = find_path(graph, LENGTH, len_of_path);

  *len_of_path += last -> get_dis(graph[0]);

  cout << "Довжина найкоротшого шляху за алгоритмом найближчого сусіда: "<< *len_of_path << endl << endl;
  fout << *len_of_path << endl;

}
