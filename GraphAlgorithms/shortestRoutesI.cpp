#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef unsigned long long ull;
const int mxn = 2e5;
int m,n, len;
arr(3) a[mxn];
priority_queue<array<ull,2>> q;
ull value[mxn];
bool ready[mxn];

bool comp (const array<int,3> &a,const array<int,3> &b) {
  if (true || a[0]!=b[0]) return a[0]<b[0];
  else return a[1]<b[1];
}

void printA() {
  FOR(m) cout << a[i][0] << " "; cout F;
  FOR(m) cout << a[i][1] << " "; cout F;
  FOR(m) cout << a[i][2] << " "; cout F;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i<m;i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    //a[i+1] = {a[i][1],a[i][0], a[i][2]};
  }
  sort(a, a+m);
  //printA(); cout F;

  //inicializamos
  for (int i = 2; i<=n; i++)
    value[i]=ULLONG_MAX;

  q.push({0,1});
  while(!q.empty()) {
    int t = q.top()[1];
    q.pop();

    if (ready[t]) continue;
    ready[t]=true;

    arr(3) next = {t,0,0};
    auto lb = lower_bound(a,a+m,next,comp);
    auto ub = upper_bound(a,a+m,next,comp);
    for (auto it = lb; it!=ub && it!=a+m ; it++) {
      ull b = (*it)[1];
      int w = (*it)[2];
      if (value[t]+w<value[b]) {
        value[b] = value[t]+w;
        q.push({-value[b],b});
      }
    }
  }

  for (int i = 1; i<=n; i++) {
    cout << value[i] << " ";
  } cout F;

}
