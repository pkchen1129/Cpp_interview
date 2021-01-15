class Human
{
private:
    int age_;
public:
    explicit Human(int age) : age_(age){}
    // Human(int age) : age_(age){}

    
};
int main(){
    //explicit conversion is ok
    Human kid(10);
    //If add explicit, implicit conversion is not ok
    // Human kid2 = 10;
}