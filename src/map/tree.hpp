#include <cstddef>

#include <memory>

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
  typedef node_type* node_type_pointer;

  explicit hx_tree_node(const value_type& value = value_type())
    : value_(value),
      parent_(0),
      left_(0),
      right_(0) {}

  const value_type& value() const { return value_; }
  node_type_pointer left() const { return left_; }
  node_type_pointer right() const { return right_; }
  node_type_pointer parent() const { return parent_; }

//  private:  // TO RETURN
  value_type value_;
  node_type_pointer parent_;
  node_type_pointer left_;
  node_type_pointer right_;
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

template <typename T, typename Comp = Less<T> , typename _Alloc = std::allocator<T> >
class hx_tree {
 public:
  typedef T value_type;
  typedef Comp value_compare;
  typedef typename ft::hx_tree_node<T, Comp>::node_type node_type;
  typedef node_type* node_type_pointer;
  typedef typename _Alloc::template rebind<node_type>::other allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef std::size_t size_type;

  explicit hx_tree(const value_compare& comp = value_compare(),
                   const allocator_type& alloc = allocator_type())
    : alloc_(alloc),
      comp_(comp),
      end_node_(0),
      begin_node_(&end_node_),
      root_(0),
      size_(0) {}

  // hx_tree(const hx_tree& other)
  //   : alloc_(other.alloc_),
  //     comp_(other.comp_),
  //     end_node_(other.end_node_),
  //     begin_node_(other.begin_node_),
  //     size_(other.size()) {}

  ~hx_tree() {
    if (root_) {
      alloc_.destroy(root_);
      alloc_.deallocate(root_, 1);
    }
  }

  void insert(const value_type& value) {
    if (!root_) {
      root_ = alloc_.allocate(1);
      alloc_.construct(root_, value);
      end_node_.left_ = root_;
      begin_node_ = root_;
      size_++;
      return;
    }

    node_type_pointer current = root_;
    while (current) {
      if (current->value_ == value) {
        return;
      }

      if (current->value_ < value) {
        if (current->right_ == NULL) {
          current->right_ = alloc_.allocate(1);  // To Fix
          alloc_.construct(current->right_, value);
          return;
        }
        current = current->right_;
      } else {
        if (current->left_ == NULL) {
          current->left_ = alloc_.allocate(1);  // TO Fix
          alloc_.construct(current->left_, value);
          return;
        }
        current = current->left_;
      }
    }
  }

  // void erase(const node_type* node) {
  //   if (node == )
  // }

  // void clear() {

  // }

void printPreOrder(node_type_pointer node) {
  if (!node) {
    return;
  }
  std::cout << (*node).value() << " ";
  printPreOrder(node->left_);
  printPreOrder(node->right_);
}

void printInOrder(node_type_pointer node) {
  if (!node) {
    return;
  }
  printInOrder(node->left_);
  std::cout << (*node).value() << " ";
  printInOrder(node->right_);
}

void printPostOrder(node_type_pointer node) {
  if (!node) {
    return;
  }
  printPostOrder(node->left_);
  printPostOrder(node->right_);
  std::cout << (*node).value()  << " ";
}

const node_type_pointer root() const { return root_; }

 private:
  allocator_type alloc_;
  node_type end_node_;
  node_type_pointer begin_node_;
  node_type_pointer root_;
  value_compare comp_;
  size_type size_;
};


}

