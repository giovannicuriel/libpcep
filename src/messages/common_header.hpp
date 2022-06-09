/*
 * @file common_header.hpp
 *
 * CommonHeader definition
 *
 * @author Giovanni Curiel dos Santos <giovannicuriel@gmail.com>
 * @date 25/08/2019
 *
 * @copyright 2019 Giovanni Curiel dos Santos
 */

#ifndef SRC_MESSAGES_COMMON_HEADER_HPP_
#define SRC_MESSAGES_COMMON_HEADER_HPP_

#include <vector>
#include "../types.hpp"
#include "marshalling.hpp"
#include "../utils.hpp"

/**
 * Values for Ver field in CommonHeader
 */
enum Version {
  VERSION_ONE = 1,  //!< ONE
};

/**
 * Values for Message-Type field in CommonHeader.
 * @see https://tools.ietf.org/html/rfc5440#section-6.1
 * @see https://tools.ietf.org/html/rfc5440#section-9.2
 */
enum MessageType {
  MSG_TYPE_OPEN = 1,
  MSG_TYPE_KEEP_ALIVE = 2,
  MSG_TYPE_PATH_COMPUTATION_REQUEST = 3,
  MSG_TYPE_PATH_COMPUTATION_RESPONSE = 4,
  MSG_TYPE_NOTIFICATION = 5,
  MSG_TYPE_ERROR = 6,
  MSG_TYPE_CLOSE = 7
};

/**
 * Common header for PCEP messages.
 * Encoded message:
 *
 *      0                   1                   2                   3
 *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *   | Ver |  Flags  |  Message-Type |       Message-Length          |
 *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 * @see https://tools.ietf.org/html/rfc5440#section-6.1
 */
class CommonHeader {
 protected:
  Version ver;
  uint8_t flags;
  MessageType messageType;
  uint16_t messageLength;

 public:
  CommonHeader(Version version = VERSION_ONE, uint8_t flags = 0,
               MessageType messageType = MSG_TYPE_OPEN);
  virtual ~CommonHeader();

  void updateMessageLength(uint16_t length);

  return_t marshall(std::vector<byte> *out);
  return_t unmarshall(std::vector<byte> *out, uint16_t *offset);
  friend std::ostream& operator<<(std::ostream &out, const CommonHeader &obj);
};

#endif  // SRC_MESSAGES_COMMON_HEADER_HPP_
