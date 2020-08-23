#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 2e5;
int n,m, a,b, len;
queue<int> q;
set<int> s;
set<int> adj[mxn];
vector<int> respuesta;
int pasos[mxn], anterior[mxn];
bool ready[mxn];

void dfs(int a) {

  if (ready[a]) return;
  ready[a]=true;

  int b;
  for(auto e: adj[a])  {
    tie(b) = e;
    dfs(b);
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  FOR(m) {
    cin >> a >> b;
    adj[a].insert(b);
  }

  dfs(1);

  if (!ready[n]) {
    cout << "IMPOSSIBLE" F;
  }
  else {
    q.push(1);
    while(!q.empty()) {
      a = q.front();
      s.erase(a);
      q.pop();
      for (auto e: adj[a]) {
        tie(b)= e;
        if (pasos[a]+1>pasos[b]) {
          auto p = s.insert(b);
          if (p.second)
            q.push(b);
          pasos[b]=pasos[a]+1;
          anterior[b]=a;
        }
      }
    }

    //for (int i = 1; i<= n; i++) cout << pasos[i] << " "; cout F;
    //for (int i = 1; i<= n; i++) cout << anterior[i] << " "; cout F;

    len = pasos[n]+1;
    cout << len F;
    for (int temp = n; temp!=1; temp=anterior[temp]) {
      respuesta.push_back(temp);
    }
    respuesta.push_back(1);
    for (int i = len-1 ; i>=0; i--)
      cout << respuesta[i] << " ";
    cout F;
  }



}
