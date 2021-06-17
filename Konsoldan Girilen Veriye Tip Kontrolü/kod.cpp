#include <iostream>
#include <ctype.h>
#include <cstring>
using namespace  std;

bool stringKontrolEtme(const string& str) {
        for (char const& c : str) {
            if (std::isdigit(c) == 0) return true;
        }
        throw "Hatali Giris";      
    }
    
bool intKontrolEtme(int gelenData) {
    
    if (cin.good()) {
        return true;
    }
    else {
        throw "Hatali Giris";
    }        
}


int main()
{
    
  int x;//int için
  cout<<"Int Deger Giriniz: ";
  cin>>x;
  try {
    bool tutanInt = intKontrolEtme(x);
    if (tutanInt) {
        cout<<"Dogru Veri Girisi"<<endl;
    }
  }
  catch (const char* msg) {
    cout<<msg<<endl;
  }
  
  
  string y;//string veri için
  cout<<"String Veri Giriniz:";
  cin>>y;
  try {
    bool tempString = stringKontrolEtme(y);
    if (tempString) {
        cout<<"Dogru Veri Girisi"<<endl;
    }
  }catch (const char* msg) {
    cout<<msg<<endl;
  }  
	
    
}


