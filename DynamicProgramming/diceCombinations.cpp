#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
const int mxn = 1e6;

bool ready[mxn];
ll value[mxn];


ll getVal(ll n)
{
  if (n==0)
    return 1;
  else if (n<=6)
    return pow(2,n-1);
  else if (n<0)
    return 0;
  else if (ready[n])
    return value[n];
  else {
    ll res = 0;
    for (int i = 1;i<=6;i++)
      res=(res+getVal(n-i))%mod;

    value[n]= res;
    ready[n]=true;
    return res;
  }
}


int main() {
  int n;
  cin >>n;

  cout << getVal(n) <<endl;
}
