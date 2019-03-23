#include <stdio.h>
#include <iostream>

using namespace std;

// 최대 마진 저장 변수. Int가 아닌 long을 써야 함.
long long max_margin = 0;
// 비용을 담을 수 있는 배열 선언. 인덱스 편의를 위해 +1 해줌.
int cost[1000001];
// 현재 팔 것으로 기억하는 시점의 판매 비용.
int cur_max;

int main()
{
   int test_case;
   scanf("%d", &test_case);

   // test_case 수 만큼 반복
   for (int t = 1; t <= test_case; t++)
   {
      cout << "#" << t << " ";
      // 각 test_case의 매매일수를 담을 변수 선언 후 담기.
      int days;
      scanf("%d", &days);
      // 각 일의 매매가 배열에 담기.
      for (int d = 1; d <= days; d++)
      {
         scanf("%d", &cost[d]);
      }
      // 마지막 날 매매가를 현재 최대 매매값으로 초기화.
      cur_max = cost[days];
      for (int d = days; d >= 1; d--)
      {
         if (cost[d] > cur_max)
            cur_max = cost[d];
         max_margin += cur_max - cost[d];
      }
      cout << max_margin << endl;
      max_margin = 0;
   }
   return 0;
}