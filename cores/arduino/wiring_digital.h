/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _WIRING_DIGITAL_
#define _WIRING_DIGITAL_

__BEGIN_DECLS

#define PortValue_t uint32_t
#define PortAddr_t uint32_t
#define PortRegister_t volatile uint32_t *

// #define digitalPinToPort(pin)    ((PortAddr_t)     GPIO_BASE_ADDR)
// #define digitalPinToPortIn(pin)  ((PortAddr_t)     GPIO_BASE_ADDR)
// #define digitalPinToBitMask(pin) ((PortValue_t)    (1<<variant_pin_map[pin].bit_pos))
// #define portOutputRegister(port) ((PortRegister_t) (GPIO_BASE_ADDR + GPIO_OUTPUT_VAL))
// #define portInputRegister(port)  ((PortRegister_t) (GPIO_BASE_ADDR + GPIO_INPUT_VAL))

#define READ_Reg(dir) (*(volatile unsigned *)dir)
#define WRITE_Reg(dir,val) ((*(volatile unsigned *)dir) = (val))

#define GPIO_INPUT (*((volatile unsigned *)(GPIO_BASE_ADDR)))    //// GPIO write
#define GPIO_OUTPUT (*((volatile unsigned *)(GPIO_BASE_ADDR+0x04)))    //// GPIO write  read
#define GPIO_DIR (*((volatile unsigned *)(GPIO_BASE_ADDR+0x08)))    //// GPIO write  Dir  

#define REMAP    0x80004200
#define DIR_REG 0x80004364
#define REMAP_OUT_REG (REMAP)
#define REMAP_IN_REG (REMAP+0x24)


/**
 * \brief Configures the specified pin to behave either as an input or an output. See the description of digital pins for details.
 *
 * \param ulPin The number of the pin whose mode you wish to set
 * \param ulMode Either INPUT or OUTPUT
 */
extern void pinMode( uint32_t dwPin, uint32_t dwMode ) ;

/**
 * \brief Write a HIGH or a LOW value to a digital pin.
 *
 * If the pin has been configured as an OUTPUT with pinMode(), its voltage will be set to the
 * corresponding value: 5V (or 3.3V on 3.3V boards) for HIGH, 0V (ground) for LOW.
 *
 * \note Digital pin PIN_LED is harder to use as a digital input than the other digital pins because it has an LED
 * and resistor attached to it that's soldered to the board on most boards. If you enable its internal 20k pull-up
 * resistor, it will hang at around 1.7 V instead of the expected 5V because the onboard LED and series resistor
 * pull the voltage level down, meaning it always returns LOW. If you must use pin PIN_LED as a digital input, use an
 * external pull down resistor.
 *
 * \param dwPin the pin number
 * \param dwVal HIGH or LOW
 */
extern void digitalWrite( uint32_t dwPin, uint32_t dwVal ) ;

/**
 * \brief Reads the value from a specified digital pin, either HIGH or LOW.
 *
 * \param ulPin The number of the digital pin you want to read (int)
 *
 * \return HIGH or LOW
 */
extern int digitalRead( uint32_t ulPin ) ;

/**
 * \brief Sets a Pin to IOs of Peripheral
 *
 * \param pin_number The pin to remap
 *
 * \param pin_dir The direction of pin is INPUT or OUTPUT
 * 
 * \param peripheral Which peripheral to assign to pin
 * \return HIGH or LOW
 */
extern void Remap(uint8_t pin_number, uint32_t pin_dir, uint8_t peripheral);

__END_DECLS

#endif /* _WIRING_DIGITAL_ */
