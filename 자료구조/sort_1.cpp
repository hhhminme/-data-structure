#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

//���� ���̹������� ��� ���̺귯���� �̿��� ���ڵ�
int main(void) {
	vector<pair<int, string>> v; 
	v.push_back(pair<int, string>(90,"park"));
	v.push_back(pair<int, string>(85, "lee"));
	v.push_back(pair<int, string>(82, "na"));
	v.push_back(pair<int, string>(87, "kang"));
	v.push_back(pair<int, string>(79, "choi"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
	}
	return 0; 
}