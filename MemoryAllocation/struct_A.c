#include "struct_A.h"

void strcpy(char *dest, char *src) {
	while (*src) {
		*dest++ = *src++;
	}
	*dest = 0;
}

void initialize_A(uint8_t A_index, char* setting_value_given) {
	memory_pool[A_index].is_alive = true;
	strcpy(memory_pool[A_index].setting_value, setting_value_given);
	memory_pool[A_index].reference_cnt = 0;
}

uint8_t create_new_A(Stack* index_stack, char* setting_value_given) {
	uint8_t selected_A_index = stack_pop(index_stack);
	if (selected_A_index == STACK_FAIL_SIGNAL) return STACK_FAIL_SIGNAL;

	initialize_A(selected_A_index, setting_value_given);

	return selected_A_index;
}

bool destroy_A(uint8_t index) {

	return false;
}

bool release_A(uint8_t index) {

	return false;
}