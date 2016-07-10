/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1113

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int main()
{
		int T, N, S, Q;
		cin >> T;

		while(T)
		{
				stack<int> carrier;
				queue<int> station[100];
				cin >> N >> S >> Q;

				for (int i = 0; i < N; i++)
				{
					int value;
					cin >> value;
					for (int j = 0; j < value; j++)
					{
						int target;
						cin >> target;
						station[i].push(target - 1);
					}
				}

				int currentPosition = 0, minutes = 0;
						while (true)
						{
							while (!carrier.empty()	&&
							      (carrier.top() == currentPosition ||
										 station[currentPosition].size() < Q))
								{
									if (carrier.top() != currentPosition)
									{
										station[currentPosition].push(carrier.top());
									}
									carrier.pop();
									minutes++;
								}

								while (!station[currentPosition].empty()  && (carrier.size() < S))
								{
									carrier.push(station[currentPosition].front());
									station[currentPosition].pop();
									minutes++;
								}

								bool clear = carrier.empty();
								for (int i = 0; i < N; i++)
								{
									clear &= station[i].empty();
								}
								if (clear) break;

								currentPosition = (currentPosition + 1) % N;
								minutes += 2;
						}
				cout << minutes << endl;
				T--;
		}

	return 0;
}
