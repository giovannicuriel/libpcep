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

#include "../utils.hpp"
#include "../types.hpp"


uint8_t ntoh(uint8_t data);
uint16_t ntoh(uint16_t data);
uint32_t ntoh(uint32_t data);
uint64_t ntoh(uint64_t data);
int8_t ntoh(int8_t data);
int16_t ntoh(int16_t data);
int32_t ntoh(int32_t data);
int64_t ntoh(int64_t data);
uint8_t hton(uint8_t data);
uint16_t hton(uint16_t data);
uint32_t hton(uint32_t data);
uint64_t hton(uint64_t data);
int8_t hton(int8_t data);
int16_t hton(int16_t data);
int32_t hton(int32_t data);
int64_t hton(int64_t data);

#endif /* SRC_MESSAGES_BYTEORDER_HPP_ */
