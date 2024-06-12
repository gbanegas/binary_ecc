cmake_minimum_required(VERSION 3.28)
project(bin_thomas C)

set(CMAKE_C_STANDARD 11)

add_executable(bin_thomas main.c)


add_executable(ff_bench ff_benchmark.c arith_233/ff_2_233.c randomness/randombytes.c)
add_executable(ff_test ff_test.c arith_233/ff_2_233.c randomness/randombytes.c)



add_executable(bin_ops main.c bin_ecc_op.c arith_233/ff_2_233.c randomness/randombytes.c)