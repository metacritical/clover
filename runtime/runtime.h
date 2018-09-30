typedef enum {
      NIL,
      ENV,
      List,
      Symbol,
      String,
      Keyword,
      Boolean,
      Integer,
      Fraction,
      Character,
      EmptyList,
      Function,
} Type;

typedef struct Env { struct Obj *up; GHashTable *vars; } Env;

typedef struct Obj {
  Type type;

  union values {
    long int integer;
    double fraction;
    bool boolean;
    const char *string;
    const char *symbol;
    const char *keyword;
    char character;
    int *nil;

    //Function attributes and code.
    struct {
      struct Obj (*ptr)(void *root, Env *env, struct Obj *args);
      struct Obj *params;
      struct Obj *body;
      int arity;
    } fn;

    //Cons cell
    struct {
      struct Obj *first;
      struct Obj *rest;
    };

    //Environment for the datatype.
    Env *env;

  } Val;
} Obj;

Obj *clj_val();
