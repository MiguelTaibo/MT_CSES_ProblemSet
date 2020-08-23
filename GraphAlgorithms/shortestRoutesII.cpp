#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl
#define INF LLONG_MAX

typedef unsigned long long int ui;
const int mxn = 1e3;
int m,n,q;
ui distancia[mxn][mxn], adj[mxn][mxn];


bool comp (const array<ui,3> &a,const array<ui,3> &b) {
  return a[1]<b[1];
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> q;
  int a,b;
  ui w;
  for (int i = 0; i<m;i++) {
    cin >> a >> b >> w;
    if (!adj[a][b]) adj[a][b]=w;
    else adj[a][b]=min(adj[a][b],w);
    if (!adj[b][a]) adj[b][a]=w;
    else adj[b][a]=min(adj[b][a],w);
  }


  for (int i = 1; i<=n; i++) {
    for (int j = 1; j<=n; j++) {
      if (i==j) distancia[i][j]=0;
      else if (adj[i][j]!=0) distancia[i][j]=adj[i][j];
      else distancia[i][j]=INF;
    }
  }

  for (int k = 1; k<=n;k++) {
    for (int i = 1; i<=n;i++) {
      for (int j = 1; j<=n;j++) {
        distancia[i][j]=min (distancia[i][j], distancia[i][k]+distancia[k][j]);
      }
    }
  }

  for (int i = 0; i<q;i++) {
      cin >> a >> b;
      if (distancia[a][b]==INF) cout << -1 F;
      else cout << distancia[a][b] F;
  }



}
