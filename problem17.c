#include <stdio.h>
#include <stdlib.h>

int ten(int i, int *special1) {
    if (i<60) {
        if ( (i/10) == 2 || (i/10) == 3)
            return 6 + special1[i%10];
    else
            return 5 + special1[i%10];
    }
    else if (i/10 == 8)
        return 6 + special1[i%10];
    else
       return special1[i/10] + 2 + special1[i%10];
}


int p(int i, int* special1) {
    if (i%100 == 0) {
        return 0;
    }
    else if((i % 100) <= 19) {
        return 3 + (special1[i%100]);
    }
    else {
        return 3 + ten(i%100, special1);
    }
}

int main()
{
    //0, 1,2,3,4,5,6,7,8,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
    int special1[20] = {0,3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
    int i, j, sum=0;
    for (i = 1; i <= 19; i++) {
        sum = sum + special1[i];
    }
    for (j = i; j < 100; j++) {
       sum = sum + ten(j, special1);
    }
    // hundred and = 7+3
    for (i = 100; i < 1000; i++) {
        sum = sum + special1[i/100] + 7 + p(i, special1);
    }
    // 1000 (one thousand)
    sum = sum + 11;
    printf("It's %d letters from 1 to 1000", sum);

}
