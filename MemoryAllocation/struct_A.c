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

uint8_t create_new_A(char* setting_value_given) {
	uint8_t selected_A_index = stack_pop(&index_stack);
	if (selected_A_index == STACK_FAIL_SIGNAL) return STACK_FAIL_SIGNAL;

	initialize_A(selected_A_index, setting_value_given);

	return selected_A_index;
}

void kill_A_object(uint8_t index) {
	memory_pool[index].is_alive = false;
}

uint8_t destroy_A(uint8_t index) {
	kill_A_object(index);

	if (memory_pool[index].reference_cnt == 0) {
		uint8_t stack_signal = release_A(index);
		if (stack_signal == STACK_FAIL_SIGNAL) return STACK_FAIL_SIGNAL;

		return true;
	}

	return false;
}

uint8_t release_A(uint8_t index) {
	if (memory_pool[index].is_alive == true) return false;
	if (memory_pool[index].reference_cnt > 0) return false;

	uint8_t stack_signal = stack_push(&index_stack, index);
	if (stack_signal == STACK_FAIL_SIGNAL) return STACK_FAIL_SIGNAL;

	return true;
}

void change_A_setting_value(uint8_t index, char* setting_value_given) {
	strcpy(memory_pool[index].setting_value, setting_value_given);
}