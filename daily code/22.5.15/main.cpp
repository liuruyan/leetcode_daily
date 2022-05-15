#include <math.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

double cal(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
  double ans = -1;
  ans = double(abs((b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]))) / 2;
  return ans;
}

double largestTriangleArea(const vector<vector<int>>& points) {
  int n = points.size();
  double result = -1;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        result = max(result, cal(points[i], points[j], points[k]));
      }
    }
  }
  return result;
}
int main() {
  vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
  printf("%f", largestTriangleArea(points));
}