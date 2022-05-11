///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

// C++ program for the above approach
#include <iostream>

using namespace std;

// Function to find estimated
// value of PI using Monte
// Carlo algorithm
void monteCarlo(int N, int K) {
  // Stores X and Y coordinates
  // of a random point
  double x, y;

  // Stores distance of a random
  // point from origin
  double d;

  // Stores number of points
  // lying inside circle
  int pCircle = 0;

  // Stores number of points
  // lying inside square
  int pSquare = 0;
  int i = 0;

// Parallel calculation of random
// points lying inside a circle
#pragma omp parallel firstprivate(x, y, d, i) reduction(+ : pCircle, pSquare) num_threads(K)
  {
    // Initializes random points
    // with a seed
    srand((int)time(NULL));

    for (i = 0; i < N; i++) {
      // Finds random X co-ordinate
      x = (double)rand();

      // Finds random X co-ordinate
      y = (double)rand();

      // Finds the square of distance
      // of point (x, y) from origin
      d = ((x * x) + (y * y));

      // If d is less than or
      // equal to 1
      if (d <= 1) {
        // Increment pCircle by 1
        pCircle++;
      }

      // Increment pSquare by 1
      pSquare++;
    }
  }

  // Stores the estimated value of PI
  double pi = 4.0 * ((double)pCircle / (double)(pSquare));

  // Prints the value in pi
  cout << "Final Estimation of Pi = " << pi;
}

// Driver Code
int main() {
  // Input
  int N = 100000;
  int K = 8;

  // Function call
  monteCarlo(N, K);
}
