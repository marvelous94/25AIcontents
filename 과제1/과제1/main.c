#include <stdio.h>
#include <stdlib.h>

int main() {
    int width = 5;
    int height = 5;
    int x = 5; // ���� ��ġ (��)
    int y = 5;  // ���� ��ġ (��)

    // �� �ٿ� width ���� + �ٹٲ� ��ſ� ĳ���� ���� + �������� ���� �� ���� ���� �ʿ�
    // (width + 2) * height + 1 ���� ũ�� ���� (�����ְ�)
    char* rect = malloc(height * (width + x + 2) + 1);
    if (rect == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }

    int pos = 0;
    for (int i = 0; i < height; i++) {
        // �� �� ������ �������� x-1ĭ �б� (Ŀ���� �̹� x ���� �����ϱ� �ٹٲ� �� ĳ���� ���� + ����)
        if (i != 0) {
            rect[pos++] = '\r'; // ĳ���� ����: �� ó������
            for (int s = 1; s < x; s++) {
                rect[pos++] = ' '; // x ��ġ ����� ����
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
            rect[pos++] = '\n'; // �ٹٲ� (���� �ٷ� �̵�)
        }
    }
    rect[pos] = '\0';

    // Ŀ�� �� ���� �̵�
    printf("\x1B[%d;%dH", y, x);
    // ��ü ���
    printf("%s", rect);

    free(rect);
    return 0;
}


