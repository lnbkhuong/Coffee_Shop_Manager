#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

class menu
{
public:
    virtual void input()=0;
    virtual void display()=0;
};
class cafe: public menu
{
   private:
    string name;
    int price;
public:
    void input();
    //kiem tra chu co nhap dung khong
    bool checkchu(string a);
    //kiem tra khoang cach
     void ktkc(string &s);
      //kiem tra chu
      void ktch(string &s);
      //hamtimkiem
      void timkiembangtencafe();
      //hamxoa
      void xoacafe();
      //docfile
      int dodaifcafe();
      void display();
};
void cafe::input()
{
       fstream fo;
        fo.open("cafe.txt",ios::app);
        cin.ignore();
        do{
        	cout <<"Nhap ten do uong: ";
            getline(cin,name);
        }while(name.length()==0|| !checkchu(name));
        ktkc(name);
        ktch(name);
        do
        {
            cout <<"Nhap gia: ";
            cin >>price;
            if(price<10000 || price>50000)
            {
                cout <<"Gia tien cua ban khong phu hop voi do uong cua ban[>=10000 va <=50000]" <<endl;
            }
        }while(price<10000 || price>50000);
             fo<<name<<"\n";
             fo<<price<<"\n";

        fo.close();
}
bool cafe::checkchu(string a)
		{

    		for(int i = 0; i < a.size(); i++)
    		{
        		if((a[i] <= '9' && a[i] >= '0') ||a[i]==',' ||a[i]=='.') return false;
   			}
    		return true;
		}
void cafe::ktkc(string& s)
{
    int t=s.size();
          for(int i=0;i<t;i++)
          {
              while(s[i]==' '&& s[i+1]==' ')
              {
                 for(int j=i;j<t;j++)
                 {
                     s[j]=s[j+1];
                 }
                 t--;
              }
              while(s[t-1]==' '){
                s[t-1]='\0';
                t--;
              }
              while(s[0]==' '){
                for(int j=0;j<t;j++){
                    s[j]=s[j+1];
                }
                t--;
             }
          }
}

void cafe::ktch(string& s)
{
     if(s[0]!=' ') s[0]=toupper(s[0]);
          for (int i=0 ; i< s.size() ; i++)
          {
              if(s[i+1]!=' ' && s[i]==' ') s[i+1]=toupper(s[i+1]);
              else s[i+1]= tolower(s[i+1]);
          }
}

void cafe::timkiembangtencafe()
{
        string name[1000];
    	int price[1000];
    	fstream fi;
    	int i=1;
        int p=0;
        int dem=0;
    	fi.open("cafe.txt",ios::in);
			string fname;
			cin.ignore();
			do{
				cout<<"Nhap ten can tim: ";
				getline(cin,fname);
			}while(fname.length()==0 || !checkchu(fname));
            ktkc(fname);
            ktch(fname);
    	 if (fi == NULL){
           cout <<"Mo tap tin that bai!!!" <<endl;
    	 }
    	 else{
            cout<<"Danh sach can tim: \n";
            while(!fi.eof()){
                if(p==(dodaifcafe()/2))
                    break;

                do{
                    getline(fi,name[i]);
                }while(name[i].length()==0);
                fi >> price[i];
                if(fname==name[i]){
                    cout <<"STT:[" <<i <<"]" <<endl;
                    cout <<"-Loai: cafe" <<endl;
                    cout <<"-Ten do uong: " <<name[i] <<endl;
                    cout <<"-Gia tien: " <<price[i]  <<" VND" <<endl;
                    dem++;
                }
                i++;
                p++;
            }
            fi.close();
            if(dem==0)
            {
               cout <<"-Khong co ten trong danh sach" <<endl;
            }
        }
            
}

void cafe::xoacafe()
{
        string name[1000];
    	int price[1000];
    	fstream fi;
    	int i=1;
        int p=0;
        int dem=0;
        if(dodaifcafe()==0)
        {
            system("pause");
        }
        else{
            fi.open("cafe.txt",ios::in);
            cout<<"Nhap STT can xoa: ";
            cin >>dem;
             if (fi == NULL){
               cout <<"Mo tap tin that bai!!!"<<endl;
             }
             else{
                while(!fi.eof()){
                    if(p==(dodaifcafe()/2))
                        break;

                    do{
                        getline(fi,name[i]);
                    }while(name[i].length()==0);
                    fi >> price[i];
                    i++;
                    p++;
                }
                fi.close();
                }
                 if(dem==0)
                {
                    system("pause");
                }
                else{
                    for(int i=dem;i<=p;i++){
                        name[i]=name[i+1];
                        price[i]=price[i+1];
                    }
                    p--;
                    fstream f;
                    f.open("cafe.txt",ios::out);
                    for(int i=1;i<=p;i++){
                        f<<name[i]<<"\n";
                        f<<price[i]<<"\n";
                    }
                    f.close();
                }
        }
}

int cafe::dodaifcafe()
{
   int dem = 0;
           ifstream f("cafe.txt");
           string u;
           while ( getline(f, u) ){
            dem++;
           }
           return dem;
}
void cafe::display()
{
    string name[1000];
    	int price[1000];
    	fstream fi;
    	int i=0;
        int p=0;
        if(dodaifcafe()==0)
        {
            cout <<"Menu chua co gi ca" <<endl;
            system("pause");
        }
        else{
            fi.open("cafe.txt",ios::in);
             if (fi == NULL){
               cout <<"Mo tap tin that bai!!!"<<endl;
             }
             else{
                while(!fi.eof()){
                    if(p==(dodaifcafe()/2))
                        break;
                    do{
                        getline(fi,name[i]);
                    }while(name[i].length()==0);
                    fi >> price[i];
                    cout <<"STT:[" <<i+1 <<"]" <<endl;
                    cout <<"-Loai: cafe" <<endl;
                    cout <<"-Ten do uong: " <<name[i] <<endl;
                    cout <<"-Gia tien: " <<price[i]  <<" VND" <<endl;
                    i++;
                    p++;
                }
                fi.close();
                }
        }
}
class nuoctraicay:public menu
{
private:
    string name;
    int price;
public:
    void input();
    //kiem tra chu co nhap dung khong
    bool checkchu(string a);
    //kiem tra khoang cach
    void ktkc(string &s);
      //kiem tra chu hoa
    void ktch(string &s);
      //hamtimkiem
      void timkiembangtennuoctraicay();
      //hamxoa
      void xoanuoctraicay();
      //docfile
      int dodaifnuoctraicay();
    void display();
};
void nuoctraicay::input()
{
    fstream f;
        f.open("nuoctraicay.txt",ios::app);
        cin.ignore();
        do{
        	cout <<"Nhap ten do uong: ";
            getline(cin,name);
        }while(name.length()==0|| !checkchu(name));
        ktkc(name);
        ktch(name);
        do
        {
            cout <<"Nhap gia: ";
            cin >>price;
            if(price<10000 || price>50000)
            {
                cout <<"gia tien cua ban khong phu hop voi do uong cua ban[>=10000 va <=50000]" <<endl;
            }
        }while(price<10000 || price>50000);
        f<<name<<"\n";
        f<<price<<"\n";
        f.close();
}
bool nuoctraicay::checkchu(string a)
		{

    		for(int i = 0; i < a.size(); i++)
    		{
        		if((a[i] <= '9' && a[i] >= '0') ||a[i]==',' ||a[i]=='.') return false;
   			}
    		return true;
		}
void nuoctraicay::ktkc(string& s)
{
    int t=s.size();
          for(int i=0;i<t;i++)
          {
              while(s[i]==' '&& s[i+1]==' ')
              {
                 for(int j=i;j<t;j++)
                 {
                     s[j]=s[j+1];
                 }
                 t--;
              }
              while(s[t-1]==' '){
                s[t-1]='\0';
                t--;
              }
              while(s[0]==' '){
                for(int j=0;j<t;j++){
                    s[j]=s[j+1];
                }
                t--;
             }
          }
}
void nuoctraicay::ktch(string& s)
{
    if(s[0]!=' ') s[0]=toupper(s[0]);
          for (int i=0 ; i< s.size() ; i++)
          {
              if(s[i+1]!=' ' && s[i]==' ') s[i+1]=toupper(s[i+1]);
              else s[i+1]= tolower(s[i+1]);
          }
}
void nuoctraicay::timkiembangtennuoctraicay(){
        string name[1000];
    	int price[1000];
    	fstream fi;
    	int i=1;
        int p=0;
        int dem=0;
    	fi.open("nuoctraicay.txt",ios::in);
			string fname;
			cin.ignore();
			do{
				cout<<"Nhap ten can tim: ";
				getline(cin,fname);
			}while(fname.length()==0 || !checkchu(fname));
            ktkc(fname);
            ktch(fname);
    	 if (fi == NULL){
           cout <<"Mo tap tin that bai!!!"<<endl;
    	 }
    	 else{
            cout<<"Danh sach can tim: \n";
            while(!fi.eof()){
                if(p==(dodaifnuoctraicay()/2))
                    break;

                do{
                    getline(fi,name[i]);
                }while(name[i].length()==0);
                fi >> price[i];
                if(fname==name[i]){
                    cout <<"STT:[" <<i <<"]" <<endl;
                    cout <<"-Loai: nuoc trai cay" <<endl;
                    cout <<"-Ten do uong: " <<name[i] <<endl;
                    cout <<"-Gia tien: " <<price[i]  <<" VND" <<endl;
                    dem++;
                }
                i++;
                p++;
            }
            fi.close();
            if(dem==0)
            {
                cout <<"-Khong co ten trong danh sach" <<endl;
            }
        }
            
      }
 void nuoctraicay::xoanuoctraicay()
      {
        string name[1000];
    	int price[1000];
    	fstream fi;
    	int i=1;
        int p=0;
        int dem=0;
        if(dodaifnuoctraicay()==0)
        {
            system("pause");
        }
        else{
            fi.open("nuoctraicay.txt",ios::in);
            cout<<"Nhap STT can xoa: ";
            cin >>dem;
             if (fi == NULL){
               cout <<"Mo tap tin that bai!!!"<<endl;
             }
             else{
                while(!fi.eof()){
                    if(p==(dodaifnuoctraicay()/2))
                        break;

                    do{
                        getline(fi,name[i]);
                    }while(name[i].length()==0);
                    fi >> price[i];
                    i++;
                    p++;
                }
                fi.close();
                }
                if(dem==0)
                {
                    system("pause");
                }
                else{
                    for(int i=dem;i<=p;i++){
                        name[i]=name[i+1];
                        price[i]=price[i+1];
                    }
                    p--;
                    fstream f;
                    f.open("nuoctraicay.txt",ios::out);
                    for(int i=1;i<=p;i++){
                        f<<name[i]<<"\n";
                        f<<price[i]<<"\n";
                    }
                    f.close();
                }
      }
}
 int nuoctraicay::dodaifnuoctraicay(){
           int dem = 0;
           ifstream fi("nuoctraicay.txt");
           string u;
           while ( getline(fi, u) ){
            dem++;
           }
           return dem;
		}
void nuoctraicay::display()
    {
        string name[1000];
    	string price[1000];
    	fstream fi;
    	int i=0;
    	int p=0;
    	if(dodaifnuoctraicay()==0)
        {
            cout <<"Menu chua co gi ca" <<endl;
            system("pause");
        }
        else{
            fi.open("nuoctraicay.txt",ios::in);
            if (fi == NULL){
               cout <<"Mo tap tin that bai!!!"<<endl;
             }
            else{
                while(!fi.eof()){
                    if(p==(dodaifnuoctraicay()/2))
                        break;
                    do{
                        getline(fi,name[i]);
                    }while(name[i].length()==0);
                    fi >> price[i];
                    cout <<"STT:[" <<i+1 <<"]" <<endl;
                    cout <<"-Loai: nuoc trai cay" <<endl;
                    cout <<"-Ten do uong: " <<name[i] <<endl;
                    cout <<"-Gia tien: " <<price[i]  <<" VND" <<endl;
                    i++;
                    p++;
                }
                fi.close();
            }
    }
}
class menus
{
    menu** ma;
    int size;
public:
    menus();
    void input();
    ~menus();
};
menus::menus()
    {
        ma = NULL;
        size = 0;
    }
void menus::input()
    {
            cout <<"Ban muon nhap bao nhieu do uong: ";
            cin >> size;
            if (ma != NULL)
              delete[] ma;

            ma=new menu*[size];
            for(int i=0;i<size;i++){
                int type=0;
                    cout <<"Chon loai do uong(cafe[1]/nuoc trai cay[2]): ";
                    cin >>type;
                    if(type==1){
                        ma[i] = new cafe();
                        ma[i]->input();
                    }
                    else if(type==2){
                        ma[i] = new nuoctraicay();
                        ma[i]->input();
                    }
                    else if(type!=1 ||type!=2)
                    {
                        cout <<"Ban da nhap sai xin vui long nhap lai"<<endl;
                    }
            }
    }
menus::~menus()
    {
        if (ma != NULL)
        delete ma;
    }
class system_managing_menu
{
private:
    cafe a;
    nuoctraicay b;
    menus c;
    int luaChon;
public:

    void input();
};
void system_managing_menu::input()
    {
        int type;
        do {
        system("cls") ;
		cout <<"=============== MENU ===============";
		cout <<"\n1. Them mon vao danh sach.";
		cout <<"\n2. Hien thi danh sach menu.";
		cout <<"\n3. Xoa ten mon.";
		cout <<"\n4. Tim mon theo ten.";
		cout <<"\n0. Thoat chuong trinh.";
		cout <<"\n====================================";
		cout <<"\nBan chon ? ";
		cin >>luaChon;
		switch(luaChon) {
			case 0:
				break;

			case 1:
                c.input();
                system("pause");
				break;

			case 2:
			    cout <<"Ban muon xem menu cafe chon [1]/nuoc trai cay chon [2]: ";
			    cin >>type;
			    if(type==1)
                {
                    a.display();
                }
				else if(type==2)
                {
                    b.display();
                }
				system("pause");
				break;

			case 3:
			    cout <<"Ban muon xoa menu cafe chon [1]/nuoc trai cay chon [2]: ";
			    cin >>type;
			    if(type==1)
                {
                    a.display();
                    a.xoacafe();
                }
				else if(type==2)
                {
                    b.display();
                    b.xoanuoctraicay();
                }
			    system("pause");
				break;

			case 4:
				cout <<"Ban muon tim kiem menu cafe chon [1]/nuoc trai cay chon [2]: ";
			    cin >>type;
			    if(type==1)
                {
                    a.timkiembangtencafe();
                }
				else if(type==2)
                {
                    b.timkiembangtennuoctraicay();
                }
				system("pause");
				break;
            default:
				cout <<"Sai chuc nang, vui long chon lai!\n";
				system("pause");
				break;
		}

        } while(luaChon);
    }
int main()
{
    system_managing_menu am;
    am.input();


    return 0;
}
