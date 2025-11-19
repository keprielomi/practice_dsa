#include <stdio.h>

/* Function prototypes */
void inputArray(int a[], int n);
void displayArray(int a[], int n);
void selectionSort(int a[], int n);
int binarySearch(int a[], int n, int x);

int main(void) {
    int a[100], n, x, pos;

    printf("Enter the number of elements you want to enter: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid size. Exiting.\n");
        return 1;
    }

    inputArray(a, n);

    printf("\nYour array (as entered): ");
    displayArray(a, n);
    printf("\n");

    /* Ensure array is sorted before binary search */
    selectionSort(a, n);
    printf("Array after sorting: ");
    displayArray(a, n);
    printf("\n");

    printf("Enter the element you want to search: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    pos = binarySearch(a, n, x);

    if (pos == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", pos); /* index is 0-based */

    return 0;
}

/* Read n integers into array a */
void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element at index %d: ", i);
        while (scanf("%d", &a[i]) != 1) {
            /* clear invalid input */
            int ch;
            while ((ch = getchar()) != EOF && ch != '\n') { }
            printf("Invalid input. Enter integer for index %d: ", i);
        }
    }
}

/* Print n elements of array a */
void displayArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(", ");
    }
}

/* Simple selection sort (ascending) */
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        if (minIdx != i) {
            int tmp = a[i];
            a[i] = a[minIdx];
            a[minIdx] = tmp;
        }
    }
}

/* Standard iterative binary search; returns 0-based index or -1 if not found */
int binarySearch(int a[], int n, int x) {
    int beg = 0, end = n - 1;
    while (beg <= end) {
        int mid = beg + (end - beg) / 2; /* safer than (beg+end)/2 */
        if (a[mid] == x) return mid;
        else if (a[mid] > x) end = mid - 1;
        else beg = mid + 1;
    }
    return -1;
}
