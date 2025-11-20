#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums = {3,4,5,55,62,11,0,-1,-4};
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[i])
            {
                swap(nums[i], nums[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}