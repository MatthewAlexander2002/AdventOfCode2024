#include <stdio.h>
#include <string.h>

#define SIZE 10

int main() {
    FILE *file;
    char line[11];
    char array[SIZE][SIZE] = {0};

    file = fopen("Day4/data2.txt", "r");
    if (file = NULL) {
        perror("Error Opening The File");
        return 1;
    }

    int row = 0;
    int col = 0;
    while(fgets(line, sizeof(line), file)){
        
    }

    return 0;
}