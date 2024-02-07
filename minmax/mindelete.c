#include <stdio.h>
#include <conio.h>

void main(void) {
    int a[100], n, i, min, ind;
    printf("\n How many elements in the array?");
    scanf("%d", &n);
    printf("\n Enter %d integer values", n);
    
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n Output: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    min = a[0];
    ind = 0;
    for (i = 1; i < n; i++) {  
        if (a[i] <= min) {
            min = a[i];
            ind = i;
        }
    }

    printf("\n Min of array = %d and corresponding index is %d", min, ind);

    
    for (i = ind; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--; 

    printf("\n Array after deleting the minimum element: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);


}