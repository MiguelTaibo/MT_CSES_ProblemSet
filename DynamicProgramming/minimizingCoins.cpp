#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e6;
int n,x;
int c[mxn];
int value[mxn];
bool ready[mxn];

int solve(int x) {

  if (x<0) return mxn;
  else if (x==0) return 0;
  else if (ready[x]) return value[x];
  else {
    int res = mxn;
    for (int i = 0; i<n;i++) {
      res = min(res, solve(x-c[i])+1);
    }
    value[x]=res;
    ready[x]=true;
    //cout << x<< " " << res << endl;
    return res;
  }


}


int main() {
  //cout <<"error" << mxn;
  cin >> n >> x;
  //cout << n << " " <<x;
  for (int i = 0; i<n;i++) {
    cin >> c[i];
    //cout << c[i] << " " << endl;
  }

  int sol = solve(x);
  if (sol<mxn)
    cout <<  sol << endl;
  else
    cout << "-1" << endl;
}
