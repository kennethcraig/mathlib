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

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

class Vector3
{
public:
	Vector3();
	Vector3( double x, double y, double z );
	Vector3( const Vector3& rhs );
	
	double x() const;
	double y() const;
	double z() const;
	
	void normalise();
	Vector3 getNormalised() const;
	
	double dot( const Vector3& rhs ) const;
	
	Vector3 cross( const Vector3& rhs ) const;
	
	double length() const;
	
	const Vector3 operator+ ( const Vector3& rhs ) const;
	const Vector3 operator- ( const Vector3& rhs ) const;
	const Vector3 operator* ( const Vector3& rhs ) const;
	const Vector3 operator* ( double rhs ) const;
	
	Vector3& operator+= ( const Vector3& rhs );
	Vector3& operator-= ( const Vector3& rhs );
	Vector3& operator*= ( const Vector3& rhs );
	Vector3& operator*= ( double rhs );
	
	bool operator== ( const Vector3& rhs ) const;
	bool operator!= ( const Vector3& rhs ) const;
	
	Vector3& operator= ( const Vector3& rhs );
		
	friend std::ostream& operator<< ( std::ostream& os, const Vector3& rhs );

	// standard basis vectors, also known as i,j & k respectively.
	static Vector3 X;
	static Vector3 Y;
	static Vector3 Z;
	
private:

	double m_x;
	double m_y;
	double m_z;
};

const Vector3 operator* ( double lhs, const Vector3& rhs );

#endif // _VECTOR3_H_

