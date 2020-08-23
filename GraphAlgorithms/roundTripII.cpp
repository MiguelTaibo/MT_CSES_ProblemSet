#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef unsigned long long int ui;
const int mxn = 2e5;
int m,n,a,b, len, reslen;
vector<int> adj[mxn], nadj[mxn], respuesta;
bool ready[mxn];
int timer, compontent;
array<int,2> times[mxn];
int anterior[mxn];

void dfs(int a) {

  if (ready[a]) return;
  ready[a]=true;
  int b;
  for(auto e: adj[a]) {
      tie(b) = e;
      dfs(b);
  }
  times[a-1]={timer++,a};
}

void dfs2(int a, int ant) {

  if (ready[a]) return;
  //cout << "   " << a F;
  ready[a]=true;
  times[a][0]=compontent;
  anterior[a]=b;
  len++;

  int b;
  for(auto e: nadj[a]) {
      tie(b) = e;
      dfs2(b,a);
      //if (anterior[b]==0)
      anterior[b]=a;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i<m;i++) {
    cin >> a >> b;
    if (a!=b) {
      adj[a].push_back({b});
      nadj[b].push_back({a});
    }
}

  for (int i = 1; i<= n; i++)
    dfs(i);

  sort(times, times+n);

  //for (int i = 0; i< n; i++) cout << times[i][0] << " "; cout F;
  //for (int i = 0; i< n; i++) cout << times[i][1] << " "; cout F;

  for (int i = 1; i<=n; i++) {
    ready[i]=false;
    times[i][0]=0;
  }

  int idx= 0;
  for (int i = 0; i<n;i++) {
    a = times[n-1-i][1];
    if (!ready[a]) {
      //cout << " " << a F;
      if (len>1) {
        break;
      }
      idx = n-i-1;
      len = 0;
      compontent++;
      dfs2(a,0);
    }
  }

  //for (int i = 1; i<= n; i++) cout << times[i][0] << " "; cout F;
  //for (int i = 0; i< n; i++) cout << times[i][1] << " "; cout F;
  //for (int i = 1; i<=n; i++) cout << anterior[i] << " "; cout F;



  a = times[idx][1];
  respuesta.push_back(a);
  a = anterior[a];
  reslen++;
  for (int i = 1; i<len &&  a!=times[idx][1]; i++) {
    respuesta.push_back(a);
    reslen++;
    a = anterior[a];
  }
  respuesta.push_back(a);
  reslen++;
  if (reslen<=2) {
    cout << "IMPOSSIBLE" F;
  }
  else {
    cout << reslen F;
    for (int i = 0; i<reslen; i++) {
      cout << respuesta[i] << " ";
    }
    cout F;    
  }

}
