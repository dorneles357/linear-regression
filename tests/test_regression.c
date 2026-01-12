#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "linear_regression.h"

#define EPSILON 0.001f

int quase_igual(float a, float b) {
    return fabsf(a - b) < EPSILON;
}

void test_model_fit() {
    float x[] = {1, 2, 3};
    float y[] = {3, 5, 7};
    
    LinearModel model = fit_model(x, y, 3);
    
    assert(quase_igual(model.slope, 2.0));
    assert(quase_igual(model.intercept, 1.0));
    
    printf("[PASS] Teste de Ajuste de Modelo (y = 2x + 1)\n");
}

int main() {
    printf("--- INICIANDO TESTES UNITÁRIOS ---\n");
    test_model_fit();
    printf("--- TODOS OS TESTES CONCLUÍDOS ---\n");
    return 0;
}