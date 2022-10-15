// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. DO it in-place.

#include <bits/stdc++.h>
using namespace std;

// Approach 1
// Using set
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> row;
        set<int> col;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (auto it : row)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[it][j] = 0;
            }
        }
        for (auto it : col)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[j][it] = 0;
            }
        }
    }
};

// Approach 2
// Using vector

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> d1(m, -1);
        vector<int> d2(n, -1);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    d1[i] = 0;
                    d2[j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d1[i] == 0 || d2[j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
};

// Approach 3
// No extra space

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 1;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                top = 0;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
            if (top == 0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
