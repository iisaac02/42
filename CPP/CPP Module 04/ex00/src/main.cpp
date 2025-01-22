/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:31:42 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/28 11:38:12 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nAnimal testing" << std::endl;
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\nWrong Animal testing\n" << std::endl;
	WrongAnimal	*wrongAnimal = new WrongAnimal;
	WrongAnimal	*wrongCat = new WrongCat;

	std::cout << "\nWrongAnimal: ";
	wrongAnimal->makeSound();
	std::cout << "WrongCat: ";
	wrongCat->makeSound();
	std::cout << std::endl;
	delete wrongAnimal;
	delete wrongCat;
}
