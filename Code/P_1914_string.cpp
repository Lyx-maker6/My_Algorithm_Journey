#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string res;
    for(int i = 0;i < s.length();i++)
        res = ( s[i] - 'a' + n ) % 26 + 'a';
    cout<<res;
    
    return 0;
}