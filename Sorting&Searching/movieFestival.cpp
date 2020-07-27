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

void duoSort(int arr[], int aux[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int rd = rand() % (high-low) + low;
        swap(&arr[rd],&arr[high]);
        swap(&aux[rd],&aux[high]);

        int pivot = arr[high]; // pivot
        int i = (low - 1); // Index of smaller element

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
                swap(&aux[i],&aux[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        swap(&aux[i+1],&aux[high]);

        duoSort(arr,aux, low, i);
        duoSort(arr,aux, i + 2, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

bool checkSort(int arr[], int len)
{
  for (int i = 1; i<len;i++) {
    if (arr[i-1]>arr[i])
      return true;
  }
  return false;

}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;


  int a[n];
  int l[n];
  for (int i = 0; i<n; i++) {
      cin >> a[i] >> l[i];
  }

  if (checkSort(l,n))
    duoSort(l,a,0,n-1);

  int ans=0,last=0;
  for (int i=0;i<n;++i) {
    if (a[i]>=last) {
      ++ans;
      last=l[i];
    }
  }
  cout << ans;

}
