#include <iostream>
#include <cstdlib>
#include <string>
#define MAX_SIZE 20

// Returns sum Ignoring the last check digit (right most digit) of the credit card number, and moving left,the value of every second digit and find the sum of these doubled numbers. If the result of the doubling operation is a two-digit number, you should add the digits of the doubled number before finding the sum.
int sum1(int* array, int size)
{   
    int digit2x_size = size/2;
    int digit2xsum[digit2x_size];
    int digits2x[digit2x_size];
    int Fsum = 0;
    printf("Calculating sum1\n");
    for (int i = size-2; i >= 0; i-=2)
    {
        int sum2x = array[i]*2;
        if (sum2x > 9)
        {
            sum2x = 1 + sum2x%10;
        }
        digits2x[(size - (i+2))/2] = array[i];    
        digit2xsum[(size - (i+2))/2] = sum2x;
        
        Fsum += sum2x;   
    }

    for (int i = 0; i < digit2x_size; i++)
    {
        printf("%d -> %d\n", digits2x[i], digit2xsum[i]);
    }
    
    return Fsum;
    
}

// Returns the sum of all other numbers (last digit is not included in this sum as well). You must printout the numbers for sum2, these should be in the order (from left to right) as it appears on credit card
int sum2(int* array, int size)
{
    printf("Calculating sum2\n");
    int OtherSum = 0;

    for (int i = 1; i < size-2; i+=2)
    {
        OtherSum += array[i];
        printf("%d -> %d\n", array[i], array[i]);
    }

    return OtherSum;
    
}

int main()
{
    std::cout << "Enter the Credit Card Number Digit by Digit \n";
    int num;
    int i = 0;
    int digits = 20;
    int c_card[MAX_SIZE]; 
    while (std::cin >> num)
    {
        if (num == -1)
        {
            digits = i;
            break;
        }

        c_card[i] = num;
        i++;
    }

    int value1 = sum1(c_card, digits);
    int value2 = sum2(c_card, digits);
    int final = value1 + value2;
    int checksum = final%10;

    printf("%d + %d = %d\n", value1, value2, final);
    printf("Checksum is %d\n", checksum);

    return 0;
}