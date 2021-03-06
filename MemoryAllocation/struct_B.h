#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>
#include "struct_A.h"

typedef struct _B {
	uint8_t A_index;
	uint64_t count_data;
} B;

B * create_B_refer(uint8_t A_object_index);
void initialize_datas_of(B* B_object, uint8_t A_object_index);
bool destory_B(B* B_object);
bool increase_reference_count_of(uint8_t A_object_index);
bool decrease_reference_count_of(uint8_t A_object_index);
bool count_data_of(B *b_object, uint64_t (*your_calc_logic)(char *));