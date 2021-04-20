/*  # common function
    FILE* open_file(const std::string& name);
    size_t read(FILE* fd, const size_t offset, const size_t size, char* buffer);
    size_t write(FILE* fd, const size_t offset, const size_t size, char* buffer);
    size_t flen(FILE* fd);
  
  # need
    #define BUFFER_SIZE 10000 // 1M
    void reverse_file(const std::string& file_name);
# test cases
  case1 'abcd' --> 'dcba'
  #define BUFFER_SIZE 1
  n=2
  O(n)
  case2 ' ' --> ' '
  case3 'abba' --> 'abba'
  case4 '' --> ''
  case5 'a cd' --> 'dc a'
  case6 'abcdefgh' --> 'hgfedcba'
  case7 
*/
'a' 
'ab'
'abc'

void reverse_file(const std::string& file_name) {
    FILE* file(file_name);
    if (!file) {
        std::cout << "cannot open! \n";
        return; // cannot open
    }
    int start = 0;
    int end = flen(file) - 1;  //2
    int mid = start + (end - start) / 2; //'abcd' mid = 1 //1
    //flen is odd, end at (mid)
    //flen is even, change mid
    char* buffer1 = new char[BUFFER_SIZE];
    char* buffer2 = new char[BUFFER_SIZE];
    mid = (flen(file) % 2 == 0)? mid + 1 : mid; //1
    while (start < mid) { // 0 < 1 // 1 < 1?
        //read
        int size = (start + BUFFER_SIZE > mid)? mid - start : BUFFER_SIZE; // 1
        int readCnt1 = read(file, start, size, buffer1); // from head      // a        
        int readCnt2 = read(file, end - size + 1, size, buffer2); // from tail // c
        
        for (int i = 0; i < readCnt1; ++i) {
            std::swap(buffer1[i], buffer2[readCnt1 - i]); // buffer1 = c, buffer2 = a
        }
        int writeCnt1 = write(file, start, readCnt1, buffer1); 
        int writeCnt2 = write(file, end - readCnt2 + 1, readCnt2, buffer2);
        start += size; // 1
        end -= size;   // 0
        
    }
    
    delete buffer1[];
    delete buffer2[];
    
}


void reverse_file(const std::string& file_name) {
    if (FILE *file = fopen(file_name.c_str(), "r") {
        
    }
    else std::cout << "Can't open! \n";
    
}
