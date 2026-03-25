#include<iostream>
using namespace std;
//大写
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
            for(int j=1;j<tp;j++)
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
