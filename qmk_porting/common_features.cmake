# VIA_ENABLE
if(VIA_ENABLE)
    add_definitions(-DVIA_ENABLE -DRAW_ENABLE -DDYNAMIC_KEYMAP_ENABLE)
    set(EEPROM_ENABLE ON CACHE BOOL "QMK" FORCE)
    set(BOOTMAGIC_ENABLE ON CACHE BOOL "QMK" FORCE)
    message(STATUS "VIA_ENABLE")
    list(APPEND quantum_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/quantum/dynamic_keymap.c"
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/quantum/via.c"
    )
endif()

# BOOTMAGIC_ENABLE
if(BOOTMAGIC_ENABLE)
    add_definitions(-DBOOTMAGIC_LITE)
    message(STATUS "BOOTMAGIC_ENABLE")
    list(APPEND quantum_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/quantum/bootmagic/bootmagic_lite.c"
    )
endif()

# EEPROM_ENABLE
if(EEPROM_ENABLE)
    add_definitions(-DEEPROM_ENABLE -DEEPROM_DRIVER)
    message(STATUS "EEPROM_ENABLE")
    message(STATUS "EEPROM_DRIVER = ${EEPROM_DRIVER}")
    list(APPEND quantum_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/drivers/eeprom/eeprom_driver.c"
    )

    if(EEPROM_DRIVER STREQUAL "custom")
        add_definitions(-DEEPROM_CUSTOM)
        list(APPEND QMK_PORTING_SOURCES
            "${CMAKE_CURRENT_LIST_DIR}/platforms/ch58x/eeprom/eeprom_ch58x_custom.c"
        )
    elseif(EEPROM_DRIVER STREQUAL "wear_leveling")
        add_definitions(-DEEPROM_WEAR_LEVELING)
        include_directories(${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/drivers/eeprom)
        list(APPEND QMK_PORTING_SOURCES
            "${CMAKE_CURRENT_LIST_DIR}/platforms/ch58x/eeprom/eeprom_wear_leveling.c"
            "${CMAKE_CURRENT_LIST_DIR}/platforms/ch58x/eeprom/wear_leveling_ch58x.c"
            "${CMAKE_CURRENT_LIST_DIR}/platforms/ch58x/eeprom/wear_leveling.c"
            "${CMAKE_CURRENT_LIST_DIR}/platforms/ch58x/eeprom/fnv/*.c"
        )
    else()
        message(FATAL_ERROR "Unsupported EEprom Driver!")
    endif()
endif()

# WS2812_REQUIRED default
set(WS2812_REQUIRED OFF CACHE BOOL "QMK" FORCE)

# RGBLIGHT_ENABLE
if(RGBLIGHT_ENABLE)
    add_definitions(-DRGBLIGHT_ENABLE -DUSE_CIE1931_CURVE)
    set(WS2812_REQUIRED ON CACHE BOOL "QMK" FORCE)
    message(STATUS "RGBLIGHT_ENABLE")
    list(APPEND quantum_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/quantum/rgblight/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/quantum/color.c"
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/quantum/process_keycode/process_rgb.c"
    )
endif()

# RGB_MATRIX_ENABLE
if(RGB_MATRIX_ENABLE)
    add_definitions(-DRGB_MATRIX_ENABLE -DUSE_CIE1931_CURVE)
    set(WS2812_REQUIRED ON CACHE BOOL "QMK" FORCE)
    message(STATUS "RGBLIGHT_ENABLE")
    include_directories(${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/lib/lib8tion)
    list(APPEND quantum_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/quantum/rgb_matrix/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/quantum/color.c"
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/quantum/process_keycode/process_rgb.c"
        "${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/lib/lib8tion/*.c"
    )
endif()

# WS2812 REQUIRED
if(WS2812_REQUIRED)
    add_definitions(-DWS2812)
    message(STATUS "WS2812_REQUIRED")
    message(STATUS "WS2812_DRIVER = ${WS2812_DRIVER}")

    if(WS2812_DRIVER STREQUAL "spi")
        add_definitions(-DWS2812_DRIVER_SPI)
        list(APPEND QMK_PORTING_SOURCES
            "${CMAKE_CURRENT_LIST_DIR}/drivers/ws2812/ws2812_spi.c"
        )
    elseif(WS2812_DRIVER STREQUAL "pwm")
        add_definitions(-DWS2812_DRIVER_PWM)
        include_directories(${CMAKE_CURRENT_LIST_DIR}/../qmk_firmware/drivers/eeprom)
        list(APPEND QMK_PORTING_SOURCES
            "${CMAKE_CURRENT_LIST_DIR}/drivers/ws2812/ws2812_pwm.c"
        )
    else()
        message(FATAL_ERROR "Unsupported WS2812 Driver!")
    endif()
endif()