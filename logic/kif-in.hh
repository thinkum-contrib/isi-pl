// kif-in.hh

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | 
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

// Class headers:
class Variable_Token;

// Function signatures:
boolean question_mark_symbolP(Symbol* symbol);
Symbol* remove_question_mark(Symbol* qmsymbol);
Generalized_Symbol* kif_symbol_to_stella_symbol(Symbol* symbol);
Symbol* kif_variable_to_stella_variable(Object* variable);
boolean kif_variable_declarationP(Object* tree);
Cons* listify_kif_variable_declarations(Object* tree);
Cons* kif_variable_declaration_to_stella(Object* tree);
Cons* kif_variable_declarations_to_stella(Cons* tree);
Cons* kif_the_to_stella_the_only(Cons* tree);
Cons* kif_setofall_to_stella_setofall(Cons* tree);
Cons* kif_kappa_to_stella_kappa(Cons* tree);
Cons* kif_implies_to_stella_implies(Cons* tree);
Cons* kif_exists_to_stella_exists(Cons* tree);
Cons* kif_forall_to_stella_forall(Cons* tree);
Cons* kif_predicate_to_stella_predicate(Cons* tree);
Symbol* kif_operator_to_internal_stella(Symbol* renamed_Operator);
Symbol* internal_stella_operator_to_kif(Symbol* renamed_Operator);
void change_kif_expressions_to_stella_expressions(Cons* expressions, boolean termP);
Object* kif_sentence_to_untyped_stella_sentence(Object* tree);
Object* kif_term_to_untyped_stella_term(Object* tree);
Object* kif_expression_to_untyped_stella_expression(Object* tree);
Variable_Token* new_variable_token();
Object* access_variable_token_slot_value(Variable_Token* self, Symbol* slotname, Object* value, boolean setvalueP);
boolean tokenP(Object* object);
Variable_Token* introduce_variable_token(Symbol* symbol, Object* typetree);
Variable_Token* find_variable_token(Symbol* symbol);
void clear_token_tables();
Class* compute_term_class(Object* term);
Slot* compute_term_slot(Cons* term);
void substitute_tokens_into_terms(Cons* termlist);
void substitute_tokens_into_variable_declarations(Cons* declordecls);
void pop_tokens_in_declarations(Cons* declordecls);
void substitute_in_variable_tokens(Cons* tree);
boolean read_OtypebecamenarrowerPO();
boolean write_OtypebecamenarrowerPO(boolean value);
void push_visible_tokens(Cons* declordecls);
void pop_visible_tokens(Cons* declordecls);
void block_visible_tokens();
void unblock_visible_tokens();
boolean all_tokens_blockedP();
boolean token_is_visibleP(Variable_Token* token);
void update_token_type(Variable_Token* token, Surrogate* type);
void infer_variable_types_within_terms(Cons* termlist);
void infer_types_in_predication(Cons* predication);
void infer_types_in_isa_term(Cons* isaterm);
void infer_types_in_in_term(Cons* interm);
void help_infer_equal_terms(Object* term1, Object* term2);
void infer_types_in_equal_term(Cons* eqterm);
void help_infer_variable_types(Object* tree);
void infer_variable_types(Cons* tree);
Object* substitute_out_variable_tokens(Object* tree);
void untyped_stella_tree_to_typed_stella(Cons* tree);
Object* convert_to_prefix_proposition_tree(Object* tree);
Cons* infix_to_prefix_quantification_tree(Cons* tree);
Object* access_prefix_quantification_clause(Cons* prefixquantificationtree, Symbol* clausename, boolean extractP);
Object* extract_where_clause(Cons* prefixquantificationtree);
Object* extract_always_clause(Cons* prefixquantificationtree);
Object* lookup_where_clause(Cons* prefixquantificationtree);
Object* lookup_always_clause(Cons* prefixquantificationtree);
Keyword* read_Ologic_dialectO();
Keyword* write_Ologic_dialectO(Keyword* value);
Object* standardize_logical_parse_tree(Object* tree);
Keyword* in_dialect(Object* dialect);
void startup_kif_in();

// Global declarations:
extern Symbol* SYM_KIF_IN_PARSE_TREE;
extern Symbol* SYM_KIF_IN_ISA;
extern Surrogate* SGT_KIF_IN_UNKNOWN;
extern Symbol* SYM_KIF_IN_COMMA;
extern Symbol* SYM_KIF_IN_THE_ONLY;
extern Symbol* SYM_KIF_IN_WHERE;
extern Symbol* SYM_KIF_IN_TRUE;
extern Symbol* SYM_KIF_IN_AND;
extern Symbol* SYM_KIF_IN_le;
extern Symbol* SYM_KIF_IN_IMPLIES;
extern Symbol* SYM_KIF_IN_ALWAYS;
extern Property_List* KIF_OPERATOR_TO_INTERNAL_STELLA_TABLE;
extern Symbol* SYM_KIF_IN_i;
extern Symbol* SYM_KIF_IN_PLUS;
extern Symbol* SYM_KIF_IN__;
extern Symbol* SYM_KIF_IN_MINUS;
extern Symbol* SYM_KIF_IN_o;
extern Symbol* SYM_KIF_IN_TIMES;
extern Symbol* SYM_KIF_IN_s;
extern Symbol* SYM_KIF_IN_DIVIDE;
extern Symbol* SYM_KIF_IN_g;
extern Symbol* SYM_KIF_IN_GREATER_THANp;
extern Symbol* SYM_KIF_IN_ge;
extern Symbol* SYM_KIF_IN_GREATER_OR_EQUALp;
extern Symbol* SYM_KIF_IN_l;
extern Symbol* SYM_KIF_IN_LESS_THANp;
extern Symbol* SYM_KIF_IN_el;
extern Symbol* SYM_KIF_IN_LESS_OR_EQUALp;
extern Symbol* SYM_KIF_IN_SUBSET;
extern Symbol* SYM_KIF_IN_SUBSET_OF;
extern Symbol* SYM_KIF_IN_MEMBER;
extern Symbol* SYM_KIF_IN_OR;
extern Symbol* SYM_KIF_IN_NOT;
extern Symbol* SYM_KIF_IN_eg;
extern Symbol* SYM_KIF_IN_EXISTS;
extern Symbol* SYM_KIF_IN_FORALL;
extern Symbol* SYM_KIF_IN_IN;
extern Symbol* SYM_KIF_IN_THE;
extern Symbol* SYM_KIF_IN_SETOFALL;
extern Symbol* SYM_KIF_IN_KAPPA;
extern Symbol* SYM_KIF_IN_TOKEN_NAME;
extern Symbol* SYM_KIF_IN_TOKEN_TYPE;
extern Surrogate* SGT_KIF_IN_VARIABLE_TOKEN;
extern List* oVARIABLE_TOKENSo;
extern Key_Value_List* oVARIABLE_TOKEN_STACKo;
extern Symbol* SYM_KIF_IN_FALSE;
extern Symbol* SYM_KIF_IN_AS;
extern boolean oTYPEBECAMENARROWERpo;
extern Symbol* SYM_KIF_IN_oTYPEBECAMENARROWERpo;
extern List* oVISIBLE_TOKEN_STACKo;
extern Variable_Token* BLOCKING_TOKEN;
extern Symbol* SYM_KIF_IN_e;
extern Keyword* oLOGIC_DIALECTo;
extern Keyword* KWD_KIF_IN_KIF;
extern Symbol* SYM_KIF_IN_oLOGIC_DIALECTo;
extern Keyword* KWD_KIF_IN_STELLA;
extern Keyword* KWD_KIF_IN_PREFIX_STELLA;
extern Keyword* KWD_KIF_IN_SQL;

class Variable_Token : public Object {
public:
  Symbol* token_name;
  Standard_Object* token_type;
public:
  virtual Surrogate* primary_type();
};

