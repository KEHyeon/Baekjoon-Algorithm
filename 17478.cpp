#include <bits/stdc++.h>
using namespace std;
int n;
void p(int num) {
	for(int i = 0; i < num * 4; i++) cout << "_";
	cout << "\"����Լ��� ������?\"\n";
	for(int i = 0; i < num * 4; i++) cout << "_";
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	for(int i = 0; i < num * 4; i++) cout << "_";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	for(int i = 0; i < num * 4; i++) cout << "_";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
}
void r(int num) {
	if(num == n) {
		for(int i = 0; i < num * 4; i++) cout << "_";
		cout << "\"����Լ��� ������?\"\n";
		for(int i = 0; i < num * 4; i++) cout << "_";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for(int i = 0; i < num * 4; i++) cout << "_";
		cout << "��� �亯�Ͽ���.\n";
		return;
		
	}
	p(num);
	r(num + 1);
	for(int i = 0; i < num * 4; i++) cout << "_";
	cout << "��� �亯�Ͽ���.\n";
}
int main() {
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	r(0);
	
}
