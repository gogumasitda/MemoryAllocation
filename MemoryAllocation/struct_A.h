#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "size_type_definition.h"
#include "stack.h"

typedef struct _A {
	bool is_alive;
	char setting_value[SETTING_VALUE_SIZE];
	uint16_t reference_cnt;
} A;

A memory_pool[MAX_A_SIZE];

uint8_t create_new_A(Stack *index_stack, char *setting_value_given);
bool destroy_A(uint8_t index);
bool release_A(uint8_t index);