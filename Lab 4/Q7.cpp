#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

void BubbleSort(int arr[],int n)
{
    int Comparisons = 0;
    int Swaps =0;
    for(int r =0; r < n; r++)
    {
        for(int i =0; i < n-1;i++)
        {
            Comparisons++;
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                Swaps++;
            }
        }
    }
    cout << " BubbleSort Swaps are : " << Swaps 
         << " Comparisons are : " << Comparisons << endl;
}

void InsertionSort(int arr[],int n)
{
    int Comparisons = 0;   
    int Swaps = 0;
    for(int y =1; y< n; y++)
    {
        int j = y;
        int val = arr[y];
        
        while (j > 0)
        {
           Comparisons++; 
           if (val < arr[j - 1]) 
           {
               arr[j] = arr[j - 1];
               Swaps++;
               j--;
           }
           else 
           {
              break;
           }
        }
        arr[j] = val;
    }
    
    cout << " Insertion Sort  Swaps are : " << Swaps 
         << " Comparisons are : " << Comparisons << endl;
}

void shellSort(int arr[], int n)
{
    int Comparisons = 0;
    int Swaps = 0;
    for (int Gap = n / 2; Gap > 0; Gap /= 2)
    {
        for (int j = Gap; j < n; j++) 
        {
            int Temp = arr[j];
            int e = j;
            while (e >= Gap) 
            {
                Comparisons++;
                if (arr[e - Gap] > Temp)
                {
                    arr[e] = arr[e - Gap];
                    Swaps++;
                    e = e - Gap;
                } 
                else
                {
                    break;
                }
            }
            arr[e] = Temp;
        }
    }
    
    cout << " Shell Sort  Swaps are : " << Swaps 
         << " Comparisons are : " << Comparisons << endl;
}

int main() 
{
    int n = 3000;
    int arr[n];
    
    srand(time(0));
    for (int j = 0; j < n; j++)
    {
      arr[j] = rand() % 10000; 
    }
    
    
    int arr1[n];
    int arr2[n];
    int arr3[n];
    
    for(int i=0; i<n; i++)
    {
       arr1[i] = arr[i];
       arr2[i] = arr[i];
       arr3[i] = arr[i];
    }

    auto start = high_resolution_clock::now();
    
    BubbleSort(arr1, n);
    
    auto stop = high_resolution_clock::now();
    
    cout << " Bubble Sort Time taken: " 
     << duration_cast<microseconds>(stop - start).count() 
     << " µs" << endl << endl;

    start = high_resolution_clock::now();
    
    InsertionSort(arr2, n);
    
    stop = high_resolution_clock::now();
    
    cout << " InsertionSort Time taken: " 
     << duration_cast<microseconds>(stop - start).count() 
     << " µs" << endl << endl;


    start = high_resolution_clock::now();
    
    shellSort(arr3, n);
    
    stop = high_resolution_clock::now();
    
    cout << " Shell Sort Time taken: " 
     << duration_cast<microseconds>(stop - start).count() 
     << " µs" << endl << endl;

    return 0;
}
