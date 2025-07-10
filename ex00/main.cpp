/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:22:59 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/10 14:25:19 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bureaucrat("Ryan", 150);
    std::cout << bureaucrat << std::endl;
    bureaucrat.incrementGrade(1);
    std::cout << bureaucrat << std::endl;
    bureaucrat.decrementGrade(1);
    std::cout << bureaucrat << std::endl;
    return 0;
}