#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    int max = nums[0];
    for (int i = 1; i < k; i++)
    {
        if (max < nums[i])
            max = nums[i];
    }
    for (int i = k; i < n; i++)
    {
        if (max < nums[i]) {
            cout << nums[i];
            break;
        }
        else {
            cout << nums[n - 1];
            break;
        }
    }

    return 0;
}