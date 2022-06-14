#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol125;
using namespace std;

/*takeaways
  - DP
    - time complexity O(n^2)
  - everyone takes turns to be the center and tries to extend the substring
    to the left and right as long as it maintains a palindrome
    - given i the center can be (i) or (i,i+1) depending on the number of
      char of the palindrome
  - record the max length along with the corresponding start
    position so we can later return the string

*/
string Solution::longestPalindrome(string s)
{
  int maxLen = 0, start = 0, n = s.size() - 1;

  for (auto i = 0; i < n; i++)
  {
    /* i serves the center or (i, i+1) serves as the center */
    auto len = max(getLen(i, i, s), getLen(i, i + 1, s));

    if (len > maxLen)
      /* don't forget i is the smaller one in the center pair
         - "baab", i=1
         - start = 1 - (4 - 1)/2 = 1 - 1 = 0
         - this why you need to subtract 1 from the maxLen
      */
      maxLen = len, start = i - (maxLen - 1) / 2;
  }

  return s.substr(start, maxLen);
}

int Solution::getLen(int l, int r, const string &s)
{
  int n = s.size();
  while (l >= 0 && r < n && s[l] == s[r])
    /* expand the palindrome */
    l--, r++;
  /* l and r will be pointing at a location outside
     the palindrome
     - so you need to subtract 2 from the total length
     - this also works for edge cases like "ba", where
       b and a are considered as the center of a
       palindrome that has an even number of chars
       1 - 0 + 1 - 2 = 0
  */
  return r - l + 1 - 2;
}
