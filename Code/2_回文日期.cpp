#include <iostream>
#include <string>
using namespace std;

int p[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int r[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };


int check(int i)
{
    int mon = (i / 100) % 100;
    int year = i / 10000;
    int day = i % 100;
    //不正常月份
    if (mon > 12 || mon < 1)
        return 0;

    //不正常日期>31,>30,>29,>28，这个需要先判断闰年还是平年
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        if (day > r[mon - 1] || day < 1)  return 0;
    }
    else {
        if (day > p[mon - 1] || day < 1)  return 0;
    }
    return 1;
}

bool isH(int y)
{
  string s = to_string(y);
  if(s[0]==s[7]&&s[1]==s[6]&&s[2]==s[5]&&s[3]==s[4])
    return 1;
  return 0;   
}

bool isAB(int y){
  string s = to_string(y);
  if((s[0]==s[2]&&s[2]==s[5]&&s[5]==s[7])&&
      s[1]==s[3]&&s[3]==s[4]&&s[4]==s[6])
      return 1;
  return 0;
}

int main()
{
  // 请在此输入您的代码
  int y;
  cin>>y;
  int m,n;

  for(int i = y+1; ;i++)
  {
    if(isH(i)&&check(i))
     {
      cout<<i<<endl;
      break;
     }
  }
  for(int i = y+1; ;i++)
  {
     if(isAB(i)&&check(i))
     {
       cout<<i;
       break;
     }
  }
  return 0;
}