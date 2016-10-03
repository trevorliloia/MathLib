#pragma once


bool fequals(float lhs, float rhs);

float deg2rad(float deg);
float rad2deg(float rad);

float linearHalf(float x);
float fastCurve(float x);
float slowCurve(float x);
float ridgeFlip(float x);
float bounce(float x);
float revBounce(float x);
float parab(float x);
float lerp2(float start, float end, float alpha);
float quadBezier(float a, float b, float c, float t);
float hermiteSpline(float x, float y, float p, float q, float t);
float cardinalSpline(float point0, float point1, float point2, float a, float t);