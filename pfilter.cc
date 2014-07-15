
#include <stdio.h>
#include <iostream>
#include <string>
#include <mpi.h>

#include "image.h"
#include "image_utils.h"
#include "file_utils.h"

extern std::string serial_main(int argc, char* argv[]);
extern std::string parallel_main(int argc, char* argv[]);

int main(int argc, char *argv[]) {
  int numprocs;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  int rank = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  std::string p_image = parallel_main(argc, argv);

  if (rank == 0) {
     std::string s_image = serial_main(argc, argv);
     compareImageFile(s_image.c_str(), p_image.c_str());
  }

  MPI_Finalize();

  return 0;
}
