#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mxn = 1e5;
int n,x;

int solve(int x)
{
  if (x==1) return 1;
  else {
    int res = 2;
    set<int> a;
    const double sq = sqrt(x);
    for (int i = 2; i<sq;i++) {
      if ((x/i)*i==x) {
        a.insert(i);
        res+=2;
      }
    }
    if (((int)(x/sq))*sq==x) res++;
    //cout << x<< " "<< sq <<" " << res << endl;
    return res;
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int k = 0; k<n;k++) {
    cin >> x;
    cout << solve(x) << endl;

  }


}
