#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol125;

/*
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
*/

tuple<string, string>
testFixture1()
{
  return make_tuple("babad", "bab");
}
/*
Input: "cbbd"
Output: "bb"
*/

tuple<string, string>
testFixture2()
{
  return make_tuple("cbbd", "bb");
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.longestPalindrome(get<0>(f)) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.longestPalindrome(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}