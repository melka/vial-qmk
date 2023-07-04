/*
  SingleWireSerial.h - A software serial library that uses only
  one wire to connect two systems in half-duplex mode. In addition,
  it uses the input capture feature and output
  compare match feature of timer 1 in order to support high bit rates.
  It is loosely based on SoftwareSerial, but uses a completely
  different method for reading and writing.

  Since one usually has only one input capture pin, it does not make
  sense to have more than one instance.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

#ifndef SingleWireSerial_h
#define SingleWireSerial_h
#include "SingleWireSerial_config.h"
#include <inttypes.h>
#include <stdbool.h>

/******************************************************************************
* Definitions
******************************************************************************/

#ifndef _SS_MAX_RX_BUFF
#define _SS_MAX_RX_BUFF 64 // RX buffer size
#endif

// only 1 object possible, so everything is static
/*static bool _ss_twoWire;
static bool _ss_waitBeforeSending;
static bool _ss_buffer_overflow;
static uint16_t _ss_oneAndAHalfBitDelay;
static uint16_t _ss_bitDelay;
static uint16_t _ss_endOfByte;
static uint8_t _ss_setICfalling, _ss_setICrising, _ss_setCTC;
static uint8_t _ss_receive_buffer[_SS_MAX_RX_BUFF];
static volatile uint8_t _ss_receive_buffer_tail;
static volatile uint8_t _ss_receive_buffer_head;*/

void ss_setRxIntMsk(bool enable);

// public methods
void ss_init(bool twoWire);
void ss_destroy(void);
void ss_begin(long speed);
void ss_end(void);
bool ss_overflow(void);
int ss_peek(void);

size_t ss_write(uint8_t data);
int ss_read(void);
int ss_available(void);
void ss_flush(void);
static inline bool ss_bool(void) { return true; }

// public only for easy access by interrupt handler
static inline void ss_handle_interrupt(void) __attribute__((__always_inline__));

#endif
