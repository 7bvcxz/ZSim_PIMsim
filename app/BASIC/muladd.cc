#include <iostream>
#include <stdlib.h>
#include <time.h>

int len = 1024*128;

int main() {
  time_t start, end;
  double result;
  float x[len];
  float y[len];
  float z[len];

  std::cout << "0\n";
  for(int i=0; i<len; i++) {
    x[i] = i/3;
    y[i] = (2*i + 1)/3;
	z[i] = 0;
  }
  std::cout << "1\n";

  start = clock();
  for(int j=0; j<64; j++) {
	for(int i=0; i<len; i++) {
	  z[i] += x[i] * y[i] + x[i] - y[i];
    }
  }

  end = clock();

  result = (double)(end - start);
  std::cout.precision(6);
  std::cout << "time taken: " << (result/CLOCKS_PER_SEC) << "s\n";

  return 0;
}
