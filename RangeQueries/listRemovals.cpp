#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e6;
const int MXN = 4e5;
int n, idx, v, a, copyIdx, minIdx;
ll x[mxn], powV, potencia, offset, inicio;
int value[mxn];

void printV() {
  inicio = 0;
  for (int k = v; k>=0;k--) {
    for (int i = inicio; i<inicio+pow(2,k);i++) {
      cout << value[i] << " ";
    } cout F;
    inicio+=pow(2,k);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i<n;i++) {
    cin >> x[i];
    value[i]++;
  };

  v = ceil(log2(n));
  powV = pow(2,v);
  inicio = 0;
  for (int k = v; k>=0; k--) {
    potencia = pow(2,k);
    inicio+=potencia;
    for (int i = 0; i<potencia; i++) {
      value[inicio+i]=value[inicio+2*i-potencia]+value[inicio+2*i-potencia+1];
    }
  }
  //printV();

  for (int k = 0; k<n;k++) {
    cin >> idx;

    potencia = 2;
    offset=inicio-1;
    a = 0;
    for  (int t = 0; t<v;t++) {
      offset-=potencia;
      if (value[a+offset]<idx) {
        idx-=value[a+offset];
        a++;
      }
      value[a+offset]--;
      a*=2;
      potencia*=2;
    }
    cout <<  x[a/2+offset] << " ";
    //printV();
  }
  cout F;

}
