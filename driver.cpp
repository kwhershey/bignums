/* -*-indent-tabs-mode: t; c-basic-offset: 8 -*- */
//handles adding, subtracting, multiplying and dividing positive integers.

#include <iostream>
#include <vector>
#include <fstream>
#include "bignums.h"

using namespace std;

int main(){
	vector<short> a,b,sum;
	ifstream nums;
	nums.open ("numsToMult.txt");
	char c;
	nums.get(c);
	while(nums && c !=' '){
		a.push_back(c-48);
		nums.get(c);
	}
	//get b
	nums.get(c);
	while(nums && c !=' '){
		b.push_back(c-48);
		nums.get(c);
	}

	print(a);
	print(b);

	if(greaterEq(a,b))
		cout << "greaterEq\n";

	sum=reverse(a);
	print(sum);

	sum=multiply(a,b);
	print(sum);

	sum=multiply(a,a);
	print(sum);

	sum=subtract(b,a);
	print(sum);

	// sum=divide(a,b);
	sum=subtract(a,b);
	print(sum);

	sum=add(a,b);
	print(sum);

	sum=add(a,a);
	sum=add(sum,a);
	print(sum);
	return 0;
}
