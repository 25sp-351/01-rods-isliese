// Isla Kim

#include <stdio.h>
#include <stdlib.h>

#define MAX_PIECES 100 

// Structure to store piece information
typedef struct {
    int length;  
    int value;
    double ratio; // Value per length
} Piece; 

// Read "length, value" from standard input
void readStandardInput(Piece pieces[], int *line_count) {
    while (scanf("%d, %d", &pieces[*line_count].length, &pieces[*line_count].value) != EOF) {
        pieces[*line_count].ratio = (double)pieces[*line_count].value / pieces[*line_count].length; // Calculate value per length
        (*line_count)++;

        // Prevent exceeding the maximum number of entries
        if (*line_count >= MAX_PIECES) {
            break;
        }  
    }
}

// Sort in descending order based on value per length
void sortCombination(Piece pieces[], int line_count) {
    for (int i = 0; i < line_count - 1; i++) {
        for (int j = i + 1; j < line_count; j++) {
            if (pieces[i].ratio < pieces[j].ratio) {
                Piece temp = pieces[i];
                pieces[i] = pieces[j];
                pieces[j] = temp;
            }
        }
    }
}

// Cut the rod, selecting the highest-value pieces first
void cutRod(Piece pieces[], int line_count, int rod_length) {
    int total_value = 0;  
    int remainder = rod_length; // Remaining length

    for (int i = 0; i < line_count; i++) {
        if (remainder <= 0) break; 

        int num_pieces = remainder / pieces[i].length; // Number of pieces that can be cut

        if (num_pieces > 0) {
            printf("%d @ %d = %d\n", num_pieces, pieces[i].length, num_pieces * pieces[i].value);
            total_value += num_pieces * pieces[i].value;
            remainder -= num_pieces * pieces[i].length;
        }
    }

    // Print final result
    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", total_value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <rod_length>\n", argv[0]); // Print usage instruction
        return 1;
    }

    int rod_length = atoi(argv[1]); // Rod length from command-line argument

    Piece pieces[MAX_PIECES]; // Array to store price entries
    int line_count = 0; // Number of price entries

    readStandardInput(pieces, &line_count); 
    sortCombination(pieces, line_count); 
    cutRod(pieces, line_count, rod_length); 

    return 0;
}
