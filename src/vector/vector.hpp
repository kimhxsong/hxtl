#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>

class vector {
 public:
    typedef int value_type;
    typedef std::allocator<value_type> allocator_type;
    typedef allocator_type::reference reference;
    typedef allocator_type::const_reference const_reference;
    typedef allocator_type::pointer pointer;
    typedef allocator_type::const_pointer const_pointer;
    // iterator...
    typedef unsigned int size_type;
    typedef unsigned int difference_type;
    explicit vector (const allocator_type& alloc = allocator_type());
    explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
    // template <class InputIterator>
        //  vector (InputIterator first, InputIterator last,
                //  const allocator_type& alloc = allocator_type());
    vector (const vector& x);
    ~vector();

    vector& operator=(const vector& rhs);

    size_type size() const;
    size_type max_size() const;
    bool empty() const;
    void resize(size_type n, value_type val = value_type());
    void reserve(size_type n);
    size_type capacity() const;

// iterator
    // begin();
    // end();
    // rbegin();
    // rend();

    reference operator[](size_type n);
    const_reference operator[](size_type n) const;

    reference at(size_type n);
    const_reference at(size_type n) const;

    reference front(size_type n);
    const_reference front(size_type n) const;

    reference back(size_type n);
    const_reference back(size_type n) const;

    // template <class InputIterator>
    // void assign (InputIterator first, InputIterator last);
    void assign(size_type n, const value_type& val);

    reference front();
    const_reference front() const;

    void push_back(const value_type& val);
    void pop_back();

    // single element (1)	
    // iterator insert (iterator position, const value_type& val);
    // fill (2)	
    // void insert (iterator position, size_type n, const value_type& val);
    // range (3)	
    // template <class InputIterator>
    // void insert (iterator position, InputIterator first, InputIterator last);

    // swap();
    void clear();

    allocator_type get_allocator() const;

 private:
    allocator_type alloc_;
    pointer elem_;
    unsigned int space_;
    unsigned int size_;
};

#endif  // VECTOR_HPP_
