/*
http://theory.ict.ac.cn/grad_oj/contest/4/problem/31
Problem description:
Some people want to cross a river by boat. Each person has a weight, and each boat can carry a maximum weight of limit. Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit. Return the minimum number of boats to carry every given person. Note that it is guaranteed each person can be carried by a boat.

Input:
The input will be 3 lines. The first line is a single integer n (1 <= n <= 50000), which means the number of people. The second line is a single integer l (1 <= l <= 30000), represents the weight limit. And the last line contains n integers p_1, p_2, …, p_n (1 <= p_i <= l), separated by spaces, that represent people’s weights.

Output:
The output will consist of one line containing one integer, which represents the minimum number of boats.

Sample Input:
4
3
3 2 2 1
Sample Output:
3
*/
#include <iostream>

void quick_sort(int* pw, int left, int right){
    if(left >= right)
        return;
    int pivot = pw[left];
    int i=left, j=right;
    while(i<j)
    {
        while(i<j && pw[j]<pivot)
            j--;
        if(i<j)
            pw[i++] = pw[j];
        while(i<j && pw[i]>pivot)
            i++;
        if(i < j)
            pw[j--] = pw[i];
    }
    pw[i] = pivot;
    quick_sort(pw, left, i-1);
    quick_sort(pw, i+1, right);
}

int cross_river(int* pw, int np, int wl)
{
    int min = 0, i = 0, j = np-1;
    while(i<=j)
    {
        if(i==j)
        {
            i++;
        } else if(pw[i]==wl)
        {
            i++;
        } else if(pw[i] + pw[j] <= wl)
        {
            i++;j--;
        } else{
            i++;
        }
        min++;
    }
    return min;
}

int main(){
    int np,wl,i=0;
    std::cin >> np >> wl;
    int pw[np];
    for(; i<np; i++)
        std::cin >> pw[i];
    quick_sort(pw,0,np-1);
    std::cout << cross_river(pw, np, wl) << std::endl;
    return 0;
}