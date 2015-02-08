/*
 * keyboard.cpp
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


#include "Keyboard.hpp"

#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <algorithm>

using namespace Graphics;

const char* Keyboard::DEFAULT_DEVICE = "/dev/input/event0";

Keyboard::Keyboard(const char* device)
{
	size_t deviceLength = strnlen(device, 24);
	
	this->device = new char[deviceLength];
	
	std::copy(device, device + deviceLength, this->device);
	
	memset(event, 0, sizeof(event));
	
	initKeyboard();
}

Keyboard::~Keyboard() {
	delete device;
	
	close(fd);
}

int Keyboard::getPressedKeyCode() const {
	::read(fd, (void*)event, sizeof(event));
	
	int ret;
	if(event[0].value != ' ' &&
		event[1].value == 1 &&
		event[1].type == 1)
	{
		ret = event[1].code;
	} else {
		ret = -1;
	}
	
	return ret;
}

void Keyboard::initKeyboard() {
	if(device != null) {
		fd = open(device, O_RDONLY | O_NONBLOCK);
		if(fd == -1) {
			perror("Cannot initialize keyboard device");
			exit(1);
		} else {
			printf("Keyboard initialized. Device: %s\n", device);
		}
	} else {
		printf("Keyboard device undefined\n");
		exit(1);
	}
}
