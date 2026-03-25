// 给定一个只包含大写字母和小写字母的字符串，请将其中所有的小写字母转换成大写字母后将字符串输出。
// 输入格式
// 输入一行包含一个字符串。
// 输出格式
// 输出转换成大写后的字符串。

#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    for(auto &c:s)
    {
        if(c>='a'&&c<='z')
        {
            c=c-32; // Convert lowercase to uppercase
        }
    }
    cout<<s<<endl;
    return 0;
}