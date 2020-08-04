#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define SPACE << " " <<

typedef long long ll;
const int mxn = 2e5;
ll x,n, a[mxn];
ll solution;

void solve(int l, int r, int x) {
  if (x==0) {
    solution++;
  } else if (x>0) {
    solve(l,r+1,x-a[r]);
  }
}

void checkArround(int r, int l) {
  ll sumR=0,sumL=0;
  if (r>0 && a[r-1]==0) solution++;
  if (l<n-1 && a[l+1]==0) solution++;
  for (int i = r-1; i>=0;i--) {
    sumR+=a[i];
    for (int j = l+1;j<n;j++) {
      sumL+=a[j];
      if (sumR+sumL==0) solution++;
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >>x;
  FOR(n)
    cin >> a[i];

  ll sum = 0;
  int r=0, l=0;
  while (sum<x && l<n) {
    sum+=a[l++];
  }

  while (l<=n) {
    if (sum==x) {
      solution++;
      //cout << r SPACE l <<endl;
      checkArround(r,l);
      sum-=a[r++];
    }
    else if (sum<x) sum+=a[l++];
    else if (sum>x) sum-=a[r++];

  }

  cout << solution << endl;


}
