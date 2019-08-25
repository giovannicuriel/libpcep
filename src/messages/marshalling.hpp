/*
 * @file marshalling.hpp
 *
 * Functions used to marshall and unmarshall data from byte arrays.
 *
 * @author Giovanni Curiel dos Santos <giovannicuriel@gmail.com>
 * @date 25/08/2019
 *
 * @copyright 2019 Giovanni Curiel dos Santos
 */

#ifndef SRC_MESSAGES_MARSHALLING_HPP_
#define SRC_MESSAGES_MARSHALLING_HPP_

#include <stdint.h>
#include <string.h>
#include <string>
#include <vector>
#include "../types.hpp"
#include "byteorder.hpp"

/**
 * Marshall data into a byte vector
 *
 * This function will marshall data into array. If needed, any byte-endianess conversion
 * is performed, so that everything is in network byte order (big-endian).
 * @param data The data to be marshalled
 * @param v The vector in which the data will be marshalled
 * @return return_t.SUCCESS, if data was successfully put into the array
 */
template<typename T>
return_t marshall(const T &data, std::vector<byte> *v) {
  const T convertedData = hton(data);
  const byte *rawData = reinterpret_cast<const byte*>(&convertedData);
  for (uint16_t i = 0; i < sizeof(T); i++) {
    v->push_back(rawData[i]);
  }
  return SUCCESS;
}

/**
 * Marshall a vector of items into a byte vector
 *
 * This function will marshall data into array. If needed, any byte-endianess conversion
 * is performed, so that everything is in network byte order (big-endian).
 * @param data The data to be marshalled
 * @param v The vector in which the data will be marshalled
 * @return return_t.SUCCESS, if data was successfully put into the array
 */
template<typename T>
return_t marshall(const std::vector<T> &data, std::vector<byte> *v) {
  const uint16_t length = data.size();
  return_t ret = marshall(length, v);
  if (ret != SUCCESS) {
    return ret;
  }
  for (auto obj : data) {
    ret = marshall(obj, v);
  }
  return SUCCESS;
}

/**
 * Unmarshall data from a byte vector
 *
 * This function will unmarshall data into array.
 * If needed, any byte-endianess conversion is performed, so that
 * everything is in network byte order (big-endian).
 * @param v The vector from which the data will be unmarshalled
 * @param offset How many bytes were already unmarshalled.
 * @param data The data to be marshalled
 * @return return_t.SUCCESS, if data was successfully put into the array
 * @return return_t.OVERFLOW, if byte array remaining bytes is less than data size.
 */
template<typename T>
return_t unmarshall(const std::vector<byte> &v, uint16_t *offset, T *data) {
  if (sizeof(T) + (*offset) > v.size()) {
    return OVERFLOW;
  }
  T originalData;
  ::memcpy(&originalData, &(v)[*offset], sizeof(T));
  *data = ntoh(originalData);
  *offset += sizeof(T);

  return SUCCESS;
}

/**
 * Unmarshall a vector of items from a byte vector
 *
 * This function will unmarshall data into array.
 * If needed, any byte-endianess conversion is performed, so that
 * everything is in network byte order (big-endian).
 * @param v The vector from which the data will be unmarshalled
 * @param offset How many bytes were already unmarshalled.
 * @param data The data to be marshalled
 * @return return_t.SUCCESS, if data was successfully put into the array
 * @return return_t.OVERFLOW, if byte array remaining bytes is less than data size.
 */
template<typename T>
return_t unmarshall(const std::vector<byte> &v, uint16_t *offset,
                    std::vector<T> *data) {
  uint16_t size = 0;
  unmarshall(v, offset, &size);
  T originalData;
  for (size_t i = 0; i < size; i++) {
    unmarshall(v, offset, &originalData);
    data->push_back(originalData);
  }
  return SUCCESS;
}

#endif  // SRC_MESSAGES_MARSHALLING_HPP_
