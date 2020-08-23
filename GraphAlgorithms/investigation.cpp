#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl
#define INF (ll) 1e15

typedef long long ll;
bool Compare(pair<ll,int> a, pair<ll,int> b) { return a.first>b.first; }
const int mxn = 2e5;
const int mod = 1e9+7;
int n,m,a,b;
ll w;
vector<pair<int,ll>> adj[mxn];
priority_queue<pair<ll ,int>, vector<pair<ll ,int>>, function<bool(pair<ll ,int>, pair<ll ,int>)>> q(Compare);
ll distancia[mxn];
int mp[mxn],MP[mxn];
ll p[mxn];
bool ready[mxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  FOR(m) {
    cin >> a >> b >> w;
    adj[a].push_back({b,w});
  }

  for (int i = 2; i<= n; i++) distancia[i]= INF;

  q.push({0,1});
  p[1]=1;
  while(!q.empty()) {
    a = q.top().second;
    //cout SPACE a SPACE q.top().first F;
    q.pop();

    if (ready[a]) continue;
    ready[a]=true;

    for (auto e: adj[a]) {
      tie(b,w) = e;
      if (distancia[a]+w<distancia[b]) {
        mp[b]=mp[a]+1;
        MP[b]=MP[a]+1;
        p[b]=p[a];
        distancia[b]=distancia[a]+w;
        q.push({distancia[b],b});
      }
      else if (distancia[a]+w==distancia[b]) {
        p[b]+=p[a];
        p[b]%=mod;
        MP[b]=max(MP[b],MP[a]+1);
        mp[b]=min(mp[b],mp[a]+1);
        q.push({distancia[b],b});
      }
    }

  }

  //for (int i = 1; i<=n; i++) cout << p[i] << " "; cout F;
  cout << distancia[n] SPACE p[n] SPACE mp[n] SPACE MP[n] F;



}
