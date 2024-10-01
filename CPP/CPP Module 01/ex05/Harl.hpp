/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:20:14 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/20 10:45:20 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

class   Harl
{
	private:
		void    debug(void);
		void    info(void);
		void    warning(void);
		void    error(void);
		
	public:
		Harl();
		~Harl();

		void	complain(std:: string level);
};

typedef void (Harl::*t_func) (void);