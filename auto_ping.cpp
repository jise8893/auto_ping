#include <iostream>
#include <thread>
#include <vector>
#include <stdarg.h>
#include <string>
using std::thread;

std::string format_string(const std::string fmt, ...) {
    int size = ((int)fmt.size()) * 2;
    std::string buffer;
   va_list ap;
   while(1){
       buffer.resize(size);
       va_start(ap,fmt);
       int n= vsnprintf((char *)buffer.data(),size,fmt.c_str(),ap);
       va_start(ap,fmt);
       va_end(ap);
       if(n>-1 && n<size){
           buffer.resize(n);
           return buffer;
       }
       if (n>-1)
           size=n+1;
       else
           size *=2;
   }
    return buffer;
}
void print_vector(std::vector<std::string>& vec){
    for(typename std::vector<std::string>::iterator itr=vec.begin(); itr!=vec.end(); ++itr){
        std::cout<<*itr <<std::endl;
    }
}
void push_vector(std::vector<std::string>& vec){
    for(int i=0; i<255; i++){
    std::string test_masage=format_string("ping -c 1 192.168.1.%d | grep from",i);
    vec.push_back(test_masage);
    }
}
void send_ping(std::vector<std::string>& vec){
    for(int i=0; i<255;i++)
    system(vec[i].c_str());
}
int main(){
    std::vector<std::string> vec;
    push_vector(vec);

    send_ping(vec);
}
