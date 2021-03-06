#include <stdio.h>
#include <math.h>

#define sqr(x) ((x)*(x))

int main(int argc, const char * argv[]) {
    const long double PI = 3.1415926535;
    int type, type_a, a;
    long double r = -1;
    while (1){
        printf("Введите:\n");
        printf("1 - Ввод радиуса круга.\n");
        printf("2 - Вывод площади круга.\n");
        printf("3 - Вывод площади сектора круга, образованного углом a.\n");
        printf("4 - Вывод длины соответствующей окружности.\n");
        printf("5 - Вывод стороны квадрата, вокруг которого описана окружность.\n");
        printf("6 - Вывод объема конуса, основанием которого служит круг, а высота которого равна введенному радиусу.\n");
        printf("7 - Информация о версии и авторе программы.\n");
        printf("8 - Выход из программы.\n");
        scanf("%d", &type);
        switch (type){
            case 1:
                printf("Введите радиус:\n");
                scanf("%Lf", &r);
                if (r < 0) printf("Ошибка!\n");
                break;
            case 2:
                if (r < 0) printf("Ошибка!\n");
                else printf("Радиус = %.2Lf, Площадь = %.2Lf\n", r, PI * sqr(r));
                break;
            case 3:
                if (r < 0) {
                    printf("Ошибка!\n");
                    break;
                }
                printf("В каком формате хотите ввести угол сектора?:\n");
                printf("1 - градусы\n");
                printf("2 - радианы\n");
                scanf("%d", &type_a);
                if (type_a == 1) {
                    printf("Введите угол в градусах (0 <= a <= 360): \n");
                    scanf("%d", &a);
                    if (a < 0 || a > 360) {
                        scanf("%d", &a);
                        break;
                    }
                    printf("Радиус = %.2Lf, Площадь = %.2Lf\n", r, PI * sqr(r) * a / 360);
                }
                else if (type_a == 2) {
                    printf("Введите угол в радианах (0 <= a <= 2 * PI): \n");
                    scanf("%d", &a);
                    if (a < 0 || a > 2 * PI) {
                        scanf("%d", &a);
                        break;
                    }
                    printf("Радиус = %.2Lf, Площадь = %.2Lf\n", r, sqr(r) * a / 2);
                }
                else {
                    printf("Ошибка!\n");
                }
                break;
            case 4:
                if (r < 0) printf("Ошибка!\n");
                else printf("Радиус = %.2Lf, Длина Окружности = %.2Lf\n", r, 2 * PI * r);
                break;
            case 5:
                if (r < 0) printf("Ошибка!\n");
                else printf("Радиус = %.2Lf, Сторона вписанного квадрата = %.2Lf\n", r, sqrt(2) * r);
                break;
            case 6:
                if (r < 0) printf("Ошибка!\n");
                else printf("Радиус = %.2Lf, Объём конуса = %.2Lf\n", r, sqr(r) * r * PI / 3);
                break;
            case 7:
                printf("Версия 1.0, Автор - Малец Д. Л.\n");
                break;
            case 8:
                return 0;
            default:
                printf("Ошибка!\n");
        }
    }
    return 0;
}
