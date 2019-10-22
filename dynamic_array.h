/*
		DYNAMIC_ARRAY.H
		---------------
		Copyright (c) 2017-2019 Vaughan Kitchen
		Originally from https://github.com/vkitchen/cocomel
		Released under the MIT license (https://opensource.org/licenses/MIT)
*/
#pragma once

#include <stdint.h>
#include <stdlib.h>
#include "memory.h"

template <typename T>
class dynamic_array
	{
	public:
		uint32_t capacity = 256;
		uint32_t length = 0;
		T *store;

	public:
		static void *operator new(size_t size)
			{
			return memory_alloc(size);
			}

		dynamic_array()
			{
			store = (T *)malloc(capacity * sizeof(T));
			}

		void append(T val)
			{
			if (length == capacity)
				{
				capacity *= 2;
				store = (T *)realloc(store, capacity * sizeof(T));
				}
			store[length] = val;
			length++;
			}

		T *back()
			{
			return &store[length-1];
			}
	};
