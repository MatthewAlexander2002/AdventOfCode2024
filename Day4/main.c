#include <stdio.h>
#include <string.h>

#define SIZE 140

int total = 0;
char array[SIZE][SIZE];

void found_x(int x, int y);
void found_m(int x, int y, int flag);
void found_a(int x, int y, int flag);
void found_s(int x, int y);

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
            if(array[i][j] == 'X'){
                found_x(i,j);
            }
        }
        printf("\n");
    }

    printf("%d\n", total);
    return 0;
}

void found_x(int x, int y){
    //top left
    if(x-1 >= 0 && y-1 >= 0 && array[x-1][y-1] == 'M'){
        found_m(x-1,y-1, 1);
    }
    //top middle
    if(y-1 >= 0 && array[x][y-1] == 'M'){
        found_m(x,y-1, 2);
    }
    //top right
    if(x+1 < SIZE && y-1 >= 0 && array[x+1][y-1] == 'M'){
        found_m(x+1,y-1, 3);
    }
    //middle left
    if(x-1 >= 0 && array[x-1][y] == 'M'){
        found_m(x-1,y, 4);
    }
    //middle right
    if(x+1 < SIZE && array[x+1][y] == 'M'){
        found_m(x+1,y, 5);
    }
    //bottom left
    if(x-1 >= 0 && y+1 < SIZE && array[x-1][y+1] == 'M'){
        found_m(x-1,y+1, 6);
    }
    //bottom middle
    if(y+1 < SIZE && array[x][y+1] == 'M'){
        found_m(x,y+1, 7);
    }
    //bottom right
    if(x+1 < SIZE && y+1 < SIZE && array[x+1][y+1] == 'M'){
        found_m(x+1,y+1, 8);
    }
}

void found_m(int x, int y, int flag){
    //top left
    if(flag == 1 && x-1 >= 0 && y-1 >= 0 && array[x-1][y-1] == 'A'){
        found_a(x-1,y-1, flag);
    }
    //top middle
    if(flag == 2 && y-1 >= 0 && array[x][y-1] == 'A'){
        found_a(x,y-1, flag);
    }
    //top right
    if(flag == 3 && x+1 < SIZE && y-1 >= 0 && array[x+1][y-1] == 'A'){
        found_a(x+1,y-1, flag);
    }
    //middle left
    if(flag == 4 && x-1 >= 0 && array[x-1][y] == 'A'){
        found_a(x-1,y, flag);
    }
    //middle right
    if(flag == 5 && x+1 < SIZE && array[x+1][y] == 'A'){
        found_a(x+1,y, flag);
    }
    //bottom left
    if(flag == 6 && x-1 >= 0 && y+1 < SIZE && array[x-1][y+1] == 'A'){
        found_a(x-1,y+1, flag);
    }
    //bottom middle
    if(flag == 7 && y+1 < SIZE && array[x][y+1] == 'A'){
        found_a(x,y+1, flag);
    }
    //bottom right
    if(flag == 8 && x+1 < SIZE && y+1 < SIZE && array[x+1][y+1] == 'A'){
        found_a(x+1,y+1, flag);
    }
}

void found_a(int x, int y, int flag){
    //top left
    if(flag == 1 && x-1 >= 0 && y-1 >= 0 && array[x-1][y-1] == 'S'){
        found_s(x-1,y-1);
    }
    //top middle
    if(flag == 2 && y-1 >= 0 && array[x][y-1] == 'S'){
        found_s(x,y-1);
    }
    //top right
    if(flag == 3 && x+1 < SIZE && y-1 >= 0 && array[x+1][y-1] == 'S'){
        found_s(x+1,y-1);
    }
    //middle left
    if(flag == 4 && x-1 >= 0 && array[x-1][y] == 'S'){
        found_s(x-1,y);
    }
    //middle right
    if(flag == 5 && x+1 < SIZE && array[x+1][y] == 'S'){
        found_s(x+1,y);
    }
    //bottom left
    if(flag == 6 && x-1 >= 0 && y+1 < SIZE && array[x-1][y+1] == 'S'){
        found_s(x-1,y+1);
    }
    //bottom middle
    if(flag == 7 && y+1 < SIZE && array[x][y+1] == 'S'){
        found_s(x,y+1);
    }
    //bottom right
    if(flag == 8 && x+1 < SIZE && y+1 < SIZE && array[x+1][y+1] == 'S'){
        found_s(x+1,y+1);
    }
}

void found_s(int x, int y){
    total++;
}

