#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Goal: adjust a number to approach the weight of the training set
i.e. our training set is x * w = y, and the true w = 2

*/

float train[][2] = {
  {0,0},
  {1,2},
  {2,4},
  {3,6},
  {4,8}

};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void){
  return (float) rand() / (float) RAND_MAX;
}

float cost(float w){
  float result = 0.0f; 

  for(size_t i = 0; i < train_count; ++i){
    float x = train[i][0];
    float y = x * w;
    float d = y - train[i][1];
    result += d*d;

  }

  result /= train_count;

  return result;

}

int main(){

  //srand(time(0));
  srand(70);
  float w = rand_float()*10.0f;
  float rate = 1e-3;
  float eps = 1e-3;

  printf("%f\n",cost(w));

  for(size_t i = 0; i < 500; ++i){
    float dcost = (cost(w + eps) - cost(w))/eps;
    w -= rate*dcost;
    printf("cost = %f, w= %f\n", cost(w),w);

  }
  
  printf("------------------------------\n");
  printf("%f\n",w);

  return 0;
}
