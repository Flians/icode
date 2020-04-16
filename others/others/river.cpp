/**
 * 二分答案/二分枚举问题
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a,int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void quick_sort(int *stone, int left, int right)
{
    if(left >= right)
        return;
    // get a key from [left,right] by random.
    int key_id = rand()%(right-left+1) + left;
    int key_value = stone[key_id];
    if(key_id != left)
        swap(stone + left, stone + key_id);
    int l = left, r = right;
    while(l < r)
    {
        while(l < r && stone[r] >= key_value)
            r--;
        if(l < r)
            stone[l++] = stone[r];
        while(l < r && stone[l] < key_value)
            l++;
        if(l < r)
            stone[r--] = stone[l];
    }
    stone[l] = key_value;
    quick_sort(stone, left, l-1);
    quick_sort(stone, l+1, right);
}

int check(int *stones, int n, int x)
{
    int num = 0, i = 1, temp = 0;
    for (; i < n; i++)
    {
        while(stones[i]-temp < x && i < n)
        {
            num++;
            i++;
        }
        temp = stones[i];
    }
    return num;
}

int min_dis(int *stones, int n, int aim)
{
    int left = stones[0], right = stones[n-1];
    while(left <= right)
    {
        int mid = (left + right) >> 1;
        // 判断搬走小于mid的石头数量是否超过aim.
        if(check(stones, n, mid) > aim)
        {
            // 说明mid过大，导致搬走的石头数量过多.
            right = mid - 1;
        }
        else
        {
            // 说明mid过小，导致搬走的石头数量不够
            left = mid + 1;
        }
    }
    return right;
}

int main()
{
    srand((unsigned)time(NULL));

    int l, n, m, i=1;
    scanf("%d %d %d", &l, &n, &m);

    int stones[n+2];
    stones[0]=0;
    for (; i < n+1; i++)
        scanf("%d", &stones[i]);
    stones[n+1]=l;

    quick_sort(stones, 1, n);

    printf("%d\n", min_dis(stones, n+2, m));

    return 0;
}