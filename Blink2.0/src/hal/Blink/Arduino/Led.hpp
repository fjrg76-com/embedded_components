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

#pragma once

#include <cstdint>
#include "../IBlinkable.hpp"

namespace fjrg76{
namespace hal{
namespace Blink{
namespace Arduino
{
class Led : public IBlinkable
{
private:
   uint8_t pin;

public:
   Led( uint8_t pin );
   void pin_state( bool new_state ) override;
};
}
}
}
}