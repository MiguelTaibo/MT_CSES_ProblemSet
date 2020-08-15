#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e5;
const int MXN = 4e5;
int m,n, len, res;
arr(2) a[MXN];
int previus[mxn];
bool ready[mxn], finish;

void printA() {
  string sp;
  FOR(len) {
    if (a[i][0]/10) sp=" ";
    else sp = "  ";
    cout << a[i][0] << sp;
  }
  cout F;
  FOR(len) {
    if (a[i][1]/10) sp=" ";
    else sp = "  ";
    cout << a[i][1] << sp;
  }
  cout F;
  return;
}

bool comp (const array<int,2> &a,const array<int,2> &b) {
  if (true || a[0]!=b[0]) return a[0]<b[0];
  else return a[1]<b[1];
}

void setPrev(int idx, int prev) {
  ready[idx]=true;
  previus[idx]=prev;
}

void checkNext(int idx, int prev) {
  //cout << prev SPACE idx F;
  if (finish) return;
  if (ready[idx]) { // hemos conseguido lo que queriamos
    finish = true;
    previus[idx]=prev;
    res = prev;
    //cout << "res: " << res F;
    return;
  }
  setPrev(idx, prev);

  array<int,2> x = {idx,idx};
  auto lb = lower_bound(a,a+len,x,comp);
  auto ub = upper_bound(a,a+len,x,comp);

  for (auto it=lb; it!=ub; it++) {
    int next = (*it)[1];
    if (prev!=next)
      checkNext(next,idx);
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  len = 2*m;
  for (int i = 0; i<len;i+=2) {
    cin >> a[i][0] >> a[i][1];
    a[i+1][0] = a[i][1];
    a[i+1][1]= a[i][0];
  }
  sort (a, a+len);
  //printA();
  int idx = 1;
  while(idx<=n) {
    if (!ready[idx]) {
      checkNext(idx,0);
    }
    if (finish) break;
    idx++;
    
  }

  //

  if (!finish) cout << "IMPOSSIBLE" F;
  else {
    //FOR(n) cout << previus[i] << " "; cout F;
    string str;
    int count= 1, i = res;
    do {
      str+=to_string(i);
      str+=' ';
      count++;
      i=previus[i];
    } while (i!=res);
    str += to_string(res);
    cout << count F;
    cout << str F;
  }


}
