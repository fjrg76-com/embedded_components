/*Copyright (C) 
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


//----------------------------------------------------------------------
// Interface: 
//----------------------------------------------------------------------
struct IBlinkable
{
   virtual void pin_state( bool new_state ) = 0; 
};


//----------------------------------------------------------------------
//  Implementation for mocked LED (PC simulation):
//----------------------------------------------------------------------
#ifdef PC_PLATFORM
#include <cstdint>
#include <iostream>

class LedPC : public IBlinkable
{
private:
   uint32_t port; // hardware port (placeholder)
   uint8_t pin;   // hardware pin (placeholder)

public:
   LedPC( uint32_t port, uint8_t pin ) : port{port}, pin{pin}
   {
      std::cout << "LedPC::LedPC()\n";
   }


   void pin_state( bool new_state ) override
   {
      std::cout << (new_state == false ? "LedPC::OFF" : "LedPC::ON") << std::endl;
   }
};
#endif


//----------------------------------------------------------------------
//  Implementation for an on-board LED:
//----------------------------------------------------------------------
#ifdef LEDONBOARD_PLATFORM
#include <cstdint>
#include <iostream> // for debugging purposes

class LedOnBoard : public IBlinkable
{
private:
   uint8_t pin; // maybe it is an Arduino implementation

public:
   LedOnBoard( uint8_t pin ) : pin{pin}
   {
      std::cout << "LedOnBoard::LedOnBoard()\n";
   }


   void pin_state( bool new_state ) override
   {
      std::cout << (new_state == false ? "LedOnBoard::OFF" : "LedOnBoard::ON") << std::endl;

      // On Arduino:
      //
      // digitalWrite( this->pin, new_state );
   }
};
#endif


//----------------------------------------------------------------------
//  Implementation for a LED on a I2C gpio xpander chip:
//----------------------------------------------------------------------
#ifdef LEDXPANDER_PLATFORM
#include <cstdint>
#include <iostream> // for debugging purposes

const uint8_t bit_mask[8] = {1,2,4,8,16,32,64,128};

class LedXpander : public IBlinkable
{
private:
   uint8_t i2c_address; // xpander I2C address
   uint8_t pin;         // 0-7

public:
   LedXpander( uint8_t i2c_address, uint8_t pin ) : i2c_address{i2c_address}, pin{pin}
   {
      std::cout << "LedXpander::LedXpander()\n";
   }


   void pin_state( bool new_state ) override
   {
      std::cout << (new_state == false ? "LedXpander::OFF" : "LedXpander::ON") << std::endl;

      // On a generic board:
      //
      // port_val = i2c_read( this->address );
      // port_val = new_state==false ? 
      //               port_val & ~bit_mask[this->pin] :
      //               port_val | bit_mask[this->pin];
      // i2c_write( this->address, port_val );
   }
};
#endif



//----------------------------------------------------------------------
// Controller (hardware independent): 
//----------------------------------------------------------------------
class Blink
{
private:
   IBlinkable& gpio;

public:
   Blink( IBlinkable& new_gpio ) : gpio{new_gpio}
   {

   }

   void on()
   {
      gpio.pin_state( true );
   }

   void off()
   {
      gpio.pin_state( false );
   }
};



//----------------------------------------------------------------------
// Client: 
//----------------------------------------------------------------------
int main()
{

#ifdef PC_PLATFORM
   LedPC led_pc( 0x1234, // port
                 10 );   // pin

   Blink led( led_pc );
#endif

#ifdef LEDONBOARD_PLATFORM

   LedOnBoard led_on_board( 13 );

   Blink led( led_on_board );
#endif

#ifdef LEDXPANDER_PLATFORM
   LedXpander led_xpander( 0x20, // 7 bit i2c address
                           3 );  // pin on the xpander chip

   Blink led( led_xpander );
#endif  


   led.on();
   led.off();
}
