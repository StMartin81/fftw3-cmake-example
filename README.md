This is an example project on how to include the FFTW library into a CMake project.

Build build the project with:
```
$ cd <path to build dir>
$ cmake -DBUILD_TESTS=OFF -DENABLE_THREADS=ON -DENABLE_OPENMP=ON -DENABLE_SSE=ON -DENABLE_SSE2=ON -DENABLE_AVX=ON -DENABLE_AVX2=ON -DBUILD_SHARED_LIBS=OFF <path to source dir>
```