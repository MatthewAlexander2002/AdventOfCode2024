#include <stdio.h>
#include <string.h>

#define SIZE 140

int total = 0;
char array[SIZE][SIZE];

// void found_x(int x, int y);
// void found_m(int x, int y, int flag);
int found_a(int x, int y);
// void found_s(int x, int y);

int main() {
    FILE *file;
    char line[SIZE+1];
    memset(array, 'Z', sizeof(array));

    file = fopen("Day4/data.txt", "r");
    if (file == NULL) {
        perror("Error Opening The File");
        return 1;
    }

    int col = 0;
    while(fgets(line, sizeof(line), file) && col < SIZE){
        line[strcspn(line, "\n")] = 0;

        if(strlen(line) == 0) {
            continue;
        }

        // printf("Line read: '%s', length: %lu\n", line, strlen(line));

        int len = strlen(line);
        if (len > SIZE) len = SIZE;

        for(int row = 0; row < len; row++){
            array[row][col] = line[row];
        }
        col++;
    }

    // for(int i = 0; i < SIZE; i++) {
    //     for(int j = 0; j < SIZE; j++) {
    //         printf("%c ", array[i][j]);
    //     }
    //     printf("\n");
    // }

    fclose(file);
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", array[i][j]);
            if(array[i][j] == 'A'){
                found_a(i, j);
            }
        }
        printf("\n");
    }

    printf("%d\n", total);
    return 0;
}

int found_a(int x, int y) {
        if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < SIZE && y + 1 < SIZE) {
        if (array[x - 1][y - 1] == 'M' && array[x - 1][y + 1] == 'M' && array[x + 1][y - 1] == 'S' && array[x + 1][y + 1] == 'S') {
            total++;
        }
        else if (array[x - 1][y - 1] == 'S' && array[x - 1][y + 1] == 'S' && array[x + 1][y - 1] == 'M' && array[x + 1][y + 1] == 'M') {
            total++;
        }
        else if (array[x - 1][y - 1] == 'M' && array[x - 1][y + 1] == 'S' && array[x + 1][y - 1] == 'M' && array[x + 1][y + 1] == 'S') {
            total++;
        }
        else if (array[x - 1][y - 1] == 'S' && array[x - 1][y + 1] == 'M' && array[x + 1][y - 1] == 'S' && array[x + 1][y + 1] == 'M') {
            total++;
        }
    }
}