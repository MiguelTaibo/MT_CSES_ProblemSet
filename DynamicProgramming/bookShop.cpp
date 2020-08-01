#include <bits/stdc++.h>

using namespace std;

const int mnx = 1e4;
int n,x, m, h,s;
array<int,2> p[mnx];
array<int,2> X[mnx*mnx];
array<int,2> Y[mnx*mnx];

void calcMiddle(array<int,2> x[], int n, int c) {
  for (int i = 0; i<(1<<n);i++) {
    int s = 0;
    int h = 0;
    for (int j = 0; j<n; j++) {
      if (i & (1<<j)) {
        s+=p[j+c][1];
        h+=p[j+c][0];
      }
    }
    x[i][1]=s;
    x[i][0]=h;
  }
}

void printArray(array<int,2> arr[], int n) {
  for (int i = 0; i<n;i++) {
    cout << arr[i][0] << " ";
  }
  cout << endl;
  for (int i = 0; i<n;i++) {
    cout << arr[i][1] << " ";
  }
  cout << endl;
}

int solve() {

  calcMiddle(X,n/2,0);
  calcMiddle(Y,n-n/2,n/2);
  //printArray(X, 1<<(n/2));
  //printArray(Y,1<<(n-n/2));
  int size_X = 1<<(n/2);
  int size_Y = 1<<(n-n/2);

  m = 0;
  sort(Y,Y+size_Y);
  sort(X,X+size_X);

  for (int i = size_X-1; i>=0;i--) {
    for (int j = size_Y-1;j>=0;j--) {
      if (Y[j][1]+X[i][1]<=x) {
        m = max(m,Y[j][0]+X[i][0]);
        break;
      }
    }
  }
  return m;
}


int main() {
  cin >> n >> x;
  for (int i = 0; i<n;i++) {
    cin >> p[i][1];
  }
  for (int i = 0; i<n; i++) {
    cin >> p[i][0];
  }

  //cout << solve() << endl;
  cout << solve() << endl;
}
