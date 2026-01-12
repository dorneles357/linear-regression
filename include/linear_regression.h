#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

typedef struct {
    float slope;
    float intercept;
} LinearModel;

LinearModel fit_model(float *vecX, float *vecY, int size);

#endif