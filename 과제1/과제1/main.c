#include <stdio.h>
#include <stdlib.h>

int main() {
    int width = 5;
    int height = 5;
    int x = 5; // 가로 위치 (열)
    int y = 5;  // 세로 위치 (줄)

    // 한 줄에 width 글자 + 줄바꿈 대신에 캐리지 리턴 + 공백으로 다음 줄 시작 맞춤 필요
    // (width + 2) * height + 1 정도 크기 잡음 (여유있게)
    char* rect = malloc(height * (width + x + 2) + 1);
    if (rect == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    int pos = 0;
    for (int i = 0; i < height; i++) {
        // 각 줄 시작은 공백으로 x-1칸 밀기 (커서가 이미 x 열에 있으니까 줄바꿈 후 캐리지 리턴 + 공백)
        if (i != 0) {
            rect[pos++] = '\r'; // 캐리지 리턴: 줄 처음으로
            for (int s = 1; s < x; s++) {
                rect[pos++] = ' '; // x 위치 맞춤용 공백
            }
        }

        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                rect[pos++] = '#';
            }
            else {
                rect[pos++] = ' ';
            }
        }

        if (i != height - 1) {
            rect[pos++] = '\n'; // 줄바꿈 (다음 줄로 이동)
        }
    }
    rect[pos] = '\0';

    // 커서 한 번만 이동
    printf("\x1B[%d;%dH", y, x);
    // 전체 출력
    printf("%s", rect);

    free(rect);
    return 0;
}


