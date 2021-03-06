#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


class KeyGeneration
{
    public:
    unsigned p;
    unsigned q;
    unsigned n;
    unsigned phi_n;
    unsigned e;
    unsigned d;
    
    void prompter();
    void primality_check();
    unsigned calculate_n();
    unsigned calculate_phi();
    unsigned calculate_e();
    unsigned calculate_d();

};

void KeyGeneration::prompter()
{
    cout<<"Enter a prime number"<<endl;
    cin>>p;
    cout<<"Enter a prime number"<<endl;
    cin>>q;
}
void KeyGeneration::primality_check()
{
   vector<unsigned> p_factors;
   for(unsigned i=2;i<=static_cast<unsigned>(sqrt(p));i++)
   {
         if(p%i==0)
        {
             p_factors.push_back(i);
             p_factors.push_back(p/i);
         }
   }

   vector<unsigned> q_factors;
   for(unsigned i=2;i<=static_cast<unsigned>(sqrt(p));i++)
   {
    if(q%i==0)
    {
        q_factors.push_back(i);
         q_factors.push_back(p/i);
    }
   }
   if(p_factors.size() !=0 || q_factors.size()!=0)
   {
    throw(runtime_error("non prime input"));
   }
}

unsigned KeyGeneration::calculate_n()
{
    n = p*q;
    return n;

}
unsigned KeyGeneration :: calculate_phi()
{
    phi_n=(p-1)*(q-1);
    return phi_n;
}
unsigned KeyGeneration :: calculate_e()
{
    unsigned i=2;
    while (__gcd(i,phi_n) != 1)
        i++;
         e=i;
if(e>= phi_n)
    throw(runtime_error("e is greater than or equal to phi_n"));
    return e;
}
unsigned KeyGeneration::calculate_d()
{
   /*
   (e*d)mod phi_n=1;
   if phi_n=20 and value of e is 3 , then d has to be 7
   so that vit satisfies the equation */
   unsigned k=1;
   while(((k*phi_n)+1)%e !=0)
    k++;
   d=((k*phi_n)+1)/e;
   return d;
}
int main( int argc, const char * argv[])
{
    try
    {
        KeyGeneration obj1;
        obj1.prompter();
        obj1.primality_check();
        cout<<obj1.calculate_n()<<endl;
        cout<<obj1.calculate_phi()<<endl;
        cout<<obj1.calculate_e()<<endl;
        cout<<obj1.calculate_d()<<endl;

    }
    catch(runtime_error & s)
    {
        cout<< s.what() <<endl;
    }
    return 0;
}
