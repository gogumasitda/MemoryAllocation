enum DATA_SIZE {
	MAX_A_SIZE = (1 << 8) - 2,
    SETTING_VALUE_SIZE = (1 << 16)
};

enum ERROR_TYPES
{
    STACK_FAIL_SIGNAL = ((1 << 8) - 1),
    EMPTY_STACK_SIGNAL = 0
};