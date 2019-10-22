/*
		MEMORY.H
		--------
		Copyright (c) 2017-2019 Vaughan Kitchen
		Originally from https://github.com/vkitchen/cocomel
		Released under the MIT license (https://opensource.org/licenses/MIT)
*/

#pragma once

#include <stddef.h>

/*
	MEMORY_ALLOC()
	--------------
*/
/*!
		@brief Allocate memory of specified size
		@param size [in] Number of bytes of memory to allocate
		@return Pointer to the allocated memory or NULL on error
*/
void *memory_alloc(size_t size);
