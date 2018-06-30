#include "helloclass.h"
#include<iostream>
using namespace std;

HelloClass::HelloClass(){
cout<<"i'm being created."<<endl;
}
HelloClass::~HelloClass(){
cout<<"i'm being destroyed."<<endl;
}
void HelloClass::sayHello(){
cout<<"hello class!"<<endl;
}
