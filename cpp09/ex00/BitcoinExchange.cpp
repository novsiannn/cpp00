/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:21:44 by novsiann          #+#    #+#             */
/*   Updated: 2024/03/15 09:53:43 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _data(src._data)
{
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this == &src) 
		return *this;
    this->_data = src._data;
    return (*this);
}

const char *BitcoinExchange::NonExistentFile::what() const throw()
{
	return ("File was not open, file not exist");
} 

void	BitcoinExchange::read_data()
{
	std::ifstream file("data.csv");
	std::string	line;
	std::string	elem;
	double		value;

	if (file.is_open())
	{
		while(std::getline(file, line))
		{
			std::istringstream iss(line);
			if(std::getline(iss, elem, ','))
			{
				iss >> value;
				_data[elem] = value;
			}
			iss.clear();
		}
	}
	else
		throw NonExistentFile();
	file.close();
	// for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); ++it)
	// {
    // 	std::cout << it->first << "=>" << it->second << std::endl;
	// }
}


//That function is not finished because I must webserv start, I'll finish it in 1-2 month.
// I need to handle date that is not in the database and find date closest to non-exist date.
std::map<std::string, double>::iterator	BitcoinExchange::findInData( std::string date )
{
	std::map<std::string, double>::iterator it;
	std::istringstream iss(date);
	std::ostringstream oss;
	int year, month, day;
	char dash;

	iss >> year >> dash >> month >> dash >> day;
	it = _data.find(date);
	
	// std::cout << " HERE " << year << dash << month << dash << day << std::endl;

	if(it != _data.end())
		return it;

	while(true)
	{
		if(day > 1)
			day--;
		else if (month > 1)
		{
			day = 31;
			month--;
		}
		else
		{
			month = 12;
			year--;
		}
		
		oss << year << dash;
		if (month < 10)
			oss << 0 << month << dash;
		else
			oss << month << dash;
		if (day < 10)
			oss << 0 << day;
		else
			oss << day;

		date = oss.str();
		// std::cout<< "Date after change" << date << std::endl;
		// it = _data.find(date);
		std::cout << date << " " << std::endl;
		it = _data.find(date);
		if (it != _data.end())
			return it;
		if (date == "2009-01-02")
			return _data.begin();
	}
}