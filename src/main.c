#include <stdio.h>
#include "linear_regression.h"

int main() {
    float x[] = {-2, -2, -1, -1, 0, 0, 1, 1, 2, 2};
    float y[] = {0, 0, 2, 3, 4, 4, 5, 6, 8, 8};
    int n = sizeof(x) / sizeof(x[0]);

    LinearModel my_model = fit_model(x, y, n);

    printf("--------------Modelo de Regressão-----------------\n");
    printf("Equação: y = %.2fx + %.2f\n", my_model.slope, my_model.intercept);
    printf("--------------------------------------------------\n");
    printf("Slope (b1):     %.2f\n", my_model.slope);
    printf("Intercept (b0): %.2f\n", my_model.intercept);
    printf("--------------------------------------------------\n");
    printf("R² Score:       %.2f\n", r2_score(x, y, my_model, n));
    printf("Standard Error: %.2f\n", standard_error(x, y, my_model, n));
    printf("--------------------------------------------------\n");
    
    return 0;
}