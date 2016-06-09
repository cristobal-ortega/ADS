#ifndef SKIP_LIST_H
#define SKIP_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <chrono>
#include <sys/time.h>
#include <iomanip>      // std::setprecision
#include <unistd.h>

struct Node {
    int key;
    std::string value;

    std::vector<Node*> _next;
    Node* next;
    Node* prev;
    Node (int k, const std::string& v, int level);
};

class skipList {
  public:
    skipList();
    skipList(double probability);
    ~skipList();

    void print();

    void insert (int key, std::string v);
    void remove (int key);
    std::string find(int key);
    bool contains (int key);

    //Support for ADS
    long long total_search_cost();
    int number_pointers();


    Node* head;
    Node* NIL;

  private:
    int maxLevel;
    double prob;
    int _height;
    long long _lastFind;
    long long _totalSearchCost;

    int randomLevel();
    int getLevel (std::vector<Node*>& x);
};

#endif

