// 행복 유치원 원장인 태양이는 어느 날 N명의 원생들을 키 순서대로 일렬로 줄 세우고, 총 K개의 조로 나누려고 한다.
// 각 조에는 원생이 적어도 한 명 있어야 하며, 같은 조에 속한 원생들은 서로 인접해 있어야 한다.조별로 인원수가 같을 필요는 없다.

// 이렇게 나뉘어진 조들은 각자 단체 티셔츠를 맞추려고 한다.조마다 티셔츠를 맞추는 비용은 조에서 가장 키가 큰 원생과 가장 키가 작은 원생의 키 차이만큼 든다.
// 최대한 비용을 아끼고 싶어 하는 태양이는 K개의 조에 대해 티셔츠 만드는 비용의 합을 최소로 하고 싶어한다.태양이를 도와 최소의 비용을 구하자.

// 입력 입력의 첫 줄에는 유치원에 있는 원생의 수를 나타내는 자연수 N(1 ≤ N ≤ 300, 000) 과 나누려고 하는 조의 개수를 나타내는 자연수 K(1 ≤ K ≤ N) 가 공백으로 구분되어 주어진다.
// 다음 줄에는 원생들의 키를 나타내는 N개의 자연수가 공백으로 구분되어 줄 서 있는 순서대로 주어진다.
// 태양이는 원생들을 키 순서대로 줄 세웠으므로, 왼쪽에 있는 원생이 오른쪽에 있는 원생보다 크지 않다.원생의 키는 109를 넘지 않는 자연수이다.
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> diff(n - 1);
	for (int i = 0; i < n - 1; i++)
		diff[i] = arr[i + 1] - arr[i];
	sort(diff.begin(), diff.end(), greater<int>());
	int result = 0;
	for (int i = k - 1; i < n - 1; i++)
		result += diff[i];
	cout << result << endl;
}