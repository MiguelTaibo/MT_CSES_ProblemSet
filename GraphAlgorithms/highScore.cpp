#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e5;
const int MXN = 4e5;
int x,m,n;
arr(3) a[mxn];
priority_queue<array<ll,2>> q;
ll value[mxn], sum;
bool ready[mxn];

bool comp (const array<int,3> &a,const array<int,3> &b) {
  if (true || a[0]!=b[0]) return a[0]<b[0];
  else return a[1]<b[1];
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  FOR(m) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    sum += max(0,a[i][2]);
  }
  sort(a, a+m);
  //FOR(m) cout << a[i][0] << " "; cout F;
  //FOR(m) cout << a[i][1] << " "; cout F;
  //FOR(m) cout << a[i][2] << " "; cout F;


  for (int i = 2; i<=n; i++)
    value[i]=LLONG_MIN;

  q.push({0,1});
  while(!q.empty()) {
    int t = q.top()[1];
    q.pop();

    arr(3) next = {t,0,0};
    auto lb = lower_bound(a,a+m,next,comp);
    auto ub = upper_bound(a,a+m,next,comp);


    for (auto it = lb; it!=ub && it!=a+m ; it++) {
      ll b = (*it)[1];
      int w = (*it)[2];
      cout << " " << b SPACE value[b] SPACE value[t]+w  F;
      if (value[t]+w>sum) {
        ready[b]=true;
        value[b]=ULLONG_MAX;
        q.push({value[b],b});
      }
      else if (value[t]+w>value[b]) {
        value[b] = value[t]+w;
        q.push({value[b],b});
      }
    }
  }
  //cout << sum F;
  for (int i= 1; i<=n;i++) {cout << value[i] << " ";} cout F;
  if (ready[n]) cout << "-1" F;
  else  cout << value[n] F;
}
