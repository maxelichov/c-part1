
#pragma warning(disable: 4996)
#include "Address.h"


class User { // user can be either seller / buyer / or both.

 protected:
	 char* Username;
	 char* FirstName;
	 char* LastName;
	 char* Password;
	 Address address;


  public:

	  User(char* username, char* firstname, char* lastname, char* password,
		  char* Country, char* City, char* Street, int& HomeNumber);

	  bool setName(char* firstName, char* lastName);
	  bool setUsername(char* username);
	  bool setPassword(char* password);
	  char* getUsername() const;
	  char* getFirstName() const;
	  char* getLastName() const;
	  char* getPassword() const;
	  void showAddress() const;
	  User(const User& other); // copy ctor
	  const User& operator=(const User& other) 
	  {
		  if (this != &other)
		  {
			  delete[] Username;
			  delete[] FirstName;
			  delete[]LastName;
			  delete[] Password;
			  Username = strdup(other.Username);
			  FirstName = strdup(other.FirstName);
			  LastName = strdup(other.LastName);
			  Password = strdup(other.Password);
			  address = other.address;
		  }
		  return *this;
	  }
	  virtual void show() const = 0; // make class user abstract, each seller and buyer need to make their own show func.
	  

	 virtual ~User();

};