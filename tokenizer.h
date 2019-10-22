/*
		TOKENIZER.H
		-----------
		Copyright (c) 2018-2019 Vaughan Kitchen
		Originally from https://github.com/vkitchen/cocomel
		Released under the MIT license (https://opensource.org/licenses/MIT)
*/
#pragma once

#include "memory.h"
#include "str.h"

enum token_type {DOCNO, WORD, END};

class tokenizer
	{
	private:
		size_t index = 0;
		size_t length;
		char *document;

	public:
		static void *operator new(size_t size)
			{
			return memory_alloc(size);
			}

		void init(char *doc, size_t len)
			{
			document = doc;
			length = len;
			}

		enum token_type next(str buffer);
	};
