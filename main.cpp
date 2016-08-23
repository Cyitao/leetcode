#include <iostream>
#include <vector>
#include<ctime>
#include "base.h"
#include "FileComparess.h"
#include "HaffmanTree.h"
#include "Heap.h"

#define _FILE_NAME_ "D:/3-01.avi"

int main()
{
	FileComparess f;
	clock_t start1, start2, finish1, finish2;
	start1 = clock();
	f.compress(_FILE_NAME_);
	finish1 = clock();
	start2 = clock();
	f.uncompress(_FILE_NAME_);
	finish2 = clock();

	cout <<"Ñ¹Ëõ£º"<< finish1 - start1 << "/" << CLOCKS_PER_SEC << " (s) " << endl;
	cout <<"½âÑ¹Ëõ£º"<< finish2 - start2 << "/" << CLOCKS_PER_SEC << " (s) " << endl;
	return 0;
}