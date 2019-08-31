/**************************************************************
 * File:    MyExceptions.h
 * Project: CSCE 221 - Project 1
 * Author : James Robinson
 * Date   : 2/10/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * MyExceptions Class definition.
 * Will be thrown in try and catch statement when there 
 * is an error in the Driver.cpp file
 *************************************************************/
#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <string>

class Exceptions221 {
public:

    /**********************************************************************
     * Name: MyExceptions (Constructor)
     * PreCondition: String containing error description.  
     * 
     * PostCondition:  Error object
     *********************************************************************/
	Exceptions221(std::string message) : m_message(message) {}

    /**********************************************************************
     * Name: GetMessage
     * PreCondition: None.  
     * 
     * PostCondition:  Returns error message.
     *********************************************************************/
    const std::string GetMessage() { return m_message; }
    
private:
	//Error message.
    std::string m_message; 
};

#endif
