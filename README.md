# C-Messaging Transpiler Toolkit (CMTT)

A *work-in-progress* transpiler and static analysis toolkit that removes boilerplate, improves diagnostics, and generates predictable Orthodox C++17 using C-Messaging.

### What's C-Messaging? It's a transpiled language that focuses on:
* Cleaner Object-oriented syntax!
* Borrows ideas from several languages,
    - including C++, C, PHP, C#, Swift, and Objective-C. :D
* Better diagnostics
* Reduced boilerplate
* Predictable generated code (on disk)
* Optional project generation without building
* Compatibility with existing C++17 toolchains (GCC & Clang)
* Designed for developers who want organization, readibility, and predictable generated code.

---

By default, CMTT uses Safety Mode. It enforces Orthodox C++17 style rules and performs additional static analysis.

For projects prioritizing convenience over strict safety checks, Ease-of-Use mode can be enabled.


#### CMTT is distributed under the [BSD 3-Clause](LICENSE).
---
### Status: Alpha / Prototype / Whateveritscalled
- The priority now is just to work on unfolders to get started. Easy to compile.
- Make a basic proof of concept
- Right now being used to dogfood my personal stuff
- I'll try to keep the main dependency free as much as possible. :p

### What does it look like?

#### C-Messaging:
```cpp
class Player {
    public float speed = 5.0f;

    void jump() {
        [physics->applyForce(self, 10)];
    }
}

auto username = user ?? "Anonymous";
```
#### C++17 (Generated Output):
```cpp
class Player {
public:
    float speed = 5.0f;

    void jump() {
        physics->applyForce(this, 10);
    }
};

auto username =
    (user != nullptr)
        ? user
        : "Anonymous";
```

## Documentation

There is NO documentation, NO help, NO guidance... yet for now. I didn't make those yet

If you guys want it, I can write it as I go. Sorry in advance if it's messy or isn't there. :c

## Installation

### Building CMTT source code

Literally compile it in GCC/clang as C++17. 

* Idk smth like GCC (g++): `g++ -std=c++17 main.cpp -o cmtt` (min ver GCC 8.1+ for complete C++17)
* Or if you hate yourself (Clang, clang++): `clang++ -std=c++17 main.cpp -o cmtt` (min ver Clang 5+ for complete C++17)

## Contributing

If you wanna help, the rules are simple:
- Please Fork, make changes, and make a Pull Request.
- I don't believe in mailing lists so please discuss on GitHub.
- If you have a new idea (eureka! :D), please treat it like an informal RFC (guys! i got an idea! look at how i did it!) type stuff. Don't take it *too* seriously.
- Bug fixes don't really need the informal RFC idea (since bugs are totally not new features).
- I'm opinionated and I'm genuinely very happy to be proven wrong if there's a better way.
- This is my current design philosophy and scope. Please convince me with practical reasoning and your commits will be added! :D

## CMTT Architecture
| Component         | Responsibility                                                                 |  Complexity   | 
| ----------------- | ------------------------------------------------------------------------------ | ------------- | 
| Main Orchestrator | Main function, step-by-step, project reading and etc.                          | Not that hard |
| Bouncer           | Static analysis, Error Guidance, and C-Messaging Diagnostics.                  | A bit tedious |  
| Unfolders         | Simple text/syntax transforms (e.g., `??` -> ternary, `[]` stripping.          | Low           | 
| Transpilers       | Context-aware logic (e.g., Include guards, mapping types, `match` exhaustion). | Medium        |
| C-OOP (C99 Only)  | C-OOP in C99 mode to generate C99 code with C++-compatible object layouts and vtables. | Extreme Demon Difficulty | 

If you want to get into C-Messaging RIGHT NOW, use the C++17 mode in the meantime. Don't expect C-OOP to drop anytime soon. 

I never wrote a vtable before so its the friends we made along the way. :D

## Some Q&A

### What's the workflow like?

CMTT isn't just a transpiler sitting in a pipe. It acts more like a C++17 project generator that GCC / Clang later reads.

For example: `main.cm -> CMTT -> /output_cpp/ -> GCC / Clang -> Binary`.

One of the biggest fears developers have with transpilers is:
> "What if the transpiler disappears? D:"

In CMTT, it addresses that! If all the generated code sits on the disk:
```bash
cmtt main.cm --generate-project-only
```

Then the user still owns the `/output_cpp/` forever. If you didn't use the flag, it still generates it anyway before building.
Even if CMTT disappeared tomorrow, they could continue building on the generated project, which appeals to businesses and long-lived embedded products.

### Are you seriously going to dogfood this?
yas queen slaaaaaay :3c

### Why isnt this professional?
- Because I just made this a few days ago. 
- Powered by ADHD & my free time.
- I'll fix it up later if it becomes interesting. (i will personally remember my early contributors by name. promise! :D)
- Anyone wanting to fund this, I'll unironically spend it on Tim Hortons, food, a PC with 64gb of ram, steam games, and rent. 
    - This speeds up devtime exponentially. Gramerci et minna, arigatou! ⸜(｡˃ ᵕ ˂ )⸝♡
- If i keep dying in tarkov, i will work on it more!

### What should I expect? 
#### The goals:
- Make your life easier (Clean predictable abstractions).
- Transparency First. (You see exactly what the compiler sees. Don't like it? Modify the exported project yourself!)
- Maximum Compatibility.
- Modern Safety, C speed. (I stole some features from PHP, C#, Swift, etc. like `??` operator, `[]` message calls, and even `#include_once` but unfolds into standard C99/C++17.)
- In C++17, you can still program like normal without cursed stuff.
- Adding Error Guidance based on hashes for common error patterns so noobs helping your project can understand: "oooh! i gotta read the guidelines and the error is about XYZ!"
- A Transpiler Bouncer to make sure you're using C-Msg features right. The Bouncer isn't there to fix your code, but to audit it.

#### And I'll explore experimental features like:
- PHP style `__construct(public string $name)` to kill boilerplate. :p
- Match Expressions (no more dumb Switch/Break stuff)
- Named Arguments `doStuff(timeout: 10, retries: 3);` which transpiles to `doStuff(10, 3);`.
- Built-in **PHP-style** Associative Arrays `['key' => 'value']` instead of `std::unordered_map`. It's a dynamic insertion ordered map implemented as a hash table that links keys to values.
    - /!\ VERY EXPERIMENTAL: Just a warning! It's a significantly larger feature idea than the other planned features, so it might get delayed or removed.
    - Not stack allocated, uses system heap.
    - Done as a hybrid hash table and linked list structure.
    - Values can be mixed types.
    
#### And REALLY experimental stuff like:  
- C-OOP in C99 mode to generate C99 code with C++-compatible object layouts and vtables.
- (we'll see what happens)

You still have to make your C-Messaging code is good if you're using C-Msg features. If you wanna do a manual C stuff, it

### Why use this instead of Orthodox C++17 or a library? Freakin' nerd... >:/

Because the whole point is to MAKE YOUR LIFE EASIER. Like dude, you absolutely CAN do this manually. I'm not your mom.

You can manually type out your `ifndef` guards, you can manually type ternary operator checks, and you can manually manage your obj scopes to mimic RAII.

But doing that 500 times a day is why people introduce bugs. The whole point of C-Messaging isn't about adding magic, it's about automating the mental tax of your code so you can focus on logic more.

For example:

### include_once

```cpp
// C-Messaging
#include_once "joemama.hm"

// Transpiled into C99/C++17 Include Guards):
#ifndef _CMSG_GUARD_6F4B9A_JOEMAMA_HM
#define _CMSG_GUARD_6F4B9A_JOEMAMA_HM
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

### Isn't this quite ambitious?
im baby
