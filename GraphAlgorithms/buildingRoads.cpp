#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 4e5;
int n,m,len;
array<int,2> a[mxn];
array<int,2> roads[mxn];
bitset<mxn> b;
ll nroads = 0;

bool comp (const array<int,2> &a,const array<int,2> &b) {
  if (true || a[0]!=b[0]) return a[0]<b[0];
  else return a[1]<b[1];
}

void newRoad(int i, int j) {
  roads[nroads][0]=i;
  roads[nroads][1]=j;
  nroads++;
}

void printArray(array<int,2> arr[], int n) {
  FOR(n) cout << arr[i][0] << " "; cout F;
  FOR(n) cout << arr[i][1] << " "; cout F;
}

void checkConections(int idx) {

  if (b[idx]==1) return;
  b[idx]=1;
  array<int,2> x = {idx,idx};
  auto lb = lower_bound(a,a+len,x,comp);
  auto ub = upper_bound(a,a+len,x,comp);

  if (lb!=a+len) {
    for (auto it=lb;it!=ub;it++) {
      checkConections((*it)[1]);
      b[(*it)[1]]=1;
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  len = 2*m;
  for(int i = 0; i<len;i+=2){
    cin >> a[i][0] >> a[i][1];
    a[i+1][0] = a[i][1];
    a[i+1][1] = a[i][0];
  }
  sort (a,a+len);

  //cout F; printArray(a,len); cout F;

  int idx = 1;
  while (idx<=n) {
    if (b[idx]==0) {
      //cout << idx F;
      newRoad(1,idx);
      checkConections(idx);
    }
    idx++;
  }

  //FOR(n) cout << b[i]; cout F;

  cout << nroads-1 F;
  FOR(nroads-1) {
    cout << roads[i+1][0] SPACE roads[i+1][1] F;
  }

}


/*
  5 4
  1 2
  1 3
  3 4
*/
