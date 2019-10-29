#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 0
#include "List.h"
typedef List<std::string> StringList;
typedef List<int> IntList;
#include "Stack.h"
typedef Stack<std::string> StringStack;
typedef Stack<int> IntStack;
#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	//DONE
	std::cout << "String List" << std::endl;
	StringList a;
	StringList b;

	a.push_front("A");
	Assert(a.front() == "A", "front == A");
	a.push_front("B");
	Assert(a.front() == "B", "front == B");
	a.pop_front();
	Assert(a.front() == "A", "front == A");
	a.push_front("Z");
	Assert(a.front() == "Z", "front == Z");

	b = a;

	Assert(b.front() == "Z", "b.front == Z");
	b.pop_front();
	Assert(b.front() == "A", "b.front == A");
	b.pop_front();
	Assert(b.empty() == true, "b is empty");
	Assert(a.empty() == false, "a is NOT empty");
	a.clear();
	Assert(a.empty() == true, "a.clear == empty");
	Assert(a.size() == 0, "size == 0");
	a.push_front("A");
	a.push_front("B");
	a.pop_back();
	Assert(a.size() == 1, "size == 1");
	Assert(a.front() == "B", "front == B");
	a.push_back("B");
	a.push_back("C");
	a.reverse();
	Assert(a.front() == "C", "Reverse Function");
	a.push_back("C");
	a.unique();
	a.pop_back();
	Assert(a.back() == "B", "Unique Function");
	// DONE
	
	std::cout << "\nString Stack" << std::endl;
	StringStack c;
	StringStack d;
	c.push("A");
	c.push("B");
	Assert(c.top() == "B", "B is at top");
	c.pop();
	Assert(c.empty() == false, "c is not empty");
	c.pop();
	Assert(c.empty() == true, "c is empty");
	Assert(c.size() == 0, "size == 0");
	c.push("A");
	c.push("B");
	Assert(c.size() == 2, "size == 2");
	d.push("A");
	d.push("B");
	d.push("C");
	c = d;
	Assert(c.size() == 3, "copy size == 3");
	Assert(c.top() == "C", "copy top is \"C\"");
	Assert(c == d, "c == d");
	c.pop();
	Assert(c != d, "c != d");
	// DONE

	std::cout << "\nInt List" << std::endl;
	IntList e;
        IntList f;

        e.push_front(1);
        Assert(e.front() == 1, "front == 1");
        e.push_front(2);
        Assert(e.front() == 2, "front == 2");
        e.pop_front();
        Assert(e.front() == 1, "front == 1");
        e.push_front(3);
        Assert(e.front() == 3, "front == 3");

        f = e;

        Assert(f.front() == 3, "f.front == 3");
        f.pop_front();
        Assert(f.front() == 1, "f.front == 1");
        f.pop_front();
        Assert(f.empty() == true, "f is empty");
        Assert(e.empty() == false, "e is NOT empty");
        e.clear();
        Assert(e.empty() == true, "e.clear == empty");
        Assert(e.size() == 0, "size == 0");
        e.push_front(1);
        e.push_front(2);
        e.pop_back();
        Assert(e.size() == 1, "size == 1");
        Assert(e.front() == 2, "front == 2");
        e.push_back(2);
        e.push_back(3);
        e.reverse();
        Assert(e.front() == 3, "Reverse Function");
        e.push_back(3);
        e.unique();
        e.pop_back();
        Assert(e.back() == 2, "Unique Function");
	//DONE
	
	std::cout << "\nInt Stack" << std::endl;

	IntStack g;
	IntStack h;

        g.push(1);
        g.push(2);
        Assert(g.top() == 2, "2 is at top");
        g.pop();
        Assert(g.empty() == false, "g is not empty");
        g.pop();
        Assert(g.empty() == true, "g is empty");
        Assert(g.size() == 0, "size == 0");
        g.push(1);
        g.push(2);
        Assert(g.size() == 2, "size == 2");
        h.push(1);
        h.push(2);
        h.push(3);
        g = h;
        Assert(g.size() == 3, "copy size == 3");
        Assert(g.top() == 3, "copy top is 3");
        Assert(g == h, "g == h");
        g.pop();
        Assert(g != h, "g != h");
	// DONE

	return 0;
}


