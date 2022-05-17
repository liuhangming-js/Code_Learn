#include<algorithm>
#include<iostream>
using namespace std;

template<class Type>
int Search(Type a[],const Type&x,int n){
	int left = 0;
	int right = n-1;
	while(left<=right){
		int middle = (left+right)/2;
		if(x==a[middle]){
			return middle;
		}
		if(x>a[middle]){
			left=middle-1;
		}
		else right=middle-1;
	}
	return -1;
}

int main(){
	int x,y,n;
	int a[20];
	cout << "please input n:" << endl;
	cin >> n;
	if(n<=20){
		cout << "please input a[]:" << endl;
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << "please input x:" << endl;
		cin >> x;
		sort(a,a+n);
		y=Search(a,x,n);
		cout << y+1 << endl;
	}
	return 0;
}