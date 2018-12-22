#ifndef INST_H_
#define  INST_H_
#include "DataTypes.h" 


enum EOperandType : u8
{
	ETC,				//Misc/control instructions
	JMP,				//Jumps/calls
	DATA8,				//8bit load/store/move instructions
	DATA16,				//16bit load/store/move instructions
	LOGIC8,				//8bit arithmetic/logical instructions
	LOGIC16,			//16bit arithmetic/logical instructions
	CB,					//8bit rotations/shifts and bit instructions(Z80 CB OPERANDS)
	BADOP,				//illegal operands
	EOperandType_MAX

};

 
enum Instruction:u16
{
			//x0		x1			x2				x3				x4				x5			x6				x7			x8				x9				xA				xB			xC			xD			xE				xF
	/*0x*/	NOP,		LD_BC,		LD_BC_A,		INC_BC,			INC_B,			DEC_B,		LD_B_D8,		RLCA,		LD_A16_SP,		ADD_HL_BC,		LD_A_BC,		DEC_BC,		INC_C,		DEC_C,		LD_C_D8,		RRCA,
	/*1x*/	STOP,		LD_DE_D16,	LD_DE_A,		INC_DE,			INC_D,			DEC_D,		LD_D_D8,		RLA,		JR_R8,			ADD_HL_DE,		LD_A_DE,		DEC_DE,		INC_E,		DEC_E,		LD_E_D8,		RRA,
	/*2x*/	JR_NZ_R8,	LD_HL_D16,	LD_HL_PLUS_A,	INC_HL,			INC_H,			DEC_H,		LD_H_D8,		DAA,		JR_Z_R8,		ADD_HL_HL,		LD_A_HLA_PLUS,	DEC_HL,		INC_L,		DEC_L,		LD_L_D8,		CPL,
	/*3x*/	JR_NC_R8,	LD_SP_D16,	LD_HL_MNUS_A,	INC_SP,			INC_HLA,		DEC_HLA,	LD_HLA_D8,		SCF,		JR_C_R8,		ADD_HL_SP,		LD_A_HLA_MNUS,	DEC_SP,		INC_A,		DEC_A,		LD_A_D8,		CCF,
	/*4x*/	LD_B_B,		LD_B_C,		LD_B_D,			LD_B_E,			LD_B_H,			LD_B_L,		LD_B_HLA,		LD_B_A,		LD_C_B,			LD_C_C,			LD_C_D,			LD_C_E,		LD_C_H,		LD_C_L,		LD_C_HLA,		LD_C_A,
	/*5x*/	LD_D_B,		LD_D_C,		LD_D_D,			LD_D_E,			LD_D_H,			LD_D_L,		LD_D_HLA,		LD_D_A,		LD_E_B,			LD_E_C,			LD_E_D,			LD_E_E,		LD_E_H,		LD_E_L,		LD_E_HLA,		LD_E_A,
	/*6x*/	LD_H_B,		LD_H_C,		LD_H_D,			LD_H_E,			LD_H_H,			LD_H_L,		LD_H_HLA,		LD_H_A,		LD_L_B,			LD_L_C,			LD_L_D,			LD_L_E,		LD_L_H,		LD_L_L,		LD_L_HLA,		LD_L_A,
	/*7x*/	LD_HLA_B,	LD_HLA_C,	LD_HLA_D,		LD_HLA_E,		LD_HLA_H,		LD_HLA_L,	HALT,			LD_HLA_A,	LD_A_B,			LD_A_C,			LD_A_D,			LD_A_E,		LD_A_H,		LD_A_L,		LD_A_HLA,		LD_A_A,
	/*8x*/	ADD_A_B,	ADD_A_C,	ADD_A_D,		ADD_A_E,		ADD_A_H,		ADD_A_L,	ADD_A_HLA,		ADD_A_A,	ADC_A_B,		ADC_A_C,		ADC_A_D,		ADC_A_E,	ADC_A_H,	ADC_A_L,	ADC_A_HLA,		ADC_A_A,
	/*9x*/	SUB_B,		SUB_C,		SUB_D,			SUB_E,			SUB_H,			SUB_L,		SUB_HLA,		SUB_A,		SBC_A_B,		SBC_A_C,		SBC_A_D,		SBC_A_E,	SBC_A_H,	SBC_A_L,	SBC_A_HLA,		SBC_A_A,
	/*Ax*/	AND_B,		AND_C,		AND_D,			AND_E,			AND_H,			AND_L,		AND_HLA,		AND_A,		XOR_B,			XOR_C,			XOR_D,			XOR_E,		XOR_H,		XOR_L,		XOR_HLA,		XOR_A,
	/*Bx*/	OR_B,		OR_C,		OR_D,			OR_E,			OR_H,			OR_L,		OR_HLA,			OR_A,		CP_B,			CP_C,			CP_D,			CP_E,		CP_H,		CP_L,		CP_HLA,			CP_A,
	/*Cx*/	RET_NZ,		POP_BC,		JP_NZ_A16,		JP_A16,			CALL_NZ_A16,	PUSH_BC,	ADD_A_D8,		RST_00H,	RET_Z,			RET,			JP_Z_A16,		PREFIX_CB,	CALL_Z_A16,	CALL_A16,	ADC_A_D8,		RST_08H,
	/*Dx*/	RET_NC,		POP_DE,		JP_NC_A16,		BADOP_1,		CALL_NC_A16,	PUSH_DE,	SUB_D8,			RST_10H,	RET_C,			RETI,			JP_C_A16,		BADOP_5,	CALL_C_A16,	BADOP_9,	SBC_A_D8,		RST_18H,
	/*Ex*/	LDH_A8ADR_A,POP_HL,		LD_CADR_A,		BADOP_2,		BADOP_10,		PUSH_HL,	AND_D8,			RST_20H,	ADD_SP_E8,		JP_HLA,			LD_A16ADR_A,	BADOP_8,	BADOP_6,	BADOP_7,	XOR_D8,			RST_28H,
	/*Fx*/	LDH_A_A8ADR,POP_AF,		LD_A_CADR,		DI,				BADOP_11,		PUSH_AF,	OR_D8,			RST_30H,	LD_HL_SPP_R8,	LD_SP_HL,		LD_A_A16ADR,	EI,			BADOP_3,	BADOP_4,	CP_D8,			RST_38H,

	//CB SECTION
			//x0		x1			x2			x3			x4			x5			x6			x7			x8			x9			xA			xB			xC			xD			xE			xF
	/*0x*/	RLC_B,		RLC_C,		RLC_D,		RLC_E,		RLC_H,		RLC_L,		RLC_HLA,	RLC_A,		RRC_B,		RRC_C,		RRC_D,		RRC_E,		RRC_H,		RRC_L,		RRC_HLA,	RRC_A,
	/*1x*/	RL_B,		RL_C,		RL_D,		RL_E,		RL_H,		RL_L,		RL_HLA,		RL_A,		RR_B,		RR_C,		RR_D,		RR_E,		RR_H,		RR_L,		RR_HLA,		RR_A,
	/*2x*/	SLA_B,		SLA_C,		SLA_D,		SLA_E,		SLA_H,		SLA_L,		SLA_HLA,	SLA_A,		SRA_B,		SRA_C,		SRA_D,		SRA_E,		SRA_H,		SRA_L,		SRA_HLA,	SRA_A,
	/*3x*/	SWAP_B,		SWAP_C,		SWAP_D,		SWAP_E,		SWAP_H,		SWAP_L,		SWAP_HLA,	SWAP_A,		SRL_B,		SRL_C,		SRL_D,		SRL_E,		SRL_H,		SRL_L,		SRL_HLA,	SRL_A,
	/*4x*/	BIT_0_B,	BIT_0_C,	BIT_0_D,	BIT_0_E,	BIT_0_H,	BIT_0_L,	BIT_0_HLA,	BIT_0_A,	BIT_1_B,	BIT_1_C,	BIT_1_D,	BIT_1_E,	BIT_1_H,	BIT_1_L,	BIT_1_HLA,	BIT_1_A,
	/*5x*/	BIT_2_B,	BIT_2_C,	BIT_2_D,	BIT_2_E,	BIT_2_H,	BIT_2_L,	BIT_2_HLA,	BIT_2_A,	BIT_3_B,	BIT_3_C,	BIT_3_D,	BIT_3_E,	BIT_3_H,	BIT_3_L,	BIT_3_HLA,	BIT_3_A,
	/*6x*/	BIT_4_B,	BIT_4_C,	BIT_4_D,	BIT_4_E,	BIT_4_H,	BIT_4_L,	BIT_4_HLA,	BIT_4_A,	BIT_5_B,	BIT_5_C,	BIT_5_D,	BIT_5_E,	BIT_5_H,	BIT_5_L,	BIT_5_HLA,	BIT_5_A,
	/*7x*/	BIT_6_B,	BIT_6_C,	BIT_6_D,	BIT_6_E,	BIT_6_H,	BIT_6_L,	BIT_6_HLA,	BIT_6_A,	BIT_7_B,	BIT_7_C,	BIT_7_D,	BIT_7_E,	BIT_7_H,	BIT_7_L,	BIT_7_HLA,	BIT_7_A,
	/*8x*/	RES_0_B,	RES_0_C,	RES_0_D,	RES_0_E,	RES_0_H,	RES_0_L,	RES_0_HLA,	RES_0_A,	RES_1_B,	RES_1_C,	RES_1_D,	RES_1_E,	RES_1_H,	RES_1_L,	RES_1_HLA,	RES_1_A,
	/*9x*/	RES_2_B,	RES_2_C,	RES_2_D,	RES_2_E,	RES_2_H,	RES_2_L,	RES_2_HLA,	RES_2_A,	RES_3_B,	RES_3_C,	RES_3_D,	RES_3_E,	RES_3_H,	RES_3_L,	RES_3_HLA,	RES_3_A,
	/*Ax*/	RES_4_B,	RES_4_C,	RES_4_D,	RES_4_E,	RES_4_H,	RES_4_L,	RES_4_HLA,	RES_4_A,	RES_5_B,	RES_5_C,	RES_5_D,	RES_5_E,	RES_5_H,	RES_5_L,	RES_5_HLA,	RES_5_A,
	/*Bx*/	RES_6_B,	RES_6_C,	RES_6_D,	RES_6_E,	RES_6_H,	RES_6_L,	RES_6_HLA,	RES_6_A,	RES_7_B,	RES_7_C,	RES_7_D,	RES_7_E,	RES_7_H,	RES_7_L,	RES_7_HLA,	RES_7_A,
	/*Cx*/	SET_0_B,	SET_0_C,	SET_0_D,	SET_0_E,	SET_0_H,	SET_0_L,	SET_0_HLA,	SET_0_A,	SET_1_B,	SET_1_C,	SET_1_D,	SET_1_E,	SET_1_H,	SET_1_L,	SET_1_HLA,	SET_1_A,
	/*Dx*/	SET_2_B,	SET_2_C,	SET_2_D,	SET_2_E,	SET_2_H,	SET_2_L,	SET_2_HLA,	SET_2_A,	SET_3_B,	SET_3_C,	SET_3_D,	SET_3_E,	SET_3_H,	SET_3_L,	SET_3_HLA,	SET_3_A,
	/*Ex*/	SET_4_B,	SET_4_C,	SET_4_D,	SET_4_E,	SET_4_H,	SET_4_L,	SET_4_HLA,	SET_4_A,	SET_5_B,	SET_5_C,	SET_5_D,	SET_5_E,	SET_5_H,	SET_5_L,	SET_5_HLA,	SET_5_A,
	/*Fx*/	SET_6_B,	SET_6_C,	SET_6_D,	SET_6_E,	SET_6_H,	SET_6_L,	SET_6_HLA,	SET_6_A,	SET_7_B,	SET_7_C,	SET_7_D,	SET_7_E,	SET_7_H,	SET_7_L,	SET_7_HLA,	SET_7_A,

};

typedef struct OperandBase
{
	OperandBase() {}

	OperandBase(
		const Instruction  instIn,
		const u8  CycleOpIn,
		const u8  CycleParamIn,
		const u8  cycleSuccIn, 
		const u8   opcodeIn, 
		char*  friendlyName, 
		EOperandType opTypeIn)
		:inst(instIn),
		CycleParam(CycleParamIn),
		CycleOp(CycleOpIn),
		CycleSucc(cycleSuccIn),
		Opcode(opcodeIn),
		FirendlyName(friendlyName),
		opType(opTypeIn) {}

	Instruction inst;
	EOperandType opType;
	u8 Opcode;
	u8 CycleOp;
	u8 CycleParam;
	u8 CycleSucc;
	char* FirendlyName;

	
} OperandBase; 


#include "OpcodeBasePredef.h" 
#endif