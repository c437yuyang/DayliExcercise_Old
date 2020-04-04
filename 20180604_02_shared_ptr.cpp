#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <memory>
template<class T>
class RefPtr
{
public:
	typedef RefPtr<T> this_type;
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;

	//ref_cnt_ptr(); //暂时没有考虑空值的情况

	RefPtr(pointer ptr);

	~RefPtr();

	RefPtr(const RefPtr<T>&rhs);

	RefPtr<T>& operator=(const RefPtr<T>&rhs);

	//template<class U>
	//RefPtr(const RefPtr<U>&rhs); //泛化copying函数，用来有血缘关系的类之间构造对象及赋值，暂时实现不了

	//template<class U>
	//ref_cnt_ptr<T>& operator=(const ref_cnt_ptr<U>&rhs);

	reference operator*() { return *(obj_ptr_->ptr_); }

	pointer operator->() { return obj_ptr_->ptr_; }

	size_t ref_count() { return obj_ptr_->ref_cnt_; }

	bool unique() { return obj_ptr_->ref_cnt_ == 1; }

private:
	struct RCObject
	{
		RCObject(pointer ptr) :ptr_(ptr), ref_cnt_(1) {}
		void add_reference() { ++ref_cnt_; }
		void sub_reference() { --ref_cnt_; }
		~RCObject()
		{
			delete ptr_;
			ptr_ = nullptr;
		}
		pointer ptr_;
		size_t ref_cnt_;
	};

private:
	void try_clear();
private:
	RCObject * obj_ptr_;

	friend class RefPtr;
};

template<class T>
RefPtr<T>::RefPtr(pointer ptr)
{
	obj_ptr_ = new RCObject(ptr);
}

template<class T>
RefPtr<T>::RefPtr(const RefPtr<T>&rhs)
	:obj_ptr_(rhs.obj_ptr_)
{
	obj_ptr_->add_reference();
}

template<class T>
RefPtr<T>::~RefPtr()
{
	obj_ptr_->sub_reference();
	try_clear();
}

template<class T>
void RefPtr<T>::try_clear()
{
	if (obj_ptr_->ref_cnt_ == 0)
	{
		delete obj_ptr_;
		obj_ptr_ = nullptr;
	}
}

template<class T>
RefPtr<T>& RefPtr<T>::operator=(const RefPtr<T>&rhs)
{
	obj_ptr_->sub_reference();
	try_clear();
	obj_ptr_ = rhs.obj_ptr_;
	obj_ptr_->add_reference();
}

//template<class T> //写在类外的写法注意
//template<class U>
//RefPtr<T>::RefPtr(const RefPtr<U>&rhs)
//	:obj_ptr_(rhs.obj_ptr_)
//{
//	obj_ptr_->add_reference();
//}




class Widget
{
public:
	Widget(int idata) :idata_(idata) {}
	void add() { ++idata_; }
	int idata() { return idata_; }
	~Widget()
	{
		std::cout << "Widget::~Widget()" << std::endl;
	}
private:
	int idata_;

};

class SpecialWidget :public Widget
{
public:
	SpecialWidget(int idata) :Widget(idata) {}
};

int main()
{
	{
		RefPtr<Widget> s1(new Widget(1));
		RefPtr<Widget> s2 = s1;
	}

	RefPtr<Widget> s1(new Widget(1));
	{
		RefPtr<Widget> s2 = s1;
		std::cout << std::boolalpha << s1.unique() << std::endl;
	}
	std::cout << std::boolalpha << s1.unique() << std::endl;

	s1->add();
	std::cout << s1->idata() << std::endl;
	(*s1).add();

	RefPtr<SpecialWidget> sw1(new SpecialWidget(1));
	//RefPtr<Widget> s2(sw1);
	

	std::shared_ptr<SpecialWidget> shared_ptr_w1(new SpecialWidget(1));
	std::shared_ptr<Widget> shared_ptr_w2(shared_ptr_w1);



	return 0;
}