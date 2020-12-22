#include <iostream>
#include <vector>

using namespace std;

/**
 * 输出在数组中等于查找值的位置，不存在则输出-1
 * @param nums int整型vector 有序数组
 * @param target int整型 查找值
 * @return int整型
 */
int find(vector<int>&& nums, int target) {
    int n = nums.size();
    int l = 0, r =  n - 1;
    while (l <= r)
    {
        int mid = (r + l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else if (nums[mid] == target) {
            return mid;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

/**
 * 输出在数组中等于查找值的最左边位置，不存在则输出-1
 * @param nums int整型vector 有序数组
 * @param target int整型 查找值
 * @return int整型
 */
int left_bound(vector<int>&& nums, int target) {
    int n = nums.size();
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (r + l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else if (nums[mid] == target) {
            r = mid;
        } else {
            r = mid;
        }
    }
    return l == n || nums[l] != target ? -1 : l;
}

/**
 * 输出在数组中等于查找值的最右边位置，不存在则输出-1
 * @param nums int整型vector 有序数组
 * @param target int整型 查找值
 * @return int整型
 */
int right_bound(vector<int>&& nums, int target) {
    int n = nums.size();
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (r + l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else if (nums[mid] == target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l == 0 || nums[l-1] != target ? -1 : l-1;
}

/**
 * 输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一
 * @param a int整型vector 有序数组
 * @param v int整型 查找值
 * @return int整型
 */
int upper_bound_(vector<int>&& a, int v) {
    int n = a.size();
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < v) {
            l = mid + 1;
        } else if (a[mid] == v) {
            r = mid;
        } else {
            r = mid;
        }
    }
    return l == n || a[l] != v ? n + 1: l+1;
}

int main() {
    cout << find({1,2,4,4,4,4,5}, 4) << " 3" << endl;
    cout << left_bound({1,2,4,4,4,4,5}, 4) << " 2" << endl;
    cout << right_bound({1,2,4,4,4,4,5}, 4) << " 5" << endl;
    cout << upper_bound_({1,2,4,4,4,4,5}, 4) << " 3" << endl;
    return 0;
}