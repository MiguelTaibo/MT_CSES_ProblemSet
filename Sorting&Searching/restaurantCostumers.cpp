#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int rd = rand() % (high-low) + low;
    swap(&arr[rd],&arr[high]);

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

// Pivot is random
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

bool checkSort(int arr[], int len) {
  for (int i = 1; i<len;i++) {
    if (arr[i-1]>arr[i])
      return true;
  }
  return false;

}


int main()  {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char input[10];
  int n;

  std::cin >> input;
  sscanf(input, "%d", &n);

  int a[n];
  int l[n];
  for (int i = 0; i<n; i++) {
      std::cin >> input;
      sscanf(input,"%d",&a[i]);
      std::cin >> input;
      sscanf(input,"%d",&l[i]);
  }

  //printArray(a,n );
  //printArray(l,n );
  if (checkSort(a,n))
    quickSort(a,0,n-1);
  if (checkSort(l,n))
    quickSort(l,0,n-1);

  int respuesta = 0; //solution (max of current)
  int current = 0;  // current people at a time
  int i = 0; // a Index
  int j = 0; // l Index


  //printArray(a,n );
  //printArray(l,n );

  while (i<n) {
    //std::cout << i<< " " << j << " " << a[i] << " " << l[j] << endl;
    if (a[i]<l[j]) {
      i++;
      current++;
      if (current>respuesta)
        respuesta = current;
    }
    else if (a[i]==l[j]) {
      j++;
      i++;
    }
    else if (a[i]>l[j]) {
      j++;
      current--;
    }
  }

  std::cout << respuesta <<endl;

}
