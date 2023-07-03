#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Algorithms
{
    public:
    int BinarySearch(vector<int> &v, int key);
    bool IsCircularSorted(vector<int> &v);
};

#endif