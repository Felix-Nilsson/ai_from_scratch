#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Goal: adjust a number to approach the weight of the training set
i.e. our training set is x * w = y, and the true w = 2

*/

float train[][2] = {
  {0,0},
  {1,3},
  {2,6},
  {3,9},
  {4,12}

};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void){
  return (float) rand() / (float) RAND_MAX;
}

float cost(float w, float b){
  float result = 0.0f; 

  for(size_t i = 0; i < train_count; ++i){
    float x = train[i][0];
    float y = x * w + b;
    float d = y - train[i][1];
    result += d*d;

  }

  result /= train_count;

  return result;

}

int main(){

  //srand(time(0));
  srand(time(0));
  float w = rand_float()*10.0f;
  float b = rand_float()*5.0f;

  float rate = 1e-3;
  float eps = 1e-3;

  for(size_t i = 0; i < 5000; ++i){
    
    float c = cost(w,b);

    float dw = (cost(w + eps, b) - c)/eps;
    float db = (cost(w, b + eps) - c)/eps;

    w -= rate*dw;
    b -= rate*db;

    printf("cost = %f, w= %f, b= %f\n", c,w,b);

  }
  
  printf("------------------------------\n");
  printf("w= %f, b= %f\n",w,b);

  return 0;
}
