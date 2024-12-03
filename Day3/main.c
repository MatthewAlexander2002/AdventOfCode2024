#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char line[64];

    file = fopen("Day3/data.txt", "r");
    if (file == NULL) {
        perror("Error Opening File");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {

    }

    return 0;
}