#pragma once
#include "stack.h"

uint8_t stack_pop(Stack *stack) {
	if (stack->_top == EMPTY_STACK_SIGNAL) return STACK_FAIL_SIGNAL;
	   
	return stack->_container[--(stack->_top)];
}

uint8_t stack_push(Stack *stack, uint8_t index) {
	if (stack->_top == MAX_A_SIZE) return STACK_FAIL_SIGNAL;

	stack->_container[stack->_top] = index;

	return (stack->_top)++;
}

void stack_init(Stack* stack) {
	stack->_top = MAX_A_SIZE;
	for (register uint8_t i = 0; i < MAX_A_SIZE; i++) {
		stack->_container[i] = i;
	}
}