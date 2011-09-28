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

#include <cmath>

#include <iostream>
#include <vector2.h>
#include <vector3.h>

#define TEST(a,b) \
	if( a != b ) { \
		std::cout << "Test Failed: " << #a " == " #b << ", expected: " << (b) << ", got " << (a) \
			<< " - " << __FILE__ << ":" << __LINE__ << std::endl; \
		return 1; \
	} \
	else\
	{\
		std::cout << "Passed" << std::endl;\
	}
	

int testVector2()
{
	std::cout << "Testing Vector2" << std::endl;

	// empty constructor, and implicitly, ==
	TEST( Vector2(), Vector2(0,0) );
	
	// constructor, and implicitly, operator==
	TEST( Vector2(1,2), Vector2(1,2) );
	
	// Accessors
	TEST( Vector2(1,2).x(), 1 );
	TEST( Vector2(1,2).y(), 2 );
	
	// Assignment
	Vector2 a(1,2);
	Vector2 b = a;
	TEST( b, a );
	
	// Normalise
	Vector2 test(2,0);
	test.normalise();
	TEST( test, Vector2(1,0) );
	
	test = Vector2(0,2);
	test.normalise();
	TEST( test, Vector2(0,1) );
	
	// dot
	TEST( Vector2(1,0).dot( Vector2(0,1) ), 0 );
	TEST( Vector2(-1,0).dot( Vector2(-1,0) ), 1 );
	
	TEST( Vector2(1,0).dot( Vector2(0,1) ), 0 );
	TEST( Vector2(1,0).dot( Vector2(-1,0) ), -1 );
	
	TEST( Vector2(0,1).dot( Vector2(0,0) ), 0 );
	TEST( Vector2(0,1).dot( Vector2(0,-1) ), -1 );

	// length
	TEST(Vector2( 1,0).length(), 1 );
	TEST(Vector2( 0,1).length(), 1 );
	
	TEST( Vector2(1,1).length(), sqrt(2) );
	
	
	// operators
	TEST( Vector2( 1,2 ) + Vector2( 1,2), Vector2( 2,4 ) );
	TEST( Vector2( -1,-2 ) + Vector2( 1,2), Vector2( 0,0) );
	
	TEST( Vector2( 1,2 ) - Vector2( 1,2), Vector2( 0,0 ) );
	TEST( Vector2( -1,-2 ) - Vector2( 1,2), Vector2( -2,-4 ) );
	
	// Operator -()
	TEST( -Vector2( 1,2 ), Vector2( -1, -2 ) );
	
	TEST( Vector2(1,2) * 2, Vector2(2,4) );	
	
	TEST( Vector2(2,2) * Vector2(2,2), Vector2(4,4 ));
	TEST( Vector2(1,2) * Vector2(1,2), Vector2(1,4 ));
	
	
	test = Vector2(1,2);
	test += Vector2( 1,2);
	TEST( test, Vector2(2,4) );
	
	test -= Vector2(1,2);
	TEST( test, Vector2(1,2) );
	
	test *= Vector2(1,2);
	TEST( test, Vector2(1,4) );
	
	test *= 2;
	TEST( test, Vector2(2,8) );
	
	TEST(  2 * Vector2(1,1), Vector2(2,2) );
	
	TEST(Vector2(1,2) != Vector2(0,2), true );
	TEST(Vector2(1,2) != Vector2(1,0), true );

	return 0;
}

int testVector3()
{
	std::cout << "Testing Vector3" << std::endl;

	// empty constructor, and implicitly, ==
	TEST( Vector3(), Vector3(0,0,0) );
	
	// constructor, and implicitly, operator==
	TEST( Vector3(1,2,3), Vector3(1,2,3) );
	
	// Accessors
	TEST( Vector3(1,2,3).x(), 1 );
	TEST( Vector3(1,2,3).y(), 2 );
	TEST( Vector3(1,2,3).z(), 3 );
	
	// Assignment
	Vector3 a(1,2,3);
	Vector3 b = a;
	TEST( b, a );
	
	// Normalise
	Vector3 test(2,0,0);
	test.normalise();
	TEST( test, Vector3(1,0,0) );
	
	test = Vector3(0,2,0);
	test.normalise();
	TEST( test, Vector3(0,1,0) );
	
	test = Vector3(0,0,2);
	test.normalise();
	TEST( test, Vector3(0,0,1) );
	
	// dot
	TEST( Vector3(1,0,0).dot( Vector3(0,1,0) ), 0 );
	TEST( Vector3(-1,0,0).dot( Vector3(-1,0,0) ), 1 );
	
	TEST( Vector3(1,0,0).dot( Vector3(0,1,0) ), 0 );
	TEST( Vector3(1,0,0).dot( Vector3(-1,0,0) ), -1 );
	
	TEST( Vector3(0,1,0).dot( Vector3(0,0,1) ), 0 );
	TEST( Vector3(0,1,0).dot( Vector3(0,-1,0) ), -1 );
	
	TEST( Vector3(1,1,0).dot( Vector3(0,0,1) ), 0 );
	TEST( Vector3(0,0,1).dot( Vector3(0,0,-1) ), -1 );
	
	// Cross
	test = Vector3::X.cross(Vector3::Y);
	TEST(test, Vector3::Z);
	
	test = Vector3::Z.cross(Vector3::X);
	TEST(test, Vector3::Y);
	
	test = Vector3::Y.cross(Vector3::Z);
	TEST(test, Vector3::X);
	
	// length
	TEST(Vector3( 1,0,0).length(), 1 );
	TEST(Vector3( 0,1,0).length(), 1 );
	TEST(Vector3( 0,0,1).length(), 1 );
	
	TEST( Vector3(1,1,1).length(), sqrt(3) );
	
	
	// operators
	TEST( Vector3( 1,2,3 ) + Vector3( 1,2,3), Vector3( 2,4,6 ) );
	TEST( Vector3( -1,-2,-3 ) + Vector3( 1,2,3), Vector3( 0,0,0 ) );
	
	TEST( Vector3( 1,2,3 ) - Vector3( 1,2,3), Vector3( 0,0,0 ) );
	TEST( Vector3( -1,-2,-3 ) - Vector3( 1,2,3), Vector3( -2,-4,-6 ) );
	
	// Operator -()
	TEST( -Vector3( 1,2,3 ), Vector3( -1, -2, -3 ) );
	
	TEST( Vector3(1,1,1) * 2, Vector3(2,2,2) );	
	
	TEST( Vector3(2,2,2) * Vector3(2,2,2), Vector3(4,4,4 ));
	TEST( Vector3(1,2,3) * Vector3(1,2,3), Vector3(1,4,9 ));
	
	
	test = Vector3(1,2,3);
	test += Vector3( 1,2,3);
	TEST( test, Vector3(2,4,6) );
	
	test -= Vector3(1,2,3);
	TEST( test, Vector3(1,2,3) );
	
	test *= Vector3(1,2,3);
	TEST( test, Vector3(1,4,9) );
	
	test *= 2;
	TEST( test, Vector3(2,8,18) );
	
	TEST(  2 * Vector3(1,1,1), Vector3(2,2,2) );
	
	TEST(Vector3(1,2,3) != Vector3(0,2,3), true );
	TEST(Vector3(1,2,3) != Vector3(1,0,3), true );
	TEST(Vector3(1,2,3) != Vector3(1,2,0), true );

	return 0;
}

int main()
{
	if( testVector2() != 0 )
	{
		return 1;
	}
	
	if( testVector3() != 0 )
	{
		return 1;
	}
	
	return 0;
}

