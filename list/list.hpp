/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:54:31 by mondrew           #+#    #+#             */
/*   Updated: 2021/02/11 08:12:36 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

//	LOGIC OF DOUBLE-LINKED LIST
//	[null_node]<---node1<->node2<->node3<->[null_node]--->node1

# include <memory>
# include <cmath>
# include <iostream>

namespace ft
{
	template < typename T, typename A = std::allocator<T> >
	class list {

		private:

			struct		t_list
			{
				T		val;
				t_list	*prev;
				t_list	*next;

			};

			t_list				*_head;
			t_list				*_tail; // null-tail
			std::size_t			_size;

		public:

			class iterator;

			// CONSTRUCTORS
			// #1 Default constructor
			explicit list<T, A>(void) {

				this->_head = new t_list;

				this->_head->val = T();
				this->_head->prev = this->_head;
				this->_head->next = this->_head;

				this->_tail = this->_head;

				this->_size = 0;
			}

			// #2 Fill constructor
			//explicit list<T, A>(std::size_t n, T const &val) {
			explicit list<T, A>(int n, T const &val) {

				int		i = 0;
				t_list	*tmp;

				if (n < 0)
					throw (std::bad_alloc());

				// Create null-element
				this->_head = new t_list;
				this->_head->val = T();
				this->_head->prev = this->_head;
				this->_head->next = this->_head;
				this->_tail = this->_head;
				this->_size = 0;

				if (n == 0)
					return ;

				// Create other elements if any
				while (i < n)
				{
					tmp = new t_list;
					tmp->val = val;
					tmp->prev = this->_tail;
					tmp->next = this->_head;
					this->_head->prev = tmp;
					this->_tail->next = tmp;
					this->_head = tmp;
					this->_size++;
					i++;
				}
			}

			// #3 Range constructor
			template <typename InputIterator>
			list<T, A>(InputIterator first, InputIterator last) {

				// Create null-element
				this->_head = new t_list;
				this->_head->val = T();
				this->_head->prev = this->_head;
				this->_head->next = this->_head;
				this->_tail = this->_head;
				this->_size = 0;

				if (first == last)
					return ;

				// Create other elements if any
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
				return ;
			}

			/*
			// #3.1 Range constructor (type pointers)
			list<T, A>(T *first, T *last) {

				t_list	*tmp;

				// Create null-element
				this->_head = new t_list;
				this->_head->val = T();
				this->_head->prev = this->_head;
				this->_head->next = this->_head;
				this->_tail = this->_head;
				this->_size = 0;

				if (first == last)
					return ;

				// Create other elements if any
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
				return ;
			}
			*/

			// #4 Copy constructor
			list<T, A>(list<T, A> const &src) {

				*this = src;
				return ;
			}

			// DESTRUCTOR
			~list<T, A>(void) {

				t_list	*tmp;

				while (this->_head != this->_tail)
				{
					tmp = this->_head->next;
					this->_head->val.~T();
					delete this->_head;
					this->_head = 0;
					this->_head = tmp;
				}
				this->_tail->val.~T();
				delete this->_tail;
				this->_tail = 0;
				this->_size = 0;
				return ;
			}

			// Assignment operation overload
			list<T, A>		&operator=(list<T, A> const &rhs) {

				t_list			*tmp;
				t_list			*from = rhs._head;

				// Create null-element
				this->_head = new t_list;
				this->_head->val = T();
				this->_head->prev = this->_head;
				this->_head->next = this->_head;
				this->_tail = this->_head;
				this->_size = 0;

				if (rhs.size() == 0)
					return (*this);

				// Create other elements if any
				while (from != rhs._tail)
				{
					tmp = new t_list;
					tmp->val = from->val;
					tmp->prev = this->_tail->prev;
					tmp->next = this->_tail;

					this->_tail->prev->next = tmp;
					this->_tail->prev = tmp;

					if (this->_size == 0)
						this->_head = tmp;

					this->_size++;
					from = from->next;
				}
				return (*this);
			}

			// ITERATORS
			// Simple iterator
			class iterator {

				private:

					t_list		*_node;
					t_list		*_head;

				public:

					// CONSTRUCTORS
					// #1 default constructor
					iterator(void) : _node(0), _head(0) { return ; }

					// #2 param constructor (for iterator init: begin, end, etc)
					iterator(t_list *node, t_list *head) :
										_node(node), _head(head) { return ; }

					// #3 Parameterized constructor
					iterator(list<T, A> const &src) {

						this->_node = src._head;
						this->_head = src._head;

						return ;
					}

					// #4 Copy constructor
					iterator(iterator const &src) {

						*this = src;
					}

					// DESTRUCTOR
					~iterator(void) { return ; }

					// Assignment operation
					iterator	&operator=(iterator const &rhs) {

						this->_node = rhs._node;
						this->_head = rhs._head;

						return (*this);
					}

					// Increment prefix
					iterator	&operator++(void) {

						this->_node = this->_node->next;

						return (*this);
					}

					// Increment postfix
					iterator	operator++(int) {

						iterator	tmp(*this);

						this->_node = this->_node->next;

						return (tmp);
					}

					// Decrement prefix
					iterator	&operator--(void) {

						this->_node = this->_node->prev;

						return (*this);
					}

					// Decrement postfix
					iterator	operator--(int) {

						iterator	tmp(*this);

						this->_node = this->_node->prev;
						return (tmp);
					}

					// Comparison operators
					bool		operator==(iterator const &rhs) {

						return (this->_node == rhs._node);
					}

					bool		operator!=(iterator const &rhs) {

						return (this->_node != rhs._node);
					}

					// Dereference operator
					T			&operator*(void) {

						return (this->_node->val);
					}

					T			*operator->(void) {

						return (this->_node);
					}

					// Getters
					t_list		*getNode(void) { return (this->_node); }
					t_list		*getHead(void) { return (this->_node); }
			};

			// Const iterator
			class const_iterator {

				private:

					t_list		*_node;
					t_list		*_head;

				public:

					// CONSTRUCTORS
					// #1 default constructor
					const_iterator(void) : _node(0), _head(0) { return ; }

					// #2 param constructor (for iterator init: begin, end, etc)
					const_iterator(t_list *node, t_list *head) :
										_node(node), _head(head) { return ; }

					// #3 Parameterized constructor
					const_iterator(list<T, A> const &src) {

						this->_node = src._head;
						this->_head = src._head;

						return ;
					}

					// #4 Copy constructor
					const_iterator(iterator const &src) {

						*this = src;

						return ;
					}

					// DESTRUCTOR
					~const_iterator(void) { return ; }

					const_iterator const	&operator=(const_iterator const &rhs) {

						this->_node = rhs._node;
						this->_head = rhs._head;

						return (*this);
					}

					// Increment prefix
					const_iterator const	&operator++(void) {

						this->_node = this->_node->next;

						return (*this);
					}

					// Increment postfix
					const_iterator		operator++(int) {

						const_iterator	tmp(*this);

						this->_node = this->_node->next;

						return (tmp);
					}

					// Decrement prefix
					const_iterator const	&operator--(void) {

						this->_node = this->_node->prev;

						return (*this);
					}

					// Decrement postfix
					const_iterator		operator--(int) {

						const_iterator	tmp(*this);

						this->_node = this->_node->prev;
						return (tmp);
					}

					// Comparison operators
					bool			operator==(const_iterator const &rhs) {

						return (this->_node == rhs._node);
					}

					bool			operator!=(const_iterator const &rhs) {

						return (this->_node != rhs._node);
					}

					// Dereference operator
					T 				&operator*(void) {

						return (this->_node->val);
					}

					T			*operator->(void) {

						return (this->_node);
					}
			};

			// Reverse iterator
			class reverse_iterator {

				private:

					t_list		*_node;
					t_list		*_head;

				public:

					// CONSTRUCTORS
					// #1 default constructor
					reverse_iterator(void) : _node(0), _head(0) { return ; }

					// #2 param constructor (for iterator init: begin, end, etc)
					reverse_iterator(t_list *node, t_list *head) :
										_node(node), _head(head) { return ; }

					// #3 Parameterized constructor
					reverse_iterator(list<T, A> const &src) {

						this->_node = src._tail()->prev;
						this->_head = src._tail()->prev;

						return ;
					}

					// #4 Copy constructor
					reverse_iterator(reverse_iterator const &src) {

						*this = src;
					}

					// DESTRUCTOR
					~reverse_iterator(void) { return ; }

					reverse_iterator	&operator=(reverse_iterator const &rhs) {

						this->_node = rhs._node;
						this->_head = rhs._head;

						return (*this);
					}

					// Increment prefix
					reverse_iterator	&operator++(void) {

						this->_node = this->_node->prev;

						return (*this);
					}

					// Increment postfix
					reverse_iterator	operator++(int) {

						reverse_iterator	tmp(*this);

						this->_node = this->_node->prev;

						return (tmp);
					}

					// Decrement prefix
					reverse_iterator	&operator--(void) {

						this->_node = this->_node->next;

						return (*this);
					}

					// Decrement postfix
					reverse_iterator	operator--(int) {

						reverse_iterator	tmp(*this);

						this->_node = this->_node->next;
						return (tmp);
					}

					// Comparison operators
					bool		operator==(reverse_iterator const &rhs) {

						return (this->_node == rhs._node);
					}

					bool		operator!=(reverse_iterator const &rhs) {

						return (this->_node != rhs._node);
					}

					// Dereference operator
					T			&operator*(void) {

						return (this->_node->val);
					}

					T			*operator->(void) {

						return (this->_node);
					}
			};

			// Const reverse iterator
			class const_reverse_iterator {

				private:

					t_list		*_node;
					t_list		*_head;

				public:

					// CONSTRUCTORS
					// #1 default constructor
					const_reverse_iterator(void) : _node(0), _head(0) { return ; }

					// #2 param constructor (for iterator init: begin, end, etc)
					const_reverse_iterator(t_list *node, t_list *head) :
										_node(node), _head(head) { return ; }

					// #3 Parameterized constructor
					const_reverse_iterator(list<T, A> const &src) {

						this->_node = src._tail()->prev;
						this->_head = src._tail()->prev;

						return ;
					}

					// #4 Copy constructor
					const_reverse_iterator(const_reverse_iterator const &src) {

						*this = src;
					}

					// DESTRUCTOR
					~const_reverse_iterator(void) { return ; }

					const_reverse_iterator	&operator=(reverse_iterator \
																const &rhs) {

						this->_node = rhs._node;
						this->_head = rhs._head;

						return (*this);
					}

					// Increment prefix
					const_reverse_iterator	&operator++(void) {

						this->_node = this->_node->prev;

						return (*this);
					}

					// Increment postfix
					const_reverse_iterator	operator++(int) {

						const_reverse_iterator	tmp(*this);

						this->_node = this->_node->prev;

						return (tmp);
					}

					// Decrement prefix
					const_reverse_iterator	&operator--(void) {

						this->_node = this->_node->next;

						return (*this);
					}

					// Decrement postfix
					const_reverse_iterator	operator--(int) {

						const_reverse_iterator	tmp(*this);

						this->_node = this->_node->next;
						return (tmp);
					}

					// Comparison operators
					bool		operator==(const_reverse_iterator const &rhs) {

						return (this->_node == rhs._node);
					}

					bool		operator!=(const_reverse_iterator const &rhs) {

						return (this->_node != rhs._node);
					}

					// Dereference operator
					T			&operator*(void) {

						return (this->_node->val);
					}

					T			*operator->(void) {

						return (this->_node);
					}
			};

			// ITERATORS
			iterator			begin(void) {

				return (iterator(this->_head, this->_head));
			}

			iterator			end(void) {

				return (iterator(this->_tail, this->_head));
			}

			const_iterator 		begin(void) const {

				return (const_iterator(this->_head, this->_head));
			}

			const_iterator		end(void) const {

				return (const_iterator(this->_tail, this->_head));
			}

			reverse_iterator	rbegin(void) {

				return (reverse_iterator(this->_tail->prev, this->_head));
			}

			reverse_iterator	rend(void) {

				return (reverse_iterator(this->_head->prev, this->_head));
			}

			const_reverse_iterator	rbegin(void) const {

				return (const_reverse_iterator(this->_tail->prev, this->_head));
			}

			const_reverse_iterator	rend(void) const {

				return (const_reverse_iterator(this->_head->prev, this->_head));
			}

			// CAPACITY
			bool				empty(void) const {

				return (this->_size == 0);
			}

			std::size_t				size(void) const {

				return (this->_size);
			}

			std::size_t				max_size(void) const {

				int		arch;

				if (sizeof(void *) == 8)
					arch = 64;
				else if (sizeof(void *) == 4)
					arch = 32;
				else
					arch = 16;

				return (static_cast<std::size_t>(pow(2, arch) / sizeof(t_list)) - 1);
			}

			// ELEMENT ACCESS
			T					&front(void) {

				return (this->_head->val);
			}

			T const				&front(void) const {

				return (this->_head->val);
			}

			T 					&back(void) {

				return (this->_tail->prev->val);
			}

			T const				&back(void) const {

				return (this->_tail->prev->val);
			}

			// MODIFIERS
			// Assign #1 range
			template <typename InputIterator>
			void			assign(InputIterator first, InputIterator last) {

				// Delete all nodes except tail-null-node
				this->clear();

				if (first == last)
					return ;

				// Create nodes
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
				return ;
			}

			// Assign #2 fill
			// void				assign(std::size_t n, T const &val) {
			void				assign(int n, T const &val) {

				if (n < 0)
					throw (std::bad_alloc());

				// Delete all nodes except tail-null-node
				this->clear();

				if (n == 0)
					return ;

				while (n > 0)
				{
					this->push_back(val);
					n--;
				}
				return ;
			}

			// Push front
			void				push_front(T const &val) {

				t_list	*tmp = new t_list;

				tmp->val = val;
				tmp->prev = this->_tail;
				tmp->next = this->_head;
				this->_head->prev = tmp;
				this->_tail->next = tmp;

				this->_head = tmp;
				this->_size++;
				return ;
			}

			// Pop front
			void				pop_front(void) {

				t_list		*tmp = this->_head->next;

				if (this->_size == 0)
					return ;

				this->_head->val.~T();
				delete this->_head;
				this->_head = tmp;
				this->_size--;

				this->_head->prev = this->_tail;
				this->_tail->next = this->_head;
				return ;
			}

			// Push back
			void				push_back(T const &val) {

				t_list		*tmp = new t_list;

				tmp->val = val;
				tmp->prev = this->_tail->prev;
				tmp->next = this->_tail;
				this->_tail->prev->next = tmp;
				this->_tail->prev = tmp;

				if (this->_size == 0)
					this->_head = tmp;
				this->_size++;
				return ;
			}

			// Pop back
			void				pop_back(void) {

				t_list		*tmp = this->_tail->prev->prev;

				if (this->_size == 0)
					return ;

				this->_tail->prev->val.~T();
				delete this->_tail->prev;
				this->_size--;

				tmp->next = this->_tail;
				this->_tail->prev = tmp;

				this->_head = this->_tail->next;
				return ;
			}

			// Insert #1 (single element)
			iterator			insert(iterator position, T const &val) {

				t_list		*tmp = new t_list;

				tmp->val = val;
				tmp->prev = position.getNode()->prev;
				tmp->next = position.getNode();
				position.getNode()->prev->next = tmp;
				position.getNode()->prev = tmp;
				this->_head = this->_tail->next;
				this->_size++;

				position--;

				return (position);
			}

			// Insert #2 (fill)
			// void		insert(iterator position, std::size_t n, \
			//													T const &val) {
			void		insert(iterator position, int n, T const &val) {

				int			i = n;
				t_list		*tmp;

				if (n < 0)
					throw (std::bad_alloc());

				while (n > 0)
				{
					tmp = new t_list;

					tmp->val = val;
					tmp->prev = position.getNode()->prev;
					tmp->next = position.getNode();
					position.getNode()->prev->next = tmp;
					position.getNode()->prev = tmp;
					this->_size++;

					n--;
				}
				this->_head = this->_tail->next;

				while (i > 0)
				{
					position--;
					i--;
				}
			}

			// Insert #3 (range)
			template <typename InputIterator>
			void				insert(iterator position, \
										InputIterator first, InputIterator last) {

				int			n = 0;
				t_list		*tmp;

				while (first != last)
				{
					tmp = new t_list;
					tmp->val = *first;
					tmp->prev = position.getNode()->prev;
					tmp->next = position.getNode();
					position.getNode()->prev->next = tmp;
					position.getNode()->prev = tmp;
					this->_size++;
					first++;
					n++;
				}
				this->_head = this->_tail->next;

				while (n > 0)
				{
					position--;
					n--;
				}
			}

			// Erase #1 (single)
			iterator			erase(iterator position) {

				t_list					*pre = position.getNode()->prev;
				t_list					*post = position.getNode()->next;
				list<T, A>::iterator	ite = this->end();

				if (position == ite)
					throw (std::out_of_range("Out of range error"));

				if (this->_size == 0)
					return (position);

				pre->next = post;
				post->prev = pre;

				position.getNode()->val.~T();
				delete position.getNode();

				this->_size--;
				this->_head = this->_tail->next;

				return (position);
			}

			// Erase #2 (range)
			iterator			erase(iterator first, iterator last) {

				list<T, A>::iterator	it = first;
				list<T, A>::iterator	ite = this->end();

				if (first == last)
					return (last);

				while (first != last)
				{
					if (first == ite)
						throw (std::out_of_range("Out of range error"));
					erase(it);
					it++;
					first++;
				}
				this->_head = this->_tail->next;
				return (last);
			}

			// Swap
			void				swap(list &x) {

				t_list			*tmp_head = x._head;
				t_list			*tmp_tail = x._tail;
				std::size_t		tmp_size = x._size;

				x._head = this->_head;
				x._tail = this->_tail;
				x._size = this->_size;

				this->_head = tmp_head;
				this->_tail = tmp_tail;
				this->_size = tmp_size;

				return ;
			}

			// Resize
			void				resize( std::size_t n, T val = T() ) {

				if (n < this->_size)
				{
					while (n < this->_size)
						this->pop_back();
				}
				else if (n > this->_size)
				{
					while (this->_size < n)
						this->push_back(val);
				}
				return ;
			}

			// Clear
			void				clear(void) {

				while (this->_size)
					this->pop_back();
			}

			// OPERATIONS
			// Splice #1 (entire list)
			void				splice(iterator position, list &x) {

				t_list		*before = position.getNode()->prev;
				t_list		*after = position.getNode();
				t_list		*tmp;

				while (x._size)
				{
					tmp = x._head;
					x._tail->next = x._head->next;
					x._head->next->prev = x._tail;
					x._head = x._tail->next;
					x._size--;

					before->next = tmp;
					tmp->prev = before;
					after->prev = tmp;
					tmp->next = after;
					this->_size++;

					this->_head = this->_tail->next;
					before = before->next;
				}
			}

			// Splice #2 (single element)
			void				splice(iterator position, list &x, iterator i) {

				t_list		*before = position.getNode()->prev;
				t_list		*after = position.getNode();
				t_list		*tmp;

				tmp = i.getNode();

				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				x._head = x._tail->next;
				x._size--;

				before->next = tmp;
				tmp->prev = before;

				after->prev = tmp;
				tmp->next = after;

				this->_head = this->_tail->next;
				this->_size++;
			}

			// Splice #3 (element range)
			void				splice(list<T, A>::iterator position, list &x, \
						list<T, A>::iterator first, list<T, A>::iterator last) {

				t_list					*before = position.getNode()->prev;
				t_list					*after = position.getNode();
				t_list					*tmp;

				while (first != last)
				{
					tmp = first.getNode();
					first++;
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					x._head = x._tail->next;
					x._size--;

					before->next = tmp;
					tmp->prev = before;
					after->prev = tmp;
					tmp->next = after;

					this->_head = this->_tail->next;

					this->_size++;
					before = before->next;
				}
			}

			// Remove
			void				remove(T const &val) {

				t_list		*tmp = this->_head;
				t_list		*tmp2;

				while (tmp != this->_tail)
				{
					tmp2 = tmp->next;
					if (tmp->val == val)
					{
						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
						tmp->val.~T();
						delete tmp;

						this->_head = this->_tail->next;

						this->_size--;
					}
					tmp = tmp2;
				}
			}

			// Remove if
			template <class Predicate>
			void				remove_if(Predicate pred) {

				iterator	it = this->begin();
				iterator	ite = this->end();
				t_list		*tmp;

				while (it != ite)
				{
					if (pred(*it))
					{
						tmp = it.getNode();
						it++;
						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
						tmp->val.~T();
						delete tmp;

						this->_head = this->_tail->next;

						this->_size--;
					}
					else
						it++;
				}
			}

			// Unique #1
			void				unique(void) {

				t_list		*fst = this->_head;
				t_list		*snd = this->_head->next;

				while (snd != this->_tail)
				{
					if (fst->val == snd->val)
					{
						fst->next = snd->next;
						snd->next->prev = fst;
						snd->val.~T();
						delete snd;

						this->_head = this->_tail->next;

						this->_size--;
					}
					else
						fst = fst->next;
					snd = fst->next;
				}
			}

			// Unique #2
			template <class BinaryPredicate>
			void				unique(BinaryPredicate binary_pred) {

				iterator	it = this->begin();
				iterator	ite = this->end();
				iterator	tmp;

				it++;
				while (it != ite)
				{
					tmp = ++it;
					it--;
					if (binary_pred(*it, it.getNode()->prev->val))
						erase(it);
					it = tmp;
				}
			}

			// Merge #1
			void				merge(list &x) {

				t_list		*src = x._head;
				t_list		*dest = this->_head;
				t_list		*tmp;

				if (x._size == 0)
					return ;
				while (src != x._tail)
				{
					tmp = src->next;
					while (dest != this->_tail && dest->val <= src->val)
						dest = dest->next;
					src->prev->next = src->next;
					src->next->prev = src->prev;
					x._head = x._tail->next;
					x._size--;

					src->prev = dest->prev;
					src->next = dest;

					dest->prev->next = src;
					dest->prev = src;

					this->_head = this->_tail->next;

					this->_size++;

					src = tmp;
				}
			}

			// Merge #2
			template <class Compare>
			void				merge(list &x, Compare comp) {

				if (&x == this || x._size == 0)
					return ;
				t_list		*src = x._head;
				t_list		*dest = this->_head;
				t_list		*tmp;

				while (src != x._tail)
				{
					tmp = src->next;
					while (dest != this->_tail && !comp(src->val, dest->val))
						dest = dest->next;
					src->prev->next = src->next;
					src->next->prev = src->prev;
					x._head = x._tail->next;
					x._size--;

					src->prev = dest->prev;
					src->next = dest;

					dest->prev->next = src;
					dest->prev = src;

					this->_head = this->_tail->next;

					this->_size++;

					src = tmp;
				}
			}

			// Sort #1
			void				sort(void) {

				t_list		*fst = this->_head;
				t_list		*snd = this->_head->next;
				bool		swapped = false;

				while (snd != this->_tail)
				{
					if (snd->val < fst->val)
					{
						swapped = true;
						// link 1 & 3
						fst->next = snd->next;
						snd->next->prev = fst;

						// link 2 & pre-1
						snd->prev = fst->prev;
						snd->next = fst;

						// link 1 & 2 (rev order)
						fst->prev->next = snd;
						fst->prev = snd;

						this->_head = this->_tail->next;

						// swap ptrs
						fst = snd;
						snd = fst->next;
					}
					fst = fst->next;
					snd = snd->next;

					// Here we go again
					if (snd == this->_tail && swapped)
					{
						fst = this->_head;
						snd = this->_head->next;
						swapped = false;
					}
				}
			}

			// Sort #2
			template <class Compare>
			void				sort(Compare comp) {

				t_list		*fst = this->_head;
				t_list		*snd = this->_head->next;
				bool		swapped = false;

				while (snd != this->_tail)
				{
					if (!comp(fst->val, snd->val))
					{
						swapped = true;
						// link 1 & 3
						fst->next = snd->next;
						snd->next->prev = fst;

						// link 2 & pre-1
						snd->prev = fst->prev;
						snd->next = fst;

						// link 1 & 2 (rev order)
						fst->prev->next = snd;
						fst->prev = snd;

						this->_head = this->_tail->next;

						// swap ptrs
						fst = snd;
						snd = fst->next;
					}
					fst = fst->next;
					snd = snd->next;

					// Here we go again
					if (snd == this->_tail && swapped)
					{
						fst = this->_head;
						snd = this->_head->next;
						swapped = false;
					}
				}
			}

			// Reverse new
			void				reverse(void) {

				t_list		*fst = this->_head;
				t_list		*snd = this->_tail->prev;
				t_list		*tmp;
				size_t		i = 0;

				while (i < this->_size / 2)
				{
					// Neightbours relink
					fst->prev->next = snd;
					fst->next->prev = snd;
					snd->prev->next = fst;
					snd->next->prev = fst;

					tmp = fst->next;
					fst->next = snd->next;
					snd->next = tmp;

					tmp = fst->prev;
					fst->prev = snd->prev;
					snd->prev = tmp;

					this->_head = this->_tail->next;

					// Swap ptrs
					tmp = fst;
					fst = snd;
					snd = tmp;

					// Get closer
					fst = fst->next;
					snd = snd->prev;

					i++;
				}
			}

			// NON-MEMBER FUNCTION OVERLOADS
			// Relational operators
			friend bool	operator==(ft::list<T, A> const &lhs, ft::list<T, A> const &rhs) {

				ft::list<T, A>::const_iterator	it1 = lhs.begin();
				ft::list<T, A>::const_iterator	ite1 = lhs.end();
				ft::list<T, A>::const_iterator	it2 = rhs.begin();

				if (lhs._size != rhs._size)
					return (false);
				while (it1 != ite1)
				{
					if (*it1 != *it2)
						return (false);
					it1++;
					it2++;
				}
				return (true);
			}

			friend bool	operator!=(ft::list<T, A> const &lhs, ft::list<T, A> const &rhs) {

				ft::list<T, A>::const_iterator	it1 = lhs.begin();
				ft::list<T, A>::const_iterator	ite1 = lhs.end();
				ft::list<T, A>::const_iterator	it2 = rhs.begin();

				if (lhs._size != rhs._size)
					return (true);
				while (it1 != ite1)
				{
					if (*it1 != *it2)
						return (true);
					it1++;
					it2++;
				}
				return (false);
			}
	
			friend bool	operator<(ft::list<T, A> const &lhs, ft::list<T, A> const &rhs) {

				ft::list<T, A>::const_iterator	it1 = lhs.begin();
				ft::list<T, A>::const_iterator	ite1 = lhs.end();
				ft::list<T, A>::const_iterator	it2 = rhs.begin();
				ft::list<T, A>::const_iterator	ite2 = rhs.end();

				while (it1 != ite1 && it2 != ite2)
				{
					if (*it1 >= *it2)
						return (false);
					it1++;
					it2++;
				}
				if (it2 != ite2)
					return (true);
				return (false);
			}

			friend bool	operator<=(ft::list<T, A> const &lhs, ft::list<T, A> const &rhs) {

				ft::list<T, A>::const_iterator	it1 = lhs.begin();
				ft::list<T, A>::const_iterator	ite1 = lhs.end();
				ft::list<T, A>::const_iterator	it2 = rhs.begin();
				ft::list<T, A>::const_iterator	ite2 = rhs.end();

				while (it1 != ite1 && it2 != ite2)
				{
					if (*it1 > *it2)
						return (false);
					it1++;
					it2++;
				}
				if (it1 != ite1)
					return (false);
				return (true);
			}

			friend bool	operator>(ft::list<T, A> const &lhs, ft::list<T, A> const &rhs) {

				ft::list<T, A>::const_iterator	it1 = lhs.begin();
				ft::list<T, A>::const_iterator	ite1 = lhs.end();
				ft::list<T, A>::const_iterator	it2 = rhs.begin();
				ft::list<T, A>::const_iterator	ite2 = rhs.end();

				while (it1 != ite1 && it2 != ite2)
				{
					if (*it1 <= *it2)
						return (false);
					it1++;
					it2++;
				}
				if (it1 != ite1)
					return (true);
				return (false);
			}

			friend bool	operator>=(ft::list<T, A> const &lhs, ft::list<T, A> const &rhs) {

				ft::list<T, A>::const_iterator	it1 = lhs.begin();
				ft::list<T, A>::const_iterator	ite1 = lhs.end();
				ft::list<T, A>::const_iterator	it2 = rhs.begin();
				ft::list<T, A>::const_iterator	ite2 = rhs.end();

				while (it1 != ite1 && it2 != ite2)
				{
					if (*it1 < *it2)
						return (false);
					it1++;
					it2++;
				}
				if (it2 != ite2)
					return (false);
				return (true);
			}

			friend void	swap(ft::list<T, A> &x, list<T, A> &y) {

				t_list		*tmp_head = y._head;
				t_list		*tmp_tail = y._tail;
				std::size_t		tmp_size = y._size;

				y._head = x._head;
				y._tail = x._tail;
				y._size = x._size;

				x._head = tmp_head;
				x._tail = tmp_tail;
				x._size = tmp_size;

				return ;
			}
	};
}

#endif
