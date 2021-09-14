/* Generated automatically by the program `genattr-common'
   from the machine description file `md'.  */

#ifndef GCC_INSN_ATTR_COMMON_H
#define GCC_INSN_ATTR_COMMON_H

enum attr_cpu {CPU_CFV1, CPU_CFV2, CPU_CFV3, CPU_CFV4, CPU_UNKNOWN};
enum attr_mac {MAC_NO, MAC_CF_MAC, MAC_CF_EMAC};
enum attr_type {TYPE_ALU_L, TYPE_ALUQ_L, TYPE_ALUX_L, TYPE_BCC, TYPE_BITR, TYPE_BITRW, TYPE_BRA, TYPE_BSR, TYPE_CLR, TYPE_CLR_L, TYPE_CMP, TYPE_CMP_L, TYPE_DIV_W, TYPE_DIV_L, TYPE_EXT, TYPE_FALU, TYPE_FBCC, TYPE_FCMP, TYPE_FDIV, TYPE_FMOVE, TYPE_FMUL, TYPE_FNEG, TYPE_FSQRT, TYPE_FTST, TYPE_IB, TYPE_IGNORE, TYPE_JMP, TYPE_JSR, TYPE_LEA, TYPE_LINK, TYPE_MOV3Q_L, TYPE_MOVE, TYPE_MOVE_L, TYPE_MOVEQ_L, TYPE_MUL_W, TYPE_MUL_L, TYPE_MVSZ, TYPE_NEG_L, TYPE_NOP, TYPE_PEA, TYPE_RTS, TYPE_SCC, TYPE_SHIFT, TYPE_TRAP, TYPE_TST, TYPE_TST_L, TYPE_UNLK, TYPE_UNKNOWN};
enum attr_opy_type {OPY_TYPE_NONE, OPY_TYPE_RN, OPY_TYPE_FPN, OPY_TYPE_MEM1, OPY_TYPE_MEM234, OPY_TYPE_MEM5, OPY_TYPE_MEM6, OPY_TYPE_MEM7, OPY_TYPE_IMM_Q, OPY_TYPE_IMM_W, OPY_TYPE_IMM_L};
enum attr_opx_type {OPX_TYPE_NONE, OPX_TYPE_RN, OPX_TYPE_FPN, OPX_TYPE_MEM1, OPX_TYPE_MEM234, OPX_TYPE_MEM5, OPX_TYPE_MEM6, OPX_TYPE_MEM7, OPX_TYPE_IMM_Q, OPX_TYPE_IMM_W, OPX_TYPE_IMM_L};
enum attr_opx_access {OPX_ACCESS_NONE, OPX_ACCESS_R, OPX_ACCESS_W, OPX_ACCESS_RW};
enum attr_op_mem {OP_MEM_00, OP_MEM_10, OP_MEM_I0, OP_MEM_01, OP_MEM_0I, OP_MEM_11, OP_MEM_I1, OP_MEM_1I};
enum attr_size {SIZE_1, SIZE_2, SIZE_3};
enum attr_ok_for_coldfire {OK_FOR_COLDFIRE_YES, OK_FOR_COLDFIRE_NO};
enum attr_flags_valid {FLAGS_VALID_NO, FLAGS_VALID_YES, FLAGS_VALID_SET, FLAGS_VALID_NOOV, FLAGS_VALID_MOVE, FLAGS_VALID_UNCHANGED};
#define INSN_SCHEDULING
#define DELAY_SLOTS 0

#endif /* GCC_INSN_ATTR_COMMON_H */
