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


#ifndef _StringObjectPtrMap_h
#ifdef __GNUG__
#pragma interface
#endif
#define _StringObjectPtrMap_h 1

// Modified -erm
#include "Pix.hh"
#include "String.defs.hh"
// Added
#include "ObjectPtr.defs.hh"

class StringObjectPtrMap
{
protected:
  int                   count;
  ObjectPtr                   def;

public:
                        StringObjectPtrMap(ObjectPtr  dflt);
  virtual              ~StringObjectPtrMap();

  int                   length() const; // current number of items
  int                   empty() const;

  virtual int           contains(String  key);      // is key mapped?

  virtual void          clear();                 // delete all items

  virtual ObjectPtr&          operator [] (String  key) = 0; // access contents by key

  virtual void          del(String  key) = 0;       // delete entry

  virtual Pix           first() = 0;             // Pix of first item or 0
  virtual void          next(Pix& i) = 0;        // advance to next or 0
  virtual String&          key(Pix i) = 0;          // access key at i
  virtual ObjectPtr&          contents(Pix i) = 0;     // access contents at i

  virtual int           owns(Pix i);             // is i a valid Pix  ?
  virtual Pix           seek(String  key);          // Pix of key

  ObjectPtr&                  dflt();                  // access default val

  void                  error(const char* msg);
  virtual int           OK() = 0;                // rep invariant
};


inline StringObjectPtrMap::~StringObjectPtrMap() {}

inline int StringObjectPtrMap::length() const
{
  return count;
}

inline int StringObjectPtrMap::empty() const
{
  return count == 0;
}

inline ObjectPtr& StringObjectPtrMap::dflt()
{
  return def;
}

inline StringObjectPtrMap::StringObjectPtrMap(ObjectPtr  dflt) :def(dflt)
{
  count = 0;
}

#endif
