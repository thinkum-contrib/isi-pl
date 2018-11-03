// This may look like C code, but it is really -*- C++ -*-
/* 
Copyright (C) 1988 Free Software Foundation
    written by Doug Lea (dl@rocky.oswego.edu)

This file is part of the GNU C++ Library.  This library is free
software; you can redistribute it and/or modify it under the terms of
the GNU Library General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your
option) any later version.  This library is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU Library General Public License for more details.
You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the Free Software
Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
*/


#ifndef _StringintVHMap_h
#ifdef __GNUG__
#pragma interface
#endif
#define _StringintVHMap_h 1

#include "String.int.Map.hh"


class StringintVHMap : public StringintMap
{
protected:
  String*           tab;
  int*           cont;
  char*          status;
  unsigned int   size;

public:
                StringintVHMap(int  dflt,unsigned int sz=DEFAULT_INITIAL_CAPACITY);
                StringintVHMap(StringintVHMap& a);
                ~StringintVHMap();

  int&          operator [] (String& key);

  void          del(String& key);

  Pix           first();
  void          next(Pix& i);
  String&          key(Pix i);
  int&          contents(Pix i);

  Pix           seek(String& key);
  int           contains(String& key);

  void          clear(); 
  void          resize(unsigned int newsize = 0);

  int           OK();
};

inline StringintVHMap::~StringintVHMap()
{
  delete [] tab;
  delete [] cont;
  delete [] status;
}

inline int StringintVHMap::contains(String& key)
{
  return seek(key) != 0;
}

inline String& StringintVHMap::key(Pix i)
{
  if (i == 0) error("null Pix");
  return *((String*)i);
}

inline int& StringintVHMap::contents(Pix i)
{
  if (i == 0) error("null Pix");
  return cont[((unsigned)(i) - (unsigned)(tab)) / sizeof(String)];
}

#endif
