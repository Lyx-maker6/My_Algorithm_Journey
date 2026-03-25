#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i = 0;i < s.length();i++)
    {
        int tp = 0;
        
        if(s[i] >= '1' && s[i] <= '9')
        {
            tp = s[i] - '0'; // Convert character to integer
            cout<<s[i-1];
            for(int j=2;j<tp;j++)
            {
                cout<<s[i-1];
            }
        }
        else{
            cout<<s[i];
        }
        
        
    }
    return 0;    
}
