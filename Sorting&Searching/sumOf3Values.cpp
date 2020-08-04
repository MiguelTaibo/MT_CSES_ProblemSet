#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define SPACE << " " <<

typedef long long ll;
const int mxn = 1e5;
int x,n;
array<int,2> a[mxn];

bool solve2SUM(int avoid, int x, int &v1, int &v2) {
  int i = avoid+1;
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


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> x;
  FOR(n) {
    cin >> a[i][0];
    a[i][1]=i+1;
  }
  sort(a,a+n);

  //FOR(n) cout << a[i][0] << " ";

  int v1, v2;
  bool found = false;
  for (int i = 0;i<n;i++) {
    if (solve2SUM(i,x-a[i][0],v1,v2)) {
      cout << a[i][1] SPACE  v1 SPACE v2<< endl;
      found = true;
      break;
    }
  }
  if (!found)
  cout << "IMPOSSIBLE"<< endl;


}
