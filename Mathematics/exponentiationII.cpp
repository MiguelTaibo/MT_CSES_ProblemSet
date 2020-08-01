#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const int mod = 1e9 +7;

int n;
unsigned long long int a,b,c;

unsigned long long int solve(unsigned long long int a, unsigned long long int b)
{
  if (b==0) return 1;
  else if (a==0) return 0;
  else if (b==1) return a;
  else {
    unsigned long long int s = solve(a,b/2);
    if (b%2==0) {
      return (s*s)%mod;
    }
    else  {
      return ((s*s)%mod)*a%mod;
    }
  }
}

unsigned long long int noMod(unsigned long long int a, unsigned long long int b)
{
  if (b==0) return 1;
  else if (a==0) return 0;
  else if (b==1) return a;
  else {
    unsigned long long int s = noMod(a,b/2);
    if (b%2==0) {
      return (s*s);
    }
    else  {
      return s*s*a;
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i<n;i++) {
    cin >> a >> b >> c;
    cout << sizeof(a) << endl;
    cout << ULLONG_MAX << endl;
    cout << noMod(b,c) << endl;
    cout << solve(a,noMod(b,c))<<endl;
  }

}
