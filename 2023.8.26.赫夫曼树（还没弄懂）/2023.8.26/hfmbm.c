#include<stdio.h>
#include<stdlib.h>
#include "huffman.h"

int main(void)
{
	httree *codetree = buildtree("I love fishc.com!");
	hltable *codetable = buildtable(codetree);
	encode(codetable,"I love fishc.com!");
	decode(codetree,"0011111000111");
	return 0;
}
