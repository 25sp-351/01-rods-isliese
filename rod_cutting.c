// Isla Kim
// I put Korean comments too to understand more easily since Korean is the most comfortable language for me

#include <stdio.h>
#include <stdlib.h>

#define MAX_PIECES 100 // 가격표 최대 개수 (Maximum number of price entries)

// 조각 정보를 저장할 구조체 (Structure to store piece information)
typedef struct {
    int length;  
    int value;
    double ratio; // 길이당 가치 (Value per length)
} Piece; 

// 표준 입력에서 "길이, 가치" 읽기 (Read "length, value" from standard input)
void readStandardInput(Piece pieces[], int *line_count) {
    while (scanf("%d, %d", &pieces[*line_count].length, &pieces[*line_count].value) != EOF) {
        pieces[*line_count].ratio = (double)pieces[*line_count].value / pieces[*line_count].length; // 단위 길이당 가치 계산 (Calculate value per length)
        (*line_count)++;

        // 최대 개수 초과 방지 (Prevent exceeding the maximum number of entries)
        if (*line_count >= MAX_PIECES) {
            break;
        }  
    }
}

// 단위 길이당 가치 기준으로 내림차순 정렬 (Sort in descending order based on value per length)
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

// 막대 자르기 (가치가 높은 조각부터 선택) (Cut the rod, selecting the highest-value pieces first)
void cutRod(Piece pieces[], int line_count, int rod_length) {
    int total_value = 0;  
    int remainder = rod_length; // 남은 길이 (Remaining length)

    for (int i = 0; i < line_count; i++) {
        if (remainder <= 0) break; 

        int num_pieces = remainder / pieces[i].length; // 해당 길이로 자를 수 있는 개수 (Number of pieces that can be cut)

        if (num_pieces > 0) {
            printf("%d @ %d = %d\n", num_pieces, pieces[i].length, num_pieces * pieces[i].value);
            total_value += num_pieces * pieces[i].value;
            remainder -= num_pieces * pieces[i].length;
        }
    }

    // 최종 결과 출력 (Print final result)
    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", total_value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <rod_length>\n", argv[0]); // 명령어 사용법 출력 (Print usage instruction)
        return 1;
    }

    int rod_length = atoi(argv[1]); // 명령줄에서 입력받은 막대 길이 (Rod length from command-line argument)

    Piece pieces[MAX_PIECES]; // 가격표 저장 배열 (Array to store price entries)
    int line_count = 0; // 가격표 개수 (Number of price entries)

    readStandardInput(pieces, &line_count); 
    sortCombination(pieces, line_count); 
    cutRod(pieces, line_count, rod_length); 

    return 0;
}
