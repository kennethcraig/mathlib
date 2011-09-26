/*
mathlib - A basic foundation maths library 
Copyright (C) 2011 Kenneth C Andrews

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <iostream>
#include <vector2.h>
#include <vector3.h>

#define TEST(a,b) \
	if( a != b ) { \
		std::cout << "Test Failed: " << #a " == " #b << ", expected: " << b << ", got " << a; \
		std::cout << " - " << __FILE__ << ":" << __LINE__ << std::endl; \
		return 1; \
	} \
	else\
	{\
		std::cout << "Passed" << std::endl;\
	}
	

int main()
{
	TEST( Vector3(1,2,3), Vector3(1,2,3) );
	TEST( Vector3(1,2,3) + Vector3(1,2,3), Vector3(2,4,6) );
	
	TEST(  2 * Vector3(1,1,1), Vector3(2,2,2));
	TEST( Vector3(1,1,1) * 2, Vector3(2,2,2));
	
	Vector3 test = Vector3::X.cross(Vector3::Y);
	TEST(test, Vector3::Z);
	return 0;
}
