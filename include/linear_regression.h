#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

typedef struct {
    float slope;
    float intercept;
} LinearModel;

LinearModel fit_model(float *vecX, float *vecY, int size);
float r2_score(float *vecX, float *vecY, LinearModel model, int size);
float standard_error(float *vecX, float *vecY, LinearModel model, int size);

#endif