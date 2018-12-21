#pragma once

#ifndef u8
#define u8 unsigned char
#endif


#ifndef u16
#define u16 unsigned short
#endif


#ifndef u32
#define u32 unsigned int
#endif

#ifdef __LITTLEENDIAN__
#define MAKEUNION(H,L)  union H##LDEC {u16 val; struct { u8 L; u8 H;}; }H##L;
#else 
#define MAKEUNION(H,L) union H##LDEC {u16 val; struct { u8 H; u8 L;}; }H##L;
#endif
 