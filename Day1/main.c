#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int total_diff = 0;
    FILE *file;
    char line[20];
    int *first_half_arr = NULL;
    int *second_half_arr = NULL;
    int count_arr = 0;

    file = fopen("Day1/data.txt", "r");

    if (file == NULL) {
        perror("Error Opening File");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        char str_first_half[6]; 
        char str_second_half[6];

        strncpy(str_first_half, line, 5);
        str_first_half[5] = '\0';

        strncpy(str_second_half, line+6, 5);
        str_second_half[5] = '\0';

        int first_half = atoi(str_first_half);
        int second_half = atoi(str_second_half);

        first_half_arr = realloc(first_half_arr, (count_arr+1)*sizeof(int));
        second_half_arr = realloc(second_half_arr, (count_arr+1)*sizeof(int));

        if (first_half_arr == NULL || second_half_arr == NULL) {
            perror("Error reallocating memory");
            free(first_half_arr);
            free(second_half_arr);
            fclose(file);
            return 1;
        }
        
        first_half_arr[count_arr] = first_half;
        second_half_arr[count_arr] = second_half;
        count_arr++;
        printf("%d,%d \n", first_half, second_half);
    }
    fclose(file);

    qsort(first_half_arr, sizeof(first_half_arr)/sizeof(first_half_arr[0]), sizeof(int), compare);
    qsort(second_half_arr, sizeof(second_half_arr)/sizeof(second_half_arr[0]), sizeof(int), compare);

    for(int i = 0; i < count_arr; i++){
        total_diff += abs(first_half_arr[i] - second_half_arr[i]);
        // printf("%d %d \n", first_half_arr[i], second_half_arr[i]);
        printf("%d \n", total_diff);
    }

    printf("Total absolute difference: %d\n", total_diff);

    free(first_half_arr);
    free(second_half_arr);
    // printf("Hello, Advent of Code 2024!\n");
    return 0;
}