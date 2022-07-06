#include <iostream>
#include <conio.h>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

class bad_information{};
class phon
{
public:

    bool search(string ,string );
    void print();
    void operator+=(int );
    void cin_information(string ,string );

    double get_price(){ return price;}
    int get_count(){return  count;}
    int get_sell_count(){return sell_count;}
    string get_name(){ return name;}
    string get_company(){ return company;}
    string get_os(){ return os;}
    int get_ram(){ return ram;}
    int get_storage(){ return storage;}
    string get_color(){ return color;}


    void set_name(string n) {name=n;}
    void set_company(string c) {company=c;}
    void set_os( );
    void set_os(string o){os=o;}
    void set_ram();
    void set_ram(int r){ram=r;}
    void set_storage();
    void set_storage(int s){storage=s;}
    void set_price();
    void set_price(int p){price=p;}
    void set_color();
    void set_color(string col){color = col;}
    void set_count(int c) {count=c;}
    void set_sell_count(int sc) {sell_count=sc;}

    void pluscount(){sell_count++;}

private:

    string name;
    string company;
    string os;
    int  ram;
    int storage;
    double price;
    string color;
    int count;
    int sell_count=0;
};


void phon::set_os()
{
    int OS;
    cout<<"\n OS(1-IOS 2-ANDROID 3-WINDOWS  WHICH?[1-3]) ?";
    cin>>OS;
    while(1)
    {

        if(OS==1)
        {os="IOS";  break;}
        else
            if(OS==2)
            { os="Android";  break;}
            else
                if(OS==3)
                {os="Windows";  break;}
                else
                { cout<<"\n OS invalid!\n";    }
    }
}

void phon::set_ram()
{
    while(1)
    {

        cout<<"\n Ram(2-4-6-8-12-16-32-64 GB)? ";
        cin>>ram;
        if(!(ram==2||ram==4||ram==6||ram==8||ram==12||ram==16||ram==32||ram==64))
            cout<<"\n**value is invalid!!**";
        else
            break;
    }
}

void phon::set_storage()
{
    while(1)
    {

        cout<<"\n Storage(16-32-64-128-256-512-1024-2048 GB)? ";
        cin>>storage;
        if(!(storage==16||storage==32||storage==64||storage==128||
             storage==256||storage==512||storage==1024||storage==2048))
            cout<<"\n**value is invalid!!**";
        else
            break;
    }
}

void phon::set_price()
{
    while(1)
    {
        cout<<"\n Price: ";
        cin>>price;
        if(price<0)
            cout<<"\ninvalid\n";
        else
            break;
    }
}

void phon::set_color()
{
    int COLOR;
    bool col=1;
    while(col)
    {
        cout<<"\n Color(1- black 2- white "
              "3- gold 4- gray 5- blue 6- red   which?) ";
        cin>>COLOR;
        switch (COLOR)
        {
        case 1 : color="black"; col=0; break;
        case 2 : color="white"; col=0; break;
        case 3 : color="gold";  col=0; break;
        case 4 : color="gray";  col=0; break;
        case 5 : color="blue";  col=0; break;
        case 6 : color="red";   col=0; break;
        default: cout<<"\n***invalid!***";

        }
    }
}
bool phon::search(string n,string c)     // جستجوی یک موبایل بر اساس اسم و کمپانی
{
    if(this->name==n&&this->company==c)
        return true;

    return false;
}

void phon::print()                  // چاپ ویژگی های موبایل
{
    cout<<"\n name: "<<name
       <<"\n company phon: "<<company
      <<"\n OS: "<<os
     <<"\n Ram: "<<ram
    <<"\n Storage: "<<storage
    <<"\n Color: "<<color
    <<"\n Price: "<<price
    <<"\n Count: "<<count
    <<"\n Count Sold: "<<sell_count;

}

void phon:: operator+=(int c)     // add count phon
{
   count+=c;
}


void phon:: cin_information(string n,string c)   //cin information phon
{

    name=n;
    company=c;
//check os
    cout<<"\n enter information below:";

    set_os();
//check ram
    set_ram();
//check storage
    set_storage();
//color

    set_color();
// price

    set_price();
//count
    while(1)
    {
        cout<<"\n Count phon: ";
        cin>>count;
        //sell count
        cout<<"\n Count Sold: ";
        cin>>sell_count;
        if(sell_count>count||count<0||sell_count<0) cout<<"\ninvalid to count and Sold count\n";
        else
            break;
    }
    cout<<"\n\ndone successfully\n\n";
    _sleep(3000);
}

void    add_phon(vector<phon>& P)          //this function for add phon for 1 to menu
// phon save to vector p
{
    string n,c;          // n== name phon     c= company phon
    int in=-1;;
    cout<<"\n enter name phon:";
    cin>>n;
    cout<<"\n enter comapny name:";
    cin>>c;
    for(int i=0;i<P.size();i++)
    {
        if(P.at(i).search(n,c)==1)
            in=i;
    }

    if(in!=-1)
    {
        int count;
        P.at(in).print();
        cout<<"\n\n enter numbers phon? ";
        cin>>count;
        P.at(in)+=count;
    }
    else
    {
        phon p;

        p.cin_information(n,c);
        P.push_back(p);
    }

}

void shift_to_left(vector<phon>& p,int ind)
{
    for(int i=ind;i<p.size()-1;i++)
    {
        p.at(i)=p.at(i+1);
    }
    p.pop_back();
}

void sort_by_price(vector<phon> & p)
{
    int size=p.size();
    phon temp;
     for(int i=0;i<size;i++)
         for(int j=i+1;j<size;j++)
         {
             if(p.at(i).get_price()>p.at(j).get_price())
             {
                 temp=p.at(i);
                 p.at(i)=p.at(j);
                 p.at(j)=temp;
             }
         }

}

void sort_by_SOLD(vector<phon> p)
{
    int size=p.size();
    phon temp;
     for(int i=0;i<size;i++)
         for(int j=i+1;j<size;j++)
         {
             if(p.at(i).get_sell_count()>p.at(j).get_sell_count())
             {
                 temp=p.at(i);
                 p.at(i)=p.at(j);
                 p.at(j)=temp;
             }
         }

     for(int i=0;i<p.size();i++)
     {
         p.at(i).print();
         cout<<endl;
     }

}
int search_to_vect(vector<phon>& p)
{
    string n,c;          // n== name phon     c= company phon
    int in=-1;;
    cout<<"\n enter name phon:";
    cin>>n;
    cout<<"\n enter comapny name:";
    cin>>c;
    for(int i=0;i<p.size();i++)
    {
        if(p.at(i).search(n,c)==1)
            in=i;
    }


    return in;
}

void save_in_to_a_file(vector<phon> &p,fstream &f)
{

    f<<"name-company-OS-RAM-Storage-color-Price-count-sold_count\n";
    for(int i=0;i<p.size();i++)
    {

        f<< p.at(i).get_name()<<"\t"<<p.at(i).get_company()<<"\t"<<p.at(i).get_os()
         <<"\t"<<p.at(i).get_ram()<<"\t"<<p.at(i).get_storage()<<"\t"<<p.at(i).get_color()
         <<"\t"<<p.at(i).get_price()<<"\t"<<p.at(i).get_count()<<"\t"<<p.at(i).get_sell_count()<<"\n";

    }

}

void load_from_a_file(vector<phon>& p,fstream &f)
{
    string information,s;
    phon P;
    f>>s;
    if(f)
    {
        while(!f.eof())
        {
            f>>information;
            P.set_name(information);
            f>>information;
            P.set_company(information);
            f>>information;
            P.set_os(information);
            f>>information;
            P.set_ram(stoi(information));
            f>>information;
            P.set_storage(stoi(information));
            f>>information;
            P.set_color(information);
            f>>information;
            P.set_price(stoi(information));
            f>>information;
            P.set_count(stoi(information));
            f>>information;
            P.set_sell_count(stoi(information));
            p.push_back(P);
        }
        if(p.size()>0)
        p.pop_back();
    }
    else
    {
        cout<<"\n\n file not found !\n\n";
    }
}
int main(int argc, char *argv[])
{
    int n;
    vector<phon> Phon;
    bool flag=1;
    fstream file;
    file.open("file.txt",ios::in);
    load_from_a_file(Phon,file);
    file.close();
    while(flag)
    {

        system("cls");
        cout<<" Hi please choose:\n"
              "\n 1- Add a phone"
              "\n 2- Remove a phone "
              "\n 3- Sort phones by price"
              "\n 4- Search a phone"
              "\n 5- Change mobile info"
              "\n 6- Sell a phone"
              "\n 7- Print phones "
              "\n 8- Print phones sorted by the most sold to the least "
              "\n 9- Quit"
              "\n\n choose[1-9]?";

        cin>>n;
        if(n==1)
        {
            system("cls");
            add_phon(Phon);


        }
        else
            if(n==2)
            {
                string np,cp;
                bool exit=1;
                system("cls");
                cout<<"Remove phon :\n enter name phon: ";
                cin>>np;
                cout<<" enter company phon: ";
                cin>>cp;
                for(int i=0;i<Phon.size();i++)
                {
                   if(Phon.at(i).search(np,cp)==1)
                   { shift_to_left(Phon,i);   exit=0;}    //after remove shift phon to left

                }

                if(exit)
                {
                    cout<<"\n *phon not found*\n";
                    _sleep(3000);
                }
                else
                {
                    cout<<"\n\ndone successfully\n\n";
                    _sleep(3000);

                }
            }
        else
                if(n==3)
                {
                    system("cls");
                    sort_by_price(Phon);
                    cout<<"\n\ndone successfully\n\n";
                    _sleep(3000);
                }
        else
                    if(n==4)
                    {
                        system("cls");
                        int in=search_to_vect(Phon);
                        if(in==-1)
                        {
                            cout<<"\n\n**phon  not  found**\n\npress to key continue ";
                            getch();
                        }
                        else
                        {
                            Phon.at(in).print();
                        }

                        cout<<"\n\npress to key continue ";
                        getch();
                    }
        else
                        if(n==5)
                        {
                            system("cls");
                            int num;
                            int in=search_to_vect(Phon);
                            if(in!=-1)
                            {

                                while(1)
                                {
                                    Phon.at(in).print();
                                    cout<<"\n\n Which do you want to change?\n\n"
                                          "1- name\n2- company\n3- OS\n"
                                          "4- Ram\n5- Storage\n6- price\n"
                                          "7- Color\n8- count\n9- sold count \n0- back\nchoos?";
                                    cin>>num;
                                    if(num==1)
                                    {
                                        string name;
                                        system("cls");
                                        Phon.at(in).print();
                                        cout<<"enter new name:";
                                        cin>>name;
                                        Phon.at(in).set_name(name);
                                        cout<<"\n\ndone successfully\n\n";
                                         _sleep(3000);

                                    }
                                    else
                                        if(num==2)
                                        {
                                            string company;
                                            system("cls");
                                            Phon.at(in).print();
                                            cout<<"enter new company:";
                                            cin>>company;
                                            Phon.at(in).set_company(company);
                                            cout<<"\n\ndone successfully\n\n";
                                             _sleep(3000);

                                        }
                                    else
                                            if(num==3)
                                                {
                                                cout<<"\n enter new OS:\n";
                                                Phon.at(in).set_os();
                                                }
                                    else
                                                if(num==4)
                                                {
                                                    cout<<"\n enter new ram:\n";
                                                    Phon.at(in).set_ram();
                                                }
                                    else
                                                    if(num==5)
                                                    {
                                                        cout<<"\n enter new storage:\n";
                                                        Phon.at(in).set_storage();
                                                    }
                                    else
                                                        if(num==6)
                                                        {
                                                            cout<<"\n enter new price:\n";
                                                            Phon.at(in).set_price();
                                                        }
                                    else
                                                            if(num==7)
                                                            {
                                                                cout<<"\n enter new color:\n";
                                                                Phon.at(in).set_color();
                                                            }
                                    else
                                                                if(num==8)
                                                                {
                                                                    int c;
                                                                    system("cls");
                                                                    cout<<"\n enter new count:\n";
                                                                    cin>>c;
                                                                    if(c<0||c<Phon.at(in).get_sell_count())
                                                                        cout<<"\n\ninvalid***\n";
                                                                    else
                                                                        Phon.at(in).set_count(c);
                                                                }
                                    else
                                                                    if(num==9)
                                                                    {
                                                                        int sc;
                                                                        system("cls");
                                                                        cout<<"\n enter new sold count:\n";
                                                                        cin>>sc;
                                                                        if(sc<0||sc>Phon.at(in).get_count())
                                                                            cout<<"\n\ninvalid***\n";
                                                                        else
                                                                            Phon.at(in).set_sell_count(sc);
                                                                    }
                                    else
                                                                        if(num==0)
                                                                        {

                                                                            break;

                                                                        }
                                    else
                                                                        {
                                                                            cout<<"\n\n invalid***\n";
                                                                        }

                                }
                            }

                        }
        else
                            if(n==6)
                            {
                                system("cls");
                                int in=search_to_vect(Phon);
                                if(in!=-1)
                                {

                                    if(Phon.at(in).get_sell_count()==Phon.at(in).get_count())
                                    {
                                        cout<<"\n\n Not exit***\n\npress to key continue\n";
                                         getch();

                                    }
                                    else
                                    {
                                        cout<<"\n sell successfully\n\npress to key continue\n";
                                        Phon.at(in).pluscount();
                                        getch();
                                    }

                                }
                                else
                                {
                                    cout<<"\n\n *not found*\n\npress to key continue\n";
                                    getch();


                                }
                            }
        else
                                if(n==7)
                                {
                                    system("cls");
                                    cout<<"\n informations Phon:\n";
                                    for(int i=0;i<Phon.size();i++)
                                    {
                                        cout<<"phon"<<i+1<<":\n";
                                        Phon.at(i).print();
                                        cout<<endl;

                                    }
                                    cout<<"\n\n press to any key to continue\n";
                                    getch();
                                }
        else
                                    if(n==8)
                                    {
                                        cout<<"\nshow sort by sold count:\n\n";
                                        sort_by_SOLD(Phon);
                                        cout<<"\n\npress to key countinue";
                                        getch();
                                    }
        else
                                        if(n==9)
                                        {
                                            cout<<"\n\nGOOD LUCK!";
                                            getch();
                                            file.open("C:/Users/red   pc/Desktop/file.txt",ios::out|ios::trunc);


                                            save_in_to_a_file(Phon,file);
                                            file.close();
                                            return 0;
                                        }
        else
                                        {
                                            cout<<"\n\n***invalid***";


                                        }



    }



}
