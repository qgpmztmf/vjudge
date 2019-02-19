#include <iostream>
#include <vector>
using namespace std;

#define MAX 105
#define CMAX (1 << 21)
int table[MAX][MAX];
int table2[MAX][MAX];
int l[MAX];
int v[MAX];

int main() {
  int numv;
  int id, adjId;
  int degree, w;
  int minl, uId;
  
  cin >> numv; 
  for(int i = 0; i < numv; i++) {
    l[i] = CMAX;
	v[i] = 0;
  	for(int j = 0; j < numv; j++) {
  		table[i][j] = table[j][i] = CMAX;
  		table2[i][j] = CMAX;
  	}
  }
  
  for(int i = 0; i < numv; i++) {
  	cin >> id >> degree;
  	table[i][i] = 0;
  	table2[i][i] = 0;
  	for(int j = 0; j < degree; j++) {
  		cin >> adjId >> w;
  		table[id][adjId] = table[adjId][id] = w;
  		table2[id][adjId] = w;
  	}
  }
  

  for(int i = 0; i < numv; i++) {
  	for(int j = 0; j < numv; j++) {
  		cout << table[i][j] << " ";
	}
	cout << endl;
  }
  cout <<endl;
  
  for(int i = 0; i < numv; i++) {
  	for(int j = 0; j < numv; j++) {
  		cout << table2[i][j] << " ";
	}
	cout << endl;
  }
  cout <<endl;
  
  l[0] = 0; 
  
  while(1) {
  	minl = CMAX;
    uId = -1;
  	for(int i = 0; i < numv; i++) {
  		if(!v[i] && l[i] < minl) {
  			minl = l[i];
  			uId = i;
  		}
  	}
  	
  	if(uId == -1) break;
  	v[uId] = 1;
  	
  	for(int j = 0; j < numv; j++) {
  		if (!v[j] && table[uId][j] != CMAX){
  			if(l[uId] + table[uId][j] <= l[j])
  			    l[j] = l[uId] + table[uId][j];
  		}
  	}
  }
  for(int i = 0; i < numv; i++) {
  	cout << i << " "  << l[i] << endl;
  }
  
  return 0;
}

