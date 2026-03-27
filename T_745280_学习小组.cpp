#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    
    int num;
    for(int i = 0;i < 2*n;i++)
    {
        cin>>num;
        nums.push_back(num);
    }
    for(int i = 0;i < 2*n;i++)
    {
        int target = nums[i];
        for(int j = 0;j < 2*n;j++)
        {
            if(target == nums[j] && i!=j)
            {
                cout<<j+1<<" ";
                break;
            }
        }
    }
    return 0;
}