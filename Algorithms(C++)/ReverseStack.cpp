#include<bits/stdc++.h>
using namespace std;

void Insert(stack<int>&s,int ele)
{
    if(s.size()==0)
    {
        s.push(ele);
        return;
    }
    int temp=s.top();
    s.pop();
    Insert(s,ele);
    s.push(temp);
    return ;

}
void reverse(stack<int>&st)
{
    if(st.size()==1)
    {
        return;
    }
    int temp=st.top();
    st.pop();
    reverse(st);
    Insert(st,temp);
}

int main()
{
    int t;
    cin>>t;
    stack<int>st;
    for(int i=0;i<t;i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }
    reverse(st);
    while(!st.empty())
    {
       cout<< st.top()<<" ";
       st.pop();
    }
    return 0;
}
