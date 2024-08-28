//Matriz header developed by wartk(08/23/2024)

#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <math.h>
#include "vectors.h"

typedef struct Matrix2 {
    float x1; float x2;
    float x3; float x4;
} Matrix2x2;

typedef struct Matrix3 {
    float x1; float x2; float x3;
    float x4; float x5; float x6;
    float x7; float x8; float x9;
} Matrix3x3;

typedef struct Matrix4 {
    float x1; float x2; float x3; float x4;
    float x5; float x6; float x7; float x8;
    float x9; float x10; float x11; float x12;
    float x13; float x14; float x15; float x16;
} Matrix4x4;

float Det(Matrix2x2 x) {
    return (x.x1 * x.x4) - (x.x2 * x.x3);
}

float Det(Matrix3x3 x) {
    float det1 = x.x1 * (x.x5 * x.x9 - x.x6 * x.x8);
    float det2 = x.x2 * (x.x4 * x.x9 - x.x6 * x.x7);
    float det3 = x.x3 * (x.x4 * x.x8 - x.x5 * x.x7);

    return det1 - det2 + det3;
}

Matrix2x2 Multi(Matrix2x2 a, Matrix2x2 b) {
    Matrix2x2 new_matrix = {
        (a.x1 * b.x1 + a.x2 * b.x3), (a.x1 * b.x2 + a.x2 * b.x4),
        (a.x3 * b.x1 + a.x4 * b.x3), (a.x3 * b.x2 + a.x4 * b.x4),
    };
    return new_matrix;
}

Matrix3x3 Multi(Matrix3x3 a, Matrix3x3 b) {
    Matrix3x3 new_matrix = {
        (a.x1 * b.x1 + a.x2 * b.x4 + a.x3 * b.x7), 
        (a.x1 * b.x2 + a.x2 * b.x5 + a.x3 * b.x8),
        (a.x1 * b.x3 + a.x2 * b.x6 + a.x3 * b.x9),

        (a.x4 * b.x1 + a.x5 * b.x4 + a.x6 * b.x7), 
        (a.x4 * b.x2 + a.x5 * b.x5 + a.x6 * b.x8),
        (a.x4 * b.x3 + a.x5 * b.x6 + a.x6 * b.x9),

        (a.x7 * b.x1 + a.x8 * b.x4 + a.x9 * b.x7), 
        (a.x7 * b.x2 + a.x8 * b.x5 + a.x9 * b.x8),
        (a.x7 * b.x3 + a.x8 * b.x6 + a.x9 * b.x9),
    };
    return new_matrix;
}

Matrix4x4 Multi(Matrix4x4 a, Matrix4x4 b) {
    Matrix4x4 new_matrix = {
        (a.x1 * b.x1 + a.x2 * b.x5 + a.x3 * b.x9 + a.x4 * b.x13),
        (a.x1 * b.x2 + a.x2 * b.x6 + a.x3 * b.x10 + a.x4 * b.x14),
        (a.x1 * b.x3 + a.x2 * b.x7 + a.x3 * b.x11 + a.x4 * b.x15),
        (a.x1 * b.x4 + a.x2 * b.x8 + a.x3 * b.x12 + a.x4 * b.x16),

        (a.x5 * b.x1 + a.x6 * b.x5 + a.x7 * b.x9 + a.x8 * b.x13),
        (a.x5 * b.x2 + a.x6 * b.x6 + a.x7 * b.x10 + a.x8 * b.x14),
        (a.x5 * b.x3 + a.x6 * b.x7 + a.x7 * b.x11 + a.x8 * b.x15),
        (a.x5 * b.x4 + a.x6 * b.x8 + a.x7 * b.x12 + a.x8 * b.x16),

        (a.x9 * b.x1 + a.x10 * b.x5 + a.x11 * b.x9 + a.x12 * b.x13),
        (a.x9 * b.x2 + a.x10 * b.x6 + a.x11 * b.x10 + a.x12 * b.x14),
        (a.x9 * b.x3 + a.x10 * b.x7 + a.x11 * b.x11 + a.x12 * b.x15),
        (a.x9 * b.x4 + a.x10 * b.x8 + a.x11 * b.x12 + a.x12 * b.x16),

        (a.x13 * b.x1 + a.x14 * b.x5 + a.x15 * b.x9 + a.x16 * b.x13),
        (a.x13 * b.x2 + a.x14 * b.x6 + a.x15 * b.x10 + a.x16 * b.x14),
        (a.x13 * b.x3 + a.x14 * b.x7 + a.x15 * b.x11 + a.x16 * b.x15),
        (a.x13 * b.x4 + a.x14 * b.x8 + a.x15 * b.x12 + a.x16 * b.x16),
    };
    return new_matrix;
}

Vector3 Multi(Matrix3x3 b, Vector3 a) {
    Vector3 new_vector;

    new_vector.x = (b.x1 * a.x) + (b.x2 * a.y) + (b.x3 * a.z);
    new_vector.y = (b.x4 * a.x) + (b.x5 * a.y) + (b.x6 * a.z);
    new_vector.z = (b.x7 * a.x) + (b.x8 * a.y) + (b.x9 * a.z);
    return new_vector;
}

Matrix3x3 rotationZ(float angle) {
    Matrix3x3 new_matrix;
    new_matrix.x1 = cos(angle);
    new_matrix.x2 = -sin(angle);
    new_matrix.x3 = 0;

    new_matrix.x4 = sin(angle);;
    new_matrix.x5 = cos(angle);;
    new_matrix.x6 = 0;

    new_matrix.x7 = 0;
    new_matrix.x8 = 0;
    new_matrix.x9 = 1;

    return new_matrix;
}

Matrix3x3 rotationY(float angle) {
    Matrix3x3 new_matrix;
    new_matrix.x1 = cos(angle);
    new_matrix.x2 = 0;
    new_matrix.x3 = sin(angle);

    new_matrix.x4 = 0;
    new_matrix.x5 = 1;
    new_matrix.x6 = 0;

    new_matrix.x7 = -sin(angle);
    new_matrix.x8 = 0;
    new_matrix.x9 = cos(angle);

    return new_matrix;
}


Matrix3x3 rotationX(float angle) {
    Matrix3x3 new_matrix;
    new_matrix.x1 = 1;
    new_matrix.x2 = 0;
    new_matrix.x3 = 0;

    new_matrix.x4 = 0;
    new_matrix.x5 = cos(angle);
    new_matrix.x6 = -sin(angle);

    new_matrix.x7 = 0;
    new_matrix.x8 = sin(angle);
    new_matrix.x9 = cos(angle);

    return new_matrix;
}

void Print(Matrix2x2 a) {
    printf("%f %f\n%f %f\n", a.x1, a.x2, a.x3, a.x4);
}

void Print(Matrix3x3 a) {
    printf("%f %f %f\n%f %f %f\n%f %f %f\n", a.x1, a.x2, a.x3,
                                             a.x4, a.x5, a.x6,
                                             a.x7, a.x8, a.x9);
}

void Print(Matrix4x4 a) {
    printf("%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n", a.x1, a.x2, a.x3, a.x4,
                                                                       a.x5, a.x6, a.x7, a.x8,
                                                                       a.x9, a.x10, a.x11, a.x12,
                                                                       a.x13, a.x14, a.x15, a.x16);
}

#endif