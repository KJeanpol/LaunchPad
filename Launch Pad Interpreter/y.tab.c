
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 15 "y.y"

	#include<stdio.h>
	//#include <iostream>
	#include <stdlib.h>
	#include <string>
	#include "lex.yy.c"
    #include "logic/Block.h"
    #include "logic/ArduinoSentence.h"
    #include "logic/Dow.h"
    #include "logic/ForTimes.h"
    #include "logic/Var.h"
    #include "logic/If.h"
    #include "logic/Decrease.h"
    #include "logic/Increase.h"
    #include "mainwindow.h"
    #include <fstream>


    //______________________________________________________________________//
	using namespace std;
	extern int yylineno;
	int yyerror(const char* s );
	long block = 0;
	std::vector<Block *> BlockList;
	std::vector<Var *> Vars;
	std::vector<Var *> Global;
    std::vector<string *> ProcI;
    string LastVar;
    int juego=1;
    MainWindow* MIDE;


//______________________________________________________________________//
bool inslocal(string pname, int pvalue){
    for(int i=0;i<Vars.size();i++){
        if(Vars[i]->getName().compare(pname)==0){
            return true;
        }
    }return false;
}

bool ins(string pname, int pvalue){
    Block* tmp= BlockList.back();
    while(tmp->hasBlock()){
        tmp=tmp->sentences.back();
    }tmp->setVal(pname, pvalue);
}

//______________________________________________________________________//
    bool cmp(string proc){
            cout<<"-----"<<BlockList.back()->sentences.size()<<endl;
            for(int i=0;i<BlockList.back()->sentences.size();i++){
                cout<<"Sentencia: "<< i<<BlockList.back()->sentences[i]->getName();
                if(BlockList.back()->sentences[i]->getName().compare(proc)==0){
                    BlockList.back()->sentences[i]->execute();
                    return true;
                }
            }return false;
}


//______________________________________________________________________//
    bool exists(string pvar){
        bool res=false;
        for(int i=0;i<Vars.size();i++){
            if(Vars[i]->getName().compare(pvar)==0){
                res=true;
                return res;
            }else{
                res=false;
            }
        }return res;
    }
        //______________________________________________________________________//
        void ejecutar(string pname){
            for(int i=0;i!=BlockList.back()->sentences.size();i++){
                if(BlockList.back()->sentences[i]->getName().compare(pname)){
                    BlockList.back()->sentences[i]->execute();
                    return;
                }
                MIDE->console("ERROR: El metodo no existe");
            }printf("ERROR: El metodo no existe");

        }
        //______________________________________________________________________//
                void addGlobals(){
                    for(int i=0;i!=Global.size();i++){
                        BlockList.back()->addVars(Global[i]);
                    }
                }
        //______________________________________________________________________//
          void addVariables(){
             Block* tmp= BlockList.back();
               while(tmp->hasBlock()){
                 tmp=tmp->sentences.back();
               } for(int i=0;i!=Vars.size();i++){
                    tmp->addVars(Vars[i]);
                 }

          }
    void setincremento(string pvar){
        Block* tmp= BlockList.back();
        while(tmp->hasBlock()){
            tmp=tmp->sentences.back();
        } tmp->setVarInc(pvar);

        }
    void setdecremento(string pvar){
        Block* tmp= BlockList.back();
        while(tmp->hasBlock()){
            tmp=tmp->sentences.back();
        } tmp->setVarDec(pvar);

    }
       //_______________________________________________________________________//
           void insertarFondo(Block *pblock){
               Block* tmp= BlockList.back();
               while(tmp->hasBlock()){
                    if(tmp->getName().compare("If")!=0){
                        tmp=tmp->sentences.back();
                    }else{
                        tmp->addSentence(pblock);
                        tmp->sentences.back()->setIDS(MIDE);
                        return;
                    }

               }tmp->addSentence(pblock); tmp->sentences.back()->setIDS(MIDE);
           }

           void setBoton(string pvar){
               Block* tmp= BlockList.back();
               while(tmp->hasBlock()){
                    if(tmp->getName().compare("If")!=0){
                        tmp=tmp->sentences.back();
                    }else{
                        tmp->boton=pvar;
                        return;
                    }

               }tmp->boton=pvar;
           }
           void setFila(string pvar){
               Block* tmp= BlockList.back();
               while(tmp->hasBlock()){
                    if(tmp->getName().compare("If")!=0){
                        tmp=tmp->sentences.back();
                    }else{
                        tmp->fil=pvar;
                        return;
                    }

               }tmp->fil=pvar;
           }
           void setCol(string pvar){
               Block* tmp= BlockList.back();
               while(tmp->hasBlock()){
                    if(tmp->getName().compare("If")!=0){
                        tmp=tmp->sentences.back();
                    }else{
                        tmp->col=pvar;
                        return;
                    }

               }tmp->col=pvar;
           }
           void setRed(int pvar){
               Block* tmp= BlockList.back();
               while(tmp->hasBlock()){
                    if(tmp->getName().compare("If")!=0){
                        tmp=tmp->sentences.back();
                    }else{
                        tmp->red=pvar;
                        return;
                    }

               }tmp->red=pvar;
           }
           void setGreen(int pvar){
               Block* tmp= BlockList.back();
               while(tmp->hasBlock()){
                    if(tmp->getName().compare("If")!=0){
                        tmp=tmp->sentences.back();
                    }else{
                        tmp->green=pvar;
                        return;
                    }

               }tmp->green=pvar;
           }
           void setBlue(int pvar){
               Block* tmp= BlockList.back();
               while(tmp->hasBlock()){
                    if(tmp->getName().compare("If")!=0){
                        tmp=tmp->sentences.back();
                    }else{
                        tmp->blue=pvar;
                        return;
                    }

               }tmp->blue=pvar;
           }

           void setNames(string pname){
                          Block* tmp= BlockList.back();
                          while(tmp->hasBlock()){
                               tmp=tmp->sentences.back();
                          }tmp->setName(pname);
                      }

        //_______________________________________________________________________//
        void addLeftIf(string pval){
            Block* tmp= BlockList.back();
            while(tmp->hasBlock()){
                tmp=tmp->sentences.back();
            }tmp->setVal1(pval);
        }
        void addRightIf(int pval){
            Block* tmp= BlockList.back();
            while(tmp->hasBlock()){
               tmp=tmp->sentences.back();
                }tmp->setVal2(pval);
        }
void setValor1(int pval){
    Block* tmp= BlockList.back();
    while(tmp->hasBlock()){
        tmp=tmp->sentences.back();
    }tmp->setValor1(pval);
}
void setValor2(int pval){
    Block* tmp= BlockList.back();
    while(tmp->hasBlock()){
        tmp=tmp->sentences.back();
    }tmp->setValor2(pval);
}
void setGame(){
    if(BlockList.back()->sentences.back()->name.find("2")<BlockList.back()->sentences.back()->name.size()){
        BlockList.back()->sentences.back()->setjuego(2);
    }else if(BlockList.back()->sentences.back()->name.find("3")<BlockList.back()->sentences.back()->name.size()){
        BlockList.back()->sentences.back()->setjuego(3);
    }else if(BlockList.back()->sentences.back()->name.find("4")<BlockList.back()->sentences.back()->name.size()){
        BlockList.back()->sentences.back()->setjuego(4);
    }else{
        BlockList.back()->sentences.back()->setjuego(1);
    }
}



int interprete(MainWindow *IDE){
   ifstream ifs("/home/joserivera/Documents/IDE-GUI v6/test.txt");
                string content( (istreambuf_iterator<char>(ifs) ),
                                 (istreambuf_iterator<char>()    ) );
                ifs.close();
                yy_scan_string(content.c_str());
//                IDE->sendMessage("AAA");
                MIDE=IDE;
                yyparse();
                return 0;
}

//void send(const QString &message){

//}




/* Line 189 of yacc.c  */
#line 341 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DEFINIR = 258,
     INCREMENTO = 259,
     DECREMENTO = 260,
     INI_VARIABLE = 261,
     VARIABLE = 262,
     COMENTARIO_I = 263,
     COMENTARIO_F = 264,
     ENCENDER_TODOS = 265,
     APAGAR_TODOS = 266,
     ENCENDER = 267,
     APAGAR = 268,
     ENCENDER_SONIDO = 269,
     APAGAR_SONIDO = 270,
     INI_LOOP = 271,
     FIN_LOOP = 272,
     INI_FOR = 273,
     FIN_FOR = 274,
     IN = 275,
     STEP = 276,
     EXIT = 277,
     TIMES = 278,
     INI_IF = 279,
     FIN_IF = 280,
     ELSE = 281,
     ELSE_IF = 282,
     THEN = 283,
     DECLARAR_PROCEDIMIENTO = 284,
     INI_PROCEDIMIENTO = 285,
     FIN_PROCEDIMIENTO = 286,
     IGUAL = 287,
     TIEMPO = 288,
     BOTON = 289,
     VTIEMPO = 290,
     PUNTO_COMA = 291,
     CALL = 292,
     PARENTESIS_A = 293,
     PARENTESIS_C = 294,
     COMA = 295,
     NOMBRE = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 424 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  198

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    12,    13,    14,    21,    22,
      23,    29,    34,    36,    39,    41,    42,    43,    49,    50,
      56,    57,    58,    66,    69,    71,    73,    75,    77,    79,
      81,    83,    85,    87,    89,    91,    93,    94,    95,    96,
      97,    98,    99,   100,   123,   124,   125,   126,   127,   141,
     142,   143,   144,   145,   159,   160,   161,   162,   163,   177,
     178,   179,   187,   188,   189,   197,   198,   199,   200,   216,
     217,   225,   226,   227,   228,   241,   242,   243,   253,   255,
     258,   260,   261,   262,   273,   275,   277,   279,   280
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    -1,    52,    44,    53,    45,   104,
      61,    -1,    -1,    -1,     3,     7,    47,    35,    48,    36,
      -1,    -1,    -1,     7,    50,    35,    51,    36,    -1,     8,
      41,     9,    52,    -1,    54,    -1,    46,    53,    -1,    54,
      -1,    -1,    -1,     4,     7,    56,     4,    36,    -1,    -1,
       5,     7,    57,     5,    36,    -1,    -1,    -1,     6,     7,
      59,    32,   107,    60,    36,    -1,    62,    61,    -1,    54,
      -1,    63,    -1,    49,    -1,    75,    -1,    84,    -1,    87,
      -1,    58,    -1,    90,    -1,    94,    -1,    96,    -1,    55,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    64,    38,   107,    65,    40,   107,    66,    40,   107,
      67,    40,   107,    68,    40,   107,    69,    40,   107,    70,
      39,    36,    -1,    -1,    -1,    -1,    -1,    10,    71,    38,
     107,    72,    40,   107,    73,    40,   107,    74,    39,    36,
      -1,    -1,    -1,    -1,    -1,    11,    76,    38,   107,    77,
      40,   107,    78,    40,   107,    79,    39,    36,    -1,    -1,
      -1,    -1,    -1,    13,    80,    38,   107,    81,    40,   107,
      82,    40,   107,    83,    39,    36,    -1,    -1,    -1,    14,
      85,    38,   107,    86,    39,    36,    -1,    -1,    -1,    15,
      88,    38,   107,    89,    39,    36,    -1,    -1,    -1,    -1,
      16,     7,    91,    20,   107,    92,    21,   107,    93,    61,
      22,    36,    61,    17,    36,    -1,    -1,    18,   107,    95,
      23,    61,    19,    36,    -1,    -1,    -1,    -1,    24,    97,
       7,    98,    32,   107,    99,    28,    61,   100,    25,    36,
      -1,    -1,    -1,    27,     7,   101,    32,   107,   102,    36,
      61,   100,    -1,   103,    -1,    26,    61,    -1,    54,    -1,
      -1,    -1,    29,     7,   105,    30,    61,    29,     7,    31,
     106,   104,    -1,    54,    -1,     7,    -1,    33,    -1,    -1,
      37,     7,   109,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   340,   340,   340,   340,   342,   342,   342,   344,   344,
     344,   346,   347,   349,   350,   352,   354,   354,   355,   355,
     358,   358,   358,   360,   361,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   376,   376,   376,   376,
     376,   376,   376,   376,   377,   377,   377,   377,   377,   380,
     380,   380,   380,   380,   381,   381,   381,   381,   381,   383,
     383,   383,   385,   385,   385,   388,   388,   388,   388,   391,
     391,   393,   393,   393,   393,   396,   396,   396,   397,   399,
     400,   402,   402,   402,   403,   405,   406,   408,   408
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINIR", "INCREMENTO", "DECREMENTO",
  "INI_VARIABLE", "VARIABLE", "COMENTARIO_I", "COMENTARIO_F",
  "ENCENDER_TODOS", "APAGAR_TODOS", "ENCENDER", "APAGAR",
  "ENCENDER_SONIDO", "APAGAR_SONIDO", "INI_LOOP", "FIN_LOOP", "INI_FOR",
  "FIN_FOR", "IN", "STEP", "EXIT", "TIMES", "INI_IF", "FIN_IF", "ELSE",
  "ELSE_IF", "THEN", "DECLARAR_PROCEDIMIENTO", "INI_PROCEDIMIENTO",
  "FIN_PROCEDIMIENTO", "IGUAL", "TIEMPO", "BOTON", "VTIEMPO", "PUNTO_COMA",
  "CALL", "PARENTESIS_A", "PARENTESIS_C", "COMA", "NOMBRE", "$accept",
  "PRINCIPIO", "$@1", "$@2", "DEFINIR_VAR", "$@3", "$@4", "DEFINIR_LOCAL",
  "$@5", "$@6", "COMENTARIO", "HOJA_D", "EPSILON", "MODIFICAR_VAR", "$@7",
  "$@8", "INSTANCIAR_VAR", "$@9", "$@10", "EXPRESION", "EXPRESION_SIMPLE",
  "TURNON", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18",
  "$@19", "$@20", "$@21", "TURNOFF", "$@22", "$@23", "$@24", "$@25",
  "$@26", "$@27", "$@28", "$@29", "SOUNDON", "$@30", "$@31", "SOUNDOFF",
  "$@32", "$@33", "DOW_LOOP", "$@34", "$@35", "$@36", "FOR_LOOP", "$@37",
  "IF_SENTENCIA", "$@38", "$@39", "$@40", "ELSEIF", "$@41", "$@42",
  "ELSEFIN", "PROCEDIMIENTO", "$@43", "$@44", "PARAMETRO",
  "INVOKE_PROCEDIMIENTO", "$@45", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    45,    43,    47,    48,    46,    50,    51,
      49,    52,    52,    53,    53,    54,    56,    55,    57,    55,
      59,    60,    58,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    64,    65,    66,    67,
      68,    69,    70,    63,    71,    72,    73,    74,    63,    76,
      77,    78,    79,    75,    80,    81,    82,    83,    75,    85,
      86,    84,    88,    89,    87,    91,    92,    93,    90,    95,
      94,    97,    98,    99,    96,   101,   102,   100,   100,   103,
     103,   105,   106,   104,   104,   107,   107,   109,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     6,     0,     0,     6,     0,     0,
       5,     4,     1,     2,     1,     0,     0,     5,     0,     5,
       0,     0,     7,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,    13,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    13,     0,
       0,     7,     0,     0,     7,     0,     0,     0,    15,     0,
       7,     0,     0,     0,    12,     0,     0,     9,     1,     2,
       1,     0,     0,    10,     1,     1,     1,     0,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     0,     2,    12,     0,     1,    15,    15,     0,
      15,     3,    14,    11,     5,    13,    15,     0,     0,    84,
      15,     6,    81,     0,     0,     0,     8,    44,    49,    36,
      54,    59,    62,     0,     0,    71,     0,    26,    24,    34,
      30,     4,    15,    25,    27,    28,    29,    31,    32,    33,
      35,     0,     0,    16,    18,    20,     0,     0,     0,     0,
       0,     0,     0,    65,    85,    86,    69,     0,    87,    23,
       7,    15,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,     0,
       0,    45,    50,    37,    55,    60,    63,     0,    15,     0,
      88,     0,    17,    19,    21,    10,     0,     0,     0,     0,
       0,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    82,    22,    46,    51,
      38,    56,    61,    64,     0,    70,     0,    15,     0,     0,
       0,     0,    67,    15,    83,     0,     0,     0,     0,    15,
      15,    47,    52,    39,    57,     0,    15,     0,    80,     0,
      78,     0,     0,     0,     0,     0,    79,    75,     0,     0,
       0,     0,     0,    15,     0,    74,    48,    53,    40,    58,
       0,     0,     0,     0,    76,     0,    68,     0,    41,    15,
       0,    15,     0,    77,    42,     0,     0,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    16,    10,    17,    51,    37,    56,    90,
       3,    11,    38,    39,    72,    73,    40,    74,   116,    41,
      42,    43,    59,   108,   140,   163,   182,   190,   195,    57,
     106,   138,   161,    44,    58,   107,   139,   162,    60,   109,
     141,   164,    45,    61,   110,    46,    62,   111,    47,    82,
     123,   149,    48,    83,    49,    67,    99,   136,   159,   174,
     187,   160,    20,    52,   137,    66,    50,    85
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int8 yypact[] =
{
      -3,   -35,     9,   -93,   -93,     2,   -93,    10,    -3,     5,
      10,   -93,   -93,   -93,   -93,   -93,   -15,   -20,    17,   -93,
      30,   -93,   -93,    18,    19,    20,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,    22,    -5,   -93,    25,   -93,   -93,   -93,
     -93,   -93,    30,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -19,     3,   -93,   -93,   -93,    12,    11,    13,    14,
      15,    26,    27,   -93,   -93,   -93,   -93,    31,   -93,   -93,
     -93,    30,    46,    50,    34,   -93,    -5,    -5,    -5,    -5,
      -5,    -5,    38,    40,   -93,    32,    41,    33,    35,    -5,
      36,   -93,   -93,   -93,   -93,   -93,   -93,    -5,    30,    42,
     -93,    66,   -93,   -93,   -93,   -93,    37,    39,    43,    44,
      47,    52,   -93,    56,    -5,    49,    45,    -5,    -5,    -5,
      -5,    57,    58,    61,    59,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,    -5,   -93,    64,   -15,    60,    63,
      65,    67,   -93,    30,   -93,    -5,    -5,    -5,    -5,    30,
     -23,   -93,   -93,   -93,   -93,    74,    30,    71,   -93,    72,
     -93,    62,    70,    76,    73,    68,   -93,   -93,    75,    78,
      81,    -5,    82,    30,    53,   -93,   -93,   -93,   -93,   -93,
      89,    -5,    79,    84,   -93,    -5,   -93,    85,   -93,    30,
      86,   -23,    -5,   -93,   -93,    83,    88,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
      90,   100,     0,   -93,   -93,   -93,   -93,   -93,   -93,   -41,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -92,   -93,
     -93,   -93,   -12,   -93,   -93,   -58,   -93,   -93
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       4,    69,    64,   156,   157,     1,     5,    12,     4,     6,
      12,     8,    14,     9,    18,    21,    19,    70,    91,    92,
      93,    94,    95,    96,    22,    53,    54,    55,    65,    63,
      86,   104,    68,    71,    23,    24,    25,    26,    84,   112,
      27,    28,    29,    30,    31,    32,    33,    75,    34,    76,
      87,    77,    78,    79,    35,    88,   125,   113,    97,   128,
     129,   130,   131,    98,    80,    81,    89,    36,   100,   102,
     101,   103,   105,   115,   114,   124,   142,   117,   167,   118,
     126,   127,   134,   119,   120,   181,   121,   151,   152,   153,
     154,   122,   143,   132,   133,   135,   165,   168,    13,   193,
     145,   169,   150,   146,   173,   147,   183,   148,   155,   170,
      15,   175,   172,   178,   176,   166,   171,   177,   179,   185,
     186,   189,   196,   184,   197,   144,   192,   188,     0,     0,
       0,     0,   180,     0,   194,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,     0,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158
};

static const yytype_int16 yycheck[] =
{
       0,    42,     7,    26,    27,     8,    41,     7,     8,     0,
      10,     9,     7,     3,    29,    35,    16,    36,    76,    77,
      78,    79,    80,    81,     7,     7,     7,     7,    33,     7,
      71,    89,     7,    30,     4,     5,     6,     7,     7,    97,
      10,    11,    12,    13,    14,    15,    16,    35,    18,    38,
       4,    38,    38,    38,    24,     5,   114,    98,    20,   117,
     118,   119,   120,    23,    38,    38,    32,    37,    36,    36,
      29,    36,    36,     7,    32,    19,   134,    40,     7,    40,
      31,    36,    21,    40,    40,    32,    39,   145,   146,   147,
     148,    39,    28,    36,    36,    36,    22,    25,     8,   191,
      40,    39,   143,    40,    36,    40,    17,    40,   149,    39,
      10,    36,    39,   171,    36,   156,    40,    36,    36,    40,
      36,    36,    39,   181,    36,   137,    40,   185,    -1,    -1,
      -1,    -1,   173,    -1,   192,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    43,    52,    54,    41,     0,    44,     9,     3,
      46,    53,    54,    52,     7,    53,    45,    47,    29,    54,
     104,    35,     7,     4,     5,     6,     7,    10,    11,    12,
      13,    14,    15,    16,    18,    24,    37,    49,    54,    55,
      58,    61,    62,    63,    75,    84,    87,    90,    94,    96,
     108,    48,   105,     7,     7,     7,    50,    71,    76,    64,
      80,    85,    88,     7,     7,    33,   107,    97,     7,    61,
      36,    30,    56,    57,    59,    35,    38,    38,    38,    38,
      38,    38,    91,    95,     7,   109,    61,     4,     5,    32,
      51,   107,   107,   107,   107,   107,   107,    20,    23,    98,
      36,    29,    36,    36,   107,    36,    72,    77,    65,    81,
      86,    89,   107,    61,    32,     7,    60,    40,    40,    40,
      40,    39,    39,    92,    19,   107,    31,    36,   107,   107,
     107,   107,    36,    36,    21,    36,    99,   106,    73,    78,
      66,    82,   107,    28,   104,    40,    40,    40,    40,    93,
      61,   107,   107,   107,   107,    61,    26,    27,    54,   100,
     103,    74,    79,    67,    83,    22,    61,     7,    25,    39,
      39,    40,    39,    36,   101,    36,    36,    36,   107,    36,
      61,    32,    68,    17,   107,    40,    36,   102,   107,    36,
      69,    61,    40,   100,   107,    70,    39,    36
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 340 "y.y"
    {BlockList.push_back(new Block());BlockList.back()->setIDS(MIDE);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 340 "y.y"
    {addVariables();Vars.clear();setNames("Block");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 342 "y.y"
    {Vars.push_back(new Var(yytext));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 342 "y.y"
    {Vars.back()->setType(yytext);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 344 "y.y"
    {Vars.push_back(new Var(yytext));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 344 "y.y"
    {Vars.back()->setType(yytext);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 354 "y.y"
    {insertarFondo((new Increase()));setNames("Incremento");setincremento(yytext); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 355 "y.y"
    {insertarFondo((new Decrease()));setNames("Decremento");setdecremento(yytext);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 358 "y.y"
    {LastVar=yytext;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 358 "y.y"
    {if(!inslocal(LastVar,atoi(yytext))) ins(LastVar,atoi(yytext));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 376 "y.y"
    {insertarFondo(new ArduinoSentence());setNames("TurnOn");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 376 "y.y"
    {setBoton(yytext);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 376 "y.y"
    {setCol(yytext);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 376 "y.y"
    {setFila(yytext);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 376 "y.y"
    {setRed(atoi(yytext));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 376 "y.y"
    {setGreen(atoi(yytext));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 376 "y.y"
    {setBlue(atoi(yytext));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 377 "y.y"
    {insertarFondo(new ArduinoSentence());setNames("TurnON");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 377 "y.y"
    {setBoton(yytext);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 377 "y.y"
    {setCol(yytext);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 377 "y.y"
    {setFila(yytext);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 380 "y.y"
    {insertarFondo(new ArduinoSentence());setNames("TurnOFF");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 380 "y.y"
    {setBoton(yytext);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 380 "y.y"
    {setCol(yytext);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 380 "y.y"
    {setFila(yytext);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 381 "y.y"
    {insertarFondo(new ArduinoSentence());setNames("TurnOff");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 381 "y.y"
    {setBoton(yytext);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 381 "y.y"
    {setCol(yytext);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 381 "y.y"
    {setFila(yytext);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 383 "y.y"
    {insertarFondo(new ArduinoSentence());setNames("SoundOn");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 383 "y.y"
    {setBoton(yytext);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 385 "y.y"
    {insertarFondo(new ArduinoSentence());setNames("SoundOff");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 385 "y.y"
    {setBoton(yytext);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 388 "y.y"
    {insertarFondo((new Dow(yytext)));setNames("Dow");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 388 "y.y"
    {setValor1(atoi(yytext));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 388 "y.y"
    {setValor2(atoi(yytext));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 391 "y.y"
    {insertarFondo((new ForTimes(atoi(yytext))));setNames("For");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 393 "y.y"
    {insertarFondo((new If())); setNames(yytext);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 393 "y.y"
    {addLeftIf(yytext);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 393 "y.y"
    {addRightIf(atoi(yytext));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 396 "y.y"
    {addLeftIf(yytext);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 396 "y.y"
    {addRightIf(atoi(yytext));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 402 "y.y"
    {BlockList.back()->addSentence(new Block()); BlockList.back()->sentences.back()->setName(yytext); setGame();;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 402 "y.y"
    {addVariables(); Vars.clear();;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 405 "y.y"
    {;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 406 "y.y"
    {;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 408 "y.y"
    {printf(yytext);if(cmp(yytext))printf("SI");;}
    break;



/* Line 1455 of yacc.c  */
#line 2121 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 410 "y.y"

int yyerror(const char* s ) {
	//yyerrok;
	//cout<<yytext<<endl;
	//fprintf(stderr,"%s: %s at line %d\n", s, yytext,yylineno);
	std::cout<<"Error de sintaxis en linea: "<<yylineno;
    yyclearin;
    QString num= QString::number(yylineno);
    QString error= "Syntax error line: " + num;
    MIDE->console(error);
    yylineno=1;

	return 0;
}

