#include <stdio.h>
//linear search

void main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int numSearch;

    printf("Enter a number between 1 - 11\n");
    scanf("%d", &numSearch);

    int i;
    
    for (i = 0; i < 11; ++i){
        if (arr[i] == numSearch)
            break;
    }

    printf("\n%d found at position %d", numSearch, i);
}
