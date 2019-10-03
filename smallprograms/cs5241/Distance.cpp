// File: Distance.cpp
// Definition for distance calculator

#include <cstring>

#include "Distance.h"

Distance::Distance(char* source, char* target) {
	this->source = source; this->target = target;
	m = strlen(source); n = strlen(target);
	matrix = new int*[m+1];
	for (int i = 0; i <= m; i++)
		matrix[i] = new int[n+1];
}

Distance::~Distance() {
  for (int i = 0; i <= m; i++) delete [] matrix[i];
  delete [] matrix;
}

// Main function
int Distance::calculate() {
  int i, j; // traversal
  
  // initialization
  matrix[0][0] = 0;
  for (j = 1; j <= n; j++) matrix[0][j] = matrix[0][j-1]+1;
  for (i = 1; i <= m; i++) matrix[i][0] = matrix[i-1][0]+1;
  
  // compute
  for (i = 1; i <= m; i++) { // row
    for (j = 1; j <= n; j++) { // column
      matrix[i][j] = minimum(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1] + sub(i, j));
    }
  }
  return matrix[m][n];
}
