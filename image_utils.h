// --*-c++-*--

#ifndef _IMAGE_UTILS_H
#define _IMAGE_UTILS_H

void image_clone(Image &src, Image &dest);
void image_filter_mean(Image &image, int windowSize);
void image_filter_gaussian(Image &image, int windowSize); 

void compareImageFile(const char *f1, const char *f2);

#endif
