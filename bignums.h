/* -*-indent-tabs-mode: t; c-basic-offset: 8 -*- */
//handles adding, subtracting, multiplying and dividing positive integers.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<short>);
bool greaterEq(vector<short>, vector<short>);
vector<short> reverse(vector<short>);
vector<short> add(vector<short>, vector<short>);
vector<short> subtract(vector<short>, vector<short>);
vector<short> multiply(vector<short>, vector<short>);
vector<short> divide(vector<short>, vector<short>);

//prints out a number
void print(vector<short> a)
{
	for(int i=0;i<a.size();i++){
		cout <<a[i];
	}
	cout << endl;
}

//returns a>=b
//fully functioning for positive numbers
bool greaterEq(vector<short> a, vector<short> b)
{
	if(a.size()>b.size())
		return true;
	if(b.size()>a.size())
		return false;
	for(int i=0;i<a.size();i++){
		if(a[i]>b[i])
			return true;
		if(b[i]>a[i])
			return false;
	}
	return true;
}

//reverses a vector.  Needed for add, sub, and divide
//fully functioning for positive
vector<short> reverse(vector<short> a)
{
	for(int i=0; i<a.size()/2; i++){
		swap(a[i], a[a.size()-i-1]);
	}
	return a;
}

//returns a+b
//functioning for positive ints
vector<short> add(vector<short> a, vector<short> b)
{
	// store the result in a
	int i;
	short carry=0;

	// we assume a >= b
	if(!greaterEq(a, b))
		swap(a, b);

	a = reverse(a);
	for(i=0; b.size() > 0; i++)
	{
		a[i] += b.back() + carry;
		carry = a[i] / 10;
		a[i] %= 10;
		b.pop_back();
	}

	if (i >= a.size() && carry)
		a.push_back(carry);

	return reverse(a);
}

//returns a-b
//funtioning for positive ints.  b can be greater than a
vector<short> subtract(vector<short> a, vector<short> b){
	vector<short> diff;
	if(!greaterEq(a,b)){
		diff = subtract(b,a);
		diff[0] = -diff[0];
		return diff;
	}
	while(b.size()>0){
		if(a.back() < b.back()){
			int i=2;
			while(a[a.size()-i] == 0){
				a[a.size()-i] = 9;
				i++;
			}
			a[a.size()-i]--;
			a.back()+=10;
		}
		diff.push_back(a.back()-b.back());
		a.pop_back();
		b.pop_back();
	}
	while(a.size()>0){
		diff.push_back(a.back());
		a.pop_back();
	}
	while(diff.size()>1 && diff.back()==0){
		diff.pop_back();
	}
	diff=reverse(diff);

	return diff;
}

//returns a*b
//has worked for my test cases
vector<short> multiply(vector<short> a, vector<short> b)
{
	vector<short> product;
	short digit;
	product.push_back(0);

	while(b.size()>0){
		/* the following could all be:
		   for(digit = d.back(), b.pop_back(); digit > 0; digit--)
			product = add(product, a);
		*/
		digit=b.back();
		b.pop_back();
		while(digit > 0) {
			product=add(product,a);
			digit--;
		}
		a.push_back(0);
	}

	return product;
}

//returns a/b
//incomplete
vector<short> divide(vector<short> a, vector<short> b)
{
	vector<short> ans, testVec,multiplier;
	if(!greaterEq(a,b)){ //handles the 0 case
		ans.push_back(0);
		return ans;
	}
	a=reverse(a);
	multiplier.push_back(1);
	while(a.size()>0){
		if(testVec.size()>0 && testVec[0]==0){
			testVec[0]=a.back();}
		else{
			testVec.push_back(a.back());}
		a.pop_back();
		while(!greaterEq(testVec,b) && a.size()>0){
			testVec.push_back(a.back());
			a.pop_back();
			print(a);
		}
		multiplier[0]=1;
		while(greaterEq(testVec,multiply(b,multiplier))){
			multiplier[0]=multiplier[0]+1;
		}
		ans.push_back(multiplier[0]=multiplier[0]-1);
		testVec=subtract(testVec,multiply(b,multiplier));
	}
	return ans;
}
