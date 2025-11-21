/*-
 * Free/Libre Near Field Communication (NFC) library
 *
 * Libnfc historical contributors:
 * Copyright (C) 2009      Roel Verdult
 * Copyright (C) 2009-2013 Romuald Conty
 * Copyright (C) 2010-2012 Romain Tartière
 * Copyright (C) 2010-2013 Philippe Teuwen
 * Copyright (C) 2012-2013 Ludovic Rousseau
 * See AUTHORS file for a more comprehensive list of contributors.
 * Additional contributors of this file:
 * Copyright (C) 2020      Adam Laurie
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

/**
 * @file pn5180.h
 * @brief PN5180 common functions
 */

#ifndef __NFC_CHIPS_PN53X_H__
#define __NFC_CHIPS_PN53X_H__

#  include <nfc/nfc-types.h>
#  include "pn5180-internal.h"

/**
 * @enum pn5180_transceive_state
 * @brief Enumeration for the value of TRANSCEIVE_STATE (bits 26:24)
 * from the RF_STATUS register
 */
typedef enum {
  IDLE          = 0,
  WAIT_TRANSMIT = 1,
  TRANSMITTING  = 2,
  WAIT_RECEIVE  = 3,
  WAIT_FOR_DATA = 4,
  RECEIVING     = 5,
  LOOPBACK      = 6,
  RESERVED      = 7
} pn5180_transceive_state; // NOTE: (temp - to read the u8/enum value, >> 24 and & 0x07)

/**
 * @enum pn5180_irq_status
 * @brief Enumeration for the value of IRQ_STATUS (bits 19:0)
 * from the IRQ_STATUS register (bits 31:20 are RFU)
 *
 * See the PN5180 data sheet, section 11.9.2: Register description, table 77.
 * IRQ_STATUS register (address 0002h) bit description, page 84 rev. 4.3 - 2025-10-30.
 */
typedef enum {
  RX_IRQ_STAT              = (1 << 0),
  TX_IRQ_STAT              = (1 << 1),
  IDLE_IRQ_STAT            = (1 << 2),
  MODE_DETECTED_IRQ_STAT   = (1 << 3),
  CARD_ACTIVATED_IRQ_STAT  = (1 << 4),
  STATE_CHANGE_IRQ_STAT    = (1 << 5),
  RFOFF_DET_IRQ_STAT       = (1 << 6),
  RFON_DET_IRQ_STAT        = (1 << 7),
  TX_RFOFF_IRQ_STAT        = (1 << 8),
  TX_RFON_IRQ_STAT         = (1 << 9),
  RF_ACTIVE_ERROR_IRQ_STAT = (1 << 10),
  TIMER0_IRQ_STAT          = (1 << 11),
  TIMER1_IRQ_STAT          = (1 << 12),
  TIMER2_IRQ_STAT          = (1 << 13),
  RX_SOF_DET_IRQ_STAT      = (1 << 14),
  RX_SC_DET_IRQ_STAT       = (1 << 15),
  TEMPSENS_ERROR_IRQ_STAT  = (1 << 16),
  GENERAL_ERROR_IRQ_STAT   = (1 << 17),
  LPCD_IRQ_STAT            = (1 << 19),
} pn5180_irq_status; // NOTE: (temp - to read the bit value, just mask the bits read from the IRQ_STATUS register)

# endif // __NFC_CHIPS_PN53X_H__
