# mathlib - A basic foundation maths library 
# Copyright (C) 2011 Kenneth C Andrews
# 
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
# 
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

SET( CMAKE_VERBOSE_MAKEFILE TRUE )

PROJECT( ${PROJECT} )

ADD_DEFINITIONS( -g )

# add Qt4, enabling open gl
SET( QT_USE_QTOPENGL TRUE )
FIND_PACKAGE( Qt4 )

INCLUDE_DIRECTORIES(
	.
	${CMAKE_SOURCE_DIR}/core
	${QT_INCLUDES}
)
