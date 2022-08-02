#include <cstddef>

#include <memory>
#include <vector>
#include <__tree>

namespace ft {

template <typename T>
struct Less {
  bool operator()(const T& lhs, const T& rhs) const {
      return lhs < rhs;
  }
};

template <typename T, typename Comp = Less<T> >
class hx_tree_node {
 public:
  typedef T value_type;
  typedef Comp value_compare;
  typedef hx_tree_node<T, Comp> node_type;
  typedef node_type* node_type*;

  explicit hx_tree_node(const value_type& value = value_type())
    : value_(value),
      parent_(0),
      left_(0),
      right_(0) {}

  const value_type& value() const { return value_; }
  node_type* left() const { return left_; }
  node_type* right() const { return right_; }
  node_type* parent() const { return parent_; }

//  private:  // TO RETURN
  value_type value_;
  node_type* parent_;
  node_type* left_;
  node_type* right_;
};

// 이터레이터에서 비교연산이 필요하기 때문에 전역에 선언되어 있어야 함.
template <typename T, typename Comp>
bool operator==(const hx_tree_node<T, Comp>& lhs, const hx_tree_node<T, Comp>& rhs) {
  return lhs.value() == rhs.value();
}

template <typename T, typename Comp>
bool operator!=(const hx_tree_node<T, Comp>& lhs, const hx_tree_node<T, Comp>& rhs) {
  return !(lhs.value() == rhs.value());
}

template <typename T, typename Comp>
bool operator<(const hx_tree_node<T, Comp>& lhs, const hx_tree_node<T, Comp>& rhs) {
  return typename hx_tree_node<T, Comp>::value_compare()(lhs.value(), rhs.value());
}

template <typename T, typename Comp>
bool operator>(const hx_tree_node<T, Comp>& lhs, const hx_tree_node<T, Comp>& rhs) {
  return rhs < lhs;
}

template <typename T, typename Comp>
bool operator<=(const hx_tree_node<T, Comp>& lhs, const hx_tree_node<T, Comp>& rhs) {
  return !(lhs > rhs);
}

template <typename T, typename Comp>
bool operator>=(const hx_tree_node<T, Comp>& lhs, const hx_tree_node<T, Comp>& rhs) {
  return !(lhs < rhs);
}

template <typename T, typename Comp = Less<T> , typename Alloc = std::allocator<T> >
class hx_tree {
 public:
  typedef T value_type;
  typedef Comp value_compare;
  typedef typename ft::hx_tree_node<T, Comp>::node_type node_type;
  typedef node_type* node_type*;
  typedef typename Alloc::template rebind<node_type>::other allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_t;

  explicit hx_tree(const value_compare& comp = value_compare(),
                   const allocator_type& alloc = allocator_type())
    : alloc_(alloc),
      comp_(comp),
      end_node_(0),
      begin_node_ptr_(&end_node_),
      root_(0),
      size_(0) {}

  // hx_tree(const hx_tree& other)
  //   : alloc_(other.alloc_),
  //     comp_(other.comp_),
  //     end_node_(other.end_node_),
  //     begin_node_(other.begin_node_),
  //     size_(other.size()) {}

  ~hx_tree() {
    clear();
  }

  void insert(const value_type& value) {
    if (!root_) {
      root_ = alloc_.allocate(1);
      alloc_.construct(root_, value);
      root_->parent_ = &end_node_;
      end_node_.left_ = root_;
      begin_node_ptr_ = root_;
      size_++;
      return;
    }

    node_type* current = root_;
    while (current) {
      if (current->value_ == value) {
        return;
      }

      if (current->value_ < value) {
        if (current->right_ == NULL) {
          current->right_ = alloc_.allocate(1);  // To Fix
          alloc_.construct(current->right_, value);
          current->right_->parent_ = current;
          return;
        }
        current = current->right_;
      } else {
        if (current->left_ == NULL) {
          current->left_ = alloc_.allocate(1);  // TO Fix
          alloc_.construct(current->left_, value);
          current->left_->parent_ = current;
          return;
        }
        current = current->left_;
      }
    }
  }

  bool isLeftChild(node_type* node) {
    return *node == *(node->parent_->left_);
  }

  bool isRightChild(node_type* node) {
    return *node == *(node->parent_->right_);
  }

  void erase(node_type* subroot) {
    if (!subroot) {
      return;
    }
    node_type* next_subroot;
    if (subroot->left_ && subroot->right_ ) {
      next_subroot = subroot->right_;
      while (next_subroot->left_) {
        next_subroot->subroot->left_;
      }
      if (isLeftChild(next_subroot) == true) {
        next_subroot->parent_->left_ = NULL;
      } else {
        next_subroot->parent_->right_ = NULL;
      }
      subroot->left_->parent_ = next_subroot;
      next_subroot = 
    } else if (subroot->left_) {
      next_subroot = subroot->left_;
    } else if (subroot->right_) {
      next_subroot = subroot->right_;
    } else {
      next_subroot = NULL;
    }

    alloc_.destroy(subroot);
    alloc_.deallocate(subroot, 1);
  }

  void clear_recursive(node_type* node) {
    if (!node)
      return;
    clear_recursive(node->left_);
    clear_recursive(node->right_);
    alloc_.destroy(node);
    alloc_.deallocate(node, 1);
  }

  void clear() {
    clear_recursive(root_);
  }

  void printPreOrder(node_type* node) {
    if (!node) {
      return;
    }
    std::cout << (*node).value() << " ";
    printPreOrder(node->left_);
    printPreOrder(node->right_);
  }

  void printInOrder(node_type* node) {
    if (!node) {
      return;
    }
    printInOrder(node->left_);
    std::cout << (*node).value() << " ";
    printInOrder(node->right_);
  }

  void printPostOrder(node_type* node) {
    if (!node) {
      return;
    }
    printPostOrder(node->left_);
    printPostOrder(node->right_);
    std::cout << (*node).value()  << " ";
  }


  node_type* tree_min(node_type* np) {
    while (np->right_ != NULL)
      np = np->right_;
    return np;
  }
  
  node_type* tree_max(node_type* np) {
    while (np->left_ != NULL)
      np = np->left_;
    return np;
  }

  node_type* tree_next(node_type* np) {
    if (np->right_ != 0) {
      return tree_min(np->right_);
    }
    while (tree_is_left_child(np) == false) {
      np = np->parent_;
    }
    return (np->parent_);
  }

  node_type* tree_prev(node_type* np) {
    if (np->left_ != NULL)
      return tree_max(np->left_);
    while (tree_is_left_child(np)) {
      np = np->parent_;
    }
    return (np);
  }

  node_type* tree_leaf(node_type* np) {
    while (1) {
      if (np->left_) {
        np = np->left_;
        continue;
      }
      if (np->right_) {
        np = np->right_;
        continue;
      }
      break;
    }
    return np;
  }

  const node_type* root() const { return root_; }

 private:
  allocator_type alloc_;
  node_type end_node_;
  node_type* begin_node_ptr_;
  node_type* root_;
  value_compare comp_;
  size_type size_;
};


}

