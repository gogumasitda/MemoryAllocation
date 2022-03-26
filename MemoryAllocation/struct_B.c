#pragma once
#include "struct_B.h"

bool create_at(B* B_object, uint8_t A_object_index) {
	B_object = (B*) malloc(sizeof(B));

	if (B_object == 0) return false;

	initialize_datas_of(B_object, A_object_index);

	return true;
}

void initialize_datas_of(B* B_object, uint8_t A_object_index) {
	B_object->A_index = A_object_index;
	B_object->count_data = 0;
}

bool destory_this(B* B_object) {

}

bool decrease_reference_count_of(uint8_t A_object_index) {

}

bool count_data_of(B* b_object, uint64_t(*your_calc_logic)(char*)) {

	return true;
}