/*
		MAIN.CPP
		--------
		Copyright (c) 2018-2019 Vaughan Kitchen
		Originally from https://github.com/vkitchen/cocomel
		Released under the MIT license (https://opensource.org/licenses/MIT)
*/
#include <stdio.h>
#include <stdint.h>
#include <utility>
#include "dynamic_array.h"
#include "tokenizer.h"
#include "str.h"
#include "file.h"

const char *usage = "\
Usage: wsjrep [file ...]\
";

int main(int argc, char **argv)
	{
	if (argc < 2)
		{
		puts(usage);
		return 1;
		}

	// Accept input
	char line[1024];
	if (fgets(line, sizeof(line), stdin) == NULL)
		{
		printf("ERROR: No input provided\n");
		exit(1);
		}
	line[strlen(line)-1] = '\0';

	// Search
	char tok_buffer_store[516]; // Provide underlying storage for tok_buffer
	str tok_buffer(tok_buffer_store);
	enum token_type token;

	dynamic_array<std::pair<char *, uint32_t>> docNos;
	dynamic_array<uint32_t> results;

	tokenizer tok;

	for (int i = 1; i < argc; i++)
		{
		char *file;
		size_t file_length = file_slurp(argv[i], &file);
		tok.init(file, file_length);
		do
			{
			token = tok.next(tok_buffer);
			if (token == DOCNO)
				docNos.append(std::make_pair(tok_buffer.c_dup(), 0));
			if ((results.length == 0 || *results.back() != docNos.length) && string_cmp(line, tok_buffer.c_str()) == 0)
				results.append(docNos.length);
			} while (token != END);
		}

	for (uint32_t i = 0; i < results.length; i++)
		printf("%s\n", docNos.store[i].first);

	return 0;
	}
