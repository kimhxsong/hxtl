#include "./map.hpp"

#include <iostream>

#include <__tree>
#include "../utility/utility.hpp"

int main()
{
  {
    ft::map<char, int> mymap;
    mymap.insert(ft::make_pair<const char, int>('a', 1));
    mymap.insert(ft::make_pair<const char, int>('b', 2));
    mymap.insert(ft::make_pair<const char, int>('c', 3));
    std::cout << "test" << std::endl;
    for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end();
         it++)
    {
      std::cout << "test" << std::endl;
      std::cout << it->first << " " << it->second << std::endl;
    }
  }
}