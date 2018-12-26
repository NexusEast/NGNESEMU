#include "LR35902.h"

 
LR35902::LR35902(IMMU* Memory)
{
	this->Memory = Memory;
}

void LR35902::Step()
{
	if (!Memory)
	{
		return;
	}
	u8 opcode = Memory->Read(++Reg.PC.val);
	switch (opcode)
	{
	case (0xCB):
	{ 
		Decode_CB(Memory->Read(++Reg.PC.val));
	}
	break;
	default: 
		Decode(opcode);
	break;
	}
}

void LR35902::Decode(u8 opcode)
{
	switch (opcode)
	{
	default:
		break;
	}
}

void LR35902::Decode_CB(u8 opcode)
{

}


void LR35902::BITSHIFT(u8 opcode)
{
	switch (opcode)
	{


		//CB
	case RLCA://0x07
	case RRCA://0x0F
	case RLA://0x17
	case RRA://0x1F



	default:
		break;
	}
}
 
  

void LR35902::CheckCarryFlagPlusFull_16(u16&reg, u16 amount)
{
	if ((0xFFFF - reg  ) < amount)// overflew
	{
		SetFlag(H);
	}
}

void LR35902::CheckCarryFlagPlusHalf_16(u16&reg, u16 amount)
{
	u8 r8 = (reg & 0xFF);
	u8 a8 = (amount & 0xFF);
	CheckCarryFlagPlusFull(r8, a8);
}

void LR35902::CheckCarryFlagMinusFull_16(u16&reg, u16 amount)
{
	if (amount>reg)
	{
		SetFlag(H);
	}
}

void LR35902::CheckCarryFlagMinusHalf_16(u16&reg, u16 amount)
{
	u8 r8 = (reg & 0xFF);
	u8 a8 = (amount & 0xFF);
	CheckCarryFlagMinusFull(r8, a8);
}

void LR35902::CheckCarryFlagPlusFull(u8&reg, u8 amount)
{
	if ((0xFF - reg)<amount)// overflew
	{
		SetFlag(C);
	}
}

void LR35902::CheckCarryFlagPlusHalf(u8&reg, u8 amount)
{
	if ((0xF - (reg & 0x0F)) < (amount & 0x0F))// overflew
	{
		SetFlag(H);
	}
	
}

void LR35902::CheckCarryFlagMinusFull(u8&reg, u8 amount)
{
	if (amount>reg)
	{
		SetFlag(H);
	}
}

void LR35902::CheckCarryFlagMinusHalf(u8&reg, u8 amount)
{
	if ((amount & 0x0F) > (reg & 0x0F)) // overflew
	{
		SetFlag(H);
	}
}

void LR35902::CheckZeroFlag(u8&reg)
{
	if (reg == 0)
	{
		SetFlag(Z);
	}
}

void LR35902::CheckZeroFlag(u16&reg)
{
	if (reg == 0)
	{
		SetFlag(Z);
	}
}

void LR35902::SetFlag(ECPUFlag flag)
{
	Reg.AF.F |= flag;
}

void LR35902::ResetFlag(ECPUFlag flag)
{
	Reg.AF.F &= ~flag;
}
 
 

u8 LR35902::GetFlag(ECPUGetFlag flag)
{
	return  (Reg.AF.F >> flag);
}

void LR35902::ToggleFlag(ECPUGetFlag flag)
{
	Reg.AF.F ^= 1 << flag;
}

void LR35902::INCR8(u8&reg)
{
	CheckCarryFlagPlusHalf(reg, 1);
	reg++;
	CheckZeroFlag(reg);
	ResetFlag(N);
}

 

void LR35902::DECR8(u8&reg)
{
	CheckCarryFlagMinusHalf(reg, 1);
	reg--;
	CheckZeroFlag(reg);
	SetFlag(N);
}

void LR35902::DECRHL(u16&reg)
{
	u8 memval = Memory->Read(reg);
	CheckCarryFlagMinusHalf(memval, 1);
	memval--;
	Memory->Write(reg,memval);
	CheckZeroFlag(memval);
	SetFlag(N);
}

void LR35902::INCRHL(u16&reg)
{
	u8 memval = Memory->Read(reg);
	CheckCarryFlagPlusHalf(memval, 1);
	memval++;
	CheckZeroFlag(memval);
	ResetFlag(N);
}

void LR35902::OPDAA()
{
	int correction = 0;
	bool setFlagC = false;
	u8 h = GetFlag(GH);
	u8 c = GetFlag(GC);
	u8 n = GetFlag(GN);
	u8 z = GetFlag(GZ);

	if (h || (!h && (Reg.AF.A & 0xf) > 9)) {
		correction |= 0x6;
	}
	if (c || (!n && Reg.AF.A > 0x99)) {
		correction |= 0x60;
		setFlagC = c;
	}

	Reg.AF.A += n ? -correction : correction;

	Reg.AF.A &= 0xff;
	if (Reg.AF.A == 0)
	{
		SetFlag(Z);
	}
	if (setFlagC)
	{
		SetFlag(C);
	}
	else
	{
		ResetFlag(C);
	}
	ResetFlag(H);

	//const setFlagZ = Reg.AF.A == = 0 ? z : 0;

	//Reg.AF.F &= ~(FLAG_H | FLAG_Z | FLAG_C);
	//Reg.AF.F |= setFlagC | setFlagZ;

}

void LR35902::ADD8(u8 data)
{
	CheckCarryFlagPlusHalf(Reg.AF.A, data);
	CheckCarryFlagPlusFull(Reg.AF.A, data);
	Reg.AF.A += data;
	CheckZeroFlag(Reg.AF.A);
	ResetFlag(N);
}
 
void LR35902::ADC8(u8 data)
{
	CheckCarryFlagPlusHalf(Reg.AF.A, data);
	CheckCarryFlagPlusFull(Reg.AF.A, data);
	Reg.AF.A += data + GetFlag(GC);
	CheckZeroFlag(Reg.AF.A);
	ResetFlag(N);
}

void LR35902::ADCHLP()
{
	u8 memval = Memory->Read(Reg.HL.val);
	CheckCarryFlagPlusHalf(Reg.AF.A, memval);
	CheckCarryFlagPlusFull(Reg.AF.A, memval);
	Reg.AF.A += memval + GetFlag(GC);
	CheckZeroFlag(Reg.AF.A);
	ResetFlag(N);
}

void LR35902::ADDHLP()
{
	u8 memval = Memory->Read(Reg.HL.val);
	CheckCarryFlagPlusHalf(Reg.AF.A, memval);
	CheckCarryFlagPlusFull(Reg.AF.A, memval);
	Reg.AF.A += memval;
	CheckZeroFlag(Reg.AF.A);
	ResetFlag(N);

}

void LR35902::SUB8(u8 data)
{
	CheckCarryFlagMinusHalf(Reg.AF.A, data);
	CheckCarryFlagMinusFull(Reg.AF.A, data);
	Reg.AF.A -= data;
	CheckZeroFlag(Reg.AF.A);
	SetFlag(N);

}

void LR35902::SUBHLP()
{
	u8 memval = Memory->Read(Reg.HL.val);
	CheckCarryFlagMinusHalf(Reg.AF.A, memval);
	CheckCarryFlagMinusFull(Reg.AF.A, memval);
	Reg.AF.A -= memval;
	CheckZeroFlag(Reg.AF.A);
	SetFlag(N);
}

void LR35902::SBC8(u8 data)
{
	CheckCarryFlagMinusHalf(Reg.AF.A, data);
	CheckCarryFlagMinusFull(Reg.AF.A, data);
	Reg.AF.A -= (data+GetFlag(GC));
	CheckZeroFlag(Reg.AF.A);
	SetFlag(N);
}

void LR35902::SBCHL()
{
	u8 memval = Memory->Read(Reg.HL.val);
	CheckCarryFlagMinusHalf(Reg.AF.A, memval);
	CheckCarryFlagMinusFull(Reg.AF.A, memval);
	Reg.AF.A -= (memval + GetFlag(GC));
	CheckZeroFlag(Reg.AF.A);
	SetFlag(N);
}

void LR35902::AND8(u8 data)
{
	Reg.AF.A &= data; 
	CheckZeroFlag(Reg.AF.A);
	SetFlag(H);
	ResetFlag(N);
	ResetFlag(C);
}

void LR35902::ANDHL()
{
	AND8(Memory->Read(Reg.HL.val));
}

void LR35902::XOR8(u8 data)
{ 
	Reg.AF.A ^= data;
	CheckZeroFlag(Reg.AF.A); 
	ResetFlag(N);
	ResetFlag(H);
	ResetFlag(C);
}

void LR35902::XORHL()
{
	XOR8(Memory->Read(Reg.HL.val));
}

void LR35902::OR8(u8 data)
{
	Reg.AF.A |= data;
	CheckZeroFlag(Reg.AF.A);
	ResetFlag(N);
	ResetFlag(H);
	ResetFlag(C);
}

void LR35902::ORHL()
{
	OR8(Memory->Read(Reg.HL.val));
}

void LR35902::CP8(u8 data)
{ 
	CheckCarryFlagMinusHalf(Reg.AF.A, data);
	CheckCarryFlagMinusFull(Reg.AF.A, data);
	SetFlag(N);
	if (Reg.AF.A == data)
	{
		SetFlag(Z);
	}
}

void LR35902::CPHL()
{
	CP8(Memory->Read(Reg.HL.val));
}


void LR35902::INC16(u16&reg)
{
	reg++;
}

void LR35902::DEC16(u16&reg)
{
	reg--;
}

void LR35902::ADD16(u16 data)
{ 
	CheckCarryFlagPlusFull_16(Reg.HL.val, data);
	CheckCarryFlagPlusHalf_16(Reg.HL.val, data);
	Reg.HL.val += data;
	ResetFlag(N);
}

void LR35902::ADDSPE8()
{
	Reg.PC.val++;
	s8 memval = (s8)Memory->Read(Reg.PC.val);
	u8 reg = (Reg.PC.val & 0xFF);
	SignedCheckCarry8(reg, memval);
	SignedCheckCarry8_Half(reg, memval);
	Reg.SP.val += memval;
	ResetFlag(N);
	ResetFlag(Z);
}

 

void LR35902::SignedCheckCarry8(u8&reg, s8 amount)
{
	// lazy way to handle signed check.
	int res = reg + amount;
	if (((res&0xF00) >> 8) != 0)
	{
		SetFlag(C);
	}
}

void LR35902::SignedCheckCarry8_Half(u8&reg, s8 amount)
{
	// lazy way to handle signed check.
	int res = reg + amount;
	if ((res & 0x10) != (reg & 0x10))
	{
		SetFlag(H);
	}
} 

u8 LR35902::ReadImmvalue8()
{
	return Memory->Read(++Reg.PC.val);
}

/*
LD reg, data	reg<-data
*/
void LR35902::LD_R8_R8(u8 &reg, u8 data)
{
	reg = data;
}

void LR35902::LD_R8_IMM(u8 &reg)
{
	Reg.PC.val++;
	u8 data = Memory->Read(Reg.PC.val);
	LD_R8_R8(data, reg);
}

void LR35902::LD_R16ADDR_A(u16 reg)
{
	Memory->Write(reg, Reg.AF.A); 
}
 
void LR35902::LD_A_R16ADDR(u16 reg)
{
	Reg.AF.A = Memory->Read(reg);
}

/*
LD [HL+],A
Store value in register A into byte pointed by HL and post-increment HL.
Cycles: 2
Bytes: 1
Flags: None affected.
*/
void LR35902::LD_HL_P_A()
{
	LD_R16ADDR_A(Reg.HL.val);
	Reg.HL.val++;
}
/*
LD [HL-],A
Store value in register A into byte pointed by HL and post-decrement HL.
Cycles: 2
Bytes: 1
Flags: None affected.
*/
void LR35902::LD_HL_M_A()
{
	LD_R16ADDR_A(Reg.HL.val);
	Reg.HL.val--;
}
 
void LR35902::LD_A_HLA_P()
{
	Reg.AF.A = Memory->Read(Reg.HL.val);
	Reg.HL.val--;
}

void LR35902::LD_A_HLA_M()
{
	Memory->Write(Reg.HL.val, Reg.AF.A);
}

/*
LD [HL],r8
Store value in register r8 into byte pointed by register HL.
Cycles: 2
Bytes: 1
Flags: None affected.
*/
void LR35902::LD_HLA_R8(u8 reg)
{
	Memory->Write(Reg.HL.val, reg);
}

/*
LD [HL],n8
Store value n8 into byte pointed by register HL.
Cycles: 3
Bytes: 2
Flags: None affected.
*/
void LR35902::LD_HLADDR_N8()
{ 
	LD_HLA_R8(Memory->Read(++Reg.PC.val));
}

/*
LD r8,[HL]
Load value into register r8 from byte pointed by register HL.
Cycles: 2
Bytes: 1
Flags: None affected.
*/
void LR35902::LD_R8_HLA(u8&reg)
{
	reg = Memory->Read(Reg.HL.val);
}

/*
LD [$FF00+n8],A
Store value in register A into high RAM or I/O registers.
The following synonym forces this encoding: LDH [$FF00+n8],A
Cycles: 3
Bytes: 2
Flags: None affected.
*/
void LR35902::LD_FF00_IMM_A()// LD (0xFF00+imm),A
{ 
	Reg.PC.val++;
	u8 imm = Memory->Read(Reg.PC.val);
	Memory->Write(0xFF00 + imm, Reg.AF.A);
}
/*\
LD [$FF00+C],A
Store value in register A into high RAM or I/O registers.
Cycles: 2
Bytes: 1
Flags: None affected.
*/
void LR35902::LD_FF00_C_A()
{
	Memory->Write( Memory->Read(0xFF00 + Reg.BC.C), Reg.AF.A);
}

void LR35902::LD_IMM16_A()
{ 
	u16 imm16 = Memory->Read16(++Reg.PC.val);
	++Reg.PC.val;
	Memory->Write(imm16, Reg.AF.A); 
}


 

void LR35902::LD_A_IMM16()
{
	Reg.AF.A = Memory->Read(Memory->Read16(++Reg.PC.val));
	Reg.PC.val++;
}

void LR35902::LD_A_FF00_C()//ld $a, (0xFF00 + $c)
{
	Memory->Write((0xFF00 + Reg.BC.C), Reg.AF.A);
}

void LR35902::LD_A_FF00_IMM8()
{
	u8 imm8 = Memory->Read(++Reg.PC.val);
	Memory->Write(0xFF00 + imm8, Reg.AF.A);
}

/*
LD A,[$FF00+n8]
Load value in register A from high RAM or I/O registers.
The following synonym forces this encoding: LDH A,[$FF00+n8]
Cycles: 3
Bytes: 2
Flags: None affected.
*/
void LR35902::LD_A_FF00_N8()
{

}

void LR35902::CB(u8 opcode)
{
	switch (opcode)
	{
		 

	default:
		break;
	}
}

void LR35902::JMP(u8 opcode)
{
	switch (opcode)
	{
		//JMP
	case JR_R8://0x18
	case JR_NZ_R8://0x20
	case JR_Z_R8://0x28
	case JR_NC_R8://0x30
	case JR_C_R8://0x38
	case RET_NZ://0xC0
	case JP_NZ_A16://0xC2
	case JP_A16://0xC3
	case CALL_NZ_A16://0xC4
	case RST_00H://0xC7
	case RET_Z://0xC8
	case RET://0xC9
	case JP_Z_A16://0xCA
	case CALL_Z_A16://0xCC
	case CALL_A16://0xCD
	case RST_08H://0xCF
	case RET_NC://0xD0
	case JP_NC_A16://0xD2
	case CALL_NC_A16://0xD4
	case RST_10H://0xD7
	case RET_C://0xD8
	case RETI://0xD9
	case JP_C_A16://0xDA
	case CALL_C_A16://0xDC
	case RST_18H://0xDF
	case RST_20H://0xE7
	case JP_HLA://0xE9
	case RST_28H://0xEF
	case RST_30H://0xF7
	case RST_38H://0xFF
	default:
		break;
	}
}

void LR35902::ETC(u8 opcode)
{
	switch (opcode)
	{	//ETC
	case NOP://0x00
	case STOP://0x10
	case HALT://0x76
	case PREFIX_CB://0xCB
	case DI://0xF3
	case EI://0xFB
	default:
		break;
	}
}

void LR35902::DATA8(u8 opcode)
{
	switch (opcode)
	{

		//DATA8
	case LD_BC_A://0x02 
		LD_R16ADDR_A(Reg.BC.val);
		break;
	case LD_B_D8://0x06
		LD_R8_IMM(Reg.BC.B);
		break;
	case LD_A_BC://0x0A
		LD_A_R16ADDR(Reg.BC.val);
		break;
	case LD_C_D8://0x0E
		LD_R8_IMM(Reg.BC.C);
		break;
	case LD_DE_A://0x12 
		LD_R16ADDR_A(Reg.DE.val);
		break;
	case LD_D_D8://0x16
		LD_R8_IMM(Reg.DE.D);
		break;
	case LD_A_DE://0x1A
		LD_A_R16ADDR(Reg.DE.val);
		break;
	case LD_E_D8://0x1E
		LD_R8_IMM(Reg.DE.E);
		break;
	case LD_HL_PLUS_A://0x22 
		LD_HL_P_A();
		break;
	case LD_H_D8://
		LD_R8_IMM(Reg.HL.H);
		break;
	case LD_A_HLA_PLUS://0x2A 
			LD_A_HLA_P();
			break;
	case LD_L_D8://0x2E
		LD_R8_IMM(Reg.HL.L);
		break;
	case LD_HL_MNUS_A://0x32  
		 LD_HL_M_A();
		break;
	case LD_HLA_D8://0x36
		LD_HLADDR_N8();
		break;
	case LD_A_HLA_MNUS://0x3A 
		LD_A_HLA_M();
		break;
	case LD_A_D8://0x3E
		LD_R8_IMM(Reg.AF.A);
		break;
	case LD_B_B://0x40
		break;
	case LD_B_C://0x41 
		LD_R8_R8(Reg.BC.C,Reg.BC.B);
		break;
	case LD_B_D://0x42
		LD_R8_R8(Reg.DE.D, Reg.BC.B);
		break;
	case LD_B_E://0x43
		LD_R8_R8(Reg.DE.E, Reg.BC.B);
		break;
	case LD_B_H://0x44
		LD_R8_R8(Reg.HL.H, Reg.BC.B);
		break;
	case LD_B_L://0x45
		LD_R8_R8(Reg.HL.L, Reg.BC.B);
		break;
	case LD_B_HLA://0x46
		LD_R8_HLA(Reg.BC.B);
		break;
	case LD_B_A://0x47
		LD_R8_R8(Reg.AF.F, Reg.BC.B);
		break;
	case LD_C_B://0x48
		LD_R8_R8(Reg.BC.B, Reg.BC.C);
		break;
	case LD_C_C://0x49
		break;
	case LD_C_D://0x4A 
		LD_R8_R8(Reg.DE.D, Reg.BC.C);
		break;
	case LD_C_E://0x4B
		LD_R8_R8(Reg.DE.E, Reg.BC.C);
		break;
	case LD_C_H://0x4C
		LD_R8_R8(Reg.HL.H, Reg.BC.C);
		break;
	case LD_C_L://0x4D
		LD_R8_R8(Reg.HL.L, Reg.BC.C);
		break;
	case LD_C_HLA://0x4E
		LD_R8_HLA(Reg.BC.C);
		break;
	case LD_C_A://0x4F
		LD_R8_R8(Reg.AF.A, Reg.BC.C);
		break;
	case LD_D_B://0x50
		LD_R8_R8(Reg.BC.B, Reg.DE.D);
		break;
	case LD_D_C://0x51
		LD_R8_R8(Reg.BC.C, Reg.DE.D);
		break;
	case LD_D_D://0x52
		break;
	case LD_D_E://0x53 
		LD_R8_R8(Reg.DE.E, Reg.DE.D);
		break;
	case LD_D_H://0x54
		LD_R8_R8(Reg.HL.H, Reg.DE.D);
		break;
	case LD_D_L://0x55
		LD_R8_R8(Reg.HL.L, Reg.DE.D);
		break;
	case LD_D_HLA://0x56
		LD_R8_HLA(Reg.DE.D);
		break;
	case LD_D_A://0x57
		LD_R8_R8(Reg.AF.A, Reg.DE.D);
		break;
	case LD_E_B://0x58
		LD_R8_R8(Reg.BC.B, Reg.DE.E);
		break;
	case LD_E_C://0x59
		LD_R8_R8(Reg.BC.C, Reg.DE.E);
		break;
	case LD_E_D://0x5A
		LD_R8_R8(Reg.DE.D, Reg.DE.E);
		break;
	case LD_E_E://0x5B
		break;
	case LD_E_H://0x5C
		LD_R8_R8(Reg.HL.H, Reg.DE.E);
		break;
	case LD_E_L://0x5D
		LD_R8_R8(Reg.HL.L, Reg.DE.E);
		break;
	case LD_E_HLA://0x5E
		LD_R8_HLA(Reg.DE.E);
		break;
	case LD_E_A://0x5F
		LD_R8_R8(Reg.AF.A, Reg.DE.E);
		break;
	case LD_H_B://0x60
		LD_R8_R8(Reg.BC.B, Reg.HL.H);
		break;
	case LD_H_C://0x61
		LD_R8_R8(Reg.BC.C, Reg.HL.H);
		break;
	case LD_H_D://0x62
		LD_R8_R8(Reg.DE.D, Reg.HL.H);
		break;
	case LD_H_E://0x63
		LD_R8_R8(Reg.DE.E, Reg.HL.H);
		break;
	case LD_H_H://0x64
		break;
	case LD_H_L://0x65 
		LD_R8_R8(Reg.HL.L, Reg.HL.H);
		break;
	case LD_H_HLA://0x66
		LD_R8_HLA(Reg.HL.H);
		break;
	case LD_H_A://0x67
		LD_R8_R8(Reg.AF.F, Reg.HL.H);
		break;
	case LD_L_B://0x68
		LD_R8_R8(Reg.BC.B, Reg.HL.L);
		break;
	case LD_L_C://0x69
		LD_R8_R8(Reg.BC.C, Reg.HL.L);
		break;
	case LD_L_D://0x6A
		LD_R8_R8(Reg.DE.D, Reg.HL.L);
		break;
	case LD_L_E://0x6B
		LD_R8_R8(Reg.DE.E, Reg.HL.L);
		break;
	case LD_L_H://0x6C
		LD_R8_R8(Reg.HL.H, Reg.HL.L);
		break;
	case LD_L_L://0x6D 
		break;
	case LD_L_HLA://0x6E
		LD_R8_HLA(Reg.HL.L);
		break;
	case LD_L_A://0x6F
		LD_R8_R8(Reg.AF.F, Reg.HL.L);
		break;
	case LD_HLA_B://0x70
		LD_HLA_R8(Reg.BC.B);
		break;
	case LD_HLA_C://0x71
		LD_HLA_R8(Reg.BC.C);
		break;
	case LD_HLA_D://0x72
		LD_HLA_R8(Reg.DE.D);
		break;
	case LD_HLA_E://0x73
		LD_HLA_R8(Reg.DE.E);
		break;
	case LD_HLA_H://0x74
		LD_HLA_R8(Reg.HL.H);
		break;
	case LD_HLA_L://0x75
		LD_HLA_R8(Reg.HL.L);
		break;
	case LD_HLA_A://0x77
		LD_HLA_R8(Reg.AF.F);
		break;
	case LD_A_B://0x78
		LD_R8_R8(Reg.BC.B, Reg.AF.A);
		break;
	case LD_A_C://0x79
		LD_R8_R8(Reg.BC.C, Reg.AF.A);
		break;
	case LD_A_D://0x7A
		LD_R8_R8(Reg.DE.D, Reg.AF.A);
		break;
	case LD_A_E://0x7B
		LD_R8_R8(Reg.DE.E, Reg.AF.A);
		break;
	case LD_A_H://0x7C
		LD_R8_R8(Reg.HL.H, Reg.AF.A);
		break;
	case LD_A_L://0x7D
		LD_R8_R8(Reg.HL.L, Reg.AF.A);
		break;
	case LD_A_HLA://0x7E
		LD_R8_HLA(Reg.AF.A);
		break;
	case LD_A_A://0x7F
		break;
	case LDH_A8ADR_A://0xE0
		LD_FF00_IMM_A();
		break;
	case LD_CADR_A://0xE2
		LD_FF00_C_A();
		break;
	case LD_A16ADR_A://0xEA
		LD_IMM16_A();
		break;
	case LDH_A_A8ADR://0xF0 
		LD_A_FF00_IMM8();
		break;
	case LD_A_CADR://0xF2
		LD_A_FF00_C();
		break;
	case LD_A_A16ADR://0xFA
		LD_A_IMM16();
		break;
	default:
		break;
	}
}

void LR35902::BADOP(u8 opcode)
{
	switch (opcode)
	{
		//BADOP
	case BADOP_1://0xD3
	case BADOP_5://0xDB
	case BADOP_9://0xDD
	case BADOP_2://0xE3
	case BADOP_10://0xE4
	case BADOP_8://0xEB
	case BADOP_6://0xEC
	case BADOP_7://0xED
	case BADOP_11://0xF4
	case BADOP_3://0xFC
	case BADOP_4://0xFD

	default:
		break;
	}
}

void LR35902::DATA16(u8 opcode)
{
	switch (opcode)
	{


		//DATA16
	case LD_BC://0x01
	case LD_A16_SP://0x08
	case LD_DE_D16://0x11
	case LD_HL_D16://0x21
	case LD_SP_D16://0x31
	case POP_BC://0xC1
	case PUSH_BC://0xC5
	case POP_DE://0xD1
	case PUSH_DE://0xD5
	case POP_HL://0xE1
	case PUSH_HL://0xE5
	case POP_AF://0xF1
	case PUSH_AF://0xF5
	case LD_HL_SPP_R8://0xF8
	case LD_SP_HL://0xF9
	default:
		break;
	}
}

void LR35902::LOGIC8(u8 opcode)
{ 
	switch (opcode)
	{
		//LOGIC8
	case INC_B://0x04 
		INCR8(Reg.BC.B);
		break;
	case DEC_B://0x05
		DECR8(Reg.BC.B); 
		break;
	case INC_C://0x0C
		INCR8(Reg.BC.C);
		break;
	case DEC_C://0x0D
		DECR8(Reg.BC.C);
		break;
	case INC_D://0x14
		INCR8(Reg.DE.D);
		break;
	case DEC_D://0x15
		DECR8(Reg.DE.D);
		break;
	case INC_E://0x1C
		INCR8(Reg.DE.E);
		break;
	case DEC_E://0x1D
		DECR8(Reg.DE.E);
		break;
	case INC_H://0x24
		INCR8(Reg.HL.H);
		break;
	case DEC_H://0x25
		DECR8(Reg.HL.H);
		break;
	case DAA://0x27https://ehaskins.com/2018-01-30%20Z80%20DAA/
		OPDAA();
		break;
	case INC_L://0x2C
		INCR8(Reg.HL.L);
		break;
	case DEC_L://0x2D
		DECR8(Reg.HL.L);
		break;
	case CPL://0x2F
		Reg.AF.A = ~Reg.AF.A;
		break;
	case INC_HLA://0x34
		INCRHL(Reg.HL.val);
		break;
	case DEC_HLA://0x35
		DECRHL(Reg.HL.val);
		break;
	case SCF://0x37
		SetFlag(C);
	case INC_A://0x3C
		INCR8(Reg.AF.A);
		break;
	case DEC_A://0x3D
		DECR8(Reg.AF.A);
		break;
	case CCF://0x3F
		ToggleFlag(GC);
		break;
	case ADD_A_B://0x80
		ADD8(Reg.BC.B);
		break;
	case ADD_A_C://0x81
		ADD8(Reg.BC.C);
		break;
	case ADD_A_D://0x82
		ADD8(Reg.DE.D);
		break;
	case ADD_A_E://0x83
		ADD8(Reg.DE.E);
		break;
	case ADD_A_H://0x84
		ADD8(Reg.HL.H);
		break;
	case ADD_A_L://0x85
		ADD8(Reg.HL.L);
		break;
	case ADD_A_HLA://0x86
		ADDHLP();
		break;
	case ADD_A_A://0x87
		ADD8(Reg.AF.A);
		break;
	case ADC_A_B://0x88
		ADC8(Reg.BC.B);
		break;
	case ADC_A_C://0x89
		ADC8(Reg.BC.C);
		break;
	case ADC_A_D://0x8A
		ADC8(Reg.DE.D);
		break;
	case ADC_A_E://
		ADC8(Reg.DE.E);
		break;
	case ADC_A_H://0x8C
		ADC8(Reg.HL.H);
		break;
	case ADC_A_L://0x8D
		ADC8(Reg.HL.L);
		break;
	case ADC_A_HLA://0x8E
		ADCHLP();
		break;
	case ADC_A_A://0x8F
		ADC8(Reg.AF.A);
		break;
	case SUB_B://0x90
		SUB8(Reg.BC.B);
		break;
	case SUB_C://0x91
		SUB8(Reg.BC.C);
			break;
	case SUB_D://0x92
		SUB8(Reg.DE.D);
		break;
	case SUB_E://0x93
		SUB8(Reg.DE.E);
		break;
	case SUB_H://0x94
		SUB8(Reg.HL.H);
		break;
	case SUB_L://0x95
		SUB8(Reg.HL.L);
		break;
	case SUB_HLA://0x96
		SUBHLP();
		break;
	case SUB_A://0x97
		SUB8(Reg.AF.A);
		break;
	case SBC_A_B://0x98
		SBC8(Reg.BC.B);
		break;
	case SBC_A_C://0x99
		SBC8(Reg.BC.C);
		break;
	case SBC_A_D://0x9A
		SBC8(Reg.DE.D);
		break;
	case SBC_A_E://0x9B
		SBC8(Reg.DE.E);
		break;
	case SBC_A_H://0x9C
		SBC8(Reg.HL.H);
		break;
	case SBC_A_L://0x9D
		SBC8(Reg.HL.L);
		break;
	case SBC_A_HLA://0x9E
		SBCHL();
		break;
	case SBC_A_A://0x9F
		SBC8(Reg.AF.A);
		break;
	case AND_B://0xA0
		AND8(Reg.BC.B);
		break;
	case AND_C://0xA1
		AND8(Reg.BC.C);
		break;
	case AND_D://0xA2
		AND8(Reg.DE.D);
		break;
	case AND_E://0xA3
		AND8(Reg.DE.E);
		break;
	case AND_H://0xA4
		AND8(Reg.HL.H);
		break;
	case AND_L://0xA5
		AND8(Reg.HL.L);
		break;
	case AND_HLA://0xA6
		ANDHL();
		break;
	case AND_A://0xA7
		AND8(Reg.AF.A);
		break;
	case XOR_B://0xA8
		XOR8(Reg.BC.B);
		break;
	case XOR_C://0xA9
		XOR8(Reg.BC.C);
		break;
	case XOR_D://0xAA
		XOR8(Reg.DE.D);
		break;
	case XOR_E://0xAB
		XOR8(Reg.DE.E);
		break;
	case XOR_H://0xAC
		XOR8(Reg.HL.H);
		break;
	case XOR_L://0xAD
		XOR8(Reg.HL.L);
		break;
	case XOR_HLA://0xAE
		XORHL();
		break;
	case XOR_A://0xAF
		XOR8(Reg.AF.A);
		break;
	case OR_B://0xB0
		OR8(Reg.BC.B);
		break;
	case OR_C://0xB1
		OR8(Reg.BC.C);
		break;
	case OR_D://0xB2
		OR8(Reg.DE.D);
		break;
	case OR_E://0xB3
		OR8(Reg.DE.E);
		break;
	case OR_H://0xB4
		OR8(Reg.HL.H);
		break;
	case OR_L://0xB5
		OR8(Reg.HL.L);
		break;
	case OR_HLA://0xB6
		ORHL();
		break;
	case OR_A://0xB7
		OR8(Reg.AF.A);
		break;
	case CP_B://0xB8
		CP8(Reg.BC.B);
		break;
	case CP_C://0xB9
		CP8(Reg.BC.C);
		break;
	case CP_D://0xBA
		CP8(Reg.DE.D);
		break;
	case CP_E://0xBB
		CP8(Reg.DE.E);
		break;
	case CP_H://0xBC
		CP8(Reg.HL.H);
		break;
	case CP_L://0xBD
		CP8(Reg.HL.L);
		break;
	case CP_HLA://0xBE
		CPHL();
		break;
	case CP_A://0xBF
		CP8(Reg.AF.A);
		break;
	case ADD_A_D8://0xC6
		ADD8(ReadImmvalue8());
		break;
	case ADC_A_D8://0xCE
		ADC8(ReadImmvalue8());
		break;
	case SUB_D8://0xD6
		SUB8(ReadImmvalue8());
		break;
	case SBC_A_D8://0xDE
		SBC8(ReadImmvalue8());
		break;
	case AND_D8://0xE6
		AND8(ReadImmvalue8());
		break;
	case XOR_D8://0xEE
		XOR8(ReadImmvalue8());
		break;
	case OR_D8://0xF6
		OR8(ReadImmvalue8());
		break;
	case CP_D8://0xFE
		CP8(ReadImmvalue8());


	default:
		break;
	}
}

void LR35902::LOGIC16(u8 opcode)
{
	switch (opcode)
	{
		//LOGIC16
	case INC_BC://0x03
		INC16(Reg.BC.val);
		break;
	case ADD_HL_BC://0x09
		ADD16(Reg.BC.val);
		break;
	case DEC_BC://0x0B
		DEC16(Reg.BC.val);
		break;
	case INC_DE://0x13
		INC16(Reg.DE.val);
		break;
	case ADD_HL_DE://0x19
		ADD16(Reg.DE.val);
		break;
	case DEC_DE://0x1B
		DEC16(Reg.DE.val);
		break;
	case INC_HL://0x23
		INC16(Reg.HL.val);
		break;
	case ADD_HL_HL://0x29
		ADD16(Reg.HL.val);
		break;
	case DEC_HL://0x2B
		DEC16(Reg.HL.val);
		break;
	case INC_SP://0x33
		INC16(Reg.SP.val);
		break;
	case ADD_HL_SP://0x39
		ADD16(Reg.SP.val);
		break;
	case DEC_SP://0x3B
		DEC16(Reg.SP.val);
		break;
	case ADD_SP_E8://0xE8
		ADDSPE8();
		break;
	default:
		break;
	}
}











