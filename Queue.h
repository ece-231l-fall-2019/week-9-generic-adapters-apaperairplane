#include <iostream>

template<typename T>

Queue
{
  protected:
     List<T> c;
  public:
     T& front(){
     	return c.front();
     }
     T& back(){
     	return c.back();
     }
     const T& front() const{
     	return c.front();
     }
     const T& back() const{
     	return c.back();
     }
     void push(const T& val){
     	c.push_back(val);
     }
     void pop(){
     	c.pop_front();
     }
     size_t size() const{
     	return c.size();
     }
     bool empty() const{
     	return c.empty();
     }
     Queue<T>& operator=(const Queue<T>& b){
     	return c = b;
     }
     bool operator==(const Queue<T>& c, const Queue<T>& b){
     	for(int i = 0; c.front* != c.back*; i++){
		if(c.front + i != b.front + i){
			return false;
		}
	}
	return true;
     }
     bool operator!=(const Queue<T>& c, const Queue<T>& b){
     	if(c==b)
		return false;
	return true;
     }
};
