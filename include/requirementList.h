#ifndef REQUIREMENTGRAPH_H
#define REQUIREMENTGRAPH_H

typedef struct Requirement Requirement;

// Requirement node structure
typedef struct ReqNode {
    Requirement *req;
    struct ReqNode *next;
} ReqNode;

// Hold requirement information
typedef struct Requirement {
    char name[64];
    struct ReqNode *parents;
    struct ReqNode *children;
    struct Requirement *next;
} Requirement;

// Add a new requirement to the global list
Requirement *addRequirement(const char *id);

// Add a node
void addDependency(Requirement *parent, Requirement *child);
// Free all nodes
void freeAllRequirements();
// Print all requirements
void printRequirements();

#endif