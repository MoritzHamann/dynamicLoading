all: version1 version2
	clang main.c -o dynamicLoading

version1:
	clang -dynamiclib -std=gnu99 version1.c -o libverison1.A.dylib

version2:
	clang -dynamiclib -std=gnu99 version2.c -o libverison2.A.dylib
