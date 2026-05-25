#include<iostream>
#include<string>

template<typename T>
class SharedPtr{
    private:
	T* ptr;
	int* count;

    public:

	explicit SharedPtr(T* p = nullptr):ptr(p){
	    if(p!=nullptr) count = new int(1);
	    else count = new int(0);
	}
	//copy
	SharedPtr(const SharedPtr<T>& other){
	    ptr = other.ptr;
	    count = other.count;
	    (*count)++;
	}

	//Assignment
	SharedPtr<T>& operator=(const SharedPtr<T>& other){
	    if(this!=&other){
		release();
		
		ptr = other.ptr;
		count = other.count;
		(*count)++;
	    }
	    return *this;

	}

	~SharedPtr(){
	    release();
	}

	void release(){
	    if(count){
		(*count)--;
		if((*count) ==0){
		    delete ptr;
		    delete count;
		}
	    }
	}

	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }

	int no_of_references() { return *count; }
};

struct Person{
    std::string name;
    int age;

    //constructor with name
    Person(const std::string &name,int age):name(name),age(age){
	std::cout<<"Person object with name: "<<this->name<<" was created!"<<std::endl;
    }

    ~Person(){
	std::cout<<"A person object was destroyed"<<std::endl;
    }

    void say_hello(){
	std::cout<<"HI I am "<<this->name<<" ,I am "<<this->age<<" years old!"<<std::endl;
    }

};


int main(){
    SharedPtr<Person> p2(new Person("Uday",19));
    
    std::cout<<"Initially there are "<<p2.no_of_references()<<"for the person with the name "<<p2->name<<"."<<std::endl;
    SharedPtr<Person> p3 = p2;
    SharedPtr<Person> p4 = p2;

    p3->say_hello();

    std::cout<<"Count after creating 2 additional pointers : "<<p2.no_of_references()<<std::endl;

    return 1;
}
