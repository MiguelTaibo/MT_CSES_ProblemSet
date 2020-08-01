#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5;

string A, B;
//int value[mxn][mxn];
//bool ready[mxn][mxn];
int calls;
int size_A;
int size_B;

int dif(int i,int j) {
  if (A[i]==B[j]) return 0;
  return 1;
}

bool goInA(int r, int dif, int offset, int index) {

  for (int i=r+1; i<=index; i++) {
    for (int j=r+offset+1; j<=index+offset;j++) {
      if (A[i]==B[j]) return true;
    }
  }

  return false;
}

bool goInB(int r, int dif, int offset, int index) {

  for (int i=r+1; i<=index; i++) {
    for (int j=r+offset+1; j<=index+offset;j++) {
      if (B[i]==A[j]) return true;
    }
  }

  return false;
}

int solveA(int r, int dif, int offset, int res) {
  while (r<size_A) {
    if (dif==0) {
      for (int i = r; i<size_A;i++) {
        if (A[i]!=B[i+offset]) res++;
      }
      break;
    }
    else {
      for (int i = r; i<=r+dif;i++) {
        if (A[r]==B[i+offset]) {
            res = solveA(r+1,dif-i+r,offset+i-r,res+i-r);
            if (goInA(r,dif,offset,i))
              res = min(res,solveA(r+1,dif,offset,res+1));
            return res;
        }
      }
      res++; r++;
    }
  }
  return res+dif;
}

int solveB(int r, int dif, int offset, int res) {
  calls++;
  while (r<size_B) {
    if (dif==0) {
      for (int i = r; i<size_B;i++) {
        if (B[i]!=A[i+offset]) res++;
      }
      break;
    }
    else {
      for (int i = r; i<=r+dif;i++) {
        if (B[r]==A[i+offset]) {
            res = solveB(r+1,dif-i+r,offset+i-r,res+i-r);
            if (goInB(r,dif,offset,i))
              res = min(res,solveB(r+1,dif,offset,res+1));
            return res;
        }
      }
      res++; r++;
    }
  }
  return res+dif;
}


void getLen(char str[], int &size)
{
  for (int i = 0; i<mxn;i++) {
    if (str[i]=='\0') {
      size = i;
      cout << str[i] << endl;
      return;
    }
  }
}

int main() {

  cin >> A;
  cin >> B;

  size_A = (int) A.length();
  size_B = (int) B.length();

  cout << size_A << " " <<size_B << endl;

  if (size_A<size_B) {
    cout << solveA(0,size_B-size_A,0,0) << endl;
  }
  else if (size_B<size_A) {
    cout << solveB(0,size_A-size_B,0,0) << endl;
  }
  else {
    int res = 0;
    int sum = 0;
    for (int i = 0; i<size_A;i++) {
      if (A[i]!=B[i]) res++;
      else sum++;
    }
    //cout << "igual" << endl;
    //cout << A[size_A-1] << " " << B[size_A-1] <<endl;
    cout << res << endl;
    //cout << calls << endl;
  }
}
