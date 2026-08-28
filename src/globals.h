#pragma once
#include <Windows.h>
#include "memory.h"
#include <iostream>


// Global structs
struct EntityListNode
{
    std::uint8_t unknown[0x08];
    EntityListNode* prev;  // +0x08
    EntityListNode* next;  // +0x0C
};

struct Entity
{
    // +0x000 ... +0x07F
    std::uint8_t unknown_000[0x80];

    // +0x080
    float x;

    // +0x084 ... +0x087
    std::uint8_t unknown_084[0x04];

    // +0x088
    float y;

    // +0x08C ... +0x0DB
    std::uint8_t unknown_08C[0x50];

    // +0x0DC
    EntityListNode listNode;

    // +0x0EC ... +0x113
    std::uint8_t unknown_0EC[0x28];

    // +0x114
    std::uint16_t name[13];

    // +0x12E ... +0x44F
    std::uint8_t unknown_12E[0x322];

    // +0x450
    std::uint32_t currentHP;

    // +0x454
    std::uint32_t currentMana;

    // +0x458
    std::uint32_t maxHP;

    // +0x45C
    std::uint32_t maxMana;
};

// Verify Entity layout
static_assert(offsetof(Entity, x) == 0x080);
static_assert(offsetof(Entity, y) == 0x088);
static_assert(offsetof(Entity, listNode) == 0x0DC);
static_assert(offsetof(Entity, name) == 0x114);
static_assert(offsetof(Entity, currentHP) == 0x450);
static_assert(offsetof(Entity, currentMana) == 0x454);
static_assert(offsetof(Entity, maxHP) == 0x458);
static_assert(offsetof(Entity, maxMana) == 0x45C);


// Function definitions 
EntityListNode* GetEntityListHead();
Entity* entityFromNode(EntityListNode* node);
Entity* GetHero();