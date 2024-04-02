// See LICENSE for license details.

#ifndef _strive_PLATFORM_H
#define _strive_PLATFORM_H

//Enable Remapable IOS
//#define REMAP_ENABLED

// Some things missing from the official encoding.h
#define MCAUSE_INT         0x80000000
#define MCAUSE_CAUSE       0x7FFFFFFF

#include "strive/const.h"
#include "strive/devices/aon.h"
#include "strive/devices/clint.h"
#include "strive/devices/gpio.h"
#include "strive/devices/plic.h"
#include "strive/devices/pwm.h"
#include "strive/devices/spi.h"
#include "strive/devices/uart.h"
#include "strive/devices/remap.h"

/****************************************************************************
 * Platform definitions
 *****************************************************************************/

#define TRAPVEC_TABLE_BASE_ADDR _AC(0x00001010,UL)
#define CLINT_BASE_ADDR _AC(0x02000000,UL)
#define PLIC_BASE_ADDR _AC(0x0C000000,UL)
#define AON_BASE_ADDR _AC(0x10000000,UL)
#define GPIO_BASE_ADDR _AC(0x80001400,UL)

#define SPI0_BASE_ADDR _AC(0x80001040,UL)
#define PWM0_BASE_ADDR _AC(0x80001200,UL)

#define SPI1_BASE_ADDR _AC(0x80001100,UL)
#define PWM1_BASE_ADDR _AC(0x80001240,UL)
#define SPI2_BASE_ADDR _AC(0x10034000,UL)
#define PWM2_BASE_ADDR _AC(0x80001280,UL)
#define SPI0_MMAP_ADDR _AC(0x20000000,UL)
#define MEM_BASE_ADDR _AC(0x80000000,UL)
#define PWM3_BASE_ADDR _AC(0x800012c0,UL)
#define PWM4_BASE_ADDR _AC(0x80004600,UL)
#define PWM5_BASE_ADDR _AC(0x80004800,UL)
#define I2C_BASE_ADDR  _AC(0x80001800,UL)
#define TIMER_BASE_ADDR _AC(0x80001800,UL)
#define EXT_TIMER_BASE_ADDR  _AC(0x80001300,UL)
#define OUT_COMP_BASE_ADDR  _AC(0x80004600,UL)

#define UART0_BASE_ADDR _AC(0x80002000,UL)
#define UART1_BASE_ADDR _AC(0x80003000,UL)
#define UART2_BASE_ADDR _AC(0x80004000,UL)
#define UART3_BASE_ADDR _AC(0x80005000,UL)
#define UART4_BASE_ADDR _AC(0x80006000,UL)



// IOF Mappings
#define IOF0_SPI1_MASK          _AC(0x000007FC,UL)
#define SPI11_NUM_SS     (4)
#define IOF_SPI1_SS0          (2u)
#define IOF_SPI1_SS1          (8u)
#define IOF_SPI1_SS2          (9u)
#define IOF_SPI1_SS3          (10u)
#define IOF_SPI1_MOSI         (3u)
#define IOF_SPI1_MISO         (4u)
#define IOF_SPI1_SCK          (5u)
#define IOF_SPI1_DQ0          (3u)
#define IOF_SPI1_DQ1          (4u)
#define IOF_SPI1_DQ2          (6u)
#define IOF_SPI1_DQ3          (7u)

#define IOF0_SPI2_MASK          _AC(0xFC000000,UL)
#define SPI2_NUM_SS       (1)
#define IOF_SPI2_SS0          (26u)
#define IOF_SPI2_MOSI         (27u)
#define IOF_SPI2_MISO         (28u)
#define IOF_SPI2_SCK          (29u)
#define IOF_SPI2_DQ0          (27u)
#define IOF_SPI2_DQ1          (28u)
#define IOF_SPI2_DQ2          (30u)
#define IOF_SPI2_DQ3          (31u)

#define IOF0_UART0_MASK         _AC(0x00030000, UL)
#define IOF_UART0_RX   (16u)
#define IOF_UART0_TX   (17u)

#define IOF0_UART1_MASK         _AC(0x03000000, UL)
#define IOF_UART1_RX (24u)
#define IOF_UART1_TX (25u)

#define IOF1_PWM0_MASK          _AC(0x0000000F, UL)
#define IOF1_PWM1_MASK          _AC(0x00780000, UL)
#define IOF1_PWM2_MASK          _AC(0x00003C00, UL)

// Interrupt Numbers
#define INT_RESERVED 0
#define INT_WDOGCMP 1
#define INT_RTCCMP 2
#define INT_UART0_BASE 3
#define INT_UART1_BASE 4
#define INT_SPI0_BASE 5
#define INT_SPI1_BASE 6
#define INT_SPI2_BASE 7
#define INT_GPIO_BASE 8
#define INT_PWM0_BASE 40
#define INT_PWM1_BASE 44
#define INT_PWM2_BASE 48

// Helper functions
#define _REG32(p, i) (*(volatile uint32_t *) ((p) + (i)))
#define _REG32P(p, i) ((volatile uint32_t *) ((p) + (i)))
#define AON_REG(offset) _REG32(AON_BASE_ADDR, offset)
#define CLINT_REG(offset) _REG32(CLINT_BASE_ADDR, offset)
#define GPIO_REG(offset) _REG32(GPIO_BASE_ADDR, offset)
#define OTP_REG(offset)  _REG32(OTP_BASE_ADDR, offset)
#define PLIC_REG(offset) _REG32(PLIC_BASE_ADDR, offset)
#define PRCI_REG(offset) _REG32(PRCI_BASE_ADDR, offset)
#define PWM0_REG(offset) _REG32(PWM0_BASE_ADDR, offset)
#define PWM1_REG(offset) _REG32(PWM1_BASE_ADDR, offset)
#define PWM2_REG(offset) _REG32(PWM2_BASE_ADDR, offset)
#define SPI0_REG(offset) _REG32(SPI0_BASE_ADDR, offset)
#define SPI1_REG(offset) _REG32(SPI1_BASE_ADDR, offset)
#define SPI2_REG(offset) _REG32(SPI2_BASE_ADDR, offset)
#define UART0_REG(offset) _REG32(UART0_BASE_ADDR, offset)
#define UART1_REG(offset) _REG32(UART1_BASE_ADDR, offset)

// Misc

#include <stdint.h>


#define NUM_GPIO 20

#define PLIC_NUM_INTERRUPTS 52
#define PLIC_NUM_PRIORITIES 7

#define HAS_BOARD_BUTTONS
#include "hifive1.h"

unsigned long get_timer_freq(void);
uint64_t get_timer_value(void);

#endif /* _strive_PLATFORM_H */
