#include<iostream>
using namespace std;
const int MAXN = 105;
int n,m,s;
double d[MAXN]={0},g1[MAXN][MAXN]={0},g2[MAXN][MAXN]={0},v;
int floyd()
{
	int i,j,k;
	double newd[MAXN];
	for(i=1;i<=n;i++) newd[i]=d[i];
	for(k=1;k<=n;k++)
	   for(i=1;i<=n;i++)
	      for(j=1;j<=n;j++) {
	      	if((d[i]-g2[i][j])*g1[i][j]>d[j]) d[j]=(d[i]-g2[i][j])*g1[i][j];
          cout << "k: " << k << " i: " << i << " j: " << j << " ";
          for(int ii = 1; ii <= n; ii++) {
            cout << d[ii] << " ";
          }
          cout << endl;
        }
	for(i=1;i<=n;i++) {
    cout << newd[i] << " ";
  }
  cout << endl;
	for(i=1;i<=n;i++) {
		  if(newd[i]<d[i])return 1;
    }
	return 0;
}
int main()
{
	cin>>n>>m>>s>>v;
	int i,j,k;
	for(i=1;i<=m;i++)
	{
		int a,b;
		double c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		g1[a][b]=c,g2[a][b]=d;
		g1[b][a]=e,g2[b][a]=f;
	}
	d[s]=v;
	floyd();
	if(floyd())cout<<"YES" << endl;
	else cout<<"NO" << endl;
}
