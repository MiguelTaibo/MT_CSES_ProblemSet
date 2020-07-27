#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printArray(array<ll,2> arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i][0] << " ";
    std::cout << std::endl;

    for (i = 0; i < size; i++)
        std::cout << arr[i][1] << " ";
    std::cout << std::endl;
}


bool isIn(ll value, ll x[], int l, int r) {
  for (int i = l;i<r;i++) {
    if (x[i]==value)
      return true;
  }
  return false;
}

void takeValues(array<ll,2> a[], int n) {


}

int main() {

  int n;
  cin >> n;

  ll x[n];
  array<ll,2> aux[n], aux2[n];
  for (int i = 0; i<n;i++) {
    cin >> x[i];
    aux[i][0]=x[i];
    aux[i][1]=i;
  }

  sort(aux, aux+n);
  //printArray(aux,n);

  for (int i = 0; i<n;i++) {
    aux2[i][0]=aux[i][1];
    aux2[i][1]=i;
  }
  sort(aux2,aux2+n);
  //printArray(aux2,n);

  int current = 0;
  int max = 0;
  int l= 0;


  for (int i = 0; i<n;i++) {
    if (aux2[i][1]!=0 && aux[aux2[i][1]][0]==aux[aux2[i][1]-1][0]) {
      for (int j = l; j<i;j++) {
        if (x[j]==x[i]) {
          l = j+1;
          break;
        }
      }
    }

    if ((i-l+1)>max)
      max = (i-l+1);
    //cout << (i-l+1) <<endl

  }
  cout << max <<endl;

}
