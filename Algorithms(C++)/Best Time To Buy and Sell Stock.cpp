// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        int minPrice=INT_MAX;
        int profit=INT_MIN;
        for(int i=0;i<n;i++){
            minPrice=min(minPrice, prices[i]);
            profit=max(profit, prices[i]-minPrice);
        }
        return profit;
    }
};