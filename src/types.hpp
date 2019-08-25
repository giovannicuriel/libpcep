// Copyright 2019 Giovanni Curiel dos Santos

#ifndef SRC_TYPES_HPP_
#define SRC_TYPES_HPP_

#include <stdint.h>

typedef uint8_t byte;

typedef enum {
  SUCCESS = 0,
  OVERFLOW = -2
} return_t;

#endif  // SRC_TYPES_HPP_
