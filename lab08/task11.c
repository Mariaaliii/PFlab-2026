#include <stdio.h>
int square(int x)     { return x * x; }
int negate(int x)     { return -x; }
int isEven(int x)     { return x % 2 == 0; }
int isPositive(int x) { return x > 0; }
void applyToArray(int *arr, int n, int (*fn)(int)) {
    int i;
	for (i = 0; i < n; i++)
        *(arr + i) = fn(*(arr + i));
}
int countIf(const int *arr, int n, int (*pred)(int)) {
    int count = 0;
    int i;
	for (i = 0; i < n; i++) {
        if (pred(*(arr + i)))
            count++;
    }
    return count;
}
void printGeneric(void *data, char type, int n) {
    int i;
	switch (type) {
    case 'i': {
        int *p = (int *)data;
        for (i = 0; i < n; i++)
            printf("%d ", *(p + i));
        printf("\n");
        break;
    }
    case 'f': {
        float *p = (float *)data;
        for (i = 0; i < n; i++)
            printf("%.2f ", *(p + i));
        printf("\n");
        break;
    }
    case 'c': {
        char *p = (char *)data;
        for (i = 0; i < n; i++)
            printf("%c ", *(p + i));
        printf("\n");
        break;
    }
    default:
        printf("Invalid type '%c' for printGeneric\n", type);
    }
}
int main() {
    int arr[50] = {3, -2, 8, -5, 6};
    int n;
    while (1) {
        printf("Enter n (1-50): ");
        scanf("%d", &n);
        if (n < 1 || n > 50)
            printf("Invalid n\n");
        else
            break;
    }
    printf("Original: ");
    printGeneric(arr, 'i', n);
    applyToArray(arr, n, negate);
    printf("After negate: ");
    printGeneric(arr, 'i', n);
    printf("Positive values after negate: %d\n", countIf(arr, n, isPositive));
    printf("Even values after negate: %d\n", countIf(arr, n, isEven));
    float f[] = {1.5f, 2.25f};
    printf("Float print (type f): ");
    printGeneric(f, 'f', 2);
    printGeneric(arr, 'x', n);
    return 0;
}
