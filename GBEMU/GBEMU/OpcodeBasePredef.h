#ifndef OPBP_H_
#define OPBP_H_

//GENERATED CODE. DO NOT MODIFY MANUALLY. 
static OperandBase G_OPERANDS[0x200] = {
	OperandBase(NOP,1,4,0,0x00,"NOP",ETC),
	OperandBase(LD_BC,3,12,0,0x01,"LD_BC",DATA16),
	OperandBase(LD_BD_A,1,8,0,0x02,"LD_BD_A",DATA8),
	OperandBase(INC_BC,1,8,0,0x03,"INC_BC",LOGIC16),
	OperandBase(INC_B,1,4,0,0x04,"INC_B",LOGIC8),
	OperandBase(DEC_B,1,4,0,0x05,"DEC_B",LOGIC8),
	OperandBase(LD_B_D8,2,8,0,0x06,"LD_B_D8",DATA8),
	OperandBase(RLCA,1,4,0,0x07,"RLCA",CB),
	OperandBase(LD_A16_SP,3,20,0,0x08,"LD_A16_SP",DATA16),
	OperandBase(ADD_HL_BC,1,8,0,0x09,"ADD_HL_BC",LOGIC16),
	OperandBase(LD_A_BC,1,8,0,0x0A,"LD_A_BC",DATA8),
	OperandBase(DEC_BC,1,8,0,0x0B,"DEC_BC",LOGIC16),
	OperandBase(INC_C,1,4,0,0x0C,"INC_C",LOGIC8),
	OperandBase(DEC_C,1,4,0,0x0D,"DEC_C",LOGIC8),
	OperandBase(LD_C_D8,2,8,0,0x0E,"LD_C_D8",DATA8),
	OperandBase(RRCA,1,4,0,0x0F,"RRCA",CB),
	OperandBase(STOP,2,4,0,0x10,"STOP",ETC),
	OperandBase(LD_DE_D16,3,12,0,0x11,"LD_DE_D16",DATA16),
	OperandBase(LD_DE_A,1,8,0,0x12,"LD_DE_A",DATA8),
	OperandBase(INC_DE,1,8,0,0x13,"INC_DE",LOGIC16),
	OperandBase(INC_D,1,4,0,0x14,"INC_D",LOGIC8),
	OperandBase(DEC_D,1,4,0,0x15,"DEC_D",LOGIC8),
	OperandBase(LD_D_D8,2,8,0,0x16,"LD_D_D8",DATA8),
	OperandBase(RLA,1,4,0,0x17,"RLA",CB),
	OperandBase(JR_R8,2,12,0,0x18,"JR_R8",JMP),
	OperandBase(ADD_HL_DE,1,8,0,0x19,"ADD_HL_DC",LOGIC16),
	OperandBase(LD_A_DE,1,8,0,0x1A,"LD_A_DE",DATA8),
	OperandBase(DEC_DE,1,8,0,0x1B,"DEC_DE",LOGIC16),
	OperandBase(INC_E,1,4,0,0x1C,"INC_E",LOGIC8),
	OperandBase(DEC_E,1,4,0,0x1D,"DEC_E",LOGIC8),
	OperandBase(LD_E_D8,2,8,0,0x1E,"LD_E_D8",DATA8),
	OperandBase(RRA,1,4,0,0x1F,"RRA",CB),
	OperandBase(JR_NZ_R8,2,8,12,0x20,"JR_NZ_R8",JMP),
	OperandBase(LD_HL_D16,3,12,0,0x21,"LD_HL_D16",DATA16),
	OperandBase(LD_HL_PLUS_A,1,8,0,0x22,"LD_HL_PLUS_A",DATA8),
	OperandBase(INC_HL,1,8,0,0x23,"INC_HL",LOGIC16),
	OperandBase(INC_H,1,4,0,0x24,"INC_H",LOGIC8),
	OperandBase(DEC_H,1,4,0,0x25,"DEC_H",LOGIC8),
	OperandBase(LD_H_D8,2,8,0,0x26,"LD_H_D8",DATA8),
	OperandBase(DAA,1,4,0,0x27,"DAA",LOGIC8),
	OperandBase(JR_Z_R8,2,8,12,0x28,"JR_Z_R8",JMP),
	OperandBase(ADD_HL_HL,1,8,0,0x29,"ADD_HL_HL",LOGIC16),
	OperandBase(LD_A_HLA_PLUS,1,8,0,0x2A,"LD_A_HLA_PLUS",DATA8),
	OperandBase(DEC_HL,1,8,0,0x2B,"DEC_HL",LOGIC16),
	OperandBase(INC_L,1,4,0,0x2C,"INC_L",LOGIC8),
	OperandBase(DEC_L,1,4,0,0x2D,"DEC_L",LOGIC8),
	OperandBase(LD_L_D8,2,8,0,0x2E,"LD_L_D8",DATA8),
	OperandBase(CPL,1,4,0,0x2F,"CPL",LOGIC8),
	OperandBase(JR_NC_R8,2,8,12,0x30,"JR_NC_R8",JMP),
	OperandBase(LD_SP_D16,3,12,0,0x31,"LD_SP_D16",DATA16),
	OperandBase(LD_HL_MNUS_A,1,8,0,0x32,"LD_HL_MNUS_A",DATA8),
	OperandBase(INC_SP,1,8,0,0x33,"INC_SP",LOGIC16),
	OperandBase(INC_HLA,1,12,0,0x34,"INC_HLA",LOGIC8),
	OperandBase(DEC_HLA,1,12,0,0x35,"DEC_HLA",LOGIC8),
	OperandBase(LD_HLA_D8,2,12,0,0x36,"LD_HLA_D8",DATA8),
	OperandBase(SCF,1,4,0,0x37,"SCF",LOGIC8),
	OperandBase(JR_C_R8,2,8,12,0x38,"JR_C_R8",JMP),
	OperandBase(ADD_HL_SP,1,8,0,0x39,"ADD_HL_SP",LOGIC16),
	OperandBase(LD_A_HLA_MNUS,1,8,0,0x3A,"LD_A_HLA_MNUS",DATA8),
	OperandBase(DEC_SP,1,8,0,0x3B,"DEC_SP",LOGIC16),
	OperandBase(INC_A,1,4,0,0x3C,"INC_A",LOGIC8),
	OperandBase(DEC_A,1,4,0,0x3D,"DEC_A",LOGIC8),
	OperandBase(LD_A_D8,2,8,0,0x3E,"LD_A_D8",DATA8),
	OperandBase(CCF,1,4,0,0x3F,"CCF",LOGIC8),
	OperandBase(LD_B_B,1,4,0,0x40,"LD_B_B",DATA8),
	OperandBase(LD_B_C,1,4,0,0x41,"LD_B_C",DATA8),
	OperandBase(LD_B_D,1,4,0,0x42,"LD_B_D",DATA8),
	OperandBase(LD_B_E,1,4,0,0x43,"LD_B_E",DATA8),
	OperandBase(LD_B_H,1,4,0,0x44,"LD_B_H",DATA8),
	OperandBase(LD_B_L,1,4,0,0x45,"LD_B_L",DATA8),
	OperandBase(LD_B_HLA,1,8,0,0x46,"LD_B_HLA",DATA8),
	OperandBase(LD_B_A,1,4,0,0x47,"LD_B_A",DATA8),
	OperandBase(LD_C_B,1,4,0,0x48,"LD_C_B",DATA8),
	OperandBase(LD_C_C,1,4,0,0x49,"LD_C_C",DATA8),
	OperandBase(LD_C_D,1,4,0,0x4A,"LD_C_D",DATA8),
	OperandBase(LD_C_E,1,4,0,0x4B,"LD_C_E",DATA8),
	OperandBase(LD_C_H,1,4,0,0x4C,"LD_C_H",DATA8),
	OperandBase(LD_C_L,1,4,0,0x4D,"LD_C_L",DATA8),
	OperandBase(LD_C_HLA,1,8,0,0x4E,"LD_C_HLA",DATA8),
	OperandBase(LD_C_A,1,4,0,0x4F,"LD_C_A",DATA8),
	OperandBase(LD_D_B,1,4,0,0x50,"LD_D_B",DATA8),
	OperandBase(LD_D_C,1,4,0,0x51,"LD_D_C",DATA8),
	OperandBase(LD_D_D,1,4,0,0x52,"LD_D_D",DATA8),
	OperandBase(LD_D_E,1,4,0,0x53,"LD_D_E",DATA8),
	OperandBase(LD_D_H,1,4,0,0x54,"LD_D_H",DATA8),
	OperandBase(LD_D_L,1,4,0,0x55,"LD_D_L",DATA8),
	OperandBase(LD_D_HLA,1,8,0,0x56,"LD_D_HLA",DATA8),
	OperandBase(LD_D_A,1,4,0,0x57,"LD_D_A",DATA8),
	OperandBase(LD_E_B,1,4,0,0x58,"LD_E_B",DATA8),
	OperandBase(LD_E_C,1,4,0,0x59,"LD_E_C",DATA8),
	OperandBase(LD_E_D,1,4,0,0x5A,"LD_E_D",DATA8),
	OperandBase(LD_E_E,1,4,0,0x5B,"LD_E_E",DATA8),
	OperandBase(LD_E_H,1,4,0,0x5C,"LD_E_H",DATA8),
	OperandBase(LD_E_L,1,4,0,0x5D,"LD_E_L",DATA8),
	OperandBase(LD_E_HLA,1,8,0,0x5E,"LD_E_HLA",DATA8),
	OperandBase(LD_E_A,1,4,0,0x5F,"LD_E_A",DATA8),
	OperandBase(LD_H_B,1,4,0,0x60,"LD_H_B",DATA8),
	OperandBase(LD_H_C,1,4,0,0x61,"LD_H_C",DATA8),
	OperandBase(LD_H_D,1,4,0,0x62,"LD_H_D",DATA8),
	OperandBase(LD_H_E,1,4,0,0x63,"LD_H_E",DATA8),
	OperandBase(LD_H_H,1,4,0,0x64,"LD_H_H",DATA8),
	OperandBase(LD_H_L,1,4,0,0x65,"LD_H_L",DATA8),
	OperandBase(LD_H_HLA,1,8,0,0x66,"LD_H_HLA",DATA8),
	OperandBase(LD_H_A,1,4,0,0x67,"LD_H_A",DATA8),
	OperandBase(LD_L_B,1,4,0,0x68,"LD_L_B",DATA8),
	OperandBase(LD_L_C,1,4,0,0x69,"LD_L_C",DATA8),
	OperandBase(LD_L_D,1,4,0,0x6A,"LD_L_D",DATA8),
	OperandBase(LD_L_E,1,4,0,0x6B,"LD_L_E",DATA8),
	OperandBase(LD_L_H,1,4,0,0x6C,"LD_L_H",DATA8),
	OperandBase(LD_L_L,1,4,0,0x6D,"LD_L_L",DATA8),
	OperandBase(LD_L_HLA,1,8,0,0x6E,"LD_L_HLA",DATA8),
	OperandBase(LD_L_A,1,4,0,0x6F,"LD_L_A",DATA8),
	OperandBase(LD_HLA_B,1,8,0,0x70,"LD_HLA_B",DATA8),
	OperandBase(LD_HLA_C,1,8,0,0x71,"LD_HLA_C",DATA8),
	OperandBase(LD_HLA_D,1,8,0,0x72,"LD_HLA_D",DATA8),
	OperandBase(LD_HLA_E,1,8,0,0x73,"LD_HLA_E",DATA8),
	OperandBase(LD_HLA_H,1,8,0,0x74,"LD_HLA_H",DATA8),
	OperandBase(LD_HLA_L,1,8,0,0x75,"LD_HLA_L",DATA8),
	OperandBase(HALT,1,4,0,0x76,"HALT",ETC),
	OperandBase(LD_HLA_A,1,8,0,0x77,"LD_HLA_A",DATA8),
	OperandBase(LD_A_B,1,4,0,0x78,"LD_A_B",DATA8),
	OperandBase(LD_A_C,1,4,0,0x79,"LD_A_C",DATA8),
	OperandBase(LD_A_D,1,4,0,0x7A,"LD_A_D",DATA8),
	OperandBase(LD_A_E,1,4,0,0x7B,"LD_A_E",DATA8),
	OperandBase(LD_A_H,1,4,0,0x7C,"LD_A_H",DATA8),
	OperandBase(LD_A_L,1,4,0,0x7D,"LD_A_L",DATA8),
	OperandBase(LD_A_HLA,1,8,0,0x7E,"LD_A_HLA",DATA8),
	OperandBase(LD_A_A,1,4,0,0x7F,"LD_A_A",DATA8),
	OperandBase(ADD_A_B,1,4,0,0x80,"ADD_A_B",LOGIC8),
	OperandBase(ADD_A_C,1,4,0,0x81,"ADD_A_C",LOGIC8),
	OperandBase(ADD_A_D,1,4,0,0x82,"ADD_A_D",LOGIC8),
	OperandBase(ADD_A_E,1,4,0,0x83,"ADD_A_E",LOGIC8),
	OperandBase(ADD_A_H,1,4,0,0x84,"ADD_A_H",LOGIC8),
	OperandBase(ADD_A_L,1,4,0,0x85,"ADD_A_L",LOGIC8),
	OperandBase(ADD_A_HLA,1,8,0,0x86,"ADD_A_HLA",LOGIC8),
	OperandBase(ADD_A_A,1,4,0,0x87,"ADD_A_A",LOGIC8),
	OperandBase(ADC_A_B,1,4,0,0x88,"ADC_A_B",LOGIC8),
	OperandBase(ADC_A_C,1,4,0,0x89,"ADC_A_C",LOGIC8),
	OperandBase(ADC_A_D,1,4,0,0x8A,"ADC_A_D",LOGIC8),
	OperandBase(ADC_A_E,1,4,0,0x8B,"ADC_A_E",LOGIC8),
	OperandBase(ADC_A_H,1,4,0,0x8C,"ADC_A_H",LOGIC8),
	OperandBase(ADC_A_L,1,4,0,0x8D,"ADC_A_L",LOGIC8),
	OperandBase(ADC_A_HLA,1,8,0,0x8E,"ADC_A_HLA",LOGIC8),
	OperandBase(ADC_A_A,1,4,0,0x8F,"ADC_A_A",LOGIC8),
	OperandBase(SUB_B,1,4,0,0x90,"SUB_B",LOGIC8),
	OperandBase(SUB_C,1,4,0,0x91,"SUB_C",LOGIC8),
	OperandBase(SUB_D,1,4,0,0x92,"SUB_D",LOGIC8),
	OperandBase(SUB_E,1,4,0,0x93,"SUB_E",LOGIC8),
	OperandBase(SUB_H,1,4,0,0x94,"SUB_H",LOGIC8),
	OperandBase(SUB_L,1,4,0,0x95,"SUB_L",LOGIC8),
	OperandBase(SUB_HLA,1,8,0,0x96,"SUB_HLA",LOGIC8),
	OperandBase(SUB_A,1,4,0,0x97,"SUB_A",LOGIC8),
	OperandBase(SBC_A_B,1,4,0,0x98,"SBC_A_B",LOGIC8),
	OperandBase(SBC_A_C,1,4,0,0x99,"SBC_A_C",LOGIC8),
	OperandBase(SBC_A_D,1,4,0,0x9A,"SBC_A_D",LOGIC8),
	OperandBase(SBC_A_E,1,4,0,0x9B,"SBC_A_E",LOGIC8),
	OperandBase(SBC_A_H,1,4,0,0x9C,"SBC_A_H",LOGIC8),
	OperandBase(SBC_A_L,1,4,0,0x9D,"SBC_A_L",LOGIC8),
	OperandBase(SBC_A_HLA,1,8,0,0x9E,"SBC_A_HLA",LOGIC8),
	OperandBase(SBC_A_A,1,4,0,0x9F,"SBC_A_A",LOGIC8),
	OperandBase(AND_B,1,4,0,0xA0,"AND_B",LOGIC8),
	OperandBase(AND_C,1,4,0,0xA1,"AND_C",LOGIC8),
	OperandBase(AND_D,1,4,0,0xA2,"AND_D",LOGIC8),
	OperandBase(AND_E,1,4,0,0xA3,"AND_E",LOGIC8),
	OperandBase(AND_H,1,4,0,0xA4,"AND_H",LOGIC8),
	OperandBase(AND_L,1,4,0,0xA5,"AND_L",LOGIC8),
	OperandBase(AND_HLA,1,8,0,0xA6,"AND_HLA",LOGIC8),
	OperandBase(AND_A,1,4,0,0xA7,"AND_A",LOGIC8),
	OperandBase(XOR_B,1,4,0,0xA8,"XOR_B",LOGIC8),
	OperandBase(XOR_C,1,4,0,0xA9,"XOR_C",LOGIC8),
	OperandBase(XOR_D,1,4,0,0xAA,"XOR_D",LOGIC8),
	OperandBase(XOR_E,1,4,0,0xAB,"XOR_E",LOGIC8),
	OperandBase(XOR_H,1,4,0,0xAC,"XOR_H",LOGIC8),
	OperandBase(XOR_L,1,4,0,0xAD,"XOR_L",LOGIC8),
	OperandBase(XOR_HLA,1,8,0,0xAE,"XOR_HLA",LOGIC8),
	OperandBase(XOR_A,1,4,0,0xAF,"XOR_A",LOGIC8),
	OperandBase(OR_B,1,4,0,0xB0,"OR_B",LOGIC8),
	OperandBase(OR_C,1,4,0,0xB1,"OR_C",LOGIC8),
	OperandBase(OR_D,1,4,0,0xB2,"OR_D",LOGIC8),
	OperandBase(OR_E,1,4,0,0xB3,"OR_E",LOGIC8),
	OperandBase(OR_H,1,4,0,0xB4,"OR_H",LOGIC8),
	OperandBase(OR_L,1,4,0,0xB5,"OR_L",LOGIC8),
	OperandBase(OR_HLA,1,8,0,0xB6,"OR_HLA",LOGIC8),
	OperandBase(OR_A,1,4,0,0xB7,"OR_A",LOGIC8),
	OperandBase(CP_B,1,4,0,0xB8,"CP_B",LOGIC8),
	OperandBase(CP_C,1,4,0,0xB9,"CP_C",LOGIC8),
	OperandBase(CP_D,1,4,0,0xBA,"CP_D",LOGIC8),
	OperandBase(CP_E,1,4,0,0xBB,"CP_E",LOGIC8),
	OperandBase(CP_H,1,4,0,0xBC,"CP_H",LOGIC8),
	OperandBase(CP_L,1,4,0,0xBD,"CP_L",LOGIC8),
	OperandBase(CP_HLA,1,8,0,0xBE,"CP_HLA",LOGIC8),
	OperandBase(CP_A,1,4,0,0xBF,"CP_A",LOGIC8),
	OperandBase(RET_NZ,1,8,20,0xC0,"RET_NZ",JMP),
	OperandBase(POP_BC,1,12,0,0xC1,"POP_BC",DATA16),
	OperandBase(JP_NZ_A16,3,12,16,0xC2,"JP_NZ_A16",JMP),
	OperandBase(JP_A16,3,16,0,0xC3,"JP_A16",JMP),
	OperandBase(CALL_NZ_A16,3,12,24,0xC4,"CALL_NZ_A16",JMP),
	OperandBase(PUSH_BC,1,16,0,0xC5,"PUSH_BC",DATA16),
	OperandBase(ADD_A_D8,2,8,0,0xC6,"ADD_A_D8",LOGIC8),
	OperandBase(RST_00H,1,16,0,0xC7,"RST_00H",JMP),
	OperandBase(RET_Z,1,8,20,0xC8,"RET_Z",JMP),
	OperandBase(RET,1,16,0,0xC9,"RET",JMP),
	OperandBase(JP_Z_A16,3,12,16,0xCA,"JP_Z_A16",JMP),
	OperandBase(PREFIX_CB,1,4,0,0xCB,"PREFIX_CB",ETC),
	OperandBase(CALL_Z_A16,3,12,24,0xCC,"CALL_Z_A16",JMP),
	OperandBase(CALL_A16,3,24,0,0xCD,"CALL_A16",JMP),
	OperandBase(ADC_A_D8,2,8,0,0xCE,"ADC_A_D8",LOGIC8),
	OperandBase(RST_08H,1,16,0,0xCF,"RST_08H",JMP),
	OperandBase(RET_NC,1,8,20,0xD0,"RET_NC",JMP),
	OperandBase(POP_DE,1,12,0,0xD1,"POP_DE",DATA16),
	OperandBase(JP_NC_A16,3,12,16,0xD2,"JP_NC_A16",JMP),
	OperandBase(BADOP_1,0,0,0,0xD3,"BADOP_1",BADOP),
	OperandBase(CALL_NC_A16,3,12,24,0xD4,"CALL_NC_A16",JMP),
	OperandBase(PUSH_DE,1,16,0,0xD5,"PUSH_DE",DATA16),
	OperandBase(SUB_D8,2,8,0,0xD6,"SUB_D8",LOGIC8),
	OperandBase(RST_10H,1,16,0,0xD7,"RST_10H",JMP),
	OperandBase(RET_C,1,8,20,0xD8,"RET_C",JMP),
	OperandBase(RETI,1,16,0,0xD9,"RETI",JMP),
	OperandBase(JP_C_A16,3,12,16,0xDA,"JP_C_A16",JMP),
	OperandBase(BADOP_5,0,0,0,0xDB,"BADOP_5",BADOP),
	OperandBase(CALL_C_A16,3,12,24,0xDC,"CALL_C_A16",JMP),
	OperandBase(BADOP_9,0,0,0,0xDD,"BADOP_9",BADOP),
	OperandBase(SBC_A_D8,2,8,0,0xDE,"SBC_A_D8",LOGIC8),
	OperandBase(RST_18H,1,16,0,0xDF,"RST_18H",JMP),
	OperandBase(LDH_A8ADR_A,2,12,0,0xE0,"LDH_A8ADR_A",DATA8),
	OperandBase(POP_HL,1,12,0,0xE1,"POP_HL",DATA16),
	OperandBase(LD_CADR_A,2,8,0,0xE2,"LD_CADR_A",DATA8),
	OperandBase(BADOP_2,0,0,0,0xE3,"BADOP_2",BADOP),
	OperandBase(BADOP_10,0,0,0,0xE4,"BADOP_10",BADOP),
	OperandBase(PUSH_HL,1,16,0,0xE5,"PUSH_HL",DATA16),
	OperandBase(AND_D8,2,8,0,0xE6,"AND_D8",LOGIC8),
	OperandBase(RST_20H,1,16,0,0xE7,"RST_20H",JMP),
	OperandBase(ADD_SP_E8,2,16,0,0xE8,"ADD_SP_R8",LOGIC16),
	OperandBase(JP_HLA,1,4,0,0xE9,"JP_HLA",JMP),
	OperandBase(LD_A16ADR_A,3,16,0,0xEA,"LD_A16ADR_A",DATA8),
	OperandBase(BADOP_8,0,0,0,0xEB,"BADOP_8",BADOP),
	OperandBase(BADOP_6,0,0,0,0xEC,"BADOP_6",BADOP),
	OperandBase(BADOP_7,0,0,0,0xED,"BADOP_7",BADOP),
	OperandBase(XOR_D8,2,8,0,0xEE,"XOR_D8",LOGIC8),
	OperandBase(RST_28H,1,16,0,0xEF,"RST_28H",JMP),
	OperandBase(LDH_A_A8ADR,2,12,0,0xF0,"LDH_A_A8ADR",DATA8),
	OperandBase(POP_AF,1,12,0,0xF1,"POP_AF",DATA16),
	OperandBase(LD_A_CADR,2,8,0,0xF2,"LD_A_CADR",DATA8),
	OperandBase(DI,1,4,0,0xF3,"DI",ETC),
	OperandBase(BADOP_11,0,0,0,0xF4,"BADOP_11",BADOP),
	OperandBase(PUSH_AF,1,16,0,0xF5,"PUSH_AF",DATA16),
	OperandBase(OR_D8,2,8,0,0xF6,"OR_D8",LOGIC8),
	OperandBase(RST_30H,1,16,0,0xF7,"RST_30H",JMP),
	OperandBase(LD_HL_SPP_R8,2,12,0,0xF8,"LD_HL_SPP_R8",DATA16),
	OperandBase(LD_SP_HL,1,8,0,0xF9,"LD_SP_HL",DATA16),
	OperandBase(LD_A_A16ADR,3,16,0,0xFA,"LD_A_A16ADR",DATA8),
	OperandBase(EI,1,4,0,0xFB,"EI",ETC),
	OperandBase(BADOP_3,0,0,0,0xFC,"BADOP_3",BADOP),
	OperandBase(BADOP_4,0,0,0,0xFD,"BADOP_4",BADOP),
	OperandBase(CP_D8,2,8,0,0xFE,"CP_D8",LOGIC8),
	OperandBase(RST_38H,1,16,0,0xFF,"RST_38H",JMP),


	// CB OPERATIONS

	OperandBase(RLC_B,2,8,0,0x00,"RLC_B",CB),
	OperandBase(RLC_C,2,8,0,0x01,"RLC_C",CB),
	OperandBase(RLC_D,2,8,0,0x02,"RLC_D",CB),
	OperandBase(RLC_E,2,8,0,0x03,"RLC_E",CB),
	OperandBase(RLC_H,2,8,0,0x04,"RLC_H",CB),
	OperandBase(RLC_L,2,8,0,0x05,"RLC_L",CB),
	OperandBase(RLC_HLA,2,16,0,0x06,"RLC_HLA",CB),
	OperandBase(RLC_A,2,8,0,0x07,"RLC_A",CB),
	OperandBase(RRC_B,2,8,0,0x08,"RRC_B",CB),
	OperandBase(RRC_C,2,8,0,0x09,"RRC_C",CB),
	OperandBase(RRC_D,2,8,0,0x0A,"RRC_D",CB),
	OperandBase(RRC_E,2,8,0,0x0B,"RRC_E",CB),
	OperandBase(RRC_H,2,8,0,0x0C,"RRC_H",CB),
	OperandBase(RRC_L,2,8,0,0x0D,"RRC_L",CB),
	OperandBase(RRC_HLA,2,16,0,0x0E,"RRC_HLA",CB),
	OperandBase(RRC_A,2,8,0,0x0F,"RRC_A",CB),
	OperandBase(RL_B,2,8,0,0x10,"RL_B",CB),
	OperandBase(RL_C,2,8,0,0x11,"RL_C",CB),
	OperandBase(RL_D,2,8,0,0x12,"RL_D",CB),
	OperandBase(RL_E,2,8,0,0x13,"RL_E",CB),
	OperandBase(RL_H,2,8,0,0x14,"RL_H",CB),
	OperandBase(RL_L,2,8,0,0x15,"RL_L",CB),
	OperandBase(RL_HLA,2,16,0,0x16,"RL_HLA",CB),
	OperandBase(RL_A,2,8,0,0x17,"RL_A",CB),
	OperandBase(RR_B,2,8,0,0x18,"RR_B",CB),
	OperandBase(RR_C,2,8,0,0x19,"RR_C",CB),
	OperandBase(RR_D,2,8,0,0x1A,"RR_D",CB),
	OperandBase(RR_E,2,8,0,0x1B,"RR_E",CB),
	OperandBase(RR_H,2,8,0,0x1C,"RR_H",CB),
	OperandBase(RR_L,2,8,0,0x1D,"RR_L",CB),
	OperandBase(RR_HLA,2,16,0,0x1E,"RR_HLA",CB),
	OperandBase(RR_A,2,8,0,0x1F,"RR_A",CB),
	OperandBase(SLA_B,2,8,0,0x20,"SLA_B",CB),
	OperandBase(SLA_C,2,8,0,0x21,"SLA_C",CB),
	OperandBase(SLA_D,2,8,0,0x22,"SLA_D",CB),
	OperandBase(SLA_E,2,8,0,0x23,"SLA_E",CB),
	OperandBase(SLA_H,2,8,0,0x24,"SLA_H",CB),
	OperandBase(SLA_L,2,8,0,0x25,"SLA_L",CB),
	OperandBase(SLA_HLA,2,16,0,0x26,"SLA_HLA",CB),
	OperandBase(SLA_A,2,8,0,0x27,"SLA_A",CB),
	OperandBase(SRA_B,2,8,0,0x28,"SRA_B",CB),
	OperandBase(SRA_C,2,8,0,0x29,"SRA_C",CB),
	OperandBase(SRA_D,2,8,0,0x2A,"SRA_D",CB),
	OperandBase(SRA_E,2,8,0,0x2B,"SRA_E",CB),
	OperandBase(SRA_H,2,8,0,0x2C,"SRA_H",CB),
	OperandBase(SRA_L,2,8,0,0x2D,"SRA_L",CB),
	OperandBase(SRA_HLA,2,16,0,0x2E,"SRA_HLA",CB),
	OperandBase(SRA_A,2,8,0,0x2F,"SRA_A",CB),
	OperandBase(SWAP_B,2,8,0,0x30,"SWAP_B",CB),
	OperandBase(SWAP_C,2,8,0,0x31,"SWAP_C",CB),
	OperandBase(SWAP_D,2,8,0,0x32,"SWAP_D",CB),
	OperandBase(SWAP_E,2,8,0,0x33,"SWAP_E",CB),
	OperandBase(SWAP_H,2,8,0,0x34,"SWAP_H",CB),
	OperandBase(SWAP_L,2,8,0,0x35,"SWAP_L",CB),
	OperandBase(SWAP_HLA,2,16,0,0x36,"SWAP_HLA",CB),
	OperandBase(SWAP_A,2,8,0,0x37,"SWAP_A",CB),
	OperandBase(SRL_B,2,8,0,0x38,"SRL_B",CB),
	OperandBase(SRL_C,2,8,0,0x39,"SRL_C",CB),
	OperandBase(SRL_D,2,8,0,0x3A,"SRL_D",CB),
	OperandBase(SRL_E,2,8,0,0x3B,"SRL_E",CB),
	OperandBase(SRL_H,2,8,0,0x3C,"SRL_H",CB),
	OperandBase(SRL_L,2,8,0,0x3D,"SRL_L",CB),
	OperandBase(SRL_HLA,2,16,0,0x3E,"SRL_HLA",CB),
	OperandBase(SRL_A,2,8,0,0x3F,"SRL_A",CB),
	OperandBase(BIT_0_B,2,8,0,0x40,"BIT_0_B",CB),
	OperandBase(BIT_0_C,2,8,0,0x41,"BIT_0_C",CB),
	OperandBase(BIT_0_D,2,8,0,0x42,"BIT_0_D",CB),
	OperandBase(BIT_0_E,2,8,0,0x43,"BIT_0_E",CB),
	OperandBase(BIT_0_H,2,8,0,0x44,"BIT_0_H",CB),
	OperandBase(BIT_0_L,2,8,0,0x45,"BIT_0_L",CB),
	OperandBase(BIT_0_HLA,2,16,0,0x46,"BIT_0_HLA",CB),
	OperandBase(BIT_0_A,2,8,0,0x47,"BIT_0_A",CB),
	OperandBase(BIT_1_B,2,8,0,0x48,"BIT_1_B",CB),
	OperandBase(BIT_1_C,2,8,0,0x49,"BIT_1_C",CB),
	OperandBase(BIT_1_D,2,8,0,0x4A,"BIT_1_D",CB),
	OperandBase(BIT_1_E,2,8,0,0x4B,"BIT_1_E",CB),
	OperandBase(BIT_1_H,2,8,0,0x4C,"BIT_1_H",CB),
	OperandBase(BIT_1_L,2,8,0,0x4D,"BIT_1_L",CB),
	OperandBase(BIT_1_HLA,2,16,0,0x4E,"BIT_1_HLA",CB),
	OperandBase(BIT_1_A,2,8,0,0x4F,"BIT_1_A",CB),
	OperandBase(BIT_2_B,2,8,0,0x50,"BIT_2_B",CB),
	OperandBase(BIT_2_C,2,8,0,0x51,"BIT_2_C",CB),
	OperandBase(BIT_2_D,2,8,0,0x52,"BIT_2_D",CB),
	OperandBase(BIT_2_E,2,8,0,0x53,"BIT_2_E",CB),
	OperandBase(BIT_2_H,2,8,0,0x54,"BIT_2_H",CB),
	OperandBase(BIT_2_L,2,8,0,0x55,"BIT_2_L",CB),
	OperandBase(BIT_2_HLA,2,16,0,0x56,"BIT_2_HLA",CB),
	OperandBase(BIT_2_A,2,8,0,0x57,"BIT_2_A",CB),
	OperandBase(BIT_3_B,2,8,0,0x58,"BIT_3_B",CB),
	OperandBase(BIT_3_C,2,8,0,0x59,"BIT_3_C",CB),
	OperandBase(BIT_3_D,2,8,0,0x5A,"BIT_3_D",CB),
	OperandBase(BIT_3_E,2,8,0,0x5B,"BIT_3_E",CB),
	OperandBase(BIT_3_H,2,8,0,0x5C,"BIT_3_H",CB),
	OperandBase(BIT_3_L,2,8,0,0x5D,"BIT_3_L",CB),
	OperandBase(BIT_3_HLA,2,16,0,0x5E,"BIT_3_HLA",CB),
	OperandBase(BIT_3_A,2,8,0,0x5F,"BIT_3_A",CB),
	OperandBase(BIT_4_B,2,8,0,0x60,"BIT_4_B",CB),
	OperandBase(BIT_4_C,2,8,0,0x61,"BIT_4_C",CB),
	OperandBase(BIT_4_D,2,8,0,0x62,"BIT_4_D",CB),
	OperandBase(BIT_4_E,2,8,0,0x63,"BIT_4_E",CB),
	OperandBase(BIT_4_H,2,8,0,0x64,"BIT_4_H",CB),
	OperandBase(BIT_4_L,2,8,0,0x65,"BIT_4_L",CB),
	OperandBase(BIT_4_HLA,2,16,0,0x66,"BIT_4_HLA",CB),
	OperandBase(BIT_4_A,2,8,0,0x67,"BIT_4_A",CB),
	OperandBase(BIT_5_B,2,8,0,0x68,"BIT_5_B",CB),
	OperandBase(BIT_5_C,2,8,0,0x69,"BIT_5_C",CB),
	OperandBase(BIT_5_D,2,8,0,0x6A,"BIT_5_D",CB),
	OperandBase(BIT_5_E,2,8,0,0x6B,"BIT_5_E",CB),
	OperandBase(BIT_5_H,2,8,0,0x6C,"BIT_5_H",CB),
	OperandBase(BIT_5_L,2,8,0,0x6D,"BIT_5_L",CB),
	OperandBase(BIT_5_HLA,2,16,0,0x6E,"BIT_5_HLA",CB),
	OperandBase(BIT_5_A,2,8,0,0x6F,"BIT_5_A",CB),
	OperandBase(BIT_6_B,2,8,0,0x70,"BIT_6_B",CB),
	OperandBase(BIT_6_C,2,8,0,0x71,"BIT_6_C",CB),
	OperandBase(BIT_6_D,2,8,0,0x72,"BIT_6_D",CB),
	OperandBase(BIT_6_E,2,8,0,0x73,"BIT_6_E",CB),
	OperandBase(BIT_6_H,2,8,0,0x74,"BIT_6_H",CB),
	OperandBase(BIT_6_L,2,8,0,0x75,"BIT_6_L",CB),
	OperandBase(BIT_6_HLA,2,16,0,0x76,"BIT_6_HLA",CB),
	OperandBase(BIT_6_A,2,8,0,0x77,"BIT_6_A",CB),
	OperandBase(BIT_7_B,2,8,0,0x78,"BIT_7_B",CB),
	OperandBase(BIT_7_C,2,8,0,0x79,"BIT_7_C",CB),
	OperandBase(BIT_7_D,2,8,0,0x7A,"BIT_7_D",CB),
	OperandBase(BIT_7_E,2,8,0,0x7B,"BIT_7_E",CB),
	OperandBase(BIT_7_H,2,8,0,0x7C,"BIT_7_H",CB),
	OperandBase(BIT_7_L,2,8,0,0x7D,"BIT_7_L",CB),
	OperandBase(BIT_7_HLA,2,16,0,0x7E,"BIT_7_HLA",CB),
	OperandBase(BIT_7_A,2,8,0,0x7F,"BIT_7_A",CB),
	OperandBase(RES_0_B,2,8,0,0x80,"RES_0_B",CB),
	OperandBase(RES_0_C,2,8,0,0x81,"RES_0_C",CB),
	OperandBase(RES_0_D,2,8,0,0x82,"RES_0_D",CB),
	OperandBase(RES_0_E,2,8,0,0x83,"RES_0_E",CB),
	OperandBase(RES_0_H,2,8,0,0x84,"RES_0_H",CB),
	OperandBase(RES_0_L,2,8,0,0x85,"RES_0_L",CB),
	OperandBase(RES_0_HLA,2,16,0,0x86,"RES_0_HLA",CB),
	OperandBase(RES_0_A,2,8,0,0x87,"RES_0_A",CB),
	OperandBase(RES_1_B,2,8,0,0x88,"RES_1_B",CB),
	OperandBase(RES_1_C,2,8,0,0x89,"RES_1_C",CB),
	OperandBase(RES_1_D,2,8,0,0x8A,"RES_1_D",CB),
	OperandBase(RES_1_E,2,8,0,0x8B,"RES_1_E",CB),
	OperandBase(RES_1_H,2,8,0,0x8C,"RES_1_H",CB),
	OperandBase(RES_1_L,2,8,0,0x8D,"RES_1_L",CB),
	OperandBase(RES_1_HLA,2,16,0,0x8E,"RES_1_HLA",CB),
	OperandBase(RES_1_A,2,8,0,0x8F,"RES_1_A",CB),
	OperandBase(RES_2_B,2,8,0,0x90,"RES_2_B",CB),
	OperandBase(RES_2_C,2,8,0,0x91,"RES_2_C",CB),
	OperandBase(RES_2_D,2,8,0,0x92,"RES_2_D",CB),
	OperandBase(RES_2_E,2,8,0,0x93,"RES_2_E",CB),
	OperandBase(RES_2_H,2,8,0,0x94,"RES_2_H",CB),
	OperandBase(RES_2_L,2,8,0,0x95,"RES_2_L",CB),
	OperandBase(RES_2_HLA,2,16,0,0x96,"RES_2_HLA",CB),
	OperandBase(RES_2_A,2,8,0,0x97,"RES_2_A",CB),
	OperandBase(RES_3_B,2,8,0,0x98,"RES_3_B",CB),
	OperandBase(RES_3_C,2,8,0,0x99,"RES_3_C",CB),
	OperandBase(RES_3_D,2,8,0,0x9A,"RES_3_D",CB),
	OperandBase(RES_3_E,2,8,0,0x9B,"RES_3_E",CB),
	OperandBase(RES_3_H,2,8,0,0x9C,"RES_3_H",CB),
	OperandBase(RES_3_L,2,8,0,0x9D,"RES_3_L",CB),
	OperandBase(RES_3_HLA,2,16,0,0x9E,"RES_3_HLA",CB),
	OperandBase(RES_3_A,2,8,0,0x9F,"RES_3_A",CB),
	OperandBase(RES_4_B,2,8,0,0xA0,"RES_4_B",CB),
	OperandBase(RES_4_C,2,8,0,0xA1,"RES_4_C",CB),
	OperandBase(RES_4_D,2,8,0,0xA2,"RES_4_D",CB),
	OperandBase(RES_4_E,2,8,0,0xA3,"RES_4_E",CB),
	OperandBase(RES_4_H,2,8,0,0xA4,"RES_4_H",CB),
	OperandBase(RES_4_L,2,8,0,0xA5,"RES_4_L",CB),
	OperandBase(RES_4_HLA,2,16,0,0xA6,"RES_4_HLA",CB),
	OperandBase(RES_4_A,2,8,0,0xA7,"RES_4_A",CB),
	OperandBase(RES_5_B,2,8,0,0xA8,"RES_5_B",CB),
	OperandBase(RES_5_C,2,8,0,0xA9,"RES_5_C",CB),
	OperandBase(RES_5_D,2,8,0,0xAA,"RES_5_D",CB),
	OperandBase(RES_5_E,2,8,0,0xAB,"RES_5_E",CB),
	OperandBase(RES_5_H,2,8,0,0xAC,"RES_5_H",CB),
	OperandBase(RES_5_L,2,8,0,0xAD,"RES_5_L",CB),
	OperandBase(RES_5_HLA,2,16,0,0xAE,"RES_5_HLA",CB),
	OperandBase(RES_5_A,2,8,0,0xAF,"RES_5_A",CB),
	OperandBase(RES_6_B,2,8,0,0xB0,"RES_6_B",CB),
	OperandBase(RES_6_C,2,8,0,0xB1,"RES_6_C",CB),
	OperandBase(RES_6_D,2,8,0,0xB2,"RES_6_D",CB),
	OperandBase(RES_6_E,2,8,0,0xB3,"RES_6_E",CB),
	OperandBase(RES_6_H,2,8,0,0xB4,"RES_6_H",CB),
	OperandBase(RES_6_L,2,8,0,0xB5,"RES_6_L",CB),
	OperandBase(RES_6_HLA,2,16,0,0xB6,"RES_6_HLA",CB),
	OperandBase(RES_6_A,2,8,0,0xB7,"RES_6_A",CB),
	OperandBase(RES_7_B,2,8,0,0xB8,"RES_7_B",CB),
	OperandBase(RES_7_C,2,8,0,0xB9,"RES_7_C",CB),
	OperandBase(RES_7_D,2,8,0,0xBA,"RES_7_D",CB),
	OperandBase(RES_7_E,2,8,0,0xBB,"RES_7_E",CB),
	OperandBase(RES_7_H,2,8,0,0xBC,"RES_7_H",CB),
	OperandBase(RES_7_L,2,8,0,0xBD,"RES_7_L",CB),
	OperandBase(RES_7_HLA,2,16,0,0xBE,"RES_7_HLA",CB),
	OperandBase(RES_7_A,2,8,0,0xBF,"RES_7_A",CB),
	OperandBase(SET_0_B,2,8,0,0xC0,"SET_0_B",CB),
	OperandBase(SET_0_C,2,8,0,0xC1,"SET_0_C",CB),
	OperandBase(SET_0_D,2,8,0,0xC2,"SET_0_D",CB),
	OperandBase(SET_0_E,2,8,0,0xC3,"SET_0_E",CB),
	OperandBase(SET_0_H,2,8,0,0xC4,"SET_0_H",CB),
	OperandBase(SET_0_L,2,8,0,0xC5,"SET_0_L",CB),
	OperandBase(SET_0_HLA,2,16,0,0xC6,"SET_0_HLA",CB),
	OperandBase(SET_0_A,2,8,0,0xC7,"SET_0_A",CB),
	OperandBase(SET_1_B,2,8,0,0xC8,"SET_1_B",CB),
	OperandBase(SET_1_C,2,8,0,0xC9,"SET_1_C",CB),
	OperandBase(SET_1_D,2,8,0,0xCA,"SET_1_D",CB),
	OperandBase(SET_1_E,2,8,0,0xCB,"SET_1_E",CB),
	OperandBase(SET_1_H,2,8,0,0xCC,"SET_1_H",CB),
	OperandBase(SET_1_L,2,8,0,0xCD,"SET_1_L",CB),
	OperandBase(SET_1_HLA,2,16,0,0xCE,"SET_1_HLA",CB),
	OperandBase(SET_1_A,2,8,0,0xCF,"SET_1_A",CB),
	OperandBase(SET_2_B,2,8,0,0xD0,"SET_2_B",CB),
	OperandBase(SET_2_C,2,8,0,0xD1,"SET_2_C",CB),
	OperandBase(SET_2_D,2,8,0,0xD2,"SET_2_D",CB),
	OperandBase(SET_2_E,2,8,0,0xD3,"SET_2_E",CB),
	OperandBase(SET_2_H,2,8,0,0xD4,"SET_2_H",CB),
	OperandBase(SET_2_L,2,8,0,0xD5,"SET_2_L",CB),
	OperandBase(SET_2_HLA,2,16,0,0xD6,"SET_2_HLA",CB),
	OperandBase(SET_2_A,2,8,0,0xD7,"SET_2_A",CB),
	OperandBase(SET_3_B,2,8,0,0xD8,"SET_3_B",CB),
	OperandBase(SET_3_C,2,8,0,0xD9,"SET_3_C",CB),
	OperandBase(SET_3_D,2,8,0,0xDA,"SET_3_D",CB),
	OperandBase(SET_3_E,2,8,0,0xDB,"SET_3_E",CB),
	OperandBase(SET_3_H,2,8,0,0xDC,"SET_3_H",CB),
	OperandBase(SET_3_L,2,8,0,0xDD,"SET_3_L",CB),
	OperandBase(SET_3_HLA,2,16,0,0xDE,"SET_3_HLA",CB),
	OperandBase(SET_3_A,2,8,0,0xDF,"SET_3_A",CB),
	OperandBase(SET_4_B,2,8,0,0xE0,"SET_4_B",CB),
	OperandBase(SET_4_C,2,8,0,0xE1,"SET_4_C",CB),
	OperandBase(SET_4_D,2,8,0,0xE2,"SET_4_D",CB),
	OperandBase(SET_4_E,2,8,0,0xE3,"SET_4_E",CB),
	OperandBase(SET_4_H,2,8,0,0xE4,"SET_4_H",CB),
	OperandBase(SET_4_L,2,8,0,0xE5,"SET_4_L",CB),
	OperandBase(SET_4_HLA,2,16,0,0xE6,"SET_4_HLA",CB),
	OperandBase(SET_4_A,2,8,0,0xE7,"SET_4_A",CB),
	OperandBase(SET_5_B,2,8,0,0xE8,"SET_5_B",CB),
	OperandBase(SET_5_C,2,8,0,0xE9,"SET_5_C",CB),
	OperandBase(SET_5_D,2,8,0,0xEA,"SET_5_D",CB),
	OperandBase(SET_5_E,2,8,0,0xEB,"SET_5_E",CB),
	OperandBase(SET_5_H,2,8,0,0xEC,"SET_5_H",CB),
	OperandBase(SET_5_L,2,8,0,0xED,"SET_5_L",CB),
	OperandBase(SET_5_HLA,2,16,0,0xEE,"SET_5_HLA",CB),
	OperandBase(SET_5_A,2,8,0,0xEF,"SET_5_A",CB),
	OperandBase(SET_6_B,2,8,0,0xF0,"SET_6_B",CB),
	OperandBase(SET_6_C,2,8,0,0xF1,"SET_6_C",CB),
	OperandBase(SET_6_D,2,8,0,0xF2,"SET_6_D",CB),
	OperandBase(SET_6_E,2,8,0,0xF3,"SET_6_E",CB),
	OperandBase(SET_6_H,2,8,0,0xF4,"SET_6_H",CB),
	OperandBase(SET_6_L,2,8,0,0xF5,"SET_6_L",CB),
	OperandBase(SET_6_HLA,2,16,0,0xF6,"SET_6_HLA",CB),
	OperandBase(SET_6_A,2,8,0,0xF7,"SET_6_A",CB),
	OperandBase(SET_7_B,2,8,0,0xF8,"SET_7_B",CB),
	OperandBase(SET_7_C,2,8,0,0xF9,"SET_7_C",CB),
	OperandBase(SET_7_D,2,8,0,0xFA,"SET_7_D",CB),
	OperandBase(SET_7_E,2,8,0,0xFB,"SET_7_E",CB),
	OperandBase(SET_7_H,2,8,0,0xFC,"SET_7_H",CB),
	OperandBase(SET_7_L,2,8,0,0xFD,"SET_7_L",CB),
	OperandBase(SET_7_HLA,2,16,0,0xFE,"SET_7_HLA",CB),
	OperandBase(SET_7_A,2,8,0,0xFF,"SET_7_A",CB),
};
#endif