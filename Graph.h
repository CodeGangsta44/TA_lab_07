#ifndef COURSEWORK_GRAPH_H
#define COURSEWORK_GRAPH_H

struct point{
  int x;
  int y;
  int len;
  point** list_of_nbr;
  float* distances;
  int count_of_nbr_in_stack;
  point(int _x, int _y, int max) {
    list_of_nbr = (point**)malloc(max * sizeof(point*));
    distances = (float*)malloc(max * sizeof(float));
    x = _x;
    y = _x;
    len = max;
    count_of_nbr_in_stack = 0;
  };
  void set_coor(int _x, int _y){x = _x; y = _y;};
  float get_dis(point* next){
    for (int i = 0; i < len; i++){
      if (next == list_of_nbr[i]) return distances[i];
    }
  }
};

//void print(point***, int);
//void print_nbr(point***, int);
//void print_path(point***, int);
point** create_matrix(int);

#endif// COURSEWORK_GRAPH_H
