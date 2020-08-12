//�л��� ��Ÿ�� �� �ִ� ������ �̸�, ����,��������� ��
//�л��� ���� ������� �����ϰ��� �Ѵ�. 
//�ٸ� ������ ������ ��� ���̰� �� � �л��� �� �켱������ ����. 

//���� ������ ���� ���� ��, ������ ���� ��� ���̰� �� � ���

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int>> a,
	pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}

int main(void) {
	vector<pair<string, pair<int, int>>> v;
	v.push_back(pair<string, pair<int, int>>("������", make_pair(90, 19961212)));
	v.push_back(pair<string, pair<int, int>>("������", make_pair(97, 19930518)));
	v.push_back(pair<string, pair<int, int>>("���ѿ�", make_pair(95, 19930203)));
	v.push_back(pair<string, pair<int, int>>("�̻��", make_pair(90, 19921207)));
	v.push_back(pair<string, pair<int, int>>("������", make_pair(88, 19900302)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
	return 0;
}