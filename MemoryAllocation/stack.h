#pragma once
#include <stdint.h>
#include "size_type_definition.h"

typedef struct _Stack {
	uint8_t _top;
	uint8_t _container[MAX_A_SIZE];
} Stack;

uint8_t stack_pop(Stack *stack);
uint8_t stack_push(Stack *stack, uint8_t index);
void stack_init(Stack *stack);