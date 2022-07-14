#include <vector>

#include "iterator_iterator.hpp"
#include "iterator_iterator_traits.hpp"

class vec {
 public:
    typedef int value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef ft::iterator_traits<int*> iterator;
    typedef ft::iterator_traits<const int*> const_iterator;
};

int main()
{
    vec::iterator vi;
    std::vector<int>::iterator vi2;
    vi2++;
}