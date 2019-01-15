#include <string>
#include <unordered_map>

namespace Roman
{
  const std::unordered_map<int, std::string> symbols = {
    {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"},
    {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"},
    {10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"}, {50, "L"},
    {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"},
    {100, "C"}, {200, "CC"}, {300, "CCC"}, {400, "CD"}, {500, "D"},
    {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"}, {1000, "M"}
  };

  auto convert(int number) -> std::string
  {
    std::string solution {};
    if(number >= 1000)
    {
      solution += std::string(number / 1000, 'M');
      number %= 1000;
    }

    int divisor {100};
    while(number != 0)
    {
      int index = (number / divisor) * divisor;
      if(index != 0)
      {
        solution += symbols.at(index);
      }
      number %= divisor;
      divisor /= 10;
    }
    return solution;
  }
}