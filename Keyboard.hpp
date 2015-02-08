/*
 * keyboard.hpp
 * 
 * Copyright 2015 Alvin Natawiguna <alvin.nt.gg@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "Types.hpp"

namespace Graphics {
	class Keyboard
	{
	private:
		static const char* DEFAULT_DEVICE;
		
		int fd;
		char *device;
	public:
		// handles the input event
		// made public, since there's still no idea about how this works
		// e.g., why the size must be struct input_event[64]?
		KeyboardEvent event;
		
		const static int NO_INPUT = -1;
	public:
		Keyboard(const char* device = DEFAULT_DEVICE);
		virtual ~Keyboard();		
		
		/**
		 * Gets the code pressed by the keyboard
		 * 
		 * @return key code when input is detected, else -1
		 */
		int getPressedKeyCode() const;
	private:
		void initKeyboard();
	};
}
#endif /* KEYBOARD_H_ */ 
