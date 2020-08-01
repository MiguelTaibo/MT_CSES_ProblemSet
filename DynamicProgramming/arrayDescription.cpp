#include <bits/stdc++.h>

using namespace std;

const int mnx = 1e5;
const int mod = 1e9+7;

int n, m, x[mnx];
bool first;

bool inRange(int value) {
  return 0<value && value<=m;
}

int solve(int index, int prev) {
  if (index==n) return 1;
  if (abs(x[index]-prev)>1 && x[index]!=0) return 0;
  else if (x[index]!=0) return solve(index+1,x[index]);
  else if (first) {
    first = false;
    int res = 0;
    for (int i = 1; i<=m;i++) {
      res+=solve(index+1,i);
    }
    return res;
  }
  else {
    int res = 0;
    for (int i = -1; i<=1;i++)
      if (inRange(prev+i))
        res+=solve(index+1,prev+i);
    return res;
  }

}


int main() {
  cin >> n >> m;
  for (int i = 0; i<n; i++) {
    cin >> x[i];
  }

  if (x[0]==0) first = true;
  cout<< solve(0, x[0])<<endl;

}
