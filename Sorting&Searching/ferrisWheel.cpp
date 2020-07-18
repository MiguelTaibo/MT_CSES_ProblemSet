#include <iostream>

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

void simplifice(int x, int n, int arr[], int &respuesta) {

    int i = 0;
    int j = n-1;
    while(i<=j) {
        if (arr[j]+arr[i]>x) {
            respuesta++;
            j--;
        } else {
            respuesta++;
            j--;
            i++;
        }
    }


}

int main() {
    char input[100];
    int n, x;

    std::cin >> input;
    sscanf(input, "%d", &n);
    std::cin >> input;
    sscanf(input, "%d", &x);

    int arr[n];
    for (int i = 0; i<n; i++) {
        std::cin >> input;
        sscanf(input,"%d",&arr[i]);
    }

    int len = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, len - 1);
    //printArray(arr,n);

    int respuesta = 0;

    simplifice( x, n,arr, respuesta);

    std::cout <<respuesta;

    return 0;
}
