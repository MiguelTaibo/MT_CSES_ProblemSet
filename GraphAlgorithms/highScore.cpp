#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define PR(n, name) for (int i = 1; i<=n;i++) cout << name[i] << " "; cout << endl;
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long int ll;
const int mxn = 3e4;
const int MXN = 4e5;
int x,m,n;
vector<tuple<int,int,ll>> edges;
vector<int> adj[mxn];
ll distancia[mxn];
int anterior[mxn];
int ready[mxn];

void dfs(int a, int step) {
  //cout << a SPACE step F;
  if (ready[a]==2) { // llegamos al final o podemos llegar al final
    int temp = anterior[a];
    //cout << "  " << a << " pone a dos a ";
    for (int i = 0; i< step;i++) {
      //cout << temp << ", ";
      ready[temp]=2;
      temp = anterior[temp];
    } //cout F;
  }
  else if (ready[a]==1) return;
  else ready[a] = 1;

  for (auto e : adj[a]) {
    anterior[e]=a;
    if (ready[e]!=ready[a])
      dfs(e, step+1);
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  int a, b, w;
  for (int i = 0; i<m;i++) {
    cin >> a >> b >> w;
    edges.push_back({a,b,w});
    adj[a].push_back(b);
  }
  for (int i = 1; i<=n; i++) {
    distancia[i]=-1e10;
  }
  distancia[1]=0;

  ready[n]=2;
  dfs(1,0);
  //PR(n,ready);
  //PR(n,anterior);


  for (int i = 0; i<n ; i++) {
    for (auto e : edges) {
      tie(a,b,w) = e;
      if (distancia[b]<distancia[a]+w) {
        distancia[b]=distancia[a]+w;
        anterior[b]=a;
      }
      distancia[b]=max(distancia[b], distancia[a]+w);
    }
  }

  //FOR(n+1) cout << distancia[i] << " "; cout F;
  //FOR(n+1) cout << anterior[i] << " "; cout F;

  for (auto e: edges) {
    tie(a,b,w) = e;
    if (distancia[b]<distancia[a]+w && ready[b]==2) {
      distancia[n]=-1;
    }
  }

  cout << distancia[n] F;

}
