#define MAX_STACK_SIZE (100)
#define EMPTY_STACK (0)
#define FAIL_SIGNAL ((1 << 8) - 1)

#include <stdint.h>

typedef struct _Stack {
	uint8_t _top;
	uint8_t _container[MAX_STACK_SIZE];
} Stack;

uint8_t stack_pop(Stack *stack);
uint8_t stack_push(Stack *stack, uint8_t index);
void stack_init(Stack *stack);