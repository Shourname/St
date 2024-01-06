#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

int rand_between(const int from, const int to) 
{
  if (to == from)
    return to;
  if (to < from)
    return rand_between(to, from);
  return from + rand() % (to-from+1);
}

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

class Teacher
{
    protected:
        bool mood;
        int changem;
        string subject;
    public:
        Teacher(string NewSubject)
        {
            subject = NewSubject;
        }
        void setMood(bool NewMood) { mood = NewMood; }
        virtual void UpgiveMarks(Student& st)
        {
            bool isSt = st.isExcellentStudent();
            int rn45 = rand_between(4, 5);
            int rn23 = rand_between(2, 3);

            if(mood == true and isSt == true) st.giveMarks(5);
            else if(mood == false and isSt == true) st.giveMarks(rn45);
            else if(mood == true and isSt == false) st.giveMarks(4);
            else if(mood == false and isSt == false) st.giveMarks(rn23);
            changem++;
            if(changem == 5) setMood(rand_between(0, 1));
        }
};

int main()
{
    srand(unsigned(time(0)));
    
    Student s1("Prohor", "Timofeev"), s2("Bordan", "Lazarev"), s3("Hohlova", "Haritina");
    s1.giveMarks(3);
    s1.giveMarks(4);
    s2.giveMarks(5);
    s2.giveMarks(5);
    s3.giveMarks(4);
    s3.giveMarks(2);

    Teacher t1("Math"), t2("English");
    t1.UpgiveMarks(s1);
    t1.UpgiveMarks(s2);
}
