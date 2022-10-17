#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 

/* Fix by checking if the addition will overflow the UINT type */
unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum;

  if(UINT_MAX - ui_a < ui_b) {
    usum = 0;
  } else {
    usum = ui_a + ui_b;
  }

  return usum;
}

/* Fix by checking if the mult will overflow the UINT type */
unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {

  unsigned umul = ui_a;

  if(ui_a == 0) {
    umul = 0;
  } else if(ui_b > UINT_MAX / ui_a) {
    umul = 1;
  } else {
    umul *= ui_b;
  }

  return umul;
}

/* Fix by checking if the expression is not shifted by a negative number of bits or by greater than or equal to the number of bits that exist in the operand */
uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  uint32_t uShift = 0;

  if(ui_b >= 32) {
    uShift = 0;
  } else {
    uShift = ui_a << ui_b | ui_a >> (32 - ui_b);
  }

  return uShift;
}
