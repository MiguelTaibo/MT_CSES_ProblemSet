#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define SPACE << " " <<

typedef long long ll;
const int mxn = 1e5;
int x,n;
array<int,2> a[mxn];

bool solve2SUM(int ini, int x, int &v1, int &v2) {
  int i = ini;
  int j = n-1;
  while (i<j) {
    if (a[i][0]+a[j][0]==x) {
      v1=a[i][1];
      v2=a[j][1];
      return true;
    }
    else if (a[i][0]+a[j][0]<x) {
      i++;
    }
    else if (a[i][0]+a[j][0]>x) {
      j--;
    }
  }
  return false;
}

bool solve3SUM(int ini, int x, int &v1, int &v2, int &v3) {
  for (int i = ini; i<n;i++ ){
    if (solve2SUM(i+1,x-a[i][0],v1,v2)) {
      v3 = a[i][1];
      return true;
    }
  }
  return false;
}

bool solve4SUM(int ini, int x, int &v1, int &v2, int &v3, int &v4) {
  for (int i = ini; i<n;i++ ) {
    if (solve3SUM(i+1,x-a[i][0],v1,v2,v3)) {
      v4 = a[i][1];
      return true;
    }
  }
  return false;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> x;
  FOR(n) {
    cin >> a[i][0];
    a[i][1]=i+1;
  }
  sort(a,a+n);

  int v1, v2, v3, v4;
  if (solve4SUM(0,x,v1,v2,v3,v4))
    cout << v1 SPACE v2 SPACE v3 SPACE v4 << endl;
  else
    cout << "IMPOSSIBLE"<< endl;


}
