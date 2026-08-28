#include "globals.h"



Entity* GetHero()
{
    auto base = reinterpret_cast<std::uintptr_t>(GetModuleHandleA(NULL));
    return *reinterpret_cast<Entity**>(base + 0x00AEF5EC);
}

Entity* entityFromNode(EntityListNode* node)
{
    return reinterpret_cast<Entity*>(reinterpret_cast<std::uintptr_t>(node) - 0xDC);
}

EntityListNode* GetEntityListHead()
{
    auto base = reinterpret_cast<std::uintptr_t>(GetModuleHandleA(NULL));
    return *reinterpret_cast<EntityListNode**>(base + 0xAC4AE4);
}

