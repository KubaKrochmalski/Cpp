#include <vector>
#include <unordered_map>
#include <algorithm>

// Given an array, find the int that appears an odd number of times.
// There will always be only one integer that appears an odd number of times.
auto findOdd(const std::vector<int>& numbers) -> int
{
  std::unordered_map<int, int> occurrences {};
  for(auto num : numbers)
  {
    occurrences[num]++;
  }

  auto result = std::find_if(std::begin(occurrences), std::end(occurrences), [](const auto& entry){
    return entry.second % 2 != 0;}
  );

  return result->first;
}

// Recursive sum of all the digits in a number.
auto digitalRoot(int n) -> int
{
  auto sumOfDigits = [](int num){
    int sum {};
    while(num != 0)
    {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  };

  int sum = sumOfDigits(n);
  return sum < 10 ? sum : digitalRoot(sum);
}