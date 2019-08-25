/*
 * @file byteorder.hpp
 *
 * Implementation of byte-ordering functions.
 *
 * @author Giovanni Curiel dos Santos <giovannicuriel@gmail.com>
 * @date 25/08/2019
 *
 * @copyright 2019 Giovanni Curiel dos Santos
 */

#ifndef SRC_MESSAGES_BYTEORDER_HPP_
#define SRC_MESSAGES_BYTEORDER_HPP_

#include <stdint.h>
#include <arpa/inet.h>
#include "../utils.hpp"
#include "byteorder.hpp"


uint8_t ntoh(uint8_t data) {
  return data;
}

uint16_t ntoh(uint16_t data) {
  return ntohs(data);
}

uint32_t ntoh(uint32_t data) {
  return ntohl(data);
}

uint64_t ntoh(uint64_t data) {
  if (isBigEndian()) {
    return data;
  } else {
    uint64_t convertedData = 0;
    convertedData |= ntohl((data >> 32) && 0xffffffff);
    convertedData |= (uint64_t) (ntohl((data & 0xffffffff))) << 32;
    return convertedData;
  }
}

int8_t ntoh(int8_t data) {
  return data;
}

int16_t ntoh(int16_t data) {
  return ntohs(data);
}

int32_t ntoh(int32_t data) {
  return ntohl(data);
}

int64_t ntoh(int64_t data) {
  if (isBigEndian()) {
    return data;
  } else {
    int64_t convertedData = 0;
    convertedData |= ntohl((data >> 32) && 0xffffffff);
    convertedData |= (uint64_t) (ntohl((data & 0xffffffff))) << 32;
    return convertedData;
  }
}

uint8_t hton(uint8_t data) {
  return data;
}

uint16_t hton(uint16_t data) {
  return htons(data);
}

uint32_t hton(uint32_t data) {
  return htonl(data);
}

uint64_t hton(uint64_t data) {
  if (isBigEndian()) {
    return data;
  } else {
    uint64_t convertedData = 0;
    convertedData |= htonl((data >> 32) && 0xffffffff);
    convertedData |= (uint64_t) (htonl((data & 0xffffffff))) << 32;
    return convertedData;
  }
}

int8_t hton(int8_t data) {
  return data;
}


int16_t hton(int16_t data) {
  return htons(data);
}

int32_t hton(int32_t data) {
  return htonl(data);
}

int64_t hton(int64_t data) {
  if (isBigEndian()) {
    return data;
  } else {
    int64_t convertedData = 0;
    convertedData |= htonl((data >> 32) && 0xffffffff);
    convertedData |= (int64_t) (htonl((data & 0xffffffff))) << 32;
    return convertedData;
  }
}

#endif /* SRC_MESSAGES_BYTEORDER_HPP_ */
