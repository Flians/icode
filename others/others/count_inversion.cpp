/*
http://theory.ict.ac.cn/grad_oj/problem/6
Problem Description
Recall the problem of finding the number of inversions. As in the course, we are given a sequence of nn numbers a1,a2,⋯,ana1,a2,⋯,an, and we define an inversion to be a pair i<ji<j such that ai>ajai>aj.
We motivated the problem of counting inversions as a good measure of how different two orderings are. However, one might feel that this measure is too sensitive. Let's call a pair a significant inversion if i<ji<j and ai>3ajai>3aj. Give an O(nlogn)O(nlog⁡n) algorithm to count the number of significant inversions between two orderings.
The array contains N elements (1<=N<=100,000). All elements are in the range from 1 to 1,000,000,000.

Input
The first line contains one integer N, indicating the size of the array. The second line contains N elements in the array.
50% test cases guarantee that N < 1000.

Output
Output a single integer which is the number of pairs of significant inversions.

Sample Inout
6
13 8 5 3 2 1
Sample Output
6
*/
#include <stdio.h>
#include <iostream>
#include <stack>

int num_inversion(int *a, int left, int right)
{
    int num = 0;
    std::stack<int> border;
    border.push(left);
    border.push(right);
    while(!border.empty())
    {
        right = border.top();
        border.pop();
        left = border.top();
        border.pop();
        int r=right, l = left;
        int key_value = a[l];
        while(r>l)
        {
            while(l < r && a[r] >= key_value)
                r--;
            if(l<r)
            {
                if(key_value > 3*a[r])
                    num++;
                a[l] = a[r];
            }
            while(l < r && a[l] < key_value)
                l++;
            if(l<r)
            {
                if(3*key_value < a[l])
                    num++;
                a[r]= a[l];
            }
        }
        a[l] = key_value;
        if(left < l-1)
        {
            border.push(left);
            border.push(l-1);
        }
        if(l+1 < right)
        {
            border.push(l+1);
            border.push(right);
        }
    }
    return num;
}

int num_inversion_byinsert(int *a, int n)
{
    int num = 0,i=0,j=0,temp=0;
    for(;i<n;i++)
    {
        temp = a[i];
        for(j=i-1; j>=0; j--){
            if(a[j] > temp)
            {
                if(a[j] > 3*temp)
                    num++;
                a[j+1]=a[j];
            }
        }
        a[j+1] = temp;
    }
    return num;
}
/*
int main()
{
    int n,i=0;
    scanf("%d", &n);
    int a[n];
    for(; i<n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", num_inversion_byinsert(a, n));
    //printf("%d\n", num_inversion(a,0,n-1));
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    return 0;
}
*/
