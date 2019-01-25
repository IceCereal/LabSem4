//Simplify Fractions
//18/Jan/19

#include <stdio.h>

int GCF(int num_1, int num_2){
    int minimum = num_1 < num_2 ? num_1 : num_2;

    int i;

    for (i = minimum; i >= 1; --i)
        if ((num_1 % i == 0) && (num_2 % i == 0))
            break;

    return i;
}

int main(){
    printf("Program 3: To simplify a fraction");
    printf("\nEnter 2 numbers in a/b:\n");

    int num_1, num_2;

    scanf("%d %d", &num_1, &num_2);

    int gcf = GCF(num_1, num_2);

    printf("\n\nThe simplified format is:\t%d/%d\n", num_1/gcf, num_2/gcf);

    return 0;
}