#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
class nhanvien
{
private:
        string ho[100];
        string ten[100];
        int tuoi[100];
        int gioitinh[100];
        int chucvu[100];
    public:
        void nhap()
        {
            fstream fo;
            fo.open("nhanvien.txt",ios::app);
            int size;
            cout <<"Ban muon nhap bao nhieu? ";
            cin >>size;
            for(int i=0;i<size;i++)
            {
                cin.ignore();
                do{
                	cout<<"Nhap ho: ";
                    getline(cin,ho[i]);
                }while(ho[i].length()==0|| !checkchu(ho[i]));
                ktkc(ho[i]);
                ktch(ho[i]);
                do{
                	cout <<"Nhap ten: ";
                    getline(cin,ten[i]);
                }while(ten[i].length()==0|| !checkchu(ten[i]));
                ktkc(ten[i]);
                ktch(ten[i]);
                do{
                    cout<<"Tuoi: ";
                    cin >> tuoi[i];
                    if(tuoi[i]<17 ||tuoi[i]>41)
                    {
                        cout <<"So tuoi vuot qua quy dinh de lam viec[ >=18 va  <=40 ]" <<endl;
                    }
                }while(tuoi[i]<7  || tuoi[i] >41 );
                cout <<"Gioi tinh(nam[1]/nu[2]): ";
                cin >>gioitinh[i];
                cout <<"Chuc vu(quanly[1]/nhanvien[2]): ";
                cin >>chucvu[i];
                fo<<ho[i]<<"\n";
                fo<<ten[i]<<"\n";
                fo<<tuoi[i]<<"\n";
                fo<<gioitinh[i]<<"\n";
                fo<<chucvu[i]<<"\n";
                cout <<"\n";
            }
            fo.close();
        }
        bool checkchu(string a)
		{

    		for(int i = 0; i < a.size(); i++)
    		{
        		if((a[i] <= '9' && a[i] >= '0') ||a[i]==',' ||a[i]=='.') return false;
   			}
    		return true;
		}
        void ktkc(string& s)
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

        void ktch(string& s)
        {
             if(s[0]!=' ') s[0]=toupper(s[0]);
                  for (int i=0 ; i< s.size() ; i++)
                  {
                      if(s[i+1]!=' ' && s[i]==' ') s[i+1]=toupper(s[i+1]);
                      else s[i+1]= tolower(s[i+1]);
                  }
        }
        void timkiem()
        {
            fstream fi;
            int i=1;
            int p=0;
            int dem=0;
            fi.open("nhanvien.txt",ios::in);
                string ften;
                cin.ignore();
                do{
                	cout<<"Nhap ten can tim: ";
                    getline(cin,ften);
                }while(ften.length()==0|| !checkchu(ften) );
                ktkc(ften);
                ktch(ften);
             if (fi == NULL){
               cout <<"Mo tap tin that bai!!!"<<endl;
             }
             else{
                cout<<"Danh sach can tim: \n";
                while(!fi.eof()){
                    if(p==(dodaif()/5))
                        break;

                    do{
                        getline(fi,ho[i]);
                    }while(ho[i].length()==0);
                    do{
                        getline(fi,ten[i]);
                    }while(ten[i].length()==0);
                    fi>>tuoi[i];
                    fi>>gioitinh[i];
                    fi>>chucvu[i];
                    if(ften==ten[i]){
                         cout <<"STT:[" <<i <<"]" <<endl;
                         cout <<"-Ho va ten: " <<ho[i] <<" " <<ten[i] <<endl;
                         cout <<"-Tuoi: " <<tuoi[i] <<endl;
                         if(gioitinh[i]==1){
                          cout <<"-Gioi tinh: Nam" <<endl;
                         }
                         else if(gioitinh[i]==2){
                            cout <<"-Gioi tinh: Nu" <<endl;
                         }
                         if(chucvu[i]==1){
                          cout <<"-Chuc vu: Quan ly" <<endl;
                         }
                         else if(chucvu[i]==2){
                            cout <<"-Chuc vu: Nhan vien" <<endl;
                         }
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
        void xoa()
        {
            fstream fi;
            int i=1;
            int p=0;
            int dem=0;
            if(dodaif()==0)
            {
                system("pause");
            }
            else{
                fi.open("nhanvien.txt",ios::in);
                cout<<"Nhap STT can xoa: ";
                cin >>dem;
                if (fi == NULL){
                    cout <<"Mo tap tin that bai!!!" <<endl;
                }
                else{
                    while(!fi.eof()){
                        if(p==(dodaif()/5))
                            break;

                        do{
                            getline(fi,ho[i]);
                        }while(ho[i].length()==0);
                        do{
                            getline(fi,ten[i]);
                        }while(ten[i].length()==0);
                        fi>>tuoi[i];
                        fi>>gioitinh[i];
                        fi>>chucvu[i];
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
                            ho[i]=ho[i+1];
                            ten[i]=ten[i+1];
                            tuoi[i]=tuoi[i+1];
                            gioitinh[i]=gioitinh[i+1];
                            chucvu[i]=chucvu[i+1];
                        }
                        p--;
                        fstream f;
                        f.open("nhanvien.txt",ios::out);
                        for(int i=1;i<=p;i++){
                            f<<ho[i]<<"\n";
                            f<<ten[i]<<"\n";
                            f<<tuoi[i]<<"\n";
                            f<<gioitinh[i]<<"\n";
                            f<<chucvu[i]<<"\n";
                        }
                        f.close();
                    }
                }
        }

        int dodaif()
        {
           int dem = 0;
                   ifstream f("nhanvien.txt");
                   string u;
                   while ( getline(f, u) ){
                    dem++;
                   }
                   return dem;
        }
        void in()
        {
            fstream fi;
            int i=1;
            int p=0;
            if(dodaif()==0)
            {
                cout <<"Danh sach chua co gi ca" <<endl;
                system("pause");
            }
            else{
                fi.open("nhanvien.txt",ios::in);
                 if (fi == NULL){
                   cout <<"Mo tap tin that bai!!!" <<endl;
                 }
                 else{
                    while(!fi.eof()){
                        if(p==(dodaif()/5))
                            break;
                        do{
                            getline(fi,ho[i]);
                        }while(ho[i].length()==0);
                        do{
                            getline(fi,ten[i]);
                        }while(ten[i].length()==0);
                        fi>>tuoi[i];
                        fi>>gioitinh[i];
                        fi>>chucvu[i];
                        cout <<"STT:[" <<i <<"]" <<endl;
                        cout <<"-Ho va ten: " <<ho[i] <<" " <<ten[i] <<endl;
                        cout <<"-Tuoi: " <<tuoi[i] <<endl;
                        if(gioitinh[i]==1){
                         cout <<"-Gioi tinh: Nam" <<endl;
                        }
                        else if(gioitinh[i]==2){
                            cout <<"-Gioi tinh: Nu" <<endl;
                        }
                        if(chucvu[i]==1){
                         cout <<"-Chuc vu: Quan ly" <<endl;
                        }
                        else if(chucvu[i]==2){
                            cout <<"-Chuc vu: Nhan vien" <<endl;
                        }
                        i++;
                        p++;
                    }
                    fi.close();
                    }
            }
        }
};
class system_management_employee
{
private:
    nhanvien a;
    int luaChon;
public:
    void input()
    {
        do {
        system("cls") ;
		cout <<"=============== MENU ===============";
		cout <<"\n1. Them nhan vien vao danh sach.";
		cout <<"\n2. Hien thi danh sach nhan vien.";
		cout <<"\n3. Xoa ten nhan vien.";
		cout <<"\n4. Tim nhan vien theo ten.";
		cout <<"\n0. Thoat chuong trinh.";
		cout <<"\n====================================";
		cout <<"\nBan chon ? ";
		cin >>luaChon;
		switch(luaChon) {
			case 0:
				break;

			case 1:
                a.nhap();
                system("pause");
				break;

			case 2:
			    a.in();
				system("pause");
				break;

			case 3:
			    a.in();
			    a.xoa();
			    system("pause");
				break;

			case 4:
			    a.timkiem();
			    system("pause");
				break;
            default:
				cout <<"Sai chuc nang, vui long chon lai!\n";
				system("pause");
				break;
		}

        } while(luaChon);
    }
};
 
int main()
{
    system_management_employee a;
    a.input();
}
