#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/__tree"
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/map"

template <typename K, typename T>
class mymap : public std::map<K, T> {};

template <typename K, typename T>
class mytree : public std::__tree<K, T> {};

int main() {
  mymap<char, int> mymap;
  for (int) mytree mytree;
}