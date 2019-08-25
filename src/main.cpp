/*
 * @file main.cpp
 *
 * Main function
 *
 * @author Giovanni Curiel dos Santos <giovannicuriel@gmail.com>
 * @date 25/08/2019
 *
 * @copyright 2019 Giovanni Curiel dos Santos
 */

#include <stdint.h>
#include <iostream>
#include "messages/marshalling.hpp"
#include "utils.hpp"
#include "messages/common_header.hpp"


int main(void) {
  uint32_t data = 1234;
  uint32_t shadowData = 0;
  std::vector<byte> buffer;
  uint16_t offset = 0;
  marshall(data, &buffer);
  printVector(buffer, std::hex);
  std::cout << "\n";
  offset = 0;
  unmarshall(buffer, &offset, &shadowData);
  std::cout << "unmarshall: " << shadowData << "\n";

  std::vector<uint32_t> data32 = { 10000, 20000, 30000 };
  std::vector<uint32_t> shadowData32;
  buffer.clear();
  offset = 0;
  marshall(data32, &buffer);
  printVector(buffer, std::hex);
  unmarshall(buffer, &offset, &shadowData32);
  printVector(shadowData32, std::dec);
  std::cout << "----------------------\n";

  CommonHeader ch;
  buffer.clear();
  ch.marshall(&buffer);
  printVector(buffer, std::hex);
  return 0;
}
