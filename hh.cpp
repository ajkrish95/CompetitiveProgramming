#include<iostream>
using namespace std;

class A{
        static int s;
        public :
            int a;
            A(){
                s++;
                a = s;
            }
            int gets(){
                return s;
            }
            A(A& b){
                s++;
                a = s;
            }
            static int add(A a,A b){
                return a.a + b.a;
            }

    };

int A::s = 0;
A a1;
A a2;
int main(){
    cout<<A::add(a1,a2)<<"\n";
    cout<<a1.gets()<<"\n";
}
