#include <iostream>
#include <cassert>
#include "Set.h"

class Coord
{
public:
	Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
	Coord() : m_row(0), m_col(0) {}
	double r() const { return m_row; }
	double c() const { return m_col; }
private:
	double m_row;
	double m_col;
};

void test()
{
	Set<int> si;
	Set<std::string> ss;
	assert(si.empty());
	assert(ss.empty());
	assert(si.size() == 0);
	assert(ss.size() == 0);
	assert(si.insert(10));
	assert(ss.insert("hello"));
	assert(si.contains(10));
	assert(ss.contains("hello"));
	int i;
	assert(si.get(0, i) && i == 10);
	std::string s;
	assert(ss.get(0, s) && s == "hello");
	assert(si.erase(10));
	assert(ss.erase("hello"));
	Set<int> si2(si);
	Set<std::string> ss2(ss);
	si.swap(si2);
	ss.swap(ss2);
	si = si2;
	ss = ss2;
	unite(si, si2, si);
	unite(ss, ss2, ss);
	subtract(si, si2, si);
	subtract(ss, ss2, ss);
}

int main()
{
	std::cout << "It builds!" << std::endl;
	test();
	std::cout << "Passed all test!" << std::endl;

	//Set<int> si;
	//si.insert(7);               // OK
	//Set<std::string> ss;
	//ss.insert("7-Up");          // OK
	//Set<Coord> sc;
	//sc.insert(Coord(7, -7));    // error!
}