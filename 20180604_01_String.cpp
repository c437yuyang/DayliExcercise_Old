#include <cstring>
#include <iostream>
class String
{
  public:
    String(const char *value = "") : value_(new StringValue(value)) {} //这样的话，每次新建对象就算是指向同一个字符串还是会建立不同的对象，但是这里主要讨论的是拷贝之后的引用计数
    String &operator=(const String &rhs)
    {
        if (value_ == rhs.value_)
            return *this;

        if (--value_->ref_count_ == 0)
            delete value_;

        value_ = rhs.value_;
        ++value_->ref_count_;
        return *this;
    }
    String(const String &rhs) : value_(rhs.value_) { ++value_->ref_count_; } //拷贝构造
    ~String()
    {
        if (--value_->ref_count_ == 0)
            delete value_; //然后value_的析构函数会去delete掉实际的data_
    }

    //实现写时拷贝,这也是lazy原则的一个特例
    const char &operator[](int index) const
    {
        return value_->data_[index];
    }                           //const版本因为肯定是只读的，因此不会拷贝
    char &operator[](int index) //C++的operator[]没有办法告知是读还是写，因此只能假设非const版本的全部是写
    {
        if (value_->ref_count_ > 1)
        {
            --value_->ref_count_;
            value_ = new StringValue(value_->data_);
            //value_->ref_count_ = 1; //这一步构造函数里面其实已经做了
        }
        return value_->data_[index];
    }

  private:
    struct StringValue
    {
        int ref_count_;
        char *data_;
        StringValue(const char *initValue);
        ~StringValue();
    };
    StringValue *value_;
};

String::StringValue::StringValue(const char *init_value)
    : ref_count_(1)
{
    data_ = new char[strlen(init_value) + 1];
    strcpy(data_, init_value);
}

String::StringValue::~StringValue()
{
    delete[] data_;
}

int main()
{
    //如果这样使用:
    String s1 = "Hello";
    char *p = &s1[1]; //拿到指针
    const String s2 = s1;   //现在s2不知道p拥有了可以修改s1的指针,然后修改，s2也会受影响就
    *p = 'c';
    std::cout << s2[1] << std::endl;
    return 0;
}