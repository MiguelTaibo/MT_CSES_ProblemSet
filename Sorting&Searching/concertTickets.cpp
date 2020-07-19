#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void dividePivot(int arr[], int low, int high, int pivot) {
  int i = (low-1);

  for (int j = low; j<=high; j++)
  {
    if (arr[j]<pivot) {
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
}

bool checkSort(int arr[], int len) {
  for (int i = 1; i<len;i++) {
    if (arr[i-1]>arr[i])
      return true;
  }
  return false;

}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char input[10];
  int n;
  int m;

  std::cin >> input;
  sscanf(input, "%d", &n);
  std::cin >> input;
  sscanf(input, "%d", &m);

  int h[n];
  for (int i = 0; i<n; i++) {
      std::cin >> input;
      sscanf(input,"%d",&h[i]);
  }

  int t[m];
  for (int i = 0; i<m; i++) {
      std::cin >> input;
      sscanf(input,"%d",&t[i]);
  }

  if (checkSort(h,n))
    quickSort(h, 0, n - 1);

  #define divide 1000

  if (n>10*divide) {
    const int MAX = 1000000001;

    int slices = n/divide;
    int values[slices];
    for (int i = 0; i<slices;i++) {
      values[i]=h[divide*i];
    }


    int res;

    int min = h[0];
    int max = h[n-1];
    int min_idx = 0;
    int max_idx = n-1;
    //Para cada valor de t (t[i])
    for (int i = 0; i<m;i++) {
      res = -1;
      if (t[i]>max) {
        for (int j = max_idx;j>=0;j--) {
          if (h[j]<=t[i]) {
            res = h[j];
            h[j]=MAX;
            max_idx=j;
            break;
          }
        }
      }
      else if (t[i]==min) {
        for (int j=min_idx; j<n;j++) {
          if (h[j]<=t[i]) {
            res = h[j];
            h[j]=MAX;
            min_idx=j;
            break;
          }

        }


      }
      else if (t[i]>min) {
        //Buscamos la slice
        for (int s=0;s<slices;s++) {
          // Cuando lo encontramos (slice)
          if (values[s]<=t[i] && (s==slices-1 || t[i]<values[s+1])) {
            // Buscamos el valor
            for (int j = (s+1)*divide-1; j>=0;j--) {
              // Y cuando lo encontramos
              if (h[j]<=t[i]) {
                res = h[j];
                h[j]=MAX;
                //salimos
                break;
              }
            }
            //salimos
            break;
          }
        }
      }

      cout << res << endl;
    }
  }
  else {

    int res;
    int min = h[0];
    const int MAX = 1000000001;

    // ACTUALITION VALUES
    int last_value=0;
    int next_start;
    int j;

    for (int i = 0; i<m;i++) {
      res = -1;
      if (t[i]>=min) {
        if (t[i]<=last_value) {
          next_start=j;
        } else {
          next_start=n-1;
        }

        for (j =next_start;j>=0;j--) {
          if (h[j]<=t[i]) {
            res = h[j];
            last_value = res;
            h[j]=MAX;
            break;
          }
        }
      }
      cout << res << endl;

    }
  }

  /*
  int res;
  for (int i= 0; i<m; i++) {
      res = -1;
      for (int j=0; j<=n;j++) {
        if (j==n || t[i]<h[j]) {
          for (int k=j-1;k>=0;k--) {
            if (h[k]!=0) {
              res = h[k];
              h[k]=0;
              break;
            }
          }
          break;
        }
      }
      //std::cout << i << " " << res << std::endl;
      std::cout << res << std::endl;
  }
  //printArray(h,n);
  */

}
