// --*-c++-*--

#include <stdlib.h>
#include <iostream>
#include <string>

#include "image.h"
#include "image_utils.h"
#include "file_utils.h"

int main(int argc, char* argv[])
{
  if (argc < 3) {
    std::cout << "usage: " << argv[0] 
	      << " <in image> <window size> " << std::endl;
    return -1;
  }

  std::string inFilename(argv[1]);
  int windowSize = atoi(argv[2]);

  Image input;
  std::cout << "- reading regular tiff: " << argv[1] << std::endl;
  input.load_tiff(std::string(argv[1]));

  { 
    Image output = input;
    std::string outName = "out.tiff"; 
    std::cout << "- saving regular tiff: " << outName << std::endl;
    output.save_tiff_rgb(outName);
  }

  { 
    Image output = input;
    std::string outName = "out2.tiff"; 
    std::cout << "- saving regular tiff: " << outName << std::endl;
    output.save_tiff_rgb(outName);
  }

  { 
    Image output = input;
    output.make_greyscale();
    std::string outName = "out_32bit.tiff";
    std::cout << "- saving 32bit tiff: " << outName << std::endl;
    output.save_tiff_grey_32bit(outName);
  }

  { 
    Image output = input;
    output.make_greyscale();
    std::string outName = "out_8bit.tiff";
    std::cout << "- saving 8bit tiff: " << outName << std::endl;
    output.save_tiff_grey_8bit(outName);
  }

  {
    Image output = input;
    std::string outName = "out_mean.tiff";
    std::cout << "- saving mean tiff: " << outName << std::endl;
    output.make_greyscale();
    output.image_filter_mean(windowSize);
    output.save_tiff_grey_8bit(outName);
  }

  {
    Image output = input;
    std::string outName = "out_median.tiff";
    std::cout << "- saving median tiff: " << outName << std::endl;
    output.make_greyscale();
    output.image_filter_median(windowSize);
    output.save_tiff_grey_8bit(outName);
  }

  compareImageFile("out.tiff", "out2.tiff");
  compareImageFile("out.tiff", "out_32bit.tiff");

  return 0;
}
