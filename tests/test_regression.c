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

void test_r2_score() {
    float x[] = {1, 2, 3};
    float y[] = {3, 5, 7};
    
    LinearModel model = fit_model(x, y, 3);
    float r2 = r2_score(x, y, model, 3);
    
    assert(quase_igual(r2, 1.0));
    
    printf("[PASS] Teste de R² Score\n");
}

void test_standard_error() {
    float x[] = {1, 2, 3};
    float y[] = {3, 5, 7};
    
    LinearModel model = fit_model(x, y, 3);
    float se = standard_error(x, y, model, 3);
    
    assert(quase_igual(se, 0.0));
    
    printf("[PASS] Teste de Erro Padrão\n");
}

int main() {
    test_model_fit();
    test_r2_score();
    test_standard_error();
    return 0;
}