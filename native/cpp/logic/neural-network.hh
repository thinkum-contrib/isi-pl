//  -*- Mode: C++ -*-

// neural-network.hh

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


namespace logic {
  using namespace stella;

// Class definitions:
class PropositionNeuralNetwork : public StandardObject {
public:
  Proposition* proposition;
  Vector* input;
  Vector* hidden;
  double output;
  Vector* inputError;
  Vector* hiddenError;
  twoDArray* ih;
  twoDArray* ihDelta;
  Vector* ho;
  Vector* hoDelta;
  twoDArray* ihSlope;
  twoDArray* ihPrevSlope;
  Vector* hoSlope;
  Vector* hoPrevSlope;
public:
  virtual Surrogate* primaryType();
};

class MultiDimensionalArray : public AbstractCollection {
public:
  virtual Surrogate* primaryType();
};

class twoDArray : public MultiDimensionalArray {
// Two-dimensional arrays with elements of type OBJECT.
public:
  int nofRows;
  int nofColumns;
  Object** theArray;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
  virtual void printArray(std::ostream* stream);
  virtual void fillArray(int values, ...);
  virtual Object* twoDElementSetter(Object* value, int row, int column);
  virtual Object* twoDElement(int row, int column);
};

class FloatVector : public AbstractCollection {
public:
  int arraySize;
  Object** theArray;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
  virtual boolean memberP(double object);
  virtual int length();
  virtual double nthSetter(double value, int position);
  virtual double nth(int position);
  virtual boolean nonEmptyP();
  virtual boolean emptyP();
  virtual void printVector(std::ostream* stream);
};

class twoDFloatArray : public MultiDimensionalArray {
// Two-dimensional arrays with elements of type FLOAT.
public:
  int nofRows;
  int nofColumns;
  Object** theArray;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
  virtual void printArray(std::ostream* stream);
  virtual void fillArray(int values, ...);
  virtual double twoDElementSetter(double value, int row, int column);
  virtual double twoDElement(int row, int column);
};


// Global declarations:
extern Keyword* oNEURAL_NETWORK_TRAINING_METHODo;
extern double oLEARNING_RATEo;
extern double oMOMENTUM_TERMo;
extern double oWEIGHT_RANGEo;
extern double oERROR_CUTOFFo;
extern int oERROR_PRINT_CYCLEo;
extern int oSAVE_NETWORK_CYCLEo;
extern char* oSAVE_NETWORK_FILEo;
extern boolean oTRACE_NEURAL_NETWORK_TRAININGo;
extern boolean oTRAIN_CACHED_NETWORKSpo;
extern double oMAX_MOVEMENTo;
extern double oMODE_SWITCHo;
extern double oSHRINK_FACTORo;
extern double oWEIGHT_DECAYo;
extern double oSIGMOID_PRIME_OFFSETo;
extern List* oMASTER_NEURAL_NETWORK_LISTo;
extern List* oACTIVATED_NETWORKSo;
extern PropositionNeuralNetwork* oSAVED_NETo;
extern List* oPARTIAL_SUPPORT_CACHEo;
extern Vector* oLEARNING_CURVEo;

// Function signatures:
PropositionNeuralNetwork* newPropositionNeuralNetwork();
Object* accessPropositionNeuralNetworkSlotValue(PropositionNeuralNetwork* self, Symbol* slotname, Object* value, boolean setvalueP);
void setTraceNeuralNetworkTraining(boolean b);
void setTraceNeuralNetworkTrainingEvaluatorWrapper(Cons* arguments);
void setSaveNetworkCycle(int i);
void setSaveNetworkCycleEvaluatorWrapper(Cons* arguments);
void setErrorCutoff(double f);
void setErrorCutoffEvaluatorWrapper(Cons* arguments);
void setTrainCachedNeuralNetworks(boolean b);
void setTrainCachedNeuralNetworksEvaluatorWrapper(Cons* arguments);
void setLearningRate(double rate);
void setLearningRateEvaluatorWrapper(Cons* arguments);
void setMomentumTerm(double m);
void setMomentumTermEvaluatorWrapper(Cons* arguments);
void setWeightRange(double w);
void setWeightRangeEvaluatorWrapper(Cons* arguments);
void setNeuralNetworkTrainingMethod(Keyword* m);
void setErrorPrintCycle(int i);
void setErrorPrintCycleEvaluatorWrapper(Cons* arguments);
void deleteAllNeuralNetworks();
void checkMasterNetworkList();
void clearAllNeuralNetworks();
void clearAllSlopes();
void clearSlopes(PropositionNeuralNetwork* net);
void randomizeNeuralNetwork(PropositionNeuralNetwork* net);
PropositionNeuralNetwork* createNeuralNetwork(Proposition* prop);
Proposition* gnp(Symbol* name);
PropositionNeuralNetwork* defnetwork(Cons* args);
PropositionNeuralNetwork* defnetworkEvaluatorWrapper(Cons* arguments);
PropositionNeuralNetwork* defineNeuralNetworkFromParseTree(Cons* tree);
PropositionNeuralNetwork* allocateNeuralNetwork(int numIn, int numHidden);
double activatePropositionalNeuralNetwork(PropositionNeuralNetwork* net);
char* makeNetInputString(Vector* input);
void trainNeuralNetwork(int cycles, int numTraining);
void trainNeuralNetworkEvaluatorWrapper(Cons* arguments);
void trainUncachedNeuralNetworks(int cycles, int numTraining);
void backpropagateError(Proposition* prop, double error);
void quickpropagateError(Proposition* prop, double error);
double computeError(double training, double output);
double computeDelta(double slope, double prevSlope, double prevDelta);
double computeQpDelta(double slope, double prevSlope, double prevDelta);
void modifyWeights();
double testOverTrainingExamples();
FloatWrapper* testOverTrainingExamplesEvaluatorWrapper(Cons* arguments);
double trainAndTestNeuralNetwork(int cycles, int numTraining, int numTesting);
FloatWrapper* trainAndTestNeuralNetworkEvaluatorWrapper(Cons* arguments);
double testNeuralNetwork();
FloatWrapper* testNeuralNetworkEvaluatorWrapper(Cons* arguments);
double multipleNetworkTrainingRuns(int runs, int cycles, int numTraining);
FloatWrapper* multipleNetworkTrainingRunsEvaluatorWrapper(Cons* arguments);
void trainCachedNeuralNetworks(int cycles, int numTraining);
void cachedBackpropagateError(Cons* tree, double error);
void cachedQuickpropagateError(Cons* tree, double error);
Cons* createCachedNetwork(Cons* consQuery);
Object* buildNetworkTree(Proposition* prop, Cons* propList);
double activateCachedNetwork(Cons* tree);
double randomWeight(double n);
double randomFloat(double n);
Vector* consToVector(Cons* form);
Vector* createVector(int values, ...);
void zeroVector(Vector* v);
void structuredNeuralNetworkRegression(Symbol* className, Symbol* slotName, int cycles);
void structuredNeuralNetworkRegressionEvaluatorWrapper(Cons* arguments);
List* getNnNearestNeighbors(TrainingExample* probe, List* cases, int k);
void swapInNewNetworks(List* oldNets, List* newNets);
void swapInNetworkFile(char* file);
void swapInNetworkFileEvaluatorWrapper(Cons* arguments);
List* loadNeuralNetworkFile(char* file);
List* loadNeuralNetworkFileEvaluatorWrapper(Cons* arguments);
void saveAllNeuralNetworks(char* file);
void saveAllNeuralNetworksEvaluatorWrapper(Cons* arguments);
void saveNeuralNetwork(PropositionNeuralNetwork* net, char* file);
void saveNeuralNetworkEvaluatorWrapper(Cons* arguments);
void printNeuralNetwork(PropositionNeuralNetwork* net, OutputStream* stream);
Vector* createHiddenSignature(Cons* consQuery);
MultiDimensionalArray* newMultiDimensionalArray();
twoDArray* new2DArray(int nofRows, int nofColumns);
Object* access2DArraySlotValue(twoDArray* self, Symbol* slotname, Object* value, boolean setvalueP);
void initialize2DArray(twoDArray* self);
twoDArray* create2DArray(int nofRows, int nofColumns, int values, ...);
FloatVector* newFloatVector(int arraySize);
Object* accessFloatVectorSlotValue(FloatVector* self, Symbol* slotname, Object* value, boolean setvalueP);
void initializeFloatVector(FloatVector* self);
FloatVector* createFloatVector(int values, ...);
twoDFloatArray* new2DFloatArray(int nofRows, int nofColumns);
Object* access2DFloatArraySlotValue(twoDFloatArray* self, Symbol* slotname, Object* value, boolean setvalueP);
void initialize2DFloatArray(twoDFloatArray* self);
twoDFloatArray* create2DFloatArray(int nofRows, int nofColumns, int values, ...);
void helpStartupNeuralNetwork1();
void helpStartupNeuralNetwork2();
void helpStartupNeuralNetwork3();
void helpStartupNeuralNetwork4();
void startupNeuralNetwork();

// Auxiliary global declarations:
extern Keyword* KWD_NEURAL_NETWORK_BACKPROP;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_WEIGHT_VECTOR;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_2_D_WEIGHT_ARRAY;
extern Surrogate* SGT_NEURAL_NETWORK_LOGIC_PROPOSITION_NEURAL_NETWORK;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_PROPOSITION;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_INPUT;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_HIDDEN;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_OUTPUT;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_INPUT_ERROR;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_HIDDEN_ERROR;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_IH;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_IH_DELTA;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_HO;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_HO_DELTA;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_IH_SLOPE;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_IH_PREV_SLOPE;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_HO_SLOPE;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_HO_PREV_SLOPE;
extern Keyword* KWD_NEURAL_NETWORK_AND;
extern Keyword* KWD_NEURAL_NETWORK_OR;
extern Keyword* KWD_NEURAL_NETWORK_QUICKPROP;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_MATCH_SCORE;
extern Keyword* KWD_NEURAL_NETWORK_BACKPROPAGATION;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_NEURAL_NETWORK;
extern Keyword* KWD_NEURAL_NETWORK_MAX;
extern Keyword* KWD_NEURAL_NETWORK_NOISY_OR;
extern Surrogate* SGT_NEURAL_NETWORK_STELLA_CONS;
extern Surrogate* SGT_NEURAL_NETWORK_LOGIC_PROPOSITION;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_DEFNETWORK;
extern Keyword* KWD_NEURAL_NETWORK_MATCH_MODE;
extern Keyword* KWD_NEURAL_NETWORK_NN;
extern Keyword* KWD_NEURAL_NETWORK_MAXIMIZE_SCOREp;
extern Surrogate* SGT_NEURAL_NETWORK_LOGIC_MULTI_DIMENSIONAL_ARRAY;
extern Surrogate* SGT_NEURAL_NETWORK_LOGIC_2_D_ARRAY;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_NOF_ROWS;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_NOF_COLUMNS;
extern Surrogate* SGT_NEURAL_NETWORK_LOGIC_FLOAT_VECTOR;
extern Symbol* SYM_NEURAL_NETWORK_STELLA_ARRAY_SIZE;
extern Surrogate* SGT_NEURAL_NETWORK_LOGIC_2_D_FLOAT_ARRAY;
extern Symbol* SYM_NEURAL_NETWORK_LOGIC_STARTUP_NEURAL_NETWORK;
extern Symbol* SYM_NEURAL_NETWORK_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
