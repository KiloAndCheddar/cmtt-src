/* 
NullCoalescer.cpp
(Feature Idea -> Pseudocode -> Implementation)

GOAL:
  Turn PHP-Style Null-Coalesce expression:
  
      [LHS] ?? RHS
  
  into equivalent ternary Orthodox C++17 code:
     
      (LHS != nullptr) ? LHS : RHS

Strategy:

1. Locate: 
     Search the current source buffer for the ?? operator.
   
2. Capture: 
     Identify & Determine two parts:
      - Left-Hand Side  (LHS): (What we're checking if null).
      - Right-Hand Side (RHS): (Custom output if null)

3. Synthesize: 
     Generate:

        (LHS != nullptr) ? LHS : RHS

4. Replace: 
     Substitute the original expression with the generated output.

YOPPIE! :D

Notes (as of 2026-06-08 lol):
   - It's supposed to be a general thing (funcs, strings, pointers, etc)
   - Right now, it's currently a scan-and-replace transform. 
       A full lexer/parser/blabla is gonna be necessary if
       nested expressions become common. (Which it will)
   - Avoid evaluating LHS twice.
   
       For example: 
         getPlayerName() ?? "Unknown"

       Becomes:
         (getPlayerName() != nullptr)
             ? getPlayerName()
             : "Unknown";

        ... which calls getPlayerName() twice. Could be a bug if the func has side effects.
        For now, I'd ignore that completely and get it working right now.

        I'll wipe Tarkov PvP & PvE in the meantime. :p
*/
