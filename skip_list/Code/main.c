#include "skipList.hpp"
#include <stdio.h>

#define M 50000
#define REPETIONS 10

void secondBenchmark() {
  int size = 50000;
  std::cout << "1" << std::endl;

  for (double p = 0; p <= 1.01; p+=0.01) {
    std::cout << p << ":";
  }
  std::cout << std::endl;

  float  n_pointers[101];
  float  n_cost[101];
  for (int i = 0; i < 101; i++){
    n_pointers[i] = 0;
    n_cost[i] = 0;
  }
  int pos = 0;
  for (int j = 0; j < 5; j++) {
    pos = 0;
    for (double p = 0; p <= 1.01; p+=0.01) {
      skipList sl(p);
        //fill skip list
        for (unsigned int i = 0; i < size; i++) {
          std::stringstream ss;
          ss << i;
          sl.insert(i,ss.str());
        }

        //search in find list for cost
        for (unsigned int i = size - 1; i > 0; i--) {
          std::string aux = sl.find(i);
        }
        n_cost[pos] += (double)sl.total_search_cost()/1000000.0;
        ++pos;

    }
  }
  for(int i = 0; i < 101; ++i) {
    std::cout << n_cost[i]/5;
    if (i+1 < 101)
      std::cout << ":";
    else
      std::cout << std::endl;

  }

}

void benchmark(int size) {

  std::cout << "0";
  for (double p = 0.1; p <= 1; p+=0.1) {
    std::cout << ":" << p;
  }
  std::cout << std::endl;

  float  n_pointers[11];
  float  n_cost[11];
  for (int i = 0; i < 11; i++){
    n_pointers[i] = 0;
    n_cost[i] = 0;
  }

  int pos = 0;
  for (int j = 0; j < REPETIONS; j++) {
    pos = 0;
    for (double p = 0; p <= 1; p+=0.1) {
      skipList sl(p);

      //fill skip list
      for (unsigned int i = 0; i < size; i++) {
        std::stringstream ss;
        ss << i;
        sl.insert(i,ss.str());
      }

      //search in find list for cost
      for (unsigned int i = size - 1; i > 0; i--) {
        std::string aux = sl.find(i);
      }
      n_cost[pos] += sl.total_search_cost();
      /*std::cout << sl.total_search_cost();*/
      /*if (p+0.1 < 1.0 )*/
        /*std::cout << ":";*/
      /*else std::cout << std::endl;*/

      /*n_pointers.push_back(sl.number_pointers());*/
      n_pointers[pos] += sl.number_pointers();
      ++pos;
    }
  }
  for(int i = 0; i < 11; ++i) {
    std::cout << n_cost[i]/REPETIONS;
    if (i+1 < 11)
      std::cout << ":";
    else
      std::cout << std::endl;

  }
  for(int i = 0; i < 11; ++i) {
    std::cout << n_pointers[i]/REPETIONS;
    if (i+1 < 11)
      std::cout << ":";
    else
      std::cout << std::endl;

  }


}

void test() {
  int size = M;
  double p = 0.75;

  skipList sl(p);

  //fill skip list
  for (unsigned int i = 0; i < size; i++) {
    std::stringstream ss;
    ss << i;
    sl.insert(i,ss.str());
  }

  //search in find list
  for (unsigned int i = size - 1; i > 0; i--) {
    std::string aux = sl.find(i);
    /*std::cout << "Our string stored in key " << i << "is: " << aux << std::endl;*/
  }
  std::cout << "========REPORT===========" << std::endl;
  std::cout << "N: " << size << std::endl;
  std::cout << "p: " << p << std::endl;
  std::cout << "Total search cost: " << sl.total_search_cost() << std::endl;
  std::cout << "Total pointers: " << sl.number_pointers() << std::endl;

}


int main(int argc, char *argv[]) {
  std::cout << "Testing Skip Lists..." << std::endl;

  /*int option = atoi(argv[1]);*/
  int option = 0;
  if (option = 0) {
    for (int i = M; i <= M*10; i +=M) {
      std::cout << "N: " << i << std::endl;
      benchmark(i);

    }
  } else if (option = 1){
    secondBenchmark();
  } else {
    test();
  }
}
