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
  "AL",
  "CL",
  "DL",
  "BL",
  "AH",
  "CH",
  "DH",
  "BH"
};

char * xregistersName[8] = {
  "AX",
  "CX",
  "DX",
  "BX",
  "SP",
  "BP",
  "SI",
  "DI"  
};
