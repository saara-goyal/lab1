#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    double average = (double)sum / n;
    printf("Average: %.2f\n", average);

    return 0;
}
