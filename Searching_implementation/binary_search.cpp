#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {-3, -6, 0, 11, 6, 9, 20, 65};
    int target = -6;
    // int target = -7;
    // int target = -65;
    int n = nums.size();

    int mid = 0;
    int left = 0;
    int flag = 0;
    int right = n - 1;

    for (int i = 0; i < n; i++)
    {
        mid = (left + right) / 2;

        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid;
        }
        else if (nums[mid] == target)
        {
            // cout << "ELEMENT FOUND AT" << mid<< endl;
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        cout << "Found at index " << mid << endl;
    }
    else
    {
        cout << "Not found" <<  endl;

    }
}
