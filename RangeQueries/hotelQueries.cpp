#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e6;
int n, m, v;
ll h[mxn], r, powV;
ll inicio, ant;

/*
void printV() {
  inicio = 0;
  for (int k = v; k>=0;k--) {
    for (int i = inicio; i<inicio+pow(2,k);i++) {
      cout << h[i] << " ";
    } cout F;
    inicio+=pow(2,k);
  }
}
*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i<n; i++) cin >> h[i];

  v = ceil(log2(n));
  powV = pow(2,v);
  inicio = 0;
  for (int k = v; k>=0; k--) {
    ant = pow(2,k);
    inicio+=pow(2,k);
    for (int i = 0; i<ant; i++) {
      h[inicio+i]=max(h[inicio+2*i-ant],h[inicio+2*i-ant+1]);
    }
  }

  //printV();

  ll offset, step, range, next;
  for (int t=0; t<m;t++) {
    cin >> r;
    if (h[inicio-1]<r) {
      cout << 0 << " ";
      continue;
    }
    offset = inicio-3;
    step = inicio-1;
    range = 2;
    while(range<n) {
      //cout << offset << " ";
      if (h[offset]<r)
        offset++;
      offset=2*offset-step-range;
      step-=range;
      range*=2;
    }
    if (h[offset]<r)
      offset++;
    cout  << offset +1 << " ";

    h[offset]-=r;
    //printV();
    step = 0;
    next = 0;
    for (int t =1; t<=v;t++) {
      offset/=2; offset*=2;
      next = (offset-step)/2+range+step;
      //cout << step << " " << range << "   ";
      //cout << offset << " & " << offset+1 << " -> " << next F;
      h[next]=max(h[offset],h[offset+1]);
      step+=range;
      range/=2;
      offset = next;
    }
    //cout F; printV();
  }
  cout F;
}

/*
8 5
3 2 4 1 5 5 2 6

10 10
1 1 1 1 1 1 1 1 1 1

*/
