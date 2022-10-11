// Binary search in a 2d matrix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row=matrix.size();
    int col=matrix[0].size();
    
    int s=0;
    int e=row*col -1;

    int mid=s+(e-s)/2;

    while(s<=e)
    {
        int el=matrix[mid/col][mid%col];
        if(target==el)
        {
            return true;
        }
        else if(target>el)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return false;
    }
};