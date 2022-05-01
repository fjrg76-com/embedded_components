/* Copyright (C)
 * 2022 - fjrg76 at hotmail dot com
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */


#include <iostream> // <- For debugging purposes

// #include <Arduino.h> // <- For the real platform


#include "Led.hpp"

using namespace fjrg76::hal::Blink::Arduino;

Led::Led( uint8_t pin ) 
    : pin{pin}
{
    std::cout << "LedArduino::LedArduino()\n";

    // pinMode( this->pin, OUTPUT ); // <- For the real platform
}

void Led::pin_state( bool new_state )
{
    std::cout << (new_state == false ? "LedArduino::OFF" : "LedArduino::ON") << std::endl;

    // digitalWrite( this->pin, new_state ); // <- For the real platform
}
