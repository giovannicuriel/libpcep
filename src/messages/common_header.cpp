/*
 * @file common_header.cpp
 *
 * CommonHeader implementation
 *
 * @author Giovanni Curiel dos Santos <giovannicuriel@gmail.com>
 * @date 25/08/2019
 *
 * @copyright 2019 Giovanni Curiel dos Santos
 */

#include <vector>
#include <iostream>
#include "../types.hpp"
#include "marshalling.hpp"
#include "../utils.hpp"
#include "common_header.hpp"

CommonHeader::CommonHeader(Version version, uint8_t flags, MessageType messageType) {
  this->ver = version;
  this->messageType = messageType;
  this->flags = flags;
  this->messageLength = 0;
}

CommonHeader::~CommonHeader() {
}

return_t CommonHeader::marshall(std::vector<byte> *out) {
  const uint8_t verflags = this->ver | (this->flags << 3);
  const uint8_t type = this->messageType;
  ::marshall(verflags, out);
  ::marshall(type, out);
  ::marshall(this->messageLength, out);
  return SUCCESS;
}

std::ostream& operator<<(std::ostream &out, const CommonHeader &obj) {
  out << "version: " << obj.ver;
  out << ", flags: " << static_cast<int>(obj.flags);
  out << ", message type: " << obj.messageType;
  out << ", message length: " << obj.messageLength;
  return out;
}

