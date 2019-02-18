#include <iostream>
#include <vector>
using namespace std;

int minOf(int a, int b) {
	return a < b ? a : b;
}

int main() {
  int numv;
  while(cin >> numv) {
  	vector<int> l(numv, 100001);
	vector<int> v(numv, 0);
	vector<vector<int> > table(numv, vector<int>(numv, 100001));
	int id, adjId;
	int degree, w;
	for(int i = 0; i < numv; i++) {
		cin >> id >> degree;
		table[i][i] = 0;
		for(int j = 0; j < degree; j++) {
			cin >> adjId >> w;
			table[id][adjId] = table[adjId][id] = w;
		}
	}
	
	l[0] = 0; 
	int uId = 0;
	v[uId] = 1;
	
	for(int i = 0; i < numv - 1; i++) {
		int minl = 100001;
		int newUId = -1;
		for(int j = 0; j < numv; j++) {
			if (!v[j]){
				l[j] = minOf(l[j], l[uId] + table[uId][j]);
				if(l[j] < minl) {
					newUId = j;
					minl = l[j];
				}
			}
		}
		uId = newUId;
		v[uId] = 1;
	
	}
	for(int i = 0; i < numv; i++) {
		cout << i << " "  << l[i] << endl;
	}
  }
  return 0;
}


