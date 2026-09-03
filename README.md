# SilkRoadDLL

> A small reverse-engineering project targeting the **Silkroad Online** client, exploring internal client structures, native functions, memory addresses, and runtime modification from an injected DLL.

**Status:** Archived / Discontinued
**Language:** C++
**Platform:** Windows / x86
**Project Type:** Reverse Engineering / Game Client Research

---

## Overview

**SilkRoadDLL** is an experimental reverse-engineering project focused on studying the internals of the Silkroad Online client.

The project was created as a practical exercise in understanding how a native Windows game client is structured and how its internal systems can be located and interacted with through an injected DLL.

The primary focus was not on building a complete end-user tool, but on the reverse-engineering process itself:

* Locating internal client functions
* Identifying useful data structures
* Understanding calling conventions
* Working with x86 assembly
* Resolving runtime addresses
* Pattern/signature scanning
* Accessing client objects from native code
* Investigating packet-related functionality
* Experimenting with hooks and function calls
* Translating reverse-engineered assembly into C++

The project was eventually abandoned, but the code remains as a snapshot of the reverse-engineering work and learning process.

---

## What I Learned

This project provided hands-on experience with several areas of low-level software development and reverse engineering.

### Reverse Engineering

The client was analyzed using tools such as:

* **Ghidra**
* **Cheat Engine**
* **x64dbg / x32dbg**
* PE analysis tools

The workflow generally involved locating interesting behavior in the client, analyzing the surrounding assembly, identifying function arguments and object pointers, and then reproducing the relevant functionality from C++.

### x86 Assembly

A significant part of the project involved understanding and translating instructions such as:

```asm
mov
lea
push
pop
call
jmp
cmp
test
je
jne
movzx
movsx
```

Understanding stack frames, registers, calling conventions, relative addresses, and compiler-generated code was essential when reconstructing internal functions.

### Runtime Address Resolution

Because static addresses are dependent on the loaded module layout, the project experimented with locating code dynamically rather than relying exclusively on hard-coded absolute addresses.

This included byte-pattern/signature scanning with wildcard support.

Example:

```text
8B 0D ? ? ? ? 85 C9 74 ? 8B 01 FF 50 ?
```

This approach makes reverse-engineered locations more resilient to changes in module layout.

### Internal Structures

Another part of the research involved reconstructing internal client objects from observed memory layouts.

For example, an object can be represented in C++ using known offsets:

```cpp
struct Entity
{
    // Unknown / unidentified fields...

    float x;        // +0x80
    // ...

    float y;        // +0x88
};
```

Rather than attempting to reconstruct an entire class immediately, individual fields were identified through debugger observations and gradually mapped into C++ structures.

### Native DLL Development

The project was implemented as a native Windows DLL, allowing the research code to execute inside the target process and interact with its address space.

This provided practical experience with:

* `DllMain`
* module base addresses
* function pointers
* pointer arithmetic
* calling conventions
* Windows memory APIs
* runtime code execution
* native C++/assembly interoperability

---

## Reverse-Engineering Workflow

The general workflow used during development was:

```text
Silkroad Client
      │
      ▼
Observe Behaviour
      │
      ▼
Cheat Engine / Debugger
      │
      ▼
Identify Interesting Address
      │
      ▼
Inspect Assembly
      │
      ▼
Determine Arguments / Objects
      │
      ▼
Trace References
      │
      ▼
Reconstruct Structure / Function
      │
      ▼
Implement in C++
      │
      ▼
Test Inside Client
```

This process was repeated for different pieces of functionality throughout the project.

---

## Project Status

This repository is **archived** and is no longer actively developed.

The project was intentionally kept public because it represents useful reverse-engineering work and documents an earlier stage of my learning process.

It should therefore be viewed as a **research / learning project rather than a finished application**.

Some functionality may be incomplete, version-specific, or dependent on addresses from the particular Silkroad Online client build that was being analyzed.

---

## Why Keep It Public?

Even though the project is small and unfinished, it demonstrates practical experience with:

* Reverse engineering
* Static and dynamic analysis
* x86 assembly
* C++
* Windows internals
* Native DLL development
* Memory analysis
* Function reconstruction
* Binary pattern scanning
* Runtime debugging
* Data-structure reconstruction

The repository is intended primarily as a technical reference and portfolio piece showing the process of taking observations from a compiled binary and turning them into usable native C++ code.

---

## Disclaimer

This project was created for **educational and reverse-engineering research purposes**.

Silkroad Online and its associated intellectual property belong to their respective owners.

This repository does not contain proprietary game assets and is not affiliated with or endorsed by the game's developers or publishers.

---

## Author

**P3tWu33y**

Reverse Engineering • C++ • Windows Internals • x86 Assembly
