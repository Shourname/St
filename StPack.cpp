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
        string getSubject() { return subject; }
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

class FiveTeacher : Teacher
{
    public:
        FiveTeacher(string NewSubject): Teacher(NewSubject){};
        string getSubject() override { return subject; }
        void UpgiveMarks(Student& st) override { st.giveMarks(5); }
};

class TwoTeacher : Teacher
{
    public:
        TwoTeacher(string NewSubject): Teacher(NewSubject){};
        string getSubject() override { return subject; }
        void UpgiveMarks(Student& st) override { st.giveMarks(2); }
};

class UnusualTeacher : Teacher
{
    public:
        UnusualTeacher(string NewSubject): Teacher(NewSubject){};
        string getSubject() override { return subject; }
        void UpgiveMarks(Student& st) override 
        { 
            bool isSt = st.isExcellentStudent();
            int rn45 = rand_between(4, 5);
            int rn23 = rand_between(2, 3);

            if(mood == true and isSt == true) st.giveMarks(5);
            else if(mood == false and isSt == true) st.giveMarks(rn45);
            else if(mood == true and isSt == false) st.giveMarks(4);
            else if(mood == false and isSt == false) st.giveMarks(rn23);
            changem++;
            if(changem == 10) setMood(rand_between(0, 1));
        }
};

class Lesson
{
    private:
        vector<Student> stList;
        string naming;
        string tc;
    public:
        Lesson(string NewNaming){ naming = NewNaming; }
        string GetNaming(){ return naming; }
        string GetTeacher() { return tc; }
        vector<Student> GetStudentsNow() { return stList; }
        void AddStudents(Student& st) { stList.push_back(st); }
        void UpAllGiveMarks(Teacher& th)
        {
            tc = th.getSubject();
            for (int i = 0; i < stList.size(); i++) th.UpgiveMarks(stList[i]);
        }
        void UpAllGiveMarks(FiveTeacher& th)
        {
            tc = th.getSubject();
            for (int i = 0; i < stList.size(); i++) th.UpgiveMarks(stList[i]);
        }
        void UpAllGiveMarks(TwoTeacher& th)
        {
            tc = th.getSubject();
            for (int i = 0; i < stList.size(); i++) th.UpgiveMarks(stList[i]);
        }
        void UpAllGiveMarks(UnusualTeacher& th)
        {
            tc = th.getSubject();
            for (int i = 0; i < stList.size(); i++) th.UpgiveMarks(stList[i]);
        }
        bool CheckFive(Student& st)
        {
            float s;
            for(int i = 0; i <= st.getMarks().size(); i++) s += st.getMarks()[i];
            s = (s / (st.getMarks().size()) - 1);
            if (s >= 4.6) return 1; else return 0;
        }
};

class Parent
{
    protected:
        bool mood = rand_between(0, 1);
        vector<Student> children;
        set<string> list;
        string surname;
    public:
        Parent(string NewSurname)
        {
            surname = NewSurname;
        }
        set<string> getList() { return list; }
        vector<Student> getChildren() { return children; }
        void AddChildren(Student& ch)
        {
            children.push_back(ch);
            list.insert(ch.getName());
        }
        void SayAll()
        {
            if(children.size() != 0)
            {
                for (int i = 0; i<children.size();i++)
                {
                    if(children[i].isExcellentStudent() == 1 and mood == 1) cout << "Our child is the best." << endl;
                    if(children[i].isExcellentStudent() == 1 and mood == 0) cout << "Our child is the good." << endl;
                    if(children[i].isExcellentStudent() == 0 and mood == 1) cout << "Our child can do it better." << endl;
                    if(children[i].isExcellentStudent() == 0 and mood == 0) cout << "Our child is the bad." << endl;
                }
            }
        }
        void SayRandom()
        {
            if(children.size() != 0)
            {
                int i = rand_between(1, children.size());
                if(children[i].isExcellentStudent() == 1 and mood == 1) cout << "Our child is the best." << endl;
                if(children[i].isExcellentStudent() == 1 and mood == 0) cout << "Our child is the good." << endl;
                if(children[i].isExcellentStudent() == 0 and mood == 1) cout << "Our child can do it better." << endl;
                if(children[i].isExcellentStudent() == 0 and mood == 0) cout << "Our child is the bad." << endl;
            }
        }
        void SaySum()
        {
            bool m = true;
            for (int i = 0; i<children.size(); i++)
            {
                if (children[i].isExcellentStudent()) continue; else m = 0;
            }
            if (m == 1 and mood == 1) cout<<"They are the best."<<endl;
            if (m == 1 and mood == 0) cout<<"They are the good."<<endl;
            if (m == 0 and mood == 1) cout<<"They can do it better."<<endl;
            if (m == 0 and mood == 0) cout<<"They are the bad."<<endl;
        }
        void SayCertain(string nameStudent)
        {
            int number;
            bool m = true;
            for (int i = 0; i<children.size(); i++)
            {
                if ((children[i].getName()) == nameStudent) number = i; else continue;
            }
            if(number != 0)
            {
                for (int i = 0;i<children.size(); i++){ if (!children[i].isExcellentStudent()) m = 0; }
            }
            if (m == 1 and mood == 1) cout<<children[number].getName()<<"Our child is the best."<<endl;
            if (m == 1 and mood == 0) cout<<children[number].getName()<<"Our child is the good."<<endl;
            if (m == 0 and mood == 1) cout<<children[number].getName()<<"Our child can do it better."<<endl;
            if (m == 0 and mood == 0) cout<<children[number].getName()<<"Our child is the bad."<<endl;
        }
};

class GrandMa : Parent
{
    public:
        GrandMa(string NewSurname): Parent(NewSurname) {};

        void SayAll() override
        {
            if(children.size() != 0)
            {
                for (int i = 0; i<children.size();i++)
                {
                    cout << children[i].getName() << " is the best." << endl;
                }
            }
        }
        void SayRandom() override
        {
            if(children.size() != 0)
            {
                int i = rand_between(1, children.size());
                cout << children[i].getName()<<" is the best."<<endl;
            }
        }
        void SaySum() override
        {
            cout<<"They are the best."<<endl;
        }
        void SayCertain(string nameStudent)
        {
            int number;
            for (int i = 0; i<children.size(); i++)
            {
                if ((children[i].getName()) == nameStudent) number = i; else continue;
            }
            if(number != 0)
            {
                cout<<children[number].getName()<<" is the best."<<endl;
            }
            else
            {
                if (mood == 1) cout<<"This child is a good."<<endl;
                if (mood == 0) cout<<"This child is a bad."<<endl;
            }
        }
};

class Meeting
{
    private:
        vector<Parent> pr;
        vector<GrandMa> gm;
        vector<Teacher> tc;
        vector<Lesson> ls;
    public:
        Meeting(){};
        void addParent(Parent &p){
            pr.push_back(p);
        }
        void addGrandMa(GrandMa &g){
            gm.push_back(g);
        }
        void addTeacher(Teacher &t){
            tc.push_back(t);
        }
        void addLesson(Lesson &l){
            ls.push_back(l);
        }
        void NowTalking()
        {
            for(int i = 0; i < ls.size(); i++)
            {
                for(int j = 0; j < tc.size(); j++)
                {
                    cout<<ls[i].GetNaming()<<"class"<<endl;
                    if(tc[j].getSubject() == ls[i].GetTeacher())
                    {
                        for(int k = 0; k < pr.size(); k++)
                        {
                            for(int h = 0; h < (pr[j].getChildren()).size(); k++)
                            {
                                for(int y = 0; y < (ls[i].GetStudentsNow()).size(); y++)
                                {
                                    if((ls[i].GetStudentsNow())[y].getName() == (pr[k].getChildren()[h]).getName())
                                    {
                                        Student now = pr[k].getChildren()[h];
                                        if(ls[i].CheckFive(ls[i].GetStudentsNow()[y]))
                                        {
                                            if(gm.size() != 0)
                                            {
                                                cout<<now.getName()<<" is the best and luscky one.";
                                            }
                                            else
                                            {
                                                cout<<now.getName()<<" work nice.";
                                            }
                                        }
                                        else
                                        {
                                            if(gm.size() != 0)
                                            {
                                                cout<<now.getName()<<" is the best and luscky one.";
                                            }
                                            else
                                            {
                                                cout<<now.getName()<<" is tryng.";
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        cout<<"No Teacher."<<endl;
                    }
                }
            }
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

    Lesson l1("Math");
    l1.AddStudents(s1);
    l1.AddStudents(s2);
    l1.AddStudents(s3);
    l1.UpAllGiveMarks(t1);

    FiveTeacher ft1("Geography");
    TwoTeacher tt1("Art");

    Parent p1("Timofeev");
    p1.AddChildren(s1);

    GrandMa g1("Lucky");

    Meeting m1;
    m1.addTeacher(t1);
    m1.addParent(p1);
    m1.addGrandMa(g1);
    m1.addLesson(l1);
    m1.NowTalking();

    return 0;
}
