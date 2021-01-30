/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:04:03 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/31 02:41:12 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <utility>
# include <memory>

typedef std::pair<const Key, T> value_type;

namespace ft
{
	template < typename Key, 
			 	typename T,
				typename Compare = less<Key>,
				typename Alloc = std::allocator<std::pair<const Key, T> >
	class map {

		class iterator;

		private:

			struct		BSTNode {

				Key			first; // key
				T			second; // val
				BSTNode		*left;
				BSTNode		*right;
			};

			BSTNode			*_root;

			// Private functions
			std::size_t		countNodes(BSTNode *root) {

				if (this->empty())
					return (0);
				return (1 + countNodes(this->_root->left) + \
												countNodes(this->_root->right));
			}

			BSTNode			*findNode(BSTNode *root, Key key) {

				BSTNode		*current = root;

				while (current && current->first != first)
				{
					if (current->first < key)
						current = current->left;
					else
						current = current->right;
				}
				return (current);
			}

			BSTNode			*findMin(BSTNode *node) {

				if (!node)
					return (0);
				while (node->left)
					node = node->left;
				return (node);
			}

			BSTNode			*getSuccessor(BSTNode *root, Key key) {

				BSTNode		*current = findNode(root, key);
				BSTNode		*ancestor;
				BSTNode		*successor;

				if (!current)
					return (0);
				// Case 1: there is right subtree
				if (current->right)
					return (findMin(current->right));
				else // Case 2: there are no right subtree - O(h)
				{
					successor = NULL;
					ancestor = root;
					while (ancestor != current)
					{
						if (current->first < ancestor->first)
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

			BSTNode			*getAncestor(BSTNode *root, Key key) {

				BSTNode		*current = getNode(root, key);
				BSTNode		*ancestor = 0;
				BSTNode		*tmp = root;

				if (!root || !current)
					return (0);
				// Case 1: left child exists
				if (current->left)
					return (current->left);
				// Case 2: no left child
				else
				{
					while (tmp->left != current && tmp->right != current)
					{
						if (current->first > ancestor->first)
						{
							ancestor = tmp;
							tmp = ancestor->right;
						}
						else
							tmp = tmp->left;
					}
					return (ancestor);
				}
			}

			void	deleteBST(BSTNode *root) {

				if (!root)
					return ;
				deleteBST(this->_root->left);
				deleteBST(this->_root->right);
				delete (this->_root);
				this->_root = 0;

				return ;
			}

			BSTNode		*deleteNode(BSTNode *root, Key key) {

				// For erase(2) -> call this function until find in erase return NULL. Return?
				if (!root)
					return (0);
				if (key < root->first)
					deleteNode(root->left, key);
				else if (key > root->first)
					deleteNode(root->right, key);
				else
				{
					// Element if found!
					// Case 1: no children
					if (!root->left && !root->right)
					{
						delete (root);
						root = 0;
						return (0);
					}
					// Case 2: one child
					else if (!root->left)
					{
						BSTNode		*tmp = root;
						root = root->right;
						delete tmp;
					}
					else if (!root->right)
					{
						BSTNode		*tmp = root;
						root = root->left;
						delete tmp;
					}
					// Case 3: two children
					else
					{
						BSTNode		*tmp = findMin(root->right); // or max in left :-)
						root->first = tmp->first;
						root->second = tmp->second;
						deleteNode(root->right, root->first);
					}
				}
				return (root);
			}

			BSTNode		*insertNode(BSTNode *root, Key key, T val) {

				if (!root)
					return (0);
				if (key < root->first)
				{
					insertNode(root->left, key, val);

					BSTNode		*node = new BSTNode();

					node->first = key;
					node->second = val;
					node->left = 0;
					node->right = 0;
					root->left = node;

					return (node);
				}
				else if (key > root->first)
				{
					insertNode(root->right, key, val);

					BSTNode		*node = new BSTNode();

					node->first = key;
					node->second = val;
					node->left = 0;
					node->right = 0;

					root->right = node;

					return (node);
				}
				else
					return (root); // Check the original
			}

			BSTNode		*copyBST(BSTNode *root) {

				BSTNode		*node = new BSTNode();

				if (!root)
					return (0);
				node->first = root->first;
				node->second = root->second;
				node->left = copyBST(root->left);
				node->right = copyBST(root->right);
				return (node);
			}

		public:

			// Constructor #1 (empty)
			explicit map(Compare const &comp = Compare(), \
						Alloc const &alloc = std::allocator<value_type>()) {

				return ;
			}

			// Constructor #2 (range)
			map(iterator first, iterator last, \
						Compare const &comp = Compare(), \
						Alloc const &alloc = std::allocator<value_type>()) {
			}

			// Constructor #3 (copy)
			map(map const &src) {

				*this = src;

				return ;
			}

			~map(void) {

				this->deleteBST(this->_root);

				return ;
			}

			map<Key, T, Compare, Alloc>		&operator=(map<Key, T, Compare, Alloc> const &rhs) {

				if (this->_root)
					deleteBST(this->_root);
				this->_root = this->copyBST(rhs->_root);

				return (*this);
			}

			class iterator {

				private:

					BSTNode		*_node;
					BSTNode		*_root;

					BSTNode			*findNode(BSTNode *root, Key key) {

						BSTNode		*current = root;

						while (current && current->first != first)
						{
							if (current->first < key)
								current = current->left;
							else
								current = current->right;
						}
						return (current);
					}

					BSTNode			*findMin(BSTNode *node) {

						if (!node)
							return (0);
						while (node->left)
							node = node->left;
						return (node);
					}

					BSTNode			*getSuccessor(BSTNode *root, Key key) {

						BSTNode		*current = findNode(root, key);
						BSTNode		*ancestor;
						BSTNode		*successor;

						if (!current)
							return (0);
						// Case 1: there is right subtree
						if (current->right)
							return (findMin(current->right));
						else // Case 2: there are no right subtree - O(h)
						{
							successor = NULL;
							ancestor = root;
							while (ancestor != current)
							{
								if (current->first < ancestor->first)
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

					BSTNode			*getAncestor(BSTNode *root, Key key) {

						BSTNode		*current = getNode(root, key);
						BSTNode		*ancestor = 0;
						BSTNode		*tmp = root;

						if (!root || !current)
							return (0);
						// Case 1: left child exists
						if (current->left)
							return (current->left);
						// Case 2: no left child
						else
						{
							while (tmp->left != current && tmp->right != current)
							{
								if (current->first > ancestor->first)
								{
									ancestor = tmp;
									tmp = ancestor->right;
								}
								else
									tmp = tmp->left;
							}
							return (ancestor);
						}
					}

				public:

					// Constructor #1 (empty)
					iterator(void) : _node(0), _root(0) { return ; }

					// Constructor #2 (init)
					iterator(map<Key, T, Compare, Alloc> const &rhs) {

						BSTNode		*tmp;
						this->_node = rhs.begin();
						this->_root = this->_node;

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

						return ;
					}

					// Copy constructor
					iterator(iterator const &src) { *this = src; return ; }

					// Destructor
					~iterator(void) { return ; }

					// Assignment operation
					iterator	&operator=(iterator const &rhs) {

						this->_node = rhs._node;
						this->_root = rhs._root;

						return ;
					}

					// Comparison operator
					bool		operator==(iterator const &rhs) {

						return (this->_node->first == rhs._node->first);
					}

					bool		operator!=(iterator const &rhs) {

						return (this->_node->first != rhs._node->first);
					}

					// Dereferencing operator
					T			&operator*(void) {

						return (this->_node->second);
					}

					// Field access operator (arrow operator)
					BSTNode			*operator->(void) {

						return (this->_node);
					}

					// Increment prefix
					iterator	&operator++(void) {

						// Change everywhere
						this->_node = map::getSuccessor(this->_root, this->_node->first);
						//this->_node = this->getSuccessor(this->_root, this->_node->first);

						return (this->_node);
					}

					// Increment postfix
					iterator	operator++(int) {

						iterator	tmp(*this);

						this->_node = this->_getSuccessor(this->_root, this->_node->first);

						return (tmp);
					}

					// Decrement prefix
					iterator	&operator--(void) {

						if (this->_node == 0 && this->_root)
						{
							this->_node = this->_root;
							while (this->_node->right)
								this->_node = this->_node->right;
						}
						else
							this->_node = this->getAncestor(this->_root, this->_node->first);

						return (this->_node);
					}

					iterator	operator--(int) {

						iterator	tmp(*this);

						if (this->_node == 0 && this->_root)
						{
							this->_node = this->_root;
							while (this->_node->right)
								this->_node = this->_node->right;
						}
						else
							this->_node = this->getAncestor(this->_root, this->_node->first);

						return (tmp);
					}

					BSTNode		*getNode(void) {

						return (this->_node);
					}

					// *a++ overloading - check
					T		*operator++(int) {

						BSTNode		*tmp = this->_node;

						if (this->_node == 0 && this->_root) // end()
							return (0); // check original. May be throw sm exception

						this->_node = this->getSuccessor(this->_root, this->_node->first);
						if (!this->_node)
							return (0);
						return (&(this->_node->second));
					}

					// *a-- overloading - check
					T		*operator--(int) {

						BSTNode		*tmp = this->_node;

						if (this->_node == 0 && this->_root) // end()
							return (0); // check original. May be throw sm exception

						this->_node = this->getAncestor(this->_root, this->_node->first);
						if (!this->_node)
							return (0);
						return (&(this->_node->second));
					}
			};

			class reverse_iterator {

				private:

					BSTNode		*_node;
					BSTNode		*_root;

					BSTNode			*findNode(BSTNode *root, Key key) {

						BSTNode		*current = root;

						while (current && current->first != first)
						{
							if (current->first < key)
								current = current->left;
							else
								current = current->right;
						}
						return (current);
					}

					BSTNode			*findMin(BSTNode *node) {

						if (!node)
							return (0);
						while (node->left)
							node = node->left;
						return (node);
					}

					BSTNode			*getSuccessor(BSTNode *root, Key key) {

						BSTNode		*current = findNode(root, key);
						BSTNode		*ancestor;
						BSTNode		*successor;

						if (!current)
							return (0);
						// Case 1: there is right subtree
						if (current->right)
							return (findMin(current->right));
						else // Case 2: there are no right subtree - O(h)
						{
							successor = NULL;
							ancestor = root;
							while (ancestor != current)
							{
								if (current->first < ancestor->first)
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

					BSTNode			*getAncestor(BSTNode *root, Key key) {

						BSTNode		*current = getNode(root, key);
						BSTNode		*ancestor = 0;
						BSTNode		*tmp = root;

						if (!root || !current)
							return (0);
						// Case 1: left child exists
						if (current->left)
							return (current->left);
						// Case 2: no left child
						else
						{
							while (tmp->left != current && tmp->right != current)
							{
								if (current->first > ancestor->first)
								{
									ancestor = tmp;
									tmp = ancestor->right;
								}
								else
									tmp = tmp->left;
							}
							return (ancestor);
						}
					}

				public:

					// Constructor #1 (empty)
					reverse_iterator(void) : _node(0), _root(0) { return ; }

					// Constructor #2 (init)
					reverse_iterator(map<Key, T, Compare, Alloc> const &rhs) {

						BSTNode		*tmp;

						this->_node = rhs.rbegin();
						this->_root = this->_node;

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
						return ;
					}

					// Copy constructor
					reverse_iterator(reverse_iterator const &src) {
						
						*this = src;
						return ;
					}

					// Destructor
					~reverse_iterator(void) { return ; }

					// Assignment operation
					reverse_iterator	&operator=(reverse_iterator const &rhs){

						this->_node = rhs._node;
						this->_root = rhs._root;

						return ;
					}

					// Comparison operator
					bool		operator==(reverse_iterator const &rhs) {

						return (this->_node->first == rhs._node->first);
					}

					bool		operator!=(reverse_iterator const &rhs) {

						return (this->_node->first != rhs._node->first);
					}

					// Dereferencing operator
					T			&operator*(void) {

						return (this->_node->second);
					}

					// Field access operator (arrow operator)
					BSTNode			*operator->(void) {

						return (this->_node);
					}

					// Increment prefix
					reverse_iterator	&operator++(void) {

						this->_node = this->getAncestor(this->_root, \
															this->_node->first);

						return (this->_node);
					}

					// Increment postfix
					reverse_iterator	operator++(int) {

						reverse_iterator	tmp(*this);

						this->_node = this->getAncestor(this->_root, \
															this->_node->first);

						return (tmp);
					}

					// Decrement prefix
					reverse_iterator	&operator--(void) {

						if (this->_node == 0 && this->_root)
						{
							this->_node = this->_root;
							while (this->_node->left)
								this->_node = this->_node->left;
						}
						else
							this->_node = this->getSuccessor(this->_root, \
															this->_node->first);
						return (this->_node);
					}

					reverse_iterator	operator--(int) {

						reverse_iterator	tmp(*this);

						if (this->_node == 0 && this->_root)
						{
							this->_node = this->_root;
							while (this->_node->left)
								this->_node = this->_node->left;
						}
						else
							this->_node = this->_getSuccessor(this->_root, \
															this->_node->first);
						return (tmp);
					}

					BSTNode		*getNode(void) {

						return (this->_node);
					}

					// *a++ overload - check
					T		*operator++(int) {

						BSTNode		*tmp = this->_node;

						if (this->_node == 0 && this->_root) // end()
							return (0); // check original. May be throw sm exception

						this->_node = this->getAncestor(this->_root, this->_node->first);
						if (!this->_node)
							return (0);
						return (&(this->_node->second));
					}

					// *a-- overload - check
					T		*operator--(int) {

						BSTNode		*tmp = this->_node;

						if (this->_node == 0 && this->_root) // end()
							return (0); // check original. May be throw sm exception

						this->_node = this->getSuccessor(this->_root, this->_node->first);
						if (!this->_node)
							return (0);
						return (&(this->_node->second));
					}
			};

			// Iterators
			iterator	begin(void) {

				BSTNode		*first = this->_root;

				if (!first)
					return (iterator());
				while (first->left)
					first = first->left;

				return (iterator(first, this->_root));
			}

			iterator	end(void) {

				return (iterator(0, this->_root));
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

				return (iterator(0, this->_root));
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
					tmp = this->insertNode(this->_root, k, 0);
				return (tmp->second);
			}

			// Modifiers
			// Insert #1 (single element)
			std::pair<iterator, bool>	insert(value_type const &val) {

				BSTNode		*tmp = this->findNode(this->_root, val.first);
				ft::map<Key, T, Compare, Alloc>::iterator	it;
				bool		res = false;

				if (!tmp)
				{
					tmp = this->insertNode(this->_root, val.first, \
																val.second);
					res = true;
				}
				it = iterator(tmp, this->_root);

				return (std::pair(it, res));
			}

			// Insert #2 (with hint)
			iterator	insert(iterator position, value_type const &val) {

				BSTNode		*node = position.getNode();
				BSTNode		*tmp = this->findNode(node, val.first);
				ft::map<Key, T, Compare, Alloc>::iterator	it;

				if (!node)
					return (iterator());
				if (!tmp)
					tmp = this->insertNode(node, val.first, val.second);
				it = iterator(tmp, this->_root);

				return (it);
			}

			// Insert #3 (range)
			void		insert(iterator first, iterator last) {

				BSTNode		*node;
				BSTNode		*tmp;

				while (first != last)
				{
					if (!first->_root)
						return ;
					if (!this->find(this->_root, first->_node->first))
						this->insertNode(this->_root, \
									first->_node->first, first->_node->second);
					first++;
				}
			}

			// Erase #1 (single)
			void		erase(iterator position) {

				if (!position.getNode())
					return ;
				this->deleteNode(this->_root, position.getNode()->first);

				return ;
			}

			// Erase #2 (key)
			std::size_t		erase(Key const &k) {

				BSTNode		*tmp = deleteNode(this->_root, k);

				if (!tmp)
					return (0);
				return (1);
			}

			// Erase #3 (range)
			void		erase(iterator first, iterator last) {

				while (first != last)
				{
					if (!first.getNode())
						return ;
					this->deleteNode(this->_root, first.getNode()->first);
					first++;
				}
			}

			// Swap
			void		swap(map<Key, T, Compare, Alloc> &x) {

				BSTNode		*tmp = this->_root;

				this->_root = x->_root;
				x->_root = tmp;
			}

			// Clear
			void		clear(void) {

				this->deleteBST(this->_root);
			}

			// Observers
			// Key_comp
			// Create key_compare class
			class key_compare {

				private:

				public:
			};
	};
}

#endif
