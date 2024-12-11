#include <stdio.h>
void tim(int a, int b) {
    int i;
    int min_num = (a < b) ? a : b;

    for (i = min_num; i > 0; i--) {
        if (a % i == 0 && b % i == 0) { 
            printf("UCLN %d và %d: %d\n", a, b, i);
            return;
        }
    }
}

int main() {
    int num1, num2;

    printf("Nhap so thu nhat: ");
    scanf("%d", &num1);
    printf("Nhap so thu 2: ");
    scanf("%d", &num2);

    tim(num1, num2);

    return 0;
}
