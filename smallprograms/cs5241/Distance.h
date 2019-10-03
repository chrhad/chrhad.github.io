// File: Distance.h
// Class header for distance calculator

#ifndef DISTANCE_H
#define DISTANCE_H

class Distance {
public:
  Distance(char* source, char* target);
  ~Distance();
  
  // Main function
  int calculate();
  
private:
  int** matrix;
  char* source;
  char* target;
  int m, n; // row, column
  
  int minimum (int, int, int);
  char charAt (char*, int); // from 1 to char length
  int sub (int, int);
};

// Support function
inline int Distance::minimum (int a, int b, int c) {
  return ((a < b) ? ((a < c) ? a : b) : ((b < c) ? b : c));
}

inline char Distance::charAt (char* str, int i) {
  // from 1 to char length
  return str[i-1];
}

inline int Distance::sub (int i, int j) {
  return ((charAt(source, i) == charAt(target, j)) ? 0 : 2);
}
#endif
