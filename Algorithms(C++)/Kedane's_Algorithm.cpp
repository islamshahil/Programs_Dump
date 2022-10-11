//Given an array arr[] of size N. The task is to find the sum of the 
// contiguous subarray 
// within a arr[] with the largest sum. 


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {

        int l_max = -1000000;
        int g_max = -1000000;
        for (int i = 0; i < n; i++)
        {
            l_max = max(arr[i], l_max + arr[i]);
            if (l_max >= g_max)
            {
                g_max = l_max;
            }
        }
        return g_max;
    }
};