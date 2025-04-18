#include <stdio.h>
#include <string.h>
#include <stdlib.h>


double mean(int *arr, int n) {
    long sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    return (double)sum / n;
}

int cmp_int(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

double median(int *arr, int n) {
    qsort(arr, n, sizeof(int), cmp_int);
    if (n % 2 == 1)
        return arr[n/2];
    else
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
}

void mode(int *arr, int n, int **modes, int *mode_count) {
    // Assumes array sorted
    qsort(arr, n, sizeof(int), cmp_int);
    int max_count = 1, curr_count = 1;
    *mode_count = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i-1]) curr_count++;
        else {
            if(curr_count > max_count) max_count = curr_count;
            curr_count = 1;
        }
    }
    if(curr_count > max_count) max_count = curr_count;

    // Collect all values appearing max_count times
    curr_count = 1;
    for(int i = 1; i <= n; i++){
        if(i < n && arr[i] == arr[i-1]) curr_count++;
        else {
            if(curr_count == max_count) {
                (*mode_count)++;
            }
            curr_count = 1;
        }
    }

    *modes = malloc((*mode_count) * sizeof(int));
    curr_count = 1;
    int idx = 0;
    for(int i = 1; i <= n; i++){
        if(i < n && arr[i] == arr[i-1]) curr_count++;
        else {
            if(curr_count == max_count) {
                (*modes)[idx++] = arr[i-1];
            }
            curr_count = 1;
        }
    }
}

int main() {
    int data[] = {1, 2, 2, 3, 4};
    int n = sizeof(data)/sizeof(data[0]);

    // Copy array for median/mode since we sort in-place
    int *copy = malloc(n * sizeof(int));
    memcpy(copy, data, n * sizeof(int));

    printf("Mean:   %.2f\n", mean(data, n));
    printf("Median: %.2f\n", median(copy, n));

    // mode
    memcpy(copy, data, n * sizeof(int));
    int *modes; int mcount;
    mode(copy, n, &modes, &mcount);
    printf("Mode:   ");
    for(int i = 0; i < mcount; i++) printf("%d ", modes[i]);
    printf("\n");

    free(copy);
    free(modes);
    return 0;
}
