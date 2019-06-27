#include <stdio.h>
#include <stdlib.h>

typedef char bool;
#define false 0
#define true 1

typedef struct boolsListNode {
	bool value;
	struct boolsListNode *next;
} boolsListNode;

typedef struct boolsList {
	boolsListNode *first,
				  *last;
} boolsList;

typedef boolsList* (*Function)(boolsListNode*);

typedef struct functionsListNode {
	Function function;
	struct functionsListNode *next;
} FunctionsListNode;

Function makeFunction(FunctionsListNode *firstFunction) {
	boolsList* newFunction(boolsListNode *firstArg) {
		boolsList **returns = malloc(sizeof(boolsList*));
		(*returns)->first = NULL;
		boolsListNode **currentReturn = &(*returns)->first;
		FunctionsListNode *currentFunctionsListNode = firstFunction;
		while (currentFunctionsListNode) {
			boolsList *currentFunctionReturnsList = currentFunctionsListNode->function(firstArg);
			*currentReturn = currentFunctionReturnsList->first;
			(*returns)->last = currentFunctionReturnsList->last;
			currentReturn = &currentFunctionReturnsList->last->next;
			currentFunctionsListNode = currentFunctionsListNode->next;
		}
		return *returns;
	}
	return newFunction;
}

int main(void) {
	
	return 0;
}