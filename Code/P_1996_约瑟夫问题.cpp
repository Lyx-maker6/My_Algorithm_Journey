#include<iostream>
#include<list>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    list<int> l;
    for(int i=1;i<=n;i++) l.push_back(i);
    list<int>::iterator it=l.begin();
    while(!l.empty())
    {
        for(int i=1;i<m;i++)
        {
            it++;
            if(it==l.end())
                it=l.begin();
        }
            cout<<*it<<" ";
            list<int>:: iterator next;
            next=++it;
            l.erase(--it);
            if(next==l.end()) next=l.begin();
            it=next;
       
        
    }
    
    return 0;
}