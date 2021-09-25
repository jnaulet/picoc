/* assert.h library for all systems */
#include <stdio.h>
#include "../interpreter.h"

/* assert calls */
void AssertAssert(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    /* FIXME: this is incompete, but will do for the moment */
    if(Param[0]->Val->Integer == 0){
        fprintf(stderr, "%s:%d: Assertion failed.\n",
                Parser->FileName, Parser->Line);
        
        PlatformExit(Parser->pc, 1);
    }
}
  
/* all assert functions */
struct LibraryFunction AssertFunctions[] =
{
     { AssertAssert, "void assert(int);" },
     { NULL, NULL }
};
