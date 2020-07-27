#include <bits/stdc++.h>
using namespace std;


int main(){
  int n, x;
  cin >> n >> x;
  array<int,2> a[n];
  for (int i = 0; i<n;i++) {
    cin>>a[i][0];
    a[i][1]=i;
  }
  sort(a,a+n);
  int l = 0, r = n-1;
  while(l<r) {
    if (a[l][0]+a[r][0]==x) {
      cout << a[l][1]+1<<" "<<a[r][1]+1<<endl;
      return 0;
    }
    else if (a[l][0]+a[r][0]<x) {
      l++;
    } else if (a[l][0]+a[r][0]>x) {
      r--;
    }
  }
  cout << "IMPOSSIBLE" <<endl;




}
