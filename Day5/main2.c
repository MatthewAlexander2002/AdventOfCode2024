//1176
//193
#include <stdio.h>
#include <string.h>

#define SIZE1 5
#define SIZE2 100
#define SEC1 1176
#define SEC2 194

struct Pair {
    int first;
    int second;
};

void add_pair(struct Pair pairs[], int index, int first, int second) {
    pairs[index].first = first;
    pairs[index].second = second;
}

void print_pair(struct Pair pair) {
    printf("(%d, %d)\n", pair.first, pair.second);
}

int main() {
    FILE *file1;
    FILE *file2;
    char line1[SIZE1+1];
    char line2[SIZE2+2];
    struct Pair pairs[SEC1];
    int total = 0;

    file1 = fopen("Day5/data.txt", "r");
    if (file1 == NULL) {
        perror("Error Opening The File");
        return 1;
    }

    int count = 0;
    while(fgets(line1, sizeof(line1), file1)){
        int first, second;
        // printf("%s", line1);
        if (sscanf(line1, "%d|%d", &first, &second) == 2) {
            add_pair(pairs, count, first, second);
            count++;
        }
    }

    fclose(file1);

    file2 = fopen("Day5/data1.txt", "r");
    if (file2 == NULL) {
        perror("Error Opening The File");
        return 1;
    }

    while(fgets(line2, sizeof(line2), file2)){
        int array_size = 0;
        int curr_page[30];

        char *token = strtok(line2, ",");
        while (token != NULL) {
            curr_page[array_size++] = atoi(token); // Convert string to integer
            token = strtok(NULL, ",");
        }
        // printf("%s", line2);
        int is_legal = 1;
        for (int i = 1; i < array_size; i++) {
            for(int j = 0; j < count; j++) {
                if(curr_page[i] == pairs[j].first){
                    for(int k = i; k >= 0; k--){
                        if(curr_page[k] == pairs[j].second){
                            is_legal = 0;
                        }
                    }
                }
            }
        }

        if (!is_legal) {
            // total += curr_page[array_size/2];
            for (int i = 1; i < array_size; i++) {
                for(int j = 0; j < count; j++) {
                    if(curr_page[i] == pairs[j].first){
                        for(int k = i; k >= 0; k--){
                            if(curr_page[k] == pairs[j].second){
                                // is_legal = 0;
                                
                            }

                            //if there is more than 1 update set i = 1
                        }
                    }
                }
            }
            total += curr_page[array_size / 2];
        }
        printf("%d\n", total);
    }

    return 0;
}