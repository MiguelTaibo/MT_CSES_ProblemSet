#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl
#define PR(n,name) for(int i =1;i<=n;i++) cout << name[i] << " "; cout F;

typedef long long ll;

bool Compare(pair<ll,int> a, pair<ll,int> b)
{
    return a.first>b.first;
}

const int mxn = 2e5;
int n,m, k;
vector<pair<int,ll>> adj[mxn];
priority_queue<pair<ll ,int>, vector<pair<ll ,int>>, function<bool(pair<ll ,int>, pair<ll ,int>)>> q(Compare);
vector<ll> respuesta;
int ready[mxn];
int len;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;

  int a,b; ll d,w;
  for (int i = 0;i<m;i++) {
    cin >> a >> b >> w;
    adj[a].push_back({b,w});
  }

  //for (int i = 1; i<=n; i++)  dfs(i);
  //sort(timer, timer+n);
  //for (int i = 0; i<=n; i++) cout << timer[i][0] << " "; cout F;
  //for (int i = 0; i<=n; i++) cout << timer[i][1] << " "; cout F;


  q.push({0,1});
  while(!q.empty() && len < k) {
    a = q.top().second;
    d = q.top().first;
    q.pop();
    ready[a]--;

    if (a==n) {
      respuesta.push_back(d);
      len++;
    }
    for (auto e : adj[a]) {
        tie(b,w) = e;
        if (true) {
          ready[b]++;
          q.push({d+w,b});
        }
    }
  }

  for (int i = 0; i<k;i++) {
    cout << respuesta[i] << " ";
  } cout F;


}
