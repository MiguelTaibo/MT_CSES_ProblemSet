#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e7;
const int MXN = 4e5;
ll q,n, x, s[mxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  for (int i = 0; i<n;i++) {
    cin >> x;
    s[i+1]=s[i]+x;
  }

  int a,b;
  for (int k = 0; k<q;k++) {
    cin >> a >> b;
    cout << s[b]-s[a-1] F;
  }


}
