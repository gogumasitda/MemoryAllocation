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
	bool isSuccessToDecrease = decrease_reference_count_of(B_object->A_index);

	if (isSuccessToDecrease == false) return false;

	free(B_object);

	return true;
}

bool decrease_reference_count_of(uint8_t A_object_index) {
	A* reference = memory_pool + A_object_index;
	
	if (reference->reference_cnt <= 0) return false;
	reference->reference_cnt--;

	if (reference->is_alive == false && reference->reference_cnt == 0) {
		release_A(A_object_index);
	}

	return true;
}

bool count_data_of(B* b_object, uint64_t(*your_calc_logic)(char*)) {
	A *reference = memory_pool + b_object->A_index;

	uint64_t calced_data = your_calc_logic(reference->setting_value);

	if (calced_data < 0) return false;
	b_object->count_data = calced_data;
	return true;
}