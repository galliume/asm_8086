#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "defines.h"

int main(int argc, char** argv)
{

  if (argc < 2) 
  {
    printf("Needs a filename");
    return -1;
  }

  u64 size = 0;
  char * file_name = argv[1];

  FILE* fp = fopen(file_name, "rb");

  if (fp == NULL) 
  {
    printf("%s: %s", "Cannot open file", file_name);
    fclose(fp);
    return -1;
  }

  printf("Decoding %s \n", file_name);
  printf("%s", "16 bits \n");

  uint8_t data;

  while (fread(&data, sizeof(uint8_t), 1, fp))
  {
    if (data >> 2 == 0b100010) //mov instruction
    {
      uint8_t dBit = data >> 1 & 1;
      uint8_t wBit = data & 1;

      //printf("%s %d/%d", "mov", dBit, wBit);

      fread(&data, sizeof(uint8_t), 1, fp);

      uint8_t mod = data >> 6;
      uint8_t reg = data >> 3 & 0b111;
      uint8_t rm = data & 0b111;

      //printf("\t %d/%d/%d \n", mod, reg, rm);

      uint8_t source, dest;

      if (dBit == 0)
      {
        source = reg;
        dest = rm;
      }
      else
      {
        source = rm;
        dest = reg;
      }

      if (wBit == 1) 
      {
        printf("mov %s, %s", xregistersName[dest], xregistersName[source]);
      }
      else
      {
        printf("mov %s, %s", lregistersName[dest], lregistersName[source]);
      }
      printf("\n");
    }
  }
  fclose(fp);

  printf("\n\n");

  return 0;
}

//cpy D = S (copy S to D)
//mov AX,BX

//D bit 0 register is source
//D bit 1 register is destination

//D give what is reg, rm is the other (source | destination)

//reg / rm 3 bits each

//W is 0 8 bits
//W is 1 16 bits

