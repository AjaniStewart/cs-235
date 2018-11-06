#include <iostream>

#include "MazeSolver.h"

void tester_function() {
  MazeSolver ms("inputB.txt");

  
  //ms.solveMaze();
  for (int i = 0; i < ms.maze_rows_; ++i) {
    for (int j = 0; j < ms.maze_columns_; ++j){
      std::cout << ms.solution_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  
  MazeSolver solver("inputC.txt");
  
  if (solver.mazeIsReady()) {
    solver.solveMaze();
    solver.printSolution();
  }
  // tester_function();
}