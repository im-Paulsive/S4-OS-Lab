#include <stdio.h>

#define MAX 100

int disk[MAX];  // -1 means free, >=0 means it points to the next block or -2 for end

void initialize_disk(int size) {
    for (int i = 0; i < size; i++) {
        disk[i] = -1;  // All blocks are free initially
    }
}

int allocate_file(int start, int length, int size) {
    int count = 0;
    int current = start;

    if (disk[start] != -1) {
        printf("Starting block %d is already allocated.\n", start);
        return -1;
    }

    disk[start] = -2;  // Temporarily mark as end (will update later)
    count++;

    while (count < length) {
        int found = 0;
        for (int i = 0; i < size; i++) {
            if (disk[i] == -1) {
                disk[current] = i;
                current = i;
                disk[current] = -2;
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Not enough free blocks to allocate file.\n");
            return -1;
        }
        count++;
    }
    return start;
}

void print_file(int start) {
    int current = start;
    printf("Allocated blocks: ");
    while (current != -2) {
        printf("%d -> ", current);
        current = disk[current];
    }
    printf("END\n");
}

int main() {
    int size = 50;  // Size of the disk (number of blocks)
    initialize_disk(size);

    int start, length;

    printf("Enter starting block and length of file: ");
    scanf("%d %d", &start, &length);

    if (start >= size) {
        printf("Invalid starting block!\n");
        return 0;
    }

    int allocated_start = allocate_file(start, length, size);

    if (allocated_start != -1) {
        print_file(allocated_start);
    }

    return 0;
}
