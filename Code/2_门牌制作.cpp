#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int cnt=0;
  for(int i=1;i<=2020;i++)
  {
    for(auto s:to_string(i))
    {
        if(s=='2') cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}