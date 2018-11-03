//  -*- Mode: C++ -*-

// powerloom.cc

/*--------------------------------------------------------------------------+
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
 +--------------------------------------------------------------------------*/

#include "logic/logic-system.hh"

namespace logic {
  using namespace stella;

int oPOWERLOOM_MAJOR_VERSION_NUMBERo = 3;

int oPOWERLOOM_MINOR_VERSION_NUMBERo = 0;

char* oPOWERLOOM_RELEASE_STATEo = ".beta";

int oPOWERLOOM_PATCH_LEVELo = 1;

char* oPOWERLOOM_VERSION_STRINGo = NULL;

char* powerloomCopyrightHeader() {
  { char* logicsystemfile = makeSystemDefinitionFileName("logic");
    SystemDefinition* logicsystem = (probeFileP(logicsystemfile) ? getSystemDefinition("logic") : ((SystemDefinition*)(NULL)));
    KeyValueList* substitutionList = newKeyValueList();

    fillInDateSubstitution(substitutionList);
    if (((boolean)(logicsystem))) {
      return (substituteTemplateVariablesInString(logicsystem->banner, substitutionList));
    }
    else {
      return ("--------------------------------------------------------------------------+\n |                                                                          |\n |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2003              |\n |  University of Southern California, Information Sciences Institute       |\n |  4676 Admiralty Way                                                      |\n |  Marina Del Rey, California 90292                                        |\n |                                                                          |\n |  This software was developed under the terms and conditions of Contract  |\n |  No. N00014-94-C-0245 between the Defense Advanced Research Projects     |\n |  Agency and the University of Southern California, Information Sciences  | \n |  Institute.  Use and distribution of this software is further subject    |\n |  to the provisions of that contract and any other agreements developed   |\n |  between the user of the software and the University of Southern         |\n |  California, Information Sciences Institute.  It is supplied \"AS IS\",    |\n |  without any warranties of any kind.  It is furnished only on the basis  |\n |  that any party who receives it indemnifies and holds harmless the       |\n |  parties who furnish and originate it against any claims, demands, or    |\n |  liabilities connected with using it, furnishing it to others or         |\n |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |\n |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |\n |  BE ATTACHED TO EVERY PART.                                              |\n |                                                                          |\n +--------------------------------------------------------------------------");
    }
  }
}

void copyright() {
  // Print detailed PowerLoom copyright information.
  std::cout << " +" << powerloomCopyrightHeader() << "+" << std::endl;
}

char* copyrightYears() {
  { char* copyright = powerloomCopyrightHeader();
    int start = stringSearch(copyright, "1997", 0);
    int end = stringSearch(copyright, "  ", start);

    return (stringSubsequence(copyright, start, end));
  }
}

// Lock object for synchronizing safe multi-process access to PowerLoom
char* oPOWERLOOM_LOCKo = NULL;

void powerloom() {
  // Run the PowerLoom listener.  Read logic commands from the
  // standard input, evaluate them, and print their results.  Exit if the user
  // entered `bye', `exit', `halt', `quit', or `stop'.
  std::cout << std::endl << "    Welcome to " << oPOWERLOOM_VERSION_STRINGo << std::endl << std::endl << "Copyright (C) USC Information Sciences Institute, " << copyrightYears() << "." << std::endl << "PowerLoom is a trademark of the University of Southern California." << std::endl << "PowerLoom comes with ABSOLUTELY NO WARRANTY!" << std::endl << "Type `(copyright)' for detailed copyright information." << std::endl << "Type `(help)' for a list of available commands." << std::endl << "Type `(demo)' for a list of example applications." << std::endl << "Type `bye', `exit', `halt', `quit', or `stop', to exit." << std::endl << std::endl;
  try {
    logicCommandLoop();
    std::cout << "Bye." << std::endl << std::endl;
  }
  catch (std::exception& _e) {
    std::exception* e = &_e;

    *(STANDARD_ERROR->nativeStream) << "Caught native non-STELLA exception " << e << " at top level." << std::endl;
    printExceptionContext(e, STANDARD_ERROR);
    *(STANDARD_ERROR->nativeStream) << "Exiting PowerLoom." << std::endl << std::endl;
  }
}

void startupPowerloom() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      SYM_POWERLOOM_LOGIC_STARTUP_POWERLOOM = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-POWERLOOM", NULL, 0)));
      SYM_POWERLOOM_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
    }
    if (currentStartupTimePhaseP(4)) {
      oPOWERLOOM_VERSION_STRINGo = stringConcatenate("PowerLoom ", integerToString(oPOWERLOOM_MAJOR_VERSION_NUMBERo), 5, ".", integerToString(oPOWERLOOM_MINOR_VERSION_NUMBERo), ".", integerToString(oPOWERLOOM_PATCH_LEVELo), oPOWERLOOM_RELEASE_STATEo);
      oPOWERLOOM_LOCKo = makeProcessLock();
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("POWERLOOM-COPYRIGHT-HEADER", "(DEFUN (POWERLOOM-COPYRIGHT-HEADER STRING) ())", ((cpp_function_code)(&powerloomCopyrightHeader)), NULL);
      defineFunctionObject("COPYRIGHT", "(DEFUN COPYRIGHT () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print detailed PowerLoom copyright information.\")", ((cpp_function_code)(&copyright)), NULL);
      defineFunctionObject("COPYRIGHT-YEARS", "(DEFUN (COPYRIGHT-YEARS STRING) ())", ((cpp_function_code)(&copyrightYears)), NULL);
      defineFunctionObject("POWERLOOM", "(DEFUN POWERLOOM () :DOCUMENTATION \"Run the PowerLoom listener.  Read logic commands from the\nstandard input, evaluate them, and print their results.  Exit if the user\nentered `bye', `exit', `halt', `quit', or `stop'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&powerloom)), NULL);
      defineFunctionObject("STARTUP-POWERLOOM", "(DEFUN STARTUP-POWERLOOM () :PUBLIC? TRUE)", ((cpp_function_code)(&startupPowerloom)), NULL);
      { MethodSlot* function = lookupFunction(SYM_POWERLOOM_LOGIC_STARTUP_POWERLOOM);

        setDynamicSlotValue(function->dynamicSlots, SYM_POWERLOOM_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Powerloom"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-MAJOR-VERSION-NUMBER* INTEGER 3)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-MINOR-VERSION-NUMBER* INTEGER 0)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-RELEASE-STATE* STRING \".beta\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-PATCH-LEVEL* INTEGER 1)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-VERSION-STRING* STRING (CONCATENATE \"PowerLoom \" (INTEGER-TO-STRING *POWERLOOM-MAJOR-VERSION-NUMBER*) \".\" (INTEGER-TO-STRING *POWERLOOM-MINOR-VERSION-NUMBER*) \".\" (INTEGER-TO-STRING *POWERLOOM-PATCH-LEVEL*) *POWERLOOM-RELEASE-STATE*))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-LOCK* PROCESS-LOCK-OBJECT (MAKE-PROCESS-LOCK) :PUBLIC? TRUE :DOCUMENTATION \"Lock object for synchronizing safe multi-process access to PowerLoom\")");
    }
  }
}

Symbol* SYM_POWERLOOM_LOGIC_STARTUP_POWERLOOM = NULL;

Symbol* SYM_POWERLOOM_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
