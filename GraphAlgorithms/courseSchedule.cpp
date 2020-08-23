#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 2e5;
int n,m, a ,b;
vector<int> adj[mxn];
int ready[mxn], respuesta[mxn],len;
bool cycle;

void dfs(int a) {
  if (cycle) return;

  if (ready[a]==1) {
    cycle = true;
    return;
  }
  else if (ready[a]==2) return;
  ready[a]=1;

  int b;
  for(auto e: adj[a])  {
    tie(b) = e;
    dfs(b);
  }

  respuesta[len++]=a;
  ready[a]=2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  FOR(m) {
    cin >> a >> b;
    adj[a].push_back(b);
  }

  for (int i = 1; i<= n; i++) {
    dfs(i);
  }

  if (cycle) cout << "IMPOSSIBLE" F;
  else {
    for (int i = len-1;i>=0; i--)
    cout << respuesta[i] << " ";
    cout F;
  }


}
