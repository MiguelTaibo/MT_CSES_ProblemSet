#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mnx = 1e4;
const int mod = 1e9 +7;

int n;
bool grid[mnx][mnx];

bool ready[mnx][mnx];
long value[mnx][mnx];

ll solve(int x, int y) {
  if (x==0 && y==0) return 1;
  else if (x<0 or y<0) return 0;
  else if (ready[x][y]) return value[x][y];
  else {
    ll res = 0;
    if (grid[x-1][y])
      res+=solve(x-1,y);
    if (grid[x][y-1])
      res+=solve(x,y-1);
    value[x][y]=res;
    ready[x][y]=true;
    return res%mod;
  }
}


int main() {

  cin >> n;

  char input[n];
  for (int i = 0; i<n;i++) {
    cin >> input;
    for (int j = 0; j< n;j++) {
      if (input[j]=='.') grid[i][j]=true;
      else if (input[j]=='*') grid[i][j]=false;
    }
  }
  if (grid[n-1][n-1])
    cout << solve(n-1,n-1) << endl;
  else
    cout << "0" << endl;
}
