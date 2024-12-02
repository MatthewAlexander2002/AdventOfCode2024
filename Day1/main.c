#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *file;
    char line[20];
    int *first_half_arr = malloc(1000 * sizeof(int));
    int *second_half_arr = malloc(1000 * sizeof(int));

    if (first_half_arr == NULL || second_half_arr == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    int count_arr = 0;
    int total_diff = 0;
    int first_half, second_half;

    file = fopen("Day1/data.txt", "r");

    if (file == NULL) {
        perror("Error Opening File");
        return 1;
    }

    while (fscanf(file, "%d,%d", &first_half, &second_half) == 2) {
        first_half_arr[count_arr] = first_half;
        second_half_arr[count_arr] = second_half;
        count_arr++;
        printf("%d,%d \n", first_half, second_half);
    }
    fclose(file);

    qsort(first_half_arr, count_arr, sizeof(int), compare);
    qsort(second_half_arr, count_arr, sizeof(int), compare);

    for(int i = 0; i < count_arr; i++){
        int diff = abs(first_half_arr[i] - second_half_arr[i]);
        printf("Difference at position %d: %d\n", i, diff);
        total_diff += diff;
    }

    printf("Total difference: %d\n", total_diff);



    free(first_half_arr);
    free(second_half_arr);
    return 0;
}