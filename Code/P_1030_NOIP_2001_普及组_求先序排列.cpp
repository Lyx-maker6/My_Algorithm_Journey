#include<iostream>
#include<string>
using namespace std;

void solve(string in ,string last)
{
    if (in.empty()) return;
    
    char root = last[last.length() - 1];
    cout<<root;

    //分左右
    //在中序遍历的字符串中，找到root进行划分，分成左孩子和右孩子
    int pos = in.find(root);
    string left_in = in.substr(0,pos);
    string left_last = last.substr(0,pos);

    string right_in = in.substr(pos + 1);
    // 右子树的后序：last 从 pos 开始（跳过左边），长度是总长 - 左边长 - 1(根)
    string right_last = last.substr(pos,last.length() - pos - 1);

    solve(left_in,left_last);//依旧一个中序一个后序
    solve(right_in,right_last);
}

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    solve(s1,s2);
    return 0;
}