#ifndef LR35902_H_
#define  LR35902_H_
#include "DataTypes.h"
#include "MMU.h"
#include "Instruction.h"

#include <iostream>
using namespace std;
 
#define CPUFSET 
 

/*
struct OperandBase
{
	OperandBase() {}
	OperandBase(const EOperandType& typeIn, const u8 &cycleIn,const u8 & opcodeIn,const string& friendlyName)
	{
		Type = typeIn;
		Cycle = cycleIn;
		Opcode = opcodeIn;
		FirendlyName = friendlyName;
	} 
	EOperandType Type;
	u8 Opcode;
	u8 Cycle;
	string FirendlyName;
	void Exec(); 
};

*/

enum ECPUFlag
{
	Z = 0x80,
	N = 0x40,
	H = 0x20,
	C = 0x10
};

enum ECPUGetFlag
{
	GZ = 0x7,
	GN = 0x6,
	GH = 0x5,
	GC = 0x4
};


struct Registers
{
	//A AND FLAG
	MAKEUNION(A, F);

	//REGISTERS
	MAKEUNION(B, C);
	MAKEUNION(D, E);
	MAKEUNION(H, L);

	//PROGRAM COUNTER
	MAKEUNION(P, C);

	//STACK POINTER
	MAKEUNION(S, P);

};

class LR35902
{
public:
	LR35902(IMMU* Memory);
	Registers Reg;
	IMMU* Memory = nullptr;

	void Step();

	//For 8086 opcodes
	void Decode(u8 opcode);

	//For Z80 opcodes
	void Decode_CB(u8 opcode);

	u32 Cycle = 0;
	//https://rednex.github.io/rgbds/gbz80.7.html 
	void CB(u8 opcode);
	void JMP(u8 opcode);
	void ETC(u8 opcode);
	void DATA8(u8 opcode);
	void BADOP(u8 opcode);
	void DATA16(u8 opcode);
	void LOGIC8(u8 opcode);
	void LOGIC16(u8 opcode);
	void BITSHIFT(u8 opcode);
	 

	void CheckCarryFlagPlusFull(u8&reg, u8 amount);
	void CheckCarryFlagPlusHalf(u8&reg, u8 amount);


	void CheckCarryFlagMinusFull(u8&reg, u8 amount);
	void CheckCarryFlagMinusHalf(u8&reg, u8 amount);


	void CheckZeroFlag(u8&reg);
	void CheckZeroFlag(u16&reg);

	void SetFlag(ECPUFlag flag);
	void ResetFlag(ECPUFlag flag);

	u8 GetFlag(ECPUGetFlag flag);
	void ToggleFlag(ECPUGetFlag flag);





	// ALU 8 BIT
	void INCR8(u8&reg); 
	void DECR8(u8&reg); 
	void DECRHL(u16&reg);
	void INCRHL(u16&reg);
/*
		info about DAA instruction:
		https://ehaskins.com/2018-01-30%20Z80%20DAA/
		https://www.reddit.com/r/Gameboy/comments/4m7sm0/technical_how_did_old_gameboy_games_represent/

------------------------------------------------------------------------------------------

		ld A, $42	; A now contains 0100 0010
		daa			; A will still contain 0100 0010, because 42 is valid decimal number
		ld A, $3C	; A now contains 0011 1100
		daa			; DAA will convert 3C into decimal form 42 (add 30 + 12, basically).

					; so for scores
					; need to add 15 and 38 (decimal, not hex)
		ld A, $15	; load 0001 0101 into A
		add A, $38	; add 0011 1000 into A
					; the result is $4D, or 0100 1101, or 77. Obvs not correct.
					; let's do a daa!
		daa			; first, is H flag set or is the LSB > 9 ?
					; it is ? add $06 to A, so output 0101 0011
					; is C flag set or is MSB > 9 ?
					; it's not, but if it were, add $60 to A.
					; end result is $53, or 0101 0011.
					; 15 (decimal)+18 (decimal) = 53 (decimal)
-------------------------------------------------------------
										; have two locations in memory, lower score and higher score
										; format is higher score has thousands and hundreds.
										; lower score has tens and ones.

		ld HL,lowerscore				; load in lowerscore memory point
		ld A,[HL]						; load in our scores. let's say it's 95
		add $20							; add 20 to the score
		daa								; A now has 115. but not really.
										; daa will set the carry flag, because 115 can't be BCD'd correctly. A now has 15.
		ld [HL],A						; save lowerscore.

		jr C,.the_rest_of_our_lives		;if it's not over 100, skip next part.

		ld HL,higherscore				; load in our thousands-hundreds byte
		ld A,[HL]
		add $01							; add one, because we only are adding 100 to the score
		daa
		ld [HL],A						; save our new score into memory

		.the_rest_of_our_lives

										; so register higherscore will have 01
										; and register lowerscore will have 15
										; combine them for 0115.

*/
	void OPDAA(); 
	void ADD8(u8 data); 
	void ADC8(u8 data);
	void ADCHLP();
	void ADDHLP(); 
	void SUB8(u8 data);
	void SUBHLP(); 
	void SBC8(u8 data);
	void SBCHL();
	void AND8(u8 data);
	void ANDHL();
	void XOR8(u8 data);
	void XORHL();
	void OR8(u8 data);
	void ORHL();
	void CP8(u8 data);
	void CPHL(); 

	//ALU 16 BIT

	//+
	void CheckCarryFlagPlusFull_16(u16&reg, u16 amount);
	void CheckCarryFlagPlusHalf_16(u16&reg, u16 amount);

	//-
	void CheckCarryFlagMinusFull_16(u16&reg, u16 amount);
	void CheckCarryFlagMinusHalf_16(u16&reg, u16 amount);



	void INC16(u16&reg);
	void DEC16(u16&reg);
	void ADD16(u16 data);
	void ADDSPE8();

	//void SignedCheckCarry_Full8_Add(u8&reg, s8 amount);
	//void SignedCheckCarry_Half8_Add(u8&reg, s8 amount);

	void SignedCheckCarry8(u8&reg, s8 amount);
	void SignedCheckCarry8_Half(u8&reg, s8 amount);
	//void SignedCheckCarry_Half8_Minus(u8&reg, s8 amount);


	u8 ReadImmvalue8();
};


#endif