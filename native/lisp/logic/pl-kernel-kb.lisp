;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; pl-kernel-kb.lisp

#|
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
|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CONCEPT NULL)
(CL:DEFVAR /PL-KERNEL-KB/KWD-PL-KERNEL-KB-ASSERT-TRUE NULL)
(CL:DEFVAR /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CLASS NULL)
(CL:DEFVAR /PL-KERNEL-KB/SYM-PL-KERNEL-KB-STELLA-THING NULL)
(CL:DEFVAR /PL-KERNEL-KB/SYM-PL-KERNEL-KB-PL-KERNEL-KB-STARTUP-PL-KERNEL-KB NULL)
(CL:DEFVAR /PL-KERNEL-KB/SYM-PL-KERNEL-KB-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* FALSE TRUE *MODULE* NIL))

;;; (DEFGLOBAL *PL-KERNEL-KB-DEFINITIONS* ...)

(CL:DEFVAR /PL-KERNEL-KB/*PL-KERNEL-KB-DEFINITIONS* NULL)

;;; (DEFUN INITIALIZE-KERNEL-KB ...)

(CL:DEFUN /PL-KERNEL-KB/INITIALIZE-KERNEL-KB ()
  "Bootstrap the PowerLoom built-in kernel KB."
  (CL:LET*
   ((KERNELINITFILE
     (LOOKUP-CONFIGURATION-PROPERTY "PLKernelKBInitFile"
      (WRAP-STRING "PL:sources;logic;pl-kernel-kb.plm") NULL))
    (KERNELKBDEFINITIONS
     (COPY-CONS-TREE /PL-KERNEL-KB/*PL-KERNEL-KB-DEFINITIONS*))
    (DUMMYCONCEPT NULL))
   (CL:SETQ KERNELINITFILE KERNELINITFILE)
   (CL:LET* ((*WARNIFREDEFINE?* FALSE))
    (CL:DECLARE (CL:SPECIAL *WARNIFREDEFINE?*))
    (CL:LET*
     ((*MODULE* (GET-STELLA-MODULE "PL-KERNEL-KB" TRUE))
      (*CONTEXT* *MODULE*))
     (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
     (CL:LET* ((SELF-000 (NEW-NAMED-DESCRIPTION)))
      (CL:SETF (%SURROGATE-VALUE-INVERSE SELF-000)
       /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CONCEPT)
      (CL:SETF (%IO-VARIABLE-TYPES SELF-000)
       (LIST /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CONCEPT))
      (CL:SETQ DUMMYCONCEPT SELF-000))
     (CL:SETF
      (%SURROGATE-VALUE
       /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CONCEPT)
      DUMMYCONCEPT)
     (GET-DESCRIPTION-EXTENSION DUMMYCONCEPT TRUE)
     (UPDATE-ISA-PROPOSITION DUMMYCONCEPT
      /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CONCEPT
      /PL-KERNEL-KB/KWD-PL-KERNEL-KB-ASSERT-TRUE)
     (CL:SETF
      (%SURROGATE-VALUE
       /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CLASS)
      DUMMYCONCEPT)
     (%EVALUATE (%%VALUE KERNELKBDEFINITIONS))
     (CL:SETF
      (%SURROGATE-VALUE
       /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CLASS)
      (%SURROGATE-VALUE
       /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CONCEPT))
     (CL:LET*
      ((DEFINITION NULL) (ITER-000 (%%REST KERNELKBDEFINITIONS)))
      (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
       (CL:PROGN (CL:SETQ DEFINITION (%%VALUE ITER-000))
        (CL:SETQ ITER-000 (%%REST ITER-000)))
       (%EVALUATE DEFINITION)))
     (FINALIZE-OBJECTS)
     (CL:LET* ((MDL NULL) (ITER-001 (ALL-MODULES)))
      (CL:LOOP WHILE (NEXT? ITER-001) DO
       (CL:SETQ MDL (%VALUE ITER-001)) (INTRODUCE-MODULE MDL)))
     (CL:LET*
      ((THING
        (GET-DESCRIPTION
         (GET-STELLA-CLASS /PL-KERNEL-KB/SYM-PL-KERNEL-KB-STELLA-THING
          TRUE))))
      (EVALUATE-STRING "(ASSERT (DOCUMENTATION THING  
           \"The class of all things.  `Thing' is the top-most concept
in the concept hierarchy.\"))"))))))

(CL:DEFUN /PL-KERNEL-KB/STARTUP-PL-KERNEL-KB ()
  (CL:LET*
   ((*MODULE*
     (GET-STELLA-MODULE "/PL-KERNEL-KB" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CONCEPT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CONCEPT" NULL 1))
    (CL:SETQ /PL-KERNEL-KB/KWD-PL-KERNEL-KB-ASSERT-TRUE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "ASSERT-TRUE" NULL 2))
    (CL:SETQ /PL-KERNEL-KB/SGT-PL-KERNEL-KB-PL-KERNEL-KB-CLASS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CLASS" NULL 1))
    (CL:SETQ /PL-KERNEL-KB/SYM-PL-KERNEL-KB-STELLA-THING
     (INTERN-RIGID-SYMBOL-WRT-MODULE "THING"
      (GET-STELLA-MODULE "/STELLA" TRUE) 0))
    (CL:SETQ
     /PL-KERNEL-KB/SYM-PL-KERNEL-KB-PL-KERNEL-KB-STARTUP-PL-KERNEL-KB
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-PL-KERNEL-KB" NULL 0))
    (CL:SETQ
     /PL-KERNEL-KB/SYM-PL-KERNEL-KB-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" TRUE) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "INITIALIZE-KERNEL-KB"
     "(DEFUN INITIALIZE-KERNEL-KB () :DOCUMENTATION \"Bootstrap the PowerLoom built-in kernel KB.\" :PUBLIC? TRUE :COMMAND? TRUE)"
     (CL:FUNCTION /PL-KERNEL-KB/INITIALIZE-KERNEL-KB) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-PL-KERNEL-KB"
     "(DEFUN STARTUP-PL-KERNEL-KB () :PUBLIC? TRUE)"
     (CL:FUNCTION /PL-KERNEL-KB/STARTUP-PL-KERNEL-KB) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION
        /PL-KERNEL-KB/SYM-PL-KERNEL-KB-PL-KERNEL-KB-STARTUP-PL-KERNEL-KB)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      /PL-KERNEL-KB/SYM-PL-KERNEL-KB-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_Startup-Pl-Kernel-Kb") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL *PL-KERNEL-KB-DEFINITIONS* CONS NULL)")
    (CL:SETQ /PL-KERNEL-KB/*PL-KERNEL-KB-DEFINITIONS*
     (GET-QUOTED-TREE
      "(((DEFCONCEPT CONCEPT (?X RELATION) :DOCUMENTATION \"The class of reified unary relations.  The Powerloom
notion of `concept' corresponds to the object-oriented notion of `class'.
From a logic standpoint, the notion of a concept is hard to distinguish
from the notion of `unary relation'.  The conceptual distinction is
best illustrated in the domain of linguistics, where concepts are
identified with collective nouns while unary relations are identified
with adjectives.  For example, `Rock' is a concept, while `rocky' is a
unary relation.\" :AXIOMS (AND (SYNONYM CONCEPT CLASS) (CLOSED CONCEPT))) (DEFCONCEPT RELATION (?X SET) :DOCUMENTATION \"The class of relations.  This includes all concepts and
all functions.\" :AXIOMS (CLOSED RELATION)) (DEFCONCEPT FUNCTION (?R RELATION) :DOCUMENTATION \"A relation is a function if its last argument
is a function of its first n-1 arguments, i.e., if it is a single-valued
relation.  Functions explicitly declared as such differ from relations
in that they may appear syntactically as a term applied to n-1 arguments.
For example, to express the sentence \\\"two plus two equals four\\\", because
`+' is a function we can write `(= (+ 2 2) 4)'.  The same sentence written
in relational syntax would look like `(+ 2 2 4)'.  If a relation is
introduced using the `defrelation' syntax and also declared to be
single-valued, the functional syntax does not apply; only the explicit
use of `deffunction' sanctions the use of that syntax.\" :AXIOMS (CLOSED FUNCTION)) (DEFCONCEPT AGGREGATE (?A) :DOCUMENTATION \"?a is an aggregate\") (DEFCONCEPT COLLECTION (?C AGGREGATE) :DOCUMENTATION \"The class of all collections.  This includes all sets,
lists, concepts, and relations.\" :AXIOMS (ABSTRACT COLLECTION)) (DEFCONCEPT DUPLICATE-FREE-COLLECTION (?C COLLECTION) :DOCUMENTATION \"?c is free of duplicates\" :=>> (DUPLICATE-FREE ?C)) (DEFCONCEPT SET (?S DUPLICATE-FREE-COLLECTION) :DOCUMENTATION \"This class denotes the mathematical notion of a 'set';
a collection that has no duplicates.\") (DEFCONCEPT NUMERIC-SET (?S COLLECTION) :DOCUMENTATION \"?s is a set of numbers\" :AXIOMS (ABSTRACT NUMERIC-SET)) (DEFCONCEPT LIST (?L COLLECTION) :DOCUMENTATION \"A list is an ordered collection of elements.  The range
of the function `listof' consists of elements of type `List'.\" :=>> (ORDERED ?L)) (DEFCONCEPT GROUP (?C DUPLICATE-FREE-COLLECTION) :DOCUMENTATION \"?c is a group\") (DEFCONCEPT STUFF (?S AGGREGATE) :DOCUMENTATION \"?s is stuff\") (DEFCONCEPT SCALAR (?X) :DOCUMENTATION \"The class of scalar quantities.\") (ASSERT (SUBSET-OF NUMBER SCALAR)) (DEFCONCEPT SCALAR-INTERVAL (?X SCALAR) :DOCUMENTATION \"An interval of scalar quantities. \") (ASSERT (SUBSET-OF INTEGER-INTERVAL SCALAR-INTERVAL)) (DEFRELATION PHRASE (?R (?S STRING)) :DOCUMENTATION \"A phrase is a variablized sentence, a template, that
is used to express individual axiomatic facts as natural language
sentences.  By convention, a phrase contains one or more occurrences
of each variable in a relation or concept definition, it does not
begin with a capital letter, and it has no concluding period.
Systematic attachment of phrases to relations can be leveraged by
tools that generate natural language paraphrases of logic sentences.\" :PHRASE \"?r has phrase ?s\") (DEFRELATION LEXEME (?R (?S STRING)) :DOCUMENTATION \"?s is a lexeme for the relation or individual ?r.
A relation or individual ?r can have zero or more lexemes, words that are
natural langage equivalents of a logical constant.  The same lexeme may be
attached to more than one constant.\") (DEFRELATION COMMENT (?X (?S STRING)) :DOCUMENTATION \"?s is a comment attached to ?x.  Comments are
a generalization of other annotations such as `documentation' and
`issue' strings.\") (DEFRELATION DOCUMENTATION (?X (?S STRING)) :DOCUMENTATION \"?s is a documentation string attached to ?x.  Some
of the PowerLoom text processing tools look for documentation strings and 
import them into documents.\" :=> (COMMENT ?X ?S)) (DEFRELATION ISSUE (?X (?S STRING)) :DOCUMENTATION \"?s is an issue attached to ?x.  An issue string 
normally comments on a topic that has not been resolved to everyone's
satisfaction.\" :=> (COMMENT ?X ?S)) (DEFRELATION EXAMPLE ((?R RELATION) ?E) :DOCUMENTATION \"?e is an example of (the use of) ?r.\") (DEFRELATION IMAGE-URL (?X (?URL STRING)) :DOCUMENTATION \"?url is a URL pointing to an image illustrating ?x.
The Ontosaurus browser looks for `image-url' values attached to
objects it is presenting, and displays them prominently, thereby spiffing
up its displays.\") (DEFRELATION RELATION-SPECIALIST ((?R RELATION) (?SP COMPUTED-PROCEDURE)) :DOCUMENTATION \"Names a 'specialist' (a function) that evaluates an (atomic) relation
proposition during query processing.  This defines an extensible
means for computing with the control stack.  The function is passed
a CONTROL-FRAME that contains the proposition, and returns a keyword
:FINAL-SUCCESS, :CONTINUING-SUCCESS, :FAILURE, or :TERMINAL-FAILURE
that controls the result of the computation.\" :AXIOMS (SINGLE-VALUED RELATION-SPECIALIST)) (DEFRELATION RELATION-EVALUATOR ((?R RELATION) (?EV COMPUTED-PROCEDURE)) :DOCUMENTATION \"Names an 'evaluator' (a function) that evaluates an (atomic) relation
proposition during constraint propagation.  This defines an extensible
means for computing using auxiliary data structures.  The function is passed
a proposition for evaluation which might update the proposition, generate
additional assertions or trigger further evaluations.  Evaluators have to
check the truth-value of the passed-in proposition and perform their actions
accordingly.  An evaluated proposition might be true, false or even unknown
in case the propositon was just newly constructed.\" :AXIOMS (SINGLE-VALUED RELATION-EVALUATOR)) (DEFRELATION RELATION-COMPUTATION ((?R RELATION) (?COMPUTATION COMPUTED-PROCEDURE)) :DOCUMENTATION \"Names a 'computation' (a function) that evaluates an (atomic) relation
proposition during query processing.  The function is passed a proposition
for evaluation for which all arguments are bound.  The function
returns a BOOLEAN if it represents a predicate, or some sort of value
if it is a function.\" :=>> (RELATION-SPECIALIST ?R COMPUTATION-SPECIALIST) :AXIOMS (SINGLE-VALUED RELATION-COMPUTATION)) (DEFRELATION RELATION-CONSTRAINT ((?R RELATION) (?COMPUTATION COMPUTED-PROCEDURE)) :DOCUMENTATION \"Names a 'computation' (a function) that evaluates an (atomic) relation
proposition during query processing.  The function is passed a proposition
for evaluation for which at most one argument is unbound.  The function
returns a BOOLEAN if it represents a predicate, or some sort of value
if it is a function.  If all arguments are bound the function computes whether
the constraint holds.  If all but one argument is bound and the unbound
argument is a pattern variable then the missing value is computed.\" :=>> (RELATION-SPECIALIST ?R CONSTRAINT-SPECIALIST) :AXIOMS (SINGLE-VALUED RELATION-CONSTRAINT)) (DEFRELATION HANDLES-REVERSE-POLARITY ((?CP COMPUTED-PROCEDURE)) :DOCUMENTATION \"Very specialized PowerLoom predicate.  Indicates that a computed procedure
used as a relation specialist is programmed to handle reverse
polarity (*reversePolarity?*).\") (DEFRELATION GOES-TRUE-DEMON ((?R RELATION) (?COMPUTATION COMPUTED-PROCEDURE)) :DOCUMENTATION \"Names a 'computation' (a function) that is attached (logically)
to ?r  Each time a proposition with predicate ?r becomes
true, the function is applied to that proposition.\" :AXIOMS (SINGLE-VALUED GOES-TRUE-DEMON)) (DEFRELATION GOES-UNKNOWN-DEMON ((?R RELATION) (?COMPUTATION COMPUTED-PROCEDURE)) :DOCUMENTATION \"Names a 'computation' (a function) that is attached (logically)
to ?r  Each time a proposition with predicate ?r becomes
unknown, the function is applied to that proposition.\" :AXIOMS (SINGLE-VALUED GOES-UNKNOWN-DEMON)) (DEFRELATION GOES-FALSE-DEMON ((?R RELATION) (?COMPUTATION COMPUTED-PROCEDURE)) :DOCUMENTATION \"Names a 'computation' (a function) that is attached (logically)
to ?r  Each time a proposition with predicate ?r becomes
false, the function is applied to that proposition.\" :AXIOMS (SINGLE-VALUED GOES-FALSE-DEMON)) (DEFRELATION SYNONYM (?TERM ?SYNONYM) :PHRASE \"?synonym is a synonym for ?term\" :DOCUMENTATION \"Assert that `?synonym' is a synonym of `?term'.  This
causes all references to `?synonym' to be interpreted as references
to `?term'.  Retraction eliminates a synonym relation.\") (ASSERT (AND (GOES-TRUE-DEMON SYNONYM ASSERT-SYNONYM-DEMON) (GOES-UNKNOWN-DEMON SYNONYM RETRACT-SYNONYM-DEMON))) (DEFFUNCTION COLLECTIONOF (?M) :-> (?C COLLECTION) :DOCUMENTATION \"Abstract function existing to subsume 'SETOF'
and 'LISTOF'.\" :AXIOMS (VARIABLE-ARITY COLLECTIONOF)) (DEFFUNCTION SETOF (?M) :-> (?C SET) :DOCUMENTATION \"Term-forming function that defines an enumerated set
consisting of all function arguments.  `setof' is like `listof' except
that it removes duplicate values.\" :AXIOMS (AND (SUBSET-OF SETOF COLLECTIONOF) (VARIABLE-ARITY SETOF) (TOTAL SETOF))) (DEFFUNCTION LISTOF (?M) :-> (?C LIST) :DOCUMENTATION \"Term-forming function that defines an ordered list
consisting of all function arguments.  Within logical expressions
`listof' is most commonly used in conjunction with the `member-of'
predicate.  For example the query
	 
  (retrieve ?x (member-of ?x (listof a b c)))
	
returns the constants `a', `b', and `c' on successive iterations.\" :AXIOMS (AND (SUBSET-OF LISTOF COLLECTIONOF) (VARIABLE-ARITY LISTOF) (TOTAL LISTOF))) (DEFRELATION HOLDS ((?RELATION RELATION) ?ARGUMENTS) :DOCUMENTATION \"True if the tuple '?arguments' is a member of the
relation '?relation'.  `holds' is a variable arity predicate that takes
a relation as its first argument, and zero or more additional arguments.
It returns values equivalent to a subgoal that has the first argument
as a predicate and the remaining arguments shifted one place to the left.
For `holds' to succeed, the (first) relation argument must be bound --
PowerLoom will NOT cycle through all relations searching for ones that
permit the proof to succeed.  However, users can obtain the same effect
if they choose by using other second-order predicates to generate
relation bindings.  For example, the query
	 
   (retrieve all ?x (and (Relation ?r)
                         (holds ?r Fred ?x)))
	
retrieves all constants for which there is some binary relation that
relates `Fred' to that relation.\" :AXIOMS (AND (VARIABLE-ARITY HOLDS) (RELATION-SPECIALIST HOLDS HOLDS-SPECIALIST))) (DEFFUNCTION VALUE ((?FUNCTION FUNCTION) ?ARGUMENTS) :-> ?VALUE :DOCUMENTATION \"True if applying '?function' to '?arguments'
yields the value '?value'.  The `value' predicate is the analog
of `holds', except that it applies to functions instead of relations.\" :AXIOMS (AND (VARIABLE-ARITY VALUE) (RELATION-SPECIALIST VALUE VALUE-SPECIALIST))) (DEFRELATION IST ((?CONTEXT CONTEXT) (?P PROPOSITION)) :DOCUMENTATION \"True if proposition '?p' is true in context '?context'.
The `IST' (is true) relation allows one to evaluate a query or rule in more
than one context.  A common use of `IST' is in defining 'lifting axioms'
that import knowledge from one context to another.  For example, below is
a rule that accesses a `patient-record' relation in a module called
`Medical-Kb', 'lifts-out' the `age' column, and imports it into a
`has-age' relation in the current context.
	 
  (<= (has-age ?person ?age)
      (and (has-ssn ?person ?ssn)
           (exists (?1 ?2 ?3 ?4)
              (ist Medical-Kb (patient-record ?ssn ?1 ?2 ?age ?3 ?4)))))
	
\" :AXIOMS (AND (RELATION-SPECIALIST IST IST-SPECIALIST) (HANDLES-REVERSE-POLARITY IST-SPECIALIST))) (DEFRELATION CUT (?ARGUMENTS) :DOCUMENTATION \"Prolog-like CUT.  Succeeds the first time and
then fails.  Side-effect:  Locally disables query optimization.\" :AXIOMS (AND (VARIABLE-ARITY CUT) (RELATION-SPECIALIST CUT CUT-SPECIALIST))) (DEFRELATION BOUND-VARIABLES (?ARGUMENTS) :DOCUMENTATION \"True if all arguments are bound.  The `bound-variables'
predicate is used as a performance enhancer, to prevent other predicates
from backchaining excessively while searching for bindings of certain of
their arguments. Purists will shun the use of this predicate, but some rules
are inherently inefficient without the addition of some kind of control logic.
Because evaluation of the `bound-variables' predicate evaluation of
predicates being 'guarded', using this predicate has the side-effect
of locally disabling query optimization.  (See `collect-into-set' for
an example that uses `bound-variables'.\" :AXIOMS (AND (VARIABLE-ARITY BOUND-VARIABLES) (HANDLES-REVERSE-POLARITY BOUND-VARIABLES-SPECIALIST) (RELATION-SPECIALIST BOUND-VARIABLES BOUND-VARIABLES-SPECIALIST))) (DEFRELATION FORK ((?TEST PROPOSITION) (?THEN PROPOSITION) (?ELSE PROPOSITION)) :DOCUMENTATION \"Fail-based conditional.  If ?test succeeds, evaluates
?then; otherwise evaluates ?else.\" :AXIOMS (RELATION-SPECIALIST FORK FORK-SPECIALIST)) (DEFRELATION QUERY ((?PROP PROPOSITION) ?OPTIONS) :DOCUMENTATION \"EXPERIMENTAL search-control relation that allows one to prove
or retrieve bindings for ?prop with modified search control ?options.  The list
of accepted ?options is currently the same as are legal for a top-level `ask'
or `retrieve' query.  The special option value :INHERIT inherits the option
value from the parent or top-level query.  The option pair :INHERIT :ALL
inherits all parent options which can then be further modified by additional
individual option specifications.  At most how many solutions will be generated
is controlled by the :HOW-MANY option (just like in the top level `retrieve').
The default is 1 which is again the same as for `retrieve' but different from
how normal subgoals behave (those behave in a lazy all solutions mode).
The reason for this is that for partial match subqueries, solutions need to be
generated eagerly, therefore, a default of generating all solutions is not
desirable.\" :VARIABLE-ARITY TRUE :RELATION-SPECIALIST QUERY-SPECIALIST) (DEFFUNCTION OBSERVED-CARDINALITY-OF ((?R RELATION)) :-> (?CARD INTEGER) :DOCUMENTATION \"Used by PowerLoom to record the sizes of class
and relation extensions.  Only filled if the relation extension was
directly accessed by some query.\") (DEFRELATION HIDDEN-RELATION ((?R RELATION)) :DOCUMENTATION \"Indicates that ?r is used like an internal data
structure; not for user consumption.\") (DEFRELATION POLYMORPHIC ((?R RELATION)) :DOCUMENTATION \"True if ?r' supports polymorphism.\") (DEFRELATION INSTANCE-OF ((?X THING) (?C CONCEPT)) :DOCUMENTATION \"True if ?x is an instance of ?c.  Can
be used to generate concept values of ?c, given an instance ?x.\" :AXIOMS (RELATION-SPECIALIST INSTANCE-OF INSTANCE-OF-SPECIALIST)) (DEFRELATION TYPE-OF ((?C CONCEPT) (?X THING)) :DOCUMENTATION \"True if ?x is a member of the concept ?c.\" :<<=>> (INSTANCE-OF ?X ?C) :AXIOMS (INVERSE INSTANCE-OF TYPE-OF)) (DEFRELATION SUBSET-OF ((?SUB COLLECTION) (?SUPER COLLECTION)) :DOCUMENTATION \"True if ?sub is a subset of ?super.  For performance
reasons, the `subset-of' predicate refuses to search for bindings if
both of its variables are unbound.  Implementation note: `subset-of' 
is treated specially internally to PowerLoom, and hence Powerloom does not
permit the augmentation of `subset-of' with additional inference rules.
In otherwords, `subset-of' behaves semantically like an operator instead
of a relation.\" :AXIOMS (RELATION-SPECIALIST SUBSET-OF SUBSET-OF-SPECIALIST)) (DEFRELATION MEMBER-OF ((?X THING) (?C COLLECTION)) :DOCUMENTATION \"TRUE if ?x is a member of collection ?c.  A common use
of `member-of' is for binding a variable to successive members in a list
or set (see `listof' and `setof').\" :AXIOMS (AND (RELATION-SPECIALIST MEMBER-OF MEMBER-OF-SPECIALIST) (HANDLES-REVERSE-POLARITY MEMBER-OF-SPECIALIST) (RELATION-EVALUATOR MEMBER-OF MEMBER-OF-EVALUATOR))) (DEFRELATION PORTION-OF ((?X AGGREGATE) (?Y AGGREGATE)) :PHRASE \"?x is a portion of (a piece of) ?y\" :AXIOMS ((TRANSITIVE PORTION-OF))) (DEFRELATION DOMAIN ((?R RELATION) (?D CONCEPT)) :DOCUMENTATION \"True if for any tuple `T' that satifies ?r, the first
argument of `T' necessarily belongs to the concept ?d.  `domain' exists
for convenience only and is defined in terms of `nth-domain'.  `domain'
assertions should be avoided, since they create redundant `nth-domain'
propositions (use `nth-domain' directly).\" :<<=>> (NTH-DOMAIN ?R 0 ?D) :=>> (=>> (HOLDS ?R ?I ?V) (HOLDS ?D ?I))) (DEFRELATION RANGE ((?R RELATION) (?RNG CONCEPT)) :DOCUMENTATION \"True if for any tuple 'T' that satifies ?r, the last
argument of 'T' necessarily belongs to the concept ?rng.  `range' exists
for convenience only and is defined in terms of `nth-domain'.  `range'
assertions should be avoided, since they create redundant `nth-domain'
propositions (use `nth-domain' directly).\" :<<= (AND (> (ARITY ?R) 1) (NTH-DOMAIN ?R (- (ARITY ?R) 1) ?RNG)) :=>> (NTH-DOMAIN ?R (- (ARITY ?R) 1) ?RNG) :=>> (=>> (HOLDS ?R ?I ?V) (HOLDS ?RNG ?V))) (DEFRELATION NTH-DOMAIN ((?R RELATION) (?I INTEGER) (?D CONCEPT)) :DOCUMENTATION \"True if the nth value for a tuple T satisfying
?r must belong to the concept ?d.  Argument counting starts at zero.\" :AXIOMS (<<= (NTH-DOMAIN ?R 0 ?R) (CONCEPT ?R))) (DEFRELATION CLOSED ((?C COLLECTION)) :PHRASE \"?c is closed\" :DOCUMENTATION \"The collection ?c is closed if all of its members are known.
Asserting that a relation is closed makes certain computations easier.
For example, suppose that the relation `happy' is closed,
implying that all things that are happy will be asserted as such.
To prove `(not (happy Fred))', PowerLoom can use a negation-as-failure 
proof strategy which returns TRUE if `Fred' cannot be proved to be happy.
Also, if the relation `children' is closed, then a value for the expression
`(range-max-cardinality children Fred)' can be inferred merely by
counting the number of fillers of the `children' role on `Fred'.\" :AXIOMS (AND (HANDLES-REVERSE-POLARITY CLOSED-SPECIALIST) (RELATION-SPECIALIST CLOSED CLOSED-SPECIALIST))) (DEFRELATION EMPTY ((?C COLLECTION)) :DOCUMENTATION \"The collection ?c is empty if it has no members.  Note
that for collections possessing open-world semantics, (e.g., most concepts)
the fact that the collection has no known members does not necessarily
imply that it is empty.\" :AXIOMS (AND (RELATION-SPECIALIST EMPTY EMPTY-SPECIALIST) (COMPUTED EMPTY))) (DEFRELATION SINGLE-VALUED ((?C RELATION)) :DOCUMENTATION \"The relation ?c is single-valued if the value of its
last argument is a function of all other arguments.  All functions
are single-valued (see `function').\" :AXIOMS (AND (HANDLES-REVERSE-POLARITY SINGLE-VALUED-SPECIALIST) (RELATION-SPECIALIST SINGLE-VALUED SINGLE-VALUED-SPECIALIST))) (DEFRELATION COMPUTED ((?C RELATION)) :DOCUMENTATION \"?c is computed if it can be evaluated only if all of
its input arguments are bound (or all of them if it is a relation).
Considered by the query optimizer when looking for generators.\") (DEFFUNCTION THE-ROLESET ((?R RELATION) ?I) :-> (?RS SET) :DOCUMENTATION \"Function that defines a mapping from a relation
and instance to the skolem that (intensionally) denotes the
corresponding set of role fillers.\") (DEFFUNCTION FILLERS ((?R RELATION) ?I) :-> (?MEMBERS SET) :DOCUMENTATION \"Given a relation ?r and instance ?i, returns
a set of known fillers of ?r applied to ?i.  IMPORTANT: this also collects
intensional fillers such as skolems that might be identical extensionally.\" :<<= (AND (BOUND-VARIABLES ?R ?I) (COLLECT-INTO-SET (SETOFALL ?V (HOLDS ?R ?I ?V)) ?MEMBERS)) :AXIOMS (COMPUTED FILLERS)) (DEFFUNCTION CARDINALITY ((?C SET)) :-> (?CARD INTEGER) :DOCUMENTATION \"Function that returns the cardinality of a set.\" :<<= (AND (CLOSED ?C) (LENGTH-OF-LIST (COLLECT-INTO-SET ?C) ?CARD))) (DEFCONCEPT FRAME-PREDICATE ((?C RELATION)) :DOCUMENTATION \"A frame predicate is a second-order relation that
is used to describe constraints on the set of fillers for a binary
relation applied to an instance.  Examples of frame predicates are
`range-cardinality', `range-type', and `numeric-minimum'.  Frame predicates
are typically used to capture the kinds of relations manipulated
by description logic systems such as USC/ISI's Loom system.\") (DEFRELATION RANGE-TYPE ((?R RELATION) ?I (?TYPE CONCEPT)) :DOCUMENTATION \"Relation that specifies a type/range of the relation ?r applied to ?i.
Multiple range types may be asserted for a single pair <?r,?i>.  Technically,
a retrieval of types for a given pair should include all supertypes
(superconcepts) of any type that is produced, but for utility's sake,
only asserted or directly inferrable types are returned.\" :=>> (FORALL ?V (=>> (HOLDS ?R ?I ?V) (HOLDS ?TYPE ?V))) :<<=>> (SUBSET-OF (THE-ROLESET ?R ?I) ?TYPE) :<<= (AND (BOUND-VARIABLES ?R ?I ?TYPE) (FORK (AND (SINGLE-VALUED ?R) (EXISTS ?V (HOLDS ?R ?I ?V))) (EXISTS ?V (AND (HOLDS ?R ?I ?V) (HOLDS ?TYPE ?V))) (OR (AND (OR (CLOSED ?R) (CLOSED (THE-ROLESET ?R ?I))) (FORALL ?V (=> (HOLDS ?R ?I ?V) (HOLDS ?TYPE ?V)))) (EXISTS (?SUPERR ?SUPERVT) (AND (SUBSET-OF ?R ?SUPERR) (RANGE-TYPE ?SUPERR ?I ?SUPERVT) (SUBSET-OF ?SUPERVT ?TYPE)))))) :AXIOMS (AND (COMPUTED RANGE-TYPE) (FRAME-PREDICATE RANGE-TYPE) (RELATION-SPECIALIST RANGE-TYPE RANGE-TYPE-SPECIALIST))) (DEFRELATION RANGE-CARDINALITY-LOWER-BOUND ((?R RELATION) ?I (?LB INTEGER)) :DOCUMENTATION \"Relation that specifies a lower bound on the cardinality 
of the set of fillers of the relation ?r applied to ?i.  The difference
between `range-cardinality-lower-bound' and `range-min-cardinality' is
subtle but significant.   Suppose we state that nine is a lower bound
on the number of planets in the solar system, and then ask if eight is
(also) a lower bound:
	 
   (assert (range-cardinality-lower-bound hasPlanets SolarSystem 9))
   (ask (range-cardinality-lower-bound hasPlanets SolarSystem 8))  ==> TRUE
	
PowerLoom will return TRUE.  However if we ask if the minimum cardinality
of the solar system's planets is eight, we get back UNKNOWN
	 
   (ask (range-min-cardinality hasPlanets SolarSystem 8)) ==> UNKNOWN
	
because eight is not the tightest lower bound.\" :AXIOMS (<<= (RANGE-CARDINALITY-LOWER-BOUND ?R ?I ?LB) (AND (BOUND-VARIABLES ?R ?I ?LB) (=< ?LB (RANGE-MIN-CARDINALITY ?R ?I)))) :AXIOMS (=>> (RANGE-CARDINALITY-LOWER-BOUND ?R ?I ?LB) (>= (CARDINALITY (THE-ROLESET ?R ?I)) ?LB)) :AXIOMS (AND (FRAME-PREDICATE RANGE-CARDINALITY-LOWER-BOUND) (RELATION-SPECIALIST RANGE-CARDINALITY-LOWER-BOUND RANGE-MIN-CARDINALITY-SPECIALIST))) (DEFRELATION RANGE-CARDINALITY-UPPER-BOUND ((?R RELATION) ?I (?UB INTEGER)) :DOCUMENTATION \"Relation that specifies an upper bound on the cardinality 
of the set of fillers of the relation ?r applied to ?i. (see the discussion
for `range-cardinality-lower-bound').\" :AXIOMS (<<= (RANGE-CARDINALITY-UPPER-BOUND ?R ?I ?UB) (AND (BOUND-VARIABLES ?R ?I ?UB) (>= ?UB (RANGE-MAX-CARDINALITY ?R ?I)))) :AXIOMS (=>> (RANGE-CARDINALITY-UPPER-BOUND ?R ?I ?UB) (=< (CARDINALITY (THE-ROLESET ?R ?I)) ?UB)) :AXIOMS (AND (FRAME-PREDICATE RANGE-CARDINALITY-UPPER-BOUND) (RELATION-SPECIALIST RANGE-CARDINALITY-UPPER-BOUND RANGE-MAX-CARDINALITY-SPECIALIST))) (DEFFUNCTION RANGE-CARDINALITY ((?R RELATION) ?I) :-> (?CARD INTEGER) :DOCUMENTATION \"Function that returns the cardinality of the set
of fillers of the relation ?r applied to ?i.  The cardinality function
returns a value only when the relations `range-min-cardinality' and
`range-max-cardinality' compute identical values, i.e., when the
best lower and upper bounds on the cardinality are equal.  Each of
these bounding functions employs a variety of rules to try and
compute a tight bound.\" :AXIOMS (<<= (RANGE-CARDINALITY ?R ?I ?CARD) (AND (RANGE-MIN-CARDINALITY ?R ?I ?CARD) (RANGE-MAX-CARDINALITY ?R ?I ?CARD))) :AXIOMS (=>> (RANGE-CARDINALITY ?R ?I ?CARD) (= (CARDINALITY (THE-ROLESET ?R ?I)) ?CARD)) :AXIOMS (AND (FRAME-PREDICATE RANGE-CARDINALITY) (COMPUTED RANGE-CARDINALITY))) (DEFFUNCTION RANGE-MIN-CARDINALITY ((?R RELATION) ?I) :-> (?MINCARD INTEGER) :DOCUMENTATION \"Returns the strictest computable lower bound on the
cardinality of the set of fillers of the relation ?r applied to ?i.
(see the discussion for `range-cardinality-lower-bound').\" :<<= (OR (AND (SINGLE-VALUED ?R) (EXISTS ?V (HOLDS ?R ?I ?V)) (= ?MINCARD 1)) (MAXIMUM-VALUE (COLLECT-INTO-SET (SETOFALL ?M (OR (>= (CARDINALITY (THE-ROLESET ?R ?I)) ?M) (= ?M 0) (LENGTH-OF-LIST (FILLERS ?R ?I) ?M) (EXISTS ?SUBR (AND (SUBSET-OF ?SUBR ?R) (>= (CARDINALITY (THE-ROLESET ?SUBR ?I)) ?M)))))) ?MINCARD)) :AXIOMS (AND (FRAME-PREDICATE RANGE-MIN-CARDINALITY) (COMPUTED RANGE-MIN-CARDINALITY) (RELATION-SPECIALIST RANGE-MIN-CARDINALITY RANGE-MIN-CARDINALITY-SPECIALIST))) (DEFFUNCTION RANGE-MAX-CARDINALITY ((?R RELATION) ?I) :-> (?MAXCARD INTEGER) :DOCUMENTATION \"Returns the strictest computable upper bound on the
cardinality of the set of fillers of the relation ?r applied to ?i.
(see the discussion for `range-cardinality-lower-bound').\" :<<= (OR (AND (SINGLE-VALUED ?R) (EXISTS ?V (HOLDS ?R ?I ?V)) (= ?MAXCARD 1)) (MINIMUM-VALUE (COLLECT-INTO-SET (SETOFALL ?M (OR (=< (CARDINALITY (THE-ROLESET ?R ?I)) ?M) (AND (SINGLE-VALUED ?R) (= ?M 1)) (AND (EMPTY (THE-ROLESET ?R ?I)) (= ?M 0)) (AND (CLOSED ?R) (RANGE-MIN-CARDINALITY ?R ?I ?M)) (EXISTS ?SUPERR (AND (SUBSET-OF ?R ?SUPERR) (=< (CARDINALITY (THE-ROLESET ?SUPERR ?I)) ?M)))))) ?MAXCARD)) :AXIOMS (AND (FRAME-PREDICATE RANGE-MAX-CARDINALITY) (COMPUTED RANGE-MAX-CARDINALITY) (RELATION-SPECIALIST RANGE-MAX-CARDINALITY RANGE-MAX-CARDINALITY-SPECIALIST))) (DEFFUNCTION QUALIFIED-RANGE-MIN-CARDINALITY ((?R RELATION) ?I (?Q CONCEPT)) :-> (?CARD INTEGER) :DOCUMENTATION \"Function that returns the minimum cardinality of the set of
fillers of type ?q of the relation ?r applied to ?i.  NOT YET IMPLEMENTED.\" :AXIOMS (AND (FRAME-PREDICATE QUALIFIED-RANGE-MIN-CARDINALITY) (COMPUTED QUALIFIED-RANGE-MIN-CARDINALITY))) (DEFFUNCTION QUALIFIED-RANGE-MAX-CARDINALITY ((?R RELATION) ?I (?Q CONCEPT)) :-> (?CARD INTEGER) :DOCUMENTATION \"Function that returns the maximum cardinality of the set of
fillers of type ?q of the relation ?r applied to ?i.  NOT YET IMPLEMENTED.\" :AXIOMS (AND (FRAME-PREDICATE QUALIFIED-RANGE-MAX-CARDINALITY) (COMPUTED QUALIFIED-RANGE-MAX-CARDINALITY))) (DEFFUNCTION QUALIFIED-RANGE-CARDINALITY ((?R RELATION) ?I (?Q CONCEPT)) :-> (?CARD INTEGER) :DOCUMENTATION \"Function that returns the cardinality of the set of
fillers of type ?q of the relation ?r applied to ?i.  The cardinality function
returns a value only when the relations `qualified-range-min-cardinality' and
`qualified-range-max-cardinality' compute identical values, i.e., when the
best lower and upper bounds on the cardinality are equal.  Each of
these bounding functions employs a variety of rules to try and
compute a tight bound.  NOT YET IMPLEMENTED.\" :AXIOMS (AND (FRAME-PREDICATE QUALIFIED-RANGE-CARDINALITY) (COMPUTED QUALIFIED-RANGE-CARDINALITY))) (DEFFUNCTION NUMERIC-INTERVAL ((?X NUMERIC-SET)) :-> (?INTERVAL INTEGER-INTERVAL) :DOCUMENTATION \"Function that returns an interval representing
the range of allowable numeric values for its members.\" :=>> (SCALAR-INTERVAL ?INTERVAL)) (DEFRELATION NUMERIC-MINIMUM ((?R RELATION) ?I (?N NUMBER)) :DOCUMENTATION \"Relation that specifies a lower bound '?n' on any numeric
value that can belong to the set of fillers of the relation ?r applied to ?i.\" :<<=>> (>= (INTERVAL-LOWER-BOUND (NUMERIC-INTERVAL (THE-ROLESET ?R ?I))) ?N) :AXIOMS (FRAME-PREDICATE NUMERIC-MINIMUM)) (DEFRELATION NUMERIC-MAXIMUM ((?R RELATION) ?I (?N NUMBER)) :DOCUMENTATION \"Relation that specifies an upper bound '?n' on any numeric
value that can belong to the set of fillers of the relation ?r applied to ?i.\" :<<=>> (=< (INTERVAL-UPPER-BOUND (NUMERIC-INTERVAL (THE-ROLESET ?R ?I))) ?N) :AXIOMS (FRAME-PREDICATE NUMERIC-MAXIMUM)) (DEFFUNCTION INTERVAL-CACHE-OF ((?X NUMBER)) :-> (?B INTERVAL-CACHE) :DOCUMENTATION \"Binds an instance ?x of type NUMBER to a structure that
records its tightest lower and upper bounds.\" :AXIOMS (HIDDEN-RELATION INTERVAL-CACHE-OF)) (DEFRELATION DIRECT-SUBRELATION ((?R RELATION) (?SUB RELATION)) :DOCUMENTATION \"True iff ?sub is a direct subrelation of ?r; written
in set notation, ?sub < ?r, and there is no ?s such that ?sub < ?s < ?r.
This relation will generate bindings for at most one unbound argument.\" :AXIOMS (RELATION-SPECIALIST DIRECT-SUBRELATION RELATION-HIERARCHY-SPECIALIST)) (DEFRELATION DIRECT-SUPERRELATION ((?R RELATION) (?SUPER RELATION)) :DOCUMENTATION \"True iff ?super is a direct superrelation of ?r;
in set notation, ?super > ?r, and there is no ?s such that ?super > ?s > ?r.
This relation will generate bindings for at most one unbound argument.\" :AXIOMS (AND (INVERSE DIRECT-SUPERRELATION DIRECT-SUBRELATION) (RELATION-SPECIALIST DIRECT-SUPERRELATION RELATION-HIERARCHY-SPECIALIST))) (DEFRELATION SUBRELATION ((?R RELATION) (?SUB RELATION)) :DOCUMENTATION \"True iff ?sub is a subrelation of ?r; written in set
notation, ?sub =< ?r.  This relation will generate bindings for at most
one unbound argument.\" :AXIOMS (RELATION-SPECIALIST SUBRELATION RELATION-HIERARCHY-SPECIALIST)) (DEFRELATION SUPERRELATION ((?R RELATION) (?SUPER RELATION)) :DOCUMENTATION \"True iff ?super is a superrelation of ?r; written in set
notation, ?super >= ?r.  This relation will generate bindings for at most
one unbound argument.\" :AXIOMS (AND (INVERSE SUPERRELATION SUBRELATION) (RELATION-SPECIALIST SUPERRELATION RELATION-HIERARCHY-SPECIALIST))) (DEFRELATION PROPER-SUBRELATION ((?R RELATION) (?SUB RELATION)) :DOCUMENTATION \"True iff ?sub is a proper subrelation of ?r; written in
set notation, ?sub < ?r.  This relation will generate bindings for at most
one unbound argument.\" :AXIOMS (RELATION-SPECIALIST PROPER-SUBRELATION RELATION-HIERARCHY-SPECIALIST)) (DEFRELATION PROPER-SUPERRELATION ((?R RELATION) (?SUPER RELATION)) :DOCUMENTATION \"True iff ?super is a proper superrelation of ?r; written in
set notation, ?super > ?r.  This relation will generate bindings for at most
one unbound argument.\" :AXIOMS (AND (INVERSE PROPER-SUPERRELATION PROPER-SUBRELATION) (RELATION-SPECIALIST PROPER-SUPERRELATION RELATION-HIERARCHY-SPECIALIST))) (DEFRELATION EQUIVALENT-RELATION ((?R RELATION) (?EQUIV RELATION)) :DOCUMENTATION \"True if ?r is equivalent to ?equiv; written in set notation,
?r = ?equiv.  This relation will generate bindings for at most one unbound
argument.\" :AXIOMS (RELATION-SPECIALIST EQUIVALENT-RELATION RELATION-HIERARCHY-SPECIALIST)) (DEFFUNCTION UNION-OF ((?S1 COLLECTION) (?S2 COLLECTION)) :-> (?UNION SET) :DOCUMENTATION \"True if the union of the collections ?s1 and ?s2
equals ?union.\") (DEFFUNCTION + ((?X NUMBER) (?Y NUMBER)) :-> (?Z NUMBER) :DOCUMENTATION \"Function that adds two numbers.\") (ASSERT (AND (COMPUTED +) (RELATION-CONSTRAINT + PLUS-CONSTRAINT) (RELATION-SPECIALIST + CONSTRAINT-SPECIALIST))) (DEFFUNCTION - ((?X NUMBER) (?Y NUMBER)) :-> (?Z NUMBER) :DOCUMENTATION \"Function that subtracts two numbers.\") (ASSERT (AND (COMPUTED -) (RELATION-CONSTRAINT - MINUS-CONSTRAINT) (RELATION-SPECIALIST - CONSTRAINT-SPECIALIST))) (DEFFUNCTION * ((?X NUMBER) (?Y NUMBER)) :-> (?Z NUMBER) :DOCUMENTATION \"Function that multiplies two numbers.\") (ASSERT (AND (COMPUTED *) (RELATION-CONSTRAINT * TIMES-CONSTRAINT) (RELATION-SPECIALIST * CONSTRAINT-SPECIALIST))) (DEFFUNCTION / ((?X NUMBER) (?Y NUMBER)) :-> (?Z NUMBER) :DOCUMENTATION \"Function that divides two numbers.\") (ASSERT (AND (COMPUTED /) (RELATION-CONSTRAINT / DIVIDE-CONSTRAINT) (RELATION-SPECIALIST / CONSTRAINT-SPECIALIST))) (DEFFUNCTION SQRT ((?X NUMBER)) :-> (?Y NUMBER) :DOCUMENTATION \"Function that returns the positive square root:
?y = sqrt(?x).  For positive and negative roots see relation SQUARE-ROOT\" :AXIOMS (AND (COMPUTED SQRT) (RELATION-CONSTRAINT SQRT SQRT-CONSTRAINT) (RELATION-SPECIALIST SQRT CONSTRAINT-SPECIALIST))) (DEFRELATION SQUARE-ROOT ((?X NUMBER) (?Y NUMBER)) :DOCUMENTATION \"Relation that returns the positive and negative square roots:
?y = sqrt(?x).  For positive roots only see function SQRT.\" :AXIOMS (AND (COMPUTED SQUARE-ROOT) (RELATION-SPECIALIST SQUARE-ROOT SQUARE-ROOT-SPECIALIST))) (ASSERT (AND (HANDLES-REVERSE-POLARITY LESS-SPECIALIST) (HANDLES-REVERSE-POLARITY GREATER-SPECIALIST))) (DEFRELATION INEQUALITY ((?X NUMBER) (?Y NUMBER)) :DOCUMENTATION \"Abstract superrelation of inequality relations.\" :<<= (=< ?X ?Y) :<<= (>= ?X ?Y) :AXIOMS (ABSTRACT INEQUALITY)) (DEFRELATION < ((?X NUMBER) (?Y NUMBER)) :DOCUMENTATION \"True if ?x < ?y.\" :<<= (EXISTS ?Z (AND (< ?X ?Z) (=< ?Z ?Y))) :<<= (EXISTS ?Z (AND (=< ?X ?Z) (< ?Z ?Y)))) (ASSERT (AND (COMPUTED <) (RELATION-SPECIALIST < LESS-SPECIALIST) (RELATION-EVALUATOR < INEQUALITY-EVALUATOR))) (DEFRELATION =< ((?X NUMBER) (?Y NUMBER)) :DOCUMENTATION \"True if ?x <= ?y.\" :<<= (EXISTS ?Z (AND (=< ?X ?Z) (=< ?Z ?Y))) :<<= (< ?X ?Y)) (ASSERT (AND (COMPUTED =<) (RELATION-SPECIALIST =< LESS-SPECIALIST) (RELATION-EVALUATOR =< INEQUALITY-EVALUATOR))) (DEFRELATION > ((?X NUMBER) (?Y NUMBER)) :DOCUMENTATION \"True if ?x > ?y.\" :<<=>> (< ?Y ?X)) (ASSERT (AND (COMPUTED >) (RELATION-SPECIALIST > GREATER-SPECIALIST))) (DEFRELATION >= ((?X NUMBER) (?Y NUMBER)) :DOCUMENTATION \"True if ?x >= ?y.\" :<<=>> (=< ?Y ?X) :<<= (> ?X ?Y)) (ASSERT (AND (COMPUTED >=) (RELATION-SPECIALIST >= GREATER-SPECIALIST))) (DEFFUNCTION COLLECT-INTO-SET ((?C COLLECTION)) :-> (?L SET) :DOCUMENTATION \"Infer as many members of ?c as possible and
collect them into a set ?l.  For example, here is a rule
used to compute bindings for the `fillers' predicate:
	 
  (<= (fillers ?r ?i ?v)
      (and (bound-variables ?r ?i)
           (collect-into-set (setofall ?v (holds ?r ?i ?v)) ?members)))
	
When `?r' and `?i' are bound, the term `(setofall ?v (holds ?r ?i ?v))'
evaluates to a unary relation satisfied for each filler of the relation
in `?r' applied to the instance in `?i'.  `collect-into-set' causes
the extension of this (dynamically-defined) unary relation to be
computed.  Note the use of `bound-variables' to screen out unbound
variables before they are passed to the `setofall' predicate.\" :AXIOMS (RELATION-SPECIALIST COLLECT-INTO-SET COLLECT-INTO-SET-SPECIALIST)) (DEFRELATION LENGTH-OF-LIST ((?L COLLECTION) (?LENGTH INTEGER)) :DOCUMENTATION \"Computes the length of the list or set ?l.\" :AXIOMS (AND (COMPUTED LENGTH-OF-LIST) (RELATION-SPECIALIST LENGTH-OF-LIST LENGTH-OF-LIST-SPECIALIST) (SINGLE-VALUED LENGTH-OF-LIST))) (DEFRELATION MINIMUM-VALUE ((?L COLLECTION) (?MIN NUMBER)) :DOCUMENTATION \"Binds ?min to the minimum of the numbers in the list ?l.\" :AXIOMS (AND (RELATION-SPECIALIST MINIMUM-VALUE MINIMUM-OF-NUMBERS-SPECIALIST) (SINGLE-VALUED MINIMUM-VALUE))) (DEFRELATION MAXIMUM-VALUE ((?L COLLECTION) (?MAX NUMBER)) :DOCUMENTATION \"Binds ?max to the maximum of the numbers in the list ?l.\" :AXIOMS (AND (RELATION-SPECIALIST MAXIMUM-VALUE MAXIMUM-OF-NUMBERS-SPECIALIST) (SINGLE-VALUED MAXIMUM-VALUE))) (DEFRELATION SUM ((?L COLLECTION) (?SUM NUMBER)) :DOCUMENTATION \"Binds ?sum to the sum of the numbers in the list ?l.\" :AXIOMS (AND (RELATION-SPECIALIST SUM SUM-OF-NUMBERS-SPECIALIST) (SINGLE-VALUED SUM))) (DEFFUNCTION PROJECT-COLUMN ((?I INTEGER) (?C COLLECTION)) :-> (?L LIST) :DOCUMENTATION \"Project elements in column ?i (zero-based) of the tuples
of ?c and collect them into a list ?l. \" :AXIOMS (RELATION-SPECIALIST PROJECT-COLUMN PROJECT-COLUMN-SPECIALIST)) (DEFRELATION MEAN-VALUE ((?L COLLECTION) (?MEAN NUMBER)) :DOCUMENTATION \"Binds ?mean to the mean of the numbers in ?l.\" :AXIOMS (AND (COMPUTED MEAN-VALUE) (RELATION-SPECIALIST MEAN-VALUE MEAN-OF-NUMBERS-SPECIALIST) (SINGLE-VALUED MEAN-VALUE))) (DEFRELATION MEDIAN-VALUE ((?L COLLECTION) (?MEDIAN NUMBER)) :DOCUMENTATION \"Binds ?median to the median of the numbers in ?l.\" :AXIOMS (AND (COMPUTED MEDIAN-VALUE) (RELATION-SPECIALIST MEDIAN-VALUE MEDIAN-OF-NUMBERS-SPECIALIST) (SINGLE-VALUED MEDIAN-VALUE))) (DEFRELATION STANDARD-DEVIATION ((?L COLLECTION) (?SD NUMBER)) :DOCUMENTATION \"Binds ?sd to the standard deviation of the numbers in ?l.\" :AXIOMS (AND (COMPUTED STANDARD-DEVIATION) (RELATION-SPECIALIST STANDARD-DEVIATION STANDARD-DEVIATION-SPECIALIST) (SINGLE-VALUED STANDARD-DEVIATION))) (DEFRELATION VARIANCE ((?L COLLECTION) (?VARIANCE NUMBER)) :DOCUMENTATION \"Binds ?variance to the variance of the numbers in ?l.\" :AXIOMS (AND (COMPUTED VARIANCE) (RELATION-SPECIALIST VARIANCE VARIANCE-SPECIALIST) (SINGLE-VALUED VARIANCE))) (DEFFUNCTION STRING-CONCATENATE ((?X1 STRING) (?X2 STRING)) :-> (?X3 STRING) :DOCUMENTATION \"Concatenate strings ?x1 and ?x2 and bind ?x3 to the result.\" :AXIOMS (AND (COMPUTED STRING-CONCATENATE) (RELATION-CONSTRAINT STRING-CONCATENATE CONCATENATE-CONSTRAINT) (RELATION-SPECIALIST STRING-CONCATENATE CONSTRAINT-SPECIALIST))) (DEFFUNCTION SUBSTRING ((?S STRING) (?START INTEGER) (?END INTEGER)) :-> (?SUB STRING) :DOCUMENTATION \"Generate the substring of ?s starting at position ?start
(zero-based), ending just before position ?end and bind ?sub to the result.
This is the PowerLoom equivalent to the STELLA method `subsequence'.  In
addition, this function can be used to locate substrings in strings by
supplying values for ?s and ?sub and allowing ?start and ?end to be
bound by the function specialist.  In other words,
      (retrieve all (?start ?end) (substring \\\"foo\\\" ?start ?end \\\"o\\\"))
 ==>  ?start = 1, ?end = 2,
      ?start = 2, ?end = 3.\" :AXIOMS (AND (COMPUTED SUBSTRING) (RELATION-SPECIALIST SUBSTRING SUBSEQUENCE-SPECIALIST))) (DEFFUNCTION STRING-MATCH ((?PATTERN STRING) (?OBJECT THING) (?START INTEGER) (?END INTEGER)) :-> (?MATCH-POSITION INTEGER) :DOCUMENTATION \"Match ?pattern against ?object between ?start and ?end
(zero-based), and return the position of the first match or fail if no
match exists.  Supplying -1 for ?end indicates the end of ?object.  ?object
can be a named logic object or a string.  ?pattern will eventually allow
support regular expressions, currently it only handles string literals.
Apart from doing to-string coercion on ?object this is somewhat redundant,
since `substring' can generate ?start/?end pairs if its string and
substring arguments are bound.\" :AXIOMS (AND (COMPUTED STRING-MATCH) (RELATION-COMPUTATION STRING-MATCH STRING-MATCH-COMPUTATION) (RELATION-SPECIALIST STRING-MATCH COMPUTATION-SPECIALIST))) (DEFFUNCTION LENGTH ((?X THING)) :-> (?Z INTEGER) :DOCUMENTATION \"Function that returns the length of a string or a logical list.
NOT YET IMPLEMENTED FOR LISTS.\" :AXIOMS (AND (COMPUTED LENGTH) (RELATION-COMPUTATION LENGTH LENGTH-COMPUTATION) (RELATION-SPECIALIST LENGTH COMPUTATION-SPECIALIST))) (ASSERT (COMPUTED-PROCEDURE COMPUTATION-SPECIALIST)) (ASSERT (HANDLES-REVERSE-POLARITY COMPUTATION-SPECIALIST)) (ASSERT (COMPUTED-PROCEDURE CONSTRAINT-SPECIALIST)) (ASSERT (HANDLES-REVERSE-POLARITY CONSTRAINT-SPECIALIST)) (DEFFUNCTION ARITY ((?R RELATION)) :-> (?ARITY INTEGER) :DOCUMENTATION \"The number of arguments/domains of the relation '?r'.\") (ASSERT (AND (COMPUTED ARITY) (RELATION-COMPUTATION ARITY ARITY-COMPUTATION) (RELATION-SPECIALIST ARITY COMPUTATION-SPECIALIST))) (DEFRELATION VARIABLE-ARITY ((?R RELATION)) :DOCUMENTATION \"Asserts that the relation ?r can take a variable
number of arguments.\" :AXIOMS (CLOSED VARIABLE-ARITY)) (DEFCONCEPT BINARY-RELATION (?R RELATION) :DOCUMENTATION \"The class of binary relations.\" :<<=>> (ARITY ?R 2)) (DEFFUNCTION INVERSE ((?R BINARY-RELATION)) :-> ?INVERSERELATION :DOCUMENTATION \"Function that returns the inverse relation for ?r.
PERFORMANCE NOTE: for best results there should be only one `(inverse R I)'
assertion per relation pair `R' and `I'.  In that case `R' is viewed as the
canonical relation and `I' simply provides a different access mechanism to
the canonical relation.  In a logic-based KR paradigm inverse relations are
redundant and do not add anything that couldn't be represented or queried
without them, however, sometimes they can provide some extra convenience for
users.  Asserting `(inverse I R)' also will not cause an error but can degrade
backward inference performance due to the extra redundant rule that gets
generated.  If domain rules will be written in terms of both `R' and `I' (as
opposed to only `R'), `(inverse I R)' should be asserted also to get full
inferential connectivity between the two relations.\" :=>> (BINARY-RELATION ?INVERSERELATION) :=>> (<<=>> (HOLDS ?INVERSERELATION ?Y ?X) (HOLDS ?R ?X ?Y)) :AXIOMS (SYMMETRIC INVERSE)) (DEFRELATION DUPLICATE-FREE ((?C COLLECTION)) :DOCUMENTATION \"?c is duplicate-free if no two members
denote the same object.\") (DEFRELATION DIFFERENT (?X ?Y) :DOCUMENTATION \"True if no two arguments are the same.  This is equivalent to
`(duplicate-free (list-of ?x ?y ...))' but without the need to generate a
collection object.  The main use for this is to state and test pairwise
inequalities between N entities without having to generate O(N**2) statements.\" :VARIABLE-ARITY TRUE :COMPUTED TRUE :RELATION-SPECIALIST DIFFERENT-SPECIALIST) (DEFRELATION ORDERED ((?C COLLECTION)) :DOCUMENTATION \"?c is ordered if the ordering of its
members is significant.  Lists are ordered, while sets are not.\") (DEFRELATION COMMUTATIVE ((?R RELATION)) :DOCUMENTATION \"A relation ?r is commutative if its truth value is
invariant with any permutation of its arguments.\" :=>> (=> (BINARY-RELATION ?R) (SYMMETRIC ?R))) (DEFRELATION REFLEXIVE ((?R RELATION)) :DOCUMENTATION \"A binary relation ?r is reflexive if it is always true when
both of its arguments are identical.\" :=>> (BINARY-RELATION ?R) :=>> (FORALL ?X (HOLDS ?R ?X ?X))) (DEFRELATION IRREFLEXIVE ((?R RELATION)) :DOCUMENTATION \"A binary relation ?r is irreflexive if it is false when both
of its arguments are identical.\" :=>> (BINARY-RELATION ?R) :<=> (NOT (REFLEXIVE ?R)) :=>> (FORALL ?X (NOT (HOLDS ?R ?X ?X)))) (DEFRELATION SYMMETRIC ((?R RELATION)) :DOCUMENTATION \"A binary relation ?r is symmetric if it is commutative.\" :=>> (BINARY-RELATION ?R) :=>> (COMMUTATIVE ?R) :=>> (FORALL (?X ?Y) (<<= (HOLDS ?R ?X ?Y) (HOLDS ?R ?Y ?X)))) (DEFRELATION ANTISYMMETRIC ((?R RELATION)) :DOCUMENTATION \"A binary relation ?r is antisymmetric if whenever (?r ?x ?y)
is true (?r ?y ?x) is false unless ?x equals ?y.\" :=>> (BINARY-RELATION ?R) :<=> (NOT (SYMMETRIC ?R)) :=> (FORALL (?X ?Y) (=> (AND (HOLDS ?R ?X ?Y) (NOT (= ?X ?Y))) (NOT (?R ?Y ?X))))) (DEFRELATION TRANSITIVE ((?R RELATION)) :DOCUMENTATION \"A binary relation ?r is transitive if (?r ?x ?y)
and (?r ?y ?z) implies that (?r ?x ?z).  Note that functions cannot
be transitive, since their single-valuedness would not allow multiple
different values such as (?r ?x ?y) and (?r ?x ?z) due to the Unique
Names Assumption made by PowerLoom.\" :=>> (AND (BINARY-RELATION ?R) (NOT (FUNCTION ?R))) :=>> (=> (AND (?R ?X ?Y) (?R ?Y ?Z)) (?R ?X ?Z))) (DEFRELATION TOTAL ((?R FUNCTION)) :DOCUMENTATION \"True if the function '?r' is defined for all
combinations of inputs.  By default, functions are not assumed to
be total (unlike Prolog, which 'does' make such an assumption.
For example, if we define a two-argument function `foo' and then retrieve
its value applied to some random instances `a' and `b', we get nothing
back:
	 
   (deffunction foo (?x ?y) :-> ?z)
   (retrieve ?x (= ?x (foo a b)))
	
However, if we assert that `foo' is total, then we get a skolem back
when we execute the same retrieve:
	 
   (assert (total foo))
   (retrieve ?x (= ?x (foo a b)))
	
\") (DEFRELATION ABSTRACT ((?R RELATION)) :DOCUMENTATION \"True if there are no direct assertions made
to the relation ?r.\") (DEFFUNCTION CONCEPT-PROTOTYPE ((?C CONCEPT)) :-> ?I :DOCUMENTATION \"Function that, given a concept, returns a prototypical
instance that inherits all constraints that apply to any concept member,
and has no additional constraints.\" :AXIOMS (AND (RELATION-SPECIALIST CONCEPT-PROTOTYPE CONCEPT-PROTOTYPE-SPECIALIST) (TOTAL CONCEPT-PROTOTYPE)) :SYNONYM CLASS-PROTOTYPE) (DEFRULE \"'Instance-of' chained with 'subset-of' rule\" (<= (INSTANCE-OF ?X ?C2) (AND (BOUND-VARIABLES ?C2) (INSTANCE-OF ?X ?C1) (SUBSET-OF ?C1 ?C2)))) (DEFRULE \"'Not instance-of' rule\" (<= (NOT (INSTANCE-OF ?X ?C)) (AND (COLLECTION ?C) (CLOSED ?C) (FAIL (INSTANCE-OF ?X ?C))))) (DEFRULE \"Forward 'instance-of' rule\" (=> (INSTANCE-OF ?X ?C) (AND (CONCEPT ?C) (HOLDS ?C ?X))) :FORWARD? TRUE) (DEFCONCEPT USER-THING (?X) :DOCUMENTATION \"The class of user-defined things.\") (DEFRELATION CASE-MATCH ((?X THING) (?Y THING))) (DEFRULE CASE-MATCH-RULE (FORALL ((?X THING) (?Y THING)) (=> (= ?X ?Y) (CASE-MATCH ?X ?Y)))) (DEFRELATION SOFT-EQ ((?X THING) (?Y THING))) (DEFRULE SOFT-EQ-RULE (FORALL ((?X THING) (?Y THING)) (=> (= ?X ?Y) (SOFT-EQ ?X ?Y)))) (DEFFUNCTION CONTEXT-OF (?X) :-> (?C CONTEXT) :AXIOMS (AND (COMPUTED CONTEXT-OF) (RELATION-COMPUTATION CONTEXT-OF CONTEXT-OF-COMPUTATION) (RELATION-SPECIALIST CONTEXT-OF COMPUTATION-SPECIALIST))) (DEFRELATION DISJOINT ((?C1 COLLECTION) (?C2 COLLECTION)) :DOCUMENTATION \"True if the intersection of ?c1 and ?c2 is empty.\" :<<= (CHEAP-DISJOINT ?C1 ?C2)) (DEFRELATION MUTUALLY-DISJOINT-COLLECTION ((?S SET)) :DOCUMENTATION \"True if the members of ?s are pair-wise disjoint.  Used
most often to expresse disjointness constraints between concepts.  For
example
	 
   (mutually-disjoint-collection (setof MAN WOMAN))
	
states that the concepts MAN and WOMAN are disjoint.
\" :=>> (=> (AND (MEMBER-OF ?C1 ?S) (MEMBER-OF ?C2 ?S) (NOT (= ?C1 ?C2))) (DISJOINT ?C1 ?C2))) (DEFRELATION COVERING ((?C COLLECTION) (?COVER SET)) :DOCUMENTATION \"True if ?c is a subset of the union of all
collections in the set ?cover (see `disjoint-covering').\") (DEFRELATION DISJOINT-COVERING ((?C COLLECTION) (?DISJOINTCOVER SET)) :DOCUMENTATION \"True if ?c is covered by the collections in ?disjointCover
and if the member sets in ?disjointCover are mutually-disjoint.  For
example the concepts `Igneous-Rock', `Metamorphic-Rock', and
`Sedimentary-Rock' together form a disjoint covering of the concept `Rock'.\" :<<= (AND (COVERING ?C ?DISJOINTCOVER) (MUTUALLY-DISJOINT-COLLECTION ?DISJOINTCOVER))) (DEFRELATION CHEAP-DISJOINT ((?C1 COLLECTION) (?C2 COLLECTION)) :DOCUMENTATION \"Find proof of disjointness without using refutation.\" :<<= (AND (HAS-PARTITION-MEMBERSHIP ?C1) (HAS-PARTITION-MEMBERSHIP ?C2) (EXISTS (?PROPOSITION ?PARTITION1 ?PARTITION2) (AND (PARTITION-MEMBERSHIP ?C1 ?PROPOSITION ?PARTITION1) (PARTITION-MEMBERSHIP ?C2 ?PROPOSITION ?PARTITION2) (NOT (= ?PARTITION1 ?PARTITION2)))))) (DEFRELATION REFUTATION-DISJOINT ((?C1 CONCEPT) (?C2 CONCEPT)) :DOCUMENTATION \"Assume that an instance belongs to both ?c1 and ?c2
and look for a clash.\" :AXIOMS (RELATION-SPECIALIST REFUTATION-DISJOINT REFUTATION-DISJOINT-SPECIALIST)) (DEFRELATION HAS-PARTITION-MEMBERSHIP ((?C COLLECTION)) :DOCUMENTATION \"TRUE if one or more PARTITION-MEMBERSHIP tuples
exist with ?c as the first argument.  FALSE if none exists.
Unknown if a derivation of PARTITION-MEMBERSHIP tuples has not
occurred.  A specialist for this relation creates PARTITION-MEMBERSHIP
tuples as a side-effect of querying this predicate.\" :AXIOMS (AND (HIDDEN-RELATION HAS-PARTITION-MEMBERSHIP) (RELATION-SPECIALIST HAS-PARTITION-MEMBERSHIP HAS-PARTITION-MEMBERSHIP-SPECIALIST))) (DEFRELATION PARTITION-MEMBERSHIP ((?C COLLECTION) (?PROPOSITION PROPOSITION) (?PARTITION COLLECTION)) :DOCUMENTATION \"Caches the fact that ?partition is a partition of
a mutually-disjoint collection, and that ?c is a subset of ?partition.
Used to support rapid computation of pairwise disjointness.\" :AXIOMS (HIDDEN-RELATION PARTITION-MEMBERSHIP))) \"/PL-KERNEL-KB\")"
      "/PL-KERNEL-KB"))
    (/PL-KERNEL-KB/INITIALIZE-KERNEL-KB))))
