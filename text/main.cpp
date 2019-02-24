#include <iostream>
#include <vector>
using namespace std;
int p, r;

int main() {
  while(cin >> p >> r && p) {
    cout << 2 * p * r / (p + r) << endl;
  }
  return 0;
}
