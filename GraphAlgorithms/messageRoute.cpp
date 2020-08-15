#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Mxn = 4e5;
const int mxn = 2e5;

bool comp (const array<int,3> &a,const array<int,3> &b) {
  if (true || a[0]!=b[0]) return a[0]<b[0];
  else return a[1]<b[1];
}

struct Con {
  int i,f;
  int idx,past;
};

int m,n, len, res = 0;
array<int,3> a[Mxn];
bitset<mxn> b;
queue<Con> q;

Con newCon(int i, int f, int idx, int past) {
  Con con ;
  con.i = i;
  con.f = f;
  con.idx = idx;
  con.past = past;
  return con;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  len = 2*m;
  for(int i = 0; i<len;i+=2) {
    cin >> a[i][0] >> a[i][1];
    a[i+1][0]=a[i][1];
    a[i+1][1]=a[i][0];
  }
  sort (a, a+len);

  Con c;
  c = newCon(0,1,0,-1);
  q.push(c);

  array<int,3> x = {0,0,0};
  auto i0 = lower_bound(a,a+len,x,comp);

  bool bk = false;
  while (!q.empty()) {
    c = q.front();
    q.pop();

    x = {c.f,c.f,0};
    auto lb = lower_bound(a,a+len,x,comp);
    auto ub = upper_bound(a,a+len,x,comp);

    for (auto it=lb; it!=ub;it++) {
      if ((*it)[1]==n) {
        a[it-i0][2]=c.idx;
        //cout << it << " " << i0 << " " << it-i0 << endl;
        res = (int)(it-i0);
        bk = true;
        break;
      }
      if (b[(*it)[1]]==0) {
        Con t = newCon((*it)[0],(*it)[1],it-i0, c.idx);
        q.push(t);
        b[(*it)[1]]=1;
        a[it-i0][2]=c.idx;
      }
    }
    if (bk) break;
  }

  if (bk) {
    int solution[mxn];
    int lsol = 0;
    solution[lsol++]=n;
    int temp = res;
    while (a[temp][0]>1 && temp>0){
      solution[lsol++]= a[temp][0];
      temp=a[temp][2];
    }
    solution[lsol++]=1;
    cout << lsol << endl;
    for (int i = lsol-1; i>=0;i--) {
      cout << solution[i] << " ";
    }
    cout << endl;
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }
}
