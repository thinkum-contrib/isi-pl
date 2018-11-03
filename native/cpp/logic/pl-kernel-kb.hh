//  -*- Mode: C++ -*-

// pl-kernel-kb.hh

/*
 +--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2003              |
 |  University of Southern California, Information Sciences Institute       |
 |  4676 Admiralty Way                                                      |
 |  Marina Del Rey, California 90292                                        |
 |                                                                          |
 |  This software was developed under the terms and conditions of Contract  |
 |  No. N00014-94-C-0245 between the Defense Advanced Research Projects     |
 |  Agency and the University of Southern California, Information Sciences  | 
 |  Institute.  Use and distribution of this software is further subject    |
 |  to the provisions of that contract and any other agreements developed   |
 |  between the user of the software and the University of Southern         |
 |  California, Information Sciences Institute.  It is supplied "AS IS",    |
 |  without any warranties of any kind.  It is furnished only on the basis  |
 |  that any party who receives it indemnifies and holds harmless the       |
 |  parties who furnish and originate it against any claims, demands, or    |
 |  liabilities connected with using it, furnishing it to others or         |
 |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |
 |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |
 |  BE ATTACHED TO EVERY PART.                                              |
 |                                                                          |
 +--------------------------------------------------------------------------+
*/



namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

// Global declarations:
extern Cons* oPL_KERNEL_KB_DEFINITIONSo;

// Function signatures:
void initializeKernelKb();
void startupPlKernelKb();

// Auxiliary global declarations:
extern Surrogate* SGT_PL_KERNEL_KB_PL_KERNEL_KB_CONCEPT;
extern Keyword* KWD_PL_KERNEL_KB_ASSERT_TRUE;
extern Surrogate* SGT_PL_KERNEL_KB_PL_KERNEL_KB_CLASS;
extern Symbol* SYM_PL_KERNEL_KB_STELLA_THING;
extern Symbol* SYM_PL_KERNEL_KB_PL_KERNEL_KB_STARTUP_PL_KERNEL_KB;
extern Symbol* SYM_PL_KERNEL_KB_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace pl_kernel_kb
