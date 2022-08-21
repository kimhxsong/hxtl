#include "__tree.hpp"
#include <__tree>
int main()
{ 
    ft::__tree<int>  mytree;
    mytree.insert(3);
    mytree.insert(mytree.begin(),3);
    mytree.insert(mytree.begin(), mytree.end());
    mytree.erase(mytree.begin());
    mytree.erase(3);
    mytree.erase(mytree.begin(), mytree.end());

    mytree.key_comp();
    mytree.value_comp();
    mytree.find(3);
    mytree.count(3);
    mytree.upper_bound(3);
    mytree.lower_bound(3);
    mytree.equal_range(3);
    mytree.get_allocator();
    ft::__tree<int>::const_iterator cit(mytree.begin());
}