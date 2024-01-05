// Copyright (c) 2023 Julien Lamoureux All rights reserved.
// .
// Created By: Julien Lamoureux
// Date: January 1, 2024
// This program shows the even numbers in a list OR sorts two lists numerically

#include <iostream>
#include <list>

std::list<int> SortElementList(
    std::list<int> listOne,
    std::list<int> sortedList) {
    // combine the two lists into sortedList
    sortedList.merge(listOne);

    // use a nested for loop to find each combination of numbers
    for (int counterOne = 0; counterOne < sortedList.size(); counterOne++) {
        // set the index of sortedList to coutnerOne
        // Source :
        // https://stackoverflow.com/questions/16747591/
        auto sortedListCounterOne = sortedList.begin();
        std::advance(sortedListCounterOne, counterOne);
        for (int counterTwo = 1; counterTwo < sortedList.size(); counterTwo++) {
            // set the index of sortedList to coutnerTwo
            auto sortedListCounterTwo = sortedList.begin();
            std::advance(sortedListCounterTwo, counterTwo);

            // if sortedListCounterOne >= sortedListCounterTwo :
            // then swap their values
            if (*sortedListCounterOne >= *sortedListCounterTwo) {
                *sortedListCounterOne, *sortedListCounterTwo
                = *sortedListCounterTwo, *sortedListCounterOne;
            }
        }
    }

    // return sortedList
    return sortedList;
}

void SortListMain() {
    // declare string variables
    std::string userIntStrOne, userIntStrTwo;

    // declare the two int lists
    std::list<int> intListOne;
    std::list<int> intListTwo;

    // tell the user what the program does
    std::cout << "This program displays the combined, sorted";
    std::cout << " list of the user's two integer lists." << std::endl;
    do {
        // get userIntStrOne
        std::cout << "First Int List : Enter your integer";
        std::cout << "here (type stop to exit): ";
        std::cin >> userIntStrOne;

        try {
            // covert userIntStrOne mark to int
            int userIntOne = std::stoi(userIntStrOne);

            // append userIntOne to the first int list
            intListOne.push_back(userIntOne);
        } catch (std::invalid_argument) {
            // if userIntStrOne == "stop", then break
            if (userIntStrOne == "stop") {
                break;
            } else {
                // otherwise, tell the user to enter a valid int
                std::cout << userIntStrOne
                          << " is not a valid integer" << std::endl;
            }
        }
    } while (userIntStrOne != "stop");

    do {
        // get userIntStrTwo
        std::cout << "Second Int List : Enter ";
        std::cout << "your integer here (type stop to exit): ";
        std::cin >> userIntStrTwo;

        try {
            // covert userIntStrOne to int
            int userIntTwo = std::stoi(userIntStrTwo);

            // append userIntTwo to the second int list
            intListTwo.push_back(userIntTwo);
        } catch (std::invalid_argument) {
            // if userIntStrTwo == "stop", then break
            if (userIntStrTwo == "stop") {
                break;
            } else {
                // otherwise, tell the user to enter a valid int
                std::cout << userIntStrTwo
                          << " is not a valid integer" << std::endl;
            }
        }
    } while (userIntStrTwo != "stop");

    // call the SortElementList function
    std::list<int> sortedListMain = SortElementList(intListOne, intListTwo);

    // display the sorted list using a for each loop
    std::cout << "The sorted, combined list is " << std::endl;
    for (int aNum : sortedListMain) {
        std::cout << aNum << std::endl;
    }
}

std::list<int> EvenNumList(std::list<int> listOfInt) {
    // declare evenList
    std::list<int> evenList;

    // use a for each loop when aNum is in listOfInt
    for (int aNum : listOfInt) {
        // if a aNum is a multiple of two, append it to evenList
        if (aNum % 2 == 0) {
            evenList.push_back(aNum);
        }
    }
    // return evenList
    return evenList;
}

void EvenNumListMain() {
    // declare variables and lists
    std::string userIntStr;
    int userInt;
    std::list<int> listOfInt;

    // display what the program does
    std::cout << "This program displays all the even numbers ";
    std::cout << "in the user's list of integers." << std::endl;

    do {
        // get userIntStr
        std::cout << "Enter your number here (type stop to exit): ";
        std::cin >> userIntStr;

        try {
            // convert userIntStr to an int
            userInt = std::stoi(userIntStr);

            // append userInt to listOfInt
            listOfInt.push_back(userInt);
        } catch (std::invalid_argument) {
            // if userIntStr == "stop", then break
            if (userIntStr == "stop") {
                break;
            } else {
                // otherwise, tell the user to enter a valid int
                std::cout << userIntStr
                          << " is not a valid integer" << std::endl;
            }
        }
    } while (userIntStr != "stop");
    // call the evenNumList Function
    std::list<int> evenList = EvenNumList(listOfInt);

    // display evenList using a for each loop
    for (int aNumTwo : evenList) {
        std::cout << aNumTwo << std::endl;
    }
}

int main() {
    // declare userChoice
    std::string userChoice;

    // get userChoice
    std::cout << "This program either shows all the even numbers ";
    std::cout << "in a list(Press 1 for this) or sorts two lists";
    std::cout << " in numerical order(Press 2 for this).";
    std::cin >> userChoice;

    // if userChoice == 1, then call EvenNumListMain
    if (userChoice == "1") {
        EvenNumListMain();
    } else if (userChoice == "2") {
        // otherwise, if userChoice is 2, call SortListMain()
        SortListMain();
    } else {
        // tell the user to enter 1 or 2
        std::cout << "Please enter 1 or 2 as an option." << std::endl;
    }
}
