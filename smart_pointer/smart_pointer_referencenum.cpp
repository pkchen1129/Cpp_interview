// Using Reference_num to count the reference number

using namespace std;
class Reference_num{
private:
    int reference_num{0};
public:
    void Increment(){
        ++reference_num;
    }
    void Decrement(){
        --reference_num;
    }
    
    int Getref() const
    {
        return reference_num;
    }
    
    Reference_num(){
        
    }
};

// Create Smart pointer template class
template<class T> 
class smart_pointer
{
private:
    /* data */
    T* object_{nullptr};
    // Create Reference_ instance here
    Reference_num* Reference_num_{nullptr};
public:
    smart_pointer(T *object)
    : object_(object)
    , Reference_num_{ new Reference_num() }
    {
        Reference_num_->Increment();
        cout << "Created smart ptr... Reference number is: " << Reference_num_->Getref() << endl; 
    }
    
    // Delete when the smart pointer disappear. Virtual destructor 
    virtual ~smart_pointer()
    {
        // Check if having this object
        if(Reference_num_){
            int decremented_reference_num = Reference_num_->Decrement();
            cout << "Decremented reference number: " << Reference_num_->Getref();
            if(decremented_reference_num <= 0){
                delete Reference_num_;
                delete object_;
            }
        }
    }
    
};

smart_pointer::smart_pointer(/* args */)
{
}

smart_pointer::~smart_pointer()
{
}

