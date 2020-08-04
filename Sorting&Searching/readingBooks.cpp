#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)

typedef long long ll;
const int mxn = 2e5;
ll m,n, a[mxn], sum;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  FOR(n) {
    cin >> a[i];
    m = max(m,a[i]);
    sum+=a[i];
  }

  cout << max(2*m,sum) <<endl;





}
