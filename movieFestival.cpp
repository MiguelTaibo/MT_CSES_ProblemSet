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

bool checkSort(int arr[], int len) {
  for (int i = 1; i<len;i++) {
    if (arr[i-1]>arr[i])
      return true;
  }
  return false;

}

void nextStep(int a[], int l[], int i, int n, int prevTime,int count, int &respuesta)
{
  if(count>respuesta)
    respuesta=count;
  if (i==n)
    return;

  if (a[i]<prevTime) {
    nextStep(a,l,i+1,n,prevTime,count,respuesta);
  } else if (i==n-1 || l[i]<a[i+1]) {
    nextStep(a,l,i+1,n,l[i],count+1,respuesta);
  } else {
    nextStep(a,l,i+1,n,l[i],count+1,respuesta);
    nextStep(a,l,i+1,n,prevTime,count,respuesta);
  }


}

int main()
{

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

  if (checkSort(a,n))
    duoSort(a,l,0,n-1);

  //printArray(a,n );
  //printArray(l,n );
  #define split 10000
  if (n>split) {
    int slice = 0;
    int indexes[split];
    for (int i = 0; i<n-1;i++) {
      if(l[i]<=a[i+1]) {
        indexes[slice++]=i;
      }
    }
    int respuesta = 0;
    int i;
    for (i = 0; i<slice;i++) {
      nextStep(a,l,0, indexes[i],0,respuesta,respuesta);
    }
    nextStep(a,l,indexes[i],n ,0,respuesta,respuesta);
  } else {
    int respuesta = 0;
    nextStep(a,l,0,n,0,0,respuesta);

    std::cout<<respuesta<<std::endl;
  }
  }
