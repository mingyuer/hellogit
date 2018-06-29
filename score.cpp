#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<cstdio>

using namespace std;

struct Student{
string name;
string sex;
double score;
Student(){};
Student(string sname,string ssex,double sscore):name(sname),sex(ssex),score(sscore){};
};

bool comp(const Student& a,const Student &b){
return (a.score>b.score)||(a.score==b.score)&&(a.name<b.name);
}
vector<Student> stu;
void  aver(){
int cnt_m=0;
int cnt_f=0;
double total_m=0;
double total_f=0;
vector<Student>::iterator it=stu.begin();
while(it!=stu.end()){
if(it->sex=="Male"){
cnt_m++;
total_m+=it->score;
}
else if(it->sex=="Female"){
cnt_f++;
total_f+=it->score;
}
++it;
}
cout<<"male average:"<<total_m/cnt_m<<endl;
cout<<"female average:"<<total_f/cnt_f<<endl;
}

int main(){
freopen("score.csv","r",stdin);
string data;
getline(cin,data);
string name,sex,score;
while(getline(cin,data)){
stringstream ss(data);
getline(ss,name,',');
getline(ss,sex,',');
getline(ss,score,',');
sex.erase(0,1);
score.erase(0,1);
double sc=atof(score.c_str());
Student t(name,sex,sc);
stu.push_back(t);
}
aver();
sort(stu.begin(),stu.end(),comp);
vector<Student>::iterator it=stu.begin();
while(it!=stu.end()){
cout<<it->name<<"\t"<<it->sex<<"\t"<<it->score<<endl;
++it;
}
return 0;
}


