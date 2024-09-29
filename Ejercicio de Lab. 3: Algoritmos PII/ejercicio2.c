#include <stdio.h>
#include <time.h>

double time1, timedif;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    time1 = (double) clock();           
    time1 = time1 / CLOCKS_PER_SEC;

    int n;
    printf("Introduce el numero: ");
    scanf("%d", &n);

    printf("Secuencia de Fibonacci hasta %d términos:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("El tiempo fue de %f segundos\n", timedif);

    return 0;
}
