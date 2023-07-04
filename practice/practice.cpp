#include <iostream>
#include <cstdlib>
#include <array>
#include <algorithm>

int main()
{
  srand(static_cast<unsigned int>(time(NULL)));
  std::array<unsigned char, 4> n;
  //unsigned short input = 0;

  //for (int i = 0; i < 4; ++i) {  // for_each
  //  input = 1 + rand() % 9;
  //  n[i] = static_cast<unsigned char>(input);
  //  for (int j = 0; j < i; j++) {
  //    if (n[j] == n[i]) {
  //      i--;
  //      break;
  //    }
  //  }
  //}
  auto f = [&n](unsigned char& input) {
    input = static_cast<unsigned char>(1 + rand() % 9);
    while (std::count(n.begin(), n.end(), input) > 1) {
      input = static_cast<unsigned char>(1 + std::rand() % 9);
    }
  };

  std::for_each(n.begin(), n.end(), f);
  

  for (int i = 0; i < 4; i++) {
    std::cout << static_cast<int>(n[i]);
  }

  return 0;

}

