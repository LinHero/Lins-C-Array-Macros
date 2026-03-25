


#pragma once


#include <stdint.h>
#include <assert.h>

#include "dtypes.h"



//__________________________________________________________________//
//			Macros													//
//__________________________________________________________________//


/*
//		Quickly generate Gets/Sets of the given type
*/
#define mCREATE_GETSET(T) \
	T get_##T(const array_t* from, u32 at){ \
		assert((at < from->size) && "Exceeded size of array"); \
		assert(((sizeof(T) * (at + 1)) <= from->capacity) && "Request exceeds array size"); \
		return ((T*)from->data)[at]; } \
	void set_##T(const array_t* from, u32 at, T v){ \
		assert((at < from->size) && "Exceeded size of array"); \
		assert(((sizeof(T) * (at + 1)) <= from->capacity) && "Request exceeds array size"); \
		((T*)from->data)[at] = (T)v; }

/*
//		Quickly generate Gets/Sets Refs of the given type
*/
#define mCREATE_GETSET_REF(T) \
	T get_##T(const array_t* from, u32 at); \
	void set_##T(const array_t* from, u32 at, T v);


/*
//		Create an array of given type
//		Pass data for said type
*/
#define mARRAY_DATA(type, name, ...) \
	type array_##name[] = (type[])__VA_ARGS__; \
	const array_t name = { \
		.size = sizeof((type[])__VA_ARGS__) / sizeof(type), \
		.capacity = sizeof((type[])__VA_ARGS__), \
		.data = &array_##name }

/*
//		Create an array of given type
//		Pass size for the array
*/
#define mARRAY_SIZE(type, name, size) \
	type array_##name[size]; \
	const array_t name = { \
		.size = size, \
		.capacity = size * sizeof(type), \
		.data = &array_##name }

/*
//		Create an array of given type
//		Pass size & data for the array
*/
#define mARRAY_SDAT(type, name, size, ...) \
	type array_##name[size] = (type[])__VA_ARGS__; \
	const array_t name = { \
		.size = size, \
		.capacity = size * sizeof(type), \
		.data = &array_##name }




//__________________________________________________________________//
//			Struct Declaration										//
//__________________________________________________________________//


typedef struct array{
	u32 size;		//Defines size in Elements
	u32 capacity;	//Defines size in Bytes
	const void* data;
}array_t;




//__________________________________________________________________//
//			Function Declaration									//
//__________________________________________________________________//


mGETSET_REF(u8);
mGETSET_REF(u16);
mGETSET_REF(u32);
mGETSET_REF(float);



