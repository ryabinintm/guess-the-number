cmake_minimum_required(VERSION 3.8)

project(guess_the_number CXX)

add_executable(a.out main.cpp random_number.cpp high_scores.cpp)

target_compile_features(a.out PUBLIC cxx_std_17)

if (MSVC)
	target_compile_options(a.out PUBLIC /W4 /Wx)
else()
	target_compile_options(a.out PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
