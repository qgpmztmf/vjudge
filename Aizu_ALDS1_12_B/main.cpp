#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
#define CMAX 100001
int table[MAX][MAX];

int minOf(int a, int b) {
	return a < b ? a : b;
}

int main() {
  int numv;
  while(cin >> numv) {
  	vector<int> l(numv, CMAX);
	vector<int> v(numv, 0);
    //vector<vector<int> > table(numv, vector<int>(numv, CMAX));
	int id, adjId;
	int degree, w;

	for(int i = 0; i < numv; i++) {
		for(int j = 0; j < numv; j++) {
			table[i][j] = table[j][i] = CMAX;
		}
	}

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
	
	while(1) {
		int minl = CMAX;
		int newUId = -1;
		for(int j = 0; j < numv; j++) {
			if (!v[j]){
				if(table[uId][j] < CMAX) {
					l[j] = minOf(l[j], l[uId] + table[uId][j]);
				}
				if(l[j] <= minl) {
					newUId = j;
					minl = l[j];
				}
			}
		}
		if(newUId == -1) {
			break;
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


