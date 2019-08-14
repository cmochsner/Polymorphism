#include <iostream>
#include <string>

using namespace std;

class Animal
{
	string name;

	protected:
		string gender;

	public:
		Animal()
		{
			name = "";
			gender = "male";
		}
		void setName(string n)
		{
			name = n;
		}
		void setGender(string g)
		{
			if (g == "f" || g == "F")
			{
				gender = "Female";
			}
		}
		virtual void print()
		{
			cout << endl << name << " is a " << gender << ".";
		}
};
class Dog: public Animal
{
	string sound;
	bool walks;

	public:
		Dog()
		{
			walks = false;
			sound = "Woof!";
		}
		void setWalks(string ans)
		{
			if (ans == "yes" || ans == "Yes")
			{
				walks = true;
			}
		}
		void print()
		{
			Animal::print();

			if (gender == "Female")
			{
				cout << " She ";
			}
			else
			{
				cout << " He ";
			}

			cout << "goes \"" << sound << "\" and likes to ";

			if (!walks)
			{
				cout << "not ";
			}

			cout<<"walk." << endl;
		}
};
class Cat : public Animal
{
	string sound;
	bool indoor;

	public:
		Cat()
		{
			indoor = false;
			sound = "Meow!";
		}
		void setIndoor(string ans)
		{
			if (ans == "Yes" || ans == "yes")
			{
				indoor = true;
			}
		}
		void print()
		{
			Animal::print();

			if (gender == "Female")
			{
				cout << " She ";
			}
			else
			{
				cout << " He ";
			}

			cout << "goes \"" << sound << "\" and is an ";
			
			if (indoor)
			{
				cout << "indoor ";
			}
			else
			{
				cout << "outdoor ";
			}

			cout << "cat." << endl;
		}
};
class Pig : public Animal
{
	string sound;
	bool pink;

	public:
		Pig()
		{
			pink = false;
			sound = "Oink!";
		}
		void setPink(string ans)
		{
			if (ans == "yes" || ans == "Yes")
			{
				pink = true;
			}
		}
		void print()
		{
			Animal::print();

			if (gender == "Female")
			{
				cout << " She ";
			}
			else
			{
				cout << " He ";
			}

			cout << "goes \"" << sound << "\" and is ";

			if (!pink)
			{
				cout << "not ";
			}

			cout << "colored pink." << endl;
		}
};

void printer(Animal *obj);

int main()
{
	int choice = 0;
	string name, gender;

	cout << "Welcome to the Animal Polymorphism Program!" << endl;
	
	while (choice != 5)
	{
		cout << "\nPick your animal by entering a number." << endl;
		cout << "1. Dog" << endl;
		cout << "2. Cat" << endl;
		cout << "3. Pig" << endl;
		cout << "4. Other" << endl;
		cout << "5. Exit the program" << endl;
		cin >> choice;
		
		if (choice == 5)
		{
			continue;
		}

		cout << "What's your animal's name?" << endl;
		cin >> name;
		cout << "What's your animal's gender? Enter f for Female, m for male." << endl;
		cin >> gender;

		switch (choice)
		{
			case 1:
			{
				Dog *d=new Dog;
				string ans;

				d->setName(name);
				d->setGender(gender);

				cout << "Does your dog like to go on walks? If so, enter yes. If not, enter anything else." << endl;
				cin >> ans;

				d->setWalks(ans);

				printer(d);

				delete d;
			}
				break;
			case 2:
			{
				Cat *c = new Cat;
				string ans;

				c->setName(name);
				c->setGender(gender);

				cout << "Is your cat an indoor cat? If so, enter yes. If not, enter anything else." << endl;
				cin >> ans;

				c->setIndoor(ans);

				printer(c);

				delete c;
			}
				break;
			case 3:
			{
				Pig *p = new Pig;
				string ans;

				p->setName(name);
				p->setGender(gender);

				cout << "Is your pig pink? If so, enter yes. If not, enter anything else." << endl;
				cin >> ans;

				p->setPink(ans);

				printer(p);

				delete p;
			}
				break;
			case 4:
			{
				Animal *a = new Animal;

				a->setName(name);
				a->setGender(gender);

				printer(a);
				cout << endl;

				delete a;

				break;
			}
			case 5:
				break;
			default:
				cout << "Invalid Choice. Try again." << endl;
				break;
		}
	}

	return 0;
}
void printer(Animal *obj)
{
	obj->print();
}