#include <iostream>
#include <memory>
#include <string>

namespace ft {

template <typename T>
class node {
 public:
  typedef T value_type;
  typedef node<T> node_type;
  node(value_type key)
   : key(key),
     parent(0),
     left(0),
     right(0) {
    std::cout << "node::ctor\n";
  }
  ~node() {
    std::cout << "node::dtor\n";
  }
  value_type key;
  node_type* parent;
  node_type* left;
  node_type* right;
};

template <typename T, typename Alloc = std::allocator<T> >
class tree {
 public:
  typedef T value_type;
  typedef node<T> node_type;
  typedef typename Alloc::template rebind<node_type>::other allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

  explicit tree(const allocator_type& alloc = allocator_type())
    : alloc(alloc),
      root(0) {
  }

  tree(T key, const allocator_type& alloc = allocator_type())
    : alloc(alloc),
      root(this->alloc.allocate(1)) {
    this->alloc.construct(root, key);
  }

  ~tree() {
    if (root) {
      alloc.destroy(root);
      alloc.deallocate(root, 1);
    }
  }

  void insert(const value_type& key) {
    if (!root) {
      root = alloc.allocate(1);
      alloc.construct(root, key);
      return;
    }
    node_type* current = root;
    while (1) {
      if (current->key == key) {
        return;
      }
      if (current->key < key) {
        if (current->right == NULL) {
          current->right = alloc.allocate(1);
          alloc.construct(current->right, key);
          return;
        }
        current = current->right;
      } else {
        if (current->left == NULL) {
          current->left = alloc.allocate(1);
          alloc.construct(current->left, key);
          return;
        }
        current = current->left;
      }
    }
  }

  void erase(const value_type& key) {
    if (!root) {
      return;
    }
    node_type* current = root;
    while (1) {
      if (current->key == key)
        break;
      if (key < current->key) {
        if (current->left == NULL) {
          return;
        }
        if (current->left->key == key) {
          if (!current->left->right && !current->right->left) {
            alloc.deallocate(current->left);
            current->left = NULL;
          } else if (current->left->left && current->left->right) {
            
            
          } else {

          }
        }
        current = current->left;
      } else {
        if (current->right == NULL) {
          return;
        }
        if (current->right->key == key) {
          //
        }
      }
    }
  }

 private:
  allocator_type alloc;
  node_type* root;
};

}  // namespace ft

int main() {
  {
    ft::tree<int> mytree1;
    mytree1.insert(1);
    mytree1.insert(12);
    mytree1.insert(4);
  }
}