#include <stdio.h>

int *bbsearch(int *t, int n, int x)
{
    int *low = t;
    int *high = t + n;//注意此处取了越界后的第一个地址，这是合法的，但不允许求其值。

    while (low < high)//因为high取了越界后的第一个地址，所以应该保证low != high
    {
        int *mid = low + ((high - low) >> 1);//此处的括号绝对不能省略。

        if (x < *mid)
        {
            high = mid; //注意因为high取了越界后的第一个地址,所以更新high时也应该保持越界。
        }
        else if(x > *mid)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return NULL;
}

int *bbbsearch(int *t, int n, int x)
{
    int low = 0, high = n-1;//high 没有越界

    while (low <= high)//因为high没有越界，所以会出现low与high相等的情况，表示指向最后一个元素。
    {
        int mid = (low + high) / 2;//也可为(low+high)>>1,其实编译器会自动转换为位运算。

        if (x < t[mid])
        {
            high = mid -1;//因为high 没有越界，所以更新high时，也不能越界，即不能取high = mid;
        }
        else if(x > t[mid])
        {
            low = mid + 1;
        }
        else
        {
            return &t[mid];//也可为t+mid
        }
    }
    return NULL;
}

int main(void)
{
    int s[10]= {0,1,2,3,4,5,6};

    printf("%d\n", *bbbsearch(s,7,2));
}
