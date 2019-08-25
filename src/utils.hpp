/*
 * @file utils.hpp
 *
 * Utility functions to be used in libpcep
 *
 * @author Giovanni Curiel dos Santos <giovannicuriel@gmail.com>
 * @date 25/08/2019
 *
 * @copyright 2019 Giovanni Curiel dos Santos
 */

#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include <arpa/inet.h>
#include <vector>
#include <iostream>

/**
 * Constant function to detect system endianess
 * @return true, if system is big-endian, false otherwise.
 */
inline constexpr bool isBigEndian() {
  return (1234 == ntohl(1234));
}


template <typename T>
void printVector(std::vector<T> buffer) {
  for (auto b : buffer) {
    std::cout << "[" << b << "]";
  }
}

template <typename T, typename F>
void printVector(std::vector<T> buffer, F format) {
  for (auto b : buffer) {
    std::cout << "[" << format << (uint32_t) b << std::dec << "]";
  }
}

#endif /* SRC_UTILS_HPP_ */
