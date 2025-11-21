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
 * @file pn5180-internal.h
 * @brief PN5180 defines and compatibility
 */

#ifndef __PN5180_INTERNAL_H__
#define __PN5180_INTERNAL_H__

#include "log.h"

/**
 * @note PN5180 host-interface commands:
 * See the PN5180 data sheet, section 11.4.3.3: Host-interface commands list, table 5.
 * 1-Byte Direct Commands and Direct Command Codes, page 20 rev. 4.3 - 2025-10-30.
 */
#define WriteRegister                  0x00
#define WriteRegisterOrMask            0x01
#define WriteRegisterAndMask           0x02
#define WriteRegisterMultiple          0x03
#define ReadRegister                   0x04
#define ReadRegisterMultiple           0x05
#define WriteEEPROM                    0x06
#define ReadEEPROM                     0x07
#define WriteTxData                    0x08
#define SendData                       0x09
#define ReadData                       0x0A
#define SwitchMode                     0x0B
#define MIFAREAuthenticate             0x0C
#define EPCInventory                   0x0D
#define EPCResumeInventory             0x0E
#define EPCRetrieveInventoryResultSize 0x0F
#define EPCRetrieveInventoryResult     0x10
#define LoadRFConfig                   0x11
#define UpdateRFConfig                 0x12
#define RetrieveRFConfigSize           0x13
#define RetrieveRFConfig               0x14
#define RFOn                           0x16
#define RFOff                          0x17

typedef struct {
  uint8_t ui8Code;
  uint8_t ui8CompatFlags;
#ifdef LOG
  const char *abtCommandText;
#endif
} pn5180_command;

#ifndef LOG
#  define PNCMD ( X, Y ) { X , Y }
#  define PNCMD_TRACE do {} while(0)
#else
#  define PNCMD ( X, Y ) { X, Y, #X }
#  define PNCMD_TRACE do { \
    for (size_t i=0; i<sizeof(pn5180_commands)/sizeof(pn5180_command); i++) { \
      if ( X == pn5180_commands[i].ui8Code ) {\
        log_put( LOG_GROUP, LOG_CATEGORY, NFC_LOG_PRIORITY_DEBUG, "%s", pn5180_commands[i].abtCommandText); \
      } \
    } \
  } while(0)
#endif

// static const pn5180_command pn5180_commands[] = {
//   // Host-interface commands
//
// };

// Misc

// RF communication

// Target

// SFR part (?)

// Registers part

/**
 * @note Register addresses:
 * See the PN5180 data sheet, section 11.9.1: Register overview, table 74.
 * Register address overview, page 80 rev. 4.3 - 2025-10-30.
 */
#define SystemConfig       0x00
#define IRQEnable          0x01
#define IRQStatus          0x02
#define IRQClear           0x03
#define TransceiverConfig  0x04
#define PadConfig          0x05
#define Padout             0x07
#define Timer0Status       0x08
#define Timer1Status       0x09
#define Timer2Status       0x0A
#define Timer0Reload       0x0B
#define Timer1Reload       0x0C
#define Timer2Reload       0x0D
#define Timer0Config       0x0E
#define Timer1Config       0x0F
#define Timer2Config       0x10
#define RxWaitConfig       0x11
#define CRCRxConfig        0x12
#define RxStatus           0x13
#define TxUndershootConfig 0x14
#define TxOvershootConfig  0x15
#define TxDataMod          0x16
#define TxWaitConfig       0x17
#define TxConfig           0x18
#define CRCTxConfig        0x19
#define RFStatus           0x1D
#define SystemStatus       0x24
#define TempControl        0x25
#define AGCRefConfig       0x26


/**
 * @note EEPROM addresses (truncated)
 * See the PN5180 data sheet, section 11.5.2: EEPROM, table 51.
 * EEPROM Addresses, page 44 rev. 4.3 - 2025-10-30.
 */
#define DieIdentifer                0x00
#define ProductVersion              0x10
#define FirmwareVersion             0x12
#define EEPROMVersion               0x14
#define IRQPinConfig                0x1A

// Low Power Card Detection (LPCD)
#define LPCD_ReferenceValue         0x34
#define LPCD_FieldOnTime            0x36
#define LPCD_Threshold              0x37
#define LPCD_RefvalGPOControl       0x38
#define LPCD_GPOToggleBeforeFieldOn 0x39
#define LPCD_GPOToggleAfterFieldOff 0x3A

/* PN5180 specific errors (?) */


#endif /* __PN5180_INTERNAL_H__ */
