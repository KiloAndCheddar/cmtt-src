# C-OOP  Specification
#### (C Object-Oriented Programming? Mouthful. :p) Work in progress anyway.
Ignore the bad spelling.

**BY THE WAY. Scroll all the way down to see expected generated code, then read everything else! :p**

### License

Like the rest of CMTT, any C-OOP implimentation is intended to be released under the [BSD 3-Clause License](LICENSE).

## Welcome, friends!

So you're interested in implimenting C-OOP...

Horray! :D

Unfortunately, that's where the fun ends.

The rest of this document is mostly about manually reproducting object-oriented behaviour in C99 (or whenever C2Y drops) using structs, function pointers, virtual tables, inheritance layouts, and other forms of self-inflicted suffering.

## Current Status

C-OOP is currently an experiemntal long-term idea. 

It's NOT a priority for the C-Messaging Transpiler Toolkit project.

The immediate goal of CMTT is generating predictable Orthodox C++17 output using C-Messaging transpiled language. 
Most development effort should be focused on the core architecture, static analysis, diagnostics, unfolders, and the transpiler pipeline.

If you wanna spend your time working on C-OOP anyway, THANK YOU SO MUCH! Seriously. You're so awesometastic! :D

## Why Does C-OOP Exist?
#### Why not GObject or [name goes here]?

The whole point and original motivation was simple: 

Writing object-oriented systems manually in C often requires a scary amount of boilerplate.

The usual patterns involve:
* Structs representing classes
* Function pointers representing methods
* Manual virtual tables
* Manual inheritance layouts
* Manual encapsulation conventions 

At that point, you're doing the original C++ in all but name. Which *is not* awesometastic.

The goal of C-OOP is to generate these patterns automatically from C-Messaging syntax.

In theory, this would allow developers to write:
```cpp
[player->jump()];
```

... and generate predictable C99 code that behaves similar to the Orthodox C++17 backend.

## Expectations?

Please keep your expectations realistic.

C-OOP may:

* Never reach production quality
* Miss the initial 1.0 release, with the ETA as Coming Soon™
* Change SIGNIFICANTLY during development
* Require compromises for portability/readibility.

This is a research project, not a promise. That's why it's under the **VERY Experimental** label in the [README.md](README.md).

## Safety

Even if a prototype becomes functional:

**PLEASE** don't use the generated C-OOP code for kernel/game development yet.

The generated code may be:
* Incorrect
* Inefficient
* Difficult to audit
* Annoying to debug
* Incompatible with edge-case compiler behaviour

The generated C-OOP output must be thoroughly validated before it can be considered suitable for safety-critical or kernel-level software.

Even then, I wouldn't trust a teleporter running on generated C-OOP with my life yet.

## Technical Goal

The long-term goal of C-OOP is to generate C99 code using:
* Structs
* Function pointers
* Virtual tables
* Predictable memory layouts

... while preserving behaviour similar to the Orthodox C++17 backend.

Ideally, generated layouts would be compatible *enough* that developers familiar with C++ object models can easily understand the generated output. (Clueless)

Whether that goal is achievable remains to be seen. :/

## The Worrying Concern

Making it work is just half the battle. 

The whole point of C-OOP was to avoid writing hundreds of structs, wrapper functions, and vtables just to LARP OOP by hand.

The biggest concern is generating output that humans can actually read. (Not 500 unreadable struct slop). A C-OOP backend that produces 50,000 lines of unreadable boilerplate is *technically* successful and **practically useless**.

For example:
```cpp
Dog dog;
Animal* animal = (Animal*)&dog;
animal->vtable->speak(animal);
```
... is ugly but understandbale.

Meanwhile:
```cpp
__cm_internal_vtable_dispatch_42(
    __cm_internal_object_17,
    __cm_internal_metadata_9
);
```
... might technically work but it's literally impossible to audit.

Generated code should remain understandable and debuggable, with comments from C-Messaging carrying over, even labeling which are Private or public.

If the output becomes a mess, there is literally no point since the designed failed regardless of whether it actually works.  

## Desired Output Style

If C-OOP manages to survive development hell and becomes functional, the generated code should remain understandable to ordinary C programmers.

For example, a simple class might generate something similar to:
```c
// how CMTT should map a class layout on disk for C99 (i hope)
typedef struct AnimalVTable AnimalVTable;

typedef struct Animal {
    const AnimalVTable* vtable; // always at offset 0, like C++
    int age;
} Animal;

struct AnimalVTable {
    void (*speak)(Animal* self); // clear, readable function pointers
};
```
Even if the implimentation needs some casts internally, the *generated code people see* should look like something you'd actually write.

The appeal isn't really "yet another OOP in C", it's "Can we generate C code that looks like something a sane programmer would write by hand?".

That's why we have `void (*speak)(Animal* self);` instead of `void (*speak)(void* self);`. Readibility over cleverness. Hopefully, you guys will get it at a first glance.

### Why not use C Object System, OOC, or SOOL?
meow meow :3
