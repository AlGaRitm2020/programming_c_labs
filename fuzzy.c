#include <stdio.h>
#include <stdlib.h>

float min(float a, float b) {
  if (a > b) return b;
  return a;}
float max(float a, float b) {
  if (a > b) return a;
  return b;}
float AND(float a, float b) {return min(a,b);} 
float OR(float a, float b) {return max(a,b);}
float NOT(float a) {return 1.0-a;}
float IMPLICATION(float a, float b) {return OR(NOT(a), b);}
float EQUIVALENT(float a, float b) {return AND(IMPLICATION(a, b), IMPLICATION(b, a));}
typedef float (*five_arg_function)(float, float, float, float, float);

float DegreeOfEquivalence(five_arg_function f1, five_arg_function f2, float* x, float* y, float* z, float* a, float* b) {
  float intersection = 1;
  for (int i = 0; x[i] != 0.0; i++) {
    for (int j = 0; y[j] != 0.0; j++) {
      for (int k = 0; z[k] != 0.0; k++) {
        for (int l = 0; a[l] != 0.0; l++) {
          for (int m = 0; z[m] != 0.0; m++) {
            float local_eq = EQUIVALENT(f1(x[i], y[j], z[k],a[l],b[m]), f2(x[i], y[j], z[k],a[l],b[m]));
            intersection = AND(intersection, local_eq);
          }
        }
       }
    } 
  }
  return intersection;
}
int main() {
  // float or2(float a, float b, float c, float d, float e) {return OR(a,b);} 
  float impl2(float a, float b, float c, float d, float e) {return IMPLICATION(NOT(a), b);}
  float and2(float a, float b, float c, float d, float e) {return AND(a, NOT(b));}
  
  float x[] = {0.8, 0.6, 0.7, 0.0};
  float y[] = {0.3, 0.4, 0.0};
  float z[] = {1.5, 0.0};
  float a[] = {1.5, 0.0};
  float b[] = {1.5, 0.0};

  
  // float x[] = {0.1, 0.2, 0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0, 0.0};
  // float y[] = {0.1, 0.2, 0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0, 0.0};

  float result = DegreeOfEquivalence(impl2, and2, x, y, z, a, b);
  printf("DegreeOfEquivalence: %f\n", result);

}
