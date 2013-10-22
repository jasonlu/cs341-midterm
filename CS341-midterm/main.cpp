//
//  main.cpp
//  CS341-midterm
//
//  Created by Jason Lu on 10/22/13.
//  Copyright (c) 2013 Lu Jason. All rights reserved.
//
//  1) A list up to 100 int from user's input.
//  2) Terminated by ctrl-z, ctrl-b, ctrl-d or string command.
//  3) Sort list in ascending order.
//  4) Calcutes and displays the mean and the median of the list.
//  5) Array managed by an object. (container class)


#include <iostream>
using namespace std;


class List {
public:
    List () {
        mean = 0;
        median = 0;
        length = 0;
        sum = 0;
    }
    
    bool addNumber(int num) {
        if(length > 99) {
            return false;
        }
        numbers[length] = num;
        sum += num;
        length++;
        return true;
    }
    
    int getNumber(unsigned int index) {
        return numbers[index];
    }
    
    bool setNumber(unsigned int index, int value) {
        numbers[index] = value;
        return true;
    }
    
    bool sort() {
        int i, j, flag = 1;    // set flag to 1 to start first pass
        int temp;             // holding variable
        for(i = 1; (i <= length) && flag; i++) {
            flag = 0;
            for (j=0; j < (length -1); j++) {
                if (numbers[j+1] < numbers[j]) {
                    temp = numbers[j];             // swap elements
                    numbers[j] = numbers[j+1];
                    numbers[j+1] = temp;
                    flag = 1;               // indicates that a swap occurred.
                }
            }
        }
        return true;
    }
    
    double getMean() {
        return getAvg();
    }
    
    double getMedian() {
        if(length % 2 == 0) {
            return (double)(numbers[length / 2] + numbers[length / 2 - 1]) / 2;
        } else {
            return numbers[length / 2 ];
        }
    }
    
    long getSum() {
        return sum;
    }
    
    double getAvg() {
        return (double)(sum / length);
    }
    
    int getLength() {
        return length;
    }
    
    int limit() {
        return 100;
    }
    
private:
    int numbers[100], length;
    long sum;
    double mean, median;
};

class ListContainer {
public:
    ListContainer() {}
    double getAvg() {
        return list.getAvg();
    }
    double getMean() {
        return getAvg();
    }
    bool addNumber(int num) {
        return list.addNumber(num);
    }
    int length() {
        return list.getLength();
    }
    int getNumber(unsigned int index) {
        return list.getNumber(index);
    }
    bool sort() {
        return list.sort();
    }
    double getSum(){
        return list.getSum();
    }
    double getMedian() {
        return list.getMedian();
    }
    
private:
    List list;
};


int main(int argc, const char * argv[])
{
    
    // insert code here...
    std::cout << "Hello, World!\n";
    int x, count = 0;
    ListContainer list;
    
    /*
    while((x = Utility::readAsInt("Please enter an integer (quit to end input): ")) != NULL && count < list.limit()) {
        list.addNumber (x);   // add user input to running sum
        count++;
    }
    */
    while ( !cin.eof() && cin.good() )   // two cin system tests (1) for end-of-data (2) valid data
    {  cout << "Please enter an integer (Ctrl-d, Ctrl-z to end input)";   // prompt user for input
		cin >> x;
        if (cin.good()) {
            list.addNumber(x);
            count++;
		}
    }  // end while
    cout << endl;
    list.sort();
    
    for (int i=0; i < list.length(); i++) {
        cout << "Index: " << i << ", value: " << list.getNumber(i) << endl;
    }
	cout << "Sum = " << list.getSum () << endl;
	if ( list.length() != 0 ) {
        cout << "Median = " << list.getMedian() << endl;  // display average
        cout << "Average = " << list.getMean() << endl;  // display average
    }
    
    return 0;
}
