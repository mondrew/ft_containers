/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:04:03 by mondrew           #+#    #+#             */
/*   Updated: 2021/02/06 00:33:36 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <utility>
# include <memory>
# include <functional>
# include <cmath>
# include <iostream>

namespace ft
{
	template < typename Key, \
			 	typename T, \
				typename Compare = std::less<Key>, \
				typename Alloc = std::allocator<std::pair<const Key, T> > >
	class map {

		typedef std::pair<const Key, T> value_type;

		private:

			struct		BSTNode {

				value_type	val;
				//Key		first; // key
				//T			second; // val
				BSTNode		*left;
				BSTNode		*right;

				BSTNode(void) {}
				BSTNode(value_type const &a_val) : val(a_val) {}
			};

			BSTNode			*_root;
			Compare			_comp;
			Alloc			_alloc;

			// Private functions
			std::size_t		countNodes(BSTNode *root) {

				if (root == 0)
					return (0);
				return (1 + countNodes(root->left) + \
										countNodes(root->right));
			}

			BSTNode			*findNode(BSTNode *root, Key key) {

				while (root && root->val.first != key)
				{
					if (key < root->val.first)
						root = root->left;
					else
						root = root->right;
				}
				return (root);
			}

			BSTNode			*findMin(BSTNode *node) {

				if (!node)
					return (0);
				while (node->left)
					node = node->left;
				return (node);
			}

			BSTNode			*findMax(BSTNode *node) {

				if (!node)
					return (0);
				while (node->right)
					node = node->right;
				return (node);
			}

			BSTNode			*getSuccessor(BSTNode *root, Key key) {

				BSTNode		*current = findNode(root, key);
				BSTNode		*ancestor = root;
				BSTNode		*successor = 0;

				if (!current)
					return (0);
				// Case 1: there is right subtree
				if (current->right)
					return (findMin(current->right));
				else // Case 2: there are no right subtree - O(h)
				{
					while (ancestor != current)
					{
						if (current->val.first < ancestor->val.first)
						{
							successor = ancestor; // the deepest node for which curr is in left
							ancestor = ancestor->left;
						}
						else
							ancestor = ancestor->right;
					}
				}
				return (successor);
			}

			BSTNode			*getAncestor(BSTNode *root, Key key) { // CHANGE EVERYWHERE

				BSTNode		*current = findNode(root, key);
				BSTNode		*ancestor = 0;

				if (!root || !current)
					return (0);
				// Case 1: left child exists
				if (current->left)
					return (findMax(current->left));
				// Case 2: no left child
				else
				{
					while (root != current)
					{
						if (current->val.first > root->val.first)
						{
							ancestor = root;
							root = ancestor->right;
						}
						else
							root = root->left;
					}
					return (ancestor);
				}
			}

			void	deleteBST(BSTNode *root) {

				if (!root)
					return ;
				deleteBST(root->left);
				deleteBST(root->right);
				delete (root);

				return ;
			}

			BSTNode		*deleteNode(BSTNode **root, Key key) {

				// For erase(2) -> call this function until find in erase return NULL. Return?
				if (!(*root))
					return (0);
				if (key < (*root)->val.first)
					deleteNode(&((*root)->left), key);
				else if (key > (*root)->val.first)
					deleteNode(&((*root)->right), key);
				else
				{
					// Element if found!
					// Case 1: no children
					if (!(*root)->left && !(*root)->right)
					{
						delete (*root);
						*root = 0;
						return (0);
					}
					// Case 2: one child
					else if (!(*root)->left)
					{
						BSTNode		*tmp = *root;
						*root = (*root)->right;
						delete tmp;
					}
					else if (!(*root)->right)
					{
						BSTNode		*tmp = *root;
						*root = (*root)->left;
						delete tmp;
					}
					// Case 3: two children
					else
					{
						BSTNode		*replace = new BSTNode((*root)->val);
						BSTNode		*parent = getAncestor(this->_root, (*root)->val.first);
						int			dir = 0; // left
						if (parent->right == (*root))
							dir = 1; // right

						//(*root)->val.first = tmp->val.first;
						//(*root)->val.second = tmp->val.second;
						replace->left = (*root)->left;
						replace->right = (*root)->right;

						// Delete tmp
						deleteNode(&((*root)->right), (*root)->val.first);

						// Replace *root parent link
						if (dir == 0)
							parent->left = replace;
						else
							parent->right = replace;

						delete (*root);
					}
				}
				return (*root);
			}

			BSTNode		*insertNode(BSTNode **root, Key const &key, T const &val) {

				if (*root == 0)
				{
					value_type	n_val(key, val);
					*root = new BSTNode(n_val);

					//(*root)->val.first = key;
					//(*root)->val.second = val;
					(*root)->left = 0;
					(*root)->right = 0;

					return (*root);
				}
				if (key < (*root)->val.first)
				{
					(*root)->left = insertNode(&((*root)->left), key, val);

					return (*root);
				}
				else if (key > (*root)->val.first)
				{
					(*root)->right = insertNode(&((*root)->right), key, val);

					return (*root);
				}
				else
					return (*root); // Check the original
			}

			BSTNode		*copyBST(BSTNode *root) {

				if (!root)
					return (0);

				BSTNode		*node = new BSTNode(root->val);
				//node->val.first = root->val.first;
				//node->val.second = root->val.second;
				node->left = copyBST(root->left);
				node->right = copyBST(root->right);
				return (node);
			}

		public:

			class iterator;

			// Constructor #1 (empty)
			explicit map(Compare const &comp = Compare(), \
						Alloc const &alloc = std::allocator<value_type>()) :
										_root(0), _comp(comp), _alloc(alloc) {
				return ;
			}

			// Constructor #2 (range)
			map(iterator first, iterator last, \
						Compare const &comp = Compare(), \
						Alloc const &alloc = std::allocator<value_type>()) :
										_root(0), _comp(comp), _alloc(alloc) {

				while (first != last)
				{
					if (!first.getRoot())
						return ;
					if (!this->findNode(this->_root, first.getNode()->val.first))
						this->insertNode(&this->_root, \
							first.getNode()->val.first, first.getNode()->val.second);
					first++;
				}

				return ;
			}

			// Constructor #3 (copy)
			map(map const &src) : _root(0) {

				*this = src;

				return ;
			}

			~map(void) {

				this->deleteBST(this->_root);

				return ;
			}

			map<Key, T, Compare, Alloc>		&operator=(map<Key, T, Compare, Alloc> const &rhs) {

				this->_comp = rhs._comp;
				this->_alloc = rhs._alloc;

				if (this->_root)
					deleteBST(this->_root);
				this->_root = this->copyBST(rhs._root);

				return (*this);
			}

			class iterator {

				protected:

					BSTNode		*_node;
					BSTNode		*_root;
					BSTNode		*_last;

					BSTNode			*findNode(BSTNode *root, Key key) {

						while (root && root->val.first != key)
						{
							if (key < root->val.first)
								root = root->left;
							else
								root = root->right;
						}
						return (root);
					}

					BSTNode			*findMin(BSTNode *node) {

						if (!node)
							return (0);
						while (node->left)
							node = node->left;
						return (node);
					}

					BSTNode			*findMax(BSTNode *node) {

						if (!node)
							return (0);
						while (node->right)
							node = node->right;
						return (node);
					}

					BSTNode			*getSuccessor(BSTNode *root, Key key) {

						BSTNode		*current = findNode(root, key);
						BSTNode		*ancestor = root;
						BSTNode		*successor = 0;

						if (!current)
							return (0);
						// Case 1: there is right subtree
						if (current->right)
							return (findMin(current->right));
						else // Case 2: there are no right subtree - O(h)
						{
							while (ancestor != current)
							{
								if (current->val.first < ancestor->val.first)
								{
									successor = ancestor; // the deepest node for which curr is in left
									ancestor = ancestor->left;
								}
								else
									ancestor = ancestor->right;
							}
						}
						return (successor);
					}

					BSTNode			*getAncestor(BSTNode *root, Key key) { // CHANGE EVERYWHERE

						BSTNode		*current = findNode(root, key);
						BSTNode		*ancestor = 0;

						if (!root || !current)
							return (0);
						// Case 1: left child exists
						if (current->left)
							return (findMax(current->left));
						// Case 2: no left child
						else
						{
							while (root != current)
							{
								if (current->val.first > root->val.first)
								{
									ancestor = root;
									root = ancestor->right;
								}
								else
									root = root->left;
							}
							return (ancestor);
						}
					}

				public:

					// Constructor #1 (empty)
					iterator(void) : _node(0), _root(0) {

						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						return ;
					}

					// Constructor #2 (init)
					iterator(map<Key, T, Compare, Alloc> const &rhs) {

						BSTNode		*tmp;
						this->_node = rhs.begin();
						this->_root = this->_node;

						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						tmp = getAncestor(this->_node);
						while (tmp)
						{
							this->_root = tmp;
							tmp = getAncestor(tmp);
						}

						return ;
					}

					// Constructor #3 (for begin & end)
					iterator(BSTNode *node, BSTNode *root) : _node(node), _root(root) {

						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						return ;
					}

					// Copy constructor
					iterator(iterator const &src) { *this = src; return ; }

					// Destructor
					~iterator(void) {
						
						delete this->_last;
						return ;
					}

					// Assignment operation
					iterator	&operator=(iterator const &rhs) {

						this->_node = rhs._node;
						this->_root = rhs._root;

						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						return (*this);
					}

					// Comparison operator
					bool		operator==(iterator const &rhs) {

						if (this->_node != rhs._node)
							return (false);
						if (!this->_node && !rhs._node)
							return (true);
						if (!this->_node || !rhs._node)
							return (false);
						return (this->_node->val.first == rhs._node->val.first);
					}

					bool		operator!=(iterator const &rhs) {

						if (this->_node == rhs._node)
							return (false);
						if (!this->_node && !rhs._node)
							return (false);
						if (!this->_node || !rhs._node)
							return (true);
						return (this->_node->val.first != rhs._node->val.first);
					}

					// Dereferencing operator
					value_type	&operator*(void) {

						if (this->_node == 0)
							return (this->_last->val);
						return (this->_node->val);
					}

					// Field access operator (arrow operator)
					value_type	*operator->(void) {

						// Возвращать нулевой value_type, чтобы его можно было разыменовать
						if (this->_node == 0)
							return (&(this->_last->val));
						return (&(this->_node->val));
					}

					// Increment prefix
					iterator	&operator++(void) {

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						// Change everywhere
						this->_node = this->getSuccessor(this->_root, \
															this->_node->val.first);

						return (*this);
					}

					// Increment postfix
					iterator	operator++(int) {

						iterator	tmp(*this);

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						if (this->_node != 0)
							this->_node = this->getSuccessor(this->_root, \
															this->_node->val.first);

						return (tmp);
					}

					// Decrement prefix
					iterator	&operator--(void) {

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						if (this->_node == 0)
						{
							this->_node = this->_root;
							while (this->_node->right)
								this->_node = this->_node->right;
						}
						else
							this->_node = this->getAncestor(this->_root, \
															this->_node->val.first);

						return (*this);
					}

					iterator	operator--(int) {

						iterator	tmp(*this);

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						if (this->_node == 0)
						{
							this->_node = this->_root;
							while (this->_node->right)
								this->_node = this->_node->right;
						}
						else
							this->_node = this->getAncestor(this->_root, \
															this->_node->val.first);

						return (tmp);
					}

					BSTNode		*getNode(void) {

						return (this->_node);
					}

					BSTNode		*getRoot(void) {

						return (this->_root);
					}
			};

			class const_iterator {

				protected:

					BSTNode		*_node;
					BSTNode		*_root;
					BSTNode		*_last;

					BSTNode			*findNode(BSTNode *root, Key key) {

						while (root && root->val.first != key)
						{
							if (key < root->val.first)
								root = root->left;
							else
								root = root->right;
						}
						return (root);
					}

					BSTNode			*findMin(BSTNode *node) {

						if (!node)
							return (0);
						while (node->left)
							node = node->left;
						return (node);
					}

					BSTNode			*findMax(BSTNode *node) {

						if (!node)
							return (0);
						while (node->right)
							node = node->right;
						return (node);
					}

					BSTNode			*getSuccessor(BSTNode *root, Key key) {

						BSTNode		*current = findNode(root, key);
						BSTNode		*ancestor = root;
						BSTNode		*successor = 0;

						if (!current)
							return (0);
						// Case 1: there is right subtree
						if (current->right)
							return (findMin(current->right));
						else // Case 2: there are no right subtree - O(h)
						{
							while (ancestor != current)
							{
								if (current->val.first < ancestor->val.first)
								{
									successor = ancestor; // the deepest node for which curr is in left
									ancestor = ancestor->left;
								}
								else
									ancestor = ancestor->right;
							}
						}
						return (successor);
					}

					BSTNode			*getAncestor(BSTNode *root, Key key) { // CHANGE EVERYWHERE

						BSTNode		*current = findNode(root, key);
						BSTNode		*ancestor = 0;

						if (!root || !current)
							return (0);
						// Case 1: left child exists
						if (current->left)
							return (findMax(current->left));
						// Case 2: no left child
						else
						{
							while (root != current)
							{
								if (current->val.first > root->val.first)
								{
									ancestor = root;
									root = ancestor->right;
								}
								else
									root = root->left;
							}
							return (ancestor);
						}
					}

				public:

					// Constructor #1 (empty)
					const_iterator(void) : _node(0), _root(0) {
						
						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						return ;
					}

					// Constructor #2 (init)
					const_iterator(map<Key, T, Compare, Alloc> const &rhs) {

						BSTNode		*tmp;
						this->_node = rhs.begin();
						this->_root = this->_node;

						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						tmp = getAncestor(this->_node);
						while (tmp)
						{
							this->_root = tmp;
							tmp = getAncestor(tmp);
						}

						return ;
					}

					// Constructor #3 (for begin & end)
					const_iterator(BSTNode *node, BSTNode *root) :
													_node(node), _root(root) {

						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						return ;
					}

					// Copy constructor
					const_iterator(const_iterator const &src) { *this = src; return ; }

					// Destructor
					~const_iterator(void) {

						delete this->_last;
						return ;
					}

					// Assignment operation
					const_iterator const	&operator=(const_iterator const &rhs) {

						this->_node = rhs._node;
						this->_root = rhs._root;

						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						return (*this);
					}

					// Comparison operator
					bool		operator==(const_iterator const &rhs) {

						if (this->_node != rhs._node)
							return (false);
						if (!this->_node && !rhs._node)
							return (true);
						if (!this->_node || !rhs._node)
							return (false);
						return (this->_node->val.first == rhs._node->val.first);
					}

					bool		operator!=(const_iterator const &rhs) {

						if (this->_node == rhs._node)
							return (false);
						if (!this->_node && !rhs._node)
							return (false);
						if (!this->_node || !rhs._node)
							return (true);
						return (this->_node->val.first != rhs._node->val.first);
					}

					// Dereferencing operator
					value_type const	&operator*(void) {

						if (this->_node == 0)
							return (this->_last->val);
						return (this->_node->val);
					}

					// Field access operator (arrow operator)
					value_type	*operator->(void) {

						if (this->_node == 0)
							return (&(this->_last->val));
						return (&(this->_node->val));
					}

					// Increment prefix
					const_iterator const	&operator++(void) {

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						// Change everywhere
						this->_node = this->getSuccessor(this->_root, \
															this->_node->val.first);

						return (*this);
					}

					// Increment postfix
					const_iterator	operator++(int) {

						const_iterator	tmp(*this);

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						if (this->_node != 0)
							this->_node = this->getSuccessor(this->_root, \
															this->_node->val.first);

						return (tmp);
					}

					// Decrement prefix
					const_iterator const	&operator--(void) {

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						if (this->_node == 0)
						{
							this->_node = this->_root;
							while (this->_node->right)
								this->_node = this->_node->right;
						}
						else
							this->_node = this->getAncestor(this->_root, \
															this->_node->val.first);

						return (*this);
					}

					const_iterator	operator--(int) {

						const_iterator	tmp(*this);

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						if (this->_node == 0)
						{
							this->_node = this->_root;
							while (this->_node->right)
								this->_node = this->_node->right;
						}
						else
							this->_node = this->getAncestor(this->_root, \
															this->_node->val.first);

						return (tmp);
					}

					BSTNode		*getNode(void) {

						return (this->_node);
					}

					BSTNode		*getRoot(void) {

						return (this->_root);
					}
			};

			class reverse_iterator {

				protected:

					BSTNode		*_node;
					BSTNode		*_root;
					BSTNode		*_last;

					BSTNode			*findNode(BSTNode *root, Key key) {

						while (root && root->val.first != key)
						{
							if (key < root->val.first)
								root = root->left;
							else
								root = root->right;
						}
						return (root);
					}

					BSTNode			*findMin(BSTNode *node) {

						if (!node)
							return (0);
						while (node->left)
							node = node->left;
						return (node);
					}

					BSTNode			*findMax(BSTNode *node) {

						if (!node)
							return (0);
						while (node->right)
							node = node->right;
						return (node);
					}

					BSTNode			*getSuccessor(BSTNode *root, Key key) {

						BSTNode		*current = findNode(root, key);
						BSTNode		*ancestor = root;
						BSTNode		*successor = 0;

						if (!current)
							return (0);
						// Case 1: there is right subtree
						if (current->right)
							return (findMin(current->right));
						else // Case 2: there are no right subtree - O(h)
						{
							while (ancestor != current)
							{
								if (current->val.first < ancestor->val.first)
								{
									successor = ancestor; // the deepest node for which curr is in left
									ancestor = ancestor->left;
								}
								else
									ancestor = ancestor->right;
							}
						}
						return (successor);
					}

					BSTNode			*getAncestor(BSTNode *root, Key key) { // CHANGE EVERYWHERE

						BSTNode		*current = findNode(root, key);
						BSTNode		*ancestor = 0;

						if (!root || !current)
							return (0);
						// Case 1: left child exists
						if (current->left)
							return (findMax(current->left));
						// Case 2: no left child
						else
						{
							while (root != current)
							{
								if (current->val.first > root->val.first)
								{
									ancestor = root;
									root = ancestor->right;
								}
								else
									root = root->left;
							}
							return (ancestor);
						}
					}

					BSTNode			*getNode(void) {

						return (this->_node);
					}

					BSTNode			*getRoot(void) {

						return (this->_root);
					}

				public:

					// Constructor #1 (empty)
					reverse_iterator(void) : _node(0), _root(0) {
						
						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						return ;
					}

					// Constructor #2 (init)
					reverse_iterator(map<Key, T, Compare, Alloc> const &rhs) {

						BSTNode		*tmp;

						this->_node = rhs.rbegin();
						this->_root = this->_node;

						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						tmp = getAncestor(this->_node);
						while (tmp)
						{
							this->_root = tmp;
							tmp = getAncestor(tmp);
						}

						return ;
					}

					// Constructor #3 (for begin & end)
					reverse_iterator(BSTNode *node, BSTNode *root) : 
													_node(node), _root(root) {

						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						return ;
					}

					// Copy constructor
					reverse_iterator(reverse_iterator const &src) {
						
						*this = src;
						return ;
					}

					// Destructor
					~reverse_iterator(void) {
						
						delete this->_last;
						return ;
					}

					// Assignment operation
					reverse_iterator	&operator=(reverse_iterator const &rhs){

						this->_node = rhs._node;
						this->_root = rhs._root;

						// Last element
						value_type	n_val(0, 0);
						this->_last = new BSTNode(n_val);

						return (*this);
					}

					// Comparison operator
					bool		operator==(reverse_iterator const &rhs) {

						if (this->_node != rhs._node)
							return (false);
						if (!this->_node && !rhs._node)
							return (true);
						if (!this->_node || !rhs._node)
							return (false);
						return (this->_node->val.first == rhs._node->val.first);
					}

					bool		operator!=(reverse_iterator const &rhs) {

						if (this->_node == rhs._node)
							return (false);
						if (!this->_node && !rhs._node)
							return (false);
						if (!this->_node || !rhs._node)
							return (true);
						return (this->_node->val.first != rhs._node->val.first);
					}

					// Dereferencing operator for pair
					value_type	&operator*(void) {

						if (this->_node == 0)
							return (this->_last->val);
						return (this->_node->val);
					}

					// Field access operator (arrow operator)
					value_type	*operator->(void) {

						if (this->_node == 0)
							return (&(this->_last->val));
						return (&(this->_node->val));
					}

					// Increment prefix
					reverse_iterator	&operator++(void) {

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						// Change everywhere
						this->_node = this->getAncestor(this->_root, \
															this->_node->val.first);

						return (*this);
					}

					// Increment postfix
					reverse_iterator	operator++(int) {

						reverse_iterator	tmp(*this);

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						if (this->_node != 0)
							this->_node = this->getAncestor(this->_root, \
															this->_node->val.first);

						return (tmp);
					}

					// Decrement prefix
					reverse_iterator	&operator--(void) {

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						if (this->_node == 0)
						{
							this->_node = this->_root;
							while (this->_node->right)
								this->_node = this->_node->right;
						}
						else
							this->_node = this->getSuccessor(this->_root, \
															this->_node->val.first);

						return (*this);
					}

					reverse_iterator	operator--(int) {

						iterator	tmp(*this);

						if (this->_root == 0)
							throw (std::out_of_range("error: out of range"));
						if (this->_node == 0)
						{
							this->_node = this->_root;
							while (this->_node->right)
								this->_node = this->_node->right;
						}
						else
							this->_node = this->getSuccessor(this->_root, \
															this->_node->val.first);

						return (tmp);
					}
			};

			// Iterators
			ft::map<Key, T, Compare, Alloc>::iterator	begin(void) {

				BSTNode		*first = this->_root;

				if (!first)
					return (iterator());
				while (first->left)
					first = first->left;

				return (ft::map<Key, T, Compare, Alloc>::iterator(first, this->_root));
			}

			iterator	end(void) {

				return (iterator(0, this->_root));
			}

			ft::map<Key, T, Compare, Alloc>::const_iterator		cbegin(void) const {

				BSTNode		*first = this->_root;

				if (!first)
					return (const_iterator());
				while (first->left)
					first = first->left;

				return (ft::map<Key, T, Compare, Alloc>::const_iterator(first, this->_root));
			}

			ft::map<Key, T, Compare, Alloc>::const_iterator		cend(void) const {

				return (const_iterator(0, this->_root));
			}

			reverse_iterator	rbegin(void) {

				BSTNode		*last = this->_root;

				if (!last)
					return (reverse_iterator());
				while (last->right)
					last = last->right;
				return (reverse_iterator(last, this->_root));
			}

			reverse_iterator	rend(void) {

				return (reverse_iterator(0, this->_root));
			}

			// Capacity
			bool		empty(void) {

				return (this->_root == 0);
			}

			std::size_t		size(void) {

				return (countNodes(this->_root));
			}

			std::size_t		max_size(void) {

				std::size_t	arch;

				if (sizeof(void *) == 8)
					arch = 64;
				else if (sizeof(void *) == 4)
					arch = 32;
				else if (sizeof(void *) == 2)
					arch = 16;

				return (static_cast<std::size_t>(pow(2, arch) / \
														sizeof(BSTNode)) - 1);
			}

			// Element access
			T		&operator[](Key const &k) {

				BSTNode		*tmp = this->findNode(this->_root, k);

				if (!tmp)
				{
					this->insertNode(&this->_root, k, 0);
					tmp = this->findNode(this->_root, k);
				}
				return (tmp->val.second);
			}

			// Modifiers
			// Insert #1 (single element)
			std::pair<iterator, bool>	insert(value_type const &val) {

				BSTNode		*tmp = this->findNode(this->_root, val.first);
				ft::map<Key, T, Compare, Alloc>::iterator	it;
				bool		res = false;

				if (!tmp)
				{
					this->insertNode(&this->_root, val.first, val.second);
					tmp = findNode(this->_root, val.first);
					res = true;
				}
				it = iterator(tmp, this->_root);

				return (std::pair<iterator, bool>(it, res));
			}

			// Insert #2 (with hint)
			iterator	insert(iterator position, value_type const &val) {

				BSTNode		*node = position.getNode();
				BSTNode		*tmp = this->findNode(node, val.first);
				ft::map<Key, T, Compare, Alloc>::iterator	it;

				if (!node)
					return (iterator());
				if (!tmp)
				{
					this->insertNode(&node, val.first, val.second);
					tmp = findNode(this->_root, val.first);
				}
				it = iterator(tmp, this->_root);

				return (it);
			}

			// Insert #3 (range)
			void		insert(iterator first, iterator last) {

				while (first != last)
				{
					if (!first.getRoot())
						return ;
					if (!this->findNode(this->_root, first.getNode()->val.first))
						this->insertNode(&this->_root, \
							first.getNode()->val.first, first.getNode()->val.second);
					first++;
				}
			}

			// Erase #1 (single)
			void		erase(iterator position) {

				if (!position.getNode())
					return ;
				this->deleteNode(&this->_root, position.getNode()->val.first);

				return ;
			}

			// Erase #2 (key)
			std::size_t		erase(Key const &k) {

				BSTNode		*tmp = deleteNode(&this->_root, k);

				if (!tmp)
					return (0);
				return (1);
			}

			// Erase #3 (range)
			void		erase(iterator first, iterator last) {

				iterator	tmp;

				while (first != last)
				{
					tmp = ++first;
					first--;
					if (!first.getNode())
						return ;
					this->deleteNode(&this->_root, first.getNode()->val.first);
					first = tmp;
				}
			}

			// Swap
			void		swap(map<Key, T, Compare, Alloc> &x) {

				BSTNode		*tmp = this->_root;

				this->_root = x._root;
				x._root = tmp;
			}

			// Clear
			void		clear(void) {

				this->deleteBST(this->_root);
				this->_root = 0;
			}

			// Functor key_compare
			//template <typename Key, typename T, typename Compare, typename Alloc>
			class key_compare
			{
				private:

					friend class map;

				protected:

					Compare		comp;

				public:

					key_compare(Compare c) : comp(c) { return ; }

					bool	operator()(Key const &x, \
													Key const &y) const {
						return comp(x, y);
					}

			};

			// Functor value_compare
			//template <typename Key, typename T, typename Compare, typename Alloc>
			class value_compare
			{
				private:

					friend class map;

				protected:

					Compare		comp;
					value_compare(Compare c) : comp(c) { return ; }

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool	operator()(value_type const &x, \
													value_type const &y) const
					{
						return comp(x.first, y.first);
					}
			};

			// Observers
			// Key_comp
			Compare			key_comp(void) const {

				return (this->_comp);
			}

			// Value_comp
			value_compare	value_comp(void) const {

				map<Key, T, Compare, Alloc>::value_compare	value_comp(this->_comp);

				return (value_comp);
			}

			// Operations
			// Find
			iterator		find(Key const &k) {

				map<Key, T, Compare, Alloc>::iterator	it = this->begin();
				map<Key, T, Compare, Alloc>::iterator	ite = this->end();

				while (it != ite)
				{
					if (this->_comp(it.getNode()->val.first, k) == false && \
							this->_comp(k, it.getNode()->val.first) == false)
						return (it);
					it++;
				}
				return (this->end());
			}

			const_iterator	find(Key const &k) const {

				map<Key, T, Compare, Alloc>::const_iterator		it = this->cbegin();
				map<Key, T, Compare, Alloc>::const_iterator		ite = this->cend();
				while (it != ite)
				{
					if (this->_comp(it.getNode()->val.first, k) == false && \
							this->_comp(k, it.getNode()->val.first) == false)
						return (it);
					it++;
				}
				return (this->end());
			}

			// Count
			std::size_t		count(Key const &k) const {

				map<Key, T, Compare, Alloc>::const_iterator	it = this->cbegin();
				map<Key, T, Compare, Alloc>::const_iterator	ite = this->cend();

				while (it != ite)
				{
					if (this->_comp(it.getNode()->val.first, k) == false && \
							this->_comp(k, it.getNode()->val.first) == false)
						return (1);
					it++;
				}
				return (0);
			}

			// Lower_bound
			iterator		lower_bound(Key const &k) {

				map<Key, T, Compare, Alloc>::iterator	it = this->begin();
				map<Key, T, Compare, Alloc>::iterator	ite = this->end();

				while (it != ite)
				{
					if (this->_comp(it.getNode()->val.first, k) == false)
						return (it);
					it++;
				}
				return (this->end());
			}

			// Lower_bound
			const_iterator		lower_bound(Key const &k) const{

				map<Key, T, Compare, Alloc>::const_iterator	it = this->begin();
				map<Key, T, Compare, Alloc>::const_iterator	ite = this->end();

				while (it != ite)
				{
					if (this->_comp(it._node->val.first, k) == false)
						return (it);
					it++;
				}
				return (this->end());
			}

			// Upper_bound
			iterator		upper_bound(Key const &k) {

				map<Key, T, Compare, Alloc>::iterator	it = this->begin();
				map<Key, T, Compare, Alloc>::iterator	ite = this->end();

				while (it != ite)
				{
					if (this->_comp(it.getNode()->val.first, k) == false)
						return (++it);
					it++;
				}
				return (this->end());
			}

			// Upper_bound
			const_iterator		upper_bound(Key const &k) const {

				map<Key, T, Compare, Alloc>::const_iterator	it = this->begin();
				map<Key, T, Compare, Alloc>::const_iterator	ite = this->end();

				while (it != ite)
				{
					if (this->_comp(it._node->val.first, k) == false)
						return (++it);
					it++;
				}
				return (this->end());
			}

			// Equal range
			std::pair<iterator, iterator>	equal_range(Key const &k) {

				map<Key, T, Compare, Alloc>::iterator	it = lower_bound(k);
				map<Key, T, Compare, Alloc>::iterator	ite = upper_bound(k);

				return (std::pair<iterator, iterator>(it, ite));
			}

			std::pair<const_iterator, const_iterator>	equal_range(Key const &k) const {

				map<Key, T, Compare, Alloc>::const_iterator	it = lower_bound(k);
				map<Key, T, Compare, Alloc>::const_iterator	ite = upper_bound(k);

				return (std::pair<iterator, iterator>(it, ite));
			}
	};
}

#endif
