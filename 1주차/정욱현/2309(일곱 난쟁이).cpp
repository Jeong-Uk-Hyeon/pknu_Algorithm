#include <bits/stdc++.h> //c++ ǥ�ض��̺귯�� ���� �ִ� �ش�
using namespace std; // ǥ�ض��̺귯�� �Լ� �Լ������� ����ϰԲ� ���� 
#define fastio cin.tie(0), ios_base::sync_with_stdio(0) // ����� �ӵ���� 

int arr[9];
int sum;

void f(){ // ��¥ �����̸� ã�� �Լ�  
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (i==j) continue;
			if (sum - (arr[i] + arr[j]) == 100){
				arr[i] = arr[j] = -1; // �������� Ű�� ����̹Ƿ� ��¥ �����̵��� -1�� �����ϰ� �����ϸ� 2~8�� �ε����� ��¥ ������ 
				return;
			}
		}
	}
}
int main(){
	sum = 0;
	stdio;
	for(int i =0; i < 9; i++){
		cin >> arr[i]; // ������ std::cin C++�� ��� ����¿� Ÿ�� �������� �ʿ���� 
		sum += arr[i];
	}
	f();
	sort(arr, arr + 9); // ������ std::sort() �迭�� ���۰� ���� �����ְ� ���Ľ�Ű�� �Լ� 
	for (int i = 2; i < 9; i++) cout << arr[i] << '\n'; // << ��Ʈ�� ���� ���δٸ� Ÿ�� ������ <<�� ��ħ 
	return 0;
}
 
