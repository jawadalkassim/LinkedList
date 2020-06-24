
// C++ implementation to find the length of
// longest increasing contiguous subarray
#include <bits/stdc++.h>
#include<iostream>
#include<time.h>
using namespace std;

// function to find the length of longest increasing
// contiguous subarray
void printLogestIncSubArr(int arr[], int SizeOfArray)
{
    // 'max' to store the length of longest
    // increasing subarray
    // 'len' to store the lengths of longest
    // increasing subarray at diiferent
    // instants of time
    int max = 1, len = 1, maxIndex = 0;

    // traverse the array from the 2nd element
    for (int i=1; i<SizeOfArray; i++)
    {
        // if current element if greater than previous
        // element, then this element helps in building
        // up the previous increasing subarray encountered
        // so far
        if (arr[i] > arr[i-1])
            len++;
        else
        {
            // check if 'max' length is less than the length
            // of the current increasing subarray. If true,
            // then update 'max'
            if (max < len)
            {
                max = len;

                // index assign the starting index of
                // longest increasing contiguous subarray.
                maxIndex = i - max;
            }

            // reset 'len' to 1 as from this element
            // again the length of the new increasing
            // subarray is being calculated
            len = 1;
        }
    }

    // comparing the length of the last
    // increasing subarray with 'max'
    if (max < len)
    {
        max = len;
        maxIndex = SizeOfArray - max;
    }

    // Print the elements of longest increasing
    // contiguous subarray.
    for (int i=maxIndex; i<max+maxIndex; i++)
        cout << arr[i] << " ";
}

// Driver program to test above
int main()
{
    srand(time(NULL));
   int SizeOfArray;
    cout<<"input size of array"<<endl; // output yo make user decide the size of array
    cin>>SizeOfArray;
    int arr[SizeOfArray];
    for (int i = 0; i < SizeOfArray - 1 ; i++) //Generate Random Number With Size of Array that given by user
    {
        arr[i] = rand() % 10;
        cout<<arr[i]<<endl;
    }
    printLogestIncSubArr(arr, SizeOfArray);
    delete[]arr;
    return 0;
}

