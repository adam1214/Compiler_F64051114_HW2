#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct Value Value;
struct Value {
	union {
		int i_val;
		float f_val;
		char* string;
	};
};

#endif
