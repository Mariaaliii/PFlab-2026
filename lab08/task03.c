#include <stdio.h>
int isValidMark(int m) {
    if (m >= 0 && m <= 100) return 1;
    else return 0;
}
void findMinMax(int arr[], int size, int *min, int *max) {
    int i;
    *min = arr[0];
    *max = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] < *min)
            *min = arr[i];
        if (arr[i] > *max)
            *max = arr[i];
    }
}
int main() {
    int arr[5];
    int i, min, max;
    for (i = 0; i < 5; i++) {
        do {
            printf("Enter mark %d: ", i + 1);
            scanf("%d", &arr[i]);
            if (!(isValidMark(arr[i])))
                printf("Invalid mark, enter again\n");
        } while (!(isValidMark(arr[i])));
    }
    findMinMax(arr, 5, &min, &max);
    printf("\nLowest mark = %d\n", min);
    printf("Highest mark = %d\n", max);
    return 0;
}
