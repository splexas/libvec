# libvec
- this is a very tiny implementation of a dynamic vector, or a replica of `std::vector` in c++.
# usage
- constructor: `vec_init`. first argument takes the size of the desired object to store. second argument takes the number of specified objects to be reserved ahead (optionally, set it to -1 and it will take `VEC_RESERVED_ELEMENTS` instead)
- deconstructor: `vec_free`. first argument takes the allocated `vec_t` pointer provided by the constructor.
# test build
`cc test.c vec.c -o test`