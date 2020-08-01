#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 +7;

int n;
ull a,b;

ull solve(ull a, ull b)
{
  if (b==1) return a;
  else {
    ull s = solve(a,b/2);
    if (b%2==0) {
      return (s*s)%mod;
    }
    else  {
      return ((s*s)%mod)*a%mod;
    }
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i<n;i++) {
    cin >> a >> b;
    if (b==0) cout << "1" << endl;
    else if (a==0) cout << "0" << endl;
    else  cout << solve(a,b) << endl;
  }

}
