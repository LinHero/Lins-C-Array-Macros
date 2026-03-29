


#pragma once


#include <stdint.h>
#include <assert.h>




//__________________________________________________________________//
//			Macros & Defines										//
//__________________________________________________________________//


/*
//		Quickly generate Gets/Sets of the given type
*/
#define mCREATE_GETSET(T) \
	static inline T get_##T(const array_t* from, u32 at){ \
		assert(((sizeof(T) * (at + 1)) <= from->capacity) && "Exceeded Array Size"); \
		return ((T*)from->data)[at]; \
	} \
	static inline void set_##T(const array_t* from, u32 at, T v){ \
		assert(((sizeof(T) * (at + 1)) <= from->capacity) && "Exceeded Array Size"); \
		((T*)from->data)[at] = v; \
	} \
	static inline T* get_##T##_addr(const array_t* from, u32 at){ \
		assert(((sizeof(T*) * (at + 1)) <= from->capacity) && "Exceeded Array Size"); \
		return &((T*)from->data)[at]; \
	}

/*
//		Quickly generate Gets/Sets of the given type's pointer
*/
#define mCREATE_GETSET_PTR(T) \
	static inline T* get_##T##_ptr(const array_t* from, u32 at){ \
		assert(((sizeof(T*) * (at + 1)) <= from->capacity) && "Exceeded Array Size"); \
		return ((T**)from->data)[at]; \
	} \
	static inline void set_##T##_ptr(const array_t* from, u32 at, T* v){ \
		assert(((sizeof(T*) * (at + 1)) <= from->capacity) && "Exceeded Array Size"); \
		((T**)from->data)[at] = v; \
	}




/*
//		Create an array of given type
//		Pass data for said type
*/
#define mARRAY_DATA(ltype, lname, ...) \
	ltype array_##lname[] = (ltype[])__VA_ARGS__; \
	const array_t lname = { \
		.size = sizeof((ltype[])__VA_ARGS__) / sizeof(ltype), \
		.capacity = sizeof((ltype[])__VA_ARGS__), \
		.data = &array_##lname \
	}

/*
//		Create an array of given type
//		Pass size for the array
*/
#define mARRAY_SIZE(ltype, lname, lsize) \
	ltype array_##lname[lsize]; \
	const array_t lname = { \
		.size = lsize, \
		.capacity = lsize * sizeof(ltype), \
		.data = &array_##lname \
	}

/*
//		Create an array of given type
//		Pass size & data for the array
*/
#define mARRAY_SIZEDATA(ltype, lname, lsize, ...) \
	ltype array_##lname[lsize] = (ltype[])__VA_ARGS__;; \
	const array_t name = { \
		.size = lsize, \
		.capacity = lsize * sizeof(ltype), \
		.data = &array_##lname \
	}


/*
//		Create an array of given type's pointer
//		Pass data for said type's ptr
*/
#define mARRAY_DATA_PTR(ltype, lname, ...) \
	ltype* array_##lname[] = (ltype*[])__VA_ARGS__; \
	const array_t lname = { \
		.size = sizeof((ltype*[])__VA_ARGS__) / sizeof(ltype), \
		.capacity = sizeof((ltype*[])__VA_ARGS__), \
		.data = &array_##lname \
	}

/*
//		Create an array of given type's pointer
//		Pass size for the array
*/
#define mARRAY_SIZE_PTR(ltype, lname, lsize) \
	ltype* array_##lname[lsize]; \
	const array_t lname = { \
		.size = lsize, \
		.capacity = lsize * sizeof(ltype), \
		.data = &array_##lname \
	}

/*
//		Create an array of given type's pointer
//		Pass size & data for the array
*/
#define mARRAY_SIZEDATA_PTR(ltype, lname, lsize, ...) \
	ltype* array_##lname[lsize] = (ltype*[])__VA_ARGS__;; \
	const array_t name = { \
		.size = lsize, \
		.capacity = lsize * sizeof(ltype*), \
		.data = &array_##lname \
	}




/*
//		Access a value from an array
*/
#define mARRAY_GET(ltype, lname, lind) \
	get_##ltype(&lname, lind)

/*
//		Write a value to an array
*/
#define mARRAY_SET(ltype, lname, lind, lval) \
	set_##ltype(&lname, lind, lval)

/*
//		Access the address of an array index
*/
#define mARRAY_GET_ADDR(ltype, lname, lind) \
	get_##ltype##_addr(&lname, lind)

/*
//		Access a pointer from an array
*/
#define mARRAY_GET_PTR(ltype, lname, lind) \
	get_##ltype##_ptr(&lname, lind)

/*
//		Write a pointer to an array
*/
#define mARRAY_SET_PTR(ltype, lname, lind, lval) \
	set_##ltype##_ptr(&lname, lind, lval)




//__________________________________________________________________//
//			Struct Definition										//
//__________________________________________________________________//


typedef struct array{
	u32 size;			//Size in Elements
	u32 capacity;		//Size in Bytes
	const void* data;	//Pointer to data
}array_t;




//__________________________________________________________________//
//			Function Definition										//
//__________________________________________________________________//


mCREATE_GETSET(uint8_t);
mCREATE_GETSET(uint16_t);
mCREATE_GETSET(uint32_t);
mCREATE_GETSET(float);

mCREATE_GETSET_PTR(uint8_t);
mCREATE_GETSET_PTR(uint16_t);
mCREATE_GETSET_PTR(uint32_t);
mCREATE_GETSET_PTR(float);


