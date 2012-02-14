/*
mathlib - A basic foundation maths library 

The following library is hereby released under the CC0 License, a copy of which can be found at 

http://creativecommons.org/publicdomain/zero/1.0/legalcode

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

