#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl
#define INF LLONG_MAX-1

typedef long long ll;

bool Compare(pair<ll,int> a, pair<ll,int> b)
{
    return a.first<b.first;
}

const int mxn = 2e5;
int n,m;
vector<pair<int,ll>> adj[mxn];

priority_queue<pair<ll ,int>, vector<pair<ll ,int>>, function<bool(pair<ll ,int>, pair<ll ,int>)>> q(Compare);
ll distancia[mxn], mdist[mxn];
bool ready[mxn];
int a,b;
ll w;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i< m; i++) {
    cin >> a >> b >> w;
    adj[a].push_back({b,w});
  }

  for (int i = 2; i <= n; i++) distancia[i] = INF;

  q.push({0,1});
  while(!q.empty()) {
    int a = q.top().second;
    q.pop();

    if (ready[a]) continue;
    ready[a]=true;

    for (auto e : adj[a]) {
      tie(b,w)  = e;
      if (w<=mdist[a]) {
        if (distancia[a]+w+mdist[a]/2<distancia[b]+mdist[b]/2 || (distancia[a]+w+mdist[a]/2==distancia[b]+mdist[b]/2 && distancia[a]+w+mdist[a]<distancia[b]+mdist[b])) {
          mdist[b]=mdist[a];
          distancia[b]=distancia[a]+w;
          q.push({-(distancia[b]+mdist[b]/2),b});
        }
      }
      else {
        if (distancia[a]+w/2+mdist[a]<distancia[b]+mdist[b]/2 || (distancia[a]+w/2+mdist[a]==distancia[b]+mdist[b]/2 && distancia[a]+w+mdist[a]<distancia[b]+mdist[b])) {
            mdist[b]=w;
            distancia[b]=distancia[a]+mdist[a];
            q.push({-(distancia[b]+mdist[b]/2),b});
        }
      }
    }
  }

  ll res = distancia[n]+mdist[n]/2;

  for (int i = 0; i<=n; i++) {
    ready[i]=false;
    distancia[i]=INF;
    mdist[i]=0;
  }
  distancia[1]=0;

  q.push({0,1});
  while(!q.empty()) {
    int a = q.top().second;
    q.pop();

    //cout << "  " << a F;

    if (ready[a]) continue;
    ready[a]=true;

    for (auto e : adj[a]) {
      tie(b,w)  = e;
      //cout << b SPACE w SPACE next_dist F;
      if (distancia[a]+w<distancia[b]) {
        distancia[b] = distancia[a]+w;
        mdist[b]=max(w,mdist[a]);
        q.push({-distancia[b],b});
      }
    }
  }

  res = min(res,distancia[n]-mdist[n]+mdist[n]/2);


  //for (int i = 0; i<n; i++) cout << distancia[i+1] << " "; cout F;
  cout << res F;


}
