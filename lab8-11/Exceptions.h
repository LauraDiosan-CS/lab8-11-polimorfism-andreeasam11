#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class DomainException{
protected:
	const char* message;
public:
	DomainException(const char* msg) : message(msg){
	}
	const char* getMessage() {
		return message;
	}
};

class LogginException {
protected:
	const char* message;
public:
	LogginException(const char* msg) : message(msg) {
	}
	const char* getMessage() {
		return message;
	}
};

class RepositoryException {
protected:
	const char* message;
public:
	RepositoryException(const char* msg) : message(msg) {
	}
	const char* getMessage() {
		return message;
	}
};