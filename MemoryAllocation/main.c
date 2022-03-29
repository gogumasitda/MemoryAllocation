#include <stdio.h>
#include "struct_A.h"
#include "struct_B.h"

uint64_t seed = 33;

uint64_t dummy_logic(char *nothing) {
	
	return seed = (seed << 5) + 987654321;
}


int main() {
	initialize_stack();
	char tmp[5] = "ABCDE";
	uint8_t a_sample = create_new_A(tmp);
	B* b_sample = create_B_refer(a_sample);
	
	printf("%d\n", memory_pool[b_sample->A_index].reference_cnt);
	count_data_of(b_sample, dummy_logic);

	return 0;
}