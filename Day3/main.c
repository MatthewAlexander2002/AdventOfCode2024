#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char line[20000];
    int total = 0;
    int do_or_dont = 1;

    file = fopen("Day3/data.txt", "r");
    if (file == NULL) {
        perror("Error Opening File");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        for(int i = 0; i < strlen(line); i++) {
            if(line[i] == 'm' && line[i+1] == 'u' && line[i+2] == 'l' && line[i+3] == '(') {
                int reset_i_to = i; //to put i back to when done to ensure that i hasn't moved too far ahead incases where the rest of the input is wrong
                i += 4;
                char first_num[10] = {0}; 
                char second_num[10] = {0}; 
                int counter = 0; //ensures the look ahead is only 3 places
                while(line[i] != ',' && counter < 3){
                    // printf("\n%c\n", line[i]);
                    first_num[counter++] = line[i++];
                }
                first_num[counter] = '\0';

                if(counter == 0 || line[i] != ','){
                    i = reset_i_to;
                    continue;
                }
                i++;

                counter = 0;
                while(line[i] != ')' && counter < 3){
                    // printf("\n%c\n", line[i]);
                    second_num[counter++] = line[i++];
                }
                second_num[counter] = '\0';

                if(counter == 0 || line[i] != ')'){
                    i = reset_i_to;
                    continue;
                } 
                i++;

                printf("First Num %s\n", first_num);
                printf("Second Num %s\n", second_num);

                char *endptr1;
                long num1 = strtol(first_num, &endptr1, 10);
                char *endptr2;
                long num2 = strtol(second_num, &endptr2, 10);

                if (*endptr1 != '\0' || *endptr2 != '\0'){
                    i = reset_i_to;
                    continue;
                } 
                
                if(do_or_dont){
                    total += (int)num1 * (int)num2;
                    printf("Current Total: %d\n", total);
                }
                i = reset_i_to;
            } else if (line[i] == 'd' && line[i+1] == 'o' && line[i+2] == '(' && line[i+3] == ')' ) {
                do_or_dont = 1;
            }
            else if (line[i] == 'd' && line[i+1] == 'o' && line[i+2] == 'n' && line[i+3] == '\'' && line[i+4] == 't' && line[i+5] == '(' && line[i+6] == ')' ) {
                do_or_dont = 0;
            }
            
        }
    }
    printf("\nTotal: %d\n", total);
    fclose(file);
    return 0;
}