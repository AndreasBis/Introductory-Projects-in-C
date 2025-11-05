#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(NULL));
    
    int min = 1;
    int max = 6;

    int num = (rand() % (max - min + 1)) + min;
    printf("%d\n", num);

    return 0;
}