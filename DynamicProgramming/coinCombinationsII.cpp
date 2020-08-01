#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxn = 1e6;
const int mod = 1e9 +7;

int x,c[mxn],n;
ll value[mxn][100];
bool ready[mxn][100];

ll solve(int x, int l)
{
  cout << x << endl;
  if (x==0) return 1;
  else if (x<c[0]) return 0;
  else if (l<0) return 0;
  else if (ready[x][l]) return value[x][l];
  else {
    int res = 0;
    for (int i = 0; i<=x; i+=c[l]) {
      res+=solve(x-i,l-1);
    }
    value[x][l]=res;
    ready[x][l]=true;
    return res;
  }
}


int main() {

  cin >> n >> x;
  for (int i = 0; i<n;i++)
    cin >> c[i];
    sort(c,c+n);
    cout << solve(x,n-1) <<endl;

}
