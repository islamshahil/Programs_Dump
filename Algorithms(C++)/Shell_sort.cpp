Software Testing Help logo 1

Shell Sort In C++ With Examples
Shell Sort
Shell Sort Technique In C++: A Complete Overview.

Shell sort is often termed as an improvement over insertion sort. In insertion sort, we take increments by 1 to compare elements and put them in their proper position.

In shell sort, the list is sorted by breaking it down into a number of smaller sublists. It’s not necessary that the lists need to be with contiguous elements. Instead, shell sort technique uses increment i, which is also called “gap” and uses it to create a list of elements that are “i” elements apart.

=> See Here To Explore The Full C++ Tutorials list.





#include  <iostream> 
using namespace std; 
  
// shellsort implementation
int shellSort(int arr[], int N) 
{ 
    for (int gap = N/2; gap > 0; gap /= 2) 
       { 
    for (int i = gap; i < N; i += 1) 
       { 
            //sort sub lists created by applying gap 
int temp = arr[i]; 

int j; 
for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
arr[j] = arr[j - gap]; 
              
arr[j] = temp; 
        } 
    } 
    return 0; 
} 
  
int main() 
{ 
    int arr[] = {45,23,53,43,18,24,8,95,101}, i; 
    //Calculate size of array 
    int N = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Array to be sorted: \n"; 
    for (int i=0; i<N; i++) 
        cout << arr[i] << " "; 
  
    shellSort(arr, N); 
  
    cout << "\nArray after shell sort: \n"; 
    for (int i=0; i<N; i++) 
        cout << arr[i] << " "; 
  
    return 0; 
}
