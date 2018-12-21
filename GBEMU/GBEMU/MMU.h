#ifndef MMU_H_
#define  MMU_H_
#include "DataTypes.h"
#define  MAX_MEM_SIZE   0XFF
class  IMMU
{
public:
	virtual u8 Read(u16 addr) = 0;
	virtual bool Write(u16 addr, u8 data) = 0;
protected:
	u8 Memory[MAX_MEM_SIZE];
};

class SimpleMMU : public IMMU
{
public:
	virtual u8 Read(u16 addr) override;
	virtual bool Write(u16 addr, u8 data) override;
};
#endif