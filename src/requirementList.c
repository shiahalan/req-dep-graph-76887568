/*
Data Structure: Linked List

The data structure I chose is a linked list graph. This is because it makes sense
to have each requirement as a node, with pointers to the parent and children nodes. This
creates a sort of dependency tree, that represents the dependencies between requirements.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/requirementList.h"

static Requirement *requirementList = NULL;

static ReqNode* createReqNode(Requirement *req) {
    ReqNode *node = malloc(sizeof(ReqNode));
    node->req = req;
    node->next = NULL;
    return node;
}

// Add a requirement to global list
Requirement* addRequirement(const char *name) {
    Requirement *curr = requirementList;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) return curr;
        curr = curr->next;
    }

    Requirement *newReq = malloc(sizeof(Requirement));
    strncpy(newReq->name, name, sizeof(newReq->name));
    newReq->name[sizeof(newReq->name) - 1] = '\0';
    newReq->parents = NULL;
    newReq->children = NULL;
    newReq->next = requirementList;
    requirementList = newReq;
    return newReq;
}

// Link parent and child requirements
void addDependency(Requirement *from, Requirement *to) {
    ReqNode *childNode = createReqNode(to);
    childNode->next = from->children;
    from->children = childNode;

    ReqNode *parentNode = createReqNode(from);
    parentNode->next = to->parents;
    to->parents = parentNode;
}

// Release all memory used by the requirements list
void freeAllRequirements(void) {
    Requirement *curr = requirementList;
    while (curr != NULL) {
        ReqNode *p = curr->parents;
        while (p != NULL) {
            ReqNode *tmp = p;
            p = p->next;
            free(tmp);
        }

        ReqNode *c = curr->children;
        while (c != NULL) {
            ReqNode *tmp = c;
            c = c->next;
            free(tmp);
        }

        Requirement *tmpReq = curr;
        curr = curr->next;
        free(tmpReq);
    }

    requirementList = NULL;
}

// Traverse and print all requirements

void printRequirements(void) {
    Requirement *curr = requirementList;
    while (curr != NULL) {
        printf("Requirement: %s\n", curr->name);

        printf("  Parents: ");
        for (ReqNode *p = curr->parents; p != NULL; p = p->next) {
            printf("%s ", p->req->name);
        }
        printf("\n");

        printf("  Children: ");
        for (ReqNode *c = curr->children; c != NULL; c = c->next) {
            printf("%s ", c->req->name);
        }
        printf("\n");

        curr = curr->next;
    }
}