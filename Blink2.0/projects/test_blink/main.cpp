
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

/* How to compile:

1. Move to folder Blink2.0/projects/test_blink

2. Compile with (for the PC platform (simulator)):
$ g++ -Wall -oblink.out \
  -I.
  -I../../src \
  main.cpp \
  ../../src/components/Blink/Blink.cpp \
  ../../src/hal/Blink/PC/Led.cpp \
  -DPLATFORM_PC

   Platforms availables for this example:
     PLATFORM_PC
     PLATFORM_ARDUINO

   If you want to compile against the Arduino platform:
$ g++ -Wall -oblink.out \
  -I.
  -I../../src \
  main.cpp \
  ../../src/components/Blink/Blink.cpp \
  ../../src/hal/Blink/Arduino/Led.cpp \
  -DPLATFORM_ARDUINO

3. All paths in this framework are referred to the src/ folder. Your build must
   provide its relative path as in:

               -I../../src

   With this convention you MUST NOT include this folder's path in your
   #includes all this framework long as shown next:

   #include "components/Blink/Blink.hpp"
   #include "hal/Blink/PC/Led.hpp"

4. Namespaces reflect and follow the framework's file structure (excluding the src/ folder).

5. Everything in this framework is inside the fjrg76 namespace.
*/


#ifdef PLATFORM_PC
// components and drivers that compile against the PC platform:
#include "PC/includes.hpp"
#define Led fjrg76::hal::Blink::PC::Led
#endif

#ifdef PLATFORM_ARDUINO
// components and drivers that compile against the Arduino platform (mocked):
#include "Arduino/includes.hpp"
#define Led fjrg76::hal::Blink::Arduino::Led
#endif


int main()
{
//  INITIALIZATION (platform/hardware dependent):

#ifdef PLATFORM_PC
    Led led_pc( 0x1234, 5 );
    fjrg76::components::Blink::Blink led( led_pc );
#endif

#ifdef PLATFORM_ARDUINO
    Led led_arduino( 13 );
    fjrg76::components::Blink::Blink led( led_arduino );
#endif

//  LOGIC (platform/hardware independent):

    led.on();
    led.off();
}