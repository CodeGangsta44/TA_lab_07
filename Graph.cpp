#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "string.h"
#include "stdio.h"
#include "Graph.h"
using namespace std;


// void print(point*** graph, int wight){
//   cout << endl << "GRAPH`s DIRECTIONS MATRIX: " << endl;
//   for (int i = 0; i < wight; i++){
//     for (int j = 0; j < wight; j++){
//       switch (graph[i][j] -> direction) {
//         case 1:cout << "↑" << " "; break;
//         case 2:cout << "↗" << " "; break;
//         case 3:cout << "→" << " "; break;
//         case 4:cout << "↘" << " "; break;
//         case 5:cout << "↓" << " "; break;
//         case 6:cout << "↙" << " "; break;
//         case 7:cout << "←" << " "; break;
//         case 8:cout << "↖" << " "; break;
//       }
//     }
//     cout << endl;
//   }
//   cout << endl << "GRAPH`s ADDRESS MATRIX: " << endl;
//   for (int i = 0; i < wight; i++){
//     for (int j = 0; j < wight; j++){
//         cout << graph[i][j] << " ";
//     }
//     cout << endl;
//   }
// }

// void print_nbr(point*** graph, int wight){
//   cout << endl << "NEIGHBORS: " << endl;
//   for (int i = 0; i < wight; i++){
//     for (int j = 0; j < wight; j++){
//       cout << i << " " << j << ": ";
//       for (int k = 0; k < graph[i][j] -> num_of_nbr; k++){
//         cout << graph[i][j] -> list_of_nbr[k] << " ";
//       }
//       cout << endl;
//     }
//     cout << endl;
//   }
// }
//
// void print_path(point*** graph, int wight){
//   ofstream fout;
//   fout.open("output.txt", std::ios_base::app);
//   for (int i = 0; i < wight; i++){
//     for (int j = 0; j < wight; j++){
//       fout << graph[i][j] -> order << " ";
//     }
//     fout << endl;
//   }
//   fout.close();
// }
//
point** create_matrix(int len){
  point** graph = (point**) malloc(len * sizeof(point*));
  for (int i = 0; i < len; i++){
    graph[i] = new point(0, 0, len - 1);
  }
  for (int i = 0; i < len; i++){
    int count = 0;
    for (int j = 0; j < len; j++){
      if (graph[i] != graph[j]) graph[i] -> list_of_nbr[count++] = graph[j];
    }
  }
  return graph;
}
