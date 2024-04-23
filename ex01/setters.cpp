/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:54:25 by alletond          #+#    #+#             */
/*   Updated: 2024/04/23 14:57:33 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::setName(std::string name)
{
    _name = name;
}

void Contact::setLastname(std::string lastname)
{
    _lastName = lastname;
}

void Contact::setNickname(std::string nickname)
{
    _Nickname = nickname;
}

void Contact::setNumber(std::string number)
{
    _number = number;
}

void Contact::setSecret(std::string secret)
{
    _secret = secret;
}