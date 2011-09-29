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

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <iostream>

class Vector2
{
public:

	Vector2();
	Vector2( double x, double y );
	Vector2( const Vector2& rhs );
	
	double x() const;
	double y() const;
	
	void normalise();
	Vector2 getNormalised() const;
	
	double dot( const Vector2& rhs ) const;
	
	double length() const;
	
	const Vector2 operator+ ( const Vector2& rhs ) const;
	const Vector2 operator- ( const Vector2& rhs ) const;
	const Vector2 operator- () const;
	const Vector2 operator* ( const Vector2& rhs ) const;
	const Vector2 operator* ( double rhs ) const;
	friend const Vector2 operator* ( double lhs, const Vector2& rhs );
	
	Vector2& operator+= ( const Vector2& rhs );
	Vector2& operator-= ( const Vector2& rhs );
	Vector2& operator*= ( const Vector2& rhs );
	Vector2& operator*= ( double rhs );
	
	bool operator== ( const Vector2& rhs ) const;
	bool operator!= ( const Vector2& rhs ) const;
	
	Vector2& operator= ( const Vector2& rhs );
	
	friend std::ostream& operator<< ( std::ostream& os, const Vector2& rhs );
private:
	static Vector2 X;
	static Vector2 Y;
	
	double m_x;
	double m_y;
};

#endif // _VECTOR2_H_

