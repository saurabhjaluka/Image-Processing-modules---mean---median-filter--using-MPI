// --*-c++-*--


#ifndef _IMAGE_H
#define _IMAGE_H

#include <stdint.h>

#include <vector>
#include <string>

class Image {
public:
  Image();
  Image(const Image &other);
  Image& operator=(const Image &rhs);
 
  void load_tiff(std::string input_filename);
  void save_tiff_rgb(std::string output_filename);
  void save_tiff_grey_32bit(std::string output_filename);
  void save_tiff_grey_8bit(std::string output_filename);
  unsigned int* getData();
  void setData(uint32_t *data,int size);
  void make_greyscale();
  void image_filter_mean(int windowSize);
  void image_filter_median(int windowSize);

  inline size_t& height() 
  { 
    return m_height; 
  };

  inline size_t& width() 
  { 
    return m_width; 
  };

  inline uint32_t& operator()(int r, int c) 
  {
     return P(r,c);
  }

  inline uint32_t& P(std::vector<uint32_t> &data, int r, int c)
  {
     size_t index = m_width * r + c;
     return data[index];
  } 

  inline uint32_t& P(int r, int c)
  {
     size_t index = m_width * r + c;
     return m_image_data[index];
  }
 
private:
  std::vector<uint32_t> m_image_data;
  size_t m_width;
  size_t m_height;
};

#endif 
