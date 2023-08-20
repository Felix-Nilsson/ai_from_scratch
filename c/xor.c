#include <stdio.h>
//timestamp: 1 : 52 : 00
typedef struct {
    float or_w1;
    float or_w2;
    float or_b;

    float nand_w1;
    float nand_w2;
    float nand_b;

    float and_w1;
    float and_w2;
    float and_b;


} Xor;

float forward(Xor m, float x, float y){
    float a = m.or_w1*x + m.or_w2*y + m.or_b;
}