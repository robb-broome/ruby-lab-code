/* Test the `vreinterpretQs8_u16' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0" } */
/* { dg-add-options arm_neon } */

#include "arm_neon.h"

void test_vreinterpretQs8_u16 (void)
{
  int8x16_t out_int8x16_t;
  uint16x8_t arg0_uint16x8_t;

  out_int8x16_t = vreinterpretq_s8_u16 (arg0_uint16x8_t);
}

/* { dg-final { cleanup-saved-temps } } */
