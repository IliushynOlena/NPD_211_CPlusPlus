//#include <iostream>
//using namespace std;
////default constructor
//// destructor
////copy constructor
////operator =
//class MyClass
//{
//    int a;
//public:
//    void setA(int a) { this->a = a; }
//    void Print()
//    {
//        cout << a << endl;
//    }
//};
//class Student
//{
//    string name;
//    string spetialization;
//    int* marks;
//    int markCount;
//public:
//    Student() :name("no name"), spetialization("no spetialization"),
//        marks(nullptr), markCount(0) {}
//    Student(string name, string spetialization): name(name), spetialization(spetialization)
//    {
//        markCount = rand() % 10 + 1;//1-10
//        marks = new int[markCount];
//        for (int i = 0; i < markCount; i++)
//        {
//            marks[i] = 8 + rand() % 5;//0-4-----8-12
//        }
//    }
//    virtual void Print()const
//    {
//        cout << "Student name : " << name << endl;
//        cout << "Student spetialization : " << spetialization << endl;
//        cout << "Marks : " ;
//        for (int i = 0; i < markCount; i++)
//        {
//            cout << marks[i] << " ";
//        }
//        cout << endl;
//    }
//    virtual ~Student()
//    {
//        cout << "Destructor Student....." << endl;
//        if (marks != nullptr)
//            delete[]marks;
//    }
//    
//};
//class Aspirant : public Student
//{
//    string *subjects;
//    int countSub;
//public:
//    Aspirant(string n, string s, initializer_list<string> list) : Student(n, s)
//    {
//        //theme1, theme2, theme3
//        this->countSub = list.size();
//        subjects = new string[countSub];
//        int i = 0;
//        for (string sub : list)
//        {            
//            subjects[i] = sub;
//            i++;
//        }
//    }
//    void Print()const override
//    {
//        Student::Print();
//        cout << "Subject : " ;
//        for (int i = 0; i < countSub; i++)
//        {
//            cout << subjects[i] << " ";
//        }
//        cout << endl;
//    }
//    ~Aspirant()
//    {
//        cout << "Destructor Aspirant....." << endl;
//        if (subjects != nullptr)
//            delete[]subjects;
//    }
//
//};
//
//int main()
//{
//    srand(time(0));
//    Student student("Vasia","Math");
//    student.Print();
//
//    Aspirant asp("Ivanka", "History", { "World war" ,"Independency day Of America", "Dovbush"});
//    asp.Print();
//    cout << "*****************************************" << endl << endl;
//    Student* group[3]
//    {
//        new Student("Vasia","Math"),
//        new Aspirant("Ivanka", "History", { "World war" ,"Independency day Of America", "Dovbush"}),
//        new Aspirant("Oksana", "English", { "Time" ,"England"})
//    };
//    for (int i = 0; i < 3; i++)
//    {
//        group[i]->Print();
//        cout << endl;
//        delete group[i];
//    }
//
//    //MyClass m;//default constructor
//    //m.setA(100);
//    //m.Print();
//    //MyClass m2(m);//copy constructor
//    //m2.Print();
//    //MyClass m3 = m;//operator =
//    //m3.Print();
//    //m2 = m;
//
//}
//
