#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 2e5;
const int mod = 1e9+7;
int n,m, a,b;
queue<int> q;
set<int> s;
set<int> adj[mxn];
ll pasos[mxn];
bool ready[mxn];

int solve(int a) {

  if (ready[a]) return pasos[a];

  ll res = 0;
  for (auto e: adj[a]) {
    tie(b) = e;
    res+=solve(b);
  }

  pasos[a]=res%mod;
  ready[a]=true;
  return res%mod;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  FOR(m) {
    cin >> a >> b;
    adj[a].insert(b);
  }

  pasos[n]=1;
  ready[n]=true;
  solve(1);

  cout << pasos[1] F;

}
