#include <stdio.h>
#include <stdlib.h>

long get_file_size(const char *filename) {
    FILE *file = fopen(filename, "rb"); // Open file in binary mode
    if (file == NULL) {
        perror("Error opening file");
        return -1; // Indicate error
    }

    // Move to the end of the file
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Error seeking to end of file");
        fclose(file);
        return -1; // Indicate error
    }

    // Get the current position in the file (which is the size of the file)
    long size = ftell(file);
    if (size == -1L) {
        perror("Error telling position in file");
        fclose(file);
        return -1; // Indicate error
    }

    // Close the file
    fclose(file);

    return size;
}

int main() {
    const char *filename = "example.txt";
    long size = get_file_size(filename);

    if (size >= 0) {
        printf("Size of file '%s': %ld bytes\n", filename, size);
    } else {
        printf("Failed to determine the size of the file.\n");
    }

    return 0;
}
