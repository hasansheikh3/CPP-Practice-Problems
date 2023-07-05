// Selection sort implementation

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (v[j] < v[min]) {
        min = j;
      }
    }
    swap(v[i], v[min]);
  }
}

// Time complexity: O(n^2)
// Space complexity: O(1)

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    selection_sort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}