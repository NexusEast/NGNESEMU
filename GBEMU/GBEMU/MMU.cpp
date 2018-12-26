#include "MMU.h"


u8 SimpleMMU::Read(u16 addr)
{
	return Memory[addr%MAX_MEM_SIZE];
}

bool SimpleMMU::Write(u16 addr, u8 data)
{
	Memory[addr%MAX_MEM_SIZE] = data;
	return true;
}

u16 SimpleMMU::Read16(u16 baseAddr)
{
	u8 lo = Read(baseAddr);
	u8 hi = Read(baseAddr + 1);
	return (hi << 8u) | lo;

}
