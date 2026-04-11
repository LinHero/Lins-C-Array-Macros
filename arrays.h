


#pragma once


#include <stdint.h>
#include <assert.h>




//__________________________________________________________________//
//			Macros & Defines										//
//__________________________________________________________________//


//				Arrays


/*
//		Create just the array_t body
//		Must be given a reference to an array
*/
#define mARRAY_T(ltype, lsize, laddr) \
	{ \
		.size = lsize, \
		.elm_size = sizeof(ltype), \
		.data = laddr \
	}


/*
//		Create an array of given type
//		Pass data of said type
*/
#define mARRAY_DATA(ltype, lname, ...) \
	ltype array_##lname[] = __VA_ARGS__; \
	const array_t lname = { \
		.size = sizeof((ltype[])__VA_ARGS__) / sizeof(ltype), \
		.elm_size = sizeof(ltype), \
		.last = (sizeof((ltype[])__VA_ARGS__) / sizeof(ltype)) - 1, \
		.data = &array_##lname, \
		.type = ARRAY_1D \
	}

/*
//		Create an array of given type
//		Pass size for the array
*/
#define mARRAY_SIZE(ltype, lname, lsize) \
	ltype array_##lname[lsize] = {0}; \
	const array_t lname = { \
		.size = lsize, \
		.elm_size = sizeof(ltype), \
		.last = lsize - 1, \
		.data = &array_##lname, \
		.type = ARRAY_1D \
	}

/*
//		Create an array of given type
//		Pass size & data for the array
*/
#define mARRAY_SIZEDATA(ltype, lname, lsize, ...) \
	ltype array_##lname[lsize] = __VA_ARGS__; \
	const array_t lname = { \
		.size = lsize, \
		.elm_size = sizeof(ltype), \
		.last = (sizeof((ltype[])__VA_ARGS__) / sizeof(ltype)) - 1, \
		.data = &array_##lname, \
		.type = ARRAY_1D \
	}

/*
//		Create an array of given type's pointer
//		Pass data of said type's ptr
*/
#define mARRAY_DATA_PTR(ltype, lname, ...) \
	ltype* array_##lname[] = __VA_ARGS__; \
	const array_t lname = { \
		.size = sizeof((ltype*[])__VA_ARGS__) / sizeof(ltype*), \
		.elm_size = sizeof(ltype*), \
		.last = (sizeof((ltype*[])__VA_ARGS__) / sizeof(ltype*)) - 1, \
		.data = &array_##lname, \
		.type = ARRAY_1D \
	}

/*
//		Create an array of given type's pointer
//		Pass size for the array
*/
#define mARRAY_SIZE_PTR(ltype, lname, lsize) \
	ltype* array_##lname[lsize] = {0}; \
	const array_t lname = { \
		.size = lsize, \
		.elm_size = sizeof(ltype*), \
		.last = lsize - 1, \
		.data = &array_##lname, \
		.type = ARRAY_1D \
	}

/*
//		Create an array of given type's pointer
//		Pass size & data for the array
*/
#define mARRAY_SIZEDATA_PTR(ltype, lname, lsize, ...) \
	ltype* array_##lname[lsize] = __VA_ARGS__; \
	const array_t lname = { \
		.size = lsize, \
		.elm_size = sizeof(ltype*), \
		.last = (sizeof((ltype*[])__VA_ARGS__) / sizeof(ltype*)) - 1, \
		.data = &array_##lname, \
		.type = ARRAY_1D \
	}


/*
//		Access a value from an array
*/
#define mARRAY_GET(ltype, lname, lind) ({\
		assert(((sizeof(ltype) * (lind + 1)) <= ((lname).size * (lname).elm_size)) && "\n\tExceeded Array Size"); \
		((ltype*)(lname).data)[lind]; \
	})
/*
//		Write a value to an array
*/
#define mARRAY_SET(ltype, lname, lind, lval) ({\
		assert(((sizeof(ltype) * (lind + 1)) <= ((lname).size * (lname).elm_size)) && "\n\tExceeded Array Size"); \
		((ltype*)(lname).data)[lind] = lval; \
	})
	
/*
//		Access the address of an array index
*/
#define mARRAY_GET_ADDR(ltype, lname, lind) ({\
		assert(((sizeof(ltype) * (lind + 1)) <= ((lname).size * (lname).elm_size)) && "\n\tExceeded Array Size"); \
		&((ltype*)(lname).data)[lind]; \
	})
	
/*
//		Access a pointer from an array
*/
#define mARRAY_GET_PTR(ltype, lname, lind) ({\
		assert(((sizeof(ltype*) * (lind + 1)) <= ((lname).size * (lname).elm_size)) && "\n\tExceeded Array Size"); \
		((ltype**)(lname).data)[lind]; \
	})

/*
//		Write a pointer to an array
*/
#define mARRAY_SET_PTR(ltype, lname, lind, lval) ({\
		assert(((sizeof(ltype*) * (lind + 1)) <= ((lname).size * (lname).elm_size)) && "\n\tExceeded Array Size"); \
		((ltype**)(lname).data)[lind] = lval; \
	})

/*
//		Access the address of an array index
*/
#define mARRAY_GET_ADDR_PTR(ltype, lname, lind) ({\
		assert(((sizeof(ltype*) * (lind + 1)) <= ((lname).size * (lname).elm_size)) && "\n\tExceeded Array Size"); \
		&((ltype**)(lname).data)[lind]; \
	})



//				Stacks & Queues


/*
//		Create an Stack of given type
//		Pass size & data for the stack
*/
#define mSTACK_SIZE(ltype, lname, lsize, ...) \
	ltype stack_##lname[lsize]; \
	array_t lname = { \
		.size = lsize, \
		.elm_size = sizeof(ltype), \
		.last = 0, \
		.data = &stack_##lname, \
		.type = ARRAY_STACK \
	}

/*
//		Create an Stack of given type
//		Pass size & data for the stack
*/
#define mSTACK_SIZEDATA(ltype, lname, lsize, ...) \
	ltype stack_##lname[lsize] = __VA_ARGS__; \
	array_t lname = { \
		.size = lsize, \
		.elm_size = sizeof(ltype), \
		.last = (sizeof((ltype[])__VA_ARGS__) / sizeof(ltype)) - 1, \
		.data = &stack_##lname, \
		.type = ARRAY_STACK \
	}

/*
//		Create an Queue of given type
//		Pass size & data for the stack
*/
#define mQUEUE_SIZE(ltype, lname, lsize) \
	ltype stack_##lname[lsize]; \
	array_t lname = { \
		.size = lsize, \
		.elm_size = sizeof(ltype), \
		.last = 0, .next = 0, \
		.data = &stack_##lname, \
		.type = ARRAY_QUEUE \
	}


/*
//		Push a value to the top of Stack
*/
#define mSTACK_PUSH(ltype, lname, lval) ({\
		assert(((sizeof(ltype) * (lname).last) <= ((lname).size * (lname).elm_size)) && "\n\tExceeded Array Size"); \
		((ltype*)(lname).data)[++(lname).last] = lval; \
	})

/*
//		Pull a value from the top of Stack
*/
#define mSTACK_PULL(ltype, lname) ({\
		assert(((sizeof(ltype) * (lname).last) <= ((lname).size * (lname).elm_size)) && "\n\tExceeded Array Size"); \
		((ltype*)(lname).data)[(lname).last--]; \
	})
	
	

/*
//		Push a value to the end of Queue
*/
#define mQUEUE_PUSH(ltype, lname, lval) ({\
		assert(((sizeof(ltype) * (lname).last) <= ((lname).size * (lname).elm_size)) && "\n\tExceeded Array Size"); \
		((ltype*)(lname).data)[(lname).last++] = lval; \
	})

/*
//		Pull a value at the front of Queue
*/
#define mQUEUE_PULL(ltype, lname) ({\
		assert(((sizeof(ltype) * (lname).next) <= ((lname).size * (lname).elm_size)) && "\n\tExceeded Array Size"); \
		((ltype*)(lname).data)[(lname).next++]; \
	})


/*
//		Read the topmost value of the Stack/Queue
*/
#define mQUEUE_LAST(ltype, lname) ({\
		&((ltype*)(lname).data)[(lname).last]; \
	})
	
#define mSTACK_LAST(ltype, lname) mQUEUE_LAST(ltype, lname)




//				Grids


/*
//		Create just the 2D array_t body
//		Must be given a reference to an array
*/
#define mARRAY2D_T(ltype, ly, lx, laddr) \
	{ \
		.size = lx * ly, \
		.elm_size = sizeof(ltype), \
		.width = lx, .height = ly, \
		.data = laddr, \
		.type = ARRAY_2D \
	}


/*
//		Create a 2D array of given type
//		Pass X and Y for the 2D array
*/
#define mARRAY2D_SIZE(ltype, lname, ly, lx) \
	ltype array_##lname[ly][lx] = {0}; \
	const array_t lname = { \
		.size = lx * ly, \
		.elm_size = sizeof(ltype), \
		.width = lx, \
		.height = ly, \
		.data = &array_##lname, \
		.type = ARRAY_2D \
	}

/*
//		Create a 2D array of given type
//		Pass X, Y, and Data for the 2D array
*/
#define mARRAY2D_SIZEDATA(ltype, lname, ly, lx, ...) \
	ltype array_##lname[ly][lx] = __VA_ARGS__; \
	const array_t lname = { \
		.size = lx * ly, \
		.elm_size = sizeof(ltype), \
		.width = lx, \
		.height = ly, \
		.data = &array_##lname, \
		.type = ARRAY_2D \
	}


/*
//		Access a value from a 2D array
*/
#define mARRAY2D_GET(ltype, lname, ly, lx) ({\
		assert(((sizeof(ltype) * (ly + 1)) <= ((lname).width * (lname).elm_size)) && "Exceeded Array2D X Size"); \
		assert((ly < (lname).height) && "Exceeded Array2D Y Size"); \
		((ltype(*)[(lname).width])(lname).data)[ly][lx]; \
	})

/*
//		Write a value to a 2D array
*/
#define mARRAY2D_SET(ltype, lname, ly, lx, lval) ({\
		assert(((sizeof(ltype) * (ly + 1)) <= ((lname).width * (lname).elm_size)) && "Exceeded Array2D X Size"); \
		assert((ly < (lname).height) && "Exceeded Array2D Y Size"); \
		((ltype(*)[(lname).width])(lname).data)[ly][lx] = lval; \
	})
	
/*
//		Access the address of a 2D array index
*/
#define mARRAY2D_GET_ADDR(ltype, lname, ly, lx) ({\
		assert(((sizeof(ltype) * (ly + 1)) <= ((lname).width * (lname).elm_size)) && "Exceeded Array2D X Size"); \
		assert((ly < (lname).height) && "Exceeded Array2D Y Size"); \
		&((ltype(*)[(lname).width])(lname).data)[ly][lx]; \
	})




//__________________________________________________________________//
//			Enumerations											//
//__________________________________________________________________//


enum{
	ARRAY_UNDEFINED = 0,
	ARRAY_1D,
	ARRAY_2D,
	ARRAY_STACK,
	ARRAY_QUEUE,
};




//__________________________________________________________________//
//			Struct Definition										//
//__________________________________________________________________//


typedef struct array{
	u32 elm_size;		//Size of Elements
	u32 size;			//Size in Elements
	
	
	union{
		struct{			//Stacks and Queues
			u32 last, next;		//Indexes into the Array
		};
		struct{			//Grid Arrays
			u32 width, height;	//Like Capacity
		};
	};
	
	
	u8 type;			//Holds the array's type
	const void* data;	//Pointer to data
}array_t;



