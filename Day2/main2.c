#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dampener(int line_nums[10], int line_num);
void removeIndex(int source[], int dest[], int size, int index_to_remove);
int is_safe(int line_nums[10], int line_num);

int main() {
    FILE *file;
    char line[64];
    int line_nums[10];
    int line_num = 0;
    int total = 0;

    file = fopen("Day2/data.txt", "r");
    if (file == NULL) {
        perror("Error Opening File");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        line_num = 0;
        int is_safe = 1;

        char *token = strtok(line, " ");
        while (token != NULL) {
            line_nums[line_num] = atoi(token);
            printf("Number: %d\n", line_nums[line_num]);
            line_num++;
            token = strtok(NULL, " ");
        }

        is_safe = dampener(line_nums, line_num);

        if(is_safe){
            total++;
        }
        printf("%d\n", total);
    }
    
    printf("%d\n", total);

    fclose(file);
    return 0;
}


int dampener(int line_nums[10], int line_num) {
    int new_line_nums[10];
    int result = 0;

    for(int i = 0; i < line_num; i++) {
        removeIndex(line_nums, new_line_nums, line_num, i);
        result = is_safe(new_line_nums, line_num-1);
        if(result) {
            return 1;
        }
    }
    return 0;
}

void removeIndex(int source[], int dest[], int size, int index_to_remove) {
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(i != index_to_remove) {
            dest[j] = source[i];
            j++;
        }
    }
}

int is_safe(int line_nums[10], int line_num){
    int is_safe = 1;

    if(line_nums[0] > line_nums[1]){
            for(int i = 1; i < line_num; i++) {
                if(line_nums[i-1] > line_nums[i] && (line_nums[i-1] - line_nums[i]) <= 3){
                    continue;
                } else {
                    is_safe = 0;
                }
            }
        } else {
            for(int i = 1; i < line_num; i++) {
                if(line_nums[i-1] < line_nums[i] && (line_nums[i] - line_nums[i-1]) <= 3){
                    continue;
                } else {
                    is_safe = 0;
                }
            }
        }
    return is_safe;
}