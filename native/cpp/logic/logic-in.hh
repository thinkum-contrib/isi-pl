//  -*- Mode: C++ -*-

// logic-in.hh

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



namespace logic {
  using namespace stella;

// Global declarations:
extern List* oAVAILABLE_POWERLOOM_FEATURESo;
extern List* oCURRENT_POWERLOOM_FEATURESo;
extern List* oDEFAULT_POWERLOOM_FEATURESo;
extern char* oLOGIC_PROMPTo;
extern char* oLOGIC_COMMAND_RESULT_INDENTo;
extern DECLARE_STELLA_SPECIAL(oCAREFUL_LOGIC_COMMAND_LOOP_EXITop, boolean );
extern DECLARE_STELLA_SPECIAL(oDEMO_LEVELo, int );
extern Cons* oDEMO_FILE_DEFAULTSo;
extern Cons* oDEMO_FILESo;
extern DECLARE_STELLA_SPECIAL(oTERMSOURCEBEINGPARSEDo, char* );
extern DECLARE_STELLA_SPECIAL(oDESCRIPTIONUNDERCONSTRUCTIONo, Object* );
extern DECLARE_STELLA_SPECIAL(oTERMUNDERCONSTRUCTIONo, Object* );
extern int oEXPRESSION_SIZE_CUTOFFo;
extern boolean oHANDLE_EXPLICITLY_QUALIFIED_LOGIC_OBJECTSpo;
extern List* oUNFINALIZED_OBJECTSo;
extern DECLARE_STELLA_SPECIAL(oFINALIZEOBJECTSIMMEDIATELYpo, boolean );
extern DECLARE_STELLA_SPECIAL(oINHIBITOBJECTFINALIZATIONpo, boolean );
extern Cons* oLOGIC_RELEVANT_STELLA_COMMANDSo;

// Function signatures:
void printFeatures();
List* listFeatures();
void setPowerloomFeature(Keyword* feature);
List* setFeature(Cons* features);
List* setFeatureEvaluatorWrapper(Cons* arguments);
void unsetPowerloomFeature(Keyword* feature);
List* unsetFeature(Cons* features);
List* unsetFeatureEvaluatorWrapper(Cons* arguments);
List* resetFeatures();
boolean enabledPowerloomFeatureP(Keyword* feature);
boolean disabledPowerloomFeatureP(Keyword* feature);
Object* coerceOptionValue(Object* value, Surrogate* type);
PropertyList* parseLogicCommandOptions(Object* options, Cons* LEGALOPTIONSATYPES, boolean coercionerrorP);
void printLogicPrompt();
void printLogicCommandResult(Object* result);
boolean logicCommandLoopExitP(Object* command, boolean& _Return1);
void logicCommandLoop();
Object* evaluateLogicCommand(Object* command, boolean finalizeP);
void load(char* file);
void loadEvaluatorWrapper(Cons* arguments);
void loadStream(InputStream* stream);
void printDemoPrompt();
boolean demoSkipToCommand(InputStream* stream);
boolean demoPauseP(boolean pauseP, boolean& _Return1);
void demoFile(char* file, boolean pauseP);
char* demoEntryFile(Cons* demoentry);
char* demoEntryDescription(Cons* demoentry);
boolean demoEntryTestSuiteP(Cons* demoentry);
char* selectExampleDemo(int index);
char* selectExampleDemoFromMenu();
void demoExampleDemos();
void demo(Cons* fileandpause);
void demoEvaluatorWrapper(Cons* arguments);
void testLogicFile(char* file);
char* getFormattedDateAndTime();
void runPowerloomTests();
void printFormulaContainingError(Object* self, OutputStream* stream);
void helpSignalPropositionError(OutputStream* stream, Keyword* warningorerror);
Keyword* logicDialect(Object* self);
Surrogate* lookupLogicObjectSurrogate(Symbol* name, Module* definitionmodule);
Surrogate* internLogicObjectSurrogate(Symbol* name);
char* nameObjectMetaclass(Object* self);
Keyword* logicObjectDefinitionType(Symbol* name, Object* oldobject, Object* newobject);
void bindLogicObjectToSurrogate(Symbol* name, Object* object);
void redefineLogicObject(Symbol* name, Object* oldobject, Object* newobject);
boolean explicitlyQualifiedLogicObjectNameP(GeneralizedSymbol* objectname, Module* definitionmodule);
Surrogate* coerceToBoundOrLocalSurrogate(GeneralizedSymbol* self);
Cons* axioms(Object* self);
Object* axiomsSetter(Object* self, Cons* axioms);
void definitionAxiomsHandler(NamedDescription* self, StorageSlot* slot, Object* theaxioms);
void definitionHalfRuleHandler(NamedDescription* self, StorageSlot* slot, Object* body);
Cons* combineAxiomLists(Cons* oldaxioms, Object* newaxioms);
Cons* yieldRelationParametersTree(NamedDescription* self, boolean dropfunctionparameterP, boolean typedP);
Object* completeRuleDefinition(NamedDescription* self, Object* body, Symbol* arrow);
void definitionKeywordAxiomsHandler(Object* self, Symbol* selfname, Keyword* key, Object* value);
Cons* helpDefineKeywordAxioms(Symbol* selfname, Keyword* key, Object* value);
void assertKeywordAxiom(Object* self, Symbol* selfname, Keyword* key, Object* value);
void registerUnfinalizedObject(Object* object);
void cleanupUnfinalizedObjects();
void linkOriginatedProposition(Object* object, Proposition* proposition);
Cons* helpFinalizeObjectAxioms(Cons* theaxioms);
void finalizeObjectAxioms(Object* self);
void checkDescriptionArgumentTypes(NamedDescription* self);
void finalizeObject(Object* self);
boolean finalizedObjectP(Object* self);
boolean objectsAreFinalizedP();
void finalizeObjects();
NamedDescription* helpDefineRelationFromParseTree(Cons* tree, char* stringifiedsource);
List* parseRelationParametersTree(Cons* parameters, List*& _Return1, boolean& _Return2);
NamedDescription* getIdenticalRelation(Symbol* name, char* stringifiedsource);
NamedDescription* deffunction(Cons* args);
NamedDescription* deffunctionEvaluatorWrapper(Cons* arguments);
NamedDescription* callDeffunction(Cons* arguments);
Cons* normalizeDeffunctionArguments(Cons* arguments);
NamedDescription* defrelation(Cons* args);
NamedDescription* defrelationEvaluatorWrapper(Cons* arguments);
NamedDescription* callDefrelation(Cons* arguments);
Cons* normalizeDefrelationArguments(Cons* arguments);
NamedDescription* defconcept(Cons* args);
NamedDescription* defconceptEvaluatorWrapper(Cons* arguments);
NamedDescription* callDefconcept(Cons* arguments);
Cons* normalizeDefconceptArguments(Cons* arguments);
NamedDescription* defineRelationFromParseTree(Cons* tree);
LogicObject* defobject(Cons* args);
LogicObject* defobjectEvaluatorWrapper(Cons* arguments);
LogicObject* definstance(Cons* args);
LogicObject* definstanceEvaluatorWrapper(Cons* arguments);
LogicObject* callDefobject(Cons* arguments);
Cons* normalizeDefobjectArguments(Cons* arguments);
Proposition* defproposition(Cons* args);
Proposition* defpropositionEvaluatorWrapper(Cons* arguments);
Proposition* defrule(Cons* args);
Proposition* defruleEvaluatorWrapper(Cons* arguments);
Proposition* callDefproposition(Cons* arguments);
Cons* normalizeDefpropositionArguments(Cons* arguments);
boolean commandL(MethodSlot* command1, MethodSlot* command2);
List* listLogicCommands();
void help(Cons* commands);
void helpEvaluatorWrapper(Cons* arguments);
void helpStartupLogicIn1();
void helpStartupLogicIn2();
void helpStartupLogicIn3();
void helpStartupLogicIn4();
void helpStartupLogicIn5();
void startupLogicIn();

// Auxiliary global declarations:
extern Keyword* KWD_LOGIC_IN_TRACE_SUBGOALS;
extern Keyword* KWD_LOGIC_IN_TRACE_SOLUTIONS;
extern Keyword* KWD_LOGIC_IN_TRACE_CLASSIFIER;
extern Keyword* KWD_LOGIC_IN_ITERATIVE_DEEPENING;
extern Keyword* KWD_LOGIC_IN_JUSTIFICATIONS;
extern Keyword* KWD_LOGIC_IN_JUST_IN_TIME_INFERENCE;
extern Keyword* KWD_LOGIC_IN_EMIT_THINKING_DOTS;
extern Keyword* KWD_LOGIC_IN_GOAL_TREE;
extern Keyword* KWD_LOGIC_IN_CLASSIFIER_INFERENCES;
extern Keyword* KWD_LOGIC_IN_CLOSED_WORLD;
extern Surrogate* SGT_LOGIC_IN_STELLA_INTEGER;
extern Surrogate* SGT_LOGIC_IN_STELLA_FLOAT;
extern Surrogate* SGT_LOGIC_IN_STELLA_NUMBER;
extern Surrogate* SGT_LOGIC_IN_STELLA_KEYWORD;
extern Surrogate* SGT_LOGIC_IN_STELLA_GENERALIZED_SYMBOL;
extern Surrogate* SGT_LOGIC_IN_STELLA_SYMBOL;
extern Surrogate* SGT_LOGIC_IN_STELLA_BOOLEAN;
extern Surrogate* SGT_LOGIC_IN_STELLA_MODULE;
extern Surrogate* SGT_LOGIC_IN_LOGIC_DESCRIPTION;
extern Surrogate* SGT_LOGIC_IN_LOGIC_NAMED_DESCRIPTION;
extern Surrogate* SGT_LOGIC_IN_STELLA_CONS;
extern Keyword* KWD_LOGIC_IN_ERROR;
extern Surrogate* SGT_LOGIC_IN_STELLA_PROPERTY_LIST;
extern Surrogate* SGT_LOGIC_IN_LOGIC_IDENTITY;
extern Keyword* KWD_LOGIC_IN_REALISTIC;
extern Keyword* KWD_LOGIC_IN_BYE;
extern Keyword* KWD_LOGIC_IN_EXIT;
extern Keyword* KWD_LOGIC_IN_HALT;
extern Keyword* KWD_LOGIC_IN_QUIT;
extern Keyword* KWD_LOGIC_IN_STOP;
extern Symbol* SYM_LOGIC_IN_LOGIC_BYE;
extern Symbol* SYM_LOGIC_IN_LOGIC_EXIT;
extern Symbol* SYM_LOGIC_IN_LOGIC_HALT;
extern Symbol* SYM_LOGIC_IN_LOGIC_QUIT;
extern Symbol* SYM_LOGIC_IN_LOGIC_STOP;
extern Keyword* KWD_LOGIC_IN_DEFINE;
extern Symbol* SYM_LOGIC_IN_STELLA_IN_MODULE;
extern Keyword* KWD_LOGIC_IN_FINALIZE;
extern Symbol* SYM_LOGIC_IN_STELLA_DEFMODULE;
extern Symbol* SYM_LOGIC_IN_STELLA_CLEAR_MODULE;
extern Symbol* SYM_LOGIC_IN_STELLA_DEFCLASS;
extern Symbol* SYM_LOGIC_IN_STELLA_DEFSLOT;
extern Symbol* SYM_LOGIC_IN_STELLA_DEFUN;
extern Symbol* SYM_LOGIC_IN_STELLA_DEFMETHOD;
extern Symbol* SYM_LOGIC_IN_LOGIC_DEFCONCEPT;
extern Symbol* SYM_LOGIC_IN_LOGIC_DEFFUNCTION;
extern Symbol* SYM_LOGIC_IN_LOGIC_DEFRELATION;
extern Symbol* SYM_LOGIC_IN_LOGIC_DEFOBJECT;
extern Symbol* SYM_LOGIC_IN_LOGIC_DEFINSTANCE;
extern Symbol* SYM_LOGIC_IN_LOGIC_IN_DIALECT;
extern Keyword* KWD_LOGIC_IN_WHITE_SPACE;
extern Symbol* SYM_LOGIC_IN_STELLA_FALSE;
extern Keyword* KWD_LOGIC_IN_WARNING;
extern Surrogate* SGT_LOGIC_IN_LOGIC_PROPOSITION;
extern Surrogate* SGT_LOGIC_IN_STELLA_RELATION;
extern Symbol* SYM_LOGIC_IN_LOGIC_MODULE_LOGIC_DIALECT;
extern Keyword* KWD_LOGIC_IN_KIF;
extern Surrogate* SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT;
extern Keyword* KWD_LOGIC_IN_DEFINITION;
extern Keyword* KWD_LOGIC_IN_REDEFINITION;
extern Keyword* KWD_LOGIC_IN_PROPER_DEFINITION;
extern Symbol* SYM_LOGIC_IN_LOGIC_OBJECT_AXIOMS;
extern Symbol* SYM_LOGIC_IN_LOGIC_PROPOSITION_AXIOMS;
extern Symbol* SYM_LOGIC_IN_STELLA_SLOT_OPTION_KEYWORD;
extern Symbol* SYM_LOGIC_IN_STELLA_AND;
extern Surrogate* SGT_LOGIC_IN_STELLA_THING;
extern Symbol* SYM_LOGIC_IN_STELLA_FORALL;
extern Symbol* SYM_LOGIC_IN_STELLA_NOT;
extern Keyword* KWD_LOGIC_IN_ASSERT_TRUE;
extern Symbol* SYM_LOGIC_IN_STELLA_BADp;
extern Symbol* SYM_LOGIC_IN_PL_KERNEL_KB_NTH_DOMAIN;
extern Symbol* SYM_LOGIC_IN_PL_KERNEL_KB_DOMAIN;
extern Symbol* SYM_LOGIC_IN_PL_KERNEL_KB_RANGE;
extern Keyword* KWD_LOGIC_IN__g;
extern Symbol* SYM_LOGIC_IN_LOGIC_pSELF;
extern Keyword* KWD_LOGIC_IN_eg;
extern Symbol* SYM_LOGIC_IN_LOGIC_DEFPROPOSITION;
extern Keyword* KWD_LOGIC_IN_CONCEIVE;
extern Keyword* KWD_LOGIC_IN_FORALL;
extern Symbol* SYM_LOGIC_IN_LOGIC_SATELLITE_PROPOSITIONS;
extern Keyword* KWD_LOGIC_IN_CONFIDENCE_LEVEL;
extern Keyword* KWD_LOGIC_IN_DEFAULT;
extern Keyword* KWD_LOGIC_IN_PRESUME_TRUE;
extern Keyword* KWD_LOGIC_IN_FORWARDp;
extern Keyword* KWD_LOGIC_IN_FORWARD_ONLYp;
extern Keyword* KWD_LOGIC_IN_BACKWARDp;
extern Keyword* KWD_LOGIC_IN_BACKWARD_ONLYp;
extern Keyword* KWD_LOGIC_IN_WEIGHT;
extern Symbol* SYM_LOGIC_IN_LOGIC_ABOUT;
extern Symbol* SYM_LOGIC_IN_LOGIC_FORWARD_ONLYp;
extern Symbol* SYM_LOGIC_IN_LOGIC_BACKWARD_ONLYp;
extern Symbol* SYM_LOGIC_IN_LOGIC_DONT_OPTIMIZEp;
extern Symbol* SYM_LOGIC_IN_STELLA_CC;
extern Symbol* SYM_LOGIC_IN_STELLA_METHOD_COMMANDp;
extern Symbol* SYM_LOGIC_IN_STELLA_DOCUMENTATION;
extern Symbol* SYM_LOGIC_IN_LOGIC_STARTUP_LOGIC_IN;
extern Symbol* SYM_LOGIC_IN_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
