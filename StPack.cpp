#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
    private:
        string Name;
        string Surname;
        vector<int> Marks;
    public:
        Student(string NewName, string NewSurname)
        {
            Name = NewName;
            Surname = NewSurname;
        }
        string getName() { return Name; }
        vector<int> getMarks() { return Marks; }
        void giveMarks(int NewMark) { Marks.push_back(NewMark); }
        bool isExcellentStudent()
        {
            float s;
            for(int i = 0; i <= Marks.size(); i++) s += Marks[i];
            s /= (Marks.size());

            if(s >= 4.6) return 1; else return 0;
        }
        
};


int main()
{
    Student s1("Prohor", "Timofeev"), s2("Bordan", "Lazarev"), s3("Hohlova", "Haritina");
    s1.giveMarks(3);
    s1.giveMarks(4);
    s2.giveMarks(5);
    s2.giveMarks(5);
    s3.giveMarks(4);
    s3.giveMarks(2);

}
