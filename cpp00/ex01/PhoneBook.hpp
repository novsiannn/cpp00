/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:06:56 by novsiann          #+#    #+#             */
/*   Updated: 2023/12/02 16:53:18 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include<iomanip>
#include <string>

class Contact{
	public:
		void	Add();
	private:
		std::string data[5];
		static std::string questions[5];
};

class PhoneBook {
	public:
		void	ComandDefine();
		void	Search();
		void	PrintHead();
	private:
		Contact contacts[8];
};

#endif