#ifndef __EE231_List_h__
#define __EE231_List_h__

#include <iostream>

template<typename T>
class List
{
        private:
        typedef struct llist {
                T val;
                llist *next;
                llist *prev;
        } llist;

        llist *_head; //begining of list
        llist *_tail;// end of list
        size_t _size;

        public:
//--- Default Constructor ------------------------------
        List(){
                _head = 0;
                _tail = 0;
                _size = 0;
        }
//--- Copy Constructor ---------------------------------
	List(const List<T>& other){
        	_head = other._head;
        	_tail = other._tail;
        	_size = other.size();
	}
	List(const std::initializer_list&){};
//--- Destructor ---------------------------------------
        ~StringList(){
                while(!empty())
                        pop_front();
        }
//--- Operator Equal -----------------------------------
	List& operator=(const List<T>& b){	
        	if(!empty())
        	        clear();

        	const llist *copier = b._head;
        	while(copier != NULL)
        	{
                	push_back(copier->val);
                	copier = copier->next;
        	}
                	_size = b.size();
        	return *this;
	}
//--- Empty --------------------------------------------
        bool empty() const{
                if(_head == 0)
                        return true;
                return false;
        }
//--- Size ---------------------------------------------
        size_t size() const{
                return _size;
        }
//--- Clear --------------------------------------------
	void clear(){
        while(empty() == false){
                pop_back();
        }
        _size = 0;
}
//--- Reference Front ----------------------------------
        const List<T>& front(){
                return _head->val;
        }
//--- Reference Back -----------------------------------
        const List<T>& back(){
                return _tail->val;
        }
//--- Push Front ---------------------------------------
	void push_front(const T& val){
        	llist *newFront = new llist;
        	newFront->val = val;
        	newFront->next = _head;
        	newFront->prev = 0;
        	if (_head != 0)
        	        _head->prev = newFront;
        	if (_tail == 0)
        	        _tail = newFront;
        	_head = newFront;
	        _size++;
	}
//--- Push Back ----------------------------------------
	void push_back(const T& val){
        	llist *newBack = new llist;
        	newBack->val = val;
        	newBack->next = 0;
        	newBack->prev = _tail;
        	if(_tail != 0)
        	        _tail->next = newBack;
        	if(_head == 0)
        	        _head = newBack;
        	_tail = newBack;
        	_size++;
	}
//--- Pop Front ----------------------------------------
	void pop_front(){
	        llist *front = _head;
	        _head = _head->next;
	        if(_head)
	                _head->prev = _head->prev->prev;
	        else
	                _tail = 0;
	        delete front;
	        _size--;
}
//--- Pop Back -----------------------------------------
	void pop_back(){
	        llist *back = _tail;
	        _tail = _tail->prev;
	        if(_tail)
	                _tail->next = _tail->next->next;
	        else
	        _head = 0;
	        delete back;
	        _size--;
	}
//--- Reverse ------------------------------------------
	void reverse(){
                llist *newhead = _tail;
                llist *esrever;
                for( ; newhead != NULL; newhead = newhead->next){
                        esrever = newhead->next;
                        newhead->next = newhead->prev;
                        newhead->prev = esrever;
                }
                llist *temp = _head;
                _head = _tail;
                _tail = temp;
        }
//--- Unique -------------------------------------------
	void unique(){
	        for(llist *clean = _head; clean != NULL; clean = clean->next){
	                while(clean->next != NULL && clean->val == clean->next->val){
	                        llist *data = clean->next;
	                        clean->next = data->next;
	                        if(data->next != NULL)
	                                data->next->prev = clean;
	                        else
	                                _tail = clean;
	                        delete data;
	                        _size--;
	                }
	        }
	}
//--- Print --------------------------------------------
	void printList(){
        	llist *printer = _head;
        	while(printer != 0)
        	{
        	        std::cout << printer->val << " ";
        	        printer = printer->next;
        	}
        	std::cout << "\n";
	}
};

#endif // __EE231_List_h__
