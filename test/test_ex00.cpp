/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex00.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:44:12 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/26 17:49:36 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Calculator {
public:
    T add(T a, T b) {
    return (a + b);
    }
    
    T subtract(T a, T b) {
    return (a - b);
    }

    T multiply(T a, T b) {
    return (a * b);
    }

    char devide(T a, T b) {
    if(b == 0)
    {
        cout<< "Error: Divison by zero!" <<endl;
        return (0);
    }
    return (a / b);
    }
};

int main ()
{
    Calculator<int> intCalculator;
    cout << intCalculator.add(5, 8) << endl;
    cout << intCalculator.subtract(5, 8) << endl;
    cout << intCalculator.multiply(5, 8) << endl;
    cout << intCalculator.devide(5, 8) << endl;

    Calculator<float> floatCalculator;
    std::cout << floatCalculator.add(5.2, 7.84) << endl;
    cout << floatCalculator.subtract(5.2, 7.84) << endl;
    cout << floatCalculator.multiply(5.2, 8) << endl;
    cout << floatCalculator.devide(5, 8) << endl;
        
    return (0);
    
    cin.get();
}
