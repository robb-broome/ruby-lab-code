/* Generated automatically by the program `genoutput'
   from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "flags.h"
#include "ggc.h"
#include "rtl.h"
#include "expr.h"
#include "insn-codes.h"
#include "tm_p.h"
#include "function.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "insn-config.h"

#include "conditions.h"
#include "insn-attr.h"

#include "recog.h"

#include "diagnostic-core.h"
#include "output.h"
#include "target.h"
#include "tm-constrs.h"

static const char * const output_0[] = {
  "test{b}\t%0, %0",
  "cmp{b}\t{%1, %0|%0, %1}",
};

static const char * const output_1[] = {
  "test{w}\t%0, %0",
  "cmp{w}\t{%1, %0|%0, %1}",
};

static const char * const output_2[] = {
  "test{l}\t%0, %0",
  "cmp{l}\t{%1, %0|%0, %1}",
};

static const char * const output_3[] = {
  "test{q}\t%0, %0",
  "cmp{q}\t{%1, %0|%0, %1}",
};

static const char *
output_18 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1215 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, false, false);
}

static const char *
output_20 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1262 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, false, false);
}

static const char *
output_22 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1296 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, false, false);
}

static const char *
output_23 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1296 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, false, false);
}

static const char *
output_26 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1331 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, false, true);
}

static const char *
output_28 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1381 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, false, false);
}

static const char *
output_29 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1381 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, false, false);
}

static const char *
output_33 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1435 "../../gcc/config/i386/i386.md"
{
#ifndef HAVE_AS_IX86_SAHF
  if (TARGET_64BIT)
    return ASM_BYTE "0x9e";
  else
#endif
  return "sahf";
}
}

static const char *
output_34 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1459 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, true, false);
}

static const char *
output_35 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1488 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, true, false);
}

static const char *
output_36 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1512 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, true, false);
}

static const char *
output_37 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1532 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, true, true);
}

static const char *
output_38 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1561 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, true, true);
}

static const char *
output_39 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1585 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, true, true);
}

static const char * const output_42[] = {
  "push{q}\t%1",
  "#",
};

static const char *
output_59 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1806 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      if (misaligned_operand (operands[0], OImode)
	  || misaligned_operand (operands[1], OImode))
	return "vmovdqu\t{%1, %0|%0, %1}";
      else
	return "vmovdqa\t{%1, %0|%0, %1}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_60 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1830 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      return "#";
    case 2:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 3:
    case 4:
      /* TDmode values are passed as TImode on the stack.  Moving them
	 to stack may result in unaligned memory access.  */
      if (misaligned_operand (operands[0], TImode)
	  || misaligned_operand (operands[1], TImode))
	{
	  if (get_attr_mode (insn) == MODE_V4SF)
	    return "%vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqu\t{%1, %0|%0, %1}";
	}
      else
	{
	  if (get_attr_mode (insn) == MODE_V4SF)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_61 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1890 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      /* TDmode values are passed as TImode on the stack.  Moving them
	 to stack may result in unaligned memory access.  */
      if (misaligned_operand (operands[0], TImode)
	  || misaligned_operand (operands[1], TImode))
	{
	  if (get_attr_mode (insn) == MODE_V4SF)
	    return "%vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqu\t{%1, %0|%0, %1}";
	}
      else
	{
	  if (get_attr_mode (insn) == MODE_V4SF)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_62 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1935 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_SSECVT:
      if (SSE_REG_P (operands[0]))
	return "movq2dq\t{%1, %0|%0, %1}";
      else
	return "movdq2q\t{%1, %0|%0, %1}";

    case TYPE_SSEMOV:
      if (get_attr_mode (insn) == MODE_TI)
	return "%vmovdqa\t{%1, %0|%0, %1}";
      /* Handle broken assemblers that require movd instead of movq.  */
      if (GENERAL_REG_P (operands[0]) || GENERAL_REG_P (operands[1]))
	return "%vmovd\t{%1, %0|%0, %1}";
      else
	return "%vmovq\t{%1, %0|%0, %1}";

    case TYPE_MMXMOV:
      /* Handle broken assemblers that require movd instead of movq.  */
      if (GENERAL_REG_P (operands[0]) || GENERAL_REG_P (operands[1]))
	return "movd\t{%1, %0|%0, %1}";
      else
	return "movq\t{%1, %0|%0, %1}";

    case TYPE_SSELOG1:
      return standard_sse_constant_opcode (insn, operands[1]);

    case TYPE_MMX:
      return "pxor\t%0, %0";

    case TYPE_MULTI:
      return "#";

    case TYPE_LEA:
      return "lea{q}\t{%E1, %0|%0, %E1}";

    default:
      gcc_assert (!flag_pic || LEGITIMATE_PIC_OPERAND_P (operands[1]));
      if (get_attr_mode (insn) == MODE_SI)
	return "mov{l}\t{%k1, %k0|%k0, %k1}";
      else if (which_alternative == 2)
	return "movabs{q}\t{%1, %0|%0, %1}";
      else if (ix86_use_lea_for_mov (insn, operands))
	return "lea{q}\t{%E1, %0|%0, %E1}";
      else
	return "mov{q}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_63 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2100 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_SSECVT:
      if (SSE_REG_P (operands[0]))
	return "movq2dq\t{%1, %0|%0, %1}";
      else
	return "movdq2q\t{%1, %0|%0, %1}";

    case TYPE_SSEMOV:
      switch (get_attr_mode (insn))
	{
	case MODE_TI:
	  return "%vmovdqa\t{%1, %0|%0, %1}";
	case MODE_DI:
	   return "%vmovq\t{%1, %0|%0, %1}";
	case MODE_V4SF:
	  return "movaps\t{%1, %0|%0, %1}";
	case MODE_V2SF:
	  return "movlps\t{%1, %0|%0, %1}";
	default:
	  gcc_unreachable ();
	}

    case TYPE_MMXMOV:
      return "movq\t{%1, %0|%0, %1}";

    case TYPE_SSELOG1:
      return standard_sse_constant_opcode (insn, operands[1]);

    case TYPE_MMX:
      return "pxor\t%0, %0";

    case TYPE_MULTI:
      return "#";

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_64 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2181 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_SSELOG1:
      return standard_sse_constant_opcode (insn, operands[1]);

    case TYPE_SSEMOV:
      switch (get_attr_mode (insn))
	{
	case MODE_TI:
	  return "%vmovdqa\t{%1, %0|%0, %1}";
	case MODE_V4SF:
	  return "%vmovaps\t{%1, %0|%0, %1}";
	case MODE_SI:
          return "%vmovd\t{%1, %0|%0, %1}";
	case MODE_SF:
          return "%vmovss\t{%1, %0|%0, %1}";
	default:
	  gcc_unreachable ();
	}

    case TYPE_MMX:
      return "pxor\t%0, %0";

    case TYPE_MMXMOV:
      if (get_attr_mode (insn) == MODE_DI)
	return "movq\t{%1, %0|%0, %1}";
      return "movd\t{%1, %0|%0, %1}";

    case TYPE_LEA:
      return "lea{l}\t{%E1, %0|%0, %E1}";

    default:
      gcc_assert (!flag_pic || LEGITIMATE_PIC_OPERAND_P (operands[1]));
      if (ix86_use_lea_for_mov (insn, operands))
	return "lea{l}\t{%E1, %0|%0, %E1}";
      else
	return "mov{l}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_65 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2260 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      /* movzwl is faster than movw on p2 due to partial word stalls,
	 though not as fast as an aligned movl.  */
      return "movz{wl|x}\t{%1, %k0|%k0, %1}";
    default:
      if (get_attr_mode (insn) == MODE_SI)
        return "mov{l}\t{%k1, %k0|%k0, %k1}";
      else
        return "mov{w}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_66 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2316 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      gcc_assert (ANY_QI_REG_P (operands[1]) || MEM_P (operands[1]));
      return "movz{bl|x}\t{%1, %k0|%k0, %1}";
    default:
      if (get_attr_mode (insn) == MODE_SI)
        return "mov{l}\t{%k1, %k0|%k0, %k1}";
      else
        return "mov{b}\t{%1, %0|%0, %1}";
    }
}
}

static const char * const output_67[] = {
  "movabs{b}\t{%1, %P0|%P0, %1}",
  "mov{b}\t{%1, %a0|%a0, %1}",
};

static const char * const output_68[] = {
  "movabs{w}\t{%1, %P0|%P0, %1}",
  "mov{w}\t{%1, %a0|%a0, %1}",
};

static const char * const output_69[] = {
  "movabs{l}\t{%1, %P0|%P0, %1}",
  "mov{l}\t{%1, %a0|%a0, %1}",
};

static const char * const output_70[] = {
  "movabs{q}\t{%1, %P0|%P0, %1}",
  "mov{q}\t{%1, %a0|%a0, %1}",
};

static const char * const output_71[] = {
  "movabs{b}\t{%P1, %0|%0, %P1}",
  "mov{b}\t{%a1, %0|%0, %a1}",
};

static const char * const output_72[] = {
  "movabs{w}\t{%P1, %0|%0, %P1}",
  "mov{w}\t{%a1, %0|%0, %a1}",
};

static const char * const output_73[] = {
  "movabs{l}\t{%P1, %0|%0, %P1}",
  "mov{l}\t{%a1, %0|%0, %a1}",
};

static const char * const output_74[] = {
  "movabs{q}\t{%P1, %0|%0, %P1}",
  "mov{q}\t{%a1, %0|%0, %a1}",
};

static const char *
output_87 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2492 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      return "movs{bl|x}\t{%h1, %k0|%k0, %h1}";
    default:
      return "mov{b}\t{%h1, %0|%0, %h1}";
    }
}
}

static const char *
output_88 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2517 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      return "movs{bl|x}\t{%h1, %k0|%k0, %h1}";
    default:
      return "mov{b}\t{%h1, %0|%0, %h1}";
    }
}
}

static const char *
output_91 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2554 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      return "movz{bl|x}\t{%h1, %k0|%k0, %h1}";
    default:
      return "mov{b}\t{%h1, %0|%0, %h1}";
    }
}
}

static const char *
output_92 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2580 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      return "movz{bl|x}\t{%h1, %k0|%k0, %h1}";
    default:
      return "mov{b}\t{%h1, %0|%0, %h1}";
    }
}
}

static const char *
output_93 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2612 "../../gcc/config/i386/i386.md"
{
  if (CONST_INT_P (operands[1]))
    operands[1] = simplify_gen_subreg (QImode, operands[1], SImode, 0);
  return "mov{b}\t{%b1, %h0|%h0, %b1}";
}
}

static const char *
output_94 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2612 "../../gcc/config/i386/i386.md"
{
  if (CONST_INT_P (operands[1]))
    operands[1] = simplify_gen_subreg (QImode, operands[1], DImode, 0);
  return "mov{b}\t{%b1, %h0|%h0, %b1}";
}
}

static const char *
output_95 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2626 "../../gcc/config/i386/i386.md"
{
  if (CONST_INT_P (operands[1]))
    operands[1] = simplify_gen_subreg (QImode, operands[1], SImode, 0);
  return "mov{b}\t{%b1, %h0|%h0, %b1}";
}
}

static const char *
output_97 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2651 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char *
output_98 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2671 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char *
output_99 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2689 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char *
output_100 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2710 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char *
output_101 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2726 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char *
output_102 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2747 "../../gcc/config/i386/i386.md"
{
  /* Anything else should be already split before reg-stack.  */
  gcc_assert (which_alternative == 1);
  return "push{q}\t%q1";
}
}

static const char *
output_103 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2760 "../../gcc/config/i386/i386.md"
{
  /* Anything else should be already split before reg-stack.  */
  gcc_assert (which_alternative == 1);
  return "push{l}\t%1";
}
}

static const char *
output_104 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2826 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      /* Handle misaligned load/store since we
         don't have movmisaligntf pattern. */
      if (misaligned_operand (operands[0], TFmode)
	  || misaligned_operand (operands[1], TFmode))
	{
	  if (get_attr_mode (insn) == MODE_V4SF)
	    return "%vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqu\t{%1, %0|%0, %1}";
	}
      else
	{
	  if (get_attr_mode (insn) == MODE_V4SF)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";
	}

    case 2:
      return standard_sse_constant_opcode (insn, operands[1]);

    case 3:
    case 4:
	return "#";

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_105 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2889 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      return output_387_reg_move (insn, operands);

    case 2:
      return standard_80387_constant_opcode (operands[1]);

    case 3:
    case 4:
      return "#";

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_106 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2925 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      return output_387_reg_move (insn, operands);

    case 2:
      return standard_80387_constant_opcode (operands[1]);

    case 3:
    case 4:
      return "mov{q}\t{%1, %0|%0, %1}";

    case 5:
      return "movabs{q}\t{%1, %0|%0, %1}";

    case 6:
      return "#";

    case 7:
      return standard_sse_constant_opcode (insn, operands[1]);

    case 8:
    case 9:
    case 10:
      switch (get_attr_mode (insn))
	{
	case MODE_V2DF:
	  if (!TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovapd\t{%1, %0|%0, %1}";
	case MODE_V4SF:
	  return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_DI:
	  return "%vmovq\t{%1, %0|%0, %1}";
	case MODE_DF:
	  if (TARGET_AVX && REG_P (operands[0]) && REG_P (operands[1]))
	    return "vmovsd\t{%1, %0, %0|%0, %0, %1}";
	  return "%vmovsd\t{%1, %0|%0, %1}";
	case MODE_V1DF:
	  return "%vmovlpd\t{%1, %d0|%d0, %1}";
	case MODE_V2SF:
	  return "%vmovlps\t{%1, %d0|%d0, %1}";
	default:
	  gcc_unreachable ();
	}

    case 11:
    case 12:
      /* Handle broken assemblers that require movd instead of movq.  */
      return "%vmovd\t{%1, %0|%0, %1}";

    default:
      gcc_unreachable();
    }
}
}

static const char *
output_107 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3068 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      return output_387_reg_move (insn, operands);

    case 2:
      return standard_80387_constant_opcode (operands[1]);

    case 3:
    case 4:
      return "#";

    case 5:
    case 9:
      return standard_sse_constant_opcode (insn, operands[1]);

    case 6:
    case 7:
    case 8:
    case 10:
    case 11:
    case 12:
      switch (get_attr_mode (insn))
	{
	case MODE_V2DF:
	  if (!TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovapd\t{%1, %0|%0, %1}";
	case MODE_V4SF:
	  return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_DI:
	  return "%vmovq\t{%1, %0|%0, %1}";
	case MODE_DF:
	  if (TARGET_AVX && REG_P (operands[0]) && REG_P (operands[1]))
	    return "vmovsd\t{%1, %0, %0|%0, %0, %1}";
	  return "%vmovsd\t{%1, %0|%0, %1}";
	case MODE_V1DF:
	  return "%vmovlpd\t{%1, %d0|%d0, %1}";
	case MODE_V2SF:
	  return "%vmovlps\t{%1, %d0|%d0, %1}";
	default:
	  gcc_unreachable ();
	}

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_108 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3200 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      return output_387_reg_move (insn, operands);

    case 2:
      return standard_80387_constant_opcode (operands[1]);

    case 3:
    case 4:
      return "mov{l}\t{%1, %0|%0, %1}";

    case 5:
      return standard_sse_constant_opcode (insn, operands[1]);

    case 6:
      if (get_attr_mode (insn) == MODE_V4SF)
	return "%vmovaps\t{%1, %0|%0, %1}";
      if (TARGET_AVX)
	return "vmovss\t{%1, %0, %0|%0, %0, %1}";

    case 7:
    case 8:
      return "%vmovss\t{%1, %0|%0, %1}";

    case 9:
    case 10:
    case 14:
    case 15:
      return "movd\t{%1, %0|%0, %1}";

    case 11:
      return "movq\t{%1, %0|%0, %1}";

    case 12:
    case 13:
      return "%vmovd\t{%1, %0|%0, %1}";

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_109 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3363 "../../gcc/config/i386/i386.md"
{
  if (STACK_TOP_P (operands[0]))
    return "fxch\t%1";
  else
    return "fxch\t%0";
}
}

static const char *
output_110 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3378 "../../gcc/config/i386/i386.md"
{
  if (STACK_TOP_P (operands[0]))
    return "fxch\t%1";
  else
    return "fxch\t%0";
}
}

static const char *
output_111 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3378 "../../gcc/config/i386/i386.md"
{
  if (STACK_TOP_P (operands[0]))
    return "fxch\t%1";
  else
    return "fxch\t%0";
}
}

static const char * const output_112[] = {
  "mov{l}\t{%1, %k0|%k0, %1}",
  "#",
  "movd\t{%1, %0|%0, %1}",
  "movd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
};

static const char * const output_113[] = {
  "#",
  "#",
  "#",
  "movd\t{%1, %0|%0, %1}",
  "movd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
};

static const char * const output_124[] = {
  "{cltq|cdqe}",
  "movs{lq|x}\t{%1, %0|%0, %1}",
};

static const char *
output_128 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3702 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_prefix_0f (insn))
    {
    case 0:
      return "{cwtl|cwde}";
    default:
      return "movs{wl|x}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_129 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3730 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_prefix_0f (insn))
    {
    case 0:
      return "{cwtl|cwde}";
    default:
      return "movs{wl|x}\t{%1, %k0|%k0, %1}";
    }
}
}

static const char *
output_132 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3773 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_prefix_0f (insn))
    {
    case 0:
      return "{cbtw|cbw}";
    default:
      return "movs{bw|x}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_133 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3887 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      return output_387_reg_move (insn, operands);

    case 2:
      return "%vcvtss2sd\t{%1, %d0|%d0, %1}";

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_135 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3918 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_136 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3947 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_137 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3947 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_138 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4036 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
      return output_387_reg_move (insn, operands);
    case 1:
      return "%vcvtsd2ss\t{%1, %d0|%d0, %1}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_140 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4068 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_141 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4078 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
      return output_387_reg_move (insn, operands);
    case 1:
      return "%vcvtsd2ss\t{%1, %d0|%d0, %1}";

    default:
      return "#";
    }
}
}

static const char *
output_142 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4102 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
      return output_387_reg_move (insn, operands);

    default:
      return "#";
    }
}
}

static const char *
output_143 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4123 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_144 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4169 "../../gcc/config/i386/i386.md"
{
  gcc_assert (!which_alternative);
  return output_387_reg_move (insn, operands);
}
}

static const char *
output_145 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4183 "../../gcc/config/i386/i386.md"
{
  gcc_assert (!which_alternative);
  return output_387_reg_move (insn, operands);
}
}

static const char *
output_146 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4197 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_147 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4197 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_148 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4206 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_149 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4206 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_159 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4464 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, true);
}

static const char *
output_160 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4464 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, true);
}

static const char *
output_161 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4464 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, true);
}

static const char *
output_168 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4548 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char *
output_170 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4603 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char *
output_171 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4603 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char * const output_193[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_194[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_199[] = {
  "fild%Z1\t%1",
  "%vcvtsi2ss\t{%1, %d0|%d0, %1}",
  "%vcvtsi2ss\t{%1, %d0|%d0, %1}",
};

static const char * const output_200[] = {
  "fild%Z1\t%1",
  "%vcvtsi2sd\t{%1, %d0|%d0, %1}",
  "%vcvtsi2sd\t{%1, %d0|%d0, %1}",
};

static const char * const output_201[] = {
  "fild%Z1\t%1",
  "%vcvtsi2ss{q}\t{%1, %d0|%d0, %1}",
  "%vcvtsi2ss{q}\t{%1, %d0|%d0, %1}",
};

static const char * const output_202[] = {
  "fild%Z1\t%1",
  "%vcvtsi2sd{q}\t{%1, %d0|%d0, %1}",
  "%vcvtsi2sd{q}\t{%1, %d0|%d0, %1}",
};

static const char * const output_203[] = {
  "fild%Z1\t%1",
  "%vcvtsi2ss\t{%1, %d0|%d0, %1}",
};

static const char * const output_204[] = {
  "fild%Z1\t%1",
  "%vcvtsi2sd\t{%1, %d0|%d0, %1}",
};

static const char * const output_205[] = {
  "fild%Z1\t%1",
  "%vcvtsi2ss{q}\t{%1, %d0|%d0, %1}",
};

static const char * const output_206[] = {
  "fild%Z1\t%1",
  "%vcvtsi2sd{q}\t{%1, %d0|%d0, %1}",
};

static const char * const output_223[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_224[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_225[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_226[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_227[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_228[] = {
  "fild%Z1\t%1",
  "#",
};

static const char *
output_241 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5401 "../../gcc/config/i386/i386.md"
{
  rtx addr = operands[1];

  if (GET_CODE (addr) == SUBREG)
    {
      gcc_assert (TARGET_64BIT);
      gcc_assert (SImode == SImode);
      gcc_assert (GET_MODE (SUBREG_REG (addr)) == DImode);
      return "lea{l}\t{%E1, %0|%0, %E1}";
    }
  else if (GET_CODE (addr) == ZERO_EXTEND
	   || GET_CODE (addr) == AND)
    {
      gcc_assert (TARGET_64BIT);
      gcc_assert (SImode == DImode);
      return "lea{l}\t{%E1, %k0|%k0, %E1}";
    }
  else 
    return "lea{l}\t{%E1, %0|%0, %E1}";
}
}

static const char *
output_242 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5401 "../../gcc/config/i386/i386.md"
{
  rtx addr = operands[1];

  if (GET_CODE (addr) == SUBREG)
    {
      gcc_assert (TARGET_64BIT);
      gcc_assert (DImode == SImode);
      gcc_assert (GET_MODE (SUBREG_REG (addr)) == DImode);
      return "lea{l}\t{%E1, %0|%0, %E1}";
    }
  else if (GET_CODE (addr) == ZERO_EXTEND
	   || GET_CODE (addr) == AND)
    {
      gcc_assert (TARGET_64BIT);
      gcc_assert (DImode == DImode);
      return "lea{l}\t{%E1, %k0|%k0, %E1}";
    }
  else 
    return "lea{q}\t{%E1, %0|%0, %E1}";
}
}

static const char *
output_248 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5495 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";

    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
        return "inc{l}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%0";
	}

    default:
      /* For most processors, ADD is faster than LEA.  This alternative
	 was added to use ADD as much as possible.  */
      if (which_alternative == 2)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}
        
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], SImode))
        return "sub{l}\t{%2, %0|%0, %2}";

      return "add{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_249 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5495 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";

    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
        return "inc{q}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{q}\t%0";
	}

    default:
      /* For most processors, ADD is faster than LEA.  This alternative
	 was added to use ADD as much as possible.  */
      if (which_alternative == 2)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}
        
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], DImode))
        return "sub{q}\t{%2, %0|%0, %2}";

      return "add{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_250 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5554 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";

    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{l}\t%k0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%k0";
	}

    default:
      /* For most processors, ADD is faster than LEA.  This alternative
	 was added to use ADD as much as possible.  */
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      if (x86_maybe_negate_const_int (&operands[2], SImode))
        return "sub{l}\t{%2, %k0|%k0, %2}";

      return "add{l}\t{%2, %k0|%k0, %2}";
    }
}
}

static const char *
output_251 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5604 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";

    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
	return "inc{w}\t%0";
      else
	{
	  gcc_assert (operands[2] == constm1_rtx);
	  return "dec{w}\t%0";
	}

    default:
      /* For most processors, ADD is faster than LEA.  This alternative
	 was added to use ADD as much as possible.  */
      if (which_alternative == 2)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], HImode))
	return "sub{w}\t{%2, %0|%0, %2}";

      return "add{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_252 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5657 "../../gcc/config/i386/i386.md"
{
  bool widen = (which_alternative == 3 || which_alternative == 4);

  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";

    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
	return widen ? "inc{l}\t%k0" : "inc{b}\t%0";
      else
	{
	  gcc_assert (operands[2] == constm1_rtx);
	  return widen ? "dec{l}\t%k0" : "dec{b}\t%0";
	}

    default:
      /* For most processors, ADD is faster than LEA.  These alternatives
	 were added to use ADD as much as possible.  */
      if (which_alternative == 2 || which_alternative == 4)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], QImode))
	{
	  if (widen)
	    return "sub{l}\t{%2, %k0|%k0, %2}";
	  else
	    return "sub{b}\t{%2, %0|%0, %2}";
	}
      if (widen)
        return "add{l}\t{%k2, %k0|%k0, %k2}";
      else
        return "add{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_253 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5719 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[1] == const1_rtx)
	return "inc{b}\t%0";
      else
	{
	  gcc_assert (operands[1] == constm1_rtx);
	  return "dec{b}\t%0";
	}

    default:
      if (x86_maybe_negate_const_int (&operands[1], QImode))
	return "sub{b}\t{%1, %0|%0, %1}";

      return "add{b}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_254 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5807 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{b}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{b}\t%0";
	}

    default:
      if (which_alternative == 2)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}
        
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], QImode))
        return "sub{b}\t{%2, %0|%0, %2}";

      return "add{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_255 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5807 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{w}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{w}\t%0";
	}

    default:
      if (which_alternative == 2)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}
        
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], HImode))
        return "sub{w}\t{%2, %0|%0, %2}";

      return "add{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_256 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5807 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{l}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%0";
	}

    default:
      if (which_alternative == 2)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}
        
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], SImode))
        return "sub{l}\t{%2, %0|%0, %2}";

      return "add{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_257 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5807 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{q}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{q}\t%0";
	}

    default:
      if (which_alternative == 2)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}
        
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], DImode))
        return "sub{q}\t{%2, %0|%0, %2}";

      return "add{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_258 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5855 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{l}\t%k0";
      else
	{
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%k0";
	}

    default:
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      if (x86_maybe_negate_const_int (&operands[2], SImode))
        return "sub{l}\t{%2, %k0|%k0, %2}";

      return "add{l}\t{%2, %k0|%k0, %2}";
    }
}
}

static const char *
output_259 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5899 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{b}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{b}\t%0";
	}

    default:
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], QImode))
        return "sub{b}\t{%2, %0|%0, %2}";

      return "add{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_260 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5899 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{w}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{w}\t%0";
	}

    default:
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], HImode))
        return "sub{w}\t{%2, %0|%0, %2}";

      return "add{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_261 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5899 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{l}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%0";
	}

    default:
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], SImode))
        return "sub{l}\t{%2, %0|%0, %2}";

      return "add{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_262 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5899 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{q}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{q}\t%0";
	}

    default:
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], DImode))
        return "sub{q}\t{%2, %0|%0, %2}";

      return "add{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_263 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5946 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{l}\t%k0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%k0";
	}

    default:
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      if (x86_maybe_negate_const_int (&operands[2], SImode))
        return "sub{l}\t{%2, %k0|%k0, %2}";

      return "add{l}\t{%2, %k0|%k0, %2}";
    }
}
}

static const char *
output_264 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5997 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == constm1_rtx)
        return "inc{q}\t%0";
      else
        {
	  gcc_assert (operands[2] == const1_rtx);
          return "dec{q}\t%0";
	}

    default:
      if (x86_maybe_negate_const_int (&operands[2], DImode))
	return "add{q}\t{%2, %0|%0, %2}";

      return "sub{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_265 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6041 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == constm1_rtx)
        return "inc{b}\t%0";
      else
        {
	  gcc_assert (operands[2] == const1_rtx);
          return "dec{b}\t%0";
	}

    default:
      if (x86_maybe_negate_const_int (&operands[2], QImode))
	return "add{b}\t{%2, %0|%0, %2}";

      return "sub{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_266 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6041 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == constm1_rtx)
        return "inc{w}\t%0";
      else
        {
	  gcc_assert (operands[2] == const1_rtx);
          return "dec{w}\t%0";
	}

    default:
      if (x86_maybe_negate_const_int (&operands[2], HImode))
	return "add{w}\t{%2, %0|%0, %2}";

      return "sub{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_267 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6041 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == constm1_rtx)
        return "inc{l}\t%0";
      else
        {
	  gcc_assert (operands[2] == const1_rtx);
          return "dec{l}\t%0";
	}

    default:
      if (x86_maybe_negate_const_int (&operands[2], SImode))
	return "add{l}\t{%2, %0|%0, %2}";

      return "sub{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_268 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6081 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{b}\t%0";
      else
        {
          gcc_assert (operands[2] == constm1_rtx);
          return "dec{b}\t%0";
	}

    default:
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], QImode))
        return "sub{b}\t{%2, %0|%0, %2}";

      return "add{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_269 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6081 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{w}\t%0";
      else
        {
          gcc_assert (operands[2] == constm1_rtx);
          return "dec{w}\t%0";
	}

    default:
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], HImode))
        return "sub{w}\t{%2, %0|%0, %2}";

      return "add{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_270 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6081 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{l}\t%0";
      else
        {
          gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%0";
	}

    default:
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], SImode))
        return "sub{l}\t{%2, %0|%0, %2}";

      return "add{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_271 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6081 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
        return "inc{q}\t%0";
      else
        {
          gcc_assert (operands[2] == constm1_rtx);
          return "dec{q}\t%0";
	}

    default:
      if (which_alternative == 1)
	{
	  rtx tmp;
	  tmp = operands[1], operands[1] = operands[2], operands[2] = tmp;
	}

      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], DImode))
        return "sub{q}\t{%2, %0|%0, %2}";

      return "add{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_272 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6130 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{b}\t%h0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{b}\t%h0";
        }

    default:
      return "add{b}\t{%2, %h0|%h0, %2}";
    }
}
}

static const char *
output_273 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6165 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{b}\t%h0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{b}\t%h0";
	}

    default:
      return "add{b}\t{%2, %h0|%h0, %2}";
    }
}
}

static const char * const output_326[] = {
  "imul{l}\t{%2, %1, %0|%0, %1, %2}",
  "imul{l}\t{%2, %1, %0|%0, %1, %2}",
  "imul{l}\t{%2, %0|%0, %2}",
};

static const char * const output_327[] = {
  "imul{q}\t{%2, %1, %0|%0, %1, %2}",
  "imul{q}\t{%2, %1, %0|%0, %1, %2}",
  "imul{q}\t{%2, %0|%0, %2}",
};

static const char * const output_328[] = {
  "imul{l}\t{%2, %1, %k0|%k0, %1, %2}",
  "imul{l}\t{%2, %1, %k0|%k0, %1, %2}",
  "imul{l}\t{%2, %k0|%k0, %2}",
};

static const char * const output_329[] = {
  "imul{w}\t{%2, %1, %0|%0, %1, %2}",
  "imul{w}\t{%2, %1, %0|%0, %1, %2}",
  "imul{w}\t{%2, %0|%0, %2}",
};

static const char * const output_333[] = {
  "mul{l}\t%2",
  "#",
};

static const char * const output_334[] = {
  "mul{q}\t%2",
  "#",
};

static const char * const output_363[] = {
  "test{l}\t{%k1, %k0|%k0, %k1}",
  "test{l}\t{%k1, %k0|%k0, %k1}",
  "test{q}\t{%1, %0|%0, %1}",
  "test{q}\t{%1, %0|%0, %1}",
  "test{q}\t{%1, %0|%0, %1}",
};

static const char *
output_364 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7424 "../../gcc/config/i386/i386.md"
{
  if (which_alternative == 3)
    {
      if (CONST_INT_P (operands[1]) && INTVAL (operands[1]) < 0)
	operands[1] = GEN_INT (INTVAL (operands[1]) & 0xff);
      return "test{l}\t{%1, %k0|%k0, %1}";
    }
  return "test{b}\t{%1, %0|%0, %1}";
}
}

static const char *
output_374 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7702 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      {
	enum machine_mode mode;

	gcc_assert (CONST_INT_P (operands[2]));
	if (INTVAL (operands[2]) == (HOST_WIDE_INT) 0xffffffff)
	  mode = SImode;
	else if (INTVAL (operands[2]) == 0xffff)
	  mode = HImode;
	else
	  {
	    gcc_assert (INTVAL (operands[2]) == 0xff);
	    mode = QImode;
	  }

	operands[1] = gen_lowpart (mode, operands[1]);
	if (mode == SImode)
	  return "mov{l}\t{%1, %k0|%k0, %1}";
	else if (mode == HImode)
	  return "movz{wl|x}\t{%1, %k0|%k0, %1}";
	else
	  return "movz{bl|x}\t{%1, %k0|%k0, %1}";
      }

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (get_attr_mode (insn) == MODE_SI)
	return "and{l}\t{%k2, %k0|%k0, %k2}";
      else
	return "and{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_375 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7754 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      {
	enum machine_mode mode;

	gcc_assert (CONST_INT_P (operands[2]));
        if (INTVAL (operands[2]) == 0xffff)
	  mode = HImode;
	else
	  {
	    gcc_assert (INTVAL (operands[2]) == 0xff);
	    mode = QImode;
	  }

	operands[1] = gen_lowpart (mode, operands[1]);
	if (mode == HImode)
	  return "movz{wl|x}\t{%1, %0|%0, %1}";
	else
	  return "movz{bl|x}\t{%1, %0|%0, %1}";
      }

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      return "and{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_377 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7811 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      gcc_assert (CONST_INT_P (operands[2]));
      gcc_assert (INTVAL (operands[2]) == 0xff);
      return "movz{bl|x}\t{%b1, %k0|%k0, %b1}";

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));

      return "and{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char * const output_378[] = {
  "and{b}\t{%2, %0|%0, %2}",
  "and{b}\t{%2, %0|%0, %2}",
  "and{l}\t{%k2, %k0|%k0, %k2}",
};

static const char * const output_380[] = {
  "and{l}\t{%k2, %k0|%k0, %k2}",
  "and{q}\t{%2, %0|%0, %2}",
  "and{q}\t{%2, %0|%0, %2}",
};

static const char *
output_381 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7930 "../../gcc/config/i386/i386.md"
{
  if (which_alternative == 2)
    {
      if (CONST_INT_P (operands[2]) && INTVAL (operands[2]) < 0)
        operands[2] = GEN_INT (INTVAL (operands[2]) & 0xff);
      return "and{l}\t{%2, %k0|%k0, %2}";
    }
  return "and{b}\t{%2, %0|%0, %2}";
}
}

static const char * const output_398[] = {
  "or{b}\t{%2, %0|%0, %2}",
  "or{b}\t{%2, %0|%0, %2}",
  "or{l}\t{%k2, %k0|%k0, %k2}",
};

static const char * const output_399[] = {
  "xor{b}\t{%2, %0|%0, %2}",
  "xor{b}\t{%2, %0|%0, %2}",
  "xor{l}\t{%k2, %k0|%k0, %k2}",
};

static const char * const output_479[] = {
  "not{b}\t%0",
  "not{l}\t%k0",
};

static const char *
output_494 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9103 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
    case TYPE_ISHIFTX:
      return "#";

    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      return "add{l}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{l}\t%0";
      else
	return "sal{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_495 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9103 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
    case TYPE_ISHIFTX:
      return "#";

    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      return "add{q}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{q}\t%0";
      else
	return "sal{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_497 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9174 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
    case TYPE_ISHIFTX:
      return "#";

    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{l}\t%k0, %k0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{l}\t%k0";
      else
	return "sal{l}\t{%2, %k0|%k0, %2}";
    }
}
}

static const char *
output_498 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9233 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";

    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{w}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{w}\t%0";
      else
	return "sal{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_499 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9278 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";

    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      if (REG_P (operands[1]) && !ANY_QI_REG_P (operands[1]))
        return "add{l}\t%k0, %k0";
      else
        return "add{b}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	{
	  if (get_attr_mode (insn) == MODE_SI)
	    return "sal{l}\t%k0";
	  else
	    return "sal{b}\t%0";
	}
      else
	{
	  if (get_attr_mode (insn) == MODE_SI)
	    return "sal{l}\t{%2, %k0|%k0, %2}";
	  else
	    return "sal{b}\t{%2, %0|%0, %2}";
	}
    }
}
}

static const char *
output_500 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9339 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[1] == const1_rtx);
      return "add{b}\t%0, %0";

    default:
      if (operands[1] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{b}\t%0";
      else
	return "sal{b}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_501 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9435 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{b}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{b}\t%0";
      else
	return "sal{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_502 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9435 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{w}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{w}\t%0";
      else
	return "sal{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_503 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9435 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{l}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{l}\t%0";
      else
	return "sal{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_504 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9435 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{q}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{q}\t%0";
      else
	return "sal{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_505 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9484 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{l}\t%k0, %k0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{l}\t%k0";
      else
	return "sal{l}\t{%2, %k0|%k0, %2}";
    }
}
}

static const char *
output_506 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9529 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{b}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{b}\t%0";
      else
	return "sal{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_507 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9529 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{w}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{w}\t%0";
      else
	return "sal{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_508 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9529 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{l}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{l}\t%0";
      else
	return "sal{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_509 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9529 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{q}\t%0, %0";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{q}\t%0";
      else
	return "sal{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char * const output_520[] = {
  "{cqto|cqo}",
  "sar{q}\t{%2, %0|%0, %2}",
};

static const char * const output_521[] = {
  "{cltd|cdq}",
  "sar{l}\t{%2, %0|%0, %2}",
};

static const char * const output_522[] = {
  "{cltd|cdq}",
  "sar{l}\t{%2, %k0|%k0, %2}",
};

static const char *
output_527 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9756 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ISHIFTX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "shr{l}\t%0";
      else
	return "shr{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_528 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9756 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ISHIFTX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sar{l}\t%0";
      else
	return "sar{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_529 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9756 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ISHIFTX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "shr{q}\t%0";
      else
	return "shr{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_530 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9756 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ISHIFTX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sar{q}\t%0";
      else
	return "sar{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_533 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9809 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ISHIFTX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "shr{l}\t%k0";
      else
	return "shr{l}\t{%2, %k0|%k0, %2}";
    }
}
}

static const char *
output_534 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9809 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ISHIFTX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sar{l}\t%k0";
      else
	return "sar{l}\t{%2, %k0|%k0, %2}";
    }
}
}

static const char *
output_535 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9853 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{b}\t%0";
  else
    return "shr{b}\t{%2, %0|%0, %2}";
}
}

static const char *
output_536 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9853 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{b}\t%0";
  else
    return "sar{b}\t{%2, %0|%0, %2}";
}
}

static const char *
output_537 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9853 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{w}\t%0";
  else
    return "shr{w}\t{%2, %0|%0, %2}";
}
}

static const char *
output_538 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9853 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{w}\t%0";
  else
    return "sar{w}\t{%2, %0|%0, %2}";
}
}

static const char *
output_539 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9879 "../../gcc/config/i386/i386.md"
{
  if (operands[1] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{b}\t%0";
  else
    return "shr{b}\t{%1, %0|%0, %1}";
}
}

static const char *
output_540 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9879 "../../gcc/config/i386/i386.md"
{
  if (operands[1] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{b}\t%0";
  else
    return "sar{b}\t{%1, %0|%0, %1}";
}
}

static const char *
output_541 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9914 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{b}\t%0";
  else
    return "shr{b}\t{%2, %0|%0, %2}";
}
}

static const char *
output_542 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9914 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{b}\t%0";
  else
    return "sar{b}\t{%2, %0|%0, %2}";
}
}

static const char *
output_543 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9914 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{w}\t%0";
  else
    return "shr{w}\t{%2, %0|%0, %2}";
}
}

static const char *
output_544 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9914 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{w}\t%0";
  else
    return "sar{w}\t{%2, %0|%0, %2}";
}
}

static const char *
output_545 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9914 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{l}\t%0";
  else
    return "shr{l}\t{%2, %0|%0, %2}";
}
}

static const char *
output_546 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9914 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{l}\t%0";
  else
    return "sar{l}\t{%2, %0|%0, %2}";
}
}

static const char *
output_547 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9914 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{q}\t%0";
  else
    return "shr{q}\t{%2, %0|%0, %2}";
}
}

static const char *
output_548 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9914 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{q}\t%0";
  else
    return "sar{q}\t{%2, %0|%0, %2}";
}
}

static const char *
output_549 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9946 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{l}\t%k0";
  else
    return "shr{l}\t{%2, %k0|%k0, %2}";
}
}

static const char *
output_550 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9946 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{l}\t%k0";
  else
    return "sar{l}\t{%2, %k0|%k0, %2}";
}
}

static const char *
output_551 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9976 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{b}\t%0";
  else
    return "shr{b}\t{%2, %0|%0, %2}";
}
}

static const char *
output_552 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9976 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{b}\t%0";
  else
    return "sar{b}\t{%2, %0|%0, %2}";
}
}

static const char *
output_553 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9976 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{w}\t%0";
  else
    return "shr{w}\t{%2, %0|%0, %2}";
}
}

static const char *
output_554 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9976 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{w}\t%0";
  else
    return "sar{w}\t{%2, %0|%0, %2}";
}
}

static const char *
output_555 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9976 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{l}\t%0";
  else
    return "shr{l}\t{%2, %0|%0, %2}";
}
}

static const char *
output_556 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9976 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{l}\t%0";
  else
    return "sar{l}\t{%2, %0|%0, %2}";
}
}

static const char *
output_557 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9976 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "shr{q}\t%0";
  else
    return "shr{q}\t{%2, %0|%0, %2}";
}
}

static const char *
output_558 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9976 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "sar{q}\t%0";
  else
    return "sar{q}\t{%2, %0|%0, %2}";
}
}

static const char *
output_569 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10136 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ROTATEX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "rol{l}\t%0";
      else
	return "rol{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_570 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10136 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ROTATEX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "ror{l}\t%0";
      else
	return "ror{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_571 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10136 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ROTATEX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "rol{q}\t%0";
      else
	return "rol{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_572 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10136 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ROTATEX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "ror{q}\t%0";
      else
	return "ror{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_574 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10202 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ROTATEX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "rol{l}\t%k0";
      else
	return "rol{l}\t{%2, %k0|%k0, %2}";
    }
}
}

static const char *
output_575 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10202 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ROTATEX:
      return "#";

    default:
      if (operands[2] == const1_rtx
	  && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "ror{l}\t%k0";
      else
	return "ror{l}\t{%2, %k0|%k0, %2}";
    }
}
}

static const char *
output_576 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10259 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "rol{b}\t%0";
  else
    return "rol{b}\t{%2, %0|%0, %2}";
}
}

static const char *
output_577 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10259 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "ror{b}\t%0";
  else
    return "ror{b}\t{%2, %0|%0, %2}";
}
}

static const char *
output_578 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10259 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "rol{w}\t%0";
  else
    return "rol{w}\t{%2, %0|%0, %2}";
}
}

static const char *
output_579 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10259 "../../gcc/config/i386/i386.md"
{
  if (operands[2] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "ror{w}\t%0";
  else
    return "ror{w}\t{%2, %0|%0, %2}";
}
}

static const char *
output_580 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10285 "../../gcc/config/i386/i386.md"
{
  if (operands[1] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "rol{b}\t%0";
  else
    return "rol{b}\t{%1, %0|%0, %1}";
}
}

static const char *
output_581 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10285 "../../gcc/config/i386/i386.md"
{
  if (operands[1] == const1_rtx
      && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    return "ror{b}\t%0";
  else
    return "ror{b}\t{%1, %0|%0, %1}";
}
}

static const char * const output_592[] = {
  "cmp%D3ss\t{%2, %0|%0, %2}",
  "vcmp%D3ss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_593[] = {
  "cmp%D3sd\t{%2, %0|%0, %2}",
  "vcmp%D3sd\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_616 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11282 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[0]);
}

static const char *
output_617 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11282 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[0]);
}

static const char *
output_619 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11327 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[0]);
}

static const char *
output_622 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11346 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[0]);
}

static const char *
output_623 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11346 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[0]);
}

static const char *
output_625 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11384 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[0]);
}

static const char *
output_627 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11409 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[0]);
}

static const char *
output_630 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11456 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[1]);
}

static const char *
output_631 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11456 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[1]);
}

static const char *
output_634 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11477 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[1]);
}

static const char *
output_635 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11477 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[1]);
}

static const char *
output_637 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11524 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[1]);
}

static const char *
output_639 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11565 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[1]);
}

static const char *
output_641 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11592 "../../gcc/config/i386/i386.md"
 return ix86_output_call_insn (insn, operands[1]);
}

static const char *
output_650 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11765 "../../gcc/config/i386/i386.md"
{
  int num = INTVAL (operands[0]);

  gcc_assert (num >= 1 && num <= 8);

  while (num--)
    fputs ("\tnop\n", asm_out_file);

  return "";
}
}

static const char *
output_651 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11786 "../../gcc/config/i386/i386.md"
{
#ifdef ASM_OUTPUT_MAX_SKIP_PAD
  ASM_OUTPUT_MAX_SKIP_PAD (asm_out_file, 4, (int)INTVAL (operands[0]));
#else
  /* It is tempting to use ASM_OUTPUT_ALIGN here, but we don't want to do that.
     The align insn is used to avoid 3 jump instructions in the row to improve
     branch prediction and the benefits hardly outweigh the cost of extra 8
     nops on the average inserted by full alignment pseudo operation.  */
#endif
  return "";
}
}

static const char *
output_652 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11809 "../../gcc/config/i386/i386.md"
 return output_set_got (operands[0], NULL_RTX);
}

static const char *
output_653 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11819 "../../gcc/config/i386/i386.md"
 return output_set_got (operands[0], operands[1]);
}

static const char *
output_660 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11922 "../../gcc/config/i386/i386.md"
{
  if (operands[0] == const0_rtx)
    return "ret";
  else
    return "ret\t%0";
}
}

static const char *
output_664 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12031 "../../gcc/config/i386/i386.md"
{
  if (TARGET_BMI)
    return "tzcnt{w}\t{%1, %0|%0, %1}";
  else
    return "bsf{w}\t{%1, %0|%0, %1}";
}
}

static const char *
output_665 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12031 "../../gcc/config/i386/i386.md"
{
  if (TARGET_BMI)
    return "tzcnt{l}\t{%1, %0|%0, %1}";
  else
    return "bsf{l}\t{%1, %0|%0, %1}";
}
}

static const char *
output_666 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12031 "../../gcc/config/i386/i386.md"
{
  if (TARGET_BMI)
    return "tzcnt{q}\t{%1, %0|%0, %1}";
  else
    return "bsf{q}\t{%1, %0|%0, %1}";
}
}

static const char *
output_686 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12178 "../../gcc/config/i386/i386.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) << 8 | INTVAL (operands[3]));
  return "bextr\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_687 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12178 "../../gcc/config/i386/i386.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) << 8 | INTVAL (operands[3]));
  return "bextr\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_709 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12346 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{w}\t{%1, %0|%0, %1}";
#endif
}
}

static const char *
output_710 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12346 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{l}\t{%1, %0|%0, %1}";
#endif
}
}

static const char *
output_711 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12346 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{q}\t{%1, %0|%0, %1}";
#endif
}
}

static const char *
output_712 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12366 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{w}\t{%1, %0|%0, %1}";
#endif
}
}

static const char *
output_713 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12366 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{l}\t{%1, %0|%0, %1}";
#endif
}
}

static const char *
output_714 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12366 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{q}\t{%1, %0|%0, %1}";
#endif
}
}

static const char *
output_715 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12385 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{l}\t{%1, %0|%0, %1}";
#endif
}
}

static const char * const output_716[] = {
  "bswap\t%0",
  "movbe\t{%1, %0|%0, %1}",
  "movbe\t{%1, %0|%0, %1}",
};

static const char * const output_717[] = {
  "bswap\t%0",
  "movbe\t{%1, %0|%0, %1}",
  "movbe\t{%1, %0|%0, %1}",
};

static const char * const output_720[] = {
  "xchg{b}\t{%h0, %b0|%b0, %h0}",
  "rol{w}\t{$8, %0|%0, 8}",
};

static const char *
output_725 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12586 "../../gcc/config/i386/i386.md"
{
  output_asm_insn
    ("lea{l}\t{%E2@tlsgd(,%1,1), %0|%0, %E2@tlsgd[%1*1]}", operands);
  if (TARGET_SUN_TLS)
#ifdef HAVE_AS_IX86_TLSGDPLT
    return "call\t%a2@tlsgdplt";
#else
    return "call\t%p3@plt";
#endif
  return "call\t%P3";
}
}

static const char *
output_726 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12619 "../../gcc/config/i386/i386.md"
{
  if (!TARGET_X32)
    fputs (ASM_BYTE "0x66\n", asm_out_file);
  output_asm_insn
    ("lea{q}\t{%E1@tlsgd(%%rip), %%rdi|rdi, %E1@tlsgd[rip]}", operands);
  fputs (ASM_SHORT "0x6666\n", asm_out_file);
  fputs ("\trex64\n", asm_out_file);
  if (TARGET_SUN_TLS)
    return "call\t%p2@plt";
  return "call\t%P2";
}
}

static const char *
output_727 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12653 "../../gcc/config/i386/i386.md"
{
  output_asm_insn
    ("lea{l}\t{%&@tlsldm(%1), %0|%0, %&@tlsldm[%1]}", operands);
  if (TARGET_SUN_TLS)
#ifdef HAVE_AS_IX86_TLSLDMPLT
    return "call\t%&@tlsldmplt";
#else
    return "call\t%p2@plt";
#endif
  return "call\t%P2";
}
}

static const char *
output_728 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12685 "../../gcc/config/i386/i386.md"
{
  output_asm_insn
    ("lea{q}\t{%&@tlsld(%%rip), %%rdi|rdi, %&@tlsld[rip]}", operands);
  if (TARGET_SUN_TLS)
    return "call\t%p1@plt";
  return "call\t%P1";
}
}

static const char *
output_738 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12815 "../../gcc/config/i386/i386.md"
{
  output_asm_insn
    ("mov{q}\t{%%fs:0, %0|%0, QWORD PTR fs:0}", operands);
  return "add{q}\t{%a1@gottpoff(%%rip), %0|%0, %a1@gottpoff[rip]}";
}
}

static const char *
output_745 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12969 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_746 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12969 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_747 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12990 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_748 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12990 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_749 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13007 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_750 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13007 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_751 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13022 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_752 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13022 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_754 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13060 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_755 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13060 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_756 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13082 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_757 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13082 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_758 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13102 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_759 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13102 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_760 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13102 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_761 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13102 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_762 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13122 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_763 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13122 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_764 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13122 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_765 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13122 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_766 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13142 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_767 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13160 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_768 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13179 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_769 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13196 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_770 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13210 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_771 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13227 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_772 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13227 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_773 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13245 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_774 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13245 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_775 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13263 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_776 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13263 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_777 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13280 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_778 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13280 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_779 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13298 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_780 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13298 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_781 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13360 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_782 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13360 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_821 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14703 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char *
output_825 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14762 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char *
output_826 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14762 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char *
output_834 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14963 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char *
output_836 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15022 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char *
output_837 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15022 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char *
output_845 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15221 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char *
output_847 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15280 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char *
output_848 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15280 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, false);
}

static const char * const output_898[] = {
  "cmov%O2%C1\t{%2, %0|%0, %2}",
  "cmov%O2%c1\t{%3, %0|%0, %3}",
};

static const char * const output_899[] = {
  "cmov%O2%C1\t{%2, %0|%0, %2}",
  "cmov%O2%c1\t{%3, %0|%0, %3}",
};

static const char * const output_900[] = {
  "cmov%O2%C1\t{%2, %0|%0, %2}",
  "cmov%O2%c1\t{%3, %0|%0, %3}",
};

static const char * const output_902[] = {
  "fcmov%F1\t{%2, %0|%0, %2}",
  "fcmov%f1\t{%3, %0|%0, %3}",
};

static const char * const output_903[] = {
  "fcmov%F1\t{%2, %0|%0, %2}",
  "fcmov%f1\t{%3, %0|%0, %3}",
  "cmov%O2%C1\t{%2, %0|%0, %2}",
  "cmov%O2%c1\t{%3, %0|%0, %3}",
};

static const char * const output_904[] = {
  "fcmov%F1\t{%2, %0|%0, %2}",
  "fcmov%f1\t{%3, %0|%0, %3}",
  "#",
  "#",
};

static const char * const output_905[] = {
  "fcmov%F1\t{%2, %0|%0, %2}",
  "fcmov%f1\t{%3, %0|%0, %3}",
  "cmov%O2%C1\t{%2, %0|%0, %2}",
  "cmov%O2%c1\t{%3, %0|%0, %3}",
};

static const char * const output_908[] = {
  "maxss\t{%2, %0|%0, %2}",
  "vmaxss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_909[] = {
  "minss\t{%2, %0|%0, %2}",
  "vminss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_910[] = {
  "maxsd\t{%2, %0|%0, %2}",
  "vmaxsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_911[] = {
  "minsd\t{%2, %0|%0, %2}",
  "vminsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_912[] = {
  "minss\t{%2, %0|%0, %2}",
  "vminss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_913[] = {
  "minsd\t{%2, %0|%0, %2}",
  "vminsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_914[] = {
  "maxss\t{%2, %0|%0, %2}",
  "vmaxss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_915[] = {
  "maxsd\t{%2, %0|%0, %2}",
  "vmaxsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_916 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16651 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOV:
      return "mov{l}\t{%1, %0|%0, %1}";

    case TYPE_ALU:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], SImode))
	return "sub{l}\t{%2, %0|%0, %2}";

      return "add{l}\t{%2, %0|%0, %2}";

    default:
      operands[2] = SET_SRC (XVECEXP (PATTERN (insn), 0, 0));
      return "lea{l}\t{%E2, %0|%0, %E2}";
    }
}
}

static const char *
output_917 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16651 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOV:
      return "mov{q}\t{%1, %0|%0, %1}";

    case TYPE_ALU:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (x86_maybe_negate_const_int (&operands[2], DImode))
	return "sub{q}\t{%2, %0|%0, %2}";

      return "add{q}\t{%2, %0|%0, %2}";

    default:
      operands[2] = SET_SRC (XVECEXP (PATTERN (insn), 0, 0));
      return "lea{q}\t{%E2, %0|%0, %E2}";
    }
}
}

static const char *
output_922 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16767 "../../gcc/config/i386/i386.md"
 return output_adjust_stack_and_probe (operands[0]);
}

static const char *
output_923 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16767 "../../gcc/config/i386/i386.md"
 return output_adjust_stack_and_probe (operands[0]);
}

static const char *
output_924 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16777 "../../gcc/config/i386/i386.md"
 return output_probe_stack_range (operands[0], operands[2]);
}

static const char *
output_925 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16777 "../../gcc/config/i386/i386.md"
 return output_probe_stack_range (operands[0], operands[2]);
}

static const char *
output_926 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 17658 "../../gcc/config/i386/i386.md"
{ return ASM_SHORT "0x0b0f"; }
}

static const char *
output_927 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 17690 "../../gcc/config/i386/i386.md"
{
  static const char * const patterns[4] = {
   "prefetchnta\t%a0", "prefetcht2\t%a0", "prefetcht1\t%a0", "prefetcht0\t%a0"
  };

  int locality = INTVAL (operands[1]);
  gcc_assert (IN_RANGE (locality, 0, 3));

  return patterns[locality];
}
}

static const char *
output_928 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 17711 "../../gcc/config/i386/i386.md"
{
  if (INTVAL (operands[1]) == 0)
    return "prefetch\t%a0";
  else
    return "prefetchw\t%a0";
}
}

static const char * const output_967[] = {
  "mov{q}\t{%1, %0|%0, %1}",
  "mov{q}\t{%1, %0|%0, %1}",
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "%vpxor\t%0, %d0",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
};

static const char * const output_968[] = {
  "mov{q}\t{%1, %0|%0, %1}",
  "mov{q}\t{%1, %0|%0, %1}",
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "%vpxor\t%0, %d0",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
};

static const char * const output_969[] = {
  "mov{q}\t{%1, %0|%0, %1}",
  "mov{q}\t{%1, %0|%0, %1}",
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "%vpxor\t%0, %d0",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
};

static const char * const output_970[] = {
  "mov{q}\t{%1, %0|%0, %1}",
  "mov{q}\t{%1, %0|%0, %1}",
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "%vpxor\t%0, %d0",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
};

static const char * const output_971[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "%vpxor\t%0, %d0",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovq\t{%1, %0|%0, %1}",
  "xorps\t%0, %0",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_972[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "%vpxor\t%0, %d0",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovq\t{%1, %0|%0, %1}",
  "xorps\t%0, %0",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_973[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "%vpxor\t%0, %d0",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovq\t{%1, %0|%0, %1}",
  "xorps\t%0, %0",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_974[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "%vpxor\t%0, %d0",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovq\t{%1, %0|%0, %1}",
  "xorps\t%0, %0",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_975[] = {
  "mov{q}\t{%1, %0|%0, %1}",
  "mov{q}\t{%1, %0|%0, %1}",
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "%vxorps\t%0, %d0",
  "%vmovaps\t{%1, %0|%0, %1}",
  "%vmovlps\t{%1, %d0|%d0, %1}",
  "%vmovlps\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
};

static const char * const output_976[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "%vxorps\t%0, %d0",
  "%vmovaps\t{%1, %0|%0, %1}",
  "%vmovlps\t{%1, %d0|%d0, %1}",
  "%vmovlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_979[] = {
  "pfsub\t{%2, %0|%0, %2}",
  "pfsubr\t{%1, %0|%0, %1}",
};

static const char * const output_1002[] = {
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1004[] = {
  "punpckhdq\t%0, %0",
  "unpckhps\t%0, %0",
  "#",
  "#",
  "#",
  "#",
};

static const char *
output_1066 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1283 "../../gcc/config/i386/mmx.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));
  if (MEM_P (operands[2]))
    return "pinsrw\t{%3, %2, %0|%0, %2, %3}";
  else
    return "pinsrw\t{%3, %k2, %0|%0, %k2, %3}";
}
}

static const char *
output_1068 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1330 "../../gcc/config/i386/mmx.md"
{
  int mask = 0;
  mask |= INTVAL (operands[2]) << 0;
  mask |= INTVAL (operands[3]) << 2;
  mask |= INTVAL (operands[4]) << 4;
  mask |= INTVAL (operands[5]) << 6;
  operands[2] = GEN_INT (mask);

  return "pshufw\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char * const output_1072[] = {
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1074[] = {
  "punpckhdq\t%0, %0",
  "punpckhdq\t%0, %0",
  "pshufd\t{$85, %1, %0|%0, %1, 85}",
  "unpckhps\t%0, %0",
  "#",
  "#",
  "#",
};

static const char *
output_1075 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1579 "../../gcc/config/i386/mmx.md"
{
  /* These two instructions have the same operation, but their encoding
     is different.  Prefer the one that is de facto standard.  */
  if (TARGET_SSE || TARGET_3DNOW_A)
    return "pavgb\t{%2, %0|%0, %2}";
  else
    return "pavgusb\t{%2, %0|%0, %2}";
}
}

static const char *
output_1083 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V32QImode)
		  || misaligned_operand (operands[1], V32QImode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V32QImode)
		  || misaligned_operand (operands[1], V32QImode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V32QImode)
		  || misaligned_operand (operands[1], V32QImode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1084 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V16QImode)
		  || misaligned_operand (operands[1], V16QImode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V16QImode)
		  || misaligned_operand (operands[1], V16QImode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V16QImode)
		  || misaligned_operand (operands[1], V16QImode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1085 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V16HImode)
		  || misaligned_operand (operands[1], V16HImode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V16HImode)
		  || misaligned_operand (operands[1], V16HImode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V16HImode)
		  || misaligned_operand (operands[1], V16HImode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1086 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V8HImode)
		  || misaligned_operand (operands[1], V8HImode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V8HImode)
		  || misaligned_operand (operands[1], V8HImode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V8HImode)
		  || misaligned_operand (operands[1], V8HImode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1087 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V8SImode)
		  || misaligned_operand (operands[1], V8SImode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V8SImode)
		  || misaligned_operand (operands[1], V8SImode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V8SImode)
		  || misaligned_operand (operands[1], V8SImode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1088 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4SImode)
		  || misaligned_operand (operands[1], V4SImode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4SImode)
		  || misaligned_operand (operands[1], V4SImode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4SImode)
		  || misaligned_operand (operands[1], V4SImode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1089 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4DImode)
		  || misaligned_operand (operands[1], V4DImode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4DImode)
		  || misaligned_operand (operands[1], V4DImode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4DImode)
		  || misaligned_operand (operands[1], V4DImode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1090 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V2DImode)
		  || misaligned_operand (operands[1], V2DImode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V2DImode)
		  || misaligned_operand (operands[1], V2DImode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V2DImode)
		  || misaligned_operand (operands[1], V2DImode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1091 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V2TImode)
		  || misaligned_operand (operands[1], V2TImode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V2TImode)
		  || misaligned_operand (operands[1], V2TImode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V2TImode)
		  || misaligned_operand (operands[1], V2TImode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1092 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V1TImode)
		  || misaligned_operand (operands[1], V1TImode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V1TImode)
		  || misaligned_operand (operands[1], V1TImode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V1TImode)
		  || misaligned_operand (operands[1], V1TImode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1093 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V8SFmode)
		  || misaligned_operand (operands[1], V8SFmode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V8SFmode)
		  || misaligned_operand (operands[1], V8SFmode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V8SFmode)
		  || misaligned_operand (operands[1], V8SFmode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1094 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4SFmode)
		  || misaligned_operand (operands[1], V4SFmode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4SFmode)
		  || misaligned_operand (operands[1], V4SFmode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4SFmode)
		  || misaligned_operand (operands[1], V4SFmode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1095 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4DFmode)
		  || misaligned_operand (operands[1], V4DFmode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4DFmode)
		  || misaligned_operand (operands[1], V4DFmode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V4DFmode)
		  || misaligned_operand (operands[1], V4DFmode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1096 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 428 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	case MODE_V4SF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V2DFmode)
		  || misaligned_operand (operands[1], V2DFmode)))
	    return "vmovups\t{%1, %0|%0, %1}";
	  else
	    return "%vmovaps\t{%1, %0|%0, %1}";

	case MODE_V4DF:
	case MODE_V2DF:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V2DFmode)
		  || misaligned_operand (operands[1], V2DFmode)))
	    return "vmovupd\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovapd\t{%1, %0|%0, %1}";

	case MODE_OI:
	case MODE_TI:
	  if (TARGET_AVX
	      && (misaligned_operand (operands[0], V2DFmode)
		  || misaligned_operand (operands[1], V2DFmode)))
	    return "vmovdqu\t{%1, %0|%0, %1}";
	  else if (TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	  else
	    return "%vmovdqa\t{%1, %0|%0, %1}";

	default:
	  gcc_unreachable ();
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char * const output_1119[] = {
  "addps\t{%2, %0|%0, %2}",
  "vaddps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1120[] = {
  "subps\t{%2, %0|%0, %2}",
  "vsubps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1121[] = {
  "addps\t{%2, %0|%0, %2}",
  "vaddps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1122[] = {
  "subps\t{%2, %0|%0, %2}",
  "vsubps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1123[] = {
  "addpd\t{%2, %0|%0, %2}",
  "vaddpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1124[] = {
  "subpd\t{%2, %0|%0, %2}",
  "vsubpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1125[] = {
  "addpd\t{%2, %0|%0, %2}",
  "vaddpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1126[] = {
  "subpd\t{%2, %0|%0, %2}",
  "vsubpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1127[] = {
  "addss\t{%2, %0|%0, %2}",
  "vaddss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1128[] = {
  "subss\t{%2, %0|%0, %2}",
  "vsubss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1129[] = {
  "addsd\t{%2, %0|%0, %2}",
  "vaddsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1130[] = {
  "subsd\t{%2, %0|%0, %2}",
  "vsubsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1131[] = {
  "mulps\t{%2, %0|%0, %2}",
  "vmulps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1132[] = {
  "mulps\t{%2, %0|%0, %2}",
  "vmulps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1133[] = {
  "mulpd\t{%2, %0|%0, %2}",
  "vmulpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1134[] = {
  "mulpd\t{%2, %0|%0, %2}",
  "vmulpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1135[] = {
  "mulss\t{%2, %0|%0, %2}",
  "vmulss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1136[] = {
  "mulsd\t{%2, %0|%0, %2}",
  "vmulsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1137[] = {
  "divps\t{%2, %0|%0, %2}",
  "vdivps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1138[] = {
  "divps\t{%2, %0|%0, %2}",
  "vdivps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1139[] = {
  "divpd\t{%2, %0|%0, %2}",
  "vdivpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1140[] = {
  "divpd\t{%2, %0|%0, %2}",
  "vdivpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1141[] = {
  "divss\t{%2, %0|%0, %2}",
  "vdivss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1142[] = {
  "divsd\t{%2, %0|%0, %2}",
  "vdivsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1145[] = {
  "rcpss\t{%1, %0|%0, %1}",
  "vrcpss\t{%1, %2, %0|%0, %2, %1}",
};

static const char * const output_1150[] = {
  "sqrtss\t{%1, %0|%0, %1}",
  "vsqrtss\t{%1, %2, %0|%0, %2, %1}",
};

static const char * const output_1151[] = {
  "sqrtsd\t{%1, %0|%0, %1}",
  "vsqrtsd\t{%1, %2, %0|%0, %2, %1}",
};

static const char * const output_1154[] = {
  "rsqrtss\t{%1, %0|%0, %1}",
  "vrsqrtss\t{%1, %2, %0|%0, %2, %1}",
};

static const char * const output_1155[] = {
  "maxps\t{%2, %0|%0, %2}",
  "vmaxps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1156[] = {
  "minps\t{%2, %0|%0, %2}",
  "vminps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1157[] = {
  "maxps\t{%2, %0|%0, %2}",
  "vmaxps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1158[] = {
  "minps\t{%2, %0|%0, %2}",
  "vminps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1159[] = {
  "maxpd\t{%2, %0|%0, %2}",
  "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1160[] = {
  "minpd\t{%2, %0|%0, %2}",
  "vminpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1161[] = {
  "maxpd\t{%2, %0|%0, %2}",
  "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1162[] = {
  "minpd\t{%2, %0|%0, %2}",
  "vminpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1163[] = {
  "maxps\t{%2, %0|%0, %2}",
  "vmaxps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1164[] = {
  "minps\t{%2, %0|%0, %2}",
  "vminps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1165[] = {
  "maxps\t{%2, %0|%0, %2}",
  "vmaxps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1166[] = {
  "minps\t{%2, %0|%0, %2}",
  "vminps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1167[] = {
  "maxpd\t{%2, %0|%0, %2}",
  "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1168[] = {
  "minpd\t{%2, %0|%0, %2}",
  "vminpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1169[] = {
  "maxpd\t{%2, %0|%0, %2}",
  "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1170[] = {
  "minpd\t{%2, %0|%0, %2}",
  "vminpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1171[] = {
  "maxss\t{%2, %0|%0, %2}",
  "vmaxss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1172[] = {
  "minss\t{%2, %0|%0, %2}",
  "vminss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1173[] = {
  "maxsd\t{%2, %0|%0, %2}",
  "vmaxsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1174[] = {
  "minsd\t{%2, %0|%0, %2}",
  "vminsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1175[] = {
  "minps\t{%2, %0|%0, %2}",
  "vminps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1176[] = {
  "minps\t{%2, %0|%0, %2}",
  "vminps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1177[] = {
  "minpd\t{%2, %0|%0, %2}",
  "vminpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1178[] = {
  "minpd\t{%2, %0|%0, %2}",
  "vminpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1179[] = {
  "maxps\t{%2, %0|%0, %2}",
  "vmaxps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1180[] = {
  "maxps\t{%2, %0|%0, %2}",
  "vmaxps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1181[] = {
  "maxpd\t{%2, %0|%0, %2}",
  "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1182[] = {
  "maxpd\t{%2, %0|%0, %2}",
  "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1184[] = {
  "addsubpd\t{%2, %0|%0, %2}",
  "vaddsubpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1186[] = {
  "addsubps\t{%2, %0|%0, %2}",
  "vaddsubps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1189[] = {
  "haddpd\t{%2, %0|%0, %2}",
  "vhaddpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1190[] = {
  "hsubpd\t{%2, %0|%0, %2}",
  "vhsubpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1193[] = {
  "haddps\t{%2, %0|%0, %2}",
  "vhaddps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1194[] = {
  "hsubps\t{%2, %0|%0, %2}",
  "vhsubps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1201[] = {
  "cmp%D3ps\t{%2, %0|%0, %2}",
  "vcmp%D3ps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1202[] = {
  "cmp%D3ps\t{%2, %0|%0, %2}",
  "vcmp%D3ps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1203[] = {
  "cmp%D3pd\t{%2, %0|%0, %2}",
  "vcmp%D3pd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1204[] = {
  "cmp%D3pd\t{%2, %0|%0, %2}",
  "vcmp%D3pd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1205[] = {
  "cmp%D3ps\t{%2, %0|%0, %2}",
  "vcmp%D3ps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1206[] = {
  "cmp%D3ps\t{%2, %0|%0, %2}",
  "vcmp%D3ps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1207[] = {
  "cmp%D3pd\t{%2, %0|%0, %2}",
  "vcmp%D3pd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1208[] = {
  "cmp%D3pd\t{%2, %0|%0, %2}",
  "vcmp%D3pd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1209[] = {
  "cmp%D3ss\t{%2, %0|%0, %2}",
  "vcmp%D3ss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1210[] = {
  "cmp%D3sd\t{%2, %0|%0, %2}",
  "vcmp%D3sd\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_1215 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1532 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "andn%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vandn%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1216 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1532 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "andn%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vandn%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1217 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1532 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "andn%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vandn%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1218 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1532 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "andn%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vandn%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1219 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "and%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vand%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1220 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "or%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1221 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "xor%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vxor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1222 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "and%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vand%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1223 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "or%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1224 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "xor%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vxor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1225 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "and%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vand%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1226 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "or%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1227 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "xor%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vxor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1228 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "and%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vand%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1229 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "or%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1230 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1572 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "xor%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vxor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1231 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1628 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "andn%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vandn%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1232 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1628 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "andn%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vandn%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1233 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1660 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "and%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vand%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1234 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1660 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "or%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1235 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1660 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "ps";

  switch (which_alternative)
    {
    case 0:
      insn = "xor%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vxor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1236 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1660 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "and%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vand%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1237 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1660 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "or%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char *
output_1238 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1660 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *insn;
  const char *suffix
    = TARGET_SSE_PACKED_SINGLE_INSN_OPTIMAL ? "ps" : "pd";

  switch (which_alternative)
    {
    case 0:
      insn = "xor%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      insn = "vxor%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), insn, suffix);
  return buf;
}
}

static const char * const output_1239[] = {
  "vfmadd132ss\t{%2, %3, %0|%0, %3, %2}",
  "vfmadd213ss\t{%3, %2, %0|%0, %2, %3}",
  "vfmadd231ss\t{%2, %1, %0|%0, %1, %2}",
  "vfmaddss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmaddss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1240[] = {
  "vfmadd132sd\t{%2, %3, %0|%0, %3, %2}",
  "vfmadd213sd\t{%3, %2, %0|%0, %2, %3}",
  "vfmadd231sd\t{%2, %1, %0|%0, %1, %2}",
  "vfmaddsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmaddsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1241[] = {
  "vfmadd132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfmadd213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfmadd231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1242[] = {
  "vfmadd132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfmadd213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfmadd231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1243[] = {
  "vfmadd132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfmadd213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfmadd231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1244[] = {
  "vfmadd132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfmadd213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfmadd231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1245[] = {
  "vfmsub132ss\t{%2, %3, %0|%0, %3, %2}",
  "vfmsub213ss\t{%3, %2, %0|%0, %2, %3}",
  "vfmsub231ss\t{%2, %1, %0|%0, %1, %2}",
  "vfmsubss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmsubss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1246[] = {
  "vfmsub132sd\t{%2, %3, %0|%0, %3, %2}",
  "vfmsub213sd\t{%3, %2, %0|%0, %2, %3}",
  "vfmsub231sd\t{%2, %1, %0|%0, %1, %2}",
  "vfmsubsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmsubsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1247[] = {
  "vfmsub132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfmsub213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfmsub231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1248[] = {
  "vfmsub132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfmsub213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfmsub231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1249[] = {
  "vfmsub132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfmsub213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfmsub231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1250[] = {
  "vfmsub132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfmsub213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfmsub231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1251[] = {
  "vfnmadd132ss\t{%2, %3, %0|%0, %3, %2}",
  "vfnmadd213ss\t{%3, %2, %0|%0, %2, %3}",
  "vfnmadd231ss\t{%2, %1, %0|%0, %1, %2}",
  "vfnmaddss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmaddss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1252[] = {
  "vfnmadd132sd\t{%2, %3, %0|%0, %3, %2}",
  "vfnmadd213sd\t{%3, %2, %0|%0, %2, %3}",
  "vfnmadd231sd\t{%2, %1, %0|%0, %1, %2}",
  "vfnmaddsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmaddsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1253[] = {
  "vfnmadd132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfnmadd213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfnmadd231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfnmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1254[] = {
  "vfnmadd132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfnmadd213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfnmadd231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfnmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1255[] = {
  "vfnmadd132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfnmadd213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfnmadd231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfnmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1256[] = {
  "vfnmadd132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfnmadd213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfnmadd231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfnmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1257[] = {
  "vfnmsub132ss\t{%2, %3, %0|%0, %3, %2}",
  "vfnmsub213ss\t{%3, %2, %0|%0, %2, %3}",
  "vfnmsub231ss\t{%2, %1, %0|%0, %1, %2}",
  "vfnmsubss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmsubss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1258[] = {
  "vfnmsub132sd\t{%2, %3, %0|%0, %3, %2}",
  "vfnmsub213sd\t{%3, %2, %0|%0, %2, %3}",
  "vfnmsub231sd\t{%2, %1, %0|%0, %1, %2}",
  "vfnmsubsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmsubsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1259[] = {
  "vfnmsub132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfnmsub213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfnmsub231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfnmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1260[] = {
  "vfnmsub132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfnmsub213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfnmsub231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfnmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1261[] = {
  "vfnmsub132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfnmsub213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfnmsub231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfnmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1262[] = {
  "vfnmsub132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfnmsub213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfnmsub231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfnmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfnmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1263[] = {
  "vfmaddsub132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfmaddsub213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfmaddsub231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfmaddsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmaddsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1264[] = {
  "vfmaddsub132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfmaddsub213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfmaddsub231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfmaddsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmaddsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1265[] = {
  "vfmaddsub132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfmaddsub213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfmaddsub231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfmaddsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmaddsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1266[] = {
  "vfmaddsub132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfmaddsub213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfmaddsub231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfmaddsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmaddsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1267[] = {
  "vfmsubadd132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfmsubadd213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfmsubadd231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfmsubaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmsubaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1268[] = {
  "vfmsubadd132ps\t{%2, %3, %0|%0, %3, %2}",
  "vfmsubadd213ps\t{%3, %2, %0|%0, %2, %3}",
  "vfmsubadd231ps\t{%2, %1, %0|%0, %1, %2}",
  "vfmsubaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmsubaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1269[] = {
  "vfmsubadd132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfmsubadd213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfmsubadd231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfmsubaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmsubaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1270[] = {
  "vfmsubadd132pd\t{%2, %3, %0|%0, %3, %2}",
  "vfmsubadd213pd\t{%3, %2, %0|%0, %2, %3}",
  "vfmsubadd231pd\t{%2, %1, %0|%0, %1, %2}",
  "vfmsubaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
  "vfmsubaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1271[] = {
  "vfmadd132ss\t{%2, %3, %0|%0, %3, %2}",
  "vfmadd213ss\t{%3, %2, %0|%0, %2, %3}",
  "vfmadd231ss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1272[] = {
  "vfmadd132sd\t{%2, %3, %0|%0, %3, %2}",
  "vfmadd213sd\t{%3, %2, %0|%0, %2, %3}",
  "vfmadd231sd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1273[] = {
  "vfmsub132ss\t{%2, %3, %0|%0, %3, %2}",
  "vfmsub213ss\t{%3, %2, %0|%0, %2, %3}",
  "vfmsub231ss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1274[] = {
  "vfmsub132sd\t{%2, %3, %0|%0, %3, %2}",
  "vfmsub213sd\t{%3, %2, %0|%0, %2, %3}",
  "vfmsub231sd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1275[] = {
  "vfnmadd132ss\t{%2, %3, %0|%0, %3, %2}",
  "vfnmadd213ss\t{%3, %2, %0|%0, %2, %3}",
  "vfnmadd231ss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1276[] = {
  "vfnmadd132sd\t{%2, %3, %0|%0, %3, %2}",
  "vfnmadd213sd\t{%3, %2, %0|%0, %2, %3}",
  "vfnmadd231sd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1277[] = {
  "vfnmsub132ss\t{%2, %3, %0|%0, %3, %2}",
  "vfnmsub213ss\t{%3, %2, %0|%0, %2, %3}",
  "vfnmsub231ss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1278[] = {
  "vfnmsub132sd\t{%2, %3, %0|%0, %3, %2}",
  "vfnmsub213sd\t{%3, %2, %0|%0, %2, %3}",
  "vfnmsub231sd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1290[] = {
  "cvtsi2ss\t{%2, %0|%0, %2}",
  "cvtsi2ss\t{%2, %0|%0, %2}",
  "vcvtsi2ss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1291[] = {
  "cvtsi2ssq\t{%2, %0|%0, %2}",
  "cvtsi2ssq\t{%2, %0|%0, %2}",
  "vcvtsi2ssq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1307[] = {
  "cvtsi2sd\t{%2, %0|%0, %2}",
  "cvtsi2sd\t{%2, %0|%0, %2}",
  "vcvtsi2sd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1308[] = {
  "cvtsi2sdq\t{%2, %0|%0, %2}",
  "cvtsi2sdq\t{%2, %0|%0, %2}",
  "vcvtsi2sdq\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_1320 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2545 "../../gcc/config/i386/sse.md"
{
  if (TARGET_AVX)
    return "vcvtpd2dq{x}\t{%1, %0|%0, %1}";
  else
    return "cvtpd2dq\t{%1, %0|%0, %1}";
}
}

static const char *
output_1323 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2602 "../../gcc/config/i386/sse.md"
{
  if (TARGET_AVX)
    return "vcvttpd2dq{x}\t{%1, %0|%0, %1}";
  else
    return "cvttpd2dq\t{%1, %0|%0, %1}";
}
}

static const char * const output_1324[] = {
  "cvtsd2ss\t{%2, %0|%0, %2}",
  "cvtsd2ss\t{%2, %0|%0, %2}",
  "vcvtsd2ss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1325[] = {
  "cvtss2sd\t{%2, %0|%0, %2}",
  "cvtss2sd\t{%2, %0|%0, %2}",
  "vcvtss2sd\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_1327 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2684 "../../gcc/config/i386/sse.md"
{
  if (TARGET_AVX)
    return "vcvtpd2ps{x}\t{%1, %0|%0, %1}";
  else
    return "cvtpd2ps\t{%1, %0|%0, %1}";
}
}

static const char * const output_1331[] = {
  "movhlps\t{%2, %0|%0, %2}",
  "vmovhlps\t{%2, %1, %0|%0, %1, %2}",
  "movlps\t{%H2, %0|%0, %H2}",
  "vmovlps\t{%H2, %1, %0|%0, %1, %H2}",
  "%vmovhps\t{%2, %0|%0, %2}",
};

static const char * const output_1332[] = {
  "movlhps\t{%2, %0|%0, %2}",
  "vmovlhps\t{%2, %1, %0|%0, %1, %2}",
  "movhps\t{%2, %0|%0, %2}",
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
  "%vmovlps\t{%2, %H0|%H0, %2}",
};

static const char * const output_1334[] = {
  "unpckhps\t{%2, %0|%0, %2}",
  "vunpckhps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1336[] = {
  "unpcklps\t{%2, %0|%0, %2}",
  "vunpcklps\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_1341 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3511 "../../gcc/config/i386/sse.md"
{
  int mask;
  mask = INTVAL (operands[3]);
  mask |= INTVAL (operands[4]) << 2;
  mask |= (INTVAL (operands[5]) - 8) << 4;
  mask |= (INTVAL (operands[6]) - 8) << 6;
  operands[3] = GEN_INT (mask);

  return "vshufps\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1342 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3553 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[3]) << 0;
  mask |= INTVAL (operands[4]) << 2;
  mask |= (INTVAL (operands[5]) - 4) << 4;
  mask |= (INTVAL (operands[6]) - 4) << 6;
  operands[3] = GEN_INT (mask);

  switch (which_alternative)
    {
    case 0:
      return "shufps\t{%3, %2, %0|%0, %2, %3}";
    case 1:
      return "vshufps\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1343 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3553 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[3]) << 0;
  mask |= INTVAL (operands[4]) << 2;
  mask |= (INTVAL (operands[5]) - 4) << 4;
  mask |= (INTVAL (operands[6]) - 4) << 6;
  operands[3] = GEN_INT (mask);

  switch (which_alternative)
    {
    case 0:
      return "shufps\t{%3, %2, %0|%0, %2, %3}";
    case 1:
      return "vshufps\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char * const output_1344[] = {
  "%vmovhps\t{%1, %0|%0, %1}",
  "%vmovhlps\t{%1, %d0|%d0, %1}",
  "%vmovlps\t{%H1, %d0|%d0, %H1}",
};

static const char * const output_1345[] = {
  "movhps\t{%2, %0|%0, %2}",
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
  "movlhps\t{%2, %0|%0, %2}",
  "vmovlhps\t{%2, %1, %0|%0, %1, %2}",
  "%vmovlps\t{%2, %H0|%H0, %2}",
};

static const char * const output_1346[] = {
  "%vmovlps\t{%1, %0|%0, %1}",
  "%vmovaps\t{%1, %0|%0, %1}",
  "%vmovlps\t{%1, %d0|%d0, %1}",
};

static const char * const output_1347[] = {
  "shufps\t{$0xe4, %1, %0|%0, %1, 0xe4}",
  "vshufps\t{$0xe4, %1, %2, %0|%0, %2, %1, 0xe4}",
  "movlps\t{%2, %0|%0, %2}",
  "vmovlps\t{%2, %1, %0|%0, %1, %2}",
  "%vmovlps\t{%2, %0|%0, %2}",
};

static const char * const output_1348[] = {
  "movss\t{%2, %0|%0, %2}",
  "vmovss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1351[] = {
  "vshufps\t{$0, %1, %1, %0|%0, %1, %1, 0}",
  "vbroadcastss\t{%1, %0|%0, %1}",
  "shufps\t{$0, %0, %0|%0, %0, 0}",
};

static const char * const output_1352[] = {
  "unpcklps\t{%2, %0|%0, %2}",
  "vunpcklps\t{%2, %1, %0|%0, %1, %2}",
  "insertps\t{$0x10, %2, %0|%0, %2, 0x10}",
  "vinsertps\t{$0x10, %2, %1, %0|%0, %1, %2, 0x10}",
  "%vmovss\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1353[] = {
  "unpcklps\t{%2, %0|%0, %2}",
  "movss\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1354[] = {
  "movlhps\t{%2, %0|%0, %2}",
  "vmovlhps\t{%2, %1, %0|%0, %1, %2}",
  "movhps\t{%2, %0|%0, %2}",
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1355[] = {
  "%vinsertps\t{$0xe, %d2, %0|%0, %d2, 0xe}",
  "%vmovd\t{%2, %0|%0, %2}",
  "%vmovd\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "vmovss\t{%2, %1, %0|%0, %1, %2}",
  "pinsrd\t{$0, %2, %0|%0, %2, 0}",
  "vpinsrd\t{$0, %2, %1, %0|%0, %1, %2, 0}",
  "#",
  "#",
  "#",
};

static const char * const output_1356[] = {
  "%vinsertps\t{$0xe, %d2, %0|%0, %d2, 0xe}",
  "%vmovss\t{%2, %0|%0, %2}",
  "%vmovd\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "vmovss\t{%2, %1, %0|%0, %1, %2}",
  "pinsrd\t{$0, %2, %0|%0, %2, 0}",
  "vpinsrd\t{$0, %2, %1, %0|%0, %1, %2, 0}",
  "#",
  "#",
  "#",
};

static const char *
output_1357 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3844 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])) << 4);
  switch (which_alternative)
    {
    case 0:
      return "insertps\t{%3, %2, %0|%0, %2, %3}";
    case 1:
      return "vinsertps\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1358 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3871 "../../gcc/config/i386/sse.md"
{
  if (MEM_P (operands[2]))
    {
      unsigned count_s = INTVAL (operands[3]) >> 6;
      if (count_s)
	operands[3] = GEN_INT (INTVAL (operands[3]) & 0x3f);
      operands[2] = adjust_address_nv (operands[2], SFmode, count_s * 4);
    }
  switch (which_alternative)
    {
    case 0:
      return "insertps\t{%3, %2, %0|%0, %2, %3}";
    case 1:
      return "vinsertps\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char * const output_1360[] = {
  "%vextractps\t{%2, %1, %0|%0, %1, %2}",
  "#",
  "#",
};

static const char * const output_1375[] = {
  "unpckhpd\t{%2, %0|%0, %2}",
  "vunpckhpd\t{%2, %1, %0|%0, %1, %2}",
  "%vmovddup\t{%H1, %0|%0, %H1}",
  "movlpd\t{%H1, %0|%0, %H1}",
  "vmovlpd\t{%H1, %2, %0|%0, %2, %H1}",
  "%vmovhpd\t{%1, %0|%0, %1}",
};

static const char * const output_1376[] = {
  "vunpcklpd\t{%2, %1, %0|%0, %1, %2}",
  "vmovddup\t{%1, %0|%0, %1}",
};

static const char * const output_1377[] = {
  "unpcklpd\t{%2, %0|%0, %2}",
  "vunpcklpd\t{%2, %1, %0|%0, %1, %2}",
  "%vmovddup\t{%1, %0|%0, %1}",
  "movhpd\t{%2, %0|%0, %2}",
  "vmovhpd\t{%2, %1, %0|%0, %1, %2}",
  "%vmovlpd\t{%2, %H0|%H0, %2}",
};

static const char *
output_1378 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4441 "../../gcc/config/i386/sse.md"
{
  int mask;
  mask = INTVAL (operands[3]);
  mask |= (INTVAL (operands[4]) - 4) << 1;
  mask |= (INTVAL (operands[5]) - 2) << 2;
  mask |= (INTVAL (operands[6]) - 6) << 3;
  operands[3] = GEN_INT (mask);

  return "vshufpd\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char * const output_1380[] = {
  "punpckhqdq\t{%2, %0|%0, %2}",
  "vpunpckhqdq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1382[] = {
  "punpcklqdq\t{%2, %0|%0, %2}",
  "vpunpcklqdq\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_1383 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4548 "../../gcc/config/i386/sse.md"
{
  int mask;
  mask = INTVAL (operands[3]);
  mask |= (INTVAL (operands[4]) - 2) << 1;
  operands[3] = GEN_INT (mask);

  switch (which_alternative)
    {
    case 0:
      return "shufpd\t{%3, %2, %0|%0, %2, %3}";
    case 1:
      return "vshufpd\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1384 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4548 "../../gcc/config/i386/sse.md"
{
  int mask;
  mask = INTVAL (operands[3]);
  mask |= (INTVAL (operands[4]) - 2) << 1;
  operands[3] = GEN_INT (mask);

  switch (which_alternative)
    {
    case 0:
      return "shufpd\t{%3, %2, %0|%0, %2, %3}";
    case 1:
      return "vshufpd\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char * const output_1385[] = {
  "%vmovhpd\t{%1, %0|%0, %1}",
  "unpckhpd\t%0, %0",
  "vunpckhpd\t{%d1, %0|%0, %d1}",
  "#",
  "#",
  "#",
};

static const char * const output_1386[] = {
  "movhps\t{%1, %0|%0, %1}",
  "movhlps\t{%1, %0|%0, %1}",
  "movlps\t{%H1, %0|%0, %H1}",
};

static const char * const output_1387[] = {
  "%vmovlpd\t{%1, %0|%0, %1}",
  "#",
  "#",
  "#",
  "#",
};

static const char * const output_1388[] = {
  "movlps\t{%1, %0|%0, %1}",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
};

static const char * const output_1389[] = {
  "movhpd\t{%2, %0|%0, %2}",
  "vmovhpd\t{%2, %1, %0|%0, %1, %2}",
  "unpcklpd\t{%2, %0|%0, %2}",
  "vunpcklpd\t{%2, %1, %0|%0, %1, %2}",
  "#",
  "#",
  "#",
};

static const char * const output_1390[] = {
  "%vmovsd\t{%2, %0|%0, %2}",
  "movlpd\t{%2, %0|%0, %2}",
  "vmovlpd\t{%2, %1, %0|%0, %1, %2}",
  "movsd\t{%2, %0|%0, %2}",
  "vmovsd\t{%2, %1, %0|%0, %1, %2}",
  "shufpd\t{$2, %1, %0|%0, %1, 2}",
  "movhpd\t{%H1, %0|%0, %H1}",
  "vmovhpd\t{%H1, %2, %0|%0, %2, %H1}",
  "#",
  "#",
  "#",
};

static const char * const output_1391[] = {
  "movsd\t{%2, %0|%0, %2}",
  "vmovsd\t{%2, %1, %0|%0, %1, %2}",
  "movlpd\t{%2, %0|%0, %2}",
  "vmovlpd\t{%2, %1, %0|%0, %1, %2}",
  "%vmovlpd\t{%2, %0|%0, %2}",
  "shufpd\t{$2, %1, %0|%0, %1, 2}",
  "movhps\t{%H1, %0|%0, %H1}",
  "vmovhps\t{%H1, %2, %0|%0, %2, %H1}",
  "%vmovhps\t{%1, %H0|%H0, %1}",
};

static const char * const output_1392[] = {
  "unpcklpd\t%0, %0",
  "%vmovddup\t{%1, %0|%0, %1}",
};

static const char * const output_1393[] = {
  "unpcklpd\t{%2, %0|%0, %2}",
  "vunpcklpd\t{%2, %1, %0|%0, %1, %2}",
  "%vmovddup\t{%1, %0|%0, %1}",
  "movhpd\t{%2, %0|%0, %2}",
  "vmovhpd\t{%2, %1, %0|%0, %1, %2}",
  "%vmovsd\t{%1, %0|%0, %1}",
  "movlhps\t{%2, %0|%0, %2}",
  "movhps\t{%2, %0|%0, %2}",
};

static const char * const output_1394[] = {
  "paddb\t{%2, %0|%0, %2}",
  "vpaddb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1395[] = {
  "psubb\t{%2, %0|%0, %2}",
  "vpsubb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1396[] = {
  "paddb\t{%2, %0|%0, %2}",
  "vpaddb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1397[] = {
  "psubb\t{%2, %0|%0, %2}",
  "vpsubb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1398[] = {
  "paddw\t{%2, %0|%0, %2}",
  "vpaddw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1399[] = {
  "psubw\t{%2, %0|%0, %2}",
  "vpsubw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1400[] = {
  "paddw\t{%2, %0|%0, %2}",
  "vpaddw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1401[] = {
  "psubw\t{%2, %0|%0, %2}",
  "vpsubw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1402[] = {
  "paddd\t{%2, %0|%0, %2}",
  "vpaddd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1403[] = {
  "psubd\t{%2, %0|%0, %2}",
  "vpsubd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1404[] = {
  "paddd\t{%2, %0|%0, %2}",
  "vpaddd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1405[] = {
  "psubd\t{%2, %0|%0, %2}",
  "vpsubd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1406[] = {
  "paddq\t{%2, %0|%0, %2}",
  "vpaddq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1407[] = {
  "psubq\t{%2, %0|%0, %2}",
  "vpsubq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1408[] = {
  "paddq\t{%2, %0|%0, %2}",
  "vpaddq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1409[] = {
  "psubq\t{%2, %0|%0, %2}",
  "vpsubq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1410[] = {
  "paddsb\t{%2, %0|%0, %2}",
  "vpaddsb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1411[] = {
  "paddusb\t{%2, %0|%0, %2}",
  "vpaddusb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1412[] = {
  "psubsb\t{%2, %0|%0, %2}",
  "vpsubsb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1413[] = {
  "psubusb\t{%2, %0|%0, %2}",
  "vpsubusb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1414[] = {
  "paddsb\t{%2, %0|%0, %2}",
  "vpaddsb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1415[] = {
  "paddusb\t{%2, %0|%0, %2}",
  "vpaddusb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1416[] = {
  "psubsb\t{%2, %0|%0, %2}",
  "vpsubsb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1417[] = {
  "psubusb\t{%2, %0|%0, %2}",
  "vpsubusb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1418[] = {
  "paddsw\t{%2, %0|%0, %2}",
  "vpaddsw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1419[] = {
  "paddusw\t{%2, %0|%0, %2}",
  "vpaddusw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1420[] = {
  "psubsw\t{%2, %0|%0, %2}",
  "vpsubsw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1421[] = {
  "psubusw\t{%2, %0|%0, %2}",
  "vpsubusw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1422[] = {
  "paddsw\t{%2, %0|%0, %2}",
  "vpaddsw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1423[] = {
  "paddusw\t{%2, %0|%0, %2}",
  "vpaddusw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1424[] = {
  "psubsw\t{%2, %0|%0, %2}",
  "vpsubsw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1425[] = {
  "psubusw\t{%2, %0|%0, %2}",
  "vpsubusw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1428[] = {
  "pmullw\t{%2, %0|%0, %2}",
  "vpmullw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1429[] = {
  "pmullw\t{%2, %0|%0, %2}",
  "vpmullw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1430[] = {
  "pmulhw\t{%2, %0|%0, %2}",
  "vpmulhw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1431[] = {
  "pmulhuw\t{%2, %0|%0, %2}",
  "vpmulhuw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1432[] = {
  "pmulhw\t{%2, %0|%0, %2}",
  "vpmulhw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1433[] = {
  "pmulhuw\t{%2, %0|%0, %2}",
  "vpmulhuw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1435[] = {
  "pmuludq\t{%2, %0|%0, %2}",
  "vpmuludq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1437[] = {
  "pmuldq\t{%2, %0|%0, %2}",
  "vpmuldq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1439[] = {
  "pmaddwd\t{%2, %0|%0, %2}",
  "vpmaddwd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1440[] = {
  "pmulld\t{%2, %0|%0, %2}",
  "vpmulld\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1441[] = {
  "pmulld\t{%2, %0|%0, %2}",
  "vpmulld\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1445[] = {
  "psraw\t{%2, %0|%0, %2}",
  "vpsraw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1446[] = {
  "psraw\t{%2, %0|%0, %2}",
  "vpsraw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1447[] = {
  "psrad\t{%2, %0|%0, %2}",
  "vpsrad\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1448[] = {
  "psrad\t{%2, %0|%0, %2}",
  "vpsrad\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1449[] = {
  "psllw\t{%2, %0|%0, %2}",
  "vpsllw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1450[] = {
  "psrlw\t{%2, %0|%0, %2}",
  "vpsrlw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1451[] = {
  "psllw\t{%2, %0|%0, %2}",
  "vpsllw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1452[] = {
  "psrlw\t{%2, %0|%0, %2}",
  "vpsrlw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1453[] = {
  "pslld\t{%2, %0|%0, %2}",
  "vpslld\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1454[] = {
  "psrld\t{%2, %0|%0, %2}",
  "vpsrld\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1455[] = {
  "pslld\t{%2, %0|%0, %2}",
  "vpslld\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1456[] = {
  "psrld\t{%2, %0|%0, %2}",
  "vpsrld\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1457[] = {
  "psllq\t{%2, %0|%0, %2}",
  "vpsllq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1458[] = {
  "psrlq\t{%2, %0|%0, %2}",
  "vpsrlq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1459[] = {
  "psllq\t{%2, %0|%0, %2}",
  "vpsllq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1460[] = {
  "psrlq\t{%2, %0|%0, %2}",
  "vpsrlq\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_1461 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5865 "../../gcc/config/i386/sse.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) / 8);

  switch (which_alternative)
    {
    case 0:
      return "pslldq\t{%2, %0|%0, %2}";
    case 1:
      return "vpslldq\t{%2, %1, %0|%0, %1, %2}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1462 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5865 "../../gcc/config/i386/sse.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) / 8);

  switch (which_alternative)
    {
    case 0:
      return "pslldq\t{%2, %0|%0, %2}";
    case 1:
      return "vpslldq\t{%2, %1, %0|%0, %1, %2}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1463 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5902 "../../gcc/config/i386/sse.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) / 8);

  switch (which_alternative)
    {
    case 0:
      return "psrldq\t{%2, %0|%0, %2}";
    case 1:
      return "vpsrldq\t{%2, %1, %0|%0, %1, %2}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1464 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5902 "../../gcc/config/i386/sse.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) / 8);

  switch (which_alternative)
    {
    case 0:
      return "psrldq\t{%2, %0|%0, %2}";
    case 1:
      return "vpsrldq\t{%2, %1, %0|%0, %1, %2}";
    default:
      gcc_unreachable ();
    }
}
}

static const char * const output_1477[] = {
  "pmaxsb\t{%2, %0|%0, %2}",
  "vpmaxsb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1478[] = {
  "pminsb\t{%2, %0|%0, %2}",
  "vpminsb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1479[] = {
  "pmaxsd\t{%2, %0|%0, %2}",
  "vpmaxsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1480[] = {
  "pminsd\t{%2, %0|%0, %2}",
  "vpminsd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1481[] = {
  "pmaxsw\t{%2, %0|%0, %2}",
  "vpmaxsw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1482[] = {
  "pminsw\t{%2, %0|%0, %2}",
  "vpminsw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1483[] = {
  "pmaxuw\t{%2, %0|%0, %2}",
  "vpmaxuw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1484[] = {
  "pminuw\t{%2, %0|%0, %2}",
  "vpminuw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1485[] = {
  "pmaxud\t{%2, %0|%0, %2}",
  "vpmaxud\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1486[] = {
  "pminud\t{%2, %0|%0, %2}",
  "vpminud\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1487[] = {
  "pmaxub\t{%2, %0|%0, %2}",
  "vpmaxub\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1488[] = {
  "pminub\t{%2, %0|%0, %2}",
  "vpminub\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1493[] = {
  "pcmpeqq\t{%2, %0|%0, %2}",
  "vpcmpeqq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1494[] = {
  "pcmpeqb\t{%2, %0|%0, %2}",
  "vpcmpeqb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1495[] = {
  "pcmpeqw\t{%2, %0|%0, %2}",
  "vpcmpeqw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1496[] = {
  "pcmpeqd\t{%2, %0|%0, %2}",
  "vpcmpeqd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1497[] = {
  "pcmpgtq\t{%2, %0|%0, %2}",
  "vpcmpgtq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1502[] = {
  "pcmpgtb\t{%2, %0|%0, %2}",
  "vpcmpgtb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1503[] = {
  "pcmpgtw\t{%2, %0|%0, %2}",
  "vpcmpgtw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1504[] = {
  "pcmpgtd\t{%2, %0|%0, %2}",
  "vpcmpgtd\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_1505 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6415 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pandn";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andnps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1506 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6415 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pandn";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andnps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1507 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6415 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pandn";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andnps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1508 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6415 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pandn";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andnps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1509 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6415 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pandn";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andnps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1510 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6415 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pandn";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andnps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1511 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6415 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pandn";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andnps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1512 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6415 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pandn";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andnps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1513 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pand";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1514 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "por";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "orps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1515 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pxor";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "xorps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1516 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pand";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1517 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "por";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "orps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1518 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pxor";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "xorps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1519 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pand";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1520 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "por";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "orps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1521 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pxor";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "xorps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1522 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pand";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1523 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "por";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "orps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1524 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pxor";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "xorps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1525 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pand";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1526 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "por";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "orps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1527 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pxor";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "xorps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1528 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pand";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1529 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "por";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "orps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1530 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pxor";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "xorps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1531 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pand";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1532 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "por";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "orps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1533 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pxor";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "xorps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1534 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pand";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "andps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1535 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "por";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "orps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char *
output_1536 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6490 "../../gcc/config/i386/sse.md"
{
  static char buf[32];
  const char *ops;
  const char *tmp;

  switch (get_attr_mode (insn))
    {
    case MODE_OI:
      gcc_assert (TARGET_AVX2);
    case MODE_TI:
      gcc_assert (TARGET_SSE2);

      tmp = "pxor";
      break;

   case MODE_V8SF:
      gcc_assert (TARGET_AVX);
   case MODE_V4SF:
      gcc_assert (TARGET_SSE);

      tmp = "xorps";
      break;

   default:
      gcc_unreachable ();
   }

  switch (which_alternative)
    {
    case 0:
      ops = "%s\t{%%2, %%0|%%0, %%2}";
      break;
    case 1:
      ops = "v%s\t{%%2, %%1, %%0|%%0, %%1, %%2}";
      break;
    default:
      gcc_unreachable ();
    }

  snprintf (buf, sizeof (buf), ops, tmp);
  return buf;
}
}

static const char * const output_1537[] = {
  "pandn\t{%2, %0|%0, %2}",
  "vpandn\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1538[] = {
  "pand\t{%2, %0|%0, %2}",
  "vpand\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1539[] = {
  "por\t{%2, %0|%0, %2}",
  "vpor\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1540[] = {
  "pxor\t{%2, %0|%0, %2}",
  "vpxor\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1541[] = {
  "packsswb\t{%2, %0|%0, %2}",
  "vpacksswb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1542[] = {
  "packsswb\t{%2, %0|%0, %2}",
  "vpacksswb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1543[] = {
  "packssdw\t{%2, %0|%0, %2}",
  "vpackssdw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1544[] = {
  "packssdw\t{%2, %0|%0, %2}",
  "vpackssdw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1545[] = {
  "packuswb\t{%2, %0|%0, %2}",
  "vpackuswb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1546[] = {
  "packuswb\t{%2, %0|%0, %2}",
  "vpackuswb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1548[] = {
  "punpckhbw\t{%2, %0|%0, %2}",
  "vpunpckhbw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1550[] = {
  "punpcklbw\t{%2, %0|%0, %2}",
  "vpunpcklbw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1552[] = {
  "punpckhwd\t{%2, %0|%0, %2}",
  "vpunpckhwd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1554[] = {
  "punpcklwd\t{%2, %0|%0, %2}",
  "vpunpcklwd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1556[] = {
  "punpckhdq\t{%2, %0|%0, %2}",
  "vpunpckhdq\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1558[] = {
  "punpckldq\t{%2, %0|%0, %2}",
  "vpunpckldq\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_1559 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6963 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));

  switch (which_alternative)
    {
    case 0:
      if (GET_MODE_SIZE (QImode) < GET_MODE_SIZE (SImode))
	return "pinsrb\t{%3, %k2, %0|%0, %k2, %3}";
      /* FALLTHRU */
    case 1:
      return "pinsrb\t{%3, %2, %0|%0, %2, %3}";
    case 2:
      if (GET_MODE_SIZE (QImode) < GET_MODE_SIZE (SImode))
	return "vpinsrb\t{%3, %k2, %1, %0|%0, %1, %k2, %3}";
      /* FALLTHRU */
    case 3:
      return "vpinsrb\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1560 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6963 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));

  switch (which_alternative)
    {
    case 0:
      if (GET_MODE_SIZE (HImode) < GET_MODE_SIZE (SImode))
	return "pinsrw\t{%3, %k2, %0|%0, %k2, %3}";
      /* FALLTHRU */
    case 1:
      return "pinsrw\t{%3, %2, %0|%0, %2, %3}";
    case 2:
      if (GET_MODE_SIZE (HImode) < GET_MODE_SIZE (SImode))
	return "vpinsrw\t{%3, %k2, %1, %0|%0, %1, %k2, %3}";
      /* FALLTHRU */
    case 3:
      return "vpinsrw\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1561 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6963 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));

  switch (which_alternative)
    {
    case 0:
      if (GET_MODE_SIZE (SImode) < GET_MODE_SIZE (SImode))
	return "pinsrd\t{%3, %k2, %0|%0, %k2, %3}";
      /* FALLTHRU */
    case 1:
      return "pinsrd\t{%3, %2, %0|%0, %2, %3}";
    case 2:
      if (GET_MODE_SIZE (SImode) < GET_MODE_SIZE (SImode))
	return "vpinsrd\t{%3, %k2, %1, %0|%0, %1, %k2, %3}";
      /* FALLTHRU */
    case 3:
      return "vpinsrd\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1562 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6963 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));

  switch (which_alternative)
    {
    case 0:
      if (GET_MODE_SIZE (DImode) < GET_MODE_SIZE (SImode))
	return "pinsrq\t{%3, %k2, %0|%0, %k2, %3}";
      /* FALLTHRU */
    case 1:
      return "pinsrq\t{%3, %2, %0|%0, %2, %3}";
    case 2:
      if (GET_MODE_SIZE (DImode) < GET_MODE_SIZE (SImode))
	return "vpinsrq\t{%3, %k2, %1, %0|%0, %1, %k2, %3}";
      /* FALLTHRU */
    case 3:
      return "vpinsrq\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1572 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7140 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[2]) << 0;
  mask |= INTVAL (operands[3]) << 2;
  mask |= INTVAL (operands[4]) << 4;
  mask |= INTVAL (operands[5]) << 6;
  operands[2] = GEN_INT (mask);

  return "vpshufd\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1573 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7179 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[2]) << 0;
  mask |= INTVAL (operands[3]) << 2;
  mask |= INTVAL (operands[4]) << 4;
  mask |= INTVAL (operands[5]) << 6;
  operands[2] = GEN_INT (mask);

  return "%vpshufd\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1574 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7239 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[2]) << 0;
  mask |= INTVAL (operands[3]) << 2;
  mask |= INTVAL (operands[4]) << 4;
  mask |= INTVAL (operands[5]) << 6;
  operands[2] = GEN_INT (mask);

  return "vpshuflw\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1575 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7282 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[2]) << 0;
  mask |= INTVAL (operands[3]) << 2;
  mask |= INTVAL (operands[4]) << 4;
  mask |= INTVAL (operands[5]) << 6;
  operands[2] = GEN_INT (mask);

  return "%vpshuflw\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1576 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7343 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= (INTVAL (operands[2]) - 4) << 0;
  mask |= (INTVAL (operands[3]) - 4) << 2;
  mask |= (INTVAL (operands[4]) - 4) << 4;
  mask |= (INTVAL (operands[5]) - 4) << 6;
  operands[2] = GEN_INT (mask);

  return "vpshufhw\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1577 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7386 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= (INTVAL (operands[2]) - 4) << 0;
  mask |= (INTVAL (operands[3]) - 4) << 2;
  mask |= (INTVAL (operands[4]) - 4) << 4;
  mask |= (INTVAL (operands[5]) - 4) << 6;
  operands[2] = GEN_INT (mask);

  return "%vpshufhw\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char * const output_1578[] = {
  "%vmovd\t{%2, %0|%0, %2}",
  "%vmovd\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "vmovss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1581[] = {
  "#",
  "#",
  "mov{q}\t{%1, %0|%0, %1}",
};

static const char * const output_1583[] = {
  "%vmovhps\t{%1, %0|%0, %1}",
  "psrldq\t{$8, %0|%0, 8}",
  "vpsrldq\t{$8, %1, %0|%0, %1, 8}",
  "%vmovq\t{%H1, %0|%0, %H1}",
  "mov{q}\t{%H1, %0|%0, %H1}",
};

static const char * const output_1584[] = {
  "%vmovhps\t{%1, %0|%0, %1}",
  "psrldq\t{$8, %0|%0, 8}",
  "vpsrldq\t{$8, %1, %0|%0, %1, 8}",
  "%vmovq\t{%H1, %0|%0, %H1}",
  "movhlps\t{%1, %0|%0, %1}",
  "movlps\t{%H1, %0|%0, %H1}",
};

static const char * const output_1585[] = {
  "%vpshufd\t{$0, %1, %0|%0, %1, 0}",
  "vbroadcastss\t{%1, %0|%0, %1}",
  "shufps\t{$0, %0, %0|%0, %0, 0}",
};

static const char * const output_1586[] = {
  "punpcklqdq\t%0, %0",
  "vpunpcklqdq\t{%d1, %0|%0, %d1}",
  "%vmovddup\t{%1, %0|%0, %1}",
  "movlhps\t%0, %0",
};

static const char * const output_1587[] = {
  "pinsrd\t{$1, %2, %0|%0, %2, 1}",
  "vpinsrd\t{$1, %2, %1, %0|%0, %1, %2, 1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "vpunpckldq\t{%2, %1, %0|%0, %1, %2}",
  "%vmovd\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1588[] = {
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1589[] = {
  "unpcklps\t{%2, %0|%0, %2}",
  "movss\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1590[] = {
  "punpcklqdq\t{%2, %0|%0, %2}",
  "vpunpcklqdq\t{%2, %1, %0|%0, %1, %2}",
  "movlhps\t{%2, %0|%0, %2}",
  "movhps\t{%2, %0|%0, %2}",
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1591[] = {
  "pinsrq\t{$1, %2, %0|%0, %2, 1}",
  "vpinsrq\t{$1, %2, %1, %0|%0, %1, %2, 1}",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "punpcklqdq\t{%2, %0|%0, %2}",
  "vpunpcklqdq\t{%2, %1, %0|%0, %1, %2}",
  "movhps\t{%2, %0|%0, %2}",
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1592[] = {
  "%vmovq\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "punpcklqdq\t{%2, %0|%0, %2}",
  "vpunpcklqdq\t{%2, %1, %0|%0, %1, %2}",
  "movlhps\t{%2, %0|%0, %2}",
  "movhps\t{%2, %0|%0, %2}",
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1594[] = {
  "pavgb\t{%2, %0|%0, %2}",
  "vpavgb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1596[] = {
  "pavgw\t{%2, %0|%0, %2}",
  "vpavgw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1597[] = {
  "psadbw\t{%2, %0|%0, %2}",
  "vpsadbw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1598[] = {
  "psadbw\t{%2, %0|%0, %2}",
  "vpsadbw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1614[] = {
  "phaddw\t{%2, %0|%0, %2}",
  "vphaddw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1617[] = {
  "phaddd\t{%2, %0|%0, %2}",
  "vphaddd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1620[] = {
  "phaddsw\t{%2, %0|%0, %2}",
  "vphaddsw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1623[] = {
  "phsubw\t{%2, %0|%0, %2}",
  "vphsubw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1626[] = {
  "phsubd\t{%2, %0|%0, %2}",
  "vphsubd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1629[] = {
  "phsubsw\t{%2, %0|%0, %2}",
  "vphsubsw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1632[] = {
  "pmaddubsw\t{%2, %0|%0, %2}",
  "vpmaddubsw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1635[] = {
  "pmulhrsw\t{%2, %0|%0, %2}",
  "vpmulhrsw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1637[] = {
  "pshufb\t{%2, %0|%0, %2}",
  "vpshufb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1638[] = {
  "pshufb\t{%2, %0|%0, %2}",
  "vpshufb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1640[] = {
  "psignb\t{%2, %0|%0, %2}",
  "vpsignb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1641[] = {
  "psignb\t{%2, %0|%0, %2}",
  "vpsignb\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1642[] = {
  "psignw\t{%2, %0|%0, %2}",
  "vpsignw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1643[] = {
  "psignw\t{%2, %0|%0, %2}",
  "vpsignw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1644[] = {
  "psignd\t{%2, %0|%0, %2}",
  "vpsignd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1645[] = {
  "psignd\t{%2, %0|%0, %2}",
  "vpsignd\t{%2, %1, %0|%0, %1, %2}",
};

static const char *
output_1649 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9277 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (INTVAL (operands[3]) / 8);

  switch (which_alternative)
    {
    case 0:
      return "palignr\t{%3, %2, %0|%0, %2, %3}";
    case 1:
      return "vpalignr\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1650 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9277 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (INTVAL (operands[3]) / 8);

  switch (which_alternative)
    {
    case 0:
      return "palignr\t{%3, %2, %0|%0, %2, %3}";
    case 1:
      return "vpalignr\t{%3, %2, %1, %0|%0, %1, %2, %3}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1651 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9306 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (INTVAL (operands[3]) / 8);
  return "palignr\t{%3, %2, %0|%0, %2, %3}";
}
}

static const char * const output_1669[] = {
  "blendps\t{%3, %2, %0|%0, %2, %3}",
  "vblendps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1670[] = {
  "blendps\t{%3, %2, %0|%0, %2, %3}",
  "vblendps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1671[] = {
  "blendpd\t{%3, %2, %0|%0, %2, %3}",
  "vblendpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1672[] = {
  "blendpd\t{%3, %2, %0|%0, %2, %3}",
  "vblendpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1673[] = {
  "blendvps\t{%3, %2, %0|%0, %2, %3}",
  "vblendvps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1674[] = {
  "blendvps\t{%3, %2, %0|%0, %2, %3}",
  "vblendvps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1675[] = {
  "blendvpd\t{%3, %2, %0|%0, %2, %3}",
  "vblendvpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1676[] = {
  "blendvpd\t{%3, %2, %0|%0, %2, %3}",
  "vblendvpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1677[] = {
  "dpps\t{%3, %2, %0|%0, %2, %3}",
  "vdpps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1678[] = {
  "dpps\t{%3, %2, %0|%0, %2, %3}",
  "vdpps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1679[] = {
  "dppd\t{%3, %2, %0|%0, %2, %3}",
  "vdppd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1680[] = {
  "dppd\t{%3, %2, %0|%0, %2, %3}",
  "vdppd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1683[] = {
  "mpsadbw\t{%3, %2, %0|%0, %2, %3}",
  "vmpsadbw\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1684[] = {
  "mpsadbw\t{%3, %2, %0|%0, %2, %3}",
  "vmpsadbw\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1686[] = {
  "packusdw\t{%2, %0|%0, %2}",
  "vpackusdw\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1687[] = {
  "pblendvb\t{%3, %2, %0|%0, %2, %3}",
  "vpblendvb\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1688[] = {
  "pblendvb\t{%3, %2, %0|%0, %2, %3}",
  "vpblendvb\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1689[] = {
  "pblendw\t{%3, %2, %0|%0, %2, %3}",
  "vpblendw\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char *
output_1690 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9596 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (INTVAL (operands[3]) & 0xff);
  return "vpblendw\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char * const output_1728[] = {
  "roundss\t{%3, %2, %0|%0, %2, %3}",
  "vroundss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1729[] = {
  "roundsd\t{%3, %2, %0|%0, %2, %3}",
  "vroundsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char * const output_1733[] = {
  "%vpcmpestrm\t{%6, %4, %2|%2, %4, %6}",
  "%vpcmpestrm\t{%6, %4, %2|%2, %4, %6}",
  "%vpcmpestri\t{%6, %4, %2|%2, %4, %6}",
  "%vpcmpestri\t{%6, %4, %2|%2, %4, %6}",
};

static const char * const output_1737[] = {
  "%vpcmpistrm\t{%4, %3, %2|%2, %3, %4}",
  "%vpcmpistrm\t{%4, %3, %2|%2, %3, %4}",
  "%vpcmpistri\t{%4, %3, %2|%2, %3, %4}",
  "%vpcmpistri\t{%4, %3, %2|%2, %3, %4}",
};

static const char *
output_1785 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11140 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT ((16 * 8) - INTVAL (operands[2]));
  return "vprotb\t{%3, %1, %0|%0, %1, %3}";
}
}

static const char *
output_1786 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11140 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT ((8 * 8) - INTVAL (operands[2]));
  return "vprotw\t{%3, %1, %0|%0, %1, %3}";
}
}

static const char *
output_1787 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11140 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT ((4 * 8) - INTVAL (operands[2]));
  return "vprotd\t{%3, %1, %0|%0, %1, %3}";
}
}

static const char *
output_1788 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11140 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT ((2 * 8) - INTVAL (operands[2]));
  return "vprotq\t{%3, %1, %0|%0, %1, %3}";
}
}

static const char *
output_1821 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11512 "../../gcc/config/i386/sse.md"
{
  return ((INTVAL (operands[3]) != 0)
	  ? "vpcomtrueb\t{%2, %1, %0|%0, %1, %2}"
	  : "vpcomfalseb\t{%2, %1, %0|%0, %1, %2}");
}
}

static const char *
output_1822 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11512 "../../gcc/config/i386/sse.md"
{
  return ((INTVAL (operands[3]) != 0)
	  ? "vpcomtruew\t{%2, %1, %0|%0, %1, %2}"
	  : "vpcomfalsew\t{%2, %1, %0|%0, %1, %2}");
}
}

static const char *
output_1823 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11512 "../../gcc/config/i386/sse.md"
{
  return ((INTVAL (operands[3]) != 0)
	  ? "vpcomtrued\t{%2, %1, %0|%0, %1, %2}"
	  : "vpcomfalsed\t{%2, %1, %0|%0, %1, %2}");
}
}

static const char *
output_1824 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11512 "../../gcc/config/i386/sse.md"
{
  return ((INTVAL (operands[3]) != 0)
	  ? "vpcomtrueq\t{%2, %1, %0|%0, %1, %2}"
	  : "vpcomfalseq\t{%2, %1, %0|%0, %1, %2}");
}
}

static const char * const output_1829[] = {
  "aesenc\t{%2, %0|%0, %2}",
  "vaesenc\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1830[] = {
  "aesenclast\t{%2, %0|%0, %2}",
  "vaesenclast\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1831[] = {
  "aesdec\t{%2, %0|%0, %2}",
  "vaesdec\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1832[] = {
  "aesdeclast\t{%2, %0|%0, %2}",
  "vaesdeclast\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1835[] = {
  "pclmulqdq\t{%3, %2, %0|%0, %2, %3}",
  "vpclmulqdq\t{%3, %2, %1, %0|%0, %1, %2, %3}",
};

static const char *
output_1849 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11764 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[2]) << 0;
  mask |= INTVAL (operands[3]) << 2;
  mask |= INTVAL (operands[4]) << 4;
  mask |= INTVAL (operands[5]) << 6;
  operands[2] = GEN_INT (mask);
  return "vpermq\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char * const output_1852[] = {
  "vbroadcastss\t{%1, %0|%0, %1}",
  "#",
};

static const char * const output_1853[] = {
  "vbroadcastss\t{%1, %0|%0, %1}",
  "#",
};

static const char * const output_1854[] = {
  "vbroadcastsd\t{%1, %0|%0, %1}",
  "#",
};

static const char * const output_1855[] = {
  "vbroadcastsd\t{%1, %0|%0, %1}",
  "#",
};

static const char * const output_1860[] = {
  "vbroadcast%~128\t{%1, %0|%0, %1}",
  "vinsert%~128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2%~128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char * const output_1861[] = {
  "vbroadcast%~128\t{%1, %0|%0, %1}",
  "vinsert%~128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2%~128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char * const output_1862[] = {
  "vbroadcast%~128\t{%1, %0|%0, %1}",
  "vinsert%~128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2%~128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char * const output_1863[] = {
  "vbroadcast%~128\t{%1, %0|%0, %1}",
  "vinsert%~128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2%~128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char * const output_1864[] = {
  "vbroadcastf128\t{%1, %0|%0, %1}",
  "vinsertf128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2f128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char * const output_1865[] = {
  "vbroadcastf128\t{%1, %0|%0, %1}",
  "vinsertf128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2f128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char *
output_1866 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11868 "../../gcc/config/i386/sse.md"
{
  int elt = INTVAL (operands[3]);
  switch (which_alternative)
    {
    case 0:
    case 1:
      operands[1] = adjust_address_nv (operands[1], SFmode, elt * 4);
      return "vbroadcastss\t{%1, %0|%0, %1}";
    case 2:
      operands[2] = GEN_INT (elt * 0x55);
      return "vpermilps\t{%2, %1, %0|%0, %1, %2}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1869 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11981 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vpermilp_parallel (operands[2], V8SFmode) - 1;
  operands[2] = GEN_INT (mask);
  return "vpermilps\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1870 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11981 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vpermilp_parallel (operands[2], V4SFmode) - 1;
  operands[2] = GEN_INT (mask);
  return "vpermilps\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1871 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11981 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vpermilp_parallel (operands[2], V4DFmode) - 1;
  operands[2] = GEN_INT (mask);
  return "vpermilpd\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1872 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11981 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vpermilp_parallel (operands[2], V2DFmode) - 1;
  operands[2] = GEN_INT (mask);
  return "vpermilpd\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1880 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12067 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vperm2f128_parallel (operands[3], V8SImode) - 1;
  if (mask == 0x12)
    return "vinsert%~128\t{$0, %x2, %1, %0|%0, %1, %x2, 0}";
  if (mask == 0x20)
    return "vinsert%~128\t{$1, %x2, %1, %0|%0, %1, %x2, 1}";
  operands[3] = GEN_INT (mask);
  return "vperm2%~128\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1881 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12067 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vperm2f128_parallel (operands[3], V8SFmode) - 1;
  if (mask == 0x12)
    return "vinsertf128\t{$0, %x2, %1, %0|%0, %1, %x2, 0}";
  if (mask == 0x20)
    return "vinsertf128\t{$1, %x2, %1, %0|%0, %1, %x2, 1}";
  operands[3] = GEN_INT (mask);
  return "vperm2f128\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1882 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12067 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vperm2f128_parallel (operands[3], V4DFmode) - 1;
  if (mask == 0x12)
    return "vinsertf128\t{$0, %x2, %1, %0|%0, %1, %x2, 0}";
  if (mask == 0x20)
    return "vinsertf128\t{$1, %x2, %1, %0|%0, %1, %x2, 1}";
  operands[3] = GEN_INT (mask);
  return "vperm2f128\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1926 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12412 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsert%~128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1927 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12412 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsert%~128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1928 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12412 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsert%~128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1929 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12412 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsert%~128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1930 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12412 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsertf128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1931 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12412 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsertf128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
	{
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1986 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V2DImode != V2DImode)
    return "vpgatherqq\t{%4, %6, %x0|%x0, %6, %4}";
  return "vpgatherqq\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1987 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V2DImode != V2DImode)
    return "vpgatherqq\t{%4, %6, %x0|%x0, %6, %4}";
  return "vpgatherqq\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1988 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V2DFmode != V2DFmode)
    return "vgatherqpd\t{%4, %6, %x0|%x0, %6, %4}";
  return "vgatherqpd\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1989 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V2DFmode != V2DFmode)
    return "vgatherqpd\t{%4, %6, %x0|%x0, %6, %4}";
  return "vgatherqpd\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1990 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V4DImode != V4DImode)
    return "vpgatherqq\t{%4, %6, %x0|%x0, %6, %4}";
  return "vpgatherqq\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1991 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V4DImode != V4DImode)
    return "vpgatherqq\t{%4, %6, %x0|%x0, %6, %4}";
  return "vpgatherqq\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1992 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V4DFmode != V4DFmode)
    return "vgatherqpd\t{%4, %6, %x0|%x0, %6, %4}";
  return "vgatherqpd\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1993 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V4DFmode != V4DFmode)
    return "vgatherqpd\t{%4, %6, %x0|%x0, %6, %4}";
  return "vgatherqpd\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1994 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V4SImode != V4SImode)
    return "vpgatherqd\t{%4, %6, %x0|%x0, %6, %4}";
  return "vpgatherqd\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1995 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V4SImode != V4SImode)
    return "vpgatherqd\t{%4, %6, %x0|%x0, %6, %4}";
  return "vpgatherqd\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1996 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V4SFmode != V4SFmode)
    return "vgatherqps\t{%4, %6, %x0|%x0, %6, %4}";
  return "vgatherqps\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1997 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V4SFmode != V4SFmode)
    return "vgatherqps\t{%4, %6, %x0|%x0, %6, %4}";
  return "vgatherqps\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1998 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V8SImode != V4SImode)
    return "vpgatherqd\t{%4, %6, %x0|%x0, %6, %4}";
  return "vpgatherqd\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_1999 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V8SImode != V4SImode)
    return "vpgatherqd\t{%4, %6, %x0|%x0, %6, %4}";
  return "vpgatherqd\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_2000 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V8SFmode != V4SFmode)
    return "vgatherqps\t{%4, %6, %x0|%x0, %6, %4}";
  return "vgatherqps\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_2001 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12652 "../../gcc/config/i386/sse.md"
{
  if (V8SFmode != V4SFmode)
    return "vgatherqps\t{%4, %6, %x0|%x0, %6, %4}";
  return "vgatherqps\t{%4, %6, %0|%0, %6, %4}";
}
}

static const char *
output_2017 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 296 "../../gcc/config/i386/sync.md"
{
  gcc_assert (find_regno_note (insn, REG_DEAD, FIRST_STACK_REG) != NULL_RTX);

  return "fistp%Z0\t%0";
}
}

static const char *
output_2022 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 420 "../../gcc/config/i386/sync.md"
{
  bool swap = REGNO (operands[5]) != BX_REG;

  if (swap)
    output_asm_insn ("xchg{l}\t%%ebx, %5", operands);

  output_asm_insn ("lock{%;} cmpxchg8b\t%2", operands);

  if (swap)
    output_asm_insn ("xchg{l}\t%%ebx, %5", operands);

  return "";
}
}

static const char *
output_2023 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 420 "../../gcc/config/i386/sync.md"
{
  bool swap = REGNO (operands[5]) != BX_REG;

  if (swap)
    output_asm_insn ("xchg{q}\t%%rbx, %5", operands);

  output_asm_insn ("lock{%;} cmpxchg16b\t%2", operands);

  if (swap)
    output_asm_insn ("xchg{q}\t%%rbx, %5", operands);

  return "";
}
}

static const char *
output_2028 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 493 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{b}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{b}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], QImode))
    return "lock{%;} sub{b}\t{%1, %0|%0, %1}";

  return "lock{%;} add{b}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2029 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 493 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{w}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{w}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], HImode))
    return "lock{%;} sub{w}\t{%1, %0|%0, %1}";

  return "lock{%;} add{w}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2030 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 493 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{l}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{l}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], SImode))
    return "lock{%;} sub{l}\t{%1, %0|%0, %1}";

  return "lock{%;} add{l}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2031 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 493 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{q}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{q}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], DImode))
    return "lock{%;} sub{q}\t{%1, %0|%0, %1}";

  return "lock{%;} add{q}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2036 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 530 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{b}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{b}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], QImode))
    return "lock{%;} sub{b}\t{%1, %0|%0, %1}";

  return "lock{%;} add{b}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2037 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 530 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{w}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{w}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], HImode))
    return "lock{%;} sub{w}\t{%1, %0|%0, %1}";

  return "lock{%;} add{w}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2038 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 530 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{l}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{l}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], SImode))
    return "lock{%;} sub{l}\t{%1, %0|%0, %1}";

  return "lock{%;} add{l}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2039 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 530 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{q}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{q}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], DImode))
    return "lock{%;} sub{q}\t{%1, %0|%0, %1}";

  return "lock{%;} add{q}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2040 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 554 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} dec{b}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} inc{b}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], QImode))
    return "lock{%;} add{b}\t{%1, %0|%0, %1}";

  return "lock{%;} sub{b}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2041 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 554 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} dec{w}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} inc{w}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], HImode))
    return "lock{%;} add{w}\t{%1, %0|%0, %1}";

  return "lock{%;} sub{w}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2042 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 554 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} dec{l}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} inc{l}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], SImode))
    return "lock{%;} add{l}\t{%1, %0|%0, %1}";

  return "lock{%;} sub{l}\t{%1, %0|%0, %1}";
}
}

static const char *
output_2043 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 554 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} dec{q}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} inc{q}\t%0";
    }

  if (x86_maybe_negate_const_int (&operands[1], DImode))
    return "lock{%;} add{q}\t{%1, %0|%0, %1}";

  return "lock{%;} sub{q}\t{%1, %0|%0, %1}";
}
}



static const struct insn_operand_data operand_data[] = 
{
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "q,?mq",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,?mr",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,?mr",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,?mr",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "qm,q",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm,r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "rn,rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "Qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "Q",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "Qmn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "Qn",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f,x",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "f,xm",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=<",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "riF*o",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=<",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "riF*o",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=<,!<",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "re*m,n",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=<",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "ri*m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=X",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_no_elim_operand,
    "rn",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "=X",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_no_elim_operand,
    "rn",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "=X",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_no_elim_operand,
    "re",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "=<",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "re*m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=<",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "re*m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r*m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    pop_operand,
    ">",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r*m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    pop_operand,
    ">",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    OImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,xm,x",
    OImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=!r,o,x,x,xm",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "riFo,riF,C,xm,x",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,xm,x",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,!o,*y,m*y,?*y,?r,?*Ym,*x,m,*x,*x,?r,?*Yi,?*x,?*Ym",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "Z,rem,i,re,n,C,*y,m,*Ym,r,C,*x,*x,m,*Yi,r,*Ym,*x",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,o,*y,m*y,*y,*x,m,*x,*x,*x,m,*x,*x,?*x,?*Ym",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "riFo,riF,C,*y,m,C,*x,*x,m,C,*x,*x,m,*Ym,*x",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,m,*y,*y,?rm,?*y,*x,*x,?r,m,?*Yi,*x",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "g,re,C,*y,*y,rm,C,*x,*Yi,*x,r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,r,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "r,rn,rm,rn",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=q,q,q,r,r,?r,m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "q,qn,qm,q,rn,qm,qn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_movabs_operand,
    "i,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "a,rn",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_movabs_operand,
    "i,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "a,rn",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_movabs_operand,
    "i,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "a,re",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_movabs_operand,
    "i,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "a,re",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a,r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_movabs_operand,
    "i,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a,r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_movabs_operand,
    "i,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_movabs_operand,
    "i,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_movabs_operand,
    "i,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+q",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+q",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "+qm,q",
    QImode,
    1,
    0,
    1,
    1
  },
  {
    general_operand,
    "qn,m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "+rm,r",
    HImode,
    1,
    0,
    1,
    1
  },
  {
    general_operand,
    "rn,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "+q",
    QImode,
    1,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+r",
    HImode,
    1,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=R",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=R",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=Q,?R",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q,Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=Qm,?r",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "Q,Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=R",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=Qm,?R",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "Q,Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "+Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "Qn",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "+Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "Qn",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "+Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "Qmn",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "+Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "Q",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "=<,<,<",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "x,Fo,*r",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=<,<",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "f,ro",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=<,<",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "f,*rFo",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=<,<,<",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "f,Yd*rFm,x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=<,<,<",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "f,Yd*rFo,x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "=X,X,X",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_no_elim_operand,
    "f,rF,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "=<,<,<",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_no_elim_operand,
    "f,rFm,x",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m,x,?*r,!o",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "xm,x,C,*roF,F*r",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,m,f,?Yx*r,!o",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "fm,f,G,Yx*roF,FYx*r",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,m,f,?r,?m,?r,!o,x,x,x,m,Yi,r",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "fm,f,G,rm,r,F,F,C,x,m,x,r,Yi",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,m,f,?Yd*r,!o,x,x,x,m,*x,*x,*x,m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "fm,f,G,Yd*roF,FYd*r,C,x,m,x,C,*x,m,*x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,m,f,?r,?m,x,x,x,m,!*y,!m,!*y,?Yi,?r,!*Ym,!r",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "fm,f,G,rmF,Fr,C,x,m,x,m,*y,*y,r,Yi,r,*Ym",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "+f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    fp_register_operand,
    "+f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    fp_register_operand,
    "+f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    fp_register_operand,
    "+f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    fp_register_operand,
    "+f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,o,?*Ym,?*y,?*Yi,*x",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm,0,r,m,r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,?r,?o,?*Ym,?*y,?*Yi,*x",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,rm,r,r,m,r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,?&q",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,?&q",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "qm,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "qm,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=*a,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "*0,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=*A,r,?r,?*o",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0,r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=X,X,X,&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=*a,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "*0,rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=*a,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "*0,rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=*a,r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "*0,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,m,x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm,f,xm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm,f",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,m",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm,f",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,m",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm,f",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=fm,x",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "f,xm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=fm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,?f,?x,?*r",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "f,xm,f,f,f",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,X,m,m,m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,?f,?x,?*r",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "f,f,f,f",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m,m,m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=m,?f,?x,?*r",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f,f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=X,m,m,m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,?f,?x,?*r",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f,f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=X,m,m,m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&x,&x",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=x,&x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "m,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=&x,&x",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=x,&x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "m,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=X,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f,f,x,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r,r,m,!x",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m,m,X,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f,x,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r,r,m,!x",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m,m,X,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r,r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m,m,X",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r,r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m,m,X",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r,r,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m,m,X",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r,r,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m,m,X",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,r,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,r,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m,!x",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m,X,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m,!x",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m,X,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m,X",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m,X",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m,X",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m,X",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=X,x",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=X,x",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=X,x",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    lea_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    lea_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,o",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "ronF,rnF",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,o",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "roe,re",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=qm,q",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm,r,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,r,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme,re,0,le",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm,r,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,r,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme,re,0,le",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,r,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme,0,le",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r,r,Yp",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,r,Yp",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "rn,rm,0,ln",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=qm,q,q,r,r,Yp",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,q,0,r,Yp",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qn,qm,0,rn,0,ln",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "+qm,q",
    QImode,
    1,
    0,
    1,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=q,qm,q",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,q",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qmn,qn,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm,r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "rmn,rn,0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme,re,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme,re,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=q,q",
    QImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0,q",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qmn,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=r,r",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0,r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "rmn,0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=r,r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=r,r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=rm",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_immediate_operand,
    "e",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=qm",
    QImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "n",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=rm",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "n",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=rm",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "Qn",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "Qmn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "%0",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    index_register_operand,
    "l",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    index_register_operand,
    "l",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const248_operand,
    "n",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "ri",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    index_register_operand,
    "l",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const248_operand,
    "n",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    index_register_operand,
    "l",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,o",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "ronF,rnF",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,o",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "roe,re",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=qm,q",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "rn,rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_general_operand,
    "rme",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=qm,q",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=qm,q",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "rn,rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "rn,rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_general_operand,
    "rme",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    scratch_operand,
    "=q",
    QImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qmn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=r",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "rmn",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%rm,rm,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "K,e,mr",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%rm,rm,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "K,e,mr",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%rm,rm,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "K,e,mr",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r,r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%rm,rm,0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "K,n,mr",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=a",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%d",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%d",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=A,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,d",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=A,r",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,d",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=A",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=A",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%a",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=1",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%a",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=1",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%a",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=1",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&d",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&d",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&d",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=d",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "1",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "1",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "1",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%!*a,r,!*a,r,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_szext_general_operand,
    "Z,Z,e,e,re",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%!*a,q,qm,r",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "n,n,qn,n",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%!*a,q,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "n,n,qn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%!*a,r,rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "n,n,rn",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%!*a,r,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "e,e,re",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "Qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,rm,r,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,0,qm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_szext_general_operand,
    "Z,re,rm,L",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,qm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "re,rm,L",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r,r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,qm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "rn,rm,L",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=qm,q,r",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qn,qmn,rn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "+qm,q",
    QImode,
    1,
    0,
    1,
    1
  },
  {
    general_operand,
    "qn,qmn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_szext_general_operand,
    "Z,rem,re",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=q,qm,*r",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qmn,qn,n",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=q,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qmn,qn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "rmn,rn",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme,re",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "+q,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "qmn,qn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "Qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "rme,re",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=q,m,r",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qmn,qn,rn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_zext_immediate_operand,
    "Z",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "+q,m",
    QImode,
    1,
    0,
    1,
    1
  },
  {
    general_operand,
    "qmn,qn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_zext_immediate_operand,
    "Z",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "+q,qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "qmn,qn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "=q",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "qmn",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=ro",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=ro",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,f,!r",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x,0,0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,0,X,X",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x,f,!r",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x,0,0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,0,X,X",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x,!r",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x,0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "xm,0,X",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    absneg_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x,!r",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x,0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "xm,0,X",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    absneg_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,!r",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    absneg_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,!r",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    absneg_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,!r",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    absneg_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,0",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    TFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "xmC",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "xmC",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "xmC",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=x,x,x,x,x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "x,0,0,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1,1,x,1,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "X,xm,xm,0,0",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,xm,1,xm,1",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=x,x,x,x,x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "x,0,0,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1,1,x,1,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "X,xm,xm,0,0",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,xm,1,xm,1",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=x,x,x,x,x",
    TFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "x,0,0,x,x",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1,1,x,1,x",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "X,xm,xm,0,0",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,xm,1,xm,1",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=qm,r",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=&r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_pm1_operand,
    "n,0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "Jc,Jc",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r,r",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_pm1_operand,
    "n,0",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "Oc,Oc",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "+r*m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "Jc",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "+r*m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "Ic",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "c",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "c",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,l,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI,M,r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,l,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cJ,M,r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,l,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI,M,r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm,Yp",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,l",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI,M",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=qm,r,Yp",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0,l",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI,cI,M",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "+qm",
    QImode,
    1,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_1_to_63_operand,
    "J",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=q",
    QImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_1_to_63_operand,
    "J",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "Jc",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "Oc",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=*d,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "*a,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=*d,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "*a,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=*d,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "*a,0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI,r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cJ,r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI,r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    const_1_to_63_operand,
    "J",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "J",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI,I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cJ,J",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "cI,I",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_63_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_nonmemory_operand,
    "rN",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_nonmemory_operand,
    "rN",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=q",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=q",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_comparison_operator,
    "",
    QImode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "+qm",
    QImode,
    1,
    0,
    1,
    1
  },
  {
    ix86_comparison_operator,
    "",
    QImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_comparison_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_comparison_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=a",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=a",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=a",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=a,a",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=a,a",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    indirect_branch_operand,
    "rw",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    indirect_branch_operand,
    "rw",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    indirect_branch_operand,
    "rw",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    indirect_branch_operand,
    "rw",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "lzw",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "rzw",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "Uz",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "Uz",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "lzm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "lzm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "Uz",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "rzw",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "Uz",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "Uz",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "lzm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "Uz",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    BLKmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&q",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "n",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,m,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,m,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "+Q,r",
    HImode,
    1,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=Q",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=&Q",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=Q",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "b",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    constant_call_address_operand,
    "z",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=d",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=c",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    constant_call_address_operand,
    "z",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "b",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    constant_call_address_operand,
    "z",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=d",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=c",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    constant_call_address_operand,
    "z",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "b",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    constant_call_address_operand,
    "z",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=d",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=c",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "b",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "b",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "b",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    tls_modbase_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    tls_modbase_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,0,x",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm,xm,xm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,0,x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm,xm,xm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,fm,0,x",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm,0,xm,xm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,fm,0,x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm,0,xm,xm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,fm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,fm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f,0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm,0",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm,0",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "fm,0",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    const_double_operand,
    "F",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_double_operand,
    "F",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    const_double_operand,
    "F",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "u",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=2",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "u",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=2",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "u",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=2",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "u",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=2",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "u",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=2",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,?r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,?r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=S",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=S",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=S",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "2",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=S",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "2",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=S",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "2",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=S",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "2",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&c",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "i",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r,r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "rm,0",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "rm,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "rm,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r,0",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    fcmov_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "f,0",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f,f,r,r",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    fcmov_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "f,0,rm,0",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,f,0,rm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f,&r,&r",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    fcmov_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "f,0,rm,0",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,f,0,rm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f,r,r",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    fcmov_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "f,0,rm,0",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,f,0,rm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_nonmemory_operand,
    "re,le",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_nonmemory_operand,
    "re,le",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "n",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    address_operand,
    "p",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    address_operand,
    "p",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    CCZmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    CCZmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    CCZmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    CCZmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=A",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=A",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r,!?y,!y,!?y,m,!y,*x,x,x,m,r,Yi",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "Cr,m,C,!y,m,!?y,*x,!y,C,xm,x,Yi,r",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r,!?y,!y,!?y,m,!y,*x,x,x,m,r,Yi",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "Cr,m,C,!y,m,!?y,*x,!y,C,xm,x,Yi,r",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r,!?y,!y,!?y,m,!y,*x,x,x,m,r,Yi",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "Cr,m,C,!y,m,!?y,*x,!y,C,xm,x,Yi,r",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r,!?y,!y,!?y,m,!y,*x,x,x,m,r,Yi",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "Cr,m,C,!y,m,!?y,*x,!y,C,xm,x,Yi,r",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!y,!?y,m,!y,*x,*x,*x,m,*x,*x,*x,m,r,m",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,!y,m,!?y,*x,!y,C,*xm,*x,C,*x,m,*x,irm,r",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!y,!?y,m,!y,*x,*x,*x,m,*x,*x,*x,m,r,m",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,!y,m,!?y,*x,!y,C,*xm,*x,C,*x,m,*x,irm,r",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!y,!?y,m,!y,*x,*x,*x,m,*x,*x,*x,m,r,m",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,!y,m,!?y,*x,!y,C,*xm,*x,C,*x,m,*x,irm,r",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!y,!?y,m,!y,*x,*x,*x,m,*x,*x,*x,m,r,m",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,!y,m,!?y,*x,!y,C,*xm,*x,C,*x,m,*x,irm,r",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r,!?y,!y,!?y,m,!y,*x,x,x,x,m,r,Yi",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "Cr,m,C,!y,m,!?y,*x,!y,C,x,m,x,Yi,r",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!y,!?y,m,!y,*x,*x,*x,*x,m,r,m",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,!y,m,!?y,*x,!y,C,*x,m,*x,irm,r",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "y",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=y",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y,y",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,ym",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym,0",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=y,y",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,rm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "ym,C",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m,y,m,f,r",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,ym,y,m,m",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=y,x,y,x,f,r",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0,o,o,o,o",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V1DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V1DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V1DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "yN",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "yN",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=y",
    V1DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V1DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "yN",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=y",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "y",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=y,y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "ym,C",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m,y,m,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,ym,y,m",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=y,x,x,x,y,x,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,0,x,0,o,o,o",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V1DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "y",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "y",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "y",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "y",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "y",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    emms_operation,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V2TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V2TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V1TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V1TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=?x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&x,X",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=x,m",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,xm,x,m",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,0,xm,x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    V8SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x,x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,xm,x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,0,xm,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    V4SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x,x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,xm,x,m",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,0,xm,x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    V4DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x,x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,xm,x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,0,xm,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    V2DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%0,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_comparison_operator,
    "",
    V8SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_comparison_operator,
    "",
    V4SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%0,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_comparison_operator,
    "",
    V4DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_comparison_operator,
    "",
    V2DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_comparison_operator,
    "",
    V8SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_comparison_operator,
    "",
    V4SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_comparison_operator,
    "",
    V4DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_comparison_operator,
    "",
    V2DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%0,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%0,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x,x,x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,0,x,x,x",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,xm,x,m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,xm,0,xm,x",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,0,x,x,x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,xm,x,m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,xm,0,xm,x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,0,x,x,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,xm,x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,xm,0,xm,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,0,x,x,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,xm,x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,xm,0,xm,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,0,x,x,x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,xm,x,m",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,xm,0,xm,x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,0,x,x,x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,xm,x,m",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,xm,0,xm,x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,0,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,xm,0",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,0,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,xm,0",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "y,m",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m,rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,x,0,x,0",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,o,o,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,o",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,x,0,x,0",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,m,x,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_8_to_11_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_8_to_11_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_12_to_15_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_12_to_15_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=m,x,x",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,o",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,o",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,x,0,x,0",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "m,m,x,x,x",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,0,x,0",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,x,m,m,x",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m,0",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x,*y,*y",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x,0,x,m,0,m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "x,x,m,m,C,*ym,C",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,*y,*y",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,m,0,m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "x,C,*y,C",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x,0,x",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,x,m,m",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,x,x,x,x,m,m,m",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,C,C,C,0,x,0,x,0,0,0",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "x,m,*r,m,x,x,*rm,*rm,!x,!*re,!*fF",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,x,x,x,x,m,m,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,C,C,C,0,x,0,x,0,0,0",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "x,m,*r,m,x,x,*rm,*rm,!x,!*re,!*fF",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=x,m,f,r",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,m,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=rm,x,x",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x,0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "n,n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,*r,f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "o,o,o",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "n,n,n",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=x,m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=x,m",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,x,o,o,o,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,1,0,x,0",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,1",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,x,o",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,x,m,0,x,0",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,1,m,m,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_1_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_5_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_2_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_6_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_1_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_2_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_1_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_2_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=m,x,x,x,*f,r",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,0,x,o,o,o",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,o",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x,*f,r",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,m,m,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,o,o,o",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,x,0,x,0,0,0",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "m,m,x,x,x,*f,r",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,x,x,x,x,m,m,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,0,x,0,x,x,o,o,0,0,0",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "m,m,m,x,x,0,0,x,x,*f,r",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,m,x,x,x,o",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "0,x,0,x,0,x,o,o,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,x,m,m,x,0,0,x,0",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,xm",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x,x,x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x,m,0,x,m,0,0",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "x,x,1,m,m,C,x,m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "xN,xN",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "xN,xN",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "xN,xN",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "xN,xN",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "xN,xN",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "xN,xN",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V2TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V2TImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_mul_8_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V1TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V1TImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_mul_8_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0,x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m,r,m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0,x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m,r,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0,x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m,r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0,x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m,r,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_7_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_7_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_7_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=rm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_1_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_8_to_11_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_8_to_11_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_8_to_11_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_8_to_11_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_12_to_15_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_12_to_15_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_12_to_15_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_12_to_15_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,Yi,x,x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "C,C,C,0,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,r,m,x,x",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=xm,r",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x,Yi",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "o",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=xm,*r,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,Yi,o",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=xm",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=m,x,x,x,r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,0,x,o,o",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x,x,x,x",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,0,x,o,x,o",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m,0",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x,m,0",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x,*y,*y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x,0,x,rm,0,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "rm,rm,x,x,C,*ym,C",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,*y,*y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,rm,0,rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "x,C,*y,C",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,*y,*y",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,m,0,*rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "x,C,*y,C",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x,x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x,0,0,x",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,x,x,m,m",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x,Yi,!x,x,x,x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "0,x,xm,r,*y,0,x,0,x",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "rm,rm,C,C,C,x,x,m,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,?x,x,x,x,x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,*y,0,x,0,0,x",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    vector_move_operand,
    "C,C,x,x,x,m,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "D",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "D",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V2TImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2TImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=y",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=y",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "0,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimm_not_xmm0_operand_maybe_avx,
    "xm,xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "Yz,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimm_not_xmm0_operand_maybe_avx,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "Yz,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "0,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimm_not_xmm0_operand_maybe_avx,
    "xm,xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "Yz,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimm_not_xmm0_operand_maybe_avx,
    "xm,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "Yz,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%0,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "=x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "0,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimm_not_xmm0_operand_maybe_avx,
    "xm,xm",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "Yz,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "=x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand_maybe_avx,
    "0,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimm_not_xmm0_operand_maybe_avx,
    "xm,xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "Yz,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    avx2_pblendw_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_15_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_15_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c,c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=Yz,Yz",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand,
    "x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a,a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimm_not_xmm0_operand,
    "x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c,c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a,a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=Yz,Yz",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a,a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=Yz,Yz,X,X",
    V16QImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=X,X,c,c",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "x,x,x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "a,a,a,a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m,x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "d,d,d,d",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "n,n,n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c,c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=Yz,Yz",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand,
    "x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimm_not_xmm0_operand,
    "x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=c,c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=Yz,Yz",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=Yz,Yz,X,X",
    V16QImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "=X,X,c,c",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "x,x,x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m,x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n,n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "x,m",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_7_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_63_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,x",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const0_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_int_operator,
    "",
    V16QImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_int_operator,
    "",
    V8HImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_int_operator,
    "",
    V4SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_int_operator,
    "",
    V2DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_uns_operator,
    "",
    V16QImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_uns_operator,
    "",
    V8HImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_uns_operator,
    "",
    V4SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_uns_operator,
    "",
    V2DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "%x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vzeroall_operation,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?x",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?x",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?x",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,?x",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,o,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    avx_vbroadcast_operand,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "C,n,n",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,o,?x",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    avx_vbroadcast_operand,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "C,n,n",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x,x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "m,o,?x",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    avx_vbroadcast_operand,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "C,n,n",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=x,m",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "xm,C",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "xm,C",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "xm,C",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "xm,C",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "xm,C",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x,x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "xm,C",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "N",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "N",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=xm",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "N",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4DFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    DFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SImode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&x",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    vsib_address_operand,
    "p",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand,
    "n",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_mem_operator,
    "",
    SFmode,
    0,
    1,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m,?r",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m,m,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=X,X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=X,xf,xf",
    DFmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m,m,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "x,m,?r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=X,X,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=X,xf,xf",
    DFmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "q",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=a,a",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    cmpxchg8b_pic_memory_operand,
    "+m,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1,1",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "b,!*r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "c,c",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=X,&5",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=a,a",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    cmpxchg8b_pic_memory_operand,
    "+m,m",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "1,1",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "b,!*r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "c,c",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=X,&5",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=q",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "0",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "0",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "i",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "i",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "i",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=q",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "qn",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "rn",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "re",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "re",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonmemory_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonmemory_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    cmp_fp_expander_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    cmp_fp_expander_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    cmp_fp_expander_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    cmp_fp_expander_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    cmp_fp_expander_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    cmp_fp_expander_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    cmp_fp_expander_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    cmp_fp_expander_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const0_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    push_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    push_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    OImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    OImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    CDImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    CDImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "=m",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    1,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    1,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    sse_reg_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    any_fp_register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    any_fp_register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    push_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    any_fp_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    fp_register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    fp_register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    push_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    fp_register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "x",
    DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "x",
    DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "x",
    SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "x",
    SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    fp_register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    fp_register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    fp_register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    fp_register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    lea_address_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    lea_address_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    index_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    index_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const248_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    index_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const248_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    index_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_carry_flag_operator,
    "",
    QImode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_carry_flag_operator,
    "",
    HImode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_carry_flag_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_carry_flag_operator,
    "",
    DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_szext_general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_szext_general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_szext_general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    fp_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    absneg_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    absneg_operator,
    "",
    SFmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    absneg_operator,
    "",
    DFmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    absneg_operator,
    "",
    XFmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    vector_move_operand,
    "",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    TFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    shiftdi_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    ashldi_input_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_pm1_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    index_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    index_register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    shiftdi_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    shiftdi_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_1_to_31_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    const_1_to_63_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const8_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const8_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const8_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const8_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_63_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    1,
    0,
    1,
    1
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=a",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=a",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=a",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=a",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=a",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    indirect_branch_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    QImode,
    0,
    1,
    0,
    0
  },
  {
    q_regs_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    sibcall_insn_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    constant_call_address_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    constant_call_address_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    constant_call_address_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    constant_call_address_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    constant_call_address_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    tls_modbase_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    tls_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    tls_modbase_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    scratch_operand,
    "",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    scratch_operand,
    "",
    XFmode,
    0,
    0,
    0,
    0
  },
  {
     register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
     register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    XFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_general_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_carry_flag_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_carry_flag_operator,
    "",
    DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    0,
    1,
    0
  },
  {
    register_and_not_any_fp_reg_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    fcmov_comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    fp_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    fp_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    binary_fp_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    ordered_comparison_operator,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    aligned_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    promotable_binary_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    aligned_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    aligned_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    push_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "q",
    QImode,
    0,
    0,
    0,
    0
  },
  {
    push_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "r",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    push_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    push_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    push_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "r",
    SFmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "q",
    QImode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    arith_or_logical_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    commutative_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    commutative_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    arith_or_logical_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    plusminuslogic_operator,
    "",
    QImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    plusminuslogic_operator,
    "",
    HImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    plusminuslogic_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    x86_64_nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    plusminuslogic_operator,
    "",
    DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    plusminuslogic_operator,
    "",
    QImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    plusminuslogic_operator,
    "",
    HImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    plusminuslogic_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    plusminuslogic_operator,
    "",
    DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    plusminuslogic_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    plusminuslogic_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    1,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const359_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const359_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const359_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const359_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    HImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_general_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    x86_64_general_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V1DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V1DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V1DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    zero_extended_scalar_load_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    zero_extended_scalar_load_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V1TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    V8SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    V4SFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    V4DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    absneg_operator,
    "",
    V2DFmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonmemory_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_3_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_mul_8_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_mul_8_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_mul_8_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_mul_8_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_15_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimm_not_xmm0_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    reg_not_xmm0_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimm_not_xmm0_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    avx_vbroadcast_operand,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    avx_vbroadcast_operand,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V2DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V4DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V4DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V2DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V2DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V4DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V4DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V4SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V8SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    vsib_address_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    0,
    1,
    0
  },
  {
    const1248_operand ,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    V8SFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    DFmode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "",
    DFmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
};


#if GCC_VERSION >= 2007
__extension__
#endif

const struct insn_data_d insn_data[] = 
{
  /* ../../gcc/config/i386/i386.md:968 */
  {
    "*cmpqi_ccno_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_0 },
#else
    { 0, output_0, 0 },
#endif
    0,
    &operand_data[1],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:968 */
  {
    "*cmphi_ccno_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_1 },
#else
    { 0, output_1, 0 },
#endif
    0,
    &operand_data[3],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:968 */
  {
    "*cmpsi_ccno_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_2 },
#else
    { 0, output_2, 0 },
#endif
    0,
    &operand_data[5],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:968 */
  {
    "*cmpdi_ccno_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_3 },
#else
    { 0, output_3, 0 },
#endif
    0,
    &operand_data[7],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:980 */
  {
    "*cmpqi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[9],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:980 */
  {
    "*cmphi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[11],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:980 */
  {
    "*cmpsi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[13],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:980 */
  {
    "*cmpdi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{q}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[15],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:989 */
  {
    "*cmpqi_minus_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[9],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:989 */
  {
    "*cmphi_minus_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[11],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:989 */
  {
    "*cmpsi_minus_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[13],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:989 */
  {
    "*cmpdi_minus_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{q}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[15],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:1000 */
  {
    "*cmpqi_ext_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%h1, %0|%0, %h1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[17],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1014 */
  {
    "*cmpqi_ext_1_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%h1, %0|%0, %h1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[19],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1028 */
  {
    "*cmpqi_ext_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t%h0, %h0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[20],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1053 */
  {
    "*cmpqi_ext_3_insn",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%1, %h0|%h0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[22],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1068 */
  {
    "*cmpqi_ext_3_insn_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%1, %h0|%h0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[24],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1083 */
  {
    "*cmpqi_ext_4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%h1, %h0|%h0, %h1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[26],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1206 */
  {
    "*cmpfp_0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_18 },
#else
    { 0, 0, output_18 },
#endif
    0,
    &operand_data[28],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1226 */
  {
    "*cmpfp_0_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[28],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1254 */
  {
    "*cmpfp_xf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_20 },
#else
    { 0, 0, output_20 },
#endif
    0,
    &operand_data[31],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1267 */
  {
    "*cmpfp_xf_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[31],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1288 */
  {
    "*cmpfp_sf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_22 },
#else
    { 0, 0, output_22 },
#endif
    0,
    &operand_data[34],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1288 */
  {
    "*cmpfp_df",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_23 },
#else
    { 0, 0, output_23 },
#endif
    0,
    &operand_data[37],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1301 */
  {
    "*cmpfp_sf_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[34],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1301 */
  {
    "*cmpfp_df_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[37],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1322 */
  {
    "*cmpfp_u",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_26 },
#else
    { 0, 0, output_26 },
#endif
    0,
    &operand_data[40],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1342 */
  {
    "*cmpfp_u_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[40],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1370 */
  {
    "*cmpfp_hi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_28 },
#else
    { 0, 0, output_28 },
#endif
    0,
    &operand_data[43],
    4,
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1370 */
  {
    "*cmpfp_si",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_29 },
#else
    { 0, 0, output_29 },
#endif
    0,
    &operand_data[47],
    4,
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1387 */
  {
    "*cmpfp_hi_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[43],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1387 */
  {
    "*cmpfp_si_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[47],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1417 */
  {
    "x86_fnstsw_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnstsw\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_x86_fnstsw_1,
    &operand_data[28],
    1,
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1430 */
  {
    "x86_sahf_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_33 },
#else
    { 0, 0, output_33 },
#endif
    (insn_gen_fn) gen_x86_sahf_1,
    &operand_data[51],
    1,
    1,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1452 */
  {
    "*cmpfp_i_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_34 },
#else
    { 0, 0, output_34 },
#endif
    0,
    &operand_data[52],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:1481 */
  {
    "*cmpfp_i_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_35 },
#else
    { 0, 0, output_35 },
#endif
    0,
    &operand_data[54],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1504 */
  {
    "*cmpfp_i_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_36 },
#else
    { 0, 0, output_36 },
#endif
    0,
    &operand_data[41],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1525 */
  {
    "*cmpfp_iu_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_37 },
#else
    { 0, 0, output_37 },
#endif
    0,
    &operand_data[52],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:1554 */
  {
    "*cmpfp_iu_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_38 },
#else
    { 0, 0, output_38 },
#endif
    0,
    &operand_data[54],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1577 */
  {
    "*cmpfp_iu_387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_39 },
#else
    { 0, 0, output_39 },
#endif
    0,
    &operand_data[41],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1600 */
  {
    "*pushdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[56],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1600 */
  {
    "*pushti2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[58],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1616 */
  {
    "*pushdi2_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_42 },
#else
    { 0, output_42, 0 },
#endif
    0,
    &operand_data[60],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:1682 */
  {
    "*pushsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{l}\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[62],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1695 */
  {
    "*pushqi2_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{q}\t%q1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[64],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1695 */
  {
    "*pushhi2_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{q}\t%q1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[66],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1695 */
  {
    "*pushsi2_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{q}\t%q1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[68],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1703 */
  {
    "*pushqi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{l}\t%k1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[64],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1703 */
  {
    "*pushhi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{l}\t%k1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[66],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1711 */
  {
    "*pushsi2_prologue",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{l}\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[70],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1711 */
  {
    "*pushdi2_prologue",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{q}\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[72],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1720 */
  {
    "*popsi1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "pop{l}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[74],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1720 */
  {
    "*popdi1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "pop{q}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[76],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1728 */
  {
    "*popsi1_epilogue",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "pop{l}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[74],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1728 */
  {
    "*popdi1_epilogue",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "pop{q}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[76],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1781 */
  {
    "*movsi_xor",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t%k0, %k0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[78],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1781 */
  {
    "*movdi_xor",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t%k0, %k0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[80],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1791 */
  {
    "*movsi_or",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[82],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1791 */
  {
    "*movdi_or",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{q}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[84],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1802 */
  {
    "*movoi_internal_avx",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_59 },
#else
    { 0, 0, output_59 },
#endif
    0,
    &operand_data[86],
    2,
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:1826 */
  {
    "*movti_internal_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_60 },
#else
    { 0, 0, output_60 },
#endif
    0,
    &operand_data[88],
    2,
    2,
    0,
    5,
    3
  },
  /* ../../gcc/config/i386/i386.md:1885 */
  {
    "*movti_internal_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_61 },
#else
    { 0, 0, output_61 },
#endif
    0,
    &operand_data[90],
    2,
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:1929 */
  {
    "*movdi_internal_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_62 },
#else
    { 0, 0, output_62 },
#endif
    0,
    &operand_data[92],
    2,
    2,
    0,
    18,
    3
  },
  /* ../../gcc/config/i386/i386.md:2094 */
  {
    "*movdi_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_63 },
#else
    { 0, 0, output_63 },
#endif
    0,
    &operand_data[94],
    2,
    2,
    0,
    15,
    3
  },
  /* ../../gcc/config/i386/i386.md:2175 */
  {
    "*movsi_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_64 },
#else
    { 0, 0, output_64 },
#endif
    0,
    &operand_data[96],
    2,
    2,
    0,
    12,
    3
  },
  /* ../../gcc/config/i386/i386.md:2256 */
  {
    "*movhi_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_65 },
#else
    { 0, 0, output_65 },
#endif
    0,
    &operand_data[98],
    2,
    2,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:2312 */
  {
    "*movqi_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_66 },
#else
    { 0, 0, output_66 },
#endif
    0,
    &operand_data[100],
    2,
    2,
    0,
    7,
    3
  },
  /* ../../gcc/config/i386/i386.md:2371 */
  {
    "*movabsqi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_67 },
#else
    { 0, output_67, 0 },
#endif
    0,
    &operand_data[102],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:2371 */
  {
    "*movabshi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_68 },
#else
    { 0, output_68, 0 },
#endif
    0,
    &operand_data[104],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:2371 */
  {
    "*movabssi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_69 },
#else
    { 0, output_69, 0 },
#endif
    0,
    &operand_data[106],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:2371 */
  {
    "*movabsdi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_70 },
#else
    { 0, output_70, 0 },
#endif
    0,
    &operand_data[108],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:2385 */
  {
    "*movabsqi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_71 },
#else
    { 0, output_71, 0 },
#endif
    0,
    &operand_data[110],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:2385 */
  {
    "*movabshi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_72 },
#else
    { 0, output_72, 0 },
#endif
    0,
    &operand_data[112],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:2385 */
  {
    "*movabssi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_73 },
#else
    { 0, output_73, 0 },
#endif
    0,
    &operand_data[114],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:2385 */
  {
    "*movabsdi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_74 },
#else
    { 0, output_74, 0 },
#endif
    0,
    &operand_data[116],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:2399 */
  {
    "*swapsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xchg{l}\t%1, %0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[118],
    2,
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2399 */
  {
    "*swapdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xchg{q}\t%1, %0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[120],
    2,
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2413 */
  {
    "*swapqi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xchg{l}\t%k1, %k0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[122],
    2,
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2413 */
  {
    "*swaphi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xchg{l}\t%k1, %k0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[124],
    2,
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2429 */
  {
    "*swapqi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xchg{b}\t%1, %0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[126],
    2,
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2429 */
  {
    "*swaphi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xchg{w}\t%1, %0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[124],
    2,
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2456 */
  {
    "*movstrictqi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[128],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:2456 */
  {
    "*movstricthi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[130],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:2466 */
  {
    "*movstrictqi_xor",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t%0, %0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[132],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2466 */
  {
    "*movstricthi_xor",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{w}\t%0, %0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[134],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2476 */
  {
    "*movhi_extv_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movs{bl|x}\t{%h1, %k0|%k0, %h1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[136],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2476 */
  {
    "*movsi_extv_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movs{bl|x}\t{%h1, %k0|%k0, %h1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[138],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2486 */
  {
    "*movqi_extv_1_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_87 },
#else
    { 0, 0, output_87 },
#endif
    0,
    &operand_data[140],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2511 */
  {
    "*movqi_extv_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_88 },
#else
    { 0, 0, output_88 },
#endif
    0,
    &operand_data[142],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2537 */
  {
    "*movsi_extzv_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{bl|x}\t{%h1, %k0|%k0, %h1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[138],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2537 */
  {
    "*movdi_extzv_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{bl|x}\t{%h1, %k0|%k0, %h1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[144],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2547 */
  {
    "*movqi_extzv_2_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_91 },
#else
    { 0, 0, output_91 },
#endif
    0,
    &operand_data[140],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2573 */
  {
    "*movqi_extzv_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_92 },
#else
    { 0, 0, output_92 },
#endif
    0,
    &operand_data[146],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2606 */
  {
    "*movsi_insv_1_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_93 },
#else
    { 0, 0, output_93 },
#endif
    0,
    &operand_data[148],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:2606 */
  {
    "*movdi_insv_1_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_94 },
#else
    { 0, 0, output_94 },
#endif
    0,
    &operand_data[150],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:2620 */
  {
    "*movsi_insv_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_95 },
#else
    { 0, 0, output_95 },
#endif
    0,
    &operand_data[152],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:2634 */
  {
    "*movqi_insv_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{b}\t{%h1, %h0|%h0, %h1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[154],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2647 */
  {
    "*pushtf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_97 },
#else
    { 0, 0, output_97 },
#endif
    0,
    &operand_data[156],
    2,
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:2667 */
  {
    "*pushxf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_98 },
#else
    { 0, 0, output_98 },
#endif
    0,
    &operand_data[158],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2685 */
  {
    "*pushxf_nointeger",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_99 },
#else
    { 0, 0, output_99 },
#endif
    0,
    &operand_data[160],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2706 */
  {
    "*pushdf_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_100 },
#else
    { 0, 0, output_100 },
#endif
    0,
    &operand_data[162],
    2,
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:2722 */
  {
    "*pushdf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_101 },
#else
    { 0, 0, output_101 },
#endif
    0,
    &operand_data[164],
    2,
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:2743 */
  {
    "*pushsf_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_102 },
#else
    { 0, 0, output_102 },
#endif
    0,
    &operand_data[166],
    2,
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:2756 */
  {
    "*pushsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_103 },
#else
    { 0, 0, output_103 },
#endif
    0,
    &operand_data[168],
    2,
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:2813 */
  {
    "*movtf_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_104 },
#else
    { 0, 0, output_104 },
#endif
    0,
    &operand_data[170],
    2,
    2,
    0,
    5,
    3
  },
  /* ../../gcc/config/i386/i386.md:2877 */
  {
    "*movxf_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_105 },
#else
    { 0, 0, output_105 },
#endif
    0,
    &operand_data[172],
    2,
    2,
    0,
    5,
    3
  },
  /* ../../gcc/config/i386/i386.md:2910 */
  {
    "*movdf_internal_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_106 },
#else
    { 0, 0, output_106 },
#endif
    0,
    &operand_data[174],
    2,
    2,
    0,
    13,
    3
  },
  /* ../../gcc/config/i386/i386.md:3051 */
  {
    "*movdf_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_107 },
#else
    { 0, 0, output_107 },
#endif
    0,
    &operand_data[176],
    2,
    2,
    0,
    13,
    3
  },
  /* ../../gcc/config/i386/i386.md:3185 */
  {
    "*movsf_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_108 },
#else
    { 0, 0, output_108 },
#endif
    0,
    &operand_data[178],
    2,
    2,
    0,
    16,
    3
  },
  /* ../../gcc/config/i386/i386.md:3357 */
  {
    "swapxf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_109 },
#else
    { 0, 0, output_109 },
#endif
    (insn_gen_fn) gen_swapxf,
    &operand_data[180],
    2,
    2,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3372 */
  {
    "*swapsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_110 },
#else
    { 0, 0, output_110 },
#endif
    0,
    &operand_data[182],
    2,
    2,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3372 */
  {
    "*swapdf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_111 },
#else
    { 0, 0, output_111 },
#endif
    0,
    &operand_data[184],
    2,
    2,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3401 */
  {
    "*zero_extendsidi2_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_112 },
#else
    { 0, output_112, 0 },
#endif
    0,
    &operand_data[186],
    2,
    2,
    0,
    6,
    2
  },
  /* ../../gcc/config/i386/i386.md:3426 */
  {
    "zero_extendsidi2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_113 },
#else
    { 0, output_113, 0 },
#endif
    (insn_gen_fn) gen_zero_extendsidi2_1,
    &operand_data[188],
    2,
    2,
    0,
    7,
    2
  },
  /* ../../gcc/config/i386/i386.md:3464 */
  {
    "zero_extendqidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{bl|x}\t{%1, %k0|%k0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendqidi2,
    &operand_data[190],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3464 */
  {
    "zero_extendhidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{wl|x}\t{%1, %k0|%k0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendhidi2,
    &operand_data[192],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3486 */
  {
    "zero_extendhisi2_and",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendhisi2_and,
    &operand_data[194],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3499 */
  {
    "*zero_extendhisi2_movzwl",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{wl|x}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[196],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3514 */
  {
    "*zero_extendqihi2_and",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[198],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:3514 */
  {
    "*zero_extendqisi2_and",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[200],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:3540 */
  {
    "*zero_extendqihi2_movzbl_and",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[202],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:3540 */
  {
    "*zero_extendqisi2_movzbl_and",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[204],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:3561 */
  {
    "*zero_extendqihi2_movzbl",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{bl|x}\t{%1, %k0|%k0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[206],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3561 */
  {
    "*zero_extendqisi2_movzbl",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{bl|x}\t{%1, %k0|%k0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[208],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3594 */
  {
    "*extendsidi2_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_124 },
#else
    { 0, output_124, 0 },
#endif
    0,
    &operand_data[210],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:3606 */
  {
    "extendsidi2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_extendsidi2_1,
    &operand_data[212],
    2,
    3,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:3689 */
  {
    "extendqidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movs{bq|x}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_extendqidi2,
    &operand_data[190],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3689 */
  {
    "extendhidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movs{wq|x}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_extendhidi2,
    &operand_data[192],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3698 */
  {
    "extendhisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_128 },
#else
    { 0, 0, output_128 },
#endif
    (insn_gen_fn) gen_extendhisi2,
    &operand_data[215],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:3724 */
  {
    "*extendhisi2_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_129 },
#else
    { 0, 0, output_129 },
#endif
    0,
    &operand_data[217],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:3752 */
  {
    "extendqisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movs{bl|x}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_extendqisi2,
    &operand_data[208],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3760 */
  {
    "*extendqisi2_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "movs{bl|x}\t{%1, %k0|%k0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[190],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3769 */
  {
    "extendqihi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_132 },
#else
    { 0, 0, output_132 },
#endif
    (insn_gen_fn) gen_extendqihi2,
    &operand_data[219],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:3882 */
  {
    "*extendsfdf2_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_133 },
#else
    { 0, 0, output_133 },
#endif
    0,
    &operand_data[221],
    2,
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:3905 */
  {
    "*extendsfdf2_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtss2sd\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[223],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3914 */
  {
    "*extendsfdf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_135 },
#else
    { 0, 0, output_135 },
#endif
    0,
    &operand_data[225],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:3942 */
  {
    "*extendsfxf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_136 },
#else
    { 0, 0, output_136 },
#endif
    0,
    &operand_data[227],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:3942 */
  {
    "*extenddfxf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_137 },
#else
    { 0, 0, output_137 },
#endif
    0,
    &operand_data[229],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:4031 */
  {
    "*truncdfsf_fast_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_138 },
#else
    { 0, 0, output_138 },
#endif
    0,
    &operand_data[231],
    2,
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:4053 */
  {
    "*truncdfsf_fast_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsd2ss\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[233],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4063 */
  {
    "*truncdfsf_fast_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_140 },
#else
    { 0, 0, output_140 },
#endif
    0,
    &operand_data[235],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4072 */
  {
    "*truncdfsf_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_141 },
#else
    { 0, 0, output_141 },
#endif
    0,
    &operand_data[237],
    3,
    3,
    0,
    5,
    3
  },
  /* ../../gcc/config/i386/i386.md:4096 */
  {
    "*truncdfsf_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_142 },
#else
    { 0, 0, output_142 },
#endif
    0,
    &operand_data[240],
    3,
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:4116 */
  {
    "*truncdfsf2_i387_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_143 },
#else
    { 0, 0, output_143 },
#endif
    0,
    &operand_data[243],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4163 */
  {
    "*truncxfsf2_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_144 },
#else
    { 0, 0, output_144 },
#endif
    0,
    &operand_data[245],
    3,
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:4177 */
  {
    "*truncxfdf2_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_145 },
#else
    { 0, 0, output_145 },
#endif
    0,
    &operand_data[248],
    3,
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:4192 */
  {
    "truncxfsf2_i387_noop",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_146 },
#else
    { 0, 0, output_146 },
#endif
    (insn_gen_fn) gen_truncxfsf2_i387_noop,
    &operand_data[251],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4192 */
  {
    "truncxfdf2_i387_noop",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_147 },
#else
    { 0, 0, output_147 },
#endif
    (insn_gen_fn) gen_truncxfdf2_i387_noop,
    &operand_data[253],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4201 */
  {
    "*truncxfsf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_148 },
#else
    { 0, 0, output_148 },
#endif
    0,
    &operand_data[255],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4201 */
  {
    "*truncxfdf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_149 },
#else
    { 0, 0, output_149 },
#endif
    0,
    &operand_data[257],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4343 */
  {
    "*fixuns_truncsf_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[259],
    5,
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4343 */
  {
    "*fixuns_truncdf_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[264],
    5,
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4373 */
  {
    "fix_truncsfdi_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvttss2si{q}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncsfdi_sse,
    &operand_data[269],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4373 */
  {
    "fix_truncdfdi_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvttsd2si{q}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncdfdi_sse,
    &operand_data[271],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4387 */
  {
    "fix_truncsfsi_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvttss2si\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncsfsi_sse,
    &operand_data[273],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4387 */
  {
    "fix_truncdfsi_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvttsd2si\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncdfsi_sse,
    &operand_data[275],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4428 */
  {
    "fix_trunchi_fisttp_i387_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_trunchi_fisttp_i387_1,
    &operand_data[277],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4428 */
  {
    "fix_truncsi_fisttp_i387_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncsi_fisttp_i387_1,
    &operand_data[279],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4428 */
  {
    "fix_truncdi_fisttp_i387_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncdi_fisttp_i387_1,
    &operand_data[281],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4455 */
  {
    "fix_trunchi_i387_fisttp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_159 },
#else
    { 0, 0, output_159 },
#endif
    (insn_gen_fn) gen_fix_trunchi_i387_fisttp,
    &operand_data[283],
    2,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4455 */
  {
    "fix_truncsi_i387_fisttp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_160 },
#else
    { 0, 0, output_160 },
#endif
    (insn_gen_fn) gen_fix_truncsi_i387_fisttp,
    &operand_data[286],
    2,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4455 */
  {
    "fix_truncdi_i387_fisttp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_161 },
#else
    { 0, 0, output_161 },
#endif
    (insn_gen_fn) gen_fix_truncdi_i387_fisttp,
    &operand_data[289],
    2,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4468 */
  {
    "fix_trunchi_i387_fisttp_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_trunchi_i387_fisttp_with_temp,
    &operand_data[292],
    3,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4468 */
  {
    "fix_truncsi_i387_fisttp_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncsi_i387_fisttp_with_temp,
    &operand_data[296],
    3,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4468 */
  {
    "fix_truncdi_i387_fisttp_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncdi_i387_fisttp_with_temp,
    &operand_data[300],
    3,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4506 */
  {
    "*fix_trunchi_i387_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[277],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4506 */
  {
    "*fix_truncsi_i387_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[279],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4506 */
  {
    "*fix_truncdi_i387_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[281],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4539 */
  {
    "fix_truncdi_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_168 },
#else
    { 0, 0, output_168 },
#endif
    (insn_gen_fn) gen_fix_truncdi_i387,
    &operand_data[304],
    4,
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4553 */
  {
    "fix_truncdi_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncdi_i387_with_temp,
    &operand_data[309],
    5,
    6,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4595 */
  {
    "fix_trunchi_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_170 },
#else
    { 0, 0, output_170 },
#endif
    (insn_gen_fn) gen_fix_trunchi_i387,
    &operand_data[315],
    4,
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4595 */
  {
    "fix_truncsi_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_171 },
#else
    { 0, 0, output_171 },
#endif
    (insn_gen_fn) gen_fix_truncsi_i387,
    &operand_data[319],
    4,
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4608 */
  {
    "fix_trunchi_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_trunchi_i387_with_temp,
    &operand_data[323],
    5,
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4608 */
  {
    "fix_truncsi_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncsi_i387_with_temp,
    &operand_data[328],
    5,
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4645 */
  {
    "x86_fnstcw_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnstcw\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_x86_fnstcw_1,
    &operand_data[283],
    1,
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4656 */
  {
    "x86_fldcw_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fldcw\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_x86_fldcw_1,
    &operand_data[45],
    1,
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4682 */
  {
    "*floathisf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[333],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4682 */
  {
    "*floathidf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[335],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4682 */
  {
    "*floathixf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[337],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4696 */
  {
    "*floathisf2_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[339],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4696 */
  {
    "*floathidf2_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[342],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4696 */
  {
    "*floathixf2_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[345],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4709 */
  {
    "*floathisf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[348],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4709 */
  {
    "*floathidf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[350],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4709 */
  {
    "*floathixf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[352],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4771 */
  {
    "*floatsisf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[354],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4771 */
  {
    "*floatsidf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[356],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4771 */
  {
    "*floatsixf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[358],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4771 */
  {
    "*floatdisf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[360],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4771 */
  {
    "*floatdidf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[362],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4771 */
  {
    "*floatdixf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[364],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4808 */
  {
    "*floatsisf2_vector_mixed_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[366],
    3,
    3,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/i386.md:4808 */
  {
    "*floatsidf2_vector_mixed_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[369],
    3,
    3,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/i386.md:4824 */
  {
    "*floatsisf2_vector_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_193 },
#else
    { 0, output_193, 0 },
#endif
    0,
    &operand_data[372],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:4824 */
  {
    "*floatsidf2_vector_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_194 },
#else
    { 0, output_194, 0 },
#endif
    0,
    &operand_data[374],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:4840 */
  {
    "*floatsisf2_mixed_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[376],
    3,
    3,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:4840 */
  {
    "*floatsidf2_mixed_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[379],
    3,
    3,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:4840 */
  {
    "*floatdisf2_mixed_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[382],
    3,
    3,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:4840 */
  {
    "*floatdidf2_mixed_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[385],
    3,
    3,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:4883 */
  {
    "*floatsisf2_mixed_interunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_199 },
#else
    { 0, output_199, 0 },
#endif
    0,
    &operand_data[388],
    2,
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:4883 */
  {
    "*floatsidf2_mixed_interunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_200 },
#else
    { 0, output_200, 0 },
#endif
    0,
    &operand_data[390],
    2,
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:4883 */
  {
    "*floatdisf2_mixed_interunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_201 },
#else
    { 0, output_201, 0 },
#endif
    0,
    &operand_data[392],
    2,
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:4883 */
  {
    "*floatdidf2_mixed_interunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_202 },
#else
    { 0, output_202, 0 },
#endif
    0,
    &operand_data[394],
    2,
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:4909 */
  {
    "*floatsisf2_mixed_nointerunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_203 },
#else
    { 0, output_203, 0 },
#endif
    0,
    &operand_data[372],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:4909 */
  {
    "*floatsidf2_mixed_nointerunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_204 },
#else
    { 0, output_204, 0 },
#endif
    0,
    &operand_data[374],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:4909 */
  {
    "*floatdisf2_mixed_nointerunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_205 },
#else
    { 0, output_205, 0 },
#endif
    0,
    &operand_data[396],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:4909 */
  {
    "*floatdidf2_mixed_nointerunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_206 },
#else
    { 0, output_206, 0 },
#endif
    0,
    &operand_data[398],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:4933 */
  {
    "*floatsisf2_vector_sse_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[400],
    3,
    3,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:4933 */
  {
    "*floatsidf2_vector_sse_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[403],
    3,
    3,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:4948 */
  {
    "*floatsisf2_vector_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[406],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4948 */
  {
    "*floatsidf2_vector_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[408],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5099 */
  {
    "*floatsisf2_sse_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[410],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5099 */
  {
    "*floatsidf2_sse_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[413],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5099 */
  {
    "*floatdisf2_sse_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[416],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5099 */
  {
    "*floatdidf2_sse_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[419],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5114 */
  {
    "*floatsisf2_sse_interunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2ss\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[410],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5114 */
  {
    "*floatsidf2_sse_interunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2sd\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[413],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5114 */
  {
    "*floatdisf2_sse_interunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2ss{q}\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[416],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5114 */
  {
    "*floatdidf2_sse_interunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2sd{q}\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[419],
    2,
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5149 */
  {
    "*floatsisf2_sse_nointerunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2ss\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[406],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5149 */
  {
    "*floatsidf2_sse_nointerunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2sd\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[408],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5149 */
  {
    "*floatdisf2_sse_nointerunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2ss{q}\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[422],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5149 */
  {
    "*floatdidf2_sse_nointerunit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2sd{q}\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[424],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5197 */
  {
    "*floatsisf2_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_223 },
#else
    { 0, output_223, 0 },
#endif
    0,
    &operand_data[426],
    3,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5197 */
  {
    "*floatsidf2_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_224 },
#else
    { 0, output_224, 0 },
#endif
    0,
    &operand_data[429],
    3,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5197 */
  {
    "*floatsixf2_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_225 },
#else
    { 0, output_225, 0 },
#endif
    0,
    &operand_data[432],
    3,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5197 */
  {
    "*floatdisf2_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_226 },
#else
    { 0, output_226, 0 },
#endif
    0,
    &operand_data[435],
    3,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5197 */
  {
    "*floatdidf2_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_227 },
#else
    { 0, output_227, 0 },
#endif
    0,
    &operand_data[438],
    3,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5197 */
  {
    "*floatdixf2_i387_with_temp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_228 },
#else
    { 0, output_228, 0 },
#endif
    0,
    &operand_data[441],
    3,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5212 */
  {
    "*floatsisf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[444],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5212 */
  {
    "*floatsidf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[446],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5212 */
  {
    "*floatsixf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[448],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5212 */
  {
    "*floatdisf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[450],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5212 */
  {
    "*floatdidf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[452],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5212 */
  {
    "*floatdixf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[454],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5245 */
  {
    "floatdisf2_i387_with_xmm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_floatdisf2_i387_with_xmm,
    &operand_data[456],
    3,
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5245 */
  {
    "floatdidf2_i387_with_xmm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_floatdidf2_i387_with_xmm,
    &operand_data[461],
    3,
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5245 */
  {
    "floatdixf2_i387_with_xmm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_floatdixf2_i387_with_xmm,
    &operand_data[466],
    3,
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5304 */
  {
    "*floatunssisf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[471],
    3,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5304 */
  {
    "*floatunssidf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[475],
    3,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5304 */
  {
    "*floatunssixf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[479],
    3,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5397 */
  {
    "*leasi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_241 },
#else
    { 0, 0, output_241 },
#endif
    0,
    &operand_data[483],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:5397 */
  {
    "*leadi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_242 },
#else
    { 0, 0, output_242 },
#endif
    0,
    &operand_data[485],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:5439 */
  {
    "*adddi3_doubleword",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[487],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5439 */
  {
    "*addti3_doubleword",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[490],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5462 */
  {
    "*addsi3_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[493],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5462 */
  {
    "*adddi3_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[496],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5475 */
  {
    "addqi3_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_addqi3_cc,
    &operand_data[499],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5488 */
  {
    "*addsi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_248 },
#else
    { 0, 0, output_248 },
#endif
    0,
    &operand_data[502],
    3,
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:5488 */
  {
    "*adddi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_249 },
#else
    { 0, 0, output_249 },
#endif
    0,
    &operand_data[505],
    3,
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:5547 */
  {
    "addsi_1_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_250 },
#else
    { 0, 0, output_250 },
#endif
    (insn_gen_fn) gen_addsi_1_zext,
    &operand_data[508],
    3,
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:5598 */
  {
    "*addhi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_251 },
#else
    { 0, 0, output_251 },
#endif
    0,
    &operand_data[511],
    3,
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:5651 */
  {
    "*addqi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_252 },
#else
    { 0, 0, output_252 },
#endif
    0,
    &operand_data[514],
    3,
    3,
    0,
    6,
    3
  },
  /* ../../gcc/config/i386/i386.md:5712 */
  {
    "*addqi_1_slp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_253 },
#else
    { 0, 0, output_253 },
#endif
    0,
    &operand_data[517],
    2,
    2,
    1,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:5796 */
  {
    "*addqi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_254 },
#else
    { 0, 0, output_254 },
#endif
    0,
    &operand_data[519],
    3,
    3,
    2,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:5796 */
  {
    "*addhi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_255 },
#else
    { 0, 0, output_255 },
#endif
    0,
    &operand_data[522],
    3,
    3,
    2,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:5796 */
  {
    "*addsi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_256 },
#else
    { 0, 0, output_256 },
#endif
    0,
    &operand_data[525],
    3,
    3,
    2,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:5796 */
  {
    "*adddi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_257 },
#else
    { 0, 0, output_257 },
#endif
    0,
    &operand_data[528],
    3,
    3,
    2,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:5845 */
  {
    "*addsi_2_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_258 },
#else
    { 0, 0, output_258 },
#endif
    0,
    &operand_data[531],
    3,
    3,
    2,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:5891 */
  {
    "*addqi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_259 },
#else
    { 0, 0, output_259 },
#endif
    0,
    &operand_data[534],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:5891 */
  {
    "*addhi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_260 },
#else
    { 0, 0, output_260 },
#endif
    0,
    &operand_data[537],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:5891 */
  {
    "*addsi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_261 },
#else
    { 0, 0, output_261 },
#endif
    0,
    &operand_data[540],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:5891 */
  {
    "*adddi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_262 },
#else
    { 0, 0, output_262 },
#endif
    0,
    &operand_data[543],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:5937 */
  {
    "*addsi_3_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_263 },
#else
    { 0, 0, output_263 },
#endif
    0,
    &operand_data[531],
    3,
    3,
    2,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:5989 */
  {
    "*adddi_4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_264 },
#else
    { 0, 0, output_264 },
#endif
    0,
    &operand_data[546],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6034 */
  {
    "*addqi_4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_265 },
#else
    { 0, 0, output_265 },
#endif
    0,
    &operand_data[549],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6034 */
  {
    "*addhi_4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_266 },
#else
    { 0, 0, output_266 },
#endif
    0,
    &operand_data[552],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6034 */
  {
    "*addsi_4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_267 },
#else
    { 0, 0, output_267 },
#endif
    0,
    &operand_data[555],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6071 */
  {
    "*addqi_5",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_268 },
#else
    { 0, 0, output_268 },
#endif
    0,
    &operand_data[534],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6071 */
  {
    "*addhi_5",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_269 },
#else
    { 0, 0, output_269 },
#endif
    0,
    &operand_data[537],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6071 */
  {
    "*addsi_5",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_270 },
#else
    { 0, 0, output_270 },
#endif
    0,
    &operand_data[540],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6071 */
  {
    "*adddi_5",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_271 },
#else
    { 0, 0, output_271 },
#endif
    0,
    &operand_data[543],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6118 */
  {
    "*addqi_ext_1_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_272 },
#else
    { 0, 0, output_272 },
#endif
    0,
    &operand_data[558],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6153 */
  {
    "addqi_ext_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_273 },
#else
    { 0, 0, output_273 },
#endif
    (insn_gen_fn) gen_addqi_ext_1,
    &operand_data[561],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6188 */
  {
    "*addqi_ext_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{b}\t{%h2, %h0|%h0, %h2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[564],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6210 */
  {
    "*lea_general_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[567],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6242 */
  {
    "*lea_general_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[571],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6272 */
  {
    "*lea_general_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[575],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6307 */
  {
    "*lea_general_4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[580],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6307 */
  {
    "*lea_general_4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[580],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6358 */
  {
    "*subdi3_doubleword",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[584],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6358 */
  {
    "*subti3_doubleword",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[587],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6380 */
  {
    "*subqi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[590],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6380 */
  {
    "*subhi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[593],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6380 */
  {
    "*subsi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[596],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6380 */
  {
    "*subdi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[599],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6391 */
  {
    "*subsi_1_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[602],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6402 */
  {
    "*subqi_1_slp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[517],
    2,
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6413 */
  {
    "*subqi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[590],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6413 */
  {
    "*subhi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[593],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6413 */
  {
    "*subsi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[596],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6413 */
  {
    "*subdi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[599],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6428 */
  {
    "*subsi_2_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[602],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6444 */
  {
    "*subqi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[590],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6444 */
  {
    "*subhi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[593],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6444 */
  {
    "*subsi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[596],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6444 */
  {
    "*subdi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[599],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6456 */
  {
    "*subsi_3_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %1|%1, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[602],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6484 */
  {
    "*addqi3_carry",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "adc{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[605],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6484 */
  {
    "*subqi3_carry",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[609],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6484 */
  {
    "*addhi3_carry",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "adc{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[613],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6484 */
  {
    "*subhi3_carry",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[617],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6484 */
  {
    "*addsi3_carry",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "adc{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[621],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6484 */
  {
    "*subsi3_carry",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[625],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6484 */
  {
    "*adddi3_carry",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "adc{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[629],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6484 */
  {
    "*subdi3_carry",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[633],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6500 */
  {
    "*addsi3_carry_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "adc{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[637],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6515 */
  {
    "*subsi3_carry_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[641],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6531 */
  {
    "*addqi3_cconly_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[645],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6531 */
  {
    "*addhi3_cconly_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[648],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6531 */
  {
    "*addsi3_cconly_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[651],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6531 */
  {
    "*adddi3_cconly_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[654],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6544 */
  {
    "*subqi3_cconly_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[9],
    2,
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6544 */
  {
    "*subhi3_cconly_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[11],
    2,
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6544 */
  {
    "*subsi3_cconly_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[13],
    2,
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6544 */
  {
    "*subdi3_cconly_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{q}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[15],
    2,
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6556 */
  {
    "*addqi3_cc_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[499],
    3,
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6556 */
  {
    "*subqi3_cc_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[590],
    3,
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6556 */
  {
    "*addhi3_cc_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[613],
    3,
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6556 */
  {
    "*subhi3_cc_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[593],
    3,
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6556 */
  {
    "*addsi3_cc_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[493],
    3,
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6556 */
  {
    "*subsi3_cc_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[596],
    3,
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6556 */
  {
    "*adddi3_cc_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[496],
    3,
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6556 */
  {
    "*subdi3_cc_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[599],
    3,
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:6570 */
  {
    "*addsi3_zext_cc_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[637],
    3,
    3,
    3,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6570 */
  {
    "*subsi3_zext_cc_overflow",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[657],
    3,
    3,
    3,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6628 */
  {
    "*mulsi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_326 },
#else
    { 0, output_326, 0 },
#endif
    0,
    &operand_data[660],
    3,
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:6628 */
  {
    "*muldi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_327 },
#else
    { 0, output_327, 0 },
#endif
    0,
    &operand_data[663],
    3,
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:6658 */
  {
    "*mulsi3_1_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_328 },
#else
    { 0, output_328, 0 },
#endif
    0,
    &operand_data[666],
    3,
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:6699 */
  {
    "*mulhi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_329 },
#else
    { 0, output_329, 0 },
#endif
    0,
    &operand_data[669],
    3,
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:6729 */
  {
    "*mulqi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul{b}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[672],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6766 */
  {
    "*bmi2_umulditi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulx\t{%3, %0, %1|%1, %0, %3}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[675],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6784 */
  {
    "*bmi2_umulsidi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulx\t{%3, %0, %1|%1, %0, %3}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[679],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6802 */
  {
    "*umulsidi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_333 },
#else
    { 0, output_333, 0 },
#endif
    0,
    &operand_data[683],
    3,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:6802 */
  {
    "*umulditi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_334 },
#else
    { 0, output_334, 0 },
#endif
    0,
    &operand_data[686],
    3,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:6853 */
  {
    "*mulsidi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "imul{l}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[689],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6853 */
  {
    "*mulditi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "imul{q}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[692],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6873 */
  {
    "*mulqihi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "imul{b}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[695],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6873 */
  {
    "*umulqihi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul{b}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[695],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6909 */
  {
    "*smuldi3_highpart_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "imul{q}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[698],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6909 */
  {
    "*umuldi3_highpart_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul{q}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[698],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6934 */
  {
    "*smulsi3_highpart_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "imul{l}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[702],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6934 */
  {
    "*umulsi3_highpart_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul{l}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[702],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6958 */
  {
    "*smulsi3_highpart_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "imul{l}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[706],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6958 */
  {
    "*umulsi3_highpart_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul{l}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[706],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7063 */
  {
    "divmodsi4_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_divmodsi4_1,
    &operand_data[710],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7063 */
  {
    "divmoddi4_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_divmoddi4_1,
    &operand_data[714],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7098 */
  {
    "*divmodhi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[718],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7098 */
  {
    "*divmodsi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[710],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7098 */
  {
    "*divmoddi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[714],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7133 */
  {
    "*divmodhi4_noext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "idiv{w}\t%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[722],
    5,
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7133 */
  {
    "*divmodsi4_noext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "idiv{l}\t%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[727],
    5,
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7133 */
  {
    "*divmoddi4_noext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "idiv{q}\t%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[732],
    5,
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7189 */
  {
    "divmodhiqi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "idiv{b}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_divmodhiqi3,
    &operand_data[737],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7236 */
  {
    "udivmodsi4_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_udivmodsi4_1,
    &operand_data[710],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7236 */
  {
    "udivmoddi4_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_udivmoddi4_1,
    &operand_data[714],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7258 */
  {
    "*udivmodhi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[718],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7258 */
  {
    "*udivmodsi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[710],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7258 */
  {
    "*udivmoddi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[714],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7279 */
  {
    "*udivmodhi4_noext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "div{w}\t%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[722],
    5,
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7279 */
  {
    "*udivmodsi4_noext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "div{l}\t%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[727],
    5,
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7279 */
  {
    "*udivmoddi4_noext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "div{q}\t%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[732],
    5,
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7330 */
  {
    "udivmodhiqi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "div{b}\t%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_udivmodhiqi3,
    &operand_data[737],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7394 */
  {
    "*testdi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_363 },
#else
    { 0, output_363, 0 },
#endif
    0,
    &operand_data[740],
    2,
    2,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/i386.md:7413 */
  {
    "*testqi_1_maybe_si",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_364 },
#else
    { 0, 0, output_364 },
#endif
    0,
    &operand_data[742],
    2,
    2,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:7438 */
  {
    "*testqi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[744],
    2,
    2,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:7438 */
  {
    "*testhi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[746],
    2,
    2,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:7438 */
  {
    "*testsi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[748],
    2,
    2,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:7464 */
  {
    "*testqi_ext_0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t{%1, %h0|%h0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[750],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7482 */
  {
    "*testqi_ext_1_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t{%1, %h0|%h0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[18],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7498 */
  {
    "*testqi_ext_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t{%1, %h0|%h0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[752],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7514 */
  {
    "*testqi_ext_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t{%h1, %h0|%h0, %h1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[26],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7532 */
  {
    "*testqi_ext_3_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[754],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7554 */
  {
    "*testqi_ext_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[757],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7695 */
  {
    "*anddi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_374 },
#else
    { 0, 0, output_374 },
#endif
    0,
    &operand_data[760],
    3,
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:7748 */
  {
    "*andsi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_375 },
#else
    { 0, 0, output_375 },
#endif
    0,
    &operand_data[763],
    3,
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:7794 */
  {
    "*andsi_1_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[637],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7805 */
  {
    "*andhi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_377 },
#else
    { 0, 0, output_377 },
#endif
    0,
    &operand_data[766],
    3,
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:7836 */
  {
    "*andqi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_378 },
#else
    { 0, output_378, 0 },
#endif
    0,
    &operand_data[769],
    3,
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:7849 */
  {
    "*andqi_1_slp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[772],
    2,
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7900 */
  {
    "*anddi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_380 },
#else
    { 0, output_380, 0 },
#endif
    0,
    &operand_data[774],
    3,
    3,
    2,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:7918 */
  {
    "*andqi_2_maybe_si",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_381 },
#else
    { 0, 0, output_381 },
#endif
    0,
    &operand_data[777],
    3,
    3,
    2,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:7942 */
  {
    "*andqi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[780],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7942 */
  {
    "*andhi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[783],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7942 */
  {
    "*andsi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[786],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7957 */
  {
    "*andsi_2_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[637],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7971 */
  {
    "*andqi_2_slp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[789],
    2,
    2,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7989 */
  {
    "andqi_ext_0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_andqi_ext_0,
    &operand_data[791],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8009 */
  {
    "*andqi_ext_0_cc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[791],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8035 */
  {
    "*andqi_ext_1_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[794],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8053 */
  {
    "*andqi_ext_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[797],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8071 */
  {
    "*andqi_ext_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%h2, %h0|%h0, %h2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[564],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8152 */
  {
    "*iorhi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[783],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8152 */
  {
    "*xorhi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[783],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8152 */
  {
    "*iorsi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[786],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8152 */
  {
    "*xorsi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[786],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8152 */
  {
    "*iordi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[800],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8152 */
  {
    "*xordi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[800],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8164 */
  {
    "*iorqi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_398 },
#else
    { 0, output_398, 0 },
#endif
    0,
    &operand_data[803],
    3,
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:8164 */
  {
    "*xorqi_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_399 },
#else
    { 0, output_399, 0 },
#endif
    0,
    &operand_data[803],
    3,
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:8178 */
  {
    "*iorsi_1_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[637],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8178 */
  {
    "*xorsi_1_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[637],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8189 */
  {
    "*iorsi_1_zext_imm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[806],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8189 */
  {
    "*xorsi_1_zext_imm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[806],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8200 */
  {
    "*iorqi_1_slp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[809],
    2,
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8200 */
  {
    "*xorqi_1_slp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[809],
    2,
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8211 */
  {
    "*iorqi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[780],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8211 */
  {
    "*xorqi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[780],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8211 */
  {
    "*iorhi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[783],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8211 */
  {
    "*xorhi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[783],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8211 */
  {
    "*iorsi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[786],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8211 */
  {
    "*xorsi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[786],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8211 */
  {
    "*iordi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[800],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8211 */
  {
    "*xordi_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[800],
    3,
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8227 */
  {
    "*iorsi_2_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[637],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8227 */
  {
    "*xorsi_2_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[637],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8240 */
  {
    "*iorsi_2_zext_imm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[811],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8240 */
  {
    "*xorsi_2_zext_imm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t{%2, %k0|%k0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[811],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8254 */
  {
    "*iorqi_2_slp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[814],
    2,
    2,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8254 */
  {
    "*xorqi_2_slp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[814],
    2,
    2,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8268 */
  {
    "*iorqi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[645],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8268 */
  {
    "*xorqi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[645],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8268 */
  {
    "*iorhi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[648],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8268 */
  {
    "*xorhi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[648],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8268 */
  {
    "*iorsi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[651],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8268 */
  {
    "*xorsi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[651],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8268 */
  {
    "*iordi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[654],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8268 */
  {
    "*xordi_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[654],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8281 */
  {
    "*iorqi_ext_0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[791],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8281 */
  {
    "*xorqi_ext_0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[791],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8299 */
  {
    "*iorqi_ext_1_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[794],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8299 */
  {
    "*xorqi_ext_1_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[794],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8318 */
  {
    "*iorqi_ext_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[797],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8318 */
  {
    "*xorqi_ext_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[797],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8337 */
  {
    "*iorqi_ext_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%h2, %h0|%h0, %h2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[794],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8337 */
  {
    "*xorqi_ext_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%h2, %h0|%h0, %h2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[794],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8420 */
  {
    "*xorqi_cc_ext_1_rex64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[558],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8445 */
  {
    "*xorqi_cc_ext_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[816],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8478 */
  {
    "*negdi2_doubleword",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[819],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8478 */
  {
    "*negti2_doubleword",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[821],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8501 */
  {
    "*negqi2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{b}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[823],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8501 */
  {
    "*neghi2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{w}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[825],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8501 */
  {
    "*negsi2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{l}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[827],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8501 */
  {
    "*negdi2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{q}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[829],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8511 */
  {
    "*negsi2_1_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{l}\t%k0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[831],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8527 */
  {
    "*negqi2_cmpz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{b}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[823],
    2,
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8527 */
  {
    "*neghi2_cmpz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{w}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[825],
    2,
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8527 */
  {
    "*negsi2_cmpz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{l}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[827],
    2,
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8527 */
  {
    "*negdi2_cmpz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{q}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[829],
    2,
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8539 */
  {
    "*negsi2_cmpz_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{l}\t%k0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[831],
    2,
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8565 */
  {
    "*absnegsf2_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[833],
    4,
    4,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:8565 */
  {
    "*absnegdf2_mixed",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[837],
    4,
    4,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:8574 */
  {
    "*absnegsf2_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[841],
    4,
    4,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:8574 */
  {
    "*absnegdf2_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[845],
    4,
    4,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:8583 */
  {
    "*absnegsf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[849],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8583 */
  {
    "*absnegdf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[853],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8583 */
  {
    "*absnegxf2_i387",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[857],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8598 */
  {
    "*absnegtf2_sse",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[861],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8736 */
  {
    "*abssf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[865],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8736 */
  {
    "*negsf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[865],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8736 */
  {
    "*absdf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[867],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8736 */
  {
    "*negdf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[867],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8736 */
  {
    "*absxf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[869],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8736 */
  {
    "*negxf2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[869],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8746 */
  {
    "*absextendsfdf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[871],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8746 */
  {
    "*negextendsfdf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[871],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8755 */
  {
    "*absextendsfxf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[873],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8755 */
  {
    "*negextendsfxf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[873],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8764 */
  {
    "*absextenddfxf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[875],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8764 */
  {
    "*negextenddfxf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[875],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8786 */
  {
    "copysignsf3_const",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_copysignsf3_const,
    &operand_data[877],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8786 */
  {
    "copysigndf3_const",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_copysigndf3_const,
    &operand_data[881],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8786 */
  {
    "copysigntf3_const",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_copysigntf3_const,
    &operand_data[885],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8800 */
  {
    "copysignsf3_var",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_copysignsf3_var,
    &operand_data[889],
    6,
    6,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/i386.md:8800 */
  {
    "copysigndf3_var",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_copysigndf3_var,
    &operand_data[895],
    6,
    6,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/i386.md:8800 */
  {
    "copysigntf3_var",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_copysigntf3_var,
    &operand_data[901],
    6,
    6,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/i386.md:8836 */
  {
    "*one_cmplhi2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "not{w}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[825],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8836 */
  {
    "*one_cmplsi2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "not{l}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[827],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8836 */
  {
    "*one_cmpldi2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "not{q}\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[829],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8845 */
  {
    "*one_cmplqi2_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_479 },
#else
    { 0, output_479, 0 },
#endif
    0,
    &operand_data[907],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8856 */
  {
    "*one_cmplsi2_1_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "not{l}\t%k0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[602],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8865 */
  {
    "*one_cmplqi2_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[823],
    2,
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8865 */
  {
    "*one_cmplhi2_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[825],
    2,
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8865 */
  {
    "*one_cmplsi2_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[827],
    2,
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8865 */
  {
    "*one_cmpldi2_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[829],
    2,
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8892 */
  {
    "*one_cmplsi2_2_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[602],
    2,
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8949 */
  {
    "*ashldi3_doubleword",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[909],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8949 */
  {
    "*ashlti3_doubleword",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[912],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8983 */
  {
    "x86_64_shld",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "shld{q}\t{%s2%1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_x86_64_shld,
    &operand_data[915],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8999 */
  {
    "x86_shld",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "shld{l}\t{%s2%1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_x86_shld,
    &operand_data[918],
    3,
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9062 */
  {
    "*ashlsi3_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[921],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9062 */
  {
    "*ashldi3_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[925],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9088 */
  {
    "*bmi2_ashlsi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "shlx\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[929],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9088 */
  {
    "*bmi2_ashldi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "shlx\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[932],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9097 */
  {
    "*ashlsi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_494 },
#else
    { 0, 0, output_494 },
#endif
    0,
    &operand_data[935],
    3,
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:9097 */
  {
    "*ashldi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_495 },
#else
    { 0, 0, output_495 },
#endif
    0,
    &operand_data[938],
    3,
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:9157 */
  {
    "*bmi2_ashlsi3_1_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "shlx\t{%2, %1, %k0|%k0, %1, %2}",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[941],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9167 */
  {
    "*ashlsi3_1_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_497 },
#else
    { 0, 0, output_497 },
#endif
    0,
    &operand_data[944],
    3,
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:9227 */
  {
    "*ashlhi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_498 },
#else
    { 0, 0, output_498 },
#endif
    0,
    &operand_data[947],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:9272 */
  {
    "*ashlqi3_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_499 },
#else
    { 0, 0, output_499 },
#endif
    0,
    &operand_data[950],
    3,
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:9329 */
  {
    "*ashlqi3_1_slp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_500 },
#else
    { 0, 0, output_500 },
#endif
    0,
    &operand_data[953],
    2,
    2,
    1,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9420 */
  {
    "*ashlqi3_cmp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_501 },
#else
    { 0, 0, output_501 },
#endif
    0,
    &operand_data[955],
    3,
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9420 */
  {
    "*ashlhi3_cmp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_502 },
#else
    { 0, 0, output_502 },
#endif
    0,
    &operand_data[958],
    3,
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9420 */
  {
    "*ashlsi3_cmp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_503 },
#else
    { 0, 0, output_503 },
#endif
    0,
    &operand_data[961],
    3,
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9420 */
  {
    "*ashldi3_cmp",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_504 },
#else
    { 0, 0, output_504 },
#endif
    0,
    &operand_data[964],
    3,
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9468 */
  {
    "*ashlsi3_cmp_zext",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_505 },
#else
    { 0, 0, output_505 },
#endif
    0,
    &operand_data[967],
    3,
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9516 */
  {
    "*ashlqi3_cconly",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_506 },
#else
    { 0, 0, output_506 },
#endif
    0,
    &operand_data[970],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9516 */
  {
    "*ashlhi3_cconly",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_507 },
#else
    { 0, 0, output_507 },
#endif
    0,
    &operand_data[973],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9516 */
  {
    "*ashlsi3_cconly",
#if HAVE_DESIGNATED_UNION_INITIALIZERS