// Example program
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

std::string tmp [] = {"age","class","firsr_name","last_name","count_of_lessons"};

struct student
{
  int age ;
  int clas;
  std::string first_name;
  std::string  last_name;
  std::string * count_of_lessons;
  //bool do_homework;
};



void make_code_R_students(int i,student*& my_student,std::ofstream& fs);
void count_of(int size,student*& my_student,std::ofstream& fs);
int midle_age(std::ifstream& ft);





void make_code_R_students(int i,student*& my_student,std::ofstream& fs)
{
   int count = 0;
   std::cout << "Please enter the age of " << i + 1 << " student" << std::endl;
   std::cin >> my_student[i].age;
   //
   std::cout << "Please enter the class of " << i + 1 << " student" << std::endl;
   std::cin >> my_student[i].clas;
   //
   std::cout << "Please enter the first_name of " << i + 1 << " student" << std::endl;
   std::cin >> my_student[i].first_name;
   //
   std::cout << "Please enter the last_name of " << i + 1 << " student" << std::endl;
   std::cin >> my_student[i].last_name;
   //
   std::cout << "Please enter how many lessanse you learn" << std::endl;
   std::cin >> count ;
   while(count < 1)
   {
       std::cout << "you enter wrong number your number must be bigger then 0 " << std::endl;
       std::cin.get();
       std::cin >> count ;
   }
   my_student[i].count_of_lessons = new std::string[count];
   for(int t = 0 ; t < count ; ++t)
   {
       std::cout << "Please enter " << t + 1 << " lesson name " << std::endl;
       std::cin >> my_student[i].count_of_lessons[t];
   }
   fs<<'{'<<'\n';
    fs <<"{"<<"\n"<<'"'<< " age " << '"'<< ' '<<':' << ' ' << '"'<< ' '<< my_student[i].age<< ' '<<'"' << ','<<"\n";
    fs << '"'<< " class " << '"'<<' '<<':' << ' '<<'"'<< my_student[i].clas<<'"'<<','<<"\n";
    fs << '"'<< " first_name " << '"'<< ' '<<':' << ' '<<'"'<< my_student[i].first_name<<'"'<<','<<"\n";
    fs << '"'<< " last_name " << '"'<< ' '<<':' << ' '<<'"'<< my_student[i].last_name<<'"'<<','<<"\n";
    fs <<'['<<'\n';
    for(int t = 0; t < count ; ++t)
    {
        fs << '"' << "count_of_lessons" << t + 1 << '"'<< ' '<<':'<< ' ' << '"' << my_student[i].count_of_lessons[t]<<'"'<<','<<"\n";
    }
    fs << ']' << '\n';
    fs << "}," << '\n';
}
void count_of(int size,student*& my_student,std::ofstream& fs)
{
    while(size<1)
    {
        std::cout << " may by you make wrong number " << std::endl;
        std::cin >> size;
    }
    for(int i = 0 ; i < size ; ++i)
    {
        make_code_R_students(i,my_student,fs);
    }
}

int age(std::string tmp,int& mid)
{

   std::string now = "";
   std::vector<std::string> line;
   for(int  i = 0; i < tmp.length(); ++i)
   {
        //std::cout << now << std::endl;
       if(tmp[i] != ' ')
       {
           now+=tmp[i];
       }
       else{
           line.push_back(now);
           now = "";
       }
   }

   for(int i = 0 ; i < line.size() ; ++i)
   {

       if(line[i] == "age")
       {
           ++mid;
           int ret = stoi(line[i+4]);
          // std::cout << "for"<<ret<<line[i]<<std::endl;
           return ret;
       }
   }
   return 0;
}


int midle_age(std::ifstream& ft)
{
   std::string tmp = "";
   int count = 0;
   int mid_count = 0;
   while (!ft.eof())
   {
       getline(ft,tmp);
       mid_count += age(tmp,count);
   }
   
   
   return mid_count / count ;
}



int main()
{
    student* code_republic_students;
    std::ofstream fs;
    fs.open("my_JSON.txt",std::ofstream::app);
   std::cout << "This program can add your new student " << std::endl;
   std::cout << "Please Enter how count of students that you whant too add this time " << std::endl;
   int count_of_students = 0 ;
   std::cin >> count_of_students;
   while(count_of_students < 1)
   {
       std::cout << "you make wrong number " << std::endl;
       std::cin.get();
       std::cin >> count_of_students;
   }
     code_republic_students = new student[count_of_students];
     count_of(count_of_students,code_republic_students,fs);
      fs.close();
      std::ifstream ft;
      ft.open("my_JSON.txt");
      if(ft.is_open()){
      std::cout << "The middle age of this grup is "<<midle_age(ft) << std::endl;
      }
     delete []code_republic_students;
     
}

