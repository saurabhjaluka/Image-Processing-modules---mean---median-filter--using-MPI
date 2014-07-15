// --*-c++-*--

#include <stdlib.h>

#include <iostream>
#include <string>

#include "image.h"
#include "image_utils.h"

std::string serial_main(int argc, char* argv[])
{
  if (argc < 5) {
    std::cout << "usage: " << argv[0] << " "
	      << "<in image> <out image> <filter type> <window size>"
              << std::endl;
    std::cout << " filter type = {mean|median} " << std::endl;
    exit(-1);
  }

  std::string inFilename(argv[1]);
  std::string outFilename(argv[2]);
  std::string filterType(argv[3]);
  int windowSize = atoi(argv[4]);

  outFilename = "s_" + outFilename;

  Image input;
  std::cout << "* doing serial image filtering ** " << std::endl;
  std::cout << "* reading regular tiff: " << argv[1] << std::endl;
  input.load_tiff(std::string(argv[1]));

  Image output = input;
  output.make_greyscale();

  if (filterType == "mean") {
    std::cout << "* processing with filter: " << filterType << std::endl;
    output.image_filter_mean(windowSize);
  }
  else if (filterType == "median") {
    std::cout << "* processing with filter: " << filterType << std::endl;
    output.image_filter_median(windowSize);
  }

  std::cout << "* saving image: " << outFilename << std::endl;
  output.save_tiff_grey_8bit(outFilename);

  std::cout << "-- done --" << std::endl;

  return outFilename;
}
