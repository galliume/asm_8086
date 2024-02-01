#pragma once

typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned char u8;

enum lregisters : u8
{
  AL,
  CL,
  DL,
  BL,
  AH,
  CH,
  DH,
  BH
};

enum xregisters : u8
{
  AX,
  CX,
  DX,
  BX,
  SP,
  BP,
  SI,
  DI
};

char * lregistersName[8] = {
  "al",
  "cl",
  "dl",
  "bl",
  "ah",
  "ch",
  "dh",
  "bh"
};

char * xregistersName[8] = {
  "ax",
  "cx",
  "dx",
  "bx",
  "sp",
  "bp",
  "si",
  "di"  
};
