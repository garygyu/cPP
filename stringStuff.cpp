#include <iostream>
#include "string.h" //for C-string
#include <string> // string class
class SimpleCat
{
public:
    SimpleCat(int age, int weight);
    ~SimpleCat() {}
    int GetAge() { return itsAge; }
    int GetWeight() { return itsWeight; }
private:
    int itsAge;
    int itsWeight;
};
  
SimpleCat::SimpleCat(int age, int weight):
itsAge(age), itsWeight(weight) {}
  
decltype(auto) TheFunction()
{
    SimpleCat Frisky(20,9);
    return Frisky;
}
  
int main()
{
    //auto&& rCat = std::forward<SimpleCat>(TheFunction());
	auto&& rCat = TheFunction();
    auto age = rCat.GetAge();
    std::cout << "rCat is " << age << " years old!\n";
    return 0;
}

using namespace std;

int main (int argc, char* argv[])
{
    int counter = 0;
    int multiples = 0;
  	
	while(multiples < 15)
	{
		counter++;
		if(counter%2 != 0) continue;		
		if(multiples%5 == 0) cout << "\n";
		multiples ++;
		cout << counter << "\t";
	}
    std::cout << "\n";

	//char string1[] = "Free the bound periodicals!";
	
	char string1 [80];
	std::cout << "\nWhat your name?";
	std::cin.getline(string1, 79);
    char string2[80];

    strcpy(string2, string1);
	std::string string3(string2);

    std::cout << "String1: " << string1 << std::endl;
    std::cout << "String2: " << string2 << std::endl;
	std::cout << "String3: " << string3 + " OK!" << std::endl;
    std::cout << "\n";
return 0;	
}
