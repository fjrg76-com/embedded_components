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

#include "Blink.hpp"

using namespace fjrg76::components::Blink;

Blink::Blink( fjrg76::hal::Blink::IBlinkable& new_gpio ) 
    : gpio{new_gpio}
{

}

void Blink::on()
{
    gpio.pin_state( true );
}

void Blink::off()
{
    gpio.pin_state( false );
}
