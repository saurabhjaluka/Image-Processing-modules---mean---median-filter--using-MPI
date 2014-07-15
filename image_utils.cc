// --*-c++-*--

#include <stdio.h>

#include "image.h"
#include "image_utils.h"
#include "file_utils.h"

void image_clone(Image &src, Image &dest)
{
   dest = src;
}

void compareImageFile(const char *f1, const char *f2)
{
  if (compare_two_binary_files(f1, f2) == 0) {
    printf("%s is the same as %s\n", f1, f2);
  } else {
    printf("%s is NOT the same as %s\n", f1, f2);
  }
}

