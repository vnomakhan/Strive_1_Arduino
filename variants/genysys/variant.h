
#ifndef _VARIANT_FREEDOM_E300_
#define _VARIANT_FREEDOM_E300_


#include <stdint.h>

#define SIFIVE_FREEDOM_E300_PLATFORM
#define FREEDOM_E300
#define RISCV
#include "platform.h"


/*----------------------------------------------------------------------------
*        Headers
*----------------------------------------------------------------------------*/

#include "Arduino.h"
#ifdef __cplusplus
#include "HardwareSerial.h"
#endif


/* LEDs */
#define PIN_LED_13          13
#define PIN_LED             3
#define LED_BUILTIN         3

#ifdef __cplusplus
// extern UARTClass Serial;
// extern UARTClass Serial1;
extern HardwareSerial Serial;
extern HardwareSerial Serial1;
extern HardwareSerial Serial2;
extern HardwareSerial Serial3;
extern HardwareSerial Serial4;

#endif

/*
 * SPI Interfaces
 */

#define SPI_INTERFACES_COUNT 1
#define SPI_REG(x) SPI1_REG(x)

#define UART_INTERFACES_COUNT 2
#define UART_REG(x) UART0_REG(x)
#define UART_REGP(i) _REG32P(UART0_BASE_ADDR, (i))

// we only want to enable 3 peripheral managed SPI pins: SCK, MOSI, MISO
// CS pins can either be handled by hardware or bit banged as GPIOs

static const uint8_t SS   = PIN_SPI1_SS0;
static const uint8_t SS1  = PIN_SPI1_SS1;
static const uint8_t SS2  = PIN_SPI1_SS2;
static const uint8_t SS3  = PIN_SPI1_SS3;
static const uint8_t MOSI = PIN_SPI1_MOSI;
static const uint8_t MISO = PIN_SPI1_MISO;
static const uint8_t SCK  = PIN_SPI1_SCK;

static const uint32_t SPI_IOF_MASK = (1 << IOF_SPI1_SCK) | (1 << IOF_SPI1_MOSI) | (1 << IOF_SPI1_MISO);
static const uint32_t IOF_UART_MASK = IOF0_UART0_MASK;

#define VARIANT_DIGITAL_PIN_MAP  {{.io_port = 0, .bit_pos = 1, .pwm_num = 0, .pwm_cmp_num = PWM_P_PTC1}, \
	{.io_port = 0, .bit_pos = 2, .pwm_num = 1, .pwm_cmp_num = PWM_P_PTC2}, \
	{.io_port = 0, .bit_pos = 3, .pwm_num = 2, .pwm_cmp_num = PWM_P_PTC3}, \
	{.io_port = 0, .bit_pos = 4, .pwm_num = 3,  .pwm_cmp_num = PWM_P_PTC4}, \
	{.io_port = 0, .bit_pos = 5, .pwm_num = 4,  .pwm_cmp_num = PWM1}, \
	{.io_port = 0, .bit_pos = 6, .pwm_num = 5,  .pwm_cmp_num = PWM2}, \
	{.io_port = 0, .bit_pos = 7, .pwm_num = 0,  .pwm_cmp_num = PWM_P_PTC1}, \
	{.io_port = 0, .bit_pos = 8, .pwm_num = 1, .pwm_cmp_num = PWM_P_PTC2}, \
	{.io_port = 0, .bit_pos = 9, .pwm_num = 2,  .pwm_cmp_num = PWM_P_PTC3}, \
	{.io_port = 0, .bit_pos = 10,  .pwm_num = 3,  .pwm_cmp_num = PWM_P_PTC4}, \
	{.io_port = 0, .bit_pos = 11,  .pwm_num = 4,  .pwm_cmp_num = PWM1}, \
	{.io_port = 0, .bit_pos = 12,  .pwm_num = 5, .pwm_cmp_num  = PWM2}, \
	{.io_port = 0, .bit_pos = 13,  .pwm_num = 0, .pwm_cmp_num = PWM_P_PTC1}, \
	{.io_port = 0, .bit_pos = 14,  .pwm_num = 0xFF, .pwm_cmp_num = 0}, \
	{.io_port = 0, .bit_pos = 15,  .pwm_num = 0xFF, .pwm_cmp_num = 0}, \
	{.io_port = 0, .bit_pos = 16,  .pwm_num = 0xFF, .pwm_cmp_num = 0}, \
	{.io_port = 0, .bit_pos = 17,  .pwm_num = 0xFF,   .pwm_cmp_num = 0}, \
	{.io_port = 0, .bit_pos = 18,  .pwm_num = 0xFF,   .pwm_cmp_num = 0}, \
	{.io_port = 0, .bit_pos = 19,  .pwm_num = 0xFF,   .pwm_cmp_num = 0}, \
	{.io_port = 0, .bit_pos = 20,  .pwm_num = 0xFF,  .pwm_cmp_num = 0}, \
	{.io_port = 0, .bit_pos = 21,  .pwm_num = 0xFF,  .pwm_cmp_num = 0}, \
	{.io_port = 0, .bit_pos = 22,  .pwm_num = 0xFF, .pwm_cmp_num  = 0}, \
	{.io_port = 0, .bit_pos = 23,  .pwm_num = 0xFF, .pwm_cmp_num = 0}, \
	{.io_port = 0, .bit_pos = 24,  .pwm_num = 0xFF, .pwm_cmp_num = 0}, \
	{.io_port = 0, .bit_pos = 14,  .pwm_num = 1, .pwm_cmp_num = PWM_P_PTC2}, \
	{.io_port = 0, .bit_pos = 15,  .pwm_num = 2, .pwm_cmp_num = PWM_P_PTC3}, \
	{.io_port = 0, .bit_pos = 16,  .pwm_num = 3,   .pwm_cmp_num = PWM_P_PTC4}, \
	{.io_port = 0, .bit_pos = 17,  .pwm_num = 4,   .pwm_cmp_num = PWM1}, \
	{.io_port = 0, .bit_pos = 18,  .pwm_num = 5,   .pwm_cmp_num = PWM2}, \
	{.io_port = 0, .bit_pos = 19,  .pwm_num = 0,   .pwm_cmp_num = PWM_P_PTC1}, \
	{.io_port = 0, .bit_pos = 20,  .pwm_num = 1,   .pwm_cmp_num = PWM_P_PTC2}}

#define VARIANT_NUM_PIN (32)

#define VARIANT_PWM_LIST {(volatile void *) PWM0_BASE_ADDR, \
      (volatile void *) PWM1_BASE_ADDR, \
	  (volatile void *) PWM2_BASE_ADDR, \
	  (volatile void *) PWM3_BASE_ADDR, \
	  (volatile void *) PWM4_BASE_ADDR, \
      (volatile void *) PWM5_BASE_ADDR}

#define VARIANT_NUM_PWM (6)
#define VARIANT_NUM_SPI (1)
// For interfacing with the onboard SPI Flash.
#define VARIANT_NUM_QSPI (1)
#define VARIANT_NUM_UART (1)

#endif 
