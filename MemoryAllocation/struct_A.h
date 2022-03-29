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
Stack index_stack;

uint8_t create_new_A(char *setting_value_given);
uint8_t destroy_A(uint8_t index);
uint8_t release_A(uint8_t index);
bool change_A_setting_value(uint8_t index, char* setting_value_given);