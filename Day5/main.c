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

    file1 = fopen("Day5/data.txt", "r");
    if (file1 == NULL) {
        perror("Error Opening The File");
        return 1;
    }

    int count = 0;
    while(fgets(line1, sizeof(line1), file1) && count < SEC1){
        int first, second;
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

    count = 0;
    while(fgets(line2, sizeof(line2), file2) && count < SEC2){
        
    }

    return 0;
}