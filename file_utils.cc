
#include <stdio.h>
#include <iostream>

int compare_two_binary_files(const char *f1, const char *f2)
{
  char ch1, ch2;
  int flag = 0;
 
  FILE *fp1 = fopen(f1, "r");
  FILE *fp2 = fopen(f2, "r");

  if (!fp1) {
    printf("error opening file: %s\n", f1);
  }

  if (!fp2) {
    printf("error opening file: %s\n", f2);
  }
	long int byteCount=0;
  while (((ch1 = fgetc(fp1)) != EOF) &&((ch2 = fgetc(fp2)) != EOF)) {
    if (ch1 == ch2) {
      flag = 0;
	byteCount++;
      continue;
    } else {
      fseek(fp1, -1, SEEK_CUR);        
      flag = 1;
      break;
    }
  }
if(flag == 1)
 std::cout<<"differ at : "<<byteCount<<" : count : "<<"\n";
  fclose(fp1);
  fclose(fp2);

  return flag;
}
