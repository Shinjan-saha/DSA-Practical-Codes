#include <stdio.h>

int main(void) {
    int a[100], n, i, min, max, indMin, indMax;
    
    printf("\n How many elements in the array?");
    scanf("%d", &n);
    
    printf("\n Enter %d integer values", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n Output: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Find minimum and its index
    min = a[0];
    indMin = 0;
    for (i = 1; i < n; i++) {  
        if (a[i] < min) {
            min = a[i];
            indMin = i;
        }
    }

    // Find maximum and its index
    max = a[0];
    indMax = 0;
    for (i = 1; i < n; i++) {  
        if (a[i] > max) {
            max = a[i];
            indMax = i;
        }
    }

    printf("\n Min of array = %d and corresponding index is %d", min, indMin);
    printf("\n Max of array = %d and corresponding index is %d", max, indMax);

    // Delete the minimum element
    for (i = indMin; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;

    printf("\n Array after deleting the minimum element: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Delete the maximum element
    for (i = indMax; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;

    printf("\n Array after deleting the maximum element: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
