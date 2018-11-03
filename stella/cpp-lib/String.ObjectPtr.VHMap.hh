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


#ifndef _StringObjectPtrVHMap_h
#ifdef __GNUG__
#pragma interface
#endif
#define _StringObjectPtrVHMap_h 1

#include "String.ObjectPtr.Map.hh"


class StringObjectPtrVHMap : public StringObjectPtrMap
{
protected:
  String*           tab;
  ObjectPtr*           cont;
  char*          status;
  unsigned int   size;

public:
                StringObjectPtrVHMap(ObjectPtr  dflt,unsigned int sz=DEFAULT_INITIAL_CAPACITY);
                StringObjectPtrVHMap(StringObjectPtrVHMap& a);
                ~StringObjectPtrVHMap();

  ObjectPtr&          operator [] (String  key);

  void          del(String  key);

  Pix           first();
  void          next(Pix& i);
  String&          key(Pix i);
  ObjectPtr&          contents(Pix i);

  Pix           seek(String  key);
  int           contains(String  key);

  void          clear(); 
  void          resize(unsigned int newsize = 0);

  int           OK();
};

inline StringObjectPtrVHMap::~StringObjectPtrVHMap()
{
  delete [] tab;
  delete [] cont;
  delete [] status;
}

inline int StringObjectPtrVHMap::contains(String  key)
{
  return seek(key) != 0;
}

inline String& StringObjectPtrVHMap::key(Pix i)
{
  if (i == 0) error("null Pix");
  return *((String*)i);
}

inline ObjectPtr& StringObjectPtrVHMap::contents(Pix i)
{
  if (i == 0) error("null Pix");
  return cont[((unsigned)(i) - (unsigned)(tab)) / sizeof(String)];
}

#endif
