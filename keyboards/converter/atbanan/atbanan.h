/*
  Copyright 2012 Jun Wako <wakojun@gmail.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

#define XXX KC_NO

/*
   .-------.  .-----------------------------------------------------------.  .---------------.
   | 05| 06|  | 0E| 16| 1E| 26| 25| 2E| 36| 3D| 3E| 46| 45| 4E| 55| 5D| 66|  | 76| 77| 7E| 7F|
   |-------|  |-----------------------------------------------------------|  |---------------|
   | 04| 0C|  |  0D | 15| 1D| 24| 2D| 2C| 35| 3C| 43| 44| 4D| 54| 5B|     |  | 6C| 75| 7D| 7C|
   |-------|  |-----------------------------------------------------|     |  |-----------|---|
   | 03| 0B|  |  14  | 1C| 1B| 23| 2B| 34| 33| 3B| 42| 4B| 4C| 52|   5A   |  | 6B| 73| 74| 7B|
   |-------|  |-----------------------------------------------------------|  |-----------|---|
   | 02| 0A|  |   12   | 1A| 22| 21| 2A| 32| 31| 3A| 41| 49| 4A|    59    |  | 69| 72| 7A|   |
   |-------|  |-----------------------------------------------------------|  |-----------| 79|
   | 01| 09|  |  11  |     |              29              |        |  58  |  |   70  | 71|   |
   '-------'  '------'     '------------------------------'        '------'  '---------------'
*/
#define LAYOUT_atbanan( \
    K05, K06,    K0E, K16, K1E, K26, K25, K2E, K36, K3D, K3E, K46, K45, K4E, K55, K5D, K66,    K76, K77, K7E, K7F, \
    K04, K0C,    K0D, K15, K1D, K24, K2D, K2C, K35, K3C, K43, K44, K4D, K54, K5B,              K6C, K75, K7D, K7C, \
    K03, K0B,    K14, K1C, K1B, K23, K2B, K34, K33, K3B, K42, K4B, K4C, K52,        K5A,       K6B, K73, K74, K7B,\
    K02, K0A,    K12,      K1A, K22, K21, K2A, K32, K31, K3A, K41, K49, K4A,        K59,       K69, K72, K7A, K79, \
    K01, K09,    K11,                          K29,                                 K58,       K70     , K71 \
) { \
    { XXX, K01, K02, K03, K04, K05, K06, XXX }, \
    { XXX, K09, K0A, K0B, K0C, K0D, K0E, XXX }, \
    { XXX, K11, K12, XXX, K14, K15, K16, XXX }, \
    { XXX, XXX, K1A, K1B, K1C, K1D, K1E, XXX }, \
    { XXX, K21, K22, K23, K24, K25, K26, XXX }, \
    { XXX, K29, K2A, K2B, K2C, K2D, K2E, XXX }, \
    { XXX, K31, K32, K33, K34, K35, K36, XXX }, \
    { XXX, XXX, K3A, K3B, K3C, K3D, K3E, XXX }, \
    { XXX, K41, K42, K43, K44, K45, K46, XXX }, \
    { XXX, K49, K4A, K4B, K4C, K4D, K4E, XXX }, \
    { XXX, XXX, K52, XXX, K54, K55, XXX, XXX }, \
    { K58, K59, K5A, K5B, XXX, K5D, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, K66, XXX }, \
    { XXX, K69, XXX, K6B, K6C, XXX, XXX, XXX }, \
    { K70, K71, K72, K73, K74, K75, K76, K77 }, \
    { XXX, K79, K7A, K7B, K7C, K7D, K7E, K7F } \
}
