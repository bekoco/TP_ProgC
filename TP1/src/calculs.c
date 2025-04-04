#include <stdio.h>

int main() {
    int num1 = 10;
    int num2 = 3;
    char op = '+'; // Change cette valeur pour tester d'autres opérations

    int result;

    switch (op) {
        case '+':
            result = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("%d * %d = %d\n", num1, num2, result);
            break;

        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("%d / %d = %d\n", num1, num2, result);
            } else {
                printf("Erreur : division par zéro !\n");
            }
            break;

        case '%':
            if (num2 != 0) {
                result = num1 % num2;
                printf("%d %% %d = %d\n", num1, num2, result);
            } else {
                printf("Erreur : modulo par zéro !\n");
            }
            break;

        case '&':
            result = num1 & num2;
            printf("%d & %d = %d\n", num1, num2, result);
            break;

        case '|':
            result = num1 | num2;
            printf("%d | %d = %d\n", num1, num2, result);
            break;

        case '~':
            result = ~num1;
            printf("~%d = %d\n", num1, result);
            break;

        default:
            printf("Opérateur non reconnu.\n");
    }

    return 0;
}

