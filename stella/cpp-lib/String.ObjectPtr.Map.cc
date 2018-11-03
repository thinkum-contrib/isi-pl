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

#ifdef __GNUG__
#pragma implementation
#endif
// Modified -erm
#include "hashfns.hh"
#include "String.ObjectPtr.Map.hh"
// Added -erm
#include <iostream.h>

Pix StringObjectPtrMap::seek(String  item)
{
  for (Pix i = first(); i != 0 && !(StringEQ(key(i), item)); next(i));
  return i;
}

int StringObjectPtrMap::owns(Pix idx)
{
  if (idx == 0) return 0;
  for (Pix i = first(); i; next(i)) if (i == idx) return 1;
  return 0;
}

void StringObjectPtrMap::clear()
{
  Pix i = first(); 
  while (i != 0)
  {
    del(key(i));
    i = first();
  }
}

int StringObjectPtrMap::contains (String  item)
{
  return seek(item) != 0;
}


void StringObjectPtrMap::error(const char* msg)
{
  // Modified -erm
  cerr << "Map error: " << msg << endl;
  //  (*lib_error_handler)("Map", msg);
}

