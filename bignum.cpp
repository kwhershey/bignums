//handles adding, subtracting, multiplying and dividing positive integers.

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool greaterEq(vector<short>, vector<short>);
vector<short> reverse(vector<short>);
vector<short> add(vector<short>, vector<short>);
vector<short> subtract(vector<short>, vector<short>);
vector<short> multiply(vector<short>, vector<short>);
vector<short> divide(vector<short>, vector<short>);

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


	for(int i=0;i<a.size();i++){
		cout <<a[i];
	}
	cout << endl;
	for(int i=0;i<b.size();i++){
		cout <<b[i];
	}

	//if(greaterEq(a,b))
	//	cout << "greaterEq\n";
	sum=multiply(a,b);
	cout << endl;
	for(int i=0;i<sum.size();i++){
		cout <<sum[i];
	}
	cout << endl;

	return 0;
}

//returns if a is greater than or equal to b
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

vector<short> reverse(vector<short> a)
{
	short temp;
	for(int i =0;i<a.size()/2;i++){
		temp=a[i];
		a[i]=a[a.size()-i-1];
		a[a.size()-i-1]=temp;
	}
	return a;
}

vector<short> add(vector<short> a, vector<short> b)
{
	vector<short> sum;
	short carry=0;
	short digitSum=0;

	while(a.size()>0 || b.size()>0){
		digitSum=0;
		if(a.size()>0){
			digitSum+=a.back();
			a.pop_back();
		}
		if(b.size()>0){
			digitSum+=b.back();
			b.pop_back();
		}
		sum.push_back((digitSum+carry)%10);
		carry=(digitSum+carry)/10;
	}
	if(carry/10!=0)
		sum.push_back(carry);
	sum=reverse(sum);
	return sum;
}

//returns a-b
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
			while((a.size()-i)==0){
				a[a.size()-i]=9;
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
	while(diff.size()>1 &&diff.back()==0){
		diff.pop_back();
	}
	diff=reverse(diff);

	return diff;
}

vector<short> multiply(vector<short> a, vector<short> b)
{
	vector<short> product;
	short digit;

	while(b.size()>0){
		digit=b.back();
		b.pop_back();
		for(digit;digit>0;digit--){
			product=add(product,a);
		}
		a.push_back(0);
	}

	return product;
}

//incomplete
vector<short> divide(vector<short> a, vector<short> b)
{
	vector<short> ans, testVec,multiplier;
	if(!greaterEq(a,b)){
		ans.push_back(0);
		return ans;
	}
	a=reverse(a);
	multiplier.push_back(1);
	while(a.size()>0){
		testVec.push_back(a.back());
		a.pop_back();
		while(!greaterEq(testVec,b)){
			testVec.push_back(a.back());
			a.pop_back();
		}
		multiplier[0]=1;
		while(greaterEq(testVec,multiply(b,multiplier)))
			multiplier[0]=multiplier[0]+1;
		ans.push_back(multiplier[0]=multiplier[0]-1);
		testVec=subtract(testVec,multiply(b,multiplier));
	}
	return ans;
}
