#pragma once

#ifdef EEPROM_CUSTOM
// we use EEPROM_CUSTOM
// todo: implement wear leveling

#ifndef EEPROM_PAGE_SIZE
#define EEPROM_PAGE_SIZE  0x100                              // 256bytes
#endif

#ifndef EEPROM_PAGE_COUNT
#define EEPROM_PAGE_COUNT 8                                  // 16pages  
#endif

#define EEPROM_SIZE (EEPROM_PAGE_SIZE * EEPROM_PAGE_COUNT)   // 4k

#ifndef EEPROM_BASE_ADDR 
#define EEPROM_BASE_ADDR 0
#endif

#define EEPROM_END_ADDR (EEPROM_BASE_ADDR + EEPROM_SIZE)

#endif
