// main.cc
// Main routine for testing Stella

#include "stella-includes.hh"


void dprint (Object* o)
  // Print routine for debugging.
{
  o->print_object(&cout);
  cout << endl;
}

main () {

  hello_world("Hi there!!");

  startup(TRUE);       // Run all Stella initializations

  hello_world("Hi there again!!");

  cout << "bye!" << endl;
}
