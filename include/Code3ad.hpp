#ifndef __CODE_3_AD__
#define __CODE_3_AD__

typedef enum {
  OPCODE_NONE = 0, /*        nop (ne rien faire) */
  OPCODE_ADD ,     /*        x := y + z          */
  OPCODE_SUB ,     /*        x := y - z          */
  OPCODE_MUL ,     /*        x := y * z          */
  OPCODE_DIV ,     /*        x := y / z          */
  OPCODE_NEG ,     /*        x := - y            */
  OPCODE_AND ,     /*        x := y & z          */
  OPCODE_OR  ,     /*        x := y | z          */
  OPCODE_NOT ,     /*        x := ! y            */
  OPCODE_CPY ,     /*        x := y              */
  OPCODE_LT ,      /*        x := y < z          */
  OPCODE_GT ,      /*        x := y > z          */
  OPCODE_LE ,      /*        x := y <= z         */
  OPCODE_GE ,      /*        x := y >= z         */
  OPCODE_EQ ,      /*        x := y == z         */
  OPCODE_NEQ ,     /*        x := y != z         */
  OPCODE_JMP ,     /*        aller � x           */
  OPCODE_JMPC ,    /*        si x aller � y      */
  OPCODE_ART ,     /*        x := y [ z ]        */
  OPCODE_ALT ,     /*        x [ y ] := z        */
  OPCODE_PTR ,     /*        x := & y            */
  OPCODE_RRT ,     /*        x := * y            */
  OPCODE_RLT ,     /*        * x := y            */
  OPCODE_PSH ,     /*        push x              */
  OPCODE_PSA ,     /*        push x [ y ]        */
  OPCODE_PSP ,     /*        push & x            */
  OPCODE_PSR ,     /*        push * x            */
  OPCODE_POP ,     /*        pop x               */
  OPCODE_PPA ,     /*        pop x [ y ]         */
  OPCODE_PPR ,     /*        pop * x             */
  OPCODE_CLL ,     /*        call x              */
  OPCODE_RET ,     /*        return              */
  OPCODE_RETV ,    /*        return x            */
  OPCODE_END       /*        end                 */
} CodeInstruction;

#endif
