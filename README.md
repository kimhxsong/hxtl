# ft_containers
My own re-implementation of a few C++ standard template library container types.

## Mandatory Part
- [ ] **vector**
- [ ] **map**
- [ ] **stack**
	- **vector** class as default underlying container.
	- It must still be compatible with other containers, the STL ones included.
- [ ] **iterators_traits**
- [ ] **reverse_iterator**
- [ ] **enable_if(C++11)**
	- It must be implemented in a C++98 manner
- [ ] **is_integral**
- [ ] **equal** and/or **lexicographical_compare**
- [ ] **std::pair**
- [ ] **std::make_pair**

## Requirements
• The namespace must be ==ft==.
• Each inner data structure used in your containers ==must be logical and justified== (this means using a simple array for map is not ok).
• ==You cannot implement more public functions== than the ones offered in the standard containers. ==Everything else must be private or protected. Each public function or variable must be justified==.
• ==All the member functions, non-member functions and overloads of the standard containers are expected==.
• ==You must follow the original naming==. Take care of details.
• If the container has an iterator system, you must implement it.
• ==You must use std::allocator==.
• ==For non-member overloads, the keyword friend is allowed==. Each use of friend must be justified and will be checked during evaluation.
• Of course, for the implementation of map::value_compare, the keyword friend is allowed.

## Testing
- You must produce two binaries that run the same tests: one with your containers only, and the other one with the STL containers.
- Compare **outputs** and **performance / timing** (your containers can be up to 20 times slower).
- Test m containers with:**ft::\<container\>**.

## Bonus Part
- [ ] **set** -- **Red-Black tree** is mandatory.
