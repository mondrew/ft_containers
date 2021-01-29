/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:04:03 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/29 20:11:04 by mondrew          ###   ########.fr       */
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

			struct		BST {

				Key		key;
				T		val;
				BST		*left;
				BST		*right;
			};

			BST		*_root;

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

			map		&operator=(map const &rhs) {
			}
	};
}

#endif
