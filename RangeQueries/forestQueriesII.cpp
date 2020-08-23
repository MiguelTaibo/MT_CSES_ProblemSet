#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e4;
const int MXN = 4e5;
ll q,n, x, s[mxn][mxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  string input;
  for (int i = 1; i<=n;i++) {
    cin >> input;
    for (int j = 1; j<=n;j++) {
      if (input[j-1]=='*') {s[i][j]=1;}
      s[i][j]+=s[i][j-1];
      s[i][j]+=s[i-1][j];
      s[i][j]-=s[i-1][j-1];
    }
  }

  /*
  cout F;
  FOR(n+1) {
    FOR2(n+1) {
      cout << s[i][j]<< " ";
    } cout F;
  }
  */

  int x1,y1,x2,y2;
  ll res;
  for (int k = 0; k<q;k++) {
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--;
    cout << s[x2][y2]+s[x1][y1]-s[x2][y1]-s[x1][y2] F;
  }





}
