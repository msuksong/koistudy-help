#include <stdio.h>

int check_value(int val) {
    if (val == 0 || val == 1) {
        return 0;
    }
    else {
        printf("%d: value must be 0 or 1.\n", val);
        return 1;
    }
}

int toggle(int array[], int pos) {
    if (pos < 0 || pos > 19) {
        printf("out of range: %d\n", pos);
        return -1;
    }
    array[pos] = 1 - array[pos];
    if (pos == 0)
    {
        array[pos + 1] = 1 - array[pos + 1];
    }
    else if (pos > 0 && pos < 19)
    {
        array[pos - 1] = 1 - array[pos - 1];
        array[pos + 1] = 1 - array[pos + 1];
    }
    else if (pos == 19)
    {
        array[pos - 1] = 1 - array[pos - 1];
    }
    return 0;
}

void printall(int a[], int cur, int num) {
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", a[i]);

    }
    printf("- %d - %d\n", cur, num);
}

int main() {
    int i = 0, num = 0;
    int a[20];

    for (i=0; i < 20; i++) {
        scanf("%d", &a[i]);
        if (check_value(a[i]) != 0)
            return 1;
    }

    /* 시작이 1 1 0 또는 1 1 1인 경우 예외 처리.
    * 토글해가다가 마지막이 0 1 1이거나 1 1 1인 경우 예외 처리.
    * 그 외에는 i - 1이 1인 경우 i위치에서 토글.
    */
    if (a[0] == 1 && a[1] == 1)
    {
        if (a[2] == 1)
        {
            toggle(a, 1);
        }
        else
        {
            toggle(a, 0);
        }
        num++;
        printall(a, i, num);
    }
    for (i=1; i < 18; i++) {
        if (a[i-1] == 1) {
            toggle(a, i);
            num++;
        }
        printall(a, i, num);
    }
    if (a[18] == 1 && a[19] == 1) {
        if (a[17] == 1) {
            toggle(a, 18);
        } else {
            toggle(a, 19);
        }
        num++;
        printall(a, i, num);
    }
    if (a[19] == 1) {
        printf("unsolvable!!\n");
    }
    return 0;
}