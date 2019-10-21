#include <iostream>

template<typename T>
Stack
{
  protected:
     List<T> c;
  public:
     T& top(){
     	return c.front();
     }
     const T& top() const{
     	return c.front();
     }
     void push(const T&){
     	c.push_back(T);
     }
     void pop(){
     	c.pop_back();
     }
     size_t size() const{
     	return c.size();
     }
     bool empty() const{
     	return c.empty();
     }
     Stack<T>& operator=(const Stack<T>& b){
     	return c = b;
     }
     bool operator==(const Stack<T>& a, const Stack<T>& b){
     	for(int i = 0; a.front() != c.front(); i++){
		if(a.front() + i != b.front + i){
			return false;
		}
	}
	return true;
     }
     bool operator!=(const Stack<T>& a, const Stack<T>& b){
     	return !(a ==  b);
     }
};
