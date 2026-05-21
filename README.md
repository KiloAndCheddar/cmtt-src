# C-Messaging Transpiler Toolkit (CMTT)

CMTT is a text processor and transpiler for my cursed object oriented superset of C99 & C++17 called "C-Messaging", which a transpiled language I made because I cannot bear to look at r/C_Programming LARP OOP in C with 500 structs. :p

Additionally, this makes the Embedded/Orthodox C++ rules formalized instead of having to remember them in the superset transpiled language.

Because CMTT outputs C99 or Orthodox C++17 (depending on mode), you can use it with any compiler! 
Even cursed Chernobyl-style forked GCC versions for exotic 24-bit or 32-bit hardware that chip manufacturers use for world domination (or just to make embed devs depressed, which is more likely).

CMTT is distributed under the [BSD 3-Clause](LICENSE).

### Status: Alpha / Prototype / Whateveritscalled
- Tokenizer is indev.
- Right now being used to dogfood my personal stuff
- I'll try to keep the main dependency free as much as possible. :p

#### CMTT Architecture
| Component         | Responsibility                                                                 |  Complexity   | 
| ----------------- | ------------------------------------------------------------------------------ | ------------- | 
| Main Orchestrator | Main function, step-by-step, project reading and etc.                          | Not that hard |
| Unfolders         | Simple text/syntax transforms (e.g., `??` -> ternary, `[]` stripping.          | Low           | 
| Transpilers       | Context-aware logic (e.g., Include guards, mapping types, `match` exhaustion). | Medium        | 
| C-OOP (C99 Only)  | Generating the ABI-compliant C structures (vtable-like dispatch, `self` pointers to mimic C++ under the hood while kept simple. | Extreme Demon Difficulty | 

Because C++17 Mode uses the existing OOP setups, we don't need the C-OOP step.
However for C99 (to make r/C_Programmers and embed devs less miserable), we're gonna try C-OOP instead. 

And for C-OOP, I'm doing the ABI in my [SPEC](SPEC.md) (doesnt exist yet). we'll be mimicking the C++ ABI because if we didn't, the linker would eat us alive.

If you want to get into C-Messaging RIGHT NOW, use the C++17 mode in the meantime. Don't expect C-OOP to drop anytime soon. I never wrote a vtable so its the friends we made along the way. :D

It would've been too easy to just focus on C++17 but the whole point was to STOP USING STRUCTS and praying nobody touches your imaginary PRIVATE class and a memory leak.
Instead, you'll finally get:
- `[ERROR: #0x999] Unauthorized access to private member 'data' in 'Player' struct.`
- BEFORE it hits the compiler. Absolute Cinema.
- its an encapsulation layer to C99 that C itself can't enforce + C-Msg unfolded deterministic treats! :D
- results? more bearable debugging mysterious memory corruption bugs! ^_^

It won't be like CObject and private classes are ENFORCED by the CMTT. (virtually impossible in normal C)

## are you unironically going to dogfood this
yas queen slaaaaaay :3c

## why isnt this professional
- because i Just made this a few days ago 
- powered by ADHD & im making it by myself
- i will fix it up later if it becomes a hit (i will personally remember my early contributors by name. promise! :D)
- anyone wanting to fund this, i'll unironically spend it on tim hortons, food, a PC with 64gb of ram, steam games, and rent. 
    - this speeds up devtime exponentially. Gramerci et minna, arigatou! ⸜(｡˃ ᵕ ˂ )⸝♡
- if i keep dying in tarkov, i will work on it more!

## What should I expect? 
The goals:
- Make your life easier (Clean predictable abstractions without STD bloat).
- Transparency First. (You see exactly what the compiler sees. Don't like it? Modify the exported project yourself!)
- Maximum Compatibility.
- Modern Safety, C speed. (I stole some features from PHP, C#, Swift, etc. like `??` operator, `[]` message calls, and even `#include_once` but unfolds into standard C99/C++17.)
- In C99 mode, it counts your malloc and frees to see if you're getting a memory leak *before* compile time.
- If your project demands C99 but you want OOP, you can use Orthodox C++17-style OOP (like a manual RAII so it errors you if you dont fix it). I'm calling it C-OOP (as original as it is).
- In C++17, you can still program like normal without cursed stuff.
- Adding Error Guidance based on hashes for common error patterns so noobs helping your project can understand: "oooh! i gotta read the guidelines and the error is about XYZ!"

And dumb features like:
- PHP style `__construct(public string $name)` to kill boilerplate. :p
- Match Expressions (no more dumb Switch/Break stuff)
- Named Arguments `doStuff(timeout: 10, retries: 3);` which transpiles to `doStuff(10, 3);`.
- Built-in Associative Arrays `['key' => 'value']` because `std::unordered_map` is too fat and heavy.
- A Transpiler Bouncer to make sure you're using C-Msg features right. The Bouncer isn't there to fix your code, but to audit it. 
- C-OOP in C99 mode to convert into manual vtables inside structs to mimic C++'s OOP, and same Orthodox C++ OOP syntax.

You still have to make your C-Messaging code is good if you're using C-Msg features. If you wanna do a manual C stuff, it



## Documentation

There is NO documentation, NO help, NO guidance (for now, I just started it cuz im baby and I don't wanna write it down yet).

If you guys want it, I can write it as I go. Sorry in advance if it's messy. :c

## Installation

### Building CMTT source code

Literally compile it in GCC/clang as C++17. 

* Idk smth like GCC (g++): `g++ -std=c++17 main.cpp -o cmtt` (min ver GCC 8.1+ for complete C++17)
* Or if you hate yourself (Clang, clang++): `clang++ -std=c++17 main.cpp -o cmtt` (min ver Clang 5+ for complete C++17)

## Contributing

If you wanna help, the rules are simple:
- Please Fork, make changes, and make a Pull Request.
- I don't believe in mailing lists so please discuss on GitHub.
- If you have a new idea (eureka! :D), please treat it like an informal RFC (guys! i got an idea! look at how i did it!) type stuff.
- Bug fixes don't really need those (since bugs are totally not new features).

## Why use this instead of manual Orthodox C++? Freakin' nerd... >:/

Because the whole point is to MAKE YOUR LIFE EASIER. Like dude, you absolutely CAN do this manually. I'm not your mom.

You can manually type out your `ifndef` guards, you can manually type ternary operator checks, and you can manually manage your obj scopes to mimic RAII.

But doing that 500 times a day is why people introduce bugs. My C-Messaging transpiled lanauge isn't about adding magic, it's about automating them mental tax of your code so you can focus on logic more.

For example:

### include_once

```cpp
// C-Messaging
#include_once "joemama.h"

// Transpiled into C99/C++17 Include Guards):
#ifndef _JOEMAMA_INC_GUARD_
#define _JOEMAMA_INC_GUARD_
#include "joemama.h"
#endif

// Alternatively (As #pragma once):
#pragma once
#include "joemama.h"
```

### Null-Coalesce
```cpp
// C-Messaging
auto name = [e->data->name] ?? "Unknown Entity";

// Transpiled Orthodox C++17
auto name = (e->data->name != nullptr) ? e->data->name : "Unknown Entity";
```

### Example Code blablbabla in C-Messaging
Before (C-Messaging):
```cpp
// update.cmpp
void update_system(Entity* e) {
    // 1. The null-coalesce operator makes defaults a one-liner
    auto name = [e->data->name] ?? "Unknown Entity";

    // 2. The [] syntax marks a high-level system call
    [e->physics->apply_gravity(0.98f)];

    printf("Updating: %s\n", name);
}
```

After (Transpiled C++ Code Output):
```cpp
// update.cpp
void update_system(Entity* e) {
    // The transpiler automatically generates the null-check
    const char* name = (e->data->name != nullptr) ? e->data->name : "Unknown Entity";

    // The transpiler strips the brackets to standard C++ call syntax
    e->physics->apply_gravity(0.98f);

    printf("Updating: %s\n", name);
}
```
This should give you a basic idea of what you might be getting familiar with. :P
