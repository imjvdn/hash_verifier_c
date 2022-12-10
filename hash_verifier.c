#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <supplied_hash> <file>\n", argv[0]);
        return 1;
    }

    // Get the supplied hash and file name from the command line arguments
    char *supplied_hash = argv[1];
    char *file_name = argv[2];

    // Use the md5sum command to calculate the hash of the file
    char command[256];
    sprintf(command, "md5sum %s", file_name);
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: Failed to calculate hash of file\n");
        return 1;
    }

    // Read the calculated hash from the output of the md5sum command
    char calculated_hash[33];
    fgets(calculated_hash, 33, fp);
    pclose(fp);

    // Print the file name and the supplied and calculated hashes
    printf("File: %s\n", file_name);
    printf("Supplied hash: %s", supplied_hash);
    printf("Calculated hash: %s", calculated_hash);

    // Check if the supplied hash and calculated hash match
    int result = strcmp(supplied_hash, calculated_hash);
    if (result == 0) {
        printf("Result: Valid\n");
    } else {
        printf("Result: Invalid\n");
    }

    // Print the algorithm used
    printf("Algorithm: MD5\n");

    return 0;
}
