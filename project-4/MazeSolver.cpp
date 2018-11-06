/*
@author: Ajani Stewart
@date: November 5, 2018
@file: MazeSolver.cpp
CSCI 235, Fall 2018, Project 4

This is the implementation of MazeSolver.h
*/

#include <fstream>
#include <iostream>
#include <string>

#include "MazeSolver.h"


void MazeSolver::initializeMaze(int rows, int columns) {
  maze_rows_ = rows;
  maze_columns_ = columns;
  maze_ = new char* [maze_rows_];
  for (int i = 0; i < maze_rows_; ++i) {
    maze_[i] = new char[maze_columns_];
  }
}

void MazeSolver::fillMaze(std::ifstream& input_stream) {
  // assuming that it is already open
  int rows, cols;
  input_stream >> rows >> cols;
  initializeMaze(rows,cols);

  for (int cur_row = 0; cur_row < maze_rows_; ++cur_row) {
    for (int cur_col = 0; cur_col < maze_columns_; ++cur_col) {
      input_stream >> maze_[cur_row][cur_col];
    }
  }
}

void MazeSolver::initializeSolution() {
  copyMazetoSolution();
  solution_[0][0] = '>';
  //initialize the stack
  backtrack_stack_.push(Position{0,0});
}

void MazeSolver::copyMazetoSolution() {
  //the solution maze will be the same dimensions
  solution_ = new char* [maze_rows_];
  for (int i = 0; i < maze_rows_; ++i) {
    solution_[i] = new char[maze_columns_];
  }

  for (int cur_row = 0; cur_row < maze_rows_; ++cur_row) {
    for (int cur_col = 0; cur_col < maze_columns_; ++cur_col) {
      solution_[cur_row][cur_col] = maze_[cur_row][cur_col];
    }
  }
}

MazeSolver::MazeSolver(std::string input_file) {
  std::ifstream in_stream(input_file);
  //check if the file was opened correctly
  if (!in_stream.is_open()) {
    std::cout << "Cannot read from " << input_file << '\n';
  } else {
    fillMaze(in_stream);
    initializeSolution();
    maze_ready = true;
    in_stream.close();
  }
}

MazeSolver::~MazeSolver() {
  //delete all the sub arrays first
  for (int cur_row = 0; cur_row < maze_rows_; ++cur_row) {
    delete[] maze_[cur_row];
    delete[] solution_[cur_row];
  }
  delete[] maze_;
  delete[] solution_;
}

bool MazeSolver::mazeIsReady() {
  return maze_ready;
}

bool MazeSolver::solveMaze() {
  Position current_position = backtrack_stack_.top();
  while (!backtrack_stack_.empty()) { 
    if (maze_[current_position.row][current_position.column] == '$') {
      std::cout << "Found the exit!!!\n";
      return true;
    } else if (extendPath(current_position)) { 
      solution_[current_position.row][current_position.column] = '>';
      current_position = backtrack_stack_.top();
    } else {
      maze_[current_position.row][current_position.column] = 'X';
      solution_[current_position.row][current_position.column] = '@';
      backtrack_stack_.pop();
      if (!backtrack_stack_.empty()) {
        current_position = backtrack_stack_.top();
      } else {
        std::cout << "This maze has no solution.\n";
        return false;
      }
    }
  }
  return false;
}

bool MazeSolver::extendPath(Position current_position) {
  bool extended = false;
  if (isExtensible(current_position,SOUTH)) {
    Position new_pos = getNewPosition(current_position,SOUTH);
    backtrack_stack_.push(new_pos);
    extended = true;
  }

  if (isExtensible(current_position,EAST)) {
    Position new_pos = getNewPosition(current_position,EAST);
    backtrack_stack_.push(new_pos);
    extended = true;
  }

  return extended;
}

Position MazeSolver::getNewPosition(Position old_position, direction dir) {
  if (dir == SOUTH) {
    return Position{old_position.row + 1, old_position.column};
  } else {
    return Position{old_position.row, old_position.column + 1};
  }
}

bool MazeSolver::isExtensible(Position current_position, direction dir) {
  bool extensible = false;
  if (dir == SOUTH) {
          // if its on the edge
    if ((current_position.row < (maze_rows_ - 1) ) && ((maze_[current_position.row + 1][current_position.column] == '_') || (maze_[current_position.row + 1][current_position.column] == '$'))) {
          extensible = true;
        }
  } else {
      if (current_position.column < (maze_columns_ - 1) && (((maze_[current_position.row][current_position.column + 1] == '_') || maze_[current_position.row][current_position.column + 1] == '$'))) {
          extensible = true;
        }
    }

  return extensible;
}

void MazeSolver::printSolution() {
  std::cout << "The solution to this maze is:\n";
  for (int i = 0; i < maze_rows_; ++i) {
    for (int j = 0; j < maze_columns_; ++j){
      std::cout << solution_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}