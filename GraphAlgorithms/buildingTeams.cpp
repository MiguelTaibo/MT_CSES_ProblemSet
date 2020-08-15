#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e5;
const int MXN = 4e5;
int n, m, len;
array<int, 2> a[MXN];
int teams[mxn];
bool ready[mxn];
bool finish = false;

bool comp (const array<int,2> &a,const array<int,2> &b) {
  if (true || a[0]!=b[0]) return a[0]<b[0];
  else return a[1]<b[1];
}

void setPupil(int pupil, int team) {
  ready[pupil]=true;
  teams[pupil]=team;
}

void checkFriends(int idx, int team) {
  if (ready[idx]) return;
  setPupil(idx, team);

  array<int,2> x = {idx,idx};
  auto lb = lower_bound(a,a+len,x,comp);
  auto ub = upper_bound(a,a+len,x,comp);

  if (lb!=a+len) {
    for (auto it=lb;it!=ub;it++) {
      int pupil = (*it)[1];
      if (ready[pupil] && teams[pupil]==teams[idx]) {
        finish = true;
      }
      else {
        checkFriends(pupil,(team+1)%2);
      }
    }
  }
}

void printA() {
  string sp;
  FOR(len) {
    if (a[i][0]/10) sp=" ";
    else sp = "  ";
    cout << a[i][0] << sp;
  }
  cout F;
  FOR(len) {
    if (a[i][1]/10) sp=" ";
    else sp = "  ";
    cout << a[i][1] << sp;
  }
  cout F;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  len = 2*m;
  for (int i = 0; i<len;i+=2) {
    cin >> a[i][0] >> a[i][1];
    a[i+1][0] = a[i][1];
    a[i+1][1]= a[i][0];
  }
  sort (a, a+len);
  //printA();

  int idx = 1;
  while(idx<=n) {
    if (!ready[idx]) {
      checkFriends(idx, 0);
    }
    idx++;
  }

  if (finish) cout << "IMPOSSIBLE" F;
  else {
    FOR(n)
      cout << teams[i+1]+1 << " ";
    cout F;
  }


}
