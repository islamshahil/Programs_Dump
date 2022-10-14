//Given an integer numRows, return the first numRows of Pascal's triangle.


#include <bits/stdc++.h>
using namespace std;
//Approach 1
//Using Dp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> ans(numRows);
        
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1);
            ans[i][0]=ans[i][i]=1;
        for(int j=1;j<i;j++){
            ans[i][j] = ans[i-1][j]+ans[i-1][j-1];
        }
        }
        
        return ans;
    }
};

//Approach 2
//Using NcR

class Solution {
public:
    long long ncr(int n, int r)
    {
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

    vector<vector<int>> generate(int rows) {
        vector<vector<int>>ans(rows + 1);
        ans[0].push_back(1);
        for(int i = 1; i < rows; i++){
            for(int j = 0; j <= i; j++){
                ans[i].push_back(ncr(i,j));
            }
        }
        ans.pop_back();
        return ans;
    }
};