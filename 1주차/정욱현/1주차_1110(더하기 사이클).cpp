#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
int n, cycle, newn, f, b;

// �� �ڵ忡 �� ��°��� �ȳ������� �𸣰ڴ�  
int main(){
	newn = -1;
	cin >> n;
	cycle = 0;
	while (n!=newn){
		if(n >= 10){
			b = ((n / 10) + (n % 10)) % 10;
			f = n % 10;
			newn = (f * 10) + b;
			cycle++;
		}
		else{
			newn = (n * 10) + n;
			cycle++ ;
		}
	}
	cout << cycle;
	return 0;
} 
