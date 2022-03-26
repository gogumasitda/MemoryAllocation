#pragma once
#include "size_type_definition.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct _A {
	bool is_alive;
	char setting_value[SETTING_VALUE_SIZE];
	uint16_t reference_cnt;
} A;

uint8_t create_new_A();
bool destroy_A();
bool release_A();