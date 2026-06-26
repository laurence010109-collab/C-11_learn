#include<cstddef>
#include<algorithm>
#include<iostream>

class MyVector
{
public:
    MyVector():data_(nullptr),size_(0),capacity_(0)
    {

    }
    //explicit关键字用于防止隐式类型转换，避免出现意外的类型转换错误
    explicit MyVector(size_t capacity):data_(new int[capacity]{}),size_(0),capacity_(capacity)
    {

    }
    
    MyVector(const MyVector& other):data_(other.capacity_>0 ? new int[other.capacity_]{} : nullptr),size_(other.size_),capacity_(other.capacity_)
    {
        std::copy(other.data_,other.data_+size_,data_);//copy函数将other.data_中的元素复制到data_中
    }
    MyVector& operator=(const MyVector&other);
    ~MyVector()
    {
        delete[] data_;
    }

    void push_back(int value)
    {
        if(size_==capacity_)
        {
            size_t new_capacity(capacity_==0 ? 4:capacity_*2);
            reallocate(new_capacity);//重新分配内存
        }
        data_[size_++]=value;
    }
    size_t size() const
    {
        return size_;
    }
    size_t capacity() const
    {
        return capacity_;
    }
    int& operator[](size_t index)
    {
        return data_[index];
    }
    const int& operator[](size_t index) const
    {
        return data_[index];
    }

private:
    int* data_; // 指向堆上数组的指针
    size_t size_;// 当前元素个数
    size_t capacity_;// 已分配容量

    void reallocate(size_t new_capacity)
    {
        int* new_data=new int[new_capacity]{};
        if(data_)//data_不为空，说明已经分配了内存，需要将原来的数据拷贝到新的内存中，并释放原来的内存
        {
            std::copy(data_,data_+size_,new_data);
            delete[] data_;
            
        }
        data_=new_data;
        capacity_=new_capacity;
    }
};

int main()
{
    MyVector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for(size_t i=0;i<v.size();++i)
    {
        std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}