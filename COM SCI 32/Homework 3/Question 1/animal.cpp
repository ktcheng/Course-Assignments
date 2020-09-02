// This is our abstract base class
class Animal
{
public:
	Animal(std::string name) { m_name = name; } // Constructs animal name
	virtual ~Animal() {} // Destructs the abstract base class
	virtual std::string moveAction() const { return("walk"); }// Ducks swim, Pigs/Cats walk
	virtual void speak() const = 0; // The animal class does not speak
	std::string name() const { return(m_name); } // Returns animal name
private:
	std::string m_name; // Stores animal's name
};

// This is our Cat derived class
class Cat : public Animal
{
public:
	Cat(std::string name) : Animal(name) {} // Constructs cat animal
	virtual void speak() const { std::cout << "Meow"; } // Cat speaks
	virtual ~Cat() { std::cout << "Destroying " << name() << " the cat" << std::endl; }
};

// This is our Duck derived class
class Duck : public Animal
{
public:
	Duck(std::string name) : Animal(name) {} // Constructs duck animal
	virtual void speak() const { std::cout << "Quack"; } // Duck speaks
	virtual std::string moveAction() const { return("swim"); }
	virtual ~Duck() { std::cout << "Destroying " << name() << " the duck" << std::endl; }
};

// This is our Pig derived class
class Pig : public Animal
{
public:
	Pig(std::string name, int weight) : Animal(name), m_weight(weight) {} // Constructs pig animal
	virtual void speak() const
	{
		if (m_weight < 160)
		{
			std::cout << "Oink";
		}
		else
		{
			std::cout << "Grunt";
		}
	}
	virtual ~Pig() { std::cout << "Destroying " << name() << " the pig" << std::endl; }
private:
	int m_weight; // Stores pig's weight
};