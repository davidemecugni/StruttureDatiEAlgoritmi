#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int ContaOccorrenze(const char* filename, const char* str) {
	FILE* f = fopen(filename, "r");
	int n = 0;
	if (f == NULL) {
		return 0;
	}
	if (str == NULL) {
		return 0;
	}
	/*
	long length;
	char* buffer = 0;

	if (f)
	{
		fseek(f, 0, SEEK_END);
		length = ftell(f);
		fseek(f, 0, SEEK_SET);
		buffer = malloc(length);
		if (buffer)
		{
			fread(buffer, 1, length, f);
		}
		fclose(f);
	}
	char* tmp = buffer;
	while (strstr(tmp, str) != NULL) {
		++n;
		tmp += strlen(str);
	}
	free(buffer);
	*/
	
	while (1) {
		char buf[100];
		int res = fscanf(f, "%s", buf);
		if (strcmp(buf, str) == 0) {
			++n;
		}
		if (res == -1) {
			break;
		}
	}
	fclose(f);
	return n;

}