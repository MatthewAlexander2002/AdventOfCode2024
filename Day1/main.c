#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key-value pair structure
struct MapEntry {
    int key;
    int value;
};

// Define the map structure
struct Map {
    struct MapEntry* entries;
    int size;
    int capacity;
};

// Initialize a new map
struct Map* createMap(int initialCapacity) {
    struct Map* map = malloc(sizeof(struct Map));
    map->entries = malloc(sizeof(struct MapEntry) * initialCapacity);
    map->size = 0;
    map->capacity = initialCapacity;
    return map;
}

// Insert or update a value
void mapPut(struct Map* map, int key, int value) {
    // Check if key exists
    for(int i = 0; i < map->size; i++) {
        if(map->entries[i].key == key) {
            map->entries[i].value = value;
            return;
        }
    }
    
    // Add new entry
    if(map->size >= map->capacity) {
        map->capacity *= 2;
        map->entries = realloc(map->entries, sizeof(struct MapEntry) * map->capacity);
    }
    
    map->entries[map->size].key = key;
    map->entries[map->size].value = value;
    map->size++;
}

// Get a value
int mapGet(struct Map* map, int key, int defaultValue) {
    for(int i = 0; i < map->size; i++) {
        if(map->entries[i].key == key) {
            return map->entries[i].value;
        }
    }
    return defaultValue;
}

int mapCheck(struct Map* map, int key) {
    for(int i = 0; i < map->size; i++) {
        if(map->entries[i].key == key) {
            return 1;
        }
    }
    return 0;
}

// Free the map
void freeMap(struct Map* map) {
    free(map->entries);
    free(map);
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *file;
    char line[20];
    int *first_half_arr = malloc(1000 * sizeof(int));
    int *second_half_arr = malloc(1000 * sizeof(int));
    struct Map* map = createMap(1000);

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

    for(int i = 0; i < count_arr; i++) {
        mapPut(map, first_half_arr[i], 0);
    }

    for(int i = 0; i < count_arr; i++) {
        if(mapCheck(map, second_half_arr[i])) {
            int value = mapGet(map, second_half_arr[i], 0);
            mapPut(map, second_half_arr[i], value+1);
        }
    }

    for(int i = 0; i < count_arr; i++) {
        // mapGet(map, first_half_arr[i], 0);
        total_diff += first_half_arr[i]*mapGet(map, first_half_arr[i], 0);
        printf("%d\n", total_diff);
    }

    // for(int i = 0; i < count_arr; i++){
    //     int diff = abs(first_half_arr[i] - second_half_arr[i]);
    //     printf("Difference at position %d: %d\n", i, diff);
    //     total_diff += diff;
    // }

    printf("Total difference: %d\n", total_diff);



    free(first_half_arr);
    free(second_half_arr);
    // printf("Hello, Advent of Code 2024!\n");
    return 0;
}